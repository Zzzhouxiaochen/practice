#include<iostream>
#include <string>
#include <fstream>
using namespace std;
/*-------------------------------------�� �� ��-------------------------------------*/
class CCommon//������ 
{
protected:
	int number;//��� 
	string name;//���� 
	string sex;//�Ա� 
	int age;//���� 
};
/*------------------------�� ʦ ��--------------------------------------*/
class Cteacher :
	public CCommon//��ʦ�� 
{
protected:
	string department;//����ϵ�� 
	string profession;//רҵ  
	string position;//ְ�� 
public:
	void set(int _number, string _name, string _sex, int _age, string _department, string
		_profession, string _position)
	{
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		department = _department;
		profession = _profession;
		position = _position;
	}//�����ʦ���� 
	void output();
	~Cteacher()
	{
	}//�������� 
	friend int find_nu(Cteacher teacher[], int _nu, int &t);
	friend int find_na(Cteacher teacher[], string _na, int &t);
	friend void add(Cteacher teacher[], int _fa);
	friend void dele(Cteacher teacher[], int _fa);
	friend void closefile(Cteacher teacher[], int &t);
	friend void _statistics(Cteacher teacher[], int &t);
};
void teacher_manage();
/*----------------------------ʵ �� Ա ��-------------------------------------------*/
class Cassistant :public CCommon//ʵ��Ա�� 
{
protected:
	string laboratory;//����ʵ���� 
	string position;//ְ�� 
public:
	void set(int _number, string _name, string _sex, int _age, string _laboratory, string
		_position)
	{
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		laboratory = _laboratory;
		position = _position;
	}//����ʵ��Ա���� 
	void output();
	~Cassistant()
	{
	}//�������� 
	friend int find_nu(Cassistant assistant[], int _nu, int &t);
	friend int find_na(Cassistant assistant[], string _na, int &t);
	friend void add(Cassistant assistant[], int _fa);
	friend void dele(Cassistant assistant[], int _fa);
	friend void closefile(Cassistant assistant[], int &t);
	friend void _statistics(Cassistant assistant[], int &t);
};
void assistant_manage();
/*----------------------------�� �� �� Ա ��--------------------------------------------*/
class Cexecution :public CCommon//������Ա�� 
{
protected:
	string politics;//������ò 
	string position;//ְ�� 
public:
	void set(int _number, string _name, string _sex, int _age, string _politics, string
		_position)
	{
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		politics = _politics;
		position = _position;
	}//����������Ա���� 
	void output();
	~Cexecution()
	{
	}//��������  
	friend int find_nu(Cexecution execution[], int _nu, int &t);
	friend int find_na(Cexecution execution[], string _na, int &t);
	friend void add(Cexecution execution[], int _fa);
	friend void dele(Cexecution execution[], int _fa);
	friend void closefile(Cexecution execution[], int &t);
	friend void _statistics(Cexecution execution[], int &t);
};
void execution_manage();
/*---------------------------�� �� �� Ա �� �� ʦ ��-------------------------------------*/
class Ctea_exe :public CCommon//������Ա���ʦ�� 
{
protected:
	string politics;//������ò 
	string department;//����ϵ�� 
	string profession;//רҵ 
	string position;//ְ�� 
public:
	void set(int _number, string _name, string _sex, int _age, string _politics, string
		_department, string _profession, string _position)
	{
		number = _number;
		name = _name;
		sex = _sex;
		age = _age;
		politics = _politics;
		department = _department;
		profession = _profession;
		position = _position;
	}//����������Ա���ʦ���� 
	void output();
	~Ctea_exe()
	{
	}//�������� 
	friend int find_nu(Ctea_exe tea_exe[], int _nu, int &t);
	friend int find_na(Ctea_exe tea_exe[], string _na, int &t);
	friend void add(Ctea_exe tea_exe[], int _fa);
	friend void dele(Ctea_exe tea_exe[], int _fa);
	friend void closefile(Ctea_exe tea_exe[], int &t);
	friend void _statistics(Ctea_exe tea_exe[], int &t);
};
void tea_exe_manage();
/*---------------------------------ͳ �� �� �� ��---------------------------------------*/
void statistics_all();//����ͳ���� 
void statistics_teacher();
void statistics_assistant();
void statistics_execution();
void statistics_tea_exe();
void order();
const int Max = 100;//����Ա���������ֵ 

