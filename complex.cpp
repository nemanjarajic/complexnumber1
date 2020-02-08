#include "complex.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <stdlib.h>

using namespace std;

 complex complex::complex_parse(string s)
{
 	//Declare local variables to pass to object
	 double real = 0;
	 double imag = 0;
 	
	//complex number Ex: 2+3i
	regex a("([-]?[0-9]+\\.?[0-9]?)([-|+]+[0-9]+\\.?[0-9]?)[i$]+");
	//only real number
	regex b("([-]?[0-9]+\\.?[0-9]?)$");
	//only imaginary number
	regex c("([-]?[0-9]+\\.?[0-9]?)[i$]");
	//number then i with positive i
	regex d("([-]?[0-9]+\\.?[0-9]?)[+][i$]+");
 	//number then i with negative i
	regex e("([-]?[0-9]+\\.?[0-9]?)[-][i$]+");
	smatch match;

	if(regex_search(s,match,a)) //matches with real number and complex number
	{
		real = atof(match.str(1).c_str());
		imag = atof(match.str(2).c_str());

	}
	else if(regex_search(s, match, b)) //matches with real number
	{
		real = atof(match.str(1).c_str());
		imag = 0;
		
	}else if(regex_search(s, match, c))	//matches with imaginary number
	{
		real = 0;
		imag = atof(match.str(1).c_str());
		
	}else if(regex_search(s, match, d))	//matches with imaginary + i
	{
		real = atof(match.str(1).c_str());
		imag = 1;
		
	}
	else if (regex_search(s, match, e))	//matches with imaginary + i
	{
		real = atof(match.str(1).c_str());
		imag = -1;

	}
	

 	// return 
	return complex(real, imag);
}

//constructor
complex::complex()
{
	this->imag = 0;
	this->real = 0;
}

complex::complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

void complex::read_write(string s)
{
	string line;
	ifstream file;
	ofstream file2;
 	//New instance of object
	complex result;

	//File we are getting input from
	file.open(s); //open text file with values to read
 	//Output file for complex objects
	file2.open("complexObj.txt", fstream::app);
 	
	if(!file.is_open())	// Error if program cant open the file
	{
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	while(getline(file,line))	//read file line by line
	{
		result = result + complex_parse(line); //parse line by line then save in in result
		file2 << complex_parse(line);
	}

	file.close();// close file

	file2 << "The sum is: ";
	file2 << result; //write sum of complex numbers
 	
	file2.close();
}

string complex::printFile(string s)
{
	string line;
	string str = "";
	ifstream file;
	file.open(s);

	if (!file.is_open())	// Error if program cant open the file
	{
		perror("Error open");
		exit(EXIT_FAILURE);
	}
	while (getline(file, line))	//read file line by line
	{
		str = str + line + "\n";
	}

	return str;
}


complex operator+(const complex& one, const complex& two)
{
	complex result;
	result.real = result.real + one.real + two.real;
	result.imag = result.imag + one.imag + two.imag;

	return result;
	
}

ostream& operator<<(ostream& os, const complex& one)
{
	os << one.real << " + " << one.imag << "i" << endl;
	return os;
}




