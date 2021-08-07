#include"School.h"



void School::admissions(float amount)
{
	if (amount >= 0)
	{
		studentAmount += amount;
	}
}


bool School::dropouts(float amount)
{
	if (amount >= 0 && amount <= studentAmount)
	{
		studentAmount -= amount;
	}
	else
	{
		return 0;
	}
	return 1;
}

bool School::transfer(float amount, School& toSchool)
{
	if (this->dropouts(amount))
	{
		toSchool.admissions(amount);
		return 1;
	}
	return 0;
}

void School::setStudent(float amount)
{
	studentAmount = amount;
}

float School::getStudent()
{
	return studentAmount;
}

void School::setStudentNextYear(float amount)
{
		studentAmountNextYear = amount;
}

float School::getStudentNextYear()
{
	return studentAmountNextYear;
}

ostream& operator << (ostream& ostr, School& school)
{
	ostr << school.name<<"\t"<<school.studentAmount<<"\t"<<school.studentAmountNextYear;
	return ostr;
}


void PublicSchool::apply_growth()
{
	int Student;
	Student = getStudentNextYear();
	Student *= 1.05;
	setStudentNextYear(Student);

}
bool PublicSchool::dropouts(float amount)
{
	if (amount <= getStudent())
	{
		setStudent(getStudent() - amount);
		if (amount > 100)
		{
			setStudentNextYear((int)(getStudentNextYear() * 0.95));
		}
	}
	else
	{
		return 0;
	}
	return 1;
	
}

bool PublicSchool::transfer(float amount, School& S)
{
	if (dropouts(amount))
	{
		S.admissions(amount);
	}
	else
	{
		return 0;
	}
	return 1;
}

void PublicSchool::admissions(float amount)
{
	float student = getStudent();
	if (amount >= 0)
	{
		student += amount;
	}
	setStudent(student);
}

bool PrivateSchool::dropouts(float amount)
{
	float student = getStudent();
	float studentNextYear = getStudentNextYear();
	if (amount <= student)
	{
		student -= amount;
		setStudent(student);
	}
	else
	{
		return 0;
	}
	if (amount > 100)
	{
		studentNextYear -= 100;
		setStudentNextYear(studentNextYear);
	}
	return 1;
}

bool PrivateSchool::transfer(float amount, School& S)
{
	if (dropouts(amount))
	{
		S.admissions(amount);
	}
	else
	{
		return 0;
	}
	return 1;
}