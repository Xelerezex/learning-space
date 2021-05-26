int min_element(int **m, unsigned rows, unsigned cols){
    int out_put = m[0][0], out_row = 0;

    for (unsigned i = 0; i < rows; ++i){
        for (unsigned j = 0; j < cols; ++j){
            if (out_put >= m[i][j]){
                out_put = m[i][j];
                out_row = i;
            }
        }
    }
    return out_row;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_row = min_element(m, rows, cols);

    int *timl = m[0];
    m[0] = m[min_row];
    m[min_row] = timl;

    //delete [] timl;
}
