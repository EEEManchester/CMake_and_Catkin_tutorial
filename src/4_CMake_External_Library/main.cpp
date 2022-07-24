#include <iostream>
#include "Fastor/Fastor.h"

int main()
{
    // basic output of testing code
    std::cout<<"Hello robot"<<std::endl;

    // call external library 
    Fastor::Tensor<double,4,3> A;

    A.random(); 

    std::cout<<"Output of fastor library"<<std::endl;

    std::cout<<"Tensor A is "<< A <<std::endl;

    
    Fastor::Tensor<double> my_scalar = 2; // this is a scalar (double) with a value of 2
    // output this on the screen
    print("my scalar",my_scalar); // print is a built-in Fastor function for printing

    Fastor::Tensor<double,3> my_vector = {1,2,3}; // this is a vector of 3 doubles with values {1,2,3}
    print("my vector",my_vector);
    Fastor::Tensor<float,3,3> my_matrix = {{1,2,3},
                                    {4,5,6},
                                    {7,8,9}}; // this a 3x3 matrix of floats with values 1...9
    print("my matrix",my_matrix);

    Fastor::Tensor<int,2,2,2,2,2> array_5d; // this a 5D array of ints with dimension 2x2x2x2x2
    array_5d.iota(1); // fill the 5d_array with sequentially ascending numbers from 1 to 2x2x2x2x2=32
    print("my 5D array", array_5d);

    return 0;
}