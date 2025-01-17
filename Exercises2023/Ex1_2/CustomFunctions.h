// CustomFunctions.h

#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>  
#include <string.h>
#include <sstream>



float magnitude(std::vector<float> numbers); // prototype
int countLines(const std::string& filename); // use to count the number of lines in a file
int printLines(const std::string& filename, int nLines);
std::vector<std::vector<float>> readLines(const std::string& filename);
std::string LeastSquaresCalc(std::vector<std::vector<float>> coordinates);
std::string LeastSquaresCalc_wCHI(std::vector<std::vector<float>> coordinates);
double powerWithoutLoop(double x, double y);

