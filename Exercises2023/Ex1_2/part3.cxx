#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>
#include <sstream>


float magnitude(std::vector<float> numbers); // prototype

int main(){

    // Print n lines of the data in plain text to the terminal

    int number_of_lines;
    
    std::string token;
    
    std::cout<<"state the number of lines you would like to read in ";
    std::cin >> number_of_lines;

    //std::cout<< "reading " << number_of_lines << "of file"<< std::endl ;
    std::string line;
    std::string filename = "input2D_float.txt";
    std:: ifstream input_file(filename);

    int i=0;
    while (std::getline(input_file, line)){

        if (i <= number_of_lines){

            //std::cout<<i<< std::endl ;


            if (i == 0){

            }
            
            else{
                //std::vector<float> numbers;
                std::cout << line << std::endl;
                
                /*
                while (std::getline(line, token, ',')) {
                    // Convert the token to a double and add it to the vector
                    double number;
                    number = std::stod(token);
                    numbers.push_back(number);
                }

                for (const auto &num : numbers) {
                    std::cout << num << " ";
                }
                */

                std::vector<float> numbers;
                std::string token;

                // Use a stringstream to parse the line
                std::istringstream iss(line);

                // Split the line into tokens using ',' as a delimiter
                while (std::getline(iss, token, ',')) {
                    // Convert the token to a double and add it to the vector
                    float number = std::stod(token);
                    numbers.push_back(number);
                }

                /*
                // Print each element in the vector
                for (const auto &num : numbers) {
                    std::cout << num << " ";
                }
                */

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


    float mag1 = pow(pow(numbers[0],2) + pow(numbers[1],2), static_cast<float>(1)/2);
    return mag1;


};


/*

int main(){
    //std::string name;
    int number_of_lines;
    
    std::cout<<"state the number of lines you would like to read in ";
    std::cin >> number_of_lines;
    //std::getline(std::cin, name);
    //std::cout<<"Your name is: " << name << std::endl;
    std::string line;
    std::string filename = "myDataFile.txt";
    std:: ifstream input_file(filename);
    if (!input_file.is_open()){
        std::cout << "Error opening file: " << filename << std::endl;
        return -1 ;
    }
    else{
        int i=0;
        while (std::getline(input_file, line)){

            if (i <= number_of_lines){

                std::cout << line << std::endl;
                i++;
            }
            else{
                break;
                //return 0;

            }
        }
    }
    return 0;
}

*/