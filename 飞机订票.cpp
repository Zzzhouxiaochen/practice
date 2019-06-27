/************************************************************************/
/* ������Ϣ                                                             */
/************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include "time.h"


//������Ϣ��
#define SIZELIMIT 10 //ÿ����ľ�����Ϣ���ַ�����������10����
#define MAXNUM 1000 //�趨���ֻ��¼��1000��������Ϣ

/************************************************************************/

typedef struct cardbase //����һ�����ں�����Ϣ�Ľṹ�壬ȡ��ΪCardBase
{
	char C_ID[SIZELIMIT];//����

	char C_TIMEYEAR[SIZELIMIT];//�����
	char C_TIMEMOUTH[SIZELIMIT];//�����
	char C_TIMEDAY[SIZELIMIT];//�����
	char C_TIMEHOUR[SIZELIMIT];//���ʱ
	char C_TIMEMINUTE[SIZELIMIT];//��ɷ�
	char C_PRICE[SIZELIMIT];//Ʊ��

	char C_ANAME[SIZELIMIT];//���վ
	char C_BNAME[SIZELIMIT];//�յ�վ
	char C_USETIME[SIZELIMIT];//����ʱ��
	char C_MAXNUM[MAXNUM];//�����
	char C_REMAINNUM[MAXNUM];//��Ʊ����

}CardBase;
int cbNum = 0;//��¼������
CardBase cBList[MAXNUM];//�����б�



typedef struct Customer   //�˿���Ϣ
{

	char Name[SIZELIMIT];   //����
	char ID[MAXNUM];	//���֤
	char LEVEl[SIZELIMIT];   //��λ�ȼ�
	char SEATNUM[SIZELIMIT];   //��λ��
	char FLIGHTNUM[SIZELIMIT];   //���������

	char ADDRESS[MAXNUM];//������ַ
	char BOOKNUM[SIZELIMIT];//����Ʊ��
	char SEX[SIZELIMIT];//�Ա�
	char TEL[MAXNUM];//�绰

}Customer;
int ccNum = 0;//��¼�˿���
Customer ccBList[MAXNUM];//�˿��б�


/************************************************************************/
/*               ��Ϣ��ȡ                                                       */
/************************************************************************/



//��ȡ������Ϣ
void readcardbasefile()
{
	FILE *fp;
	//���ļ�ʧ���򴴽��ļ�
	if ((fp = fopen("./number.dat", "r")) == NULL)
	{
		//�������д����ļ�
		if ((fp = fopen("./number.dat", "w")) == NULL)
		{
			exit(0); //����
		}
		else
		{
			fclose(fp);
		}
		return;
	}
	/*�ļ�λ��ָ���ƶ����ļ�ĩβ*/
	fseek(fp, 0, SEEK_END);//�ض�λ�ļ��ڲ�λ��ָ��
	/* int fseek( FILE *stream, long offset, int origin );
	��һ������streamΪ�ļ�ָ��
	�ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��
	����������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET
	SEEK_SET�� �ļ���ͷ
	SEEK_CUR�� ��ǰλ��
	SEEK_END�� �ļ���β
	����SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
	����֮��
	fseek(fp,100L,0);��streamָ���ƶ������ļ���ͷ100�ֽڴ���
	fseek(fp,100L,1);��streamָ���ƶ������ļ���ǰλ��100�ֽڴ���
	fseek(fp,-100L,2);��streamָ���˻ص����ļ���β100�ֽڴ��� */
	if (ftell(fp) > 0)//�ļ���Ϊ��
		/*ftell�������ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
		Ҳ���ǵõ��ļ����������ֽ���,�������0��������ļ��ǿ�*/
	{
		//�ļ�λ��ָ���ƶ����ļ���ʼ
		rewind(fp);
		char buff[10] = { 0 };
		for (cbNum = 0; !feof(fp) && fread(&cBList[cbNum], sizeof(CardBase), 1, fp); cbNum++)
			/*����feof��������������ļ�����������feof��fp����ֵΪ����ֵ������Ϊ0��
			������ļ�������!feof(fp)Ϊ0������ѭ��
			����fread�������Ǵ�һ���ļ����ж����ݣ�������óɹ�����ʵ�ʶ�ȡ�����������
			������ɹ�������ļ�ĩβ���� 0*/
			fgets(buff, 10, fp);
		/*char *fgets(char *buf, int bufsize, FILE *stream);
		���ļ��ṹ��ָ��stream�ж�ȡ���ݣ�ÿ�ζ�ȡһ�С���ȡ�����ݱ�����bufָ����ַ������У�
		ÿ������ȡbufsize-1���ַ�����bufsize���ַ���'\0'��������ļ��еĸ��У�����bufsize���ַ���
		�������оͽ������������У��������һ�����з������ַ�������bufsize-1����fgetsֻ����һ�����������У�
		���ǣ�������������NULL�ַ���β����fgets����һ�ε��û���������С������ɹ�������buf��ʧ�ܻ�����ļ���β����NULL��
		������ǲ���ֱ��ͨ��fgets�ķ���ֵ���жϺ����Ƿ��ǳ������ֹ�ģ�Ӧ�ý���feof��������ferror�������жϡ�
		*/
		fclose(fp);
	}
	else
	{
		fclose(fp);
	}
	return;
}

