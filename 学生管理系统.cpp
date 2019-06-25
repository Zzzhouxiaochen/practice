#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>//�������
const int TMAX = 50;//���峣����
using namespace std;
class Person
{
public:
	int num;
	string name;
	string sex;
	int age;
	int banji;
public:
	Person(int n = 0, string nm = "", string s = "", int a = 0, int b = 0) :num(n), name(nm), sex(s), age(a), banji(b){};
	virtual void Input(){};//�麯���������������¶���
	virtual void Output(){};
	int GetNum(){ return num; }//��ȡ���
	string GetName(){ return name; }//��ȡ����
};
class zhongxuesheng :virtual public Person//����Ϊ���������Ϊ����������ֻ�̳�һ��
{
public:
	string depart;
	int spec;
	int title;
	int yuwen;
	int shuxue;
	int yingyu;
	int choice1;
	int choice2;
public:
	zhongxuesheng(int n = 0, string nm = "", string s = "��", int a = 0, int b = 0, string d = "�Ϻ�·", int sp = 0, int t = 0, int yw = 0, int sx = 0, int yy = 0)
		:Person(n, nm, s, a, b), depart(d), spec(sp), title(t), yuwen(yw), shuxue(sx), yingyu(yy){};
	void Input()
	{
		cout << "������ѧ����ѧ��" << endl;
		cin >> num;
		cout << "������ѧ������" << endl;
		cin >> name;
		cout << "ѡ���Ա�";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "������ѧ������" << endl;
		cin >> age;
		cout << "������ѧ���༶" << endl;
		cin >> banji;
		cout << "ѡ���ַ" << endl;
		cout << setw(10) << "1.�Ϻ�·" << setw(10) << "2.������·" << setw(10) << "3.������·" << setw(10) << "4.˳��·" << setw(10) << "5.�Ͼ���·"
			<< setw(10) << "6.�Ͼ���·" << setw(10) << "7.��Ŷ�·" << setw(10) << "8.�����·" << setw(10) << "9.��ɽ�����" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:depart = "�Ϻ�·"; break;
		case 2:depart = "������·"; break;
		case 3:depart = "������·"; break;
		case 4:depart = "˳��·"; break;
		case 5:depart = "�Ͼ���·"; break;
		case 6:depart = "�Ͼ���·"; break;
		case 7:depart = "��Ŷ�·"; break;
		case 8:depart = "�����·"; break;
		case 9:depart = "��ɽ�����"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "����ɼ� " << endl;
		cin >> spec;
		cout << "��ʷ�ɼ�" << endl;
		cin >> title;
		cout << "���ĳɼ� " << endl;
		cin >> yuwen;
		cout << "��ѧ�ɼ�" << endl;
		cin >> shuxue;
		cout << "Ӣ��ɼ� " << endl;
		cin >> yingyu;
	}
	void Output()
	{
		cout << setw(10) << "ѧ��"
			<< setw(10) << "����"
			<< setw(10) << "�Ա�"
			<< setw(10) << "����"
			<< setw(10) << "�༶"
			<< endl;
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << banji
			<< endl;
		cout << setw(10) << "��ַ"
			<< setw(10) << "����"
			<< setw(10) << "��ʷ"
			<< setw(10) << "����"
			<< setw(10) << "��ѧ"
			<< setw(10) << "Ӣ��"
			<< endl;
		cout << setw(10) << depart
			<< setw(10) << spec
			<< setw(10) << title
			<< setw(10) << yuwen
			<< setw(10) << shuxue
			<< setw(10) << yingyu
			<< endl;
	}
};
class daxuesheng :virtual public Person//��ѧ��
{
public:
	string zzmm;//��ͥסַ
	string zc;//רҵ
	int choice2;//�Ա�ѡ��
	int choice1;
	int yuwen;
	int shuxue;
	int yingyu;
	int dili;
	int lishi;
	string lianxi;
public:
	daxuesheng(int n = 0, string nm = "", string s = "��", int a = 0, int b = 0, string z = "", string zc = "", int yw = 0, int sx = 0, int yy = 0, int dl = 0, int ls = 0, string lx = "")
		:Person(n, nm, s, a), zzmm(z), zc(zc), yuwen(yw), shuxue(sx), yingyu(yy), dili(dl), lishi(ls), lianxi(lx){};
	void Input()
	{
		cout << "����ѧ��" << endl;
		cin >> num;
		cout << "��������" << endl;
		cin >> name;
		cout << "ѡ���Ա�";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "��������" << endl;
		cin >> age;
		cout << "������ѧ���༶" << endl;
		cin >> banji;
		cout << "ѡ���ַ" << endl;
		cout << setw(10) << "1.�Ϻ�·" << setw(10) << "2.������·" << setw(10) << "3.������·" << setw(10) << "4.˳��·" << setw(10) << "5.�Ͼ���·"
			<< setw(10) << "6.�Ͼ���·" << setw(10) << "7.��Ŷ�·" << setw(10) << "8.�����·" << setw(10) << "9.��ɽ�����" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:zzmm = "�Ϻ�·"; break;
		case 2:zzmm = "������·"; break;
		case 3:zzmm = "������·"; break;
		case 4:zzmm = "˳��·"; break;
		case 5:zzmm = "�Ͼ���·"; break;
		case 6:zzmm = "�Ͼ���·"; break;
		case 7:zzmm = "��Ŷ�·"; break;
		case 8:zzmm = "�����·"; break;
		case 9:zzmm = "��ɽ�����"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "����רҵ" << endl;
		cin >> zc;
		cout << "����ɼ� " << endl;
		cin >> dili;
		cout << "��ʷ�ɼ�" << endl;
		cin >> lishi;
		cout << "���ĳɼ� " << endl;
		cin >> yuwen;
		cout << "��ѧ�ɼ�" << endl;
		cin >> shuxue;
		cout << "Ӣ��ɼ� " << endl;
		cin >> yingyu;
		cout << "��ϵ�绰 " << endl;
		cin >> lianxi;
	}
	void Output()
	{
		cout << setw(10) << "ѧ��"
			<< setw(10) << "����"
			<< setw(10) << "�Ա�"
			<< setw(10) << "����"
			<< endl;
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< endl;
		cout << setw(10) << "�༶"
			<< setw(10) << "��ַ"
			<< setw(10) << "רҵ"
			<< setw(10) << "����"
			<< setw(10) << "��ʷ"
			<< endl;
		cout << setw(10) << banji
			<< setw(10) << zzmm
			<< setw(10) << zc
			<< setw(10) << dili
			<< setw(10) << lishi
			<< endl;
		cout << setw(10) << "����"
			<< setw(10) << "��ѧ"
			<< setw(10) << "Ӣ��"
			<< setw(10) << "��ϵ�绰"
			<< endl;
		cout << setw(10) << yuwen
			<< setw(10) << shuxue
			<< setw(10) << yingyu
			<< setw(12) << lianxi
			<< endl;
	}
};
class xiaoxuesheng :virtual public Person//Сѧ��
{
public:
	int yuwen;//����
	int yingyu;//Ӣ��
	int shuxue;//��ѧ
	int choice2;//ѡ���Ա�
public:
	xiaoxuesheng(int n = 0, string nm = "", string s = "��", int a = 0, int b = 0, int yw = 0, int yy = 0, int sx = 0)
		:Person(n, nm, s, a), yuwen(yw), yingyu(yy), shuxue(sx){};
	void Input()
	{
		cout << "����ѧ��" << endl;
		cin >> num;
		cout << "��������" << endl;
		cin >> name;
		cout << "ѡ���Ա�";
		cout << "(1.��  2.Ů)" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "��"; break;
		case 2:sex = "Ů"; break;
		default:cout << "�������" << endl; break;
		}
		cout << "��������" << endl;
		cin >> age;
		cout << "����༶" << endl;
		cin >> banji;
		cout << "���ĳɼ�" << endl;
		cin >> yuwen;
		cout << "Ӣ��ɼ�" << endl;
		cin >> yingyu;
		cout << "��ѧ�ɼ�" << endl;
		cin >> shuxue;
	}
	void Output()
	{
		cout << setw(10) << "ְ�����"
			<< setw(10) << "����"
			<< setw(10) << "�Ա�"
			<< setw(10) << "����"
			<< setw(10) << "�༶"
			<< setw(10) << "����"
			<< setw(10) << "Ӣ��"
			<< setw(10) << "��ѧ"
			<< endl;
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << banji
			<< setw(10) << yuwen
			<< setw(10) << yingyu
			<< setw(10) << yingyu
			<< endl;
	}
};

