#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>
#include <sstream>


float magnitude(std::vector<float> numbers); // prototype

int main(){

    // print n lines of the data in plain text to the terminal

    int number_of_lines; //the number of lines to print
    
    std::string token; //used to split up the data
    
    std::cout<<"state the number of lines you would like to read in "; //user specified number of lines to read in
    std::cin >> number_of_lines;

    //std::cout<< "reading " << number_of_lines << "of file"<< std::endl ;
    std::string line;
    std::string filename = "input2D_float.txt";
    std:: ifstream input_file(filename);

    int i=0;
    while (std::getline(input_file, line)){

        if (i <= number_of_lines){


            if (i == 0){
                //if no lines are read in do nothing
            }
            
            else{

                //std::cout << line << std::endl; //print out the line
                std::vector<float> numbers;
                std::string token;

                // use stringstream to parse each line (eg x,y)
                std::istringstream iss(line);

                // split the line into tokens using ',' as a delimiter
                while (std::getline(iss, token, ',')) {
                    // conver the token bit of string to a float and add it to the vector (float)
                    float number = std::stod(token);
                    numbers.push_back(number);
                }


               //find the magnitude now

               float mag1 = magnitude(numbers);

               std::cout << "The Magnitude of this vector is: " << line << " , "<<mag1 << std::endl;

                

            }
        }
        
        else{
            break;
            //return 0;

        }
        i++;
    }

    return 0;

}

float magnitude(std::vector<float> numbers){
    /*
    magnitude - finds the magnitude of a vector in 2d
    inputs- vector (float) numbers - the coordinates in 2d

    outputs - float mag1 - the magnitude of the vector
    */


    float mag1 = pow(pow(numbers[0],2) + pow(numbers[1],2), static_cast<float>(1)/2);
    return mag1;


};
