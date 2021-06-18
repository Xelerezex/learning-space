void rotate(int pa[], unsigned size, int shift)
{
    // TAKE A COPY
    int cpa[size];
    for (unsigned i = 0; i < size; ++i){
        cpa[i] = *(pa + i);
    }

    for (unsigned i = 0; i < size; ++i){
        pa[i] = cpa[(i + shift) % size];
    }
}
