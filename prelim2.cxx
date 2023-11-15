#include <iostream>
#include <vector>
#include<cmath>  


int main(){

  float x = 2.3;
  float y = 4.5;

  std::vector<float> numbers; 
  numbers.push_back(x); //.push_back() member used to add members to a vector
  numbers.push_back(y); // subsequent calls get added one-after-another, the vector maintains the order

  float mag1 = pow(pow(numbers[0],2) + pow(numbers[1],2), static_cast<float>(1)/2);

  std::cout << "The Magnitude of this vector is: " << mag1 << std::endl;


}

/*\#include <iostream>
\#include <vector>
int main()
\{
std::string name = "John Doe."; //Strings work largely as you might expect
std: : cout $\ll$ "The name is: " $\ll$ name $\ll$ std: : endl;
std::vector<float> numbers; //vector declaration without assignment
numbers.push_back(1.1); //.push_back() member used to add members to a vector
numbers.push_back(2.3); // subsequent calls get added one-after-another, the vector maintains the order
numbers.push_back(4.9);
std:: cout $\ll$ "The numbers are: " $\ll$ numbers[0] $\ll$ ", " $\ll$ numbers[1] $\ll ", " \ll$ numbers[2] $\ll$ std: : endl; //Use [i] to pick out members
/Nectors can also be used to hold strings
std::vector<std::string> names $=\{$ "John Doe.", "Jane Doe." $\} ; / /$ vector declaration with assignment is also possible
std: : cout $\ll$ "The names are: " $\ll$ names $[0] \ll$ ", and " $\ll$ names $[1] \ll$ std: : endl ;
return 0 ;
\} */