// ��ȡ�û���Ϣ
void readyonghubasefile()
{
	FILE *fp;
	//���ļ�ʧ���򴴽��ļ�
	if ((fp = fopen("yonghu.txt", "r")) == NULL)
	{
		//�������д����ļ�
		if ((fp = fopen("yonghu.txt", "w")) == NULL)
		{
			exit(0); //����
		}
		else
		{
			fclose(fp);
		}
		return;
	}
	/*�ļ�λ��ָ���ƶ����ļ�ĩβ*/
	fseek(fp, 0, SEEK_END);//�ض�λ�ļ��ڲ�λ��ָ��
	/* int fseek( FILE *stream, long offset, int origin );
	��һ������streamΪ�ļ�ָ��
	�ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��
	����������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET
	SEEK_SET�� �ļ���ͷ
	SEEK_CUR�� ��ǰλ��
	SEEK_END�� �ļ���β
	����SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
	����֮��
	fseek(fp,100L,0);��streamָ���ƶ������ļ���ͷ100�ֽڴ���
	fseek(fp,100L,1);��streamָ���ƶ������ļ���ǰλ��100�ֽڴ���
	fseek(fp,-100L,2);��streamָ���˻ص����ļ���β100�ֽڴ��� */
	if (ftell(fp) > 0)//�ļ���Ϊ��
		/*ftell�������ڵõ��ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
		Ҳ���ǵõ��ļ����������ֽ���,�������0��������ļ��ǿ�*/
	{
		//�ļ�λ��ָ���ƶ����ļ���ʼ
		rewind(fp);
		char buff[10] = { 0 };
		for (ccNum = 0; !feof(fp) && fread(&ccBList[ccNum], sizeof(Customer), 1, fp); ccNum++)
			/*����feof��������������ļ�����������feof��fp����ֵΪ����ֵ������Ϊ0��
			������ļ�������!feof(fp)Ϊ0������ѭ��
			����fread�������Ǵ�һ���ļ����ж����ݣ�������óɹ�����ʵ�ʶ�ȡ�����������
			������ɹ�������ļ�ĩβ���� 0*/
			fgets(buff, 10, fp);
		/*char *fgets(char *buf, int bufsize, FILE *stream);
		���ļ��ṹ��ָ��stream�ж�ȡ���ݣ�ÿ�ζ�ȡһ�С���ȡ�����ݱ�����bufָ����ַ������У�
		ÿ������ȡbufsize-1���ַ�����bufsize���ַ���'\0'��������ļ��еĸ��У�����bufsize���ַ���
		�������оͽ������������У��������һ�����з������ַ�������bufsize-1����fgetsֻ����һ�����������У�
		���ǣ�������������NULL�ַ���β����fgets����һ�ε��û���������С������ɹ�������buf��ʧ�ܻ�����ļ���β����NULL��
		������ǲ���ֱ��ͨ��fgets�ķ���ֵ���жϺ����Ƿ��ǳ������ֹ�ģ�Ӧ�ý���feof��������ferror�������жϡ�
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
/* ������Ϣ                                                                     */
/************************************************************************/

//���溽����Ϣ
void writecardbasefile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("./number.dat", "w")) == NULL)
	{
		printf("ϵͳ����");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < cbNum; i++)
	{
		if (fwrite(&cBList[i], sizeof(CardBase), 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
	}
	fclose(fp);
}
//����������Ϣ
void writesortfile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("./sort.dat", "w")) == NULL)
	{
		printf("ϵͳ����");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < cbNum; i++)
	{
		if (fwrite(&cBList[i], sizeof(CardBase), 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
	}
	fclose(fp);
}
//�����û���Ϣ
void writeyonghubasefile()
{
	int i;
	FILE *fp;
	if ((fp = fopen("yonghu.txt", "w")) == NULL)
	{
		printf("ϵͳ����");
	}
	char buff[10] = { 0 };
	strcpy(buff, "\r\n");
	for (i = 0; i < ccNum; i++)
	{
		if (fwrite(&ccBList[i], sizeof(Customer), 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
		if (fwrite(buff, 2, 1, fp) != 1)
		{
			printf("ϵͳ����");
		}
	}
	fclose(fp);
}


/************************************************************************/
/* ������Ϣ                                                                     */
/************************************************************************/
enum xingbie
{
	Man,
	Woman
}Sex;
enum cang
{
	ͷ�Ȳ� = 1,
	���ò�,
	��ͨ��
};


/************************************************************************/
/*         �����������                                                             */
/************************************************************************/

//������Ϣ
void setInfo(char pinfo[1024], char desinfo[])
{
	printf("\n\t%s:", pinfo);
	fflush(stdin);
	scanf("%s", desinfo);
}
//��������
void setInfo1(char pinfo[1024], int desinfo)
{
	printf("\n\t%s:", pinfo);
	fflush(stdin);
	scanf("%d", desinfo);
}

//��ӡ������󷵻�
void printReturn(char *info)
{
	printf("\n\n\t %s", info);
	fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
	getchar();
}


//ϵͳ��ʼ��
void initsystem()
{
	readcardbasefile();
	readyonghubasefile();
}

/************************************************************************/
/* ʱ��Ƚ�                                                             */
/************************************************************************/
//ʱ��Ƚ�
//atime:�涨ʱ��
int timecmp(char A[10])
{
	//���ɻ�ʱ��ת������
	char tempa[10] = { 0 };
	int ta = 0;
	int i;
	for (i = 0; i < strlen(A); i++)
	if (A[i] != ':'&&A[i] != '��') //ð�ŵ����������Ӣ������
	{
		tempa[ta] = A[i];
		ta++;
	}
	int atime = atoi(tempa);//���ַ����������

	//��ȡϵͳʱ��
	char tempb[10] = { 0 };
	time_t t = time(0);
	strftime(tempb, 10, "%H%M", localtime(&t));
	int btime = atoi(tempb);
	//�Ƚ�
	if (atime <= btime) //�Ѿ����
		return 1;
	if (((atime - btime <= 30) && (atime - btime > 5) && (atime / 100 == btime / 100)) || (((atime % 100 + (60 - btime % 100)) <= 30) && (atime % 100 + (60 - btime % 100)) > 5 && (atime / 100 - btime / 100 == 1))) //����ɰ�Сʱ����,ֹͣ��Ʊ,%��ʾȡ��
		return 2;
	if (((atime - btime <= 5) && (atime / 100 == btime / 100)) || ((atime % 100 + (60 - btime % 100) && (atime / 100 - btime / 100 == 1)) <= 5)) //�����ǰ�������ֹͣ��Ʊ
		return 3;
	return 0; //���԰�����Ʊ
}

/************************************************************************/
/* �û�����                                                             */
/************************************************************************/


//�û�ע��
void infoinputyonghu()
{
	setInfo("���֤", ccBList[ccNum].ID);
	setInfo("����", ccBList[ccNum].Name);
	setInfo("�Ա�(Man/Woman)", ccBList[ccNum].SEX);
	setInfo("��λ�ȼ�(ͷ�Ȳ�/���ò�/��ͨ��)", ccBList[ccNum].LEVEl);
	setInfo("��λ��", ccBList[ccNum].SEATNUM);
	setInfo("���������", ccBList[ccNum].FLIGHTNUM);
	setInfo("������ַ", ccBList[ccNum].ADDRESS);
	setInfo("����Ʊ��", ccBList[ccNum].BOOKNUM);
	setInfo("�绰", ccBList[ccNum].TEL);

	ccNum++;
	writeyonghubasefile();
	printReturn("\n\t¼��ɹ����س�������");
};

//������к���
void queryallinfo()
{
	printf("������Ϣ\n");
	printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t ״̬\n");
	int i;
	for (i = 0; i < cbNum; i++)
	{
		char temp[20] = { 0 };
		strcpy(temp, "δ���");
		if (1 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "�����");
		if (2 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "ֹͣ��Ʊ");
		if (3 == timecmp(cBList[i].C_TIMEHOUR))
			strcpy(temp, "ֹͣ��Ʊ");

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
	printReturn("\n\t�س�������");
};

//ͨ������Ų�·��
void queryinfobyID()
{
	char ID[20] = { 0 };
	setInfo("���뺽���", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			printf("������Ϣ\n");
			printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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

			printReturn("\n\t�س�������");
			return;
		}
	}
	printReturn("\n\tָ����Ϣ�����ڣ��س�������");
};

//ͨ���յ�վ��·��
void queryinfobyBNAME()
{
	char Name[20] = { 0 };
	setInfo("�����յ�վ", Name);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_BNAME, Name) == 0)
		{
			printf("������Ϣ\n");
			printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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

			printReturn("\n\t�س�������");
			return;
		}
	}
	printReturn("\n\tָ����Ϣ�����ڣ��س�������");
};

