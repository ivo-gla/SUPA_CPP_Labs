#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>
#include <sstream>

//imports

float magnitude(std::vector<float> numbers); // prototype
int countLines(const std::string& filename); // use to count the number of lines in a file

int main(){

    // print n lines of the data in plain text to the terminal

    int number_of_lines; //the number of lines to print
    std::string line; //string to contain the lines of the file
    std::string token; //used to split up the data
    
    
    std::cout<<"state the number of lines you would like to read in "; //user specified number of lines to read in
    std::cin >> number_of_lines; //get the number of lines in the file

    
    std::string filename = "input2D_float.txt";

    int total_lines = countLines(filename);

    //std::cout<<"the total nubmer of line in the file is " << total_lines << std::endl;

    std::ifstream input_file(filename);

    int i=0;
    while (std::getline(input_file, line)){
        

        if (number_of_lines <= total_lines){

            if (i <= number_of_lines){
                if (i == 0){
                    //if no lines are read in do nothing
                }
                
                else{

                    //std::cout << line << std::endl; //print out the line
                    std::vector<float> numbers;
                    std::vector<float> x_array;
                    std::vector<float> y_array;
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
                std::cout << "The Magnitude of this vector: (" << line << "), is: "<<mag1 << std::endl;
    

                }
            }
            
            else{
                break;
                //return 0;
            }
            i++;
        } else {
            std::cout << "There are only " << total_lines << " first 5 lines will be printed instead" << std::endl;
            number_of_lines = 5;

        }

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

int countLines(const std::string& filename){
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1; //return -1 to indicate an error opening this file
    }

    int lineCount = 0;
    std::string line;

    while (std::getline(file, line)) {
        ++lineCount;
    }

    file.close();
    
    return lineCount;
}
