#include "Users.h"
#include "Tabl.h"
#include "MyList.h"
#include <iostream>
using namespace std;
bool Letter_In_String(const MyString& str);
bool Num_In_String(const MyString& str);
int MyString_to_Int(const MyString& str);
bool Only_Num_In_String(const MyString& str);
bool MyString_is_Date(const MyString& str);
MyDate MyString_to_Date(const MyString& str);
bool Char_Is_Num(const char c);



void Print(Tabl& t);
void Add_User(Tabl& t);
void Change_User(Tabl& t);
void Save(Tabl& t);
void Read(Tabl& t);
void Delete(Tabl& t);
void Sort(Tabl& t);
int Find(Tabl& t, list<int> lst = list<int>());
int Find_Name(Tabl& t,list<int> lst = list<int>());
int Find_PhoneNumber(Tabl& t, list<int> lst = list<int>());
int Find_Adress(Tabl& t, list<int> lst = list<int>());
int Find_TypeOfBuilding(Tabl& t, list<int> lst = list<int>());
int Find_Price(Tabl& t, list<int> lst = list<int>());
int Find_Date(Tabl& t, list<int> lst = list<int>());





int main()
{
	setlocale(LC_ALL, "ru");
	Tabl t;
	
	int pick;
	pick = -1;
	

	while (pick != 0)
	{
		system("cls");
		cout << "1.������� �������� �� �����\n";
		cout << "2.�������� ������� � ������\n";
		cout << "3.���������� ��������\n";
		cout << "4.����� ������� � ������\n";
		cout << "5.�������� ������� �� ������\n";
		cout << "6.������� ������� �� ������\n";
		cout << "7.��������� ������ �������� � ����\n";
		cout << "8.��������� ������ �������� �� �����\n";
		cout << "0.����� �� ���������\n";
		cin >> pick;
		system("cls");
		switch (pick)
		{
		case 1:
			Print(t);
			break;
		case 2:
			Add_User(t);
			break;
		case 3:
			Sort(t);
			break;
		case 4:
			Find(t);
			break;
		case 5:
			Change_User(t);
			break;
		case 6:
			Delete(t);
			break;
		case 7:
			Save(t);
			break;
		case 8:
			Read(t);
			break;
		}
	}
	

	system("cls");

		
}



void Delete(Tabl& t)
{
	if (t.GetSize() == 0)
	{
		cout << "������ �������� ����\n";
		cout << "������� 0 ��� ������ � ����\n";
		MyString tmp_str;
		while (tmp_str != '0')
		{
			cin >> tmp_str;
		}
		return;
	}
	cout << "������� ������������ �������� ������ �������\n";
	int k = -1;
	int pick=-1;
	while (k == -1)
	{
		k = Find(t);
		if (k == -1)
		{
			cout << "\n��������� ����� ��������\n";
		}
		if (k==-2)
		{
			return;
		}
	}
	t.DeleteUser(k);
	cout << "������������ �����\n������� 0 ��� ������";
	while (pick!=0)
	{
		cin >> pick;
	}
}
void Sort(Tabl& t)
{
	int pick;
	cout << "�������� �������� ��� ����������\n";
	cout << "1.�� �����\n2.�� ������ ��������\n3.�� �������\n4.�� ���� ������������\n5.�� ����\n6.�� ����\n0.��������� � ����\n";
	cin >> pick;
	switch (pick)
	{
	case 1:
		t.Sort_Name();
		break;
	case 2:
		t.Sort_PhoneNumber();
		break;
	case 3:
		t.Sort_Adress();
		break;
	case 4:
		t.Sort_TypeOfBuilding();
		break;
	case 5:
		t.Sort_Price();
		break;
	case 6:
		t.Sort_Date();
		break;
	case 0:
		break;
	}
	system("cls");
	cout << "������ �������� ������������\n������� 0 ��� �������� � ����\n";
	cin >> pick;
	
}
void Change_User(Tabl& t)
{
	if (t.GetSize()==0)
	{
		cout << "������ �������� ����\n";
		cout << "������� 0 ��� ������ � ����\n";
		MyString tmp_str;
		while (tmp_str!='0')
		{
			cin >> tmp_str;
		}
		return;
	}
	cout << "������� ������������ �������� ������ ��������\n";
	int k = -1;
	int pick;
	while (k==-1)
	{
		k = Find(t);
		if (k==-1)
		{
			cout << "\n��������� ����� ��������\n";
		}
		if (k==-2)
		{
			return;
		}
	}
	cout << "����� �������� ������ ��������?\n";
	cout << "1.���\n2.����� ��������\n3.������\n4.��� ������������\n5.����\n6.����\n7,8,9,0 ������� � ������� ����\n";
	//getchar();
	cin >> pick;
	MyString tmp_str;
	switch (pick)
	{
	case 1:
		cout << "������� ����� ���: ";
		cin >> tmp_str;
		t[k].ChangeName(tmp_str);
		break;
	case 2:
		cout << "������� ����� ����� ��������: ";
		cin >> tmp_str;
		t[k].ChangePhoneNumber(tmp_str);
		break;
	case 3:
		cout << "������� ����� ������: ";
		cin >> tmp_str;
		t[k].ChangeAdress(tmp_str);
		break;
	case 4:
		cout << "������� ����� ��� ������������: ";
		cin >> tmp_str;
		t[k].ChangeTypeOfBuilding(tmp_str);
		break;
	case 5:
		cout << "������� ����� ����: ";
		int price;
		cin >> price;
		t[k].ChangePrice(price);
		break;
	case 6:
		cout << "������� ����� ����: ";
		MyDate date;
		cin >> date;
		t[k].ChangeDate(date);
		break;
	}
}

