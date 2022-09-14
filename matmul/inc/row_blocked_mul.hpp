#ifndef ROW_BLOCK_MUL
#define ROW_BLOCK_MUL

namespace row_block{

    void _matmul(int dim, double** &A, double** &B, double** &C);

    double** _create_matrix(int dim); 

    void _initialize_matrix(int dim, double** &mat);

    inline double _saxpy(int dim, double &a, double* &X);

}

#endif