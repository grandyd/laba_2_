#include "Tabl.h"






void Tabl::Save()
{
	ofstream out("data.txt");
	if (!out)
	{
		cout << "Не удалось открыть файл\n";
		return;
	}
	for (int i = 0; i < this->arr.GetSize(); i++)
	{
		out.write(this->arr[i].Name+"\n",this->arr[i].Name.Len()+1);
		out.write(this->arr[i].PhoneNumber + "\n", this->arr[i].PhoneNumber.Len() + 1);
		out.write(this->arr[i].Adress + "\n", this->arr[i].Adress.Len() + 1);
		out.write(this->arr[i].TypeOfBuilding + "\n", this->arr[i].TypeOfBuilding.Len() + 1);
		char str[10];
		sprintf(str, "%d", this->arr[i].Price);
		out.write(str , strlen(str));
		out.write("\n", 1);
		/*out.write((MyString)this->arr[i].Date, 10);
		if (i!=this->arr.GetSize()-1)
		{
			out << '\n';
		}*/
		out << this->arr[i].Date;
		if (i != this->arr.GetSize() - 1)
		{
			out << '\n';
		}
	}

	out.close();
}

void Tabl::Read()
{
	ifstream in("data.txt");
	if (!in.is_open())
	{
		cout << "Не удалось открыть файл\n";
		return;
	}
	else
	{
		cout << "Файл успешно открыт и считан\n";
	}
	int index = 0;
	int tmp_int;
	MyString tmp_string;
	MyDate tmp_date;
	while (this->arr.GetSize())
	{
		this->DeleteUser(0);
	}
	while (!in.eof())
	{

		this->AddUser();
		in >> tmp_string;
		this->arr[index].Name = tmp_string;
		in >> tmp_string;
		this->arr[index].PhoneNumber = tmp_string;
		in >> tmp_string;
		this->arr[index].Adress = tmp_string;
		in >> tmp_string;
		this->arr[index].TypeOfBuilding = tmp_string;
		in >> tmp_int;
		this->arr[index].Price = tmp_int;
		in >> tmp_date;
		this->arr[index].Date = tmp_date;
		index++;
	}

	in.close();
}

int Tabl::GetSize()
{
	return this->size;
}

void Tabl::AddUser(const MyString& Name, const MyString& PhoneNumber, const MyString& Adress, const MyString& TypeOfBuilding, const int& Price, const MyDate& Date)
{
	arr.push_back(Users(Name, PhoneNumber, Adress, TypeOfBuilding, Price, Date));
	this->size++;
}

void Tabl::AddUser(const Users& user)
{
	this->arr.push_back(user);
	this->size++;
}

void Tabl::DeleteUser(const int index)
{
	this->arr.pop(index);
	this->size--;
}

void Tabl::ChangeUser(const int index, const Users& User)
{
	this->arr[index] = User;
}

void Tabl::ChangeName(const int index, const MyString& Name)
{
	this->arr[index].Name = Name;
}

void Tabl::ChangePhoneNumber(const int index, const MyString& PhoneNumber)
{
	this->arr[index].PhoneNumber = PhoneNumber;
}

void Tabl::ChangeAdress(const int index, const MyString& Adress)
{
	this->arr[index].Adress = Adress;
}

void Tabl::ChangeTypeOfBuilding(const int index, const MyString& TypeOfBuilding)
{
	this->arr[index].TypeOfBuilding = TypeOfBuilding;
}

void Tabl::ChangePrice(const int index, const int Price)
{
	this->arr[index].Price = Price;
}

void Tabl::ChangeDate(const int index, const MyDate& Date)
{
	this->arr[index].Date = Date;
}

void Tabl::Print()
{
	if (this->size==0)
	{
		cout << "Записей нет\n";
		return;
	}
	this->arr.print();
}

Users& Tabl::operator[](int index)
{
	return this->arr[index];
}

void Tabl::Create()
{
	MyString Name, Adress, TypeOfBuilding;
	int PhoneNumber, Price;
	MyDate Date;
	std::cout << "Введите имя\n";
	std::cin >> Name;
	getchar();
	system("cls");
	std::cout << "Введите номер\n";
	std::cin >> PhoneNumber;
	getchar();
	system("cls");
	std::cout << "Введите адресс\n";
	std::cin >> Adress;
	getchar();
	system("cls");
	std::cout << "Введите тип здания\n";
	std::cin >> TypeOfBuilding;
	getchar();
	system("cls");
	std::cout << "Введите цену\n";
	std::cin >> Price;
	getchar();
	system("cls");
	std::cout << "Введите дату\n";
	std::cin >> Date;
	getchar();
	system("cls");
	this->arr.push_back(Users(Name, PhoneNumber, Adress, TypeOfBuilding, Price, Date));
	this->size++;
}