//��Ʊ
void sale()
{
	char ID[20] = { 0 };
	setInfo("���뺽���", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			if (cBList[i].C_REMAINNUM == 0)
			{
				printReturn("\n\t��Ʊ���㣬�س�����");
				return;
			}
			//��Ʊ����
			int temp = atoi(cBList[i].C_REMAINNUM) - 1;
			if (temp < 0) temp = 0;//ȷ����Ʊ��Ϊ����
			_itoa(temp, cBList[i].C_REMAINNUM, 10);
			//���浽�ļ�
			writecardbasefile();
			printf("������Ϣ\n");
			printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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


			printReturn("\n\t��Ʊ�ɹ����س�����");
			return;
		}
	}
	printReturn("\n\tָ�����಻���ڣ��س�������");
};
//��Ʊ
void back()
{
	char ID[20] = { 0 };
	setInfo("���뺽���", ID);
	int i;
	for (i = 0; i < cbNum; i++)
	{
		if (strcmp(cBList[i].C_ID, ID) == 0)
		{
			//��Ʊ����
			int temp = atoi(cBList[i].C_REMAINNUM) + 1;
			_itoa(temp, cBList[i].C_REMAINNUM, 10);
			//���浽�ļ�
			writecardbasefile();
			printf("������Ϣ\n");
			printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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

			printReturn("\n\t\t��Ʊ�ɹ����س�����");
			return;
		}
	}
	printReturn("\n\tָ�����಻���ڣ��س�������");
};