class xiao_Manage//Сѧ��������
{
	xiaoxuesheng zhong[TMAX];   //TMAXΪ������Ϊ�����пɴ洢�Ľ�ʦ��¼���������
	int top;            //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	xiao_Manage(){ top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //��ӣ�
	void Show();         //��ʾ�� 
	void Search();       //��ѯ��
	void Edit();         //�޸ģ�
	void Delete();       //ɾ����
	void Total();        //ͳ�ƣ�
	void Save();         //����
	void Read();         //�ɴ��ļ��н���¼��ȡ������������У�
};
void xiao_Manage::Add()//Сѧ��
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	xiaoxuesheng t;//��������
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())//����ı������ڵı�űȽ�
	{
		cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void xiao_Manage::Show()//Сѧ��
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < top; i++)
			zhong[i].Output();
	}
}
void xiao_Manage::Search()//Сѧ��
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "������Ҫ���ҵı��:" << endl;
			   int num;
			   cin >> num;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetNum() == num)
				   {
					   zhong[i].Output();
					   return;
				   }
			   }
			   cout << "���޴��ˣ�" << endl;
	}break;
	case 2:{
			   cout << "������Ҫ���ҵ�����" << endl;
			   string name;
			   cin >> name;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetName() == name)
				   {
					   zhong[i].Output();
				   }
			   }
			   if (zhong[i].GetName() == name)
				   return;
			   cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void xiao_Manage::Edit()//Сѧ��
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵḺ̌��:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "�����λ��ʦ����Ϣ�����޸�:" << endl;
			zhong[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void xiao_Manage::Delete()//Сѧ��
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "�������ţ�";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "ɾ���ɹ���" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "�޴��ʧ�ܣ�" << endl; break;
					  }return;
				  }
			  }
			  cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{
			  cout << "������������";
			  string name;
			  cin >> name;
			  for (int i = 0; i < top; i++)
			  {
				  if (name == zhong[i].name)
				  {
					  cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "ɾ���ɹ���" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "�޴��ʧ�ܣ�" << endl; break;
					  }return;
				  }
			  }
			  cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void xiao_Manage::Total()//Сѧ��
{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "Сѧ������Ϊ:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;//�ֱ�����ͳ����Ů������
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "��") a++;
				  if (zhong[i].sex == "Ů") b++;
			  }
			  cout << "��������Ϊ" << a << endl;
			  cout << "Ů������Ϊ" << b << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void xiao_Manage::Save()//Сѧ��
{
	ofstream out("D:\\ying1.txt", ios::out);//�����ļ������󣬴򿪴����ļ���ofstream����֧�ִӴ����ļ�������
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << zhong[i].num << " "
			<< zhong[i].name << " "
			<< zhong[i].sex << " "
			<< zhong[i].age << " "
			<< zhong[i].yuwen << " "
			<< zhong[i].yingyu
			<< endl;//������ļ��������
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void xiao_Manage::Read()//Сѧ��
{
	ifstream in("D:\\ying1.txt", ios::in);//ifstream����֧��������ļ������
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> zhong[i].num
		>> zhong[i].name
		>> zhong[i].sex
		>> zhong[i].age
		>> zhong[i].yuwen
		>> zhong[i].yingyu)//����ȡ�ɹ�ִ����������
	{
		zhong[i].Output();
		i++;
		top++;
	}
	in.close();
};
class zhong_Manage
{
	zhongxuesheng zhong[TMAX];   //TMAXΪ������Ϊ�����пɴ洢�Ľ�ʦ��¼���������
	int top;             //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	zhong_Manage(){ top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //��ӣ�
	void Show();         //��ʾ�� 
	void Search();       //��ѯ��
	void Edit();         //�޸ģ�
	void Delete();       //ɾ����
	void Total();        //ͳ�ƣ�
	void Save();         //���浽�ļ���
	void Read();         //��ȡ������������У�
};
void zhong_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	zhongxuesheng t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())
	{
		cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void zhong_Manage::Show()
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}

	for (int i = 0; i < top; i++)
		zhong[i].Output();
}
void zhong_Manage::Search()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "������Ҫ���ҵı��:" << endl;
			   int num;
			   cin >> num;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetNum() == num)
				   {
					   zhong[i].Output();
					   return;
				   }
			   }
			   cout << "���޴��ˣ�" << endl;
	}break;
	case 2:{
			   cout << "������Ҫ���ҵ�����" << endl;
			   string name;
			   cin >> name;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetName() == name)
				   {
					   zhong[i].Output();
				   }
			   }

			   if (zhong[i].GetName() == name)
				   return;
			   cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void zhong_Manage::Edit()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵḺ̌��:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "��Ը�����Ϣ�����޸�:" << endl;
			zhong[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void zhong_Manage::Delete()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "�������ţ�";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "ɾ���ɹ���" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "�޴��ʧ�ܣ�" << endl; break;
					  }return;
				  }
			  }
			  cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{
			  cout << "������������";
			  string name;
			  cin >> name;
			  for (int i = 0; i < top; i++)
			  {
				  if (name == zhong[i].name)
				  {
					  cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "ɾ���ɹ���" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "�޴��ʧ�ܣ�" << endl; break;
					  }return;
				  }
			  }
			  cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void zhong_Manage::Total()
{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��    3   ����ַͳ�� " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "��ѧ������Ϊ:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "��") a++;
				  if (zhong[i].sex == "Ů") b++;
			  }
			  cout << "��������Ϊ" << a << endl;
			  cout << "Ů������Ϊ" << b << endl;
	}break;
	case 3:
	{
			  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;//�ֱ�ͳ�Ƹ��ص�����
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].depart == "�Ϻ�·") a1++;
				  if (zhong[i].depart == "������·") a2++;
				  if (zhong[i].depart == "������·") a3++;
				  if (zhong[i].depart == "˳��·") a4++;
				  if (zhong[i].depart == "�Ͼ���·") a5++;
				  if (zhong[i].depart == "�Ͼ���·") a6++;
				  if (zhong[i].depart == "��Ŷ�·") a7++;
				  if (zhong[i].depart == "�����·") a8++;
				  if (zhong[i].depart == "��ɽ�����") a9++;
			  }
			  cout << "�Ϻ�·����Ϊ" << a1 << endl;
			  cout << "������·����Ϊ" << a2 << endl;
			  cout << "������·����Ϊ" << a3 << endl;
			  cout << "˳��·����Ϊ" << a4 << endl;
			  cout << "�Ͼ���·����Ϊ" << a5 << endl;
			  cout << "�Ͼ���·����Ϊ" << a6 << endl;
			  cout << "��Ŷ�·����Ϊ" << a7 << endl;
			  cout << "�����·����Ϊ" << a8 << endl;
			  cout << "��ɽ���������Ϊ" << a9 << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void zhong_Manage::Save()
{
	ofstream out("D:\\ying2.txt", ios::out);
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << zhong[i].num << " "
			<< zhong[i].name << " "
			<< zhong[i].sex << " "
			<< zhong[i].age << " "
			<< zhong[i].depart << " "
			<< zhong[i].spec << " "
			<< zhong[i].title
			<< endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void zhong_Manage::Read()
{
	ifstream in("D:\\ying2.txt", ios::in);
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> zhong[i].num
		>> zhong[i].name
		>> zhong[i].sex
		>> zhong[i].age
		>> zhong[i].depart
		>> zhong[i].spec
		>> zhong[i].title)
	{
		zhong[i].Output();
		i++;
		top++;
	}
	in.close();
};
class da_Manage
{
	daxuesheng zhong[TMAX];   //TMAXΪ������Ϊ�����пɴ洢�Ľ�ʦ��¼���������
	int top;             //top��ʾ��ǰϵͳ�д洢�ļ�¼������
public:
	da_Manage(){ top = 0; } //��ʼʱ��¼�ĸ���Ϊ0����������top=0;
	void Add();          //��ӣ�
	void Show();         //��ʾ�� 
	void Search();       //��ѯ��
	void Edit();         //�޸ģ�
	void Delete();       //ɾ����
	void Total();        //ͳ�ƣ�
	void Save();         //���浽�ļ���
	void Read();         //��ȡ������������У�
};
void da_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "�û�����" << endl;
		return;
	}
	daxuesheng t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())
	{
		cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "��ӳɹ�!" << endl;
}
void da_Manage::Show()
{
	if (top == 0)
	{
		cout << "������!" << endl;
		return;
	}
	for (int i = 0; i < top; i++)
		zhong[i].Output();
}
void da_Manage::Search()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼" << endl;
		return;
	}
	int choice;
	cout << "��ѡ����ҷ�ʽ:1.����Ų��� 2.����������." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "������Ҫ���ҵı��:" << endl;
			   int num;
			   cin >> num;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetNum() == num)
				   {
					   zhong[i].Output();
					   return;
				   }
			   }
			   cout << "���޴��ˣ�" << endl;
	}break;
	case 2:{
			   cout << "������Ҫ���ҵ�����" << endl;
			   string name;
			   cin >> name;
			   for (int i = 0; i < top; i++)
			   {
				   if (zhong[i].GetName() == name)
				   {
					   zhong[i].Output();
				   }
			   }
			   if (zhong[i].GetName() == name)
				   return;
			   cout << "���޴��ˣ�" << endl;
	}break;
	default:cout << "�޴�ѡ��!������!" << endl; break;
	}
}
void da_Manage::Delete()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "1������Ų���ɾ��          2������������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "�������ţ�";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "ɾ���ɹ���" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "�޴��ʧ�ܣ�" << endl; break;
					  }return;
				  }
			  }
			  cout << "�޴��ˣ�" << endl;

	}; break;
	case 2:
	{cout << "������������";
	string name;
	cin >> name;
	for (int i = 0; i < top; i++)
	{
		if (name == zhong[i].name)
		{
			cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
					  for (int j = i; j < top - 1; j++)
						  zhong[j] = zhong[j + 1];
					  cout << "ɾ���ɹ���" << endl;
					  top--;
			}; break;
			case 2:return;
			default:cout << "�޴��ʧ�ܣ�" << endl; break;
			}return;
		}
	}
	cout << "�޴��ˣ�" << endl;
	};  break;
	default:cout << "û�д��ʧ�ܣ�" << endl; break;
	}
}
void da_Manage::Edit()
{
	if (top == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int num;
	cout << "������Ҫ���ҵ�ѧ��:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "���޸ĸ�����Ϣ:" << endl;
			zhong[i].Input();
			cout << "�޸ĳɹ�" << endl; return;
		}
	}
	cout << "���޴���" << endl;
}
void da_Manage::Total()
{
	cout << "1  ������ͳ��    2  ���Ա�ͳ��    " << endl;
	int choice;
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "��ѧ������Ϊ:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "��") a++;
				  if (zhong[i].sex == "Ů") b++;
			  }
			  cout << "��������Ϊ" << a << endl;
			  cout << "Ů������Ϊ" << b << endl;
	}break;
	default:cout << "�����������������" << endl; break;
	}
}
void da_Manage::Save()
{
	ofstream out("D:\\ying3.txt", ios::out);
	if (!out)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << zhong[i].num << " "
			<< zhong[i].name << " "
			<< zhong[i].sex << " "
			<< zhong[i].age << " "
			<< zhong[i].zzmm << " "
			<< zhong[i].zc
			<< endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}
