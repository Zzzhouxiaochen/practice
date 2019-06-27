/************************************************************************/
/* 数据信息                                                             */
/************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "time.h"


//航班信息表
#define SIZELIMIT 10 //每航班的具体信息的字符个数限制在10以内
#define MAXNUM 1000 //设定最多只能录入1000个航班信息

/************************************************************************/

typedef struct cardbase //定义一个关于航班信息的结构体，取名为CardBase
{
	char C_ID[SIZELIMIT];//航班

	char C_TIMEYEAR[SIZELIMIT];//起飞年
	char C_TIMEMOUTH[SIZELIMIT];//起飞月
	char C_TIMEDAY[SIZELIMIT];//起飞日
	char C_TIMEHOUR[SIZELIMIT];//起飞时
	char C_TIMEMINUTE[SIZELIMIT];//起飞分
	char C_PRICE[SIZELIMIT];//票价

	char C_ANAME[SIZELIMIT];//起点站
	char C_BNAME[SIZELIMIT];//终点站
	char C_USETIME[SIZELIMIT];//飞行时间
	char C_MAXNUM[MAXNUM];//额定载量
	char C_REMAINNUM[MAXNUM];//余票数量

}CardBase;
int cbNum = 0;//记录航班数
CardBase cBList[MAXNUM];//航班列表



typedef struct Customer   //乘客信息
{

	char Name[SIZELIMIT];   //姓名
	char ID[MAXNUM];	//身份证
	char LEVEl[SIZELIMIT];   //舱位等级
	char SEATNUM[SIZELIMIT];   //座位号
	char FLIGHTNUM[SIZELIMIT];   //所定航班号

	char ADDRESS[MAXNUM];//工作地址
	char BOOKNUM[SIZELIMIT];//所定票数
	char SEX[SIZELIMIT];//性别
	char TEL[MAXNUM];//电话

}Customer;
int ccNum = 0;//记录顾客数
Customer ccBList[MAXNUM];//顾客列表


/************************************************************************/
/*               信息读取                                                       */
/************************************************************************/



//读取航班信息
void readcardbasefile()
{
	FILE *fp;
	//打开文件失败则创建文件
	if ((fp = fopen("./number.dat", "r")) == NULL)
	{
		//初次运行创建文件
		if ((fp = fopen("./number.dat", "w")) == NULL)
		{
			exit(0); //返回
		}
		else
		{
			fclose(fp);
		}
		return;
	}
	/*文件位置指针移动到文件末尾*/
	fseek(fp, 0, SEEK_END);//重定位文件内部位置指针
	/* int fseek( FILE *stream, long offset, int origin );
	第一个参数stream为文件指针
	第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
	第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
	SEEK_SET： 文件开头
	SEEK_CUR： 当前位置
	SEEK_END： 文件结尾
	其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
	简言之：
	fseek(fp,100L,0);把stream指针移动到离文件开头100字节处；
	fseek(fp,100L,1);把stream指针移动到离文件当前位置100字节处；
	fseek(fp,-100L,2);把stream指针退回到离文件结尾100字节处。 */
	if (ftell(fp) > 0)//文件不为空
		/*ftell函数用于得到文件位置指针当前位置相对于文件首的偏移字节数
		也就是得到文件所包含的字节数,如果大于0，则代表文件非空*/
	{
		//文件位置指针移动到文件开始
		rewind(fp);
		char buff[10] = { 0 };
		for (cbNum = 0; !feof(fp) && fread(&cBList[cbNum], sizeof(CardBase), 1, fp); cbNum++)
			/*对于feof函数，如果遇到文件结束，函数feof（fp）的值为非零值，否则为0。
			即如果文件结束，!feof(fp)为0，跳出循环
			对于fread函数，是从一个文件流中读数据，如果调用成功返回实际读取到的项个数，
			如果不成功或读到文件末尾返回 0*/
			fgets(buff, 10, fp);
		/*char *fgets(char *buf, int bufsize, FILE *stream);
		从文件结构体指针stream中读取数据，每次读取一行。读取的数据保存在buf指向的字符数组中，
		每次最多读取bufsize-1个字符（第bufsize个字符赋'\0'），如果文件中的该行，不足bufsize个字符，
		则读完该行就结束。如若该行（包括最后一个换行符）的字符数超过bufsize-1，则fgets只返回一个不完整的行，
		但是，缓冲区总是以NULL字符结尾，对fgets的下一次调用会继续读该行。函数成功将返回buf，失败或读到文件结尾返回NULL。
		因此我们不能直接通过fgets的返回值来判断函数是否是出错而终止的，应该借助feof函数或者ferror函数来判断。
		*/
		fclose(fp);
	}
	else
	{
		fclose(fp);
	}
	return;
}

