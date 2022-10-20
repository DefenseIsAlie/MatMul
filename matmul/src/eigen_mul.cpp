#include <Eigen/Dense>
#include <iostream>
#include <sstream>
#include <chrono>


int main(int argc, char **argv){

    Eigen::MatrixXd o = Eigen::MatrixXd::Random(1024, 1024);
    Eigen::MatrixXd p = Eigen::MatrixXd::Random(1024, 1024);
    
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXd res = o*p;
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    
    double mul_time = std::chrono::duration<double, std::milli>(end - start).count();
    std::cout << "Time take for eigen_mul is "<< mul_time << " ms" << std::endl;
    
    return 0;
}
