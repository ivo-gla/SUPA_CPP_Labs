#include <iostream>
#include <vector>
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



std::string LeastSquaresCalc(std::vector<std::vector<float>> coordinates){

    std::string equation;
    double p;
    double q;
    double sum_x;
    double sum_y;
    double sum_xy;
    double sum_xx;
    double N; 

    //std::cout << "COORDS SIZE" <<coordinates.size() << std::endl;
    N = coordinates.size();

    for (const auto& row : coordinates) {

        sum_x += row[0];
        sum_y += row[1];
        sum_xy += row[0] * row[1];
        sum_xx += row[0] * row[0];
        //std::cout << row[0] << " " <<row[1] << std::endl;
        std::cout << row[1] << std::endl;
        //float mag1 = magnitude(row);
        //std::cout << "The Magnitude of this vector: (" << row[0] << " " <<row[1] << "), is: "<<mag1 << std::endl;
        
    }

    p = (N * sum_xy - sum_x * sum_y) / (N * sum_xx - sum_x * sum_x);
    q = (sum_xx * sum_y - sum_xy * sum_x) / (N * sum_xx - sum_x * sum_x);

    std::cout << "p" << p << std::endl;
    std::cout << "q" << q << std::endl;

    /*
    $$
    y=p x+q 
    p=\frac{N \sum x_i y_i-\sum x_i \sum y_i}{N \sum x_i^2-\sum x_i \sum x_i},
    q=\frac{\sum x_i^2 \sum y_i-\sum x_i y_i \sum x_i}{N \sum x_i^2-\sum x_i \sum x_i}
    $$
    */
    std::string p1 = "The equation is y = ";
    std::string pString = std::to_string(p);
    std::string p2 = "x +";
    std::string qString = std::to_string(q);
    equation = p1.append(pString).append(p2).append(qString);



    //equation = "The equation is y = " << p <<"x + "<< q <<;






    return equation;
}



std::string LeastSquaresCalc_wCHI(std::vector<std::vector<float>> coordinates){

    std::string equation;
    std::vector<std::vector<float>> errors = readLines("error2D_float.txt");
    double p;
    double q;
    double sum_x;
    double sum_y;
    double sum_xy;
    double sum_xx;
    double N;
    double chi; 
    double error_x;
    double error_y;

    //std::cout << "COORDS SIZE" <<coordinates.size() << std::endl;
    N = coordinates.size();

    for (int i = 0; i <= N; ++i){
        error_x = errors[i][0];
        error_y = errors[i][1];

        sum_x += coordinates[i][0];
        sum_y += coordinates[i][1];
        sum_xy += coordinates[i][0] * coordinates[i][1];
        sum_xx += coordinates[i][0] * coordinates[i][0];
        
        
        //std::cout << row[0] << " " <<row[1] << std::endl;
        //std::cout << row[1] << std::endl;
        //float mag1 = magnitude(row);
        //std::cout << "The Magnitude of this vector: (" << row[0] << " " <<row[1] << "), is: "<<mag1 << std::endl;
        
    }

    p = (N * sum_xy - sum_x * sum_y) / (N * sum_xx - sum_x * sum_x);
    q = (sum_xx * sum_y - sum_xy * sum_x) / (N * sum_xx - sum_x * sum_x);

    std::cout << "p" << p << std::endl;
    std::cout << "q" << q << std::endl;

    /*
    $$
    y=p x+q 
    p=\frac{N \sum x_i y_i-\sum x_i \sum y_i}{N \sum x_i^2-\sum x_i \sum x_i},
    q=\frac{\sum x_i^2 \sum y_i-\sum x_i y_i \sum x_i}{N \sum x_i^2-\sum x_i \sum x_i}
    $$
    */
    std::string p1 = "The equation is y = ";
    std::string pString = std::to_string(p);
    std::string p2 = "x +";
    std::string qString = std::to_string(q);
    equation = p1.append(pString).append(p2).append(qString);



    //equation = "The equation is y = " << p <<"x + "<< q <<;






    return equation;
}



double powerWithoutLoop(double x, double y){
    int y_i = static_cast<int>(y);
    if (y_i == 0) {
        return 1.0;
    }
    
    return x * powerWithoutLoop(x, y_i * 1.0 - 1);

}
   



