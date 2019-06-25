#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>//输入操纵
const int TMAX = 50;//定义常变量
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
	virtual void Input(){};//虚函数，派生类中重新定义
	virtual void Output(){};
	int GetNum(){ return num; }//获取编号
	string GetName(){ return name; }//获取姓名
};
class zhongxuesheng :virtual public Person//声明为虚基类是因为在派生类中只继承一次
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
	zhongxuesheng(int n = 0, string nm = "", string s = "男", int a = 0, int b = 0, string d = "上海路", int sp = 0, int t = 0, int yw = 0, int sx = 0, int yy = 0)
		:Person(n, nm, s, a, b), depart(d), spec(sp), title(t), yuwen(yw), shuxue(sx), yingyu(yy){};
	void Input()
	{
		cout << "请输入学生生学号" << endl;
		cin >> num;
		cout << "请输入学生名字" << endl;
		cin >> name;
		cout << "选择性别";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "请输入学生年龄" << endl;
		cin >> age;
		cout << "请输入学生班级" << endl;
		cin >> banji;
		cout << "选择地址" << endl;
		cout << setw(10) << "1.上海路" << setw(10) << "2.北京东路" << setw(10) << "3.北京西路" << setw(10) << "4.顺外路" << setw(10) << "5.南京东路"
			<< setw(10) << "6.南京西路" << setw(10) << "7.解放东路" << setw(10) << "8.解放西路" << setw(10) << "9.青山湖大道" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:depart = "上海路"; break;
		case 2:depart = "北京东路"; break;
		case 3:depart = "北京西路"; break;
		case 4:depart = "顺外路"; break;
		case 5:depart = "南京东路"; break;
		case 6:depart = "南京西路"; break;
		case 7:depart = "解放东路"; break;
		case 8:depart = "解放西路"; break;
		case 9:depart = "青山湖大道"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "地理成绩 " << endl;
		cin >> spec;
		cout << "历史成绩" << endl;
		cin >> title;
		cout << "语文成绩 " << endl;
		cin >> yuwen;
		cout << "数学成绩" << endl;
		cin >> shuxue;
		cout << "英语成绩 " << endl;
		cin >> yingyu;
	}
	void Output()
	{
		cout << setw(10) << "学号"
			<< setw(10) << "姓名"
			<< setw(10) << "性别"
			<< setw(10) << "年龄"
			<< setw(10) << "班级"
			<< endl;
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< setw(10) << banji
			<< endl;
		cout << setw(10) << "地址"
			<< setw(10) << "地理"
			<< setw(10) << "历史"
			<< setw(10) << "语文"
			<< setw(10) << "数学"
			<< setw(10) << "英语"
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
class daxuesheng :virtual public Person//大学生
{
public:
	string zzmm;//家庭住址
	string zc;//专业
	int choice2;//性别选择
	int choice1;
	int yuwen;
	int shuxue;
	int yingyu;
	int dili;
	int lishi;
	string lianxi;
public:
	daxuesheng(int n = 0, string nm = "", string s = "男", int a = 0, int b = 0, string z = "", string zc = "", int yw = 0, int sx = 0, int yy = 0, int dl = 0, int ls = 0, string lx = "")
		:Person(n, nm, s, a), zzmm(z), zc(zc), yuwen(yw), shuxue(sx), yingyu(yy), dili(dl), lishi(ls), lianxi(lx){};
	void Input()
	{
		cout << "输入学号" << endl;
		cin >> num;
		cout << "输入名字" << endl;
		cin >> name;
		cout << "选择性别";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "输入年龄" << endl;
		cin >> age;
		cout << "请输入学生班级" << endl;
		cin >> banji;
		cout << "选择地址" << endl;
		cout << setw(10) << "1.上海路" << setw(10) << "2.北京东路" << setw(10) << "3.北京西路" << setw(10) << "4.顺外路" << setw(10) << "5.南京东路"
			<< setw(10) << "6.南京西路" << setw(10) << "7.解放东路" << setw(10) << "8.解放西路" << setw(10) << "9.青山湖大道" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:zzmm = "上海路"; break;
		case 2:zzmm = "北京东路"; break;
		case 3:zzmm = "北京西路"; break;
		case 4:zzmm = "顺外路"; break;
		case 5:zzmm = "南京东路"; break;
		case 6:zzmm = "南京西路"; break;
		case 7:zzmm = "解放东路"; break;
		case 8:zzmm = "解放西路"; break;
		case 9:zzmm = "青山湖大道"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "输入专业" << endl;
		cin >> zc;
		cout << "地理成绩 " << endl;
		cin >> dili;
		cout << "历史成绩" << endl;
		cin >> lishi;
		cout << "语文成绩 " << endl;
		cin >> yuwen;
		cout << "数学成绩" << endl;
		cin >> shuxue;
		cout << "英语成绩 " << endl;
		cin >> yingyu;
		cout << "联系电话 " << endl;
		cin >> lianxi;
	}
	void Output()
	{
		cout << setw(10) << "学号"
			<< setw(10) << "姓名"
			<< setw(10) << "性别"
			<< setw(10) << "年龄"
			<< endl;
		cout << setw(10) << num
			<< setw(10) << name
			<< setw(10) << sex
			<< setw(10) << age
			<< endl;
		cout << setw(10) << "班级"
			<< setw(10) << "地址"
			<< setw(10) << "专业"
			<< setw(10) << "地理"
			<< setw(10) << "历史"
			<< endl;
		cout << setw(10) << banji
			<< setw(10) << zzmm
			<< setw(10) << zc
			<< setw(10) << dili
			<< setw(10) << lishi
			<< endl;
		cout << setw(10) << "语文"
			<< setw(10) << "数学"
			<< setw(10) << "英语"
			<< setw(10) << "联系电话"
			<< endl;
		cout << setw(10) << yuwen
			<< setw(10) << shuxue
			<< setw(10) << yingyu
			<< setw(12) << lianxi
			<< endl;
	}
};
class xiaoxuesheng :virtual public Person//小学生
{
public:
	int yuwen;//语文
	int yingyu;//英语
	int shuxue;//数学
	int choice2;//选择性别
public:
	xiaoxuesheng(int n = 0, string nm = "", string s = "男", int a = 0, int b = 0, int yw = 0, int yy = 0, int sx = 0)
		:Person(n, nm, s, a), yuwen(yw), yingyu(yy), shuxue(sx){};
	void Input()
	{
		cout << "输入学号" << endl;
		cin >> num;
		cout << "输入姓名" << endl;
		cin >> name;
		cout << "选择性别";
		cout << "(1.男  2.女)" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice2;
		switch (choice2)
		{
		case 1:sex = "男"; break;
		case 2:sex = "女"; break;
		default:cout << "输入错误。" << endl; break;
		}
		cout << "输入年龄" << endl;
		cin >> age;
		cout << "输入班级" << endl;
		cin >> banji;
		cout << "语文成绩" << endl;
		cin >> yuwen;
		cout << "英语成绩" << endl;
		cin >> yingyu;
		cout << "数学成绩" << endl;
		cin >> shuxue;
	}
	void Output()
	{
		cout << setw(10) << "职工编号"
			<< setw(10) << "姓名"
			<< setw(10) << "性别"
			<< setw(10) << "年龄"
			<< setw(10) << "班级"
			<< setw(10) << "语文"
			<< setw(10) << "英语"
			<< setw(10) << "数学"
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

class xiao_Manage//小学生管理类
{
	xiaoxuesheng zhong[TMAX];   //TMAX为常量，为数组中可存储的教师记录的最大数；
	int top;            //top表示当前系统中存储的记录个数；
public:
	xiao_Manage(){ top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //添加；
	void Show();         //显示； 
	void Search();       //查询；
	void Edit();         //修改；
	void Delete();       //删除；
	void Total();        //统计；
	void Save();         //保存
	void Read();         //可从文件中将记录读取到该类的数组中；
};
void xiao_Manage::Add()//小学生
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	xiaoxuesheng t;//声明对象
	cout << "输入新添加的人员的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())//输入的编号与存在的编号比较
	{
		cout << "该编号的人员已存在" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void xiao_Manage::Show()//小学生
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < top; i++)
			zhong[i].Output();
	}
}
void xiao_Manage::Search()//小学生
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "请输入要查找的编号:" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	case 2:{
			   cout << "请输入要查找的姓名" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void xiao_Manage::Edit()//小学生
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的教编号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "请对这位教师的信息进行修改:" << endl;
			zhong[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void xiao_Manage::Delete()//小学生
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "请输入编号：";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "是否确认删除？     1、是    2、否  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "删除成功！" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "无此项，失败！" << endl; break;
					  }return;
				  }
			  }
			  cout << "无此人！" << endl;

	}; break;
	case 2:
	{
			  cout << "请输入姓名：";
			  string name;
			  cin >> name;
			  for (int i = 0; i < top; i++)
			  {
				  if (name == zhong[i].name)
				  {
					  cout << "是否确认删除？     1、是    2、否  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "删除成功！" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "无此项，失败！" << endl; break;
					  }return;
				  }
			  }
			  cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void xiao_Manage::Total()//小学生
{
	cout << "1  按人数统计    2  按性别统计    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "小学生人数为:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;//分别用于统计男女的人数
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "男") a++;
				  if (zhong[i].sex == "女") b++;
			  }
			  cout << "男性人数为" << a << endl;
			  cout << "女性人数为" << b << endl;
	}break;
	default:cout << "输入错误。请重新输入" << endl; break;
	}
}
void xiao_Manage::Save()//小学生
{
	ofstream out("D:\\ying1.txt", ios::out);//定义文件流对象，打开磁盘文件，ofstream用来支持从磁盘文件的输入
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
	for (int i = 0; i < top; i++)
	{
		out << zhong[i].num << " "
			<< zhong[i].name << " "
			<< zhong[i].sex << " "
			<< zhong[i].age << " "
			<< zhong[i].yuwen << " "
			<< zhong[i].yingyu
			<< endl;//向磁盘文件输出数据
	}
	cout << "写入成功！" << endl;
	out.close();
}
void xiao_Manage::Read()//小学生
{
	ifstream in("D:\\ying1.txt", ios::in);//ifstream用来支持向磁盘文件的输出
	if (!in)
	{
		cout << "打开失败!" << endl;
		return;
	}
	int i = 0;
	while (in >> zhong[i].num
		>> zhong[i].name
		>> zhong[i].sex
		>> zhong[i].age
		>> zhong[i].yuwen
		>> zhong[i].yingyu)//当读取成功执行下面的语句
	{
		zhong[i].Output();
		i++;
		top++;
	}
	in.close();
};
class zhong_Manage
{
	zhongxuesheng zhong[TMAX];   //TMAX为常量，为数组中可存储的教师记录的最大数；
	int top;             //top表示当前系统中存储的记录个数；
public:
	zhong_Manage(){ top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //添加；
	void Show();         //显示； 
	void Search();       //查询；
	void Edit();         //修改；
	void Delete();       //删除；
	void Total();        //统计；
	void Save();         //保存到文件；
	void Read();         //读取到该类的数组中；
};
void zhong_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	zhongxuesheng t;
	cout << "输入新添加的人员的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())
	{
		cout << "该编号的人员已存在" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void zhong_Manage::Show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}