void da_Manage::Read()
{
	ifstream in("D:\\ying3.txt", ios::in);
	if (!in)
	{
		cout << "��ʧ��!" << endl;
		return;
	}
	int i = 0;
	while (in >> zhong[i].num
		>> zhong[i].name
		>> zhong[i].sex
		>> zhong[i].age
		>> zhong[i].zzmm
		>> zhong[i].zc)
	{
		zhong[i].Output();
		i++;
		top++;
	}
	in.close();
};

void xiaoMenu();
void zhongMenu();
void daMenu();
int main()
{
	cout << "***********************************************************************************************************************" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                      ѧ         ��         ��         ��         ��        ��        ϵ         ͳ                  *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	int choice;

	do{
		cout << "                  *****���˵�*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                    1=>Сѧ����Ϣ����               ||" << endl;
		cout << "||                    2=>��ѧ����Ϣ����               ||" << endl;
		cout << "||                    3=>��ѧ����Ϣ����               ||" << endl;
		cout << "||                    0=>�˳�ϵͳ                     ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n����������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:xiaoMenu(); break;
		case 2:zhongMenu(); break;
		case 3:daMenu(); break;
		case 0:cout << "\n���Ѱ�ȫ�˳�ϵͳ." << endl; break;
		default:cout << "\nû�д�ѡ��.����ѡ." << endl; break;
		}
	} while (choice != 0);
	cout << "\n                                          ***��ӭ���´���ʹ�ñ�ϵͳ!***" << endl;
	return 0;
}
void xiaoMenu()
{
	xiao_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****Сѧ��*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>�����Ϣ               ||" << endl;
		cout << "||                    2=>������Ϣ               ||" << endl;
		cout << "||                    3=>�޸���Ϣ               ||" << endl;
		cout << "||                    4=>ɾ����Ϣ               ||" << endl;
		cout << "||                    5=>��ʾ��Ϣ               ||" << endl;
		cout << "||                    6=>������Ϣ               ||" << endl;
		cout << "||                    7=>��ȡ��Ϣ               ||" << endl;
		cout << "||                    8=>ͳ����Ϣ               ||" << endl;
		cout << "||                    0=>�˳�                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 0:cout << "�˳��ɹ�!" << endl; break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
void zhongMenu()
{
	zhong_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****��ѧ��*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>�����Ϣ               ||" << endl;
		cout << "||                    2=>������Ϣ               ||" << endl;
		cout << "||                    3=>�޸���Ϣ               ||" << endl;
		cout << "||                    4=>ɾ����Ϣ               ||" << endl;
		cout << "||                    5=>��ʾ��Ϣ               ||" << endl;
		cout << "||                    6=>������Ϣ               ||" << endl;
		cout << "||                    7=>��ȡ��Ϣ               ||" << endl;
		cout << "||                    8=>ͳ����Ϣ               ||" << endl;
		cout << "||                    0=>�˳�                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 0:cout << "�˳��ɹ�!" << endl; break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}
void daMenu()
{
	da_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****��ѧ��*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>�����Ϣ               ||" << endl;
		cout << "||                    2=>������Ϣ               ||" << endl;
		cout << "||                    3=>�޸���Ϣ               ||" << endl;
		cout << "||                    4=>ɾ����Ϣ               ||" << endl;
		cout << "||                    5=>��ʾ��Ϣ               ||" << endl;
		cout << "||                    6=>������Ϣ               ||" << endl;
		cout << "||                    7=>��ȡ��Ϣ               ||" << endl;
		cout << "||                    8=>ͳ����Ϣ               ||" << endl;
		cout << "||                    0=>�˳�                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n������������ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 1:t.Add(); break;
		case 2:t.Search(); break;
		case 3:t.Edit(); break;
		case 4:t.Delete(); break;
		case 5:t.Show(); break;
		case 6:t.Save(); break;
		case 7:t.Read(); break;
		case 8:t.Total(); break;
		case 0:cout << "�˳��ɹ�!" << endl; break;
		default:cout << "�޴�ѡ��!������!" << endl; break;
		}
	}
}


