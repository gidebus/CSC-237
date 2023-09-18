//  Demonstration of C++ sizeof() operator.
//
#include <iostream>  // necessary to use cout, endl operators.

int main() {
	// Define variables of different types:
	bool bVariable;                     // boolean
	char cVariable;                     // signed character
	unsigned char ucVariable;           // unsigned character        
	short sVariable;                    // signed short integer
	unsigned short usVariable;          // unsigned short integer
	int iVariable;                      // signed integer
	unsigned int uiVariable;            // unsigned integer
	long lVariable;                     // signed long integer
	unsigned long ulVariable;           // unsigned long integer
	long long int llVariable;           // signed long long integer
	unsigned long long int ullVariable; // unsigned long long integer
	float fVariable;                    // single-precision floating point 
	double dVariable;                   // double-precision floating point
	long double ldVariable;             // long double-precision floating point

	std::cout<<"Output sizeof() value for variables of different types:"<<std::endl;
	std::cout<<"sizeof(bool) =               "<<sizeof(bVariable)<<std::endl;
	std::cout<<"sizeof(char) =               "<<sizeof(cVariable)<<std::endl;
	std::cout<<"sizeof(unsigned char) =      "<<sizeof(ucVariable)<<std::endl;
	std::cout<<"sizeof(short) =              "<<sizeof(sVariable)<<std::endl;
	std::cout<<"sizeof(unsigned short) =     "<<sizeof(usVariable)<<std::endl;
	std::cout<<"sizeof(int) =                "<<sizeof(iVariable)<<std::endl;
	std::cout<<"sizeof(unsigned int) =       "<<sizeof(uiVariable)<<std::endl;
	std::cout<<"sizeof(long) =               "<<sizeof(lVariable)<<std::endl;
	std::cout<<"sizeof(unsigned long) =      "<<sizeof(ulVariable)<<std::endl;
	std::cout<<"sizeof(long long) =          "<<sizeof(llVariable)<<std::endl;
	std::cout<<"sizeof(unsigned long long) = "<<sizeof(ullVariable)<<std::endl;
	std::cout<<"sizeof(float) =              "<<sizeof(fVariable)<<std::endl;
	std::cout<<"sizeof(double) =             "<<sizeof(dVariable)<<std::endl;
	std::cout<<"sizeof(long double) =        "<<sizeof(ldVariable)<<std::endl;

}