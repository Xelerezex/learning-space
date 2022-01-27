#include "search_server.h"

vector<string> SplitIntoWords(const string& line)
{
    istringstream words_input(line);
    return {istream_iterator<string>(words_input), istream_iterator<string>()};
}


void InvertedIndex::Add(string document)
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
    UpdateDocumentBase(document_input);
}


void SearchServer::UpdateDocumentBase(istream& document_input)
{
    InvertedIndex new_index;

    for (string current_document; getline(document_input, current_document); )
    {
        new_index.Add(move(current_document));
    }

    index = move(new_index);
}


void SearchServer::AddQueriesStream(
    istream& query_input,
    ostream& search_results_output
)
{
    const size_t docs_size = index.GetDocumentSize();
    vector<pair<size_t, size_t>> docid_count(docs_size);

    for (string current_query; getline(query_input, current_query); )
    {
        // First Part
        //------------------------------------------------------------
        for (const auto& word : SplitIntoWords(current_query))
        {
            for (const pair<size_t, size_t> &docid : index.Lookup(word))        // Accessing to
            {                                                                   // the index
                docid_count[docid.first].first   = docid.first;
                docid_count[docid.first].second += docid.second;
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
        search_results_output << '\n';
        //------------------------------------------------------------
        fill(docid_count.begin(), docid_count.end(), pair{0, 0});
    }
}
