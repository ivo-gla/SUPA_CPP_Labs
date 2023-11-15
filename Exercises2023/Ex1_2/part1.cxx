#include <fstream>
#include <iostream>

int main(){

    // Print n lines of the data in plain text to the terminal

    int number_of_lines;
    
    std::cout<<"state the number of lines you would like to read in ";
    std::cin >> number_of_lines;

    //std::cout<< "reading " << number_of_lines << "of file"<< std::endl ;
    std::string line;
    std::string filename = "input2D_float.txt";
    std:: ifstream input_file(filename);

    int i=1;
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