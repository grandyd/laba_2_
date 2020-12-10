#include "Users.h"
#include <iostream>



Users::Users()
{
	this->Name = "Empty";
	this->PhoneNumber = "Empty";
	this->Adress = "Empty";
	this->TypeOfBuilding = "Empty";
	this->Price = 0;
}
Users::Users(const MyString& name, const MyString& phonenumber, const MyString& adress, const MyString& typeofbuilding, const int price, const MyDate& date)
{
	this->Name = name;
	this->PhoneNumber = phonenumber;
	this->Adress = adress;
	this->TypeOfBuilding = typeofbuilding;
	this->Price = price;
	this->Date = date;
}
Users::Users(const Users& user)
{
	this->Name = user.Name;
	this->PhoneNumber = user.PhoneNumber;
	this->Adress = user.Adress;
	this->TypeOfBuilding = user.TypeOfBuilding;
	this->Price = user.Price;
	this->Date = user.Date;
}

bool Users::Equal(const Users& user)
{
	if (this->Name != user.Name || this->PhoneNumber != user.PhoneNumber || this->Adress != user.Adress || this->TypeOfBuilding != user.TypeOfBuilding || this->Price != user.Price || this->Date != user.Date)
	{
		return false;
	}
	return true;
}

Users::~Users()
{
}

Users& Users::operator=(const Users& user)
{
	this->Name = user.Name;
	this->PhoneNumber = user.PhoneNumber;
	this->Adress = user.Adress;
	this->TypeOfBuilding = user.TypeOfBuilding;
	this->Price = user.Price;
	this->Date = user.Date;
	return
		*this;
}

void Users::ChangeName(const MyString& Name)
{
	this->Name = Name;
}

void Users::ChangePhoneNumber(const MyString& PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}

void Users::ChangeAdress(const MyString& Adress)
{
	this->Adress = Adress;
}

void Users::ChangeTypeOfBuilding(const MyString& TypeOfBuilding)
{
	this->TypeOfBuilding = TypeOfBuilding;
}

void Users::ChangePrice(const int Price)
{
	this->Price = Price;
}

void Users::ChangeDate(const MyDate& Date)
{
	this->Date = Date;
}

bool operator==(const Users& user1, const Users& user2)
{
	if (user1.Name != user2.Name || user1.PhoneNumber != user2.PhoneNumber || user1.Adress != user2.Adress || this->TypeOfBuilding != user.TypeOfBuilding || user1.Price != user2.Price || user1.Date != user2.Date)
	{
		return false;
	}
	return true;
}
bool operator!=(const Users& user1, const Users& user2)
{
	return !(user1 == user2);
}

std::ostream& operator<<(std::ostream& out, const Users& user)
{
	out << user.Name << "\t" << user.PhoneNumber << "\t" << user.Adress << "\t" << user.TypeOfBuilding << "\t" << user.Price << "\t" << user.Date << "\n";
	return out;
}
std::istream& operator>>(std::istream& in, Users& user)
{
	std::cout << "Please input Name\n";
	in >> user.Name;
	std::cout << "Please input Phone Number\n";
	in >> user.PhoneNumber;
	std::cout << "Please input Adress\n";
	in >> user.Adress;
	std::cout << "Please input Type of Building\n";
	in >> user.TypeOfBuilding;
	std::cout << "Please input Price\n";
	in >> user.Price;
	std::cout << "Please input Date\n";
	in >> user.Date;
	return in;
}

int CmpName(const Users& user1, const Users& user2)
{
	if (user1.Name > user2.Name)
	{
		return 1;
	}
	if (user1.Name == user1.Name)
	{
		return 0;
	}
	return -1;
}
int CmpPhoneNuber(const Users& user1, const Users& user2)
{
	if (user1.PhoneNumber > user2.PhoneNumber)
	{
		return 1;
	}
	if (user1.PhoneNumber == user1.PhoneNumber)
	{
		return 0;
	}
	return -1;
}
int CmpAdress(const Users& user1, const Users& user2)
{
	if (user1.Adress > user2.Adress)
	{
		return 1;
	}
	if (user1.Adress == user1.Adress)
	{
		return 0;
	}
	return -1;
}
int CmpTypeOfBuilding(const Users& user1, const Users& user2)
{
	if (user1.TypeOfBuilding > user2.TypeOfBuilding)
	{
		return 1;
	}
	if (user1.TypeOfBuilding == user1.TypeOfBuilding)
	{
		return 0;
	}
	return -1;
}
int CmpPrice(const Users& user1, const Users& user2)
{
	if (user1.Price > user2.Price)
	{
		return 1;
	}
	if (user1.Price == user1.Price)
	{
		return 0;
	}
	return -1;
}
int CmpDate(const Users& user1, const Users& user2)
{
	if (user1.Date > user2.Date)
	{
		return 1;
	}
	if (user1.Date == user1.Date)
	{
		return 0;
	}
	return -1;
}


