#ifndef student_H
#define student_H
#include<iostream>
#include <iomanip>
class Student
{
public:
	Student(long id, double hw, double mid_proj, double mid_exam, double party = 50);
	void setID(long id);
	long getID();
	void setHomework(double hw);
	double getHomework();
	void setMidtermProject(double project);
	double getMidtermProject();
	void setMidtermExam(double exam);
	double getMidtermExam();
	void setParty(double party);
	double getParty();
	double value();
	void show();
	//this function is friend and had access to private memebers
    friend std::ostream &operator<<(std::ostream &os, Student);
private:
	long id{};
	double homework{};
	double midterm_project{};
	double midterm_exam{};
	double party{};
};

#endif