/************************************************************************/
/* ������                                                             */
/************************************************************************/

//¼�뺽��
void infoinput()
{
	setInfo("����", cBList[cbNum].C_ID);
	setInfo("�����", cBList[cbNum].C_TIMEYEAR);
	setInfo("�����", cBList[cbNum].C_TIMEMOUTH);
	setInfo("�����", cBList[cbNum].C_TIMEDAY);
	setInfo("���ʱ(24Сʱ��)", cBList[cbNum].C_TIMEHOUR);
	setInfo("��ɷ�", cBList[cbNum].C_TIMEMINUTE);
	setInfo("Ʊ��", cBList[cbNum].C_PRICE);

	setInfo("���վ", cBList[cbNum].C_ANAME);
	setInfo("�յ�վ", cBList[cbNum].C_BNAME);
	setInfo("����ʱ��", cBList[cbNum].C_USETIME);
	setInfo("�����", cBList[cbNum].C_MAXNUM);
	setInfo("��Ʊ����", cBList[cbNum].C_REMAINNUM);
	cbNum++;
	writecardbasefile();
	printReturn("\n\t¼��ɹ����س�������");
};

//��������û�
void liulan()
{
	printf("�û���Ϣ\n");
	printf("����\t�Ա�\t���֤\t������ַ\t�绰\t���������\t��λ�ȼ�\t��λ��\t����Ʊ��\n");
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
	printReturn("\n\t�س�������");
};