list<int> Tabl::Find_Name(const MyString& Name, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (Name.In_String(this->arr[i].Name))
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (Name.In_String(this->arr[lst[i]].Name))
			{
				n.push_back(lst[i]);
			}
		}
	}
	return n;
}

list<int> Tabl::Find_PhoneNumber(const MyString& PhoneNumber, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (PhoneNumber.In_String(this->arr[i].PhoneNumber))
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (PhoneNumber.In_String(this->arr[lst[i]].PhoneNumber))
			{
				n.push_back(lst[i]);
			}
		}
	}
	return n;
}

list<int> Tabl::Find_Adress(const MyString& Adress, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (Adress.In_String(this->arr[i].Adress))
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (Adress.In_String(this->arr[lst[i]].Adress))
			{
				n.push_back(lst[i]);
			}
		}
	}
	return n;
}

list<int> Tabl::Find_TypeOfBuilding(const MyString& TypeOfBuilding, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (TypeOfBuilding.In_String(this->arr[i].TypeOfBuilding))
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (TypeOfBuilding.In_String(this->arr[lst[i]].TypeOfBuilding))
			{
				n.push_back(lst[i]);
			}
		}
	}
	return n;
}

list<int> Tabl::Find_Price(int Price, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (Price == this->arr[i].Price)
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (Price == this->arr[lst[i]].Price)
			{
				n.push_back(i);
			}
		}
	}
	return n;
}

list<int> Tabl::Find_Date(const MyDate& Date, const list<int>& lst)
{
	list<int> n;
	if (lst.Empty())
	{
		for (int i = 0; i < this->size; i++)
		{
			if (Date == this->arr[i].Date)
			{
				n.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < lst.GetSize(); i++)
		{
			if (Date == this->arr[lst[i]].Date)
			{
				n.push_back(i);
			}
		}
	}
	return n;
}

void Tabl::Sort_Name(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.Name<this->arr[j].Name&&j>=0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

void Tabl::Sort_PhoneNumber(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.PhoneNumber < this->arr[j].PhoneNumber && j >= 0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

void Tabl::Sort_Adress(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.Adress < this->arr[j].Adress && j >= 0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

void Tabl::Sort_TypeOfBuilding(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.TypeOfBuilding < this->arr[j].TypeOfBuilding && j >= 0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

void Tabl::Sort_Price(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.Price < this->arr[j].Price && j >= 0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

void Tabl::Sort_Date(bool reverse)
{
	Users tmp;
	for (int i = 1; i < this->arr.GetSize(); i++)
	{
		tmp = this->arr[i];
		int j = i - 1;
		while (tmp.Date < this->arr[j].Date && j >= 0)
		{
			this->arr[j + 1] = this->arr[j];
			j--;
		}
		this->arr[j + 1] = tmp;
	}
	if (reverse)
	{
		this->arr.revers();
	}
}

std::ostream& operator<<(std::ostream& out, const Tabl& t)
{
	out << t.arr;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, const Tabl& t)
{
	for (int i = 0; i < t.size; i++)
	{
		out << t.arr[i].GetName()<<"\n"<<t.arr[i].GetPhoneNumber()<<"\n"<<t.arr[i].GetAdress()<<"\n"<<t.arr[i].GetTypeOfBuilding()<<"\n"<<t.arr[i].GetPrice()<<"\n"<<t.arr[i].GetDate()<<"\n";
	}
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Tabl& t)
{
	int index = 0;
	int tmp_int;
	MyString tmp_string;
	MyDate tmp_date;
	while (t.arr.GetSize())
	{
		t.DeleteUser(0);
	}
	while (!in.eof())
	{

		t.AddUser();
		in >> tmp_string;
		t.arr[index].GetName() = tmp_string;
		in >> tmp_string;
		t.arr[index].GetPhoneNumber() = tmp_string;
		in >> tmp_string;
		t.arr[index].GetAdress() = tmp_string;
		in >> tmp_string;
		t.arr[index].GetTypeOfBuilding() = tmp_string;
		in >> tmp_int;
		t.arr[index].GetPrice() = tmp_int;
		in >> tmp_date;
		t.arr[index].GetDate() = tmp_date;
		index++;
	}
	return in;
}

