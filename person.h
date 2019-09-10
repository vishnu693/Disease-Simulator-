#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
 
using namespace std;
class person{
	public:
		person();
		char getStatus();
		int getInfectPeriod();
		void setStatus(char c);
		void setInfectPeriod(int i);
	
	private:
		char status;
		int infectedPeriod;
};

#endif

