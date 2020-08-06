#ifndef apds_H
#define apds_H
#include <vector>
#include <algorithm>
#include <numeric>  
#include <string>
#include <student.h>
class APDS
{
public:
	APDS(std::vector<Student>& students, size_t capacity = 3);
	//this constructor is made so we can handel l value input
	APDS(std::vector<Student>&& students, size_t capacity = 3);
	APDS();
	~APDS();
	bool push(Student&);
	bool pop();
	size_t getSize();
	size_t getCapacity();
	Student* getHeadStudent();
	Student* searchByID(long id);
	Student& go(int n);
	void show()const;
	void setCapacity(size_t i);
	void setName(std::string s)const;
	Student& operator[](int i);
	//these fucntions are friend and have access to private members
    friend std::ostream &operator<<(std::ostream &os, APDS& ap);
	friend void show(const APDS&);
private:
	struct Item
	{
		Item(Student&);
		Item()=default;
		Item(Item*) ;
		Student* ps{ nullptr };
		Item* pnext{ nullptr };
		Item* pprev{ nullptr };

	};
	size_t capacity;
	Student S_Temp{ 0,0,0,0,0 };
	std::string name{ "AP Data Structure" };
	size_t size{ 0 };
	Item* phead{ nullptr };
	Item* ptail{ nullptr };
};


#endif