// 读取用户信息
void readyonghubasefile()
{
	FILE *fp;
	//打开文件失败则创建文件
	if ((fp = fopen("yonghu.txt", "r")) == NULL)
	{
		//初次运行创建文件
		if ((fp = fopen("yonghu.txt", "w")) == NULL)
		{
			exit(0); //返回
		}
		else
		{
			fclose(fp);
		}
		return;
	}
	/*文件位置指针移动到文件末尾*/
	fseek(fp, 0, SEEK_END);//重定位文件内部位置指针
	/* int fseek( FILE *stream, long offset, int origin );
	第一个参数stream为文件指针
	第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移
	第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET
	SEEK_SET： 文件开头
	SEEK_CUR： 当前位置
	SEEK_END： 文件结尾
	其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
	简言之：
	fseek(fp,100L,0);把stream指针移动到离文件开头100字节处；
	fseek(fp,100L,1);把stream指针移动到离文件当前位置100字节处；
	fseek(fp,-100L,2);把stream指针退回到离文件结尾100字节处。 */
	if (ftell(fp) > 0)//文件不为空
		/*ftell函数用于得到文件位置指针当前位置相对于文件首的偏移字节数
		也就是得到文件所包含的字节数,如果大于0，则代表文件非空*/
	{
		//文件位置指针移动到文件开始
		rewind(fp);
		char buff[10] = { 0 };
		for (ccNum = 0; !feof(fp) && fread(&ccBList[ccNum], sizeof(Customer), 1, fp); ccNum++)
			/*对于feof函数，如果遇到文件结束，函数feof（fp）的值为非零值，否则为0。
			即如果文件结束，!feof(fp)为0，跳出循环
			对于fread函数，是从一个文件流中读数据，如果调用成功返回实际读取到的项个数，
			如果不成功或读到文件末尾返回 0*/
			fgets(buff, 10, fp);
		/*char *fgets(char *buf, int bufsize, FILE *stream);
		从文件结构体指针stream中读取数据，每次读取一行。读取的数据保存在buf指向的字符数组中，
		每次最多读取bufsize-1个字符（第bufsize个字符赋'\0'），如果文件中的该行，不足bufsize个字符，
		则读完该行就结束。如若该行（包括最后一个换行符）的字符数超过bufsize-1，则fgets只返回一个不完整的行，
		但是，缓冲区总是以NULL字符结尾，对fgets的下一次调用会继续读该行。函数成功将返回buf，失败或读到文件结尾返回NULL。
		因此我们不能直接通过fgets的返回值来判断函数是否是出错而终止的，应该借助feof函数或者ferror函数来判断。
		*/
		fclose(fp);
	}
	else
	{
		fclose(fp);
	}
	return;
}


/************************************************************************/
/* 保存信息                                                                     */
/************************************************************************/

//保存航班信息
void writecardbasefile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("./number.dat", "w")) == NULL)
	{
		printf("系统错误");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < cbNum; i++)
	{
		if (fwrite(&cBList[i], sizeof(CardBase), 1, fp) != 1)
		{
			printf("系统错误");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("系统错误");
		}
	}
	fclose(fp);
}
//保存排序信息
void writesortfile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("./sort.dat", "w")) == NULL)
	{
		printf("系统错误");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < cbNum; i++)
	{
		if (fwrite(&cBList[i], sizeof(CardBase), 1, fp) != 1)
		{
			printf("系统错误");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("系统错误");
		}
	}
	fclose(fp);
}
//保存用户信息
void writeyonghubasefile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("yonghu.txt", "w")) == NULL)
	{
		printf("系统错误");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < ccNum; i++)
	{
		if (fwrite(&ccBList[i], sizeof(Customer), 1, fp) != 1)
		{
			printf("系统错误");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("系统错误");
		}
	}
	fclose(fp);
}


