#include<aphw4.h>

std::vector<Student> getData(const char* filename)
{
    //opens the file
	std::ifstream Student_data;
	Student_data.open(filename);
    std::vector<Student> Student_Vector; 
    std::string line;
    
    
    while(Student_data.good())
    {
        std::vector<double> temp;
        for (size_t i = 0; i < 4; i++)
        {
            std::getline(Student_data, line,',');
            temp.push_back(std::stod(line));
            
        }
        //it makes temp vector
        std::getline(Student_data, line,'\n');
        temp.push_back(std::stod(line));
        //make a student with the values
        Student ST{static_cast<long>(temp[0]),temp[1],temp[2],temp[3],temp[4]};
        //and push it in student vector
        Student_Vector.push_back(ST);
    }
    Student_data.close();
    return Student_Vector;
}
void show(std::vector<Student> student)
{
    //it shows a student
    size_t rows{ student.size()} ;
    for (size_t i = 0; i < rows; i++)
    {    
       
        std::cout<< "Student ID:" << std::setw(10) << student[i].getID() <<std::setw(10);
        std::cout<< "Homework:" << std::setw(10) << student[i].getHomework() << std::setw(10);
        std::cout<< "Midterm Project:" << std::setw(10) << student[i].getMidtermProject() << std::setw(10);
        std::cout<< "Party:" << std::setw(10) << student[i].getParty() << std::setw(10);
        std::cout << "Value:" << std::setw(10) << student[i].value() <<std::endl;
    }
    
}
void show(const APDS& ap)
{
	//it is a friend function so it has access to private members
	std::cout << "Name: " << ap.name << std::endl;
	std::cout << "Capacity: " << ap.capacity << std::endl;
	std::cout << "Size: " << ap.size << std::endl;

	std::cout << std::left << std::setw(15) << "NO";
	std::cout << std::left << std::setw(15) << "ID";
	std::cout << std::left << std::setw(15) << "HomeWork";
	std::cout << std::left << std::setw(15) << "MidProject";
	std::cout << std::left << std::setw(15) << "MidExam" << std::setw(15);
	std::cout << std::left << std::setw(15) << "Party" << std::setw(15);
	std::cout << std::left << std::setw(15) << "Value" << std::endl;
	APDS::Item* temp_item{ ap.phead };
	for (size_t i = 0; i < ap.size; i++)
	{
        if(i==0)
            {
                std::cout<<"the student with the highest value is :"<<std::endl;
                for(size_t j=0;j<120;j++)
                std::cout<<"*";
                std::cout<<std::endl;
            }
        else if(i==ap.size-1)
            {
                std::cout<<"and the student with the lest value is :"<<std::endl;
                for(size_t j=0;j<120;j++)
                std::cout<<"*";
                std::cout<<std::endl;
            }
		std::cout << std::left << std::setw(15) << i+1<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getID()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getHomework()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getMidtermProject()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getMidtermExam() << std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getParty() << std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->value() << std::endl;
        if(i==0)
        {
            for(size_t j=0;j<120;j++)
            std::cout<<"*";
            std::cout<<std::endl;
        }
        else if(i==ap.size-1)
        {
            for(size_t j=0;j<120;j++)
            std::cout<<"*";
            std::cout<<std::endl;
        }
		temp_item = temp_item->pnext;

	}
}