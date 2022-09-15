#ifndef KIJ_MUL
#define KIJ_MUL

namespace kij{

    void _matmul(int dim, double* &A, double* &B, double* &C);

    double** _create_matrix(int dim); 

    void _initialize_matrix(int dim, double** &mat);

}

#endif