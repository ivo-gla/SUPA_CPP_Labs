#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>
#include <sstream>

#include "FiniteFunctions.h"
std::vector<double> readfile(const std::string& filename);

int main() {
    FiniteFunction myfunction;
    std::cout << "Hello, World!" << std::endl;
    std::string filename = "Outputs/data/MysteryData00133.txt";

    //read in mystery file
    std::vector<double> test = readfile(filename);

    myfunction.plotData(test, 1000, true);
    myfunction.plotFunction();
    //FiniteFunction::generatePlot();
    double etet = myfunction.integral(1000);

    myfunction.setOutfile("test124.png");
    myfunction.plotFunction();
    //for (const auto& row : test) {
    //    std::cout << row  << std::endl;
    //}
    return 0;
}




std::vector<double> readfile(const std::string& filename){
    std::vector<double> numbers;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)){
        
        //std::cout << line << std::endl;
        double number = std::stod(line);
        numbers.push_back(number);
    }
    return numbers;
}