//������Ʊ�������򱣴�
void sortSave()
{
	//ð������
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
	//��ӡ������
	queryallinfo();
	//����������
	writesortfile();
};



//���º�����Ϣ
void update()
{
	int flag;
	char ID[20] = { 0 };
	setInfo("������Ҫɾ�����޸ĵĺ��ࣨ��ȷ�Ϻ���������ȷ��", ID);
	do
	{
		printf("\n\t��������ʾ���º�����Ϣ���˳��޸��밴0��:\n");
		printf(" *********************�޸ĺ���***********************\n");
		printf(" *     1��ɾ������                 2���޸����ʱ��  *\n");
		printf(" *     3���޸����վ               4���޸��յ�վ    *\n");
		printf(" *     5���޸ķ���ʱ��             6���޸Ķ����  *\n");
		printf(" *     7���޸���Ʊ����             0���˳��޸�      *\n");
		printf(" ****************************************************\n");

		printf("\n\t��ѡ��");
		scanf("%d", &flag);
		int i;
		CardBase temp;
		for (i = 0; i < cbNum; i++)
		{
			if (strcmp(cBList[i].C_ID, ID) == 0)
			{
				if (flag == 1) //ɾ��������Ϣ
				{
					int j;
					for (j = i; j < cbNum; j++)
						cBList[j] = cBList[j + 1];//��������ݸ���ǰ�������
					cbNum--;//��������һ
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 2) //�޸����ʱ��
				{
					setInfo("�������µ������", cBList[i].C_TIMEYEAR);
					setInfo("�������µ������", cBList[i].C_TIMEMOUTH);
					setInfo("�������µ������", cBList[i].C_TIMEDAY);
					setInfo("�������µ����ʱ", cBList[i].C_TIMEHOUR);
					setInfo("�������µ���ɷ�", cBList[i].C_TIMEMINUTE);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 3) //�޸����վ
				{
					setInfo("�������µ����վ", cBList[i].C_ANAME);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 4) //�޸��յ�վ
				{
					setInfo("�������µ��յ�վ", cBList[i].C_BNAME);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 5) //�޸ķ���ʱ��
				{
					setInfo("�������µķ���ʱ��", cBList[i].C_USETIME);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 6) //�޸Ķ����
				{
					setInfo("�������µĶ����", cBList[i].C_MAXNUM);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
				if (flag == 7) //�޸���Ʊ����
				{
					setInfo("�������µ���Ʊ����", cBList[i].C_REMAINNUM);
					temp = cBList[i];
					//���浽�ļ�
					writecardbasefile();
				}
			}
		}
		//������ɺ���ʾ���º�ĺ�����Ϣ,�����ɾ����������ʾ,��flag������0��ʱ����ʾ������Ϣ
		if (flag != 1 && flag != 0)
		{
			printf("���º�ĺ�����Ϣ\n");
			for (i = 0; i < cbNum; i++)
			{
				if (strcmp(cBList[i].C_ID, ID) == 0)
				{
					printf("������Ϣ\n");
					printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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

					printReturn("\n\t�س�������");
					return;
				}
			}
		}
	} while (flag);
	printReturn("\n\t��ɺ�����Ϣ���£��س�������");
};


/************************************************************************/
/* �˵�����                                                             */
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

	setInfo("\n�������֤", yonghuID);

	for (int j = 0; j < ccNum; j++)
	{
		if (strcmp(ccBList[j].ID, yonghuID) == 0)
		{
			//printf("��½�ɹ�");
			printReturn("\n\t��½�ɹ����س�����");

			break;
		}
		else
		{
			printf("����������������룡");
			denglu();
		}
	}

	denglumenu();

}

