#pragma once
#include"School.h"

class PublicSchool :public School
{
	PublicSchool():School() {}
	PublicSchool(string str,float amount):School(str,amount){}
};