/************************************************************************/
/* 闲杂信息                                                                     */
/************************************************************************/
enum xingbie
{
	Man,
	Woman
}Sex;
enum cang
{
	头等舱 = 1,
	经济舱,
	普通舱
};


/************************************************************************/
/*         输入输出函数                                                             */
/************************************************************************/

//输入信息
void setInfo(char pinfo[1024], char desinfo[])
{
	printf("\n\t%s:", pinfo);
	fflush(stdin);
	scanf("%s", desinfo);
}
//输入数字
void setInfo1(char pinfo[1024], int desinfo)
{
	printf("\n\t%s:", pinfo);
	fflush(stdin);
	scanf("%d", desinfo);
}

//打印并输入后返回
void printReturn(char *info)
{
	printf("\n\n\t %s", info);
	fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
	getchar();
}


//系统初始化
void initsystem()
{
	readcardbasefile();
	readyonghubasefile();
}

/************************************************************************/
/* 时间比较                                                             */
/************************************************************************/
//时间比较
//atime:规定时间
int timecmp(char A[10])
{
	//将飞机时间转成整数
	char tempa[10] = { 0 };
	int ta = 0;
	int i;
	for (i = 0; i < strlen(A); i++)
	if (A[i] != ':'&&A[i] != '：') //冒号的中文输入和英文输入
	{
		tempa[ta] = A[i];
		ta++;
	}
	int atime = atoi(tempa);//把字符串变成整型

	//获取系统时间
	char tempb[10] = { 0 };
	time_t t = time(0);
	strftime(tempb, 10, "%H%M", localtime(&t));
	int btime = atoi(tempb);
	//比较
	if (atime <= btime) //已经起飞
		return 1;
	if (((atime - btime <= 30) && (atime - btime > 5) && (atime / 100 == btime / 100)) || (((atime % 100 + (60 - btime % 100)) <= 30) && (atime % 100 + (60 - btime % 100)) > 5 && (atime / 100 - btime / 100 == 1))) //距起飞半小时以内,停止退票,%表示取余
		return 2;
	if (((atime - btime <= 5) && (atime / 100 == btime / 100)) || ((atime % 100 + (60 - btime % 100) && (atime / 100 - btime / 100 == 1)) <= 5)) //距起飞前五分钟内停止检票
		return 3;
	return 0; //可以办理购退票
}

/************************************************************************/
/* 用户功能                                                             */
/************************************************************************/


//用户注册
void infoinputyonghu()
{
	setInfo("身份证", ccBList[ccNum].ID);
	setInfo("姓名", ccBList[ccNum].Name);
	setInfo("性别(Man/Woman)", ccBList[ccNum].SEX);
	setInfo("舱位等级(头等舱/经济舱/普通舱)", ccBList[ccNum].LEVEl);
	setInfo("座位号", ccBList[ccNum].SEATNUM);
	setInfo("所定航班号", ccBList[ccNum].FLIGHTNUM);
	setInfo("工作地址", ccBList[ccNum].ADDRESS);
	setInfo("所定票数", ccBList[ccNum].BOOKNUM);
	setInfo("电话", ccBList[ccNum].TEL);

	ccNum++;
	writeyonghubasefile();
	printReturn("\n\t录入成功，回车键返回");
};

//浏览所有航班
void queryallinfo()
{
	printf("航班信息\n");
	printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t 状态\n");
	int i;
	for (i = 0; i < cbNum; i++)
	{
		char temp[20] = { 0 };
		strcpy(temp, "未起飞");
		if (1 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "已起飞");
		if (2 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "停止退票");
		if (3 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "停止检票");

		printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t %s\n",
			cBList[i].C_ID,

			cBList[i].C_TIMEYEAR,
			cBList[i].C_TIMEMOUTH,
			cBList[i].C_TIMEDAY,
			cBList[i].C_TIMEHOUR,
			cBList[i].C_TIMEMINUTE,

			cBList[i].C_ANAME,
			cBList[i].C_BNAME,

			cBList[i].C_USETIME,

			cBList[i].C_MAXNUM,
			cBList[i].C_REMAINNUM,
			temp
			);
	}
	printReturn("\n\t回车键返回");
};

