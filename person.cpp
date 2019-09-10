#include <iostream>
#include <string> 
#include "person.h"
using namespace std;

person::person()
{
	status ='';
	infectedPeriod =0;
}

char person::getStatus()
{
	return status;
}
int person::getInfectPeriod()
{
	return infectedPeriod;
}
void person::setStatus(char c)
{
	status = c;
}
void person::setInfectPeriod(int i)
{
	infectedPeriod = i;
}