#include<iostream>
#include <string>
#include <fstream>
using namespace std;
/*-------------------------------------共 有 类-------------------------------------*/
class CCommon//公有类 
{
protected:
	int number;//编号 
	string name;//姓名 
	string sex;//性别 
	int age;//年龄 
};
/*------------------------教 师 类--------------------------------------*/
class Cteacher :
	public CCommon//教师类 
{
protected:
	string department;//所在系部 
	string profession;//专业  
	string position;//职称 
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
	}//输入教师数据 
	void output();
	~Cteacher()
	{
	}//析构函数 
	friend int find_nu(Cteacher teacher[], int _nu, int &t);
	friend int find_na(Cteacher teacher[], string _na, int &t);
	friend void add(Cteacher teacher[], int _fa);
	friend void dele(Cteacher teacher[], int _fa);
	friend void closefile(Cteacher teacher[], int &t);
	friend void _statistics(Cteacher teacher[], int &t);
};
void teacher_manage();
/*----------------------------实 验 员 类-------------------------------------------*/
class Cassistant :public CCommon//实验员类 
{
protected:
	string laboratory;//所在实验室 
	string position;//职称 
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
	}//输入实验员数据 
	void output();
	~Cassistant()
	{
	}//析构函数 
	friend int find_nu(Cassistant assistant[], int _nu, int &t);
	friend int find_na(Cassistant assistant[], string _na, int &t);
	friend void add(Cassistant assistant[], int _fa);
	friend void dele(Cassistant assistant[], int _fa);
	friend void closefile(Cassistant assistant[], int &t);
	friend void _statistics(Cassistant assistant[], int &t);
};
void assistant_manage();
/*----------------------------行 政 人 员 类--------------------------------------------*/
class Cexecution :public CCommon//行政人员类 
{
protected:
	string politics;//政治面貌 
	string position;//职称 
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
	}//输入行政人员数据 
	void output();
	~Cexecution()
	{
	}//析构函数  
	friend int find_nu(Cexecution execution[], int _nu, int &t);
	friend int find_na(Cexecution execution[], string _na, int &t);
	friend void add(Cexecution execution[], int _fa);
	friend void dele(Cexecution execution[], int _fa);
	friend void closefile(Cexecution execution[], int &t);
	friend void _statistics(Cexecution execution[], int &t);
};
void execution_manage();
/*---------------------------行 政 人 员 兼 教 师 类-------------------------------------*/
class Ctea_exe :public CCommon//行政人员兼教师类 
{
protected:
	string politics;//政治面貌 
	string department;//所在系部 
	string profession;//专业 
	string position;//职称 
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
	}//输入行政人员兼教师数据 
	void output();
	~Ctea_exe()
	{
	}//析构函数 
	friend int find_nu(Ctea_exe tea_exe[], int _nu, int &t);
	friend int find_na(Ctea_exe tea_exe[], string _na, int &t);
	friend void add(Ctea_exe tea_exe[], int _fa);
	friend void dele(Ctea_exe tea_exe[], int _fa);
	friend void closefile(Ctea_exe tea_exe[], int &t);
	friend void _statistics(Ctea_exe tea_exe[], int &t);
};
void tea_exe_manage();
/*---------------------------------统 计 总 人 数---------------------------------------*/
void statistics_all();//数据统计数 
void statistics_teacher();
void statistics_assistant();
void statistics_execution();
void statistics_tea_exe();
void order();
const int Max = 100;//各人员总人数最大值 