//通过航班号查路线
void queryinfobyID()
{
	char ID[20] = { 0 };
	setInfo("输入航班号", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			printf("航班信息\n");
			printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
			printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t\n",
				cBList[i].C_ID,

				cBList[i].C_TIMEYEAR,
				cBList[i].C_TIMEMOUTH,
				cBList[i].C_TIMEDAY,
				cBList[i].C_TIMEHOUR,
				cBList[i].C_TIMEMINUTE,

				cBList[i].C_ANAME,
				cBList[i].C_BNAME,

				cBList[i].C_USETIME,

				cBList[i].C_MAXNUM,
				cBList[i].C_REMAINNUM
				);

			printReturn("\n\t回车键返回");
			return;
		}
	}
	printReturn("\n\t指定信息不存在，回车键返回");
};

//通过终点站查路线
void queryinfobyBNAME()
{
	char Name[20] = { 0 };
	setInfo("输入终点站", Name);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_BNAME, Name) == 0)
		{
			printf("航班信息\n");
			printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
			printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t \n",
				cBList[i].C_ID,

				cBList[i].C_TIMEYEAR,
				cBList[i].C_TIMEMOUTH,
				cBList[i].C_TIMEDAY,
				cBList[i].C_TIMEHOUR,
				cBList[i].C_TIMEMINUTE,

				cBList[i].C_ANAME,
				cBList[i].C_BNAME,

				cBList[i].C_USETIME,

				cBList[i].C_MAXNUM,
				cBList[i].C_REMAINNUM
				);

			printReturn("\n\t回车键返回");
			return;
		}
	}
	printReturn("\n\t指定信息不存在，回车键返回");
};

//售票
void sale()
{
	char ID[20] = { 0 };
	setInfo("输入航班号", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			if (cBList[i].C_REMAINNUM == 0)
			{
				printReturn("\n\t余票不足，回车返回");
				return;
			}
			//余票减少
			int temp = atoi(cBList[i].C_REMAINNUM) - 1;
			if (temp < 0) temp = 0;//确保余票不为负数
			_itoa(temp, cBList[i].C_REMAINNUM, 10);
			//保存到文件
			writecardbasefile();
			printf("航班信息\n");
			printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
			printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t \n",
				cBList[i].C_ID,

				cBList[i].C_TIMEYEAR,
				cBList[i].C_TIMEMOUTH,
				cBList[i].C_TIMEDAY,
				cBList[i].C_TIMEHOUR,
				cBList[i].C_TIMEMINUTE,

				cBList[i].C_ANAME,
				cBList[i].C_BNAME,

				cBList[i].C_USETIME,

				cBList[i].C_MAXNUM,
				cBList[i].C_REMAINNUM
				);


			printReturn("\n\t售票成功，回车返回");
			return;
		}
	}
	printReturn("\n\t指定航班不存在，回车键返回");
};
//退票
void back()
{
	char ID[20] = { 0 };
	setInfo("输入航班号", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			//余票增加
			int temp = atoi(cBList[i].C_REMAINNUM) + 1;
			_itoa(temp, cBList[i].C_REMAINNUM, 10);
			//保存到文件
			writecardbasefile();
			printf("航班信息\n");
			printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
			printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t \n",
				cBList[i].C_ID,

				cBList[i].C_TIMEYEAR,
				cBList[i].C_TIMEMOUTH,
				cBList[i].C_TIMEDAY,
				cBList[i].C_TIMEHOUR,
				cBList[i].C_TIMEMINUTE,

				cBList[i].C_ANAME,
				cBList[i].C_BNAME,

				cBList[i].C_USETIME,

				cBList[i].C_MAXNUM,
				cBList[i].C_REMAINNUM
				);

			printReturn("\n\t\t退票成功，回车返回");
			return;
		}
	}
	printReturn("\n\t指定航班不存在，回车键返回");
};