int Find(Tabl& t, list<int> lst)
{
	if (t.GetSize()==0)
	{
		cout << "��� ������� ��� ������\n";
		cout << "������� 0 ��� ������ � ����\n";
		MyString tmp_str;
		while (tmp_str!='0')
		{
			cin >> tmp_str;
		}
		return -1;
	}
	int pick;
	cout << "����� �� ������ ��������� ������ �����������?\n";
	cout << "1.�� �����\n2.�� ������ ��������\n3.�� �������\n4.�� ���� ������������\n5.�� ����\n6.�� ����\n7,8,9,0-������� �� ������� �����\n";
	cin >> pick;
	switch (pick)
	{
	case 1:
		return Find_Name(t,lst);
		break;
	case 2:
		return Find_PhoneNumber(t, lst);
		break;
	case 3:
		return Find_Adress(t, lst);
		break;
	case 4:
		return Find_TypeOfBuilding(t, lst);
		break;
	case 5:
		return Find_Price(t, lst);
		break;
	case 6:
		return Find_Date(t, lst);
		break;
	default:
		return -2;
	}
	cout << "������� 0 ��� �������� � ����\n";
	cin >> pick;

}
int Find_Name(Tabl& t, list<int> lst )
{
	char chose;
	MyString st;
	int counter;

	cout << "������� ����� ��� ������(����� �����>=2): ";
	cin >> st;
	while (st.Len()<2)
	{
		cout << "������� ����� ��� ���(����� �����>=2): ";
		cin >> st;
	}
	if (!lst.Empty())
	{
		lst = t.Find_Name(st, lst);
	}
	else
	{
		lst = t.Find_Name(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose=='1')
		{
			Find_Name(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose=='3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}
int Find_PhoneNumber(Tabl& t, list<int> lst)
{
	char chose;
	MyString st;
	int counter;

	cout << "������� ����� ��� ������(����� �����>=2): ";
	cin >> st;
	while (st.Len() < 2)
	{
		cout << "������� ����� ��� ���(����� ������>=2): ";
		cin >> st;
	}
	if (!lst.Empty())
	{
		lst = t.Find_PhoneNumber(st, lst);
	}
	else
	{
		lst = t.Find_PhoneNumber(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose == '1')
		{
			Find_PhoneNumber(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose == '3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}
int Find_Adress(Tabl& t, list<int> lst)
{
	char chose;
	MyString st;
	int counter;

	cout << "������� ����� ��� ������(����� �����>=2): ";
	cin >> st;
	while (st.Len() < 2)
	{
		cout << "������� ����� ��� ���(����� �����>=2): ";
		cin >> st;
	}
	if (!lst.Empty())
	{
		lst = t.Find_Adress(st, lst);
	}
	else
	{
		lst = t.Find_Adress(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose == '1')
		{
			Find_Adress(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose == '3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}
int Find_TypeOfBuilding(Tabl& t, list<int> lst)
{
	char chose;
	MyString st;
	int counter;

	cout << "������� ����� ��� ������(����� �����>=2): ";
	cin >> st;
	while (st.Len() < 2)
	{
		cout << "������� ����� ��� ���(����� �����>=2): ";
		cin >> st;
	}
	if (!lst.Empty())
	{
		lst = t.Find_TypeOfBuilding(st, lst);
	}
	else
	{
		lst = t.Find_TypeOfBuilding(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose == '1')
		{
			Find_TypeOfBuilding(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose == '3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}
int Find_Price(Tabl& t, list<int> lst)
{
	char chose;
	int st;
	int counter;

	cout << "������� ���� ��� ������: ";
	cin >> st;
	if (!lst.Empty())
	{
		lst = t.Find_Price(st, lst);
	}
	else
	{
		lst = t.Find_Price(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose == '1')
		{
			Find_Price(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose == '3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}
int Find_Date(Tabl& t, list<int> lst)
{
	char chose;
	MyDate st;
	int counter;

	cout << "������� ���� ��� ������: ";
	cin >> st;
	if (!lst.Empty())
	{
		lst = t.Find_Date(st, lst);
	}
	else
	{
		lst = t.Find_Date(st);
	}
	counter = lst.GetSize();
	if (counter == 0)
	{
		cout << "�� ������ ������� ������ �� �������";
		return -1;
	}
	for (int i = 0; i < counter; i++)
	{
		cout << t[lst[i]];
	}
	if (counter != 1)
	{
		cout << "��� �� ������ ���������� �����?\n";
		cout << "1.����� �� �������� ���������\n2.�������� �������� ������\n3.���������� ����� �� ���� ���������\n4.��������� �� ������� �����\n";
		cin >> chose;
		if (chose == '1')
		{
			Find_Date(t, lst);
		}
		else if (chose == '2')
		{
			Find(t, lst);
		}
		else if (chose == '3')
		{
			Find(t);
		}
		else {
			return -1;
		}
	}
	return lst[0];
}

void Print(Tabl& t)
{
	t.Print();
	int pick=-1;
	while (pick != 0)
	{
		cout << "������� 0 ��� ������\n";
		cin >> pick;
	}
}

void Add_User(Tabl& t)//�������� ���������
{
	Users user;
	MyString tmp_str;
	MyDate tmp_date;
	cout << "������� ���: ";
	cin >> tmp_str;
	while(Num_In_String(tmp_str)||tmp_str.Len()<2)
	{
		cout << "�� ����� ������������ ���. ������� ��� ���\n";
		cin >> tmp_str;
	}
	user.GetName() = tmp_str;
	cout << "������� ����� ��������: ";
	cin >> tmp_str;
	while (Letter_In_String(tmp_str) || tmp_str.Len() !=11)
	{
		cout << "�� ����� ������������ ����� ��������. ������� ��� ���\n";
		cin >> tmp_str;
	}
	user.GetPhoneNumber() = tmp_str;
	cout << "������� ������: ";
	cin >> tmp_str;
	while (tmp_str.Len() < 2)
	{
		cout << "�� ����� ������������ ������. ������� ��� ���\n";
		cin >> tmp_str;
	}
	user.GetAdress() = tmp_str;
	cout << "������� ��� ������������: ";
	cin >> tmp_str;
	user.GetTypeOfBuilding() = tmp_str;
	cout << "������� ����: ";
	cin >> tmp_str;
	while (!Only_Num_In_String(tmp_str))
	{
		cout << "�� ����� ������������ ����. ������� ��� ���\n";
		cin >> tmp_str;
	}
	user.GetPrice() = MyString_to_Int(tmp_str);
	cout << "������� ����: ";
	cin >> tmp_str;
	while (!MyString_is_Date(tmp_str))
	{
		cout << "�� ����� ������������ ����(�� �� ����). ������� ��� ���\n";
		cin >> tmp_str;
	}
	user.GetDate() = MyString_to_Date(tmp_str);

	for (int i = 0; i < t.GetSize(); i++)
	{
		if (t[i]==user)
		{
			cout << "���� ������ ��� ������������ � ������\n";
			cout << "������� 0 ��� ������ � ����";
			while (tmp_str!='0')
			{
				cin >> tmp_str;
			}
			return;
		}
	}
	t.AddUser(user);
}

void Read(Tabl& t)
{
	t.Read();
	int pick = -1;
	while (pick != 0)
	{
		cout << "������� 0 ��� ������\n";
		cin >> pick;
	}
}
void Save(Tabl& t)
{
	if (t.GetSize() == 0)
	{
		cout << "������ �������� ����\n";
		cout << "�� �������, ��� ������ ��� ���������?\n1.��\t2.���\n";
		MyString tmp_str;
		while (true)
		{
			cin >> tmp_str;
			if (tmp_str=="2" || tmp_str=="1")
			{
				break;
			}
		}
		if (tmp_str=="2")
		{
			return;
		}
	}
	t.Save();
	cout << "������� ������� ���������\n������� 0 ��� ������";
	int pick=-1;
	while (pick!=0)
	{
		cin >> pick;
	}
}

/////////////////////////
//��������� ����������
bool Letter_In_String(const MyString& str)
{
	for (int i = 0; i < str.Len(); i++)
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '�' && str[i] <= '�') || (str[i] >= '�' && str[i] <= '�'))
		{
			return true;
		}
	}
	return false;
}

bool Num_In_String(const MyString& str)
{
	for (int i = 0; i < str.Len(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			return true;
		}
	}
	return false;
}

int MyString_to_Int(const MyString& str)
{
	int tmp = 0;
	for (int i = 0; i < str.Len(); i++)
	{
		tmp *= 10;
		tmp += str[i] - '0';
		
	}
	return tmp;
}

bool Only_Num_In_String(const MyString& str)
{
	for (int i = 0; i < str.Len(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}
	return true;
}

bool MyString_is_Date(const MyString& str)
{
	if (Char_Is_Num(str[0]) && Char_Is_Num(str[1]) && Char_Is_Num(str[3]) && Char_Is_Num(str[4]) && Char_Is_Num(str[6]) && Char_Is_Num(str[7]) && Char_Is_Num(str[8]) && Char_Is_Num(str[9]) && ((str[2] == ' ' && str[5] == ' ') || (str[2] == '.' && str[5] == '.')))
	{
		return true;
	}
	return false;
}

//MyDate MyString_to_Date(const MyString& str)
//{
//	int dd, mm, yyyy;
//	dd = (str[0] - '0') * 10 + str[1] - '0';
//	mm = (str[3] - '0') * 10 + str[4] - '0';
//	yyyy = ((str[6] - '0') * 10) + ((str[7] - '0') * 10) + ((str[8] - '0') * 10) + (str[9] - '0');
//	return MyDate(dd, mm, yyyy);
//}
MyDate MyString_to_Date(const MyString& str)
{
	int dd = 0, mm = 0, yyyy = 0;
	int i = 0;
	while (str[i] != '.')
	{
		dd *= 10;
		dd += (str[i] - '0');
		i++;

	}
	i++;
	while (str[i] != '.')
	{
		mm *= 10;
		mm += (str[i] - '0');
		i++;
	}
	i++;
	while (str[i] != '\0')
	{
		yyyy *= 10;
		yyyy += (str[i] - '0');
		i++;
	}

	return MyDate(dd, mm, yyyy);
}
bool Char_Is_Num(const char c)
{
	if (c>='0'&&c<='9')
	{
		return true;
	}
	return false;
}