#include "stdio.h"
/*----------------------------��ʦ���еĸ�����������-----------------------*/
void Cteacher::output()//��ʦ������������ 
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << department << "\t" << profession << "\t";
	cout << position << endl;
}
void teacher_muen()//��ʦ���˵� 
{
	cout << endl;
	cout << "***********��ӭ�����ʦ��Ϣ����ϵͳ***********" << endl;
	cout << "*         1---�����Ϣ,  2---��ѯ��Ϣ        *" << endl;
	cout << "*         3---��ʾ��Ϣ,  4---�༭��Ϣ        *" << endl;
	cout << "*         5---ɾ����Ϣ,  6---ͳ����Ϣ        *" << endl;
	cout << "*                        7---�˳�            *" << endl;
	cout << "**********************************************" << endl;
	cout << "����������ѡ��--->:";
}
void _add(Cteacher *teacher, int &t)//1��ʦ�����Ϣ 
{
	int number, age;
	string name, sex, department, profession, position;
	cout << "�����Ϣ->������:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "����(����0��������),�Ա�(M--man,W--woman),����,ϵ��,רҵ,ְ��" << endl;
		cin >> name;
		if ("0" == name)
			break;
		while (1)
		{
			cin >> sex >> age >> department >> profession >> position;
			teacher[t].set(number, name, sex, age, department, profession, position);
			++t;
			break;
		}
	}
}
void _query(Cteacher teacher[], int &t)//2��ѯ��Ϣ 
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---���,2---����" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "����������������몤!" << endl;
	}
	switch (flag)
	{
	case 1://��Ų�ѯ 
	{
			   do
			   {
				   cout << "��������!" << endl;
				   cin >> nu;
				   if (find_nu(teacher, nu, t) < t)
					   teacher[find_nu(teacher, nu, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://������ѯ 
	{
			   do
			   {
				   cout << "����������!" << endl;
				   cin >> na;
				   if (find_na(teacher, na, t) < t)
					   teacher[find_na(teacher, na, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}
}
int find_nu(Cteacher teacher[], int _nu, int &t)//��Ų�ѯ��ʽ 
{
	int i;
	for (i = 0; i < t; i++)
	if (teacher[i].number == _nu)
		return i;
	return t;
}
int find_na(Cteacher teacher[], string _na, int &t)//������ѯ��ʽ 
{
	int i;
	for (i = 0; i < t; i++)
	if (teacher[i].name == _na)
		return i;
	return t;
}
void _display(Cteacher teacher[], int &t)//3��ʾ���� 
{
	int i;
	cout << endl;
	cout << "���\t����\t�Ա�\t����\tϵ��\tרҵ\tְ��" << endl;
	for (i = 0; i < t; i++)
		teacher[i].output();
	cout << "--------------------------------------------" << endl << endl;
}
void _edit(Cteacher teacher[], int &t)//4�༭����- 
{
	int score, fa, choice;
	while (1)
	{
		cout << "��������Ҫ�༭�ı��:";
		cin >> score;
		fa = find_nu(teacher, score, t);
		if (fa < t)
		{
			teacher[fa].output();
			add(teacher, fa);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}
void add(Cteacher teacher[], int _fa)//�༭���ݷ�ʽ 
{
	int number = _fa + 1, age;
	string name, sex, department, profession, position;
	cout << "����������:" << endl << "����,�Ա�,����,ϵ��,רҵ,ְ��" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		if (sex == "M" || sex == "W")
		{
			cin >> age >> department >> profession >> position;
			teacher[_fa].set(number, name, sex, age, department, profession, position);
			break;
		}
		else
			cout << "�����Ա����,����������!" << endl;
	}
}
void _delete(Cteacher teacher[], int &t)//ɾ������ 
{
	int score, de, choice1;
	while (1)
	{
		cout << "��������Ҫɾ���ı��!" << endl;
		cin >> score;
		de = find_nu(teacher, score, t);
		if (de < t)
		{
			teacher[de].output();
			dele(teacher, de);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "���˳�!" << endl;
			break;
		}
	}
}
void dele(Cteacher teacher[], int _fa)//ɾ�����ݷ�ʽ 
{
	int number, age, qr;
	string name, sex, department, profession, position;
	cout << "ȷ��ɾ��(1�Ǫ�2��):";
	cin >> qr;
	if (qr == 1)
	{
		cout << "��ɾ��!" << endl;
		number = 0;
		name = '0';
		sex = '0';
		age = 0;
		department = '0';
		profession = '0';
		position = '0';
		teacher[_fa].set(number, name, sex, age, department, profession, position);
	}
	if (qr == 2)
		cout << "δɾ��!" << endl;
}
void teacher_put()//�˳� 
{
	cout << "ллʹ�ý�ʦϵͳ!" << endl;
}


int openfile(Cteacher teacher[])//���ļ��ж������� 
{
	int t, number, age;
	string name, sex, department, profession, position;
	ifstream fcin;
	fcin.open("teacher.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "�ļ���ʧ�ܪ�����Ŀ¼���Ƿ����ļ�teacher.txt\n";
		return 0;
	}
	t = 0;
	while (fcin >> number >> name >> sex >> age >> department >> profession >> position)
	{
		teacher[t].set(number, name, sex, age, department, profession, position);
		++t;
	}
	return t;
	fcin.close();
}

void closefile(Cteacher teacher[], int &t)//���ļ���д������ 
{
	int i, number, age;
	string name, sex, department, profession, position;
	ofstream fout("teacher.txt");
	for (i = 0; i < t; i++)
	{
		number = teacher[i].number;
		name = teacher[i].name;
		sex = teacher[i].sex;
		age = teacher[i].age;
		department = teacher[i].department;
		profession = teacher[i].profession;
		position = teacher[i].position;
		if (number != 0)
			fout << number << "\t" << name << "\t" << sex << "\t" << age << "\t" <<
			department << "\t" << profession << "\t" << position << endl;
	}
	fout.close();
}

void teacher_manage()//��ʦ���ܵ��ú���- 
{
	Cteacher teacher[Max];
	int i, t;
	while (1)
	{
		t = openfile(teacher);//�ļ��е����� 
		teacher_muen(); //��ӡ�˵� 
		cin >> i;
		switch (i)
		{
		case 1: _add(teacher, t);     break;//��ӹ��� 
		case 2: _query(teacher, t);     break;//��ѯ���� 
		case 3: _display(teacher, t);   break;//��ʾ���� 
		case 4: _edit(teacher, t);  break;//�༭���� 
		case 5: _delete(teacher, t);     break;//ɾ������ 
		case 6: _statistics(teacher, t); break;//ͳ�ƹ��� 
		default: teacher_put(); goto loop;//�˳����� 
		}
		closefile(teacher, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
void _statistics(Cteacher teacher[], int &t)//ͳ������ 
{
	int i, boy = 0, girl = 0, sum = 0;
	for (i = 0; i < t; i++)
	{
		if (teacher[i].sex == "W")
			girl++;
		if (teacher[i].sex == "M")
			boy++;
	}
	sum = girl + boy;
	cout << "��ʦ�ܹ���" << sum << endl;
	cout << "����" << boy << "��  Ů��" << girl << "��" << endl;
}
void statistics_teacher()//��ʦͳ�ƺ��� 
{
	int t;
	Cteacher teacher[Max];
	t = openfile(teacher);
	_statistics(teacher, t);
}
/*****************ʵ �� Ա*********************/
/*--------------------�� �� �� �� �� �� �� �� ��---------------------*/
void Cassistant::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << laboratory << "\t";
	cout << position << endl;
}//������������ 
/*--------------------�� �� ��-----------------------------*/
void assistant_muen()
{
	cout << "***********��ӭ����ʵ��Ա��Ϣ����ϵͳ**********" << endl;
	cout << "*          1---�����Ϣ,  2---��ѯ��Ϣ        *" << endl;
	cout << "*          3---��ʾ��Ϣ,  4---�༭��Ϣ        *" << endl;
	cout << "*          5---ɾ����Ϣ,  6---ͳ����Ϣ        *" << endl;
	cout << "*                         7---�˳�            *" << endl;
	cout << "***********************************************" << endl;
	cout << "����������ѡ��--->:";
}//���˵� 
/*--------------------------�� �� �� ��------------------------*/
void _add(Cassistant *assistant, int &t)
{
	int number, age;
	string name, sex, laboratory, position;
	cout << "�����Ϣ->������:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "����(����0�������Ա�(M--man,W--woman�������䣬ʵ���ң�ְ��" << endl;
		cin >> name;
		if (name == "0")
			break;
		while (1)
		{
			cin >> sex >> age >> laboratory >> position;
			assistant[t].set(number, name, sex, age, laboratory, position);
			++t;
			break;
		}
	}
}//�����Ϣ 
/*------------------------�� ѯ �� ��-----------------------------*/
void _query(Cassistant assistant[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---���,2---����" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "����������������몤";
	}
	switch (flag)
	{
	case 1://��Ų�ѯ 
	{
			   do
			   {
				   cout << "��������!" << endl;
				   cin >> nu;
				   if (find_nu(assistant, nu, t) < t)
					   assistant[find_nu(assistant, nu, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://������ѯ 
	{
			   do
			   {
				   cout << "����������!" << endl;
				   cin >> na;
				   if (find_na(assistant, na, t) < t)
					   assistant[find_na(assistant, na, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	};
}//��ѯ��Ϣ 
/*------------ʹ �� �� �� �� ѯ �� �� �� ʽ--------------------*/
int find_nu(Cassistant assistant[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (assistant[i].number == _nu)
		return i;
	return t;
}//��Ų�ѯ��ʽ 
/*---------ʹ �� �� �� �� ѯ �� �� �� ʽ-----------------*/
int find_na(Cassistant assistant[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (assistant[i].name == _na)
		return i;
	return t;
}//������ѯ��ʽ 
/*------------------------------�� ʾ �� ��--------------------------------*/
void _display(Cassistant assistant[], int &t)
{
	int i;
	cout << "���\t����\t�Ա�\t����\tʵ����\tְ��" << endl;
	for (i = 0; i < t; i++)
		assistant[i].output();
}//��ʾ����  
/*---------------------------------�� �� �� ��----------------------------------*/
void _edit(Cassistant assistant[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "��������Ҫ�༭�ı��:";
		cin >> score;
		fa = find_nu(assistant, score, t);
		if (fa < t)
		{
			assistant[fa].output();
			add(assistant, fa);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//�༭���� 
/*------------------------�� �� �� �� �� ʽ-----------------*/
void add(Cassistant assistant[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, laboratory, position;
	cout << "����������->ʵ��Ա����,�Ա�,����,ʵ����,ְ��" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> laboratory >> position;
		assistant[_fa].set(number, name, sex, age, laboratory, position);
		break;
	}
}//�༭��Ϣ 
/*----------------------------ɾ �� �� ��--------------------------*/
void _delete(Cassistant assistant[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "��������Ҫɾ���ı��!" << endl;
		cin >> score;
		de = find_nu(assistant, score, t);
		if (de < t)
		{
			assistant[de].output();
			dele(assistant, de);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "���˳�!" << endl;
			break;
		}
	}
}
/*------------------------ɾ �� �� �� �� ʽ------------------*/

void dele(Cassistant assistant[], int _fa)
{
	int number, age, qr;
	string name, sex, laboratory, position;
	cout << "ȷ��ɾ��(1�Ǫ�2��):";
	cin >> qr;
	if (qr == 1)
	{
		cout << "��ɾ��!" << endl;
		number = 0;
		name = '0';
		sex = '0';
		age = 0;
		laboratory = '0';
		position = '0';
		assistant[_fa].set(number, name, sex, age, laboratory, position);
	}
	if (qr == 2)
		cout << "�����˳�ɾ������!" << endl;
}//�༭��Ϣ 
/*-----------------ͳ �� �� ��--------------------------------*/
void _statistics(Cassistant assistant[], int &t)
{
	int i, boy = 0, girl = 0, sum = 0;
	for (i = 0; i < t; i++)
	{
		if (assistant[i].sex == "W")
			girl++;
		if (assistant[i].sex == "M")
			boy++;
	}
	sum = girl + boy;
	cout << "ʵ��Ա�ܹ���" << sum << endl;
	cout << "����" << boy << "��  Ů��" << girl << "��" << endl;
}//ͳ�� 
/*--------------------------�� ��--------------------------------*/
void assistant_put()
{
	cout << "ллʹ�ý�ʦϵͳ!" << endl;
}//�˳� 
/*------------------------------�� �� �� �� �� �� �� ��----------------------------*/
int openfile(Cassistant assistant[])
{
	int t, number, age;
	string name, sex, laboratory, position;
	ifstream fcin;
	fcin.open("assistant.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "�ļ���ʧ�ܪ�����Ŀ¼���Ƿ����ļ�assistant.txt\n";
		return 0;
	}
	t = 0;
	while (fcin >> number >> name >> sex >> age >> laboratory >> position)
	{
		assistant[t].set(number, name, sex, age, laboratory, position);
		++t;
	}
	return t;
	fcin.close();
}//���ļ��ж������� 
/*--------------------------�� �� �� �� д �� �� ��-----------------------------*/
void closefile(Cassistant assistant[], int &t)
{
	int i, number, age;
	string name, sex, laboratory, position;
	ofstream fout("assistant.txt");
	for (i = 0; i < t; i++)
	{
		number = assistant[i].number;
		name = assistant[i].name;
		sex = assistant[i].sex;
		age = assistant[i].age;
		laboratory = assistant[i].laboratory;
		position = assistant[i].position;
		if (number != 0)
			fout << number << "\t" << name << "\t" << sex << "\t" << age << "\t" <<
			laboratory << "\t" << position << endl;
	}
	fout.close();
}//д�����ݵ��ļ��� 
/*-----------------------ʵ �� Ա �� �� �� �� �� ��-----------------------------*/
void assistant_manage()
{
	Cassistant assistant[Max];
	int i, t;
	while (1)
	{
		t = openfile(assistant);
		assistant_muen(); //��ӡ�˵� 
		cin >> i;
		switch (i)
		{
		case 1: _add(assistant, t);     break;//��ӹ��� 
		case 2: _query(assistant, t);     break;//��ѯ���� 
		case 3: _display(assistant, t);   break;//��ʾ���� 
		case 4: _edit(assistant, t);  break;//�༭���� 
		case 5: _delete(assistant, t);     break;//ɾ������ 
		case 6: _statistics(assistant, t); break;//ͳ�ƹ��� 
		default: assistant_put(); goto loop;//�˳����� 
		}
		closefile(assistant, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*--------------------------------ʵ �� Ա ͳ �� �� ��-----------------------------*/
void statistics_assistant()
{
	int t;
	Cassistant assistant[Max];
	t = openfile(assistant);
	_statistics(assistant, t);
}
/*************************�� �� �� Ա*****************************/
void Cexecution::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << politics << "\t";
	cout << position << endl;
}//������������ 
/*----�� �� ��-----------------------*/
void execution_muen()
{
	cout << "********��ӭ����������Ա��Ϣ����ϵͳ************" << endl;
	cout << "*        1---�����Ϣ,  2---��ѯ��Ϣ           *" << endl;
	cout << "*        3---��ʾ��Ϣ,  4---�༭��Ϣ           *" << endl;
	cout << "*        5---ɾ����Ϣ,  6---ͳ����Ϣ           *" << endl;
	cout << "*                       7---�˳�               *" << endl;
	cout << "************************************************" << endl;
}//���˵� 
/*----------------------------�� �� �� ��-----------------*/
void _add(Cexecution *execution, int &t)
{
	int number, age;
	string name, sex, politics, position;
	cout << "�����Ϣ->������:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "����(����0����),�Ա�(M--man,W--woman),����,������ò,ְ��" << endl;
		cin >> name;
		if (name == "0")
			break;
		while (1)
		{
			cin >> sex >> age >> politics >> position;
			execution[t].set(number, name, sex, age, politics, position);
			++t;
			break;
		}
	}
}//�����Ϣ 
/*---------------------------�� ѯ �� ��--------------------*/
void _query(Cexecution execution[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---���,2---����" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "����������������몤";
	}
	switch (flag)
	{
	case 1://��Ų�ѯ 
	{
			   do
			   {
				   cout << "��������!" << endl;
				   cin >> nu;
				   if (find_nu(execution, nu, t) < t)
					   execution[find_nu(execution, nu, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://������ѯ 
	{
			   do
			   {
				   cout << "����������!" << endl;
				   cin >> na;
				   if (find_na(execution, na, t) < t)
					   execution[find_na(execution, na, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}





}//��ѯ��Ϣ 
/*-----------------ʹ �� �� �� �� ѯ �� �� �� ʽ------------------*/
int find_nu(Cexecution execution[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (execution[i].number == _nu)
		return i;
	return t;
}//��Ų�ѯ��ʽ 
/*---------------------------ʹ �� �� �� �� ѯ �� �� �� ʽ  ----------------------------*/
int find_na(Cexecution execution[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (execution[i].name == _na)
		return i;
	return t;
}//������ѯ��ʽ 
/*-------------------------�� ʾ �� ��---------------------------*/
void _display(Cexecution execution[], int &t)
{
	int i;
	cout << "���\t����\t�Ա�\t����\t������ò\tְ��" << endl;
	for (i = 0; i < t; i++)
		execution[i].output();
}//��ʾ���� 
/*-----------------------------------�� �� �� ��-----------------------------*/
void _edit(Cexecution execution[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "��������Ҫ�༭�ı��:" << endl;
		cin >> score;
		fa = find_nu(execution, score, t);
		if (fa < t)
		{
			execution[fa].output();
			add(execution, fa);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//�༭���� 
/*---------------------------�� �� �� �� �� ʽ-----------*/
void add(Cexecution execution[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, politics, position;
	cout << "����������->����,�Ա�,����,������ò,ְ��" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> politics >> position;
		execution[_fa].set(number, name, sex, age, politics, position);
		break;
	}
}//�༭��Ϣ 
/*----------------------------ɾ �� �� ��-----------------------*/
void _delete(Cexecution execution[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "��������Ҫɾ���ı��!" << endl;
		cin >> score;
		de = find_nu(execution, score, t);
		if (de < t)
		{
			execution[de].output();
			dele(execution, de);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "���˳�!" << endl;
			break;
		}
	}
}
/*----------------------ɾ �� �� �� �� ʽ-------------*/
void dele(Cexecution execution[], int _fa)
{
	int number, age, qr;
	string name, sex, politics, position;
	cout << "ȷ��ɾ��(1�Ǫ�2��):";
	cin >> qr;
	if (qr == 1)
	{
		number = 0; name = '0';  sex = '0';  age = 0; politics = '0'; position = '0';
		execution[_fa].set(number, name, sex, age, politics, position);
	}
	if (qr == 2)
		cout << "�����˳�ɾ������!" << endl;
}//�༭��Ϣ 
/*-------------------------ͳ �� �� ��-----------------------------*/
void _statistics(Cexecution execution[], int &t)
{
	int i, boy = 0, girl = 0, sum = 0;
	for (i = 0; i < t; i++)
	{
		if (execution[i].sex == "W")
			girl++;
		if (execution[i].sex == "M")
			boy++;
	}
	sum = girl + boy;
	cout << "ʵ��Ա�ܹ���" << sum << endl;
	cout << "����" << boy << "��  Ů��" << girl << "��" << endl;
}//ͳ�� 
/*--------------------------------�� ��--------------------------------*/
void execution_put()
{
	cout << "ллʹ�ý�ʦϵͳ!" << endl;
}//�˳� 
/*--------------------------------�� �� �� �� �� �� �� ��----------------------------*/
int openfile(Cexecution execution[])
{
	int t, number, age;
	string name, sex, politics, position;
	ifstream fcin;
	fcin.open("execution.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "�ļ���ʧ�ܪ�����Ŀ¼���Ƿ����ļ�execution.txt\n";
		return 0;
	}
	t = 0;
	while (fcin >> number >> name >> sex >> age >> politics >> position)
	{
		execution[t].set(number, name, sex, age, politics, position);
		++t;
	}
	return t;
	fcin.close();
}//���ļ��ж������� 
/*----------------------------�� �� �� �� д �� �� ��--------------------------*/
void closefile(Cexecution execution[], int &t)
{
	int i, number, age;
	string name, sex, politics, position;
	ofstream fout("execution.txt");
	for (i = 0; i < t; i++)
	{
		number = execution[i].number;
		name = execution[i].name;
		sex = execution[i].sex;
		age = execution[i].age;
		politics = execution[i].politics;
		position = execution[i].position;
		if (number != 0)
			fout << number << "\t" << name << "\t" << sex << "\t" << age << "\t" <<
			politics << "\t" << position << endl;
	}
	fout.close();
}//д�����ݵ��ļ��� 
/*-----------------------�� �� �� Ա �� �� �� �� �� ��-----------------*/
void execution_manage()
{
	Cexecution execution[Max];
	int i, t;
	while (1)
	{
		t = openfile(execution);
		execution_muen(); //��ӡ�˵� 
		cin >> i;
		switch (i)
		{
		case 1: _add(execution, t);     break;//��ӹ��� 
		case 2: _query(execution, t);     break;//��ѯ���� 
		case 3: _display(execution, t);   break;//��ʾ���� 
		case 4: _edit(execution, t);  break;//�༭���� 
		case 5: _delete(execution, t);     break;//ɾ������ 
		case 6: _statistics(execution, t); break;//ͳ�ƹ��� 
		default: execution_put(); goto loop;//�˳����� 
		}
		closefile(execution, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*---------------------�� �� �� Ա ͳ �� �� ��-----------------------------*/
void statistics_execution()
{
	int t;
	Cexecution execution[Max];
	t = openfile(execution);
	_statistics(execution, t);
}
/*************************�� �� �� Ա �� �� ʦ******************/
/*----------------------------�� �� �� �� �� �� �� �� ��-----------------------*/
void Ctea_exe::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << politics << "\t" << department << "\t" << profession << "\t";
	cout << position << endl;
}//������������ 
/*-----------------------------�� �� ��----------------------------*/
void tea_exe_muen()
{
	cout << "***********��ӭ����������Ա���ʦ��Ϣ����ϵͳ*********" << endl;
	cout << "*            1---�����Ϣ,  2---��ѯ��Ϣ             *" << endl;
	cout << "*            3---��ʾ��Ϣ,  4---�༭��Ϣ             *" << endl;
	cout << "*            5---ɾ����Ϣ,  6---ͳ����Ϣ             *" << endl;
	cout << "*                           7---�˳�                 *" << endl;
	cout << "******************************************************" << endl;
	cout << "����������ѡ��--->:";
}
//���˵�  
/*----------------------------�� �� �� ��-------------------------*/
void _add(Ctea_exe *tea_exe, int &t)
{
	int number, age;
	string name, sex, politics, department, profession, position;
	cout << "�����Ϣ->������:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "����(����0����),�Ա�(M--man,W--woman),���䣬������ò��ϵ����רҵ��ְ��" << endl;
		cin >> name;
		if (name == "0")
			break;
		while (1)
		{
			cin >> sex >> age >> politics >> department >> profession >> position;
			tea_exe[t].set(number, name, sex, age, politics, department, profession, position
				);
			++t;
			break;
		}

	}
}//�����Ϣ 
/*----------------------------------�� ѯ �� ��-----------------------------*/
void _query(Ctea_exe tea_exe[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---���,2---����" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "����������������몤!" << endl;
	}
	switch (flag)
	{
	case 1://��Ų�ѯ 
	{
			   do
			   {
				   cout << "��������!" << endl;
				   cin >> nu;
				   if (find_nu(tea_exe, nu, t) < t)
					   tea_exe[find_nu(tea_exe, nu, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://������ѯ 
	{
			   do
			   {
				   cout << "����������!" << endl;
				   cin >> na;
				   if (find_na(tea_exe, na, t) < t)
					   tea_exe[find_na(tea_exe, na, t)].output();
				   else
					   cout << "���޴���!" << endl;
				   cout << "�Ƿ������1�Ǫ�2��" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}
}//��ѯ��Ϣ 
/*--------------------ʹ �� �� �� �� ѯ �� �� �� ʽ-----------------*/
int find_nu(Ctea_exe tea_exe[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (tea_exe[i].number == _nu)
		return i;
	return t;
}//��Ų�ѯ��ʽ 
/*-----------------ʹ �� �� �� �� ѯ �� �� �� ʽ-------------*/
int find_na(Ctea_exe tea_exe[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (tea_exe[i].name == _na)
		return i;
	return t;
}//������ѯ��ʽ 
/*---------------------------------�� ʾ �� ��-----------------------------*/
void _display(Ctea_exe tea_exe[], int &t)
{
	int i;
	cout << "���\t����\t�Ա�\t����\t������ò\tϵ��\tרҵ\tְ��" << endl;
	for (i = 0; i < t; i++)
		tea_exe[i].output();
}//��ʾ���� 
/*----------------------------------�� �� �� ��--------------------------*/
void _edit(Ctea_exe tea_exe[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "��������Ҫ�༭�ı��:";
		cin >> score;
		fa = find_nu(tea_exe, score, t);
		if (fa < t)
		{
			tea_exe[fa].output();
			add(tea_exe, fa);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//�༭���� 
/*------------------------�� �� �� �� �� ʽ----------------*/
void add(Ctea_exe tea_exe[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, politics, department, profession, position;
	cout << "����������->����,�Ա�,����,������ò,ϵ��,רҵ,ְ��" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> politics >> department >> profession >> position;
		tea_exe[_fa].set(number, name, sex, age, politics, department, profession, position);
		break;
	}
}//�༭��Ϣ 
/*----------------------------ɾ �� �� ��----------------------------*/
void _delete(Ctea_exe tea_exe[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "��������Ҫɾ���ı��!" << endl;
		cin >> score;
		de = find_nu(tea_exe, score, t);
		if (de < t)
		{
			tea_exe[de].output();
			dele(tea_exe, de);
		}
		else
			cout << "���޴���!" << endl;
		cout << "�Ƿ����(1�Ǫ�2��):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "���˳�!" << endl;
			break;
		}
	}
}
/*-----------------------------ɾ �� �� �� �� ʽ------------*/
void dele(Ctea_exe tea_exe[], int _fa)
{
	int number, age, qr;
	string name, sex, politics, department, profession, position;
	cout << "ȷ��ɾ��(1�Ǫ�2��)��";
	cin >> qr;
	if (qr == 1)
	{
		cout << "��ɾ��!" << endl;
		number = 0; name = '0'; sex = '0';  age = 0; department = '0'; position = '0';
		tea_exe[_fa].set(number, name, sex, age, politics, department, profession, position);
	}

	if (qr == 2)
		cout << "δɾ��!" << endl;
}//�༭��Ϣ 
/*---------------------------ͳ �� �� ��---------------------------*/
void _statistics(Ctea_exe tea_exe[], int &t)
{
	int i, boy = 0, girl = 0, sum = 0;
	for (i = 0; i < t; i++)
	{
		if (tea_exe[i].sex == "W")
			girl++;
		if (tea_exe[i].sex == "M")
			boy++;
	}
	sum = girl + boy;
	cout << "������Ա���ʦ�ܹ���" << sum << endl;
	cout << "����" << boy << "��  Ů��" << girl << "��" << endl;
}//ͳ�� 
/*-------------------------------------�� ��-------------------------------*/
void tea_exe_put()
{
	cout << "ллʹ�ý�ʦϵͳ!" << endl;
}//�˳� 
/*----------------------------�� �� �� �� �� �� �� ��-----------*/
int openfile(Ctea_exe tea_exe[])
{
	int t, number, age;
	string name, sex, politics, department, profession, position;
	ifstream fcin;
	fcin.open("tea_exe.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "�ļ���ʧ�ܪ�����Ŀ¼���Ƿ����ļ�tea_exe.txt\n";
		return 0;
	}
	t = 0;
	while (fcin >> number >> name >> sex >> age >> politics >> department >> profession >>
		position)
	{
		tea_exe[t].set(number, name, sex, age, politics, department, profession, position
			);
		++t;
	}
	return t;
	fcin.close();
}//���ļ��ж�������   
/*-----------------------�� �� �� �� д �� �� ��-----------------------*/
void closefile(Ctea_exe tea_exe[], int &t)
{
	int i, number, age;
	string name, sex, politics, department, profession, position;
	ofstream fout("tea_exe.txt");
	for (i = 0; i < t; i++)
	{
		number = tea_exe[i].number;
		name = tea_exe[i].name;
		sex = tea_exe[i].sex;
		age = tea_exe[i].age;
		politics = tea_exe[i].politics;
		department = tea_exe[i].department;
		profession = tea_exe[i].profession;
		position = tea_exe[i].position;
		if (number != 0)
			fout << number << "\t" << name << "\t" << sex << "\t" << age << "\t" <<
			politics << "\t" << department << "\t" << profession << "\t" << position << endl;
	}
	fout.close();
}//д�����ݵ��ļ��� 
void tea_exe_manage()
{
	Ctea_exe tea_exe[Max];
	int i, t;
	while (1)
	{
		t = openfile(tea_exe);
		tea_exe_muen(); //��ӡ�˵� 
		cin >> i;
		switch (i)
		{
		case 1: _add(tea_exe, t);     break;//��ӹ��� 
		case 2: _query(tea_exe, t);     break;//��ѯ���� 
		case 3: _display(tea_exe, t);   break;//��ʾ���� 
		case 4: _edit(tea_exe, t);  break;//�༭���� 
		case 5: _delete(tea_exe, t);     break;//ɾ������ 
		case 6: _statistics(tea_exe, t); break;//ͳ�ƹ��� 
		default: tea_exe_put(); goto loop;//�˳����� 
		}
		closefile(tea_exe, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*--------------------�� �� �� Ա �� �� ʦ ͳ �� �� ��------------------------*/
void statistics_tea_exe()
{
	int t;
	Ctea_exe tea_exe[Max];
	t = openfile(tea_exe);
	_statistics(tea_exe, t);
}
#include"stdio.h"
void statistics_all()//����ͳ������ 
{
	statistics_teacher();
	statistics_assistant();
	statistics_execution();
	statistics_tea_exe();
}
void muen()
{
	cout << "**********��ӭ�����У��Ϣ����ϵͳ***********" << endl;
	cout << "*        1---��ʦ��Ϣ,2---ʵ��Ա��Ϣ        *" << endl;
	cout << "*        3---������Ա,4---��ʦ��������Ա    *" << endl;
	cout << "*        5---ͳ������,6---�˳�ϵͳ          *" << endl;
	cout << "*********************************************" << endl;
	cout << "����������ѡ��--->:";
}
int main()
{
	int i;
	while (1)
	{
		muen();
		cin >> i;
		switch (i)
		{
		case 1: teacher_manage();     break;//��ʦ 
		case 2: assistant_manage();   break;//ʵ��Ա 
		case 3: execution_manage();   break;//���� 
		case 4: tea_exe_manage();     break;//��ʦ������ 
		case 5: statistics_all();     break;//ͳ�� 
		default:cout << "��ӭ�ٴ�ʹ��!" << endl;
			exit(0);
		}
	}
	return 0;
}
