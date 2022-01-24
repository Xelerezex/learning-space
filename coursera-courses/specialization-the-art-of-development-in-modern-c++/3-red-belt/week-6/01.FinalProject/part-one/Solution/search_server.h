#pragma once

#include "search_server.h"
#include "iterator_range.h"

// Split string with spaces. And gets us vector of string "a b c" -> ["a", "b", "c"].
vector<string> SplitIntoWords(const string& line);

class InvertedIndex
{
    public:
        void Add(string document);                          // Added string document to vector of docs.
                                                            // And generate map of words with ids of
                                                            // documents, where did that words came from.

        list<size_t> Lookup(const string& word) const;      // If some word found in map (index), give
                                                            // list of ids

        const string& GetDocument(size_t id) const          // Gives vector of input documents
        {   // ~O(1)
            return docs[id];
        }

    private:
        map<string, list<size_t>> index;
        vector<string> docs;
};

class SearchServer
{
    public:
        SearchServer() = default;                           // Just Default constructor

        explicit SearchServer(istream& document_input);     // Constructor of class, just calling
                                                            // UpdateDocumentBase() function.

        void UpdateDocumentBase(istream& document_input);   // Drops old InvertedIndex index & generates
                                                            // new. Added our document to InvertedIndex.

        void AddQueriesStream(                              // Takes words that should find, output var.
                istream& query_input,                       // Generates map of doc id & count of words.
                ostream& search_results_output              // Then writes answer to search_results_output
        );

    private:
        InvertedIndex index;
};