/************************************************************************/
/* 管理功能                                                             */
/************************************************************************/

//录入航班
void infoinput()
{
	setInfo("航班", cBList[cbNum].C_ID);
	setInfo("起飞年", cBList[cbNum].C_TIMEYEAR);
	setInfo("起飞月", cBList[cbNum].C_TIMEMOUTH);
	setInfo("起飞日", cBList[cbNum].C_TIMEDAY);
	setInfo("起飞时(24小时制)", cBList[cbNum].C_TIMEHOUR);
	setInfo("起飞分", cBList[cbNum].C_TIMEMINUTE);
	setInfo("票价", cBList[cbNum].C_PRICE);

	setInfo("起点站", cBList[cbNum].C_ANAME);
	setInfo("终点站", cBList[cbNum].C_BNAME);
	setInfo("飞行时间", cBList[cbNum].C_USETIME);
	setInfo("额定载量", cBList[cbNum].C_MAXNUM);
	setInfo("余票数量", cBList[cbNum].C_REMAINNUM);
	cbNum++;
	writecardbasefile();
	printReturn("\n\t录入成功，回车键返回");
};

//浏览所有用户
void liulan()
{
	printf("用户信息\n");
	printf("姓名\t性别\t身份证\t工作地址\t电话\t所定航班号\t舱位等级\t座位号\t所定票数\n");
	int i;
	for (i = 0; i < ccNum; i++)
	{
		printf("%s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n",
			ccBList[i].Name,
			ccBList[i].SEX,
			ccBList[i].ID,
			ccBList[i].ADDRESS,
			ccBList[i].TEL,
			ccBList[i].FLIGHTNUM,
			ccBList[i].LEVEl,
			ccBList[i].SEATNUM,
			ccBList[i].BOOKNUM
			);
	}
	printReturn("\n\t回车键返回");
};


//排序按余票数量排序保存
void sortSave()
{
	//冒泡排序
	int i, j;
	for (i = 0; i < cbNum; i++)
	for (j = 0; j < cbNum - i - 1; j++)
	{
		if (atoi(cBList[j].C_REMAINNUM) < atoi(cBList[j + 1].C_REMAINNUM))
		{
			CardBase temp = cBList[j];
			cBList[j] = cBList[j + 1];
			cBList[j + 1] = temp;
		}
	}
	//打印排序结果
	queryallinfo();
	//保存排序结果
	writesortfile();
};



