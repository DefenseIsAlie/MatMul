#include<iostream>
#include<sstream>
#include "../inc/input.hpp"

int diminput::_commandline_input(int block_flag){
    int input = -1;
    std::string input_str; 
    std::istringstream conv;
    if (block_flag){
        std::cout << "Enter block size in decimal: \n";
    } else {
        std::cout << "Enter matrix dimension in decimal: \n";
    }
                            // skips after space                        
    std::cin >> input_str; // Convert the input string to stringstream
    conv.str(input_str);

    if (!(conv >> input))
    {   // check for invalid character
        std::cerr << "Invalid Number -> Enter only decimal number, Entered: "<< input_str << std::endl;
        return INPUT_ERROR;
    } else if (!(conv.eof()))
    {   
        // Check for trailing character
        std::cerr << "Enter only the dimension, But entered: "<< input_str << "\n";
        return INPUT_ERROR;
    }

    return input;
}



int diminput::_argv_input(char* args[], int indx){
    int input = -1;

    std::istringstream conv;
    conv.str(args[indx]);

    if (!(conv >> input))
    {   
        // Check for invalid character 
        std::cerr << "Invalid Number -> Enter only decimal number, Entered: "<< args[1] << std::endl;
        return INPUT_ERROR;
    } else if (!(conv.eof()))
    {   
        // Check for trailing character
        std::cerr << "Enter only the dimension, But entered: "<< args[1] << "\n";
        return INPUT_ERROR;
    }

    return input;
}