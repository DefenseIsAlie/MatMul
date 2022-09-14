#ifndef IJK_MUL
#define IJK_MUL

namespace ijk{

    void _matmul(int dim, double** &A, double** &B, double** &C);

    double** _create_matrix(int dim); 

    void _initialize_matrix(int dim, double** &mat);

}

#endif