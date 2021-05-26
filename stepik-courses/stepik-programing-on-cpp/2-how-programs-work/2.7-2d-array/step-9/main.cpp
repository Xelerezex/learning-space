int ** CreateDArray(/*size_t*/unsigned row, /*size_t*/unsigned col);

int ** CreateDArray(/*size_t*/unsigned row, /*size_t*/unsigned col) {
    int ** arr = new int* [row];
    arr[0] = new int[row * col];
    for (/*size_t*/unsigned i = 1; i != row; ++i){
        arr[i] = arr[i - 1] + col;
    }
    return arr;
}

int ** transpose(const int * const * m, /*size_t*/ unsigned rows, /*size_t*/ unsigned cols) {
    int ** out_put = CreateDArray(cols, rows);

    for (/*size_t*/ unsigned i = 0; i < rows; ++i){
        for (/*size_t*/ unsigned j = 0; j < cols; ++j){
            out_put[j][i] = m[i][j];
        }
    }

    return out_put;
}
