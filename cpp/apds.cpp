#include<apds.h>


APDS::APDS(std::vector<Student>& students, size_t capacity)
{
	//initializing private values
	this->capacity = capacity;
	size_t i{ 0 };
	//and we push every student in the Data_struct
	while (i < capacity&& i < students.size())
	{
		push(students[i]);
		i++;
	}

}
APDS::APDS(std::vector<Student>&& students, size_t capacity)
{
	//initializing private values
	this->capacity = capacity;
	size_t i{ 0 };
	//and we push every student in the Data_struct
	while (i < capacity && i < students.size())
	{
		push(students[i]);
		i++;
	}

}
APDS::APDS()
{
	//makes a empty data_struct
	this->capacity = 3;
	this->size = 0;
}

APDS::~APDS()
{
	//it pop (start from ptail) until the phead become nullptr
	while(size!=0)
	{
		pop();
	}
	ptail=nullptr;
	size=0;
}

bool APDS::push(Student& S)
{
	
	if (ptail == nullptr)
	{
		// if it is the first data so all the pointer are poining to nullptr
		Item* new_item = new Item{ S };
		phead = new_item;
		ptail = new_item;
		new_item->pnext = new_item;
		new_item->pprev = new_item;
		this->size++;
		return true;
	}
	else if (size < capacity)
	{
		//if the value is more than head value it becomes the new head
		Item* new_item = new Item{ S };
		if (S.value() > phead->ps->value())
		{
			phead->pprev = new_item;
			new_item->pnext = phead;
			new_item->pprev = ptail;
			phead = new_item;
			ptail->pnext = new_item;
			size++;
			return true;
		}
		else if (ptail->ps->value() < S.value())
		{
			//if the value is more than head tail it should be previous to ptail
			new_item->pprev = ptail->pprev;
			new_item->pnext = ptail;
			ptail->pprev->pnext = new_item;
			ptail->pprev = new_item;
			//and we check it with previous ones
			while (S.value() > new_item->pprev->ps->value())
			{
				new_item->pprev->pnext = new_item->pnext;
				new_item->pnext->pprev = new_item->pprev;
				new_item->pnext = new_item->pprev;
				new_item->pprev->pprev->pnext = new_item;
				new_item->pprev = new_item->pprev->pprev;
				new_item->pnext->pprev = new_item;
			}
			this->size++;
			return true;
		}
		else
		{
			//if the value is not more than tail value it becomes the new tial
			new_item->pprev = ptail;
			new_item->pnext = phead;
			ptail->pnext = new_item;
			phead->pprev = new_item;
			ptail = new_item;
			this->size++;
			return true;
		}
	}

	else if (ptail->ps->value() < S.value() && size >= capacity)
	{
		Item* new_item = new Item{ S };
		new_item->pprev = ptail->pprev;
		new_item->pnext = ptail;
		ptail->pprev->pnext = new_item;
		ptail->pprev = new_item;
		pop();
		while (S.value() > new_item->pprev->ps->value())
		{
			new_item->pprev->pnext = new_item->pnext;
			new_item->pnext->pprev = new_item->pprev;
			new_item->pnext = new_item->pprev;
			new_item->pprev->pprev->pnext = new_item;
			new_item->pprev = new_item->pprev->pprev;
			new_item->pnext->pprev = new_item;
		}
		if (S.value() > phead->ps->value())
		{
			ptail->pprev = new_item;
			ptail->pnext = new_item;
			new_item->pprev = ptail;
			new_item->pnext =phead;
			phead=new_item;
		}
		return true;
	}
	else
		return false;
}


bool APDS::pop()
{
	//we delete the tail
	if (size != 0)
	{
		phead->pprev = ptail->pprev;
		delete ptail;
		ptail = phead->pprev;
		ptail->pnext =phead;
		size--;
		return true;
	}
	else
		return false;
}
size_t APDS::getSize()
{
	//to access the size value
	return size;
}
size_t APDS::getCapacity()
{
	//to access the capacity value
	return capacity;
}

Student* APDS::getHeadStudent()
{
	//to access the phead value
	return phead->ps;
}