//更新航班信息
void update()
{
	int flag;
	char ID[20] = { 0 };
	setInfo("请输入要删除或修改的航班（请确认航班输入正确）", ID);
	do
	{
		printf("\n\t按下列提示更新航班信息（退出修改请按0）:\n");
		printf(" *********************修改航班***********************\n");
		printf(" *     1、删除航班                 2、修改起飞时间  *\n");
		printf(" *     3、修改起点站               4、修改终点站    *\n");
		printf(" *     5、修改飞行时间             6、修改额定载量  *\n");
		printf(" *     7、修改余票数量             0、退出修改      *\n");
		printf(" ****************************************************\n");

		printf("\n\t请选择：");
		scanf("%d", &flag);
		int i;
		CardBase temp;
		for (i = 0; i < cbNum; i++)
		{
			if (strcmp(cBList[i].C_ID, ID) == 0)
			{
				if (flag == 1) //删除航班信息
				{
					int j;
					for (j = i; j < cbNum; j++)
						cBList[j] = cBList[j + 1];//后面的数据覆盖前面的数据
					cbNum--;//航班数减一
					//保存到文件
					writecardbasefile();
				}
				if (flag == 2) //修改起飞时间
				{
					setInfo("请输入新的起飞年", cBList[i].C_TIMEYEAR);
					setInfo("请输入新的起飞月", cBList[i].C_TIMEMOUTH);
					setInfo("请输入新的起飞日", cBList[i].C_TIMEDAY);
					setInfo("请输入新的起飞时", cBList[i].C_TIMEHOUR);
					setInfo("请输入新的起飞分", cBList[i].C_TIMEMINUTE);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
				if (flag == 3) //修改起点站
				{
					setInfo("请输入新的起点站", cBList[i].C_ANAME);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
				if (flag == 4) //修改终点站
				{
					setInfo("请输入新的终点站", cBList[i].C_BNAME);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
				if (flag == 5) //修改飞行时间
				{
					setInfo("请输入新的飞行时间", cBList[i].C_USETIME);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
				if (flag == 6) //修改额定载量
				{
					setInfo("请输入新的额定载量", cBList[i].C_MAXNUM);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
				if (flag == 7) //修改余票数量
				{
					setInfo("请输入新的余票数量", cBList[i].C_REMAINNUM);
					temp = cBList[i];
					//保存到文件
					writecardbasefile();
				}
			}
		}
		//更改完成后显示更新后的航班信息,如果是删除航班则不显示,即flag不等于0的时候显示更新信息
		if (flag != 1 && flag != 0)
		{
			printf("更新后的航班信息\n");
			for (i = 0; i < cbNum; i++)
			{
				if (strcmp(cBList[i].C_ID, ID) == 0)
				{
					printf("航班信息\n");
					printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
					printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t\n",
						cBList[i].C_ID,

						cBList[i].C_TIMEYEAR,
						cBList[i].C_TIMEMOUTH,
						cBList[i].C_TIMEDAY,
						cBList[i].C_TIMEHOUR,
						cBList[i].C_TIMEMINUTE,

						cBList[i].C_ANAME,
						cBList[i].C_BNAME,

						cBList[i].C_USETIME,

						cBList[i].C_MAXNUM,
						cBList[i].C_REMAINNUM
						);

					printReturn("\n\t回车键返回");
					return;
				}
			}
		}
	} while (flag);
	printReturn("\n\t完成航班信息更新，回车键返回");
};


/************************************************************************/
/* 菜单函数                                                             */
/************************************************************************/


void zhumenu();
void feijimenu();
void yonghumenu();
void caozuo();
void denglu();
void denglumenu();


void denglu()
{
	char ID[20] = { 0 };
	char yonghuID[20] = { 0 };

	setInfo("\n输入身份证", yonghuID);

	for (int j = 0; j < ccNum; j++)
	{
		if (strcmp(ccBList[j].ID, yonghuID) == 0)
		{
			//printf("登陆成功");
			printReturn("\n\t登陆成功，回车返回");

			break;
		}
		else
		{
			printf("输入错误请重新输入！");
			denglu();
		}
	}

	denglumenu();

}

//用户登陆
void denglumenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//清屏
			printf("\n\t 飞机航班系统 ");
			printf("\n\t ────────────────");
			printf("\n\t 1.购票 ");
			printf("\n\t 2.退票 ");
			printf("\n\t 0.退出系统 ");
			printf("\n\t ────────────────");
			printf("\n\t 请选择：");
			fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
			select = getchar();//等待用户输入数据
		} while (select<'0' || select>'2');
		switch (select)
		{
		case '0':
			exit(0); break;
		case '1':
			sale();
			break;
		case '2':
			back(); break;
		}
	}
}




void zhumenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//清屏
			printf("\n\t 飞机航班系统 ");
			printf("\n\t ────────────────");
			printf("\n\t 1.用户入口 ");
			printf("\n\t 2.管理员入口 ");
			printf("\n\t 0.退出登录 ");
			printf("\n\t ────────────────");
			printf("\n\t 请选择：");
			fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
			select = getchar();//等待用户输入数据
		} while (select<'0' || select>'2');
		switch (select)
		{
		case '0':exit(0); break;
		case '1':yonghumenu(); break;
		case '2':feijimenu(); break;
		}
	}
}
void yonghumenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//清屏
			printf("\n\t 飞机航班系统（用户） ");
			printf("\n\t ────────────────");
			printf("\n\t 1.用户操作 ");
			printf("\n\t 2.浏览所有航班 ");
			printf("\n\t 3.通过航班号查路线 ");
			printf("\n\t 4.通过终点站查路线 ");
			//printf("\n\t 5.买票 ");
			//printf("\n\t 6.退票 ");
			printf("\n\t 0.返回上一层 ");
			printf("\n\t ────────────────");
			printf("\n\t 请选择：");
			fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
			select = getchar();//等待用户输入数据
		} while (select<'0' || select>'4');
		switch (select)
		{
		case '0':zhumenu(); break;
		case '1':caozuo(); break;
		case '2':queryallinfo(); break;
		case '3':queryinfobyID(); break;
		case '4':queryinfobyBNAME(); break;
			//case '5':sale(); break;
			//case '6':back(); break;
		}
	}
}