#include "stdio.h"
/*----------------------------教师类中的各个函数操作-----------------------*/
void Cteacher::output()//教师读出数据内容 
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << department << "\t" << profession << "\t";
	cout << position << endl;
}
void teacher_muen()//教师主菜单 
{
	cout << endl;
	cout << "***********欢迎进入教师信息管理系统***********" << endl;
	cout << "*         1---添加信息,  2---查询信息        *" << endl;
	cout << "*         3---显示信息,  4---编辑信息        *" << endl;
	cout << "*         5---删除信息,  6---统计信息        *" << endl;
	cout << "*                        7---退出            *" << endl;
	cout << "**********************************************" << endl;
	cout << "请输入您的选择--->:";
}
void _add(Cteacher *teacher, int &t)//1教师添加信息 
{
	int number, age;
	string name, sex, department, profession, position;
	cout << "添加信息->请输入:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "姓名(输入0结束输入),性别(M--man,W--woman),年龄,系部,专业,职称" << endl;
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
void _query(Cteacher teacher[], int &t)//2查询信息 
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---编号,2---姓名" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "输入错误请重新输入!" << endl;
	}
	switch (flag)
	{
	case 1://编号查询 
	{
			   do
			   {
				   cout << "请输入编号!" << endl;
				   cin >> nu;
				   if (find_nu(teacher, nu, t) < t)
					   teacher[find_nu(teacher, nu, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://姓名查询 
	{
			   do
			   {
				   cout << "请输入姓名!" << endl;
				   cin >> na;
				   if (find_na(teacher, na, t) < t)
					   teacher[find_na(teacher, na, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}
}
int find_nu(Cteacher teacher[], int _nu, int &t)//编号查询方式 
{
	int i;
	for (i = 0; i < t; i++)
	if (teacher[i].number == _nu)
		return i;
	return t;
}
int find_na(Cteacher teacher[], string _na, int &t)//姓名查询方式 
{
	int i;
	for (i = 0; i < t; i++)
	if (teacher[i].name == _na)
		return i;
	return t;
}
void _display(Cteacher teacher[], int &t)//3显示功能 
{
	int i;
	cout << endl;
	cout << "编号\t姓名\t性别\t年龄\t系部\t专业\t职称" << endl;
	for (i = 0; i < t; i++)
		teacher[i].output();
	cout << "--------------------------------------------" << endl << endl;
}
void _edit(Cteacher teacher[], int &t)//4编辑数据- 
{
	int score, fa, choice;
	while (1)
	{
		cout << "请输入需要编辑的编号:";
		cin >> score;
		fa = find_nu(teacher, score, t);
		if (fa < t)
		{
			teacher[fa].output();
			add(teacher, fa);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}
void add(Cteacher teacher[], int _fa)//编辑数据方式 
{
	int number = _fa + 1, age;
	string name, sex, department, profession, position;
	cout << "请重新输入:" << endl << "姓名,性别,年龄,系部,专业,职称" << endl;
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
			cout << "输入性别错误,请重新输入!" << endl;
	}
}
void _delete(Cteacher teacher[], int &t)//删除数据 
{
	int score, de, choice1;
	while (1)
	{
		cout << "请输入需要删除的编号!" << endl;
		cin >> score;
		de = find_nu(teacher, score, t);
		if (de < t)
		{
			teacher[de].output();
			dele(teacher, de);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "已退出!" << endl;
			break;
		}
	}
}
void dele(Cteacher teacher[], int _fa)//删除数据方式 
{
	int number, age, qr;
	string name, sex, department, profession, position;
	cout << "确定删除(1是2否):";
	cin >> qr;
	if (qr == 1)
	{
		cout << "已删除!" << endl;
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
		cout << "未删除!" << endl;
}
void teacher_put()//退出 
{
	cout << "谢谢使用教师系统!" << endl;
}


int openfile(Cteacher teacher[])//从文件中读入数据 
{
	int t, number, age;
	string name, sex, department, profession, position;
	ifstream fcin;
	fcin.open("teacher.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "文件打开失败请检查目录下是否有文件teacher.txt\n";
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

void closefile(Cteacher teacher[], int &t)//向文件中写入数据 
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

void teacher_manage()//教师类总调用函数- 
{
	Cteacher teacher[Max];
	int i, t;
	while (1)
	{
		t = openfile(teacher);//文件中的行数 
		teacher_muen(); //打印菜单 
		cin >> i;
		switch (i)
		{
		case 1: _add(teacher, t);     break;//添加功能 
		case 2: _query(teacher, t);     break;//查询功能 
		case 3: _display(teacher, t);   break;//显示功能 
		case 4: _edit(teacher, t);  break;//编辑功能 
		case 5: _delete(teacher, t);     break;//删除功能 
		case 6: _statistics(teacher, t); break;//统计功能 
		default: teacher_put(); goto loop;//退出功能 
		}
		closefile(teacher, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
void _statistics(Cteacher teacher[], int &t)//统计数据 
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
	cout << "教师总共有" << sum << endl;
	cout << "男有" << boy << "人  女有" << girl << "人" << endl;
}
void statistics_teacher()//教师统计函数 
{
	int t;
	Cteacher teacher[Max];
	t = openfile(teacher);
	_statistics(teacher, t);
}
/*****************实 验 员*********************/
/*--------------------从 类 中 读 出 数 据 内 容---------------------*/
void Cassistant::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << laboratory << "\t";
	cout << position << endl;
}//读出数据内容 
/*--------------------主 菜 单-----------------------------*/
void assistant_muen()
{
	cout << "***********欢迎进入实验员信息管理系统**********" << endl;
	cout << "*          1---添加信息,  2---查询信息        *" << endl;
	cout << "*          3---显示信息,  4---编辑信息        *" << endl;
	cout << "*          5---删除信息,  6---统计信息        *" << endl;
	cout << "*                         7---退出            *" << endl;
	cout << "***********************************************" << endl;
	cout << "请输入您的选择--->:";
}//主菜单 
/*--------------------------添 加 数 据------------------------*/
void _add(Cassistant *assistant, int &t)
{
	int number, age;
	string name, sex, laboratory, position;
	cout << "添加信息->请输入:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "姓名(输入0结束，性别(M--man,W--woman），年龄，实验室，职称" << endl;
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
}//添加信息 
/*------------------------查 询 数 据-----------------------------*/
void _query(Cassistant assistant[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---编号,2---姓名" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "输入错误请重新输入";
	}
	switch (flag)
	{
	case 1://编号查询 
	{
			   do
			   {
				   cout << "请输入编号!" << endl;
				   cin >> nu;
				   if (find_nu(assistant, nu, t) < t)
					   assistant[find_nu(assistant, nu, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://姓名查询 
	{
			   do
			   {
				   cout << "请输入姓名!" << endl;
				   cin >> na;
				   if (find_na(assistant, na, t) < t)
					   assistant[find_na(assistant, na, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	};
}//查询信息 
/*------------使 用 编 号 查 询 数 据 方 式--------------------*/
int find_nu(Cassistant assistant[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (assistant[i].number == _nu)
		return i;
	return t;
}//编号查询方式 
/*---------使 用 姓 名 查 询 数 据 方 式-----------------*/
int find_na(Cassistant assistant[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (assistant[i].name == _na)
		return i;
	return t;
}//姓名查询方式 
/*------------------------------显 示 数 据--------------------------------*/
void _display(Cassistant assistant[], int &t)
{
	int i;
	cout << "编号\t姓名\t性别\t年龄\t实验室\t职称" << endl;
	for (i = 0; i < t; i++)
		assistant[i].output();
}//显示功能  
/*---------------------------------编 辑 数 据----------------------------------*/
void _edit(Cassistant assistant[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "请输入需要编辑的编号:";
		cin >> score;
		fa = find_nu(assistant, score, t);
		if (fa < t)
		{
			assistant[fa].output();
			add(assistant, fa);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//编辑功能 
/*------------------------编 辑 数 据 方 式-----------------*/
void add(Cassistant assistant[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, laboratory, position;
	cout << "请重新输入->实验员姓名,性别,年龄,实验室,职称" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> laboratory >> position;
		assistant[_fa].set(number, name, sex, age, laboratory, position);
		break;
	}
}//编辑信息 
/*----------------------------删 除 数 据--------------------------*/
void _delete(Cassistant assistant[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "请输入需要删除的编号!" << endl;
		cin >> score;
		de = find_nu(assistant, score, t);
		if (de < t)
		{
			assistant[de].output();
			dele(assistant, de);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "已退出!" << endl;
			break;
		}
	}
}
/*------------------------删 除 数 据 方 式------------------*/

void dele(Cassistant assistant[], int _fa)
{
	int number, age, qr;
	string name, sex, laboratory, position;
	cout << "确定删除(1是2否):";
	cin >> qr;
	if (qr == 1)
	{
		cout << "已删除!" << endl;
		number = 0;
		name = '0';
		sex = '0';
		age = 0;
		laboratory = '0';
		position = '0';
		assistant[_fa].set(number, name, sex, age, laboratory, position);
	}
	if (qr == 2)
		cout << "您已退出删除功能!" << endl;
}//编辑信息 
/*-----------------统 计 数 据--------------------------------*/
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
	cout << "实验员总共有" << sum << endl;
	cout << "男有" << boy << "人  女有" << girl << "人" << endl;
}//统计 
/*--------------------------退 出--------------------------------*/
void assistant_put()
{
	cout << "谢谢使用教师系统!" << endl;
}//退出 
/*------------------------------从 文 件 中 读 入 数 据----------------------------*/
int openfile(Cassistant assistant[])
{
	int t, number, age;
	string name, sex, laboratory, position;
	ifstream fcin;
	fcin.open("assistant.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "文件打开失败请检查目录下是否有文件assistant.txt\n";
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
}//从文件中读入数据 
/*--------------------------向 文 件 中 写 入 数 据-----------------------------*/
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
}//写入数据到文件中 
/*-----------------------实 验 员 类 总 调 用 函 数-----------------------------*/
void assistant_manage()
{
	Cassistant assistant[Max];
	int i, t;
	while (1)
	{
		t = openfile(assistant);
		assistant_muen(); //打印菜单 
		cin >> i;
		switch (i)
		{
		case 1: _add(assistant, t);     break;//添加功能 
		case 2: _query(assistant, t);     break;//查询功能 
		case 3: _display(assistant, t);   break;//显示功能 
		case 4: _edit(assistant, t);  break;//编辑功能 
		case 5: _delete(assistant, t);     break;//删除功能 
		case 6: _statistics(assistant, t); break;//统计功能 
		default: assistant_put(); goto loop;//退出功能 
		}
		closefile(assistant, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*--------------------------------实 验 员 统 计 函 数-----------------------------*/
void statistics_assistant()
{
	int t;
	Cassistant assistant[Max];
	t = openfile(assistant);
	_statistics(assistant, t);
}
/*************************行 政 人 员*****************************/
void Cexecution::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << politics << "\t";
	cout << position << endl;
}//读出数据内容 
/*----主 菜 单-----------------------*/
void execution_muen()
{
	cout << "********欢迎进入行政人员信息管理系统************" << endl;
	cout << "*        1---添加信息,  2---查询信息           *" << endl;
	cout << "*        3---显示信息,  4---编辑信息           *" << endl;
	cout << "*        5---删除信息,  6---统计信息           *" << endl;
	cout << "*                       7---退出               *" << endl;
	cout << "************************************************" << endl;
}//主菜单 
/*----------------------------添 加 数 据-----------------*/
void _add(Cexecution *execution, int &t)
{
	int number, age;
	string name, sex, politics, position;
	cout << "添加信息->请输入:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "姓名(输入0结束),性别(M--man,W--woman),年龄,政治面貌,职称" << endl;
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
}//添加信息 
/*---------------------------查 询 数 据--------------------*/
void _query(Cexecution execution[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---编号,2---姓名" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "输入错误请重新输入";
	}
	switch (flag)
	{
	case 1://编号查询 
	{
			   do
			   {
				   cout << "请输入编号!" << endl;
				   cin >> nu;
				   if (find_nu(execution, nu, t) < t)
					   execution[find_nu(execution, nu, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://姓名查询 
	{
			   do
			   {
				   cout << "请输入姓名!" << endl;
				   cin >> na;
				   if (find_na(execution, na, t) < t)
					   execution[find_na(execution, na, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}





}//查询信息 
/*-----------------使 用 编 号 查 询 数 据 方 式------------------*/
int find_nu(Cexecution execution[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (execution[i].number == _nu)
		return i;
	return t;
}//编号查询方式 
/*---------------------------使 用 姓 名 查 询 数 据 方 式  ----------------------------*/
int find_na(Cexecution execution[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (execution[i].name == _na)
		return i;
	return t;
}//姓名查询方式 
/*-------------------------显 示 数 据---------------------------*/
void _display(Cexecution execution[], int &t)
{
	int i;
	cout << "编号\t姓名\t性别\t年龄\t政治面貌\t职称" << endl;
	for (i = 0; i < t; i++)
		execution[i].output();
}//显示功能 
/*-----------------------------------编 辑 数 据-----------------------------*/
void _edit(Cexecution execution[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "请输入需要编辑的编号:" << endl;
		cin >> score;
		fa = find_nu(execution, score, t);
		if (fa < t)
		{
			execution[fa].output();
			add(execution, fa);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//编辑功能 
/*---------------------------编 辑 数 据 方 式-----------*/
void add(Cexecution execution[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, politics, position;
	cout << "请重新输入->姓名,性别,年龄,政治面貌,职称" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> politics >> position;
		execution[_fa].set(number, name, sex, age, politics, position);
		break;
	}
}//编辑信息 
/*----------------------------删 除 数 据-----------------------*/
void _delete(Cexecution execution[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "请输入需要删除的编号!" << endl;
		cin >> score;
		de = find_nu(execution, score, t);
		if (de < t)
		{
			execution[de].output();
			dele(execution, de);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "已退出!" << endl;
			break;
		}
	}
}
/*----------------------删 除 数 据 方 式-------------*/
void dele(Cexecution execution[], int _fa)
{
	int number, age, qr;
	string name, sex, politics, position;
	cout << "确定删除(1是2否):";
	cin >> qr;
	if (qr == 1)
	{
		number = 0; name = '0';  sex = '0';  age = 0; politics = '0'; position = '0';
		execution[_fa].set(number, name, sex, age, politics, position);
	}
	if (qr == 2)
		cout << "您已退出删除功能!" << endl;
}//编辑信息 
/*-------------------------统 计 数 据-----------------------------*/
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
	cout << "实验员总共有" << sum << endl;
	cout << "男有" << boy << "人  女有" << girl << "人" << endl;
}//统计 
/*--------------------------------退 出--------------------------------*/
void execution_put()
{
	cout << "谢谢使用教师系统!" << endl;
}//退出 
/*--------------------------------从 文 件 中 读 入 数 据----------------------------*/
int openfile(Cexecution execution[])
{
	int t, number, age;
	string name, sex, politics, position;
	ifstream fcin;
	fcin.open("execution.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "文件打开失败请检查目录下是否有文件execution.txt\n";
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
}//从文件中读入数据 
/*----------------------------向 文 件 中 写 入 数 据--------------------------*/
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
}//写入数据到文件中 
/*-----------------------行 政 人 员 类 总 调 用 函 数-----------------*/
void execution_manage()
{
	Cexecution execution[Max];
	int i, t;
	while (1)
	{
		t = openfile(execution);
		execution_muen(); //打印菜单 
		cin >> i;
		switch (i)
		{
		case 1: _add(execution, t);     break;//添加功能 
		case 2: _query(execution, t);     break;//查询功能 
		case 3: _display(execution, t);   break;//显示功能 
		case 4: _edit(execution, t);  break;//编辑功能 
		case 5: _delete(execution, t);     break;//删除功能 
		case 6: _statistics(execution, t); break;//统计功能 
		default: execution_put(); goto loop;//退出功能 
		}
		closefile(execution, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*---------------------行 政 人 员 统 计 函 数-----------------------------*/
void statistics_execution()
{
	int t;
	Cexecution execution[Max];
	t = openfile(execution);
	_statistics(execution, t);
}
/*************************行 政 人 员 兼 教 师******************/
/*----------------------------从 类 中 读 出 数 据 内 容-----------------------*/
void Ctea_exe::output()
{
	cout << number << "\t" << name << "\t";
	cout << sex << "\t" << age << "\t";
	cout << politics << "\t" << department << "\t" << profession << "\t";
	cout << position << endl;
}//读出数据内容 
/*-----------------------------主 菜 单----------------------------*/
void tea_exe_muen()
{
	cout << "***********欢迎进入行政人员兼教师信息管理系统*********" << endl;
	cout << "*            1---添加信息,  2---查询信息             *" << endl;
	cout << "*            3---显示信息,  4---编辑信息             *" << endl;
	cout << "*            5---删除信息,  6---统计信息             *" << endl;
	cout << "*                           7---退出                 *" << endl;
	cout << "******************************************************" << endl;
	cout << "请输入您的选择--->:";
}
//主菜单  
/*----------------------------添 加 数 据-------------------------*/
void _add(Ctea_exe *tea_exe, int &t)
{
	int number, age;
	string name, sex, politics, department, profession, position;
	cout << "添加信息->请输入:" << endl;
	while (1)
	{
		number = t + 1;
		cout << "姓名(输入0结束),性别(M--man,W--woman),年龄，政治面貌，系部，专业，职称" << endl;
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
}//添加信息 
/*----------------------------------查 询 数 据-----------------------------*/
void _query(Ctea_exe tea_exe[], int &t)
{
	int choice;
	int flag, nu;
	string na;
	cout << "1---编号,2---姓名" << endl;
	while (1)
	{
		cin >> flag;
		if (1 == flag || 2 == flag)
			break;
		else
			cout << "输入错误请重新输入!" << endl;
	}
	switch (flag)
	{
	case 1://编号查询 
	{
			   do
			   {
				   cout << "请输入编号!" << endl;
				   cin >> nu;
				   if (find_nu(tea_exe, nu, t) < t)
					   tea_exe[find_nu(tea_exe, nu, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	case 2://姓名查询 
	{
			   do
			   {
				   cout << "请输入姓名!" << endl;
				   cin >> na;
				   if (find_na(tea_exe, na, t) < t)
					   tea_exe[find_na(tea_exe, na, t)].output();
				   else
					   cout << "查无此人!" << endl;
				   cout << "是否继续1是2否" << endl;
				   cin >> choice;
				   if (choice == 2)
					   break;
			   } while (choice == 1);
	}; break;
	}
}//查询信息 
/*--------------------使 用 编 号 查 询 数 据 方 式-----------------*/
int find_nu(Ctea_exe tea_exe[], int _nu, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (tea_exe[i].number == _nu)
		return i;
	return t;
}//编号查询方式 
/*-----------------使 用 姓 名 查 询 数 据 方 式-------------*/
int find_na(Ctea_exe tea_exe[], string _na, int &t)
{
	int i;
	for (i = 0; i < t; i++)
	if (tea_exe[i].name == _na)
		return i;
	return t;
}//姓名查询方式 
/*---------------------------------显 示 数 据-----------------------------*/
void _display(Ctea_exe tea_exe[], int &t)
{
	int i;
	cout << "编号\t姓名\t性别\t年龄\t政治面貌\t系部\t专业\t职称" << endl;
	for (i = 0; i < t; i++)
		tea_exe[i].output();
}//显示功能 
/*----------------------------------编 辑 数 据--------------------------*/
void _edit(Ctea_exe tea_exe[], int &t)
{
	int score, fa, choice;
	while (1)
	{
		cout << "请输入需要编辑的编号:";
		cin >> score;
		fa = find_nu(tea_exe, score, t);
		if (fa < t)
		{
			tea_exe[fa].output();
			add(tea_exe, fa);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice;
		if (choice != 1)
			break;
	}
}//编辑功能 
/*------------------------编 辑 数 据 方 式----------------*/
void add(Ctea_exe tea_exe[], int _fa)
{
	int number = _fa + 1, age;
	string name, sex, politics, department, profession, position;
	cout << "请重新输入->姓名,性别,年龄,政治面貌,系部,专业,职称" << endl;
	cin >> name;
	while (1)
	{
		cin >> sex;
		cin >> age >> politics >> department >> profession >> position;
		tea_exe[_fa].set(number, name, sex, age, politics, department, profession, position);
		break;
	}
}//编辑信息 
/*----------------------------删 除 数 据----------------------------*/
void _delete(Ctea_exe tea_exe[], int &t)
{
	int score, de, choice1;
	while (1)
	{
		cout << "请输入需要删除的编号!" << endl;
		cin >> score;
		de = find_nu(tea_exe, score, t);
		if (de < t)
		{
			tea_exe[de].output();
			dele(tea_exe, de);
		}
		else
			cout << "查无此人!" << endl;
		cout << "是否继续(1是2否):";
		cin >> choice1;
		if (choice1 == 2)
		{
			cout << "已退出!" << endl;
			break;
		}
	}
}
/*-----------------------------删 除 数 据 方 式------------*/
void dele(Ctea_exe tea_exe[], int _fa)
{
	int number, age, qr;
	string name, sex, politics, department, profession, position;
	cout << "确定删除(1是2否)";
	cin >> qr;
	if (qr == 1)
	{
		cout << "已删除!" << endl;
		number = 0; name = '0'; sex = '0';  age = 0; department = '0'; position = '0';
		tea_exe[_fa].set(number, name, sex, age, politics, department, profession, position);
	}

	if (qr == 2)
		cout << "未删除!" << endl;
}//编辑信息 
/*---------------------------统 计 数 据---------------------------*/
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
	cout << "行政人员兼教师总共有" << sum << endl;
	cout << "男有" << boy << "人  女有" << girl << "人" << endl;
}//统计 
/*-------------------------------------退 出-------------------------------*/
void tea_exe_put()
{
	cout << "谢谢使用教师系统!" << endl;
}//退出 
/*----------------------------从 文 件 中 读 入 数 据-----------*/
int openfile(Ctea_exe tea_exe[])
{
	int t, number, age;
	string name, sex, politics, department, profession, position;
	ifstream fcin;
	fcin.open("tea_exe.txt", ios_base::in);
	if (fcin == NULL)
	{
		cout << "文件打开失败请检查目录下是否有文件tea_exe.txt\n";
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
}//从文件中读入数据   
/*-----------------------向 文 件 中 写 入 数 据-----------------------*/
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
}//写入数据到文件中 
void tea_exe_manage()
{
	Ctea_exe tea_exe[Max];
	int i, t;
	while (1)
	{
		t = openfile(tea_exe);
		tea_exe_muen(); //打印菜单 
		cin >> i;
		switch (i)
		{
		case 1: _add(tea_exe, t);     break;//添加功能 
		case 2: _query(tea_exe, t);     break;//查询功能 
		case 3: _display(tea_exe, t);   break;//显示功能 
		case 4: _edit(tea_exe, t);  break;//编辑功能 
		case 5: _delete(tea_exe, t);     break;//删除功能 
		case 6: _statistics(tea_exe, t); break;//统计功能 
		default: tea_exe_put(); goto loop;//退出功能 
		}
		closefile(tea_exe, t);
	}
loop:
	cout << "--------------------------------------------" << endl;
}
/*--------------------行 政 人 员 兼 教 师 统 计 函 数------------------------*/
void statistics_tea_exe()
{
	int t;
	Ctea_exe tea_exe[Max];
	t = openfile(tea_exe);
	_statistics(tea_exe, t);
}
#include"stdio.h"
void statistics_all()//数据统计行数 
{
	statistics_teacher();
	statistics_assistant();
	statistics_execution();
	statistics_tea_exe();
}
void muen()
{
	cout << "**********欢迎进入高校信息管理系统***********" << endl;
	cout << "*        1---教师信息,2---实验员信息        *" << endl;
	cout << "*        3---行政人员,4---教师兼行政人员    *" << endl;
	cout << "*        5---统计人数,6---退出系统          *" << endl;
	cout << "*********************************************" << endl;
	cout << "请输入您的选择--->:";
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
		case 1: teacher_manage();     break;//教师 
		case 2: assistant_manage();   break;//实验员 
		case 3: execution_manage();   break;//行政 
		case 4: tea_exe_manage();     break;//教师兼行政 
		case 5: statistics_all();     break;//统计 
		default:cout << "欢迎再次使用!" << endl;
			exit(0);
		}
	}
	return 0;
}
