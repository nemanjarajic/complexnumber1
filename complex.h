#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

using namespace std;

class complex
{

	friend ostream& operator<< (ostream&, const complex&);
	friend complex operator+(const complex& one, const complex& two);
	
public:
	complex complex_parse(string);
	complex(double real, double imag);
	complex();
	void read_write(string);
	string printFile(string);
private:
	double real;
	double imag;
	
};

#endif