//用户操作
void caozuo()
{
	while (1)
	{
		char select;
		do{
			system("cls");//清屏
			printf("\n\t 飞机航班系统（用户操作） ");
			printf("\n\t ────────────────");
			printf("\n\t 1.用户信息注册 ");
			printf("\n\t 2.用户登陆 ");
			printf("\n\t 0.返回上一层 ");
			printf("\n\t ────────────────");
			printf("\n\t 请选择：");
			fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
			select = getchar();//等待用户输入数据
		} while (select<'0' || select>'2');
		switch (select)
		{
		case '0':
			yonghumenu(); break;
		case '1':
			infoinputyonghu();
			break;
		case '2':
			denglu(); break;
		}
	}
}







////购票
//void goupiao()
//{
//	int i;
//	char ID[20] = { 0 };
//	printf("每人仅限购买一张！！！")
//		setInfo("输入航班号", ID);
//	for (i = 0; i < cbNum; i++)
//	{
//		if (strcmp(cBList[i].C_ID, ID) == 0)
//		{
//			if (cBList[i].C_REMAINNUM == 0)
//			{
//				printReturn("\n\t余票不足，回车返回");
//				return;
//			}
//			//余票减少
//			int temp = atoi(cBList[i].C_REMAINNUM) - 1;
//			if (temp < 0) temp = 0;//确保余票不为负数
//			_itoa(temp, cBList[i].C_REMAINNUM, 10);
//			//保存到文件
//			writecardbasefile();
//			printf("航班信息\n");
//			printf("航班\t 年-月-日-时-分\t 起点站\t 终点站\t 飞行时长\t 额定载量\t 余票数量\t\n");
//			printf("%s\t %s-%s-%s-%s-%s\t %s\t %s\t %s\t %s\t %s\t \n",
//				cBList[i].C_ID,
//
//				cBList[i].C_TIMEYEAR,
//				cBList[i].C_TIMEMOUTH,
//				cBList[i].C_TIMEDAY,
//				cBList[i].C_TIMEHOUR,
//				cBList[i].C_TIMEMINUTE,
//
//				cBList[i].C_ANAME,
//				cBList[i].C_BNAME,
//
//				cBList[i].C_USETIME,
//
//				cBList[i].C_MAXNUM,
//				cBList[i].C_REMAINNUM
//				);
//
//
//			printReturn("\n\t买票成功，回车返回");
//			return;
//		}
//	}
//	printReturn("\n\t指定航班不存在，回车键返回");
//}





void feijimenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//清屏

			printf("\n\t 飞机航班系统（管理员） ");
			printf("\n\t ────────────────");
			printf("\n\t 1.录入航班 ");
			printf("\n\t 2.浏览所有航班 ");
			printf("\n\t 3.通过航班号查路线 ");
			printf("\n\t 4.通过终点站查路线 ");
			printf("\n\t 5.按余票数量排序保存 ");
			printf("\n\t 6.更新航班信息 ");
			printf("\n\t 7.浏览用户信息 ");
			printf("\n\t 0.返回上一层 ");
			printf("\n\t ────────────────");
			printf("\n\t 请选择：");
			fflush(stdin);//清空输入缓冲区，通常是为了确保不影响后面的数据读取.
			select = getchar();//等待用户输入数据
		} while (select<'0' || select>'7');
		switch (select)
		{
		case '0':zhumenu(); break;
		case '1':infoinput(); break;
		case '2':queryallinfo(); break;
		case '3':queryinfobyID(); break;
		case '4':queryinfobyBNAME(); break;
		case '5':sortSave(); break;
		case '6':update(); break;
		case '7':liulan(); break;
		}
	}
}



//主函数
int main()
{
	initsystem(); //系统初始化
	while (1)
	{
		zhumenu();
	}
}
