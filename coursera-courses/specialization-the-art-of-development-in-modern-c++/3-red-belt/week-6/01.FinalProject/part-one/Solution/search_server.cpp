#include "search_server.h"
#include "iterator_range.h"


#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>


vector<string> SplitIntoWords(const string& line)
{   // O(N)
    istringstream words_input(line);
    return {istream_iterator<string>(words_input), istream_iterator<string>()};
}


void InvertedIndex::Add(string document)
{   // O(N)
    const size_t docid = docs.size();
    for (const auto& word : SplitIntoWords(document))
    {
        index[word].push_back(docid);
    }
    docs.push_back(move(document));
}


list<size_t> InvertedIndex::Lookup(const string& word) const
{   // O(log N)
    if (auto it = index.find(word); it != index.end())
    {
        return it->second;
    }
    else
    {
        return {};
    }
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
    for (string current_query; getline(query_input, current_query); )
    {
        const auto words = SplitIntoWords(current_query);

        map<size_t, size_t> docid_count;
        for (const auto& word : words)
        {
            for (const size_t docid : index.Lookup(word))
            {
                docid_count[docid]++;
            }
        }

        vector<pair<size_t, size_t>> search_results(
            make_move_iterator(docid_count.begin()),
            make_move_iterator(docid_count.end())
        );

        sort(
            begin(search_results),
            end(search_results),
            [](pair<size_t, size_t> lhs, pair<size_t, size_t> rhs) {
                int64_t lhs_docid = lhs.first;
                auto lhs_hit_count = lhs.second;

                int64_t rhs_docid = rhs.first;
                auto rhs_hit_count = rhs.second;
                return make_pair(lhs_hit_count, -lhs_docid) > make_pair(rhs_hit_count, -rhs_docid);
            }
        );

        search_results_output << current_query << ':';
        for (auto [docid, hitcount] : Head(search_results, 5))
        {
            search_results_output << " {"
                << "docid: " << docid << ", "
                << "hitcount: " << hitcount << '}';
        }
        search_results_output << endl;
    }
}
