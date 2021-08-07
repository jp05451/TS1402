#pragma once
#include"School.h"

class PrivateSchool :public School
{
	PrivateSchool():School(){}
	PrivateSchool(string str,float amount):School(str,amount){}
};