Student* APDS::searchByID(long id)
{
	//it starts from the head
	Item* temp_item{ phead };
	for (size_t i = 0; i < size; i++)
	{
		if (temp_item->ps->getID() == id)
		{
			//and if it's not in the where the pointer is it goes next
			return temp_item->ps;
		}
		else
			temp_item = temp_item->pnext;
	}
	//if it wasn't in the struct it returns NULL
	return nullptr;
}

Student& APDS::go(int n)
{
	if (n > 0)
	{
		//it starts from head
		Item* temp_item{ phead };
		//and goes n time next to get to the point
		for (int i = 0; i < n; i++)
		{
			temp_item = temp_item->pnext;
		}
		return *temp_item->ps;
	}
	else
	{
		//it starts from head
		Item* temp_item{ phead };
		//and goes n time pprev to get to the point
		for (int i = 0; i < abs(n); i++)
		{
			temp_item = temp_item->pprev;
		}
		return *temp_item->ps;
	}
}

void APDS::show()const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Capacity: " << capacity << std::endl;
	std::cout << "Size: " << size << std::endl;

	std::cout << std::left << std::setw(15) << "NO";
	std::cout << std::left << std::setw(15) << "ID";
	std::cout << std::left << std::setw(15) << "HomeWork";
	std::cout << std::left << std::setw(15) << "MidProject";
	std::cout << std::left << std::setw(15) << "MidExam" << std::setw(15);
	std::cout << std::left << std::setw(15) << "Party" << std::setw(15);
	std::cout << std::left << std::setw(15) << "Value" << std::endl;
	Item* temp_item{ phead };
	for (size_t i = 0; i < size; i++)
	{
		std::cout << std::left << std::setw(15) << i+1<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getID()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getHomework()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getMidtermProject()<< std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getMidtermExam() << std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->getParty() << std::setw(15);
		std::cout << std::left << std::setw(15) << temp_item->ps->value() << std::endl;
		temp_item = temp_item->pnext;

	}


}

void APDS::setCapacity(size_t i)
{
	//if new capacity is less than the last one it pops
	if (i < capacity)
	{
		for (size_t j = 0; j < this->capacity - i; j++)
		{
			pop();
		}
		this->capacity = i;
	}
	else
	this->capacity = i;
}
void APDS::setName(std::string s)const
{
	//so we can access the name
	std::string* a = const_cast<std::string*>(&name);
	*a = s;
}
Student& APDS::operator[](int i)
{
	//if the i is in the range it will return the students
	if(abs(i)<=size)
	return go(i);
	else
	{
		//if it's not it returns a student with all values are zero
		return S_Temp;	
	}

}
APDS::Item::Item(Student& S)
{
	//initializing values
	this->ps = &S;
	this->pnext = nullptr;
	this->pprev = nullptr;
}
APDS::Item::Item(Item* S)
{
	//initializing values
	pnext = S->pnext;
	pprev = S->pprev;
	ps = S->ps;
}

std::ostream &operator<<(std::ostream &os, APDS& ap)
{
	//it is a friend function so it has access to private members
    os << "Name: " << ap.name << std::endl;
	os << "Capacity: " << ap.capacity << std::endl;
	os << "Size: " << ap.size << std::endl;

	os << std::left << std::setw(15) << "NO";
	os << std::left << std::setw(15) << "ID";
	os << std::left << std::setw(15) << "HomeWork";
	os << std::left << std::setw(15) << "MidProject";
	os << std::left << std::setw(15) << "MidExam" << std::setw(15);
	os << std::left << std::setw(15) << "Party" << std::setw(15);
	os << std::left << std::setw(15) << "Value" << std::endl;
	APDS::Item* temp_item{ ap.phead };
	for (size_t i = 0; i < ap.size; i++)
	{
		os << std::left << std::setw(15) << i+1<< std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->getID()<< std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->getHomework()<< std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->getMidtermProject()<< std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->getMidtermExam() << std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->getParty() << std::setw(15);
		os << std::left << std::setw(15) << temp_item->ps->value() << std::endl;
		temp_item = temp_item->pnext;

	}
	return os;

} 