//�û���½
void denglumenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//����
			printf("\n\t �ɻ�����ϵͳ ");
			printf("\n\t ��������������������������������");
			printf("\n\t 1.��Ʊ ");
			printf("\n\t 2.��Ʊ ");
			printf("\n\t 0.�˳�ϵͳ ");
			printf("\n\t ��������������������������������");
			printf("\n\t ��ѡ��");
			fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
			select = getchar();//�ȴ��û���������
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
			system("cls");//����
			printf("\n\t �ɻ�����ϵͳ ");
			printf("\n\t ��������������������������������");
			printf("\n\t 1.�û���� ");
			printf("\n\t 2.����Ա��� ");
			printf("\n\t 0.�˳���¼ ");
			printf("\n\t ��������������������������������");
			printf("\n\t ��ѡ��");
			fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
			select = getchar();//�ȴ��û���������
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
			system("cls");//����
			printf("\n\t �ɻ�����ϵͳ���û��� ");
			printf("\n\t ��������������������������������");
			printf("\n\t 1.�û����� ");
			printf("\n\t 2.������к��� ");
			printf("\n\t 3.ͨ������Ų�·�� ");
			printf("\n\t 4.ͨ���յ�վ��·�� ");
			//printf("\n\t 5.��Ʊ ");
			//printf("\n\t 6.��Ʊ ");
			printf("\n\t 0.������һ�� ");
			printf("\n\t ��������������������������������");
			printf("\n\t ��ѡ��");
			fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
			select = getchar();//�ȴ��û���������
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

//�û�����
void caozuo()
{
	while (1)
	{
		char select;
		do{
			system("cls");//����
			printf("\n\t �ɻ�����ϵͳ���û������� ");
			printf("\n\t ��������������������������������");
			printf("\n\t 1.�û���Ϣע�� ");
			printf("\n\t 2.�û���½ ");
			printf("\n\t 0.������һ�� ");
			printf("\n\t ��������������������������������");
			printf("\n\t ��ѡ��");
			fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
			select = getchar();//�ȴ��û���������
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







////��Ʊ
//void goupiao()
//{
//	int i;
//	char ID[20] = { 0 };
//	printf("ÿ�˽��޹���һ�ţ�����")
//		setInfo("���뺽���", ID);
//	for (i = 0; i < cbNum; i++)
//	{
//		if (strcmp(cBList[i].C_ID, ID) == 0)
//		{
//			if (cBList[i].C_REMAINNUM == 0)
//			{
//				printReturn("\n\t��Ʊ���㣬�س�����");
//				return;
//			}
//			//��Ʊ����
//			int temp = atoi(cBList[i].C_REMAINNUM) - 1;
//			if (temp < 0) temp = 0;//ȷ����Ʊ��Ϊ����
//			_itoa(temp, cBList[i].C_REMAINNUM, 10);
//			//���浽�ļ�
//			writecardbasefile();
//			printf("������Ϣ\n");
//			printf("����\t ��-��-��-ʱ-��\t ���վ\t �յ�վ\t ����ʱ��\t �����\t ��Ʊ����\t\n");
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
//			printReturn("\n\t��Ʊ�ɹ����س�����");
//			return;
//		}
//	}
//	printReturn("\n\tָ�����಻���ڣ��س�������");
//}





void feijimenu()
{
	while (1)
	{
		char select;
		do{
			system("cls");//����

			printf("\n\t �ɻ�����ϵͳ������Ա�� ");
			printf("\n\t ��������������������������������");
			printf("\n\t 1.¼�뺽�� ");
			printf("\n\t 2.������к��� ");
			printf("\n\t 3.ͨ������Ų�·�� ");
			printf("\n\t 4.ͨ���յ�վ��·�� ");
			printf("\n\t 5.����Ʊ�������򱣴� ");
			printf("\n\t 6.���º�����Ϣ ");
			printf("\n\t 7.����û���Ϣ ");
			printf("\n\t 0.������һ�� ");
			printf("\n\t ��������������������������������");
			printf("\n\t ��ѡ��");
			fflush(stdin);//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ.
			select = getchar();//�ȴ��û���������
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



//������
int main()
{
	initsystem(); //ϵͳ��ʼ��
	while (1)
	{
		zhumenu();
	}
}
