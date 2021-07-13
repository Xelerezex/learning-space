//--> EDIT HERE

#ifndef DIAGONAL_TRAVERSE_CPP
#define DIAGONAL_TRAVERSE_CPP

#include "diagonal_traverse.h"

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    size_t row = mat.size(), column = mat[0].size();
    vector<vector<int>> diagonals(row + column - 1);

    vector<int> out_put;

    for (size_t i = 0; i < row; ++i){
        for (size_t j = 0; j < column; ++j){
            diagonals[i + j].push_back(mat[i][j]); 
        }
    }

    out_put.push_back(diagonals[0][0]);

    for (size_t i = 1; i < diagonals.size(); ++i){
        for (size_t j = 0; j < diagonals[i].size(); ++j){
            if (i % 2 == 0) {
                out_put.push_back(diagonals[i][((diagonals[i].size() - 1) - j)]);
            } else {
                out_put.push_back(diagonals[i][j]);
            }
        }
    }

    return out_put;        
}

#endif