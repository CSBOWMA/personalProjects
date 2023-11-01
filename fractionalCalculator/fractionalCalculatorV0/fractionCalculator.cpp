#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


std::string history;
int solutionCount, error;
std::ostringstream oss;
std::string solution;


//takes the string input and converts it into numbers
//the numbers are then evaluated depending on the arithmetic symbol used and then reduced to simplest form
int fractionCalculator (std::string input);






int main () {



  std::string input;
  history = ""; 
  solutionCount = 0;
  error = 0; 

  solution.push_back(1);
  solution.push_back(1);


  std::string intro1 = "This program allows basic arithmetic operations to be preformed";
  std::string intro2 = "on fractions, and returns the solution in simplest form.";



  for(;;) {

     system("cls");

    std::cout << std::setw(120) << std::setfill('=') << ""; 

    std::cout << "\n\n\n\n\n" << std::endl;

    std::cout << std::setfill(' ') << std::setw(60+intro1.length()/2) << std::right << intro1 << "\n" << std::endl;
    std::cout << std::setw(60+intro2.length()/2) << std::right << intro2 << std::endl;
    std::cout << std::endl;

    std::cout << history;

// fills in the balnk space deepnding on how many lines history is

    for (int i = 0; i < 17-solutionCount; i++) {

      std::cout << std::endl;

    }

  //decides if the input is valid based off if the function returned an error

    if(error == 0) {

      std::cout << std::endl;


    } else if (error == 1) {

      std::cout << "The solution is: " << solution << std::endl;

    } else if (error == 2) {

      std::cout << "Error, unable to read input" << std::endl; 

    } else if (error == 3) {
      
      std::cout << "Error, division by 0" << std::endl;
      
    }


    std::cout << std::setw(120) << std::setfill('=') << "" << std::endl;
  
    //takes the input equation from the user
    
    std::cout << "Enter equation: ";
    std::cin >> input;

    error = fractionCalculator(input);

    



  }




  return 0;

}



int fractionCalculator (std::string input) {






  oss.str("");
  oss.clear();
  std::string num0{}, num1{}, num2{}, num3{};
  int number0, number1, number2, number3, solution0, solution1;
  char symbol = ' ';
  int stringPos = 0;
  solution = "";

  //checks if the value is negative
  if (input.at(stringPos) == '-') {

    stringPos += 1;
    num0.push_back('-');
    
  
    
  }

  //makes sure the input is a number
  if (!(input.at(stringPos)-'0' < 10 && input.at(stringPos)-'0' >= 0)) {

    return 2;


  }



//evaluates the string until the first non number and appends it to a string
  while (input.at(stringPos)-'0' < 10 && input.at(stringPos)-'0' >= 0) {

    num0.push_back(input.at(stringPos));
    stringPos += 1;

    if (stringPos+1 == input.length()) {
      
      return 2;
      
    }
    

  }

  if (input.at(stringPos) == '/') {

    stringPos += 1;

  } else {
    return 2;
  }

  if (input.at(stringPos) == '-') {

    stringPos += 1;
    num1.push_back('-');
  }

  while (input.at(stringPos)-'0' < 10 && input.at(stringPos)-'0' >= 0) {

    num1.push_back(input.at(stringPos));
    stringPos += 1;

    
    if (stringPos+1 == input.length()) {
      
      return 2;
    }
    


  }

  if (input.at(stringPos) == '/' || input.at(stringPos) == '*' || input.at(stringPos) == '-' || input.at(stringPos) == '+') {

    symbol = input.at(stringPos);
    stringPos += 1;

  } else {

    return 2;

  }


  if (input.at(stringPos) == '-') {

    stringPos += 1;
    num2.push_back('-');

  }


  while (input.at(stringPos)-'0' < 10 && input.at(stringPos)-'0' >= 0) {

    num2.push_back(input.at(stringPos));
    stringPos += 1;
      
    
    if (stringPos+1 == input.length()) {
      
      return 2;
    }
    

  }

  if (input.at(stringPos) == '/') {

    stringPos += 1;

  } else {
    return 2;
  }



  if (input.at(stringPos) == '-') {

    stringPos += 1;
    num3.push_back('-');
    
  }

  while (stringPos < input.length()) {


    if (input.at(stringPos)-'0' < 10 && input.at(stringPos)-'0' >= 0) {

      num3.push_back(input.at(stringPos));
      stringPos += 1;



    } else {

      return 2;

    }

  }


 //converts the strings to integers 

  number0 = std::stoi(num0);

  number1 = std::stoi(num1);

  number2 = std::stoi(num2);

  number3 = std::stoi(num3);


  
//conconates the equation  using a string stream
  oss << num0 << "/" << num1 << symbol << num2 << "/" << num3 << "=";
  

  if (symbol == '/') {

    solution0 = number0 * number3;
    solution1 = number1 * number2;

  } else if (symbol == '*') {

    solution0 = number0*number2;
    solution1 = number1*number3;


  } else if (symbol == '+') {

    solution1 = number1*number3;

    number0 *= number3;
    number2 *= number1;

    solution0 = number0 + number2;




  } else if (symbol == '-') {


    solution1 = number1*number3;

    number0 *= number3;
    number2 *= number1;

    solution0 = number0 - number2;

  }

//fraction reducer


  //makes the denominator 
  if (solution1 < 0) {

    solution1 *= -1;
    solution0 *= -1;
  }
  //divides the numerator and denominator by common factors
  for (int i=solution1; i > 1; i--) {

    if (solution0%i == 0 && solution1%i == 0) {
      
      solution0 /= i;
      solution1 /= i;

      i=solution1;
  
    }

  }
  


  oss << solution0;

  //checks if the denomitor is one 
  if (solution1 != 1) {

  oss << "/" << solution1;

  }
  solution += oss.str();

//replace a blank line with new line in history 
  solutionCount += 1;

  if (solutionCount < 15) {

    history += solution + "\n";

  }

  return 1;

}




