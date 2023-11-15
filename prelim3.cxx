#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>

float magnitude(std::vector<float> numbers); // prototype


int main(){

    std::string user_input;

    //float x = 2.3;
    //float y = 4.5;
    std::cout << "Please enter a vector (x,y)" << std::endl;
    float x;
    std::cout << "x component" << std::endl;
    std::cin >> x; //Prompt for user input and pass it to pre-defined string
    //std::cout << x << std::endl;

    float y;
    std::cout << "y component" << std::endl;
    std::cin >> y; //Prompt for user input and pass it to pre-defined string
    //std::cout << y << std::endl;

    std::vector<float> numbers; 
    numbers.push_back(x); //.push_back() member used to add members to a vector
    numbers.push_back(y); // subsequent calls get added one-after-another, the vector maintains the order

    //float mag1 = pow(pow(numbers[0],2) + pow(numbers[1],2), static_cast<float>(1)/2);

    float mag1 = magnitude(numbers);

    std::cout << "The Magnitude of this vector is: " << mag1 << std::endl;


}



float magnitude(std::vector<float> numbers){


    float mag1 = pow(pow(numbers[0],2) + pow(numbers[1],2), static_cast<float>(1)/2);
    return mag1;


};

/* 

int cubeNumber(int); // prototype
int main( ) \{
int myNum i=3;
...
int myNumCubed = cubeNumber (myNum);
cout $\ll$ "The cube of " $<$ myNum $\ll$ " is " $<$ myNumCubed $<$ <endl;
return 0 ;
\}
int cubeNumber(int i) \{/ /$ definition
return (i * i * i);
\}

*/