#include <iostream>
#include "CustomFunctions.h"


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

int printLines(const std::string& filename, int nLines ){
    /*
    prints nLines of a file named filename and has some error handling
    
    */

    std::ifstream file(filename);
    std::string line;

    int total_lines = countLines(filename);

    if (nLines > total_lines){

        std::cout << "WARNING YOU ARE REQUESTING TOO MANY LINES" << std::endl;
        std::cout << "PRINTING THE FIRST 5 LINES" << std::endl;
        nLines =5;
    }

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return -1; //return -1 to indicate an error opening this file
    }
    else{

        int i=0;
        while (std::getline(file, line)){

            if (i <= nLines){
                
                std::cout << line << std::endl;
                i++;
            }
        }

    }
    
    return 0;
}


std::vector<std::vector<float>> readLines(const std::string& filename){
    std::vector<std::vector<float>> coordinates;
    std::vector<float> numbers;
    std::ifstream file(filename);
    std::string line;

    int i=0;
    while (std::getline(file, line)){
        
        if (i == 0){
            //if no lines are read in do nothing
        }
        
        else{

            //std::cout << line << std::endl; //print out the line
            std::vector<float> numbers;
            //std::vector<float> x_array;
            //std::vector<float> y_array;
            std::string token;

            // use stringstream to parse each line (eg x,y)
            std::istringstream iss(line);

            // split the line into tokens using ',' as a delimiter
            while (std::getline(iss, token, ',')) {
                // conver the token bit of string to a float and add it to the vector (float)
                float number = std::stod(token);
                numbers.push_back(number);
            }
            coordinates.push_back(numbers);
        }
        i++;
    }
    






    return coordinates;
}
