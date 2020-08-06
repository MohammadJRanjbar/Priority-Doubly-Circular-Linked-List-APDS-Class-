#include<student.h>

Student::Student (long id , double hw, double mid_proj, double mid_exam, double party)
{
    //initializing private values
    this->id = id;
    this->homework = hw;
    this->midterm_project=mid_proj;
    this->midterm_exam=mid_exam;
    this->party=party;
}
void Student::setID(long id)
{
    //so we can access ID outside of the class
    this->id = id;
}
long Student::getID()
{
    //so we can access ID outside of the class
    return this->id;
}
void Student::setHomework(double hw)
{
    //so we can access hw outside of the class
    this->homework = hw;
}
double Student::getHomework()
{
    //so we can access hw outside of the class
    return this->homework;
}
void Student::setMidtermProject(double project)
{
    //so we can access midterm_project outside of the class
    this->midterm_project = project;
}
double Student::getMidtermProject()
{
    //so we can access midterm_project outside of the class
    return this->midterm_project;
}
void Student::setMidtermExam(double exam)
{
    //so we can access midterm_exam outside of the class
    this->midterm_exam = exam;
}
double Student::getMidtermExam()
{
    //so we can access midterm_exam outside of the class
    return this->midterm_exam;
}
void Student::setParty(double party)
{
    //so we can access party outside of the class
    this->party=party;
}
double Student::getParty()
{
    //so we can access party outside of the class
    return this->party;
}
double Student::value()
{
    //calulating value based on given formula
    return static_cast<double>(-(homework+midterm_exam+midterm_project)/3)+party;
}
void Student::show()
{
    std::cout<<"Student ID:" << std::setfill(' ') << std::setw(20)  << id << std::setfill(' ') << std::setw(20);
    std::cout<<"Homework:"<< std::setfill(' ') << std::setw(20) << homework << std::setfill(' ') << std::setw(20);
    std::cout<<"Midterm Project:"<< std::setfill(' ') << std::setw(20) << midterm_project << std::setfill(' ') << std::setw(20);
    std::cout<<"Party:"<< std::setfill(' ') << std::setw(20) << party << std::setfill(' ') << std::setw(20);
    std::cout<< "Value:" << std::setfill(' ') << std::setw(20) << value();
} 
std::ostream &operator<<(std::ostream &os, Student S )
{
    //it is freind so it has accesss to private members
    os<<"Student ID:" << std::setfill(' ') << std::setw(20)  << S.id << std::setfill(' ') << std::setw(20);
    os<<"Homework:"<< std::setfill(' ') << std::setw(20) << S.homework << std::setfill(' ') << std::setw(20);
    os<<"Midterm Project:"<< std::setfill(' ') << std::setw(20) << S.midterm_project << std::setfill(' ') << std::setw(20);
    os<<"Party:"<< std::setfill(' ') << std::setw(20) << S.party << std::setfill(' ') << std::setw(20);
    os<< "Value:" << std::setfill(' ') << std::setw(20) << S.value();
    return os;
}