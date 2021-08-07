#pragma once
#include<string>
#include<iostream>

using namespace std;

class School
{
public:
	School(){}
	School(string str, float amount) :name(str), studentAmount(amount),studentAmountNextYear(amount) {}
	void admissions(float amount);
	bool dropouts(float amount);
	bool transfer(float amount, School& toSchool);

	float getStudent();
	void setStudent(float);
	float getStudentNextYear();
	void setStudentNextYear(float);

	friend ostream& operator << (ostream& ostr, School& S);
private:
	float studentAmount=0;
	float studentAmountNextYear=0;
	string name="";
};


class PublicSchool :public School
{
public:
	PublicSchool() :School() {}
	PublicSchool(string str, float amount) :School(str, amount) {}
	void apply_growth();
	bool dropouts(float);
	void admissions(float);
	bool transfer(float, School&);
};


class PrivateSchool :public School
{
public:
	PrivateSchool() :School() {}
	PrivateSchool(string str, float amount) :School(str, amount) {}
	bool dropouts(float); 
	bool transfer(float, School&);
};
