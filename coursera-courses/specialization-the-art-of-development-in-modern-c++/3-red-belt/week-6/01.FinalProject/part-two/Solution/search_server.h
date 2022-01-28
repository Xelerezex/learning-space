#pragma once

#include "syncronized.h"

// Split string with spaces. And gets us vector of string "a b c" -> ["a", "b", "c"].
vector<string> SplitIntoWords(const string& line);

class InvertedIndex
{
    public:

        void Add(const string &document);                        // Added string document to vector
                                                                 // of docs. And generate map of words
                                                                 // with ids of documents, where
                                                                 // did that words came from.

        const vector<pair<size_t, size_t>>& Lookup(const string& word) const; // If some word found
                                                                              // in map (index),
                                                                              // give:
                                                                              // vector<word, quantity>

        size_t GetDocumentSize() const;                          // Gives size of document's vector

    private:
        // map<string, vector<pair<size_t, size_t>>> index;
        unordered_map<string, vector<pair<size_t, size_t>>> index;
        vector<pair<size_t, size_t>> nothing {};
        size_t docs_size = 0;
};

class SearchServer
{
    public:
        SearchServer() = default;                           // Just Default constructor

        explicit SearchServer(istream& document_input);     // Constructor of class, just calling
                                                            // UpdateDocumentBase() function.

        // InvertedIndex & GetIndex();


        void UpdateDocumentBase(istream& document_input);   // Drops old InvertedIndex index &
                                                            // generates new. Added our document
                                                            //  to InvertedIndex.

        void AddQueriesSingleThread(
            istream& query_input,
            ostream& search_results_output
        );

        void AddQueriesStream(                              // Takes words that should find, output
                istream& query_input,                       // var. Generates map of doc id &
                ostream& search_results_output              // count of words. Then writes answer to
        );                                                  // search_results_output

    private:
        std::shared_mutex shared;
        InvertedIndex index;
        // Synchronized<InvertedIndex> synchronized_index;
        vector<future<void>> futures;
};

