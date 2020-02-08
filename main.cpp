#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
	complex c;
	c.read_write("complex.txt");
	cout << c.printFile("complexObj.txt");
	
	return 0;
}
