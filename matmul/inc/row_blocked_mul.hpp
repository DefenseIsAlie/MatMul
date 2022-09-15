#ifndef ROW_BLOCK_MUL
#define ROW_BLOCK_MUL

namespace row_block{

    void _matmul(int dim, int block_size ,double* &a, double* &b, double* &c);

    double** _create_matrix(int dim); 

    void _initialize_matrix(int dim, double** &mat);

}

#endif