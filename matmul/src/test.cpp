#include "test.hpp"

void check(int dim, double** &C){

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (C[i][j] != dim)
            {
                std::cout << "Validation: Error at " << i << " " << j << std::endl;
                std::cout << "Expected " << dim << " but got " << C[i][j] << std::endl;
                return;
            }
        }
    }
    std::cout << "validation: PASS!" << std::endl;
}