	for (int i = 0; i < top; i++)
		zhong[i].Output();
}
void zhong_Manage::Search()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "请输入要查找的编号:" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	case 2:{
			   cout << "请输入要查找的姓名" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void zhong_Manage::Edit()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的教编号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "请对该生信息进行修改:" << endl;
			zhong[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void zhong_Manage::Delete()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "请输入编号：";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "是否确认删除？     1、是    2、否  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "删除成功！" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "无此项，失败！" << endl; break;
					  }return;
				  }
			  }
			  cout << "无此人！" << endl;

	}; break;
	case 2:
	{
			  cout << "请输入姓名：";
			  string name;
			  cin >> name;
			  for (int i = 0; i < top; i++)
			  {
				  if (name == zhong[i].name)
				  {
					  cout << "是否确认删除？     1、是    2、否  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "删除成功！" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "无此项，失败！" << endl; break;
					  }return;
				  }
			  }
			  cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void zhong_Manage::Total()
{
	cout << "1  按人数统计    2  按性别统计    3   按地址统计 " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "中学生人数为:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "男") a++;
				  if (zhong[i].sex == "女") b++;
			  }
			  cout << "男生人数为" << a << endl;
			  cout << "女生人数为" << b << endl;
	}break;
	case 3:
	{
			  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;//分别统计各地的人数
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].depart == "上海路") a1++;
				  if (zhong[i].depart == "北京东路") a2++;
				  if (zhong[i].depart == "北京西路") a3++;
				  if (zhong[i].depart == "顺外路") a4++;
				  if (zhong[i].depart == "南京东路") a5++;
				  if (zhong[i].depart == "南京西路") a6++;
				  if (zhong[i].depart == "解放东路") a7++;
				  if (zhong[i].depart == "解放西路") a8++;
				  if (zhong[i].depart == "青山湖大道") a9++;
			  }
			  cout << "上海路人数为" << a1 << endl;
			  cout << "北京东路人数为" << a2 << endl;
			  cout << "北京西路人数为" << a3 << endl;
			  cout << "顺外路人数为" << a4 << endl;
			  cout << "南京东路人数为" << a5 << endl;
			  cout << "南京西路人数为" << a6 << endl;
			  cout << "解放东路人数为" << a7 << endl;
			  cout << "解放西路人数为" << a8 << endl;
			  cout << "青山湖大道人数为" << a9 << endl;
	}break;
	default:cout << "输入错误。请重新输入" << endl; break;
	}
}
void zhong_Manage::Save()
{
	ofstream out("D:\\ying2.txt", ios::out);
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
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
	cout << "写入成功！" << endl;
	out.close();
}
void zhong_Manage::Read()
{
	ifstream in("D:\\ying2.txt", ios::in);
	if (!in)
	{
		cout << "打开失败!" << endl;
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
	daxuesheng zhong[TMAX];   //TMAX为常量，为数组中可存储的教师记录的最大数；
	int top;             //top表示当前系统中存储的记录个数；
public:
	da_Manage(){ top = 0; } //初始时记录的个数为0，所以设置top=0;
	void Add();          //添加；
	void Show();         //显示； 
	void Search();       //查询；
	void Edit();         //修改；
	void Delete();       //删除；
	void Total();        //统计；
	void Save();         //保存到文件；
	void Read();         //读取到该类的数组中；
};
void da_Manage::Add()
{
	if (top >= TMAX)
	{
		cout << "用户已满" << endl;
		return;
	}
	daxuesheng t;
	cout << "输入新添加的人员的信息" << endl;
	t.Input();
	for (int i = 0; i < top; i++)
	if (t.GetNum() == zhong[i].GetNum())
	{
		cout << "该编号的人员已存在" << endl;
		return;
	}
	zhong[top] = t;
	top = top + 1;
	cout << "添加成功!" << endl;
}
void da_Manage::Show()
{
	if (top == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	for (int i = 0; i < top; i++)
		zhong[i].Output();
}
void da_Manage::Search()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录" << endl;
		return;
	}
	int choice;
	cout << "请选择查找方式:1.按编号查找 2.按姓名查找." << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:{
			   cout << "请输入要查找的编号:" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	case 2:{
			   cout << "请输入要查找的姓名" << endl;
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
			   cout << "查无此人！" << endl;
	}break;
	default:cout << "无此选项!请重试!" << endl; break;
	}
}
void da_Manage::Delete()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "1、按编号查找删除          2、按姓名查找删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
			  cout << "请输入编号：";
			  int num;
			  cin >> num;
			  for (int i = 0; i < top; i++)
			  {
				  if (num == zhong[i].num)
				  {
					  cout << "是否确认删除？     1、是    2、否  " << endl;
					  int choice;
					  cin >> choice;
					  switch (choice)
					  {
					  case 1:
					  {
								for (int j = i; j < top - 1; j++)
									zhong[j] = zhong[j + 1];
								cout << "删除成功！" << endl;
								top--;
					  }; break;
					  case 2:return;
					  default:cout << "无此项，失败！" << endl; break;
					  }return;
				  }
			  }
			  cout << "无此人！" << endl;

	}; break;
	case 2:
	{cout << "请输入姓名：";
	string name;
	cin >> name;
	for (int i = 0; i < top; i++)
	{
		if (name == zhong[i].name)
		{
			cout << "是否确认删除？     1、是    2、否  " << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
					  for (int j = i; j < top - 1; j++)
						  zhong[j] = zhong[j + 1];
					  cout << "删除成功！" << endl;
					  top--;
			}; break;
			case 2:return;
			default:cout << "无此项，失败！" << endl; break;
			}return;
		}
	}
	cout << "无此人！" << endl;
	};  break;
	default:cout << "没有此项，失败：" << endl; break;
	}
}
void da_Manage::Edit()
{
	if (top == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int num;
	cout << "请输入要查找的学号:" << endl;
	cin >> num;
	for (int i = 0; i < top; i++)
	{
		if (zhong[i].GetNum() == num)
		{
			cout << "请修改该生信息:" << endl;
			zhong[i].Input();
			cout << "修改成功" << endl; return;
		}
	}
	cout << "查无此人" << endl;
}
void da_Manage::Total()
{
	cout << "1  按人数统计    2  按性别统计    " << endl;
	int choice;
	cout << "请输入你的选择" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:cout << "大学生人数为:" << top << endl; break;
	case 2:
	{
			  int a = 0, b = 0;
			  for (int i = 0; i < top; i++)
			  {
				  if (zhong[i].sex == "男") a++;
				  if (zhong[i].sex == "女") b++;
			  }
			  cout << "男性人数为" << a << endl;
			  cout << "女性人数为" << b << endl;
	}break;
	default:cout << "输入错误。请重新输入" << endl; break;
	}
}
void da_Manage::Save()
{
	ofstream out("D:\\ying3.txt", ios::out);
	if (!out)
	{
		cout << "打开失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
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
	cout << "写入成功！" << endl;
	out.close();
}
void da_Manage::Read()
{
	ifstream in("D:\\ying3.txt", ios::in);
	if (!in)
	{
		cout << "打开失败!" << endl;
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
	cout << "*                      学         生         成         绩         管        理        系         统                  *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "*                                                                                                                     *" << endl;
	cout << "***********************************************************************************************************************" << endl;
	int choice;

	do{
		cout << "                  *****主菜单*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                    1=>小学生信息管理               ||" << endl;
		cout << "||                    2=>中学生信息管理               ||" << endl;
		cout << "||                    3=>大学生信息管理               ||" << endl;
		cout << "||                    0=>退出系统                     ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << "||                                                    ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n请输入您的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:xiaoMenu(); break;
		case 2:zhongMenu(); break;
		case 3:daMenu(); break;
		case 0:cout << "\n您已安全退出系统." << endl; break;
		default:cout << "\n没有此选项.请重选." << endl; break;
		}
	} while (choice != 0);
	cout << "\n                                          ***欢迎您下次再使用本系统!***" << endl;
	return 0;
}
void xiaoMenu()
{
	xiao_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****小学生*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>添加信息               ||" << endl;
		cout << "||                    2=>查找信息               ||" << endl;
		cout << "||                    3=>修改信息               ||" << endl;
		cout << "||                    4=>删除信息               ||" << endl;
		cout << "||                    5=>显示信息               ||" << endl;
		cout << "||                    6=>保存信息               ||" << endl;
		cout << "||                    7=>读取信息               ||" << endl;
		cout << "||                    8=>统计信息               ||" << endl;
		cout << "||                    0=>退出                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl; break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
void zhongMenu()
{
	zhong_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****中学生*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>添加信息               ||" << endl;
		cout << "||                    2=>查找信息               ||" << endl;
		cout << "||                    3=>修改信息               ||" << endl;
		cout << "||                    4=>删除信息               ||" << endl;
		cout << "||                    5=>显示信息               ||" << endl;
		cout << "||                    6=>保存信息               ||" << endl;
		cout << "||                    7=>读取信息               ||" << endl;
		cout << "||                    8=>统计信息               ||" << endl;
		cout << "||                    0=>退出                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl; break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}
void daMenu()
{
	da_Manage t;
	int choice;
	while (choice != 0)
	{
		cout << "                  *****大学生*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                              ||" << endl;
		cout << "||                    1=>添加信息               ||" << endl;
		cout << "||                    2=>查找信息               ||" << endl;
		cout << "||                    3=>修改信息               ||" << endl;
		cout << "||                    4=>删除信息               ||" << endl;
		cout << "||                    5=>显示信息               ||" << endl;
		cout << "||                    6=>保存信息               ||" << endl;
		cout << "||                    7=>读取信息               ||" << endl;
		cout << "||                    8=>统计信息               ||" << endl;
		cout << "||                    0=>退出                   ||" << endl;
		cout << "||                                              ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n输入您操作的选项：";
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
		case 0:cout << "退出成功!" << endl; break;
		default:cout << "无此选项!请重试!" << endl; break;
		}
	}
}


