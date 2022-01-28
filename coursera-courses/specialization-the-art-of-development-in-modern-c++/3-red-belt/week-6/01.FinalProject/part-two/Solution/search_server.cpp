#include "search_server.h"

vector<string> SplitIntoWords(const string& line)
{
    istringstream words_input(line);
    return {istream_iterator<string>(words_input), istream_iterator<string>()};
}


void InvertedIndex::Add(const string &document)
{
    unordered_map<string, size_t> local;

    for (const auto &word : SplitIntoWords(document)) {
        ++local[word];
    }

    for (const auto &[word, size] : local)
    {
        index[word].push_back({docs_size, size});
    }
    ++docs_size;
}


const vector<pair<size_t, size_t>>& InvertedIndex::Lookup(const string& word) const
{
    if (auto it = index.find(word); it != index.end())
    {
        return it->second;
    }
    else
    {
        return nothing;
    }
}


size_t InvertedIndex::GetDocumentSize() const
{
    return docs_size;
}


SearchServer::SearchServer(istream& document_input)
{
    UpdateDocumentBaseSingleThread(document_input);
}


void SearchServer::UpdateDocumentBaseSingleThread(istream& document_input)
{
    InvertedIndex new_index;

    for (string current_document; getline(document_input, current_document); )
    {
        new_index.Add(move(current_document));
    }

    {
        std::unique_lock<shared_mutex> lock {shared};
        index = move(new_index);
    }
}

void SearchServer::UpdateDocumentBase(istream& document_input)
{
    futures.push_back(
        async(
            std::launch::async,
            &SearchServer::UpdateDocumentBaseSingleThread,
            this,
            ref(document_input)
        )
    );
}

void SearchServer::AddQueriesSingleThread(
    istream& query_input,
    ostream& search_results_output
)
{
    vector<pair<size_t, size_t>> docid_count;
    for (string current_query; getline(query_input, current_query); )
    {
        // First Part
        //------------------------------------------------------------
        {
            shared_lock<shared_mutex> lock{shared};
            const size_t docs_size = index.GetDocumentSize();
            docid_count.assign(docs_size, pair{0, 0});

            for (const auto& word : SplitIntoWords(current_query))
            {
                for (const pair<size_t, size_t> &docid : index.Lookup(word))
                {
                    docid_count[docid.first].first   = docid.first;
                    docid_count[docid.first].second += docid.second;
                }
            }
        }
        //------------------------------------------------------------

        // Second Part
        //------------------------------------------------------------
        size_t step = min<size_t>(5, (docid_count.size() - 1));
        partial_sort(
            docid_count.begin(),
            docid_count.begin() + step,
            docid_count.end(),
            [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
                int64_t lhs_docid = lhs.first;
                auto lhs_hit_count = lhs.second;
                int64_t rhs_docid = rhs.first;
                auto rhs_hit_count = rhs.second;
                return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
            }
        );
        //------------------------------------------------------------

        // Third part
        //------------------------------------------------------------
        search_results_output << current_query << ':';
        for (const auto &[docid, hitcount] : Head(docid_count, 5))
        {
            if (hitcount != 0)
            {
                search_results_output << " {"
                    << "docid: " << docid << ", "
                    << "hitcount: " << hitcount << '}';
            }
        }
        search_results_output << endl;
        //------------------------------------------------------------
    }
}


void SearchServer::AddQueriesStream(
    istream& query_input,
    ostream& search_results_output
)
{
    futures.push_back(
        async(
            std::launch::async,
            &SearchServer::AddQueriesSingleThread,
            this,
            ref(query_input),
            ref(search_results_output)
        )
    );
}
