#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
using namespace std;
#define NUMFL 5
#define NUMTCH 5
#define TCHID 6
#define TOTAL_LIST 1

char residInfo[20] = "resident Info.txt";
char fl1[20] = "flour-1.txt";
char fl2[20] = "flour-2.txt";
char fl3[20] = "flour-3.txt";
char fl4[20] = "flour-4.txt";
char fl5[20] = "flour-5.txt";
char tchrs[20] = "Teachers.txt";


class teachers
{
public:
	char name[20];
	char fname[20];
	char pater[20];
	char passportInfo[20];

	teachers(){};
	teachers(char name[20], char fname[20], char pater[20], char passport[20]){
		for (int i = 0; i < strlen(name); i++)
		{
			this->name[i] = name[i];
		}
		for (int i = 0; i < strlen(fname); i++)
		{
			this->fname[i] = fname[i];
		}
		for (int i = 0; i < strlen(pater); i++)
		{
			this->pater[i] = pater[i];
		}
		for (int i = 0; i < strlen(passport); i++)
		{
			this->passportInfo[i] = passport[i];
		}
		this->name[strlen(name)] = '\0';
		this->fname[strlen(fname)] = '\0';
		this->pater[strlen(pater)] = '\0';
		this->passportInfo[strlen(passport)] = '\0';
	}
} teachList[NUMTCH];

class residence
{
public:
	char name[20];
	char fname[20];
	char patername[20];
	char dateStart[20];
	char dateFinish[20];
	bool isMale;
	int room;
	bool isPayed;
	residence(){};
	residence(char name[20], char fname[20], char patername[20], char dateStart[20], char dateFinish[20], bool isMale, int Room, bool isPayed){
		for (int i = 0; i < strlen(name); i++)
		{
			this->name[i] = name[i];
		}
		for (int i = 0; i < strlen(fname); i++)
		{
			this->fname[i] = fname[i];
		}
		for (int i = 0; i < strlen(patername); i++)
		{
			this->patername[i] = patername[i];
		}
		for (int i = 0; i < strlen(dateStart); i++)
		{
			this->dateStart[i] = dateStart[i];
		}
		for (int i = 0; i < strlen(dateFinish); i++)
		{
			this->dateFinish[i] = dateFinish[i];
		}
		this->name[strlen(name)] = '\0';
		this->fname[strlen(fname)] = '\0';
		this->patername[strlen(patername)] = '\0';
		this->dateStart[strlen(dateStart)] = '\0';
		this->dateFinish[strlen(dateFinish)] = '\0';
		this->isMale = isMale;
		this->room = Room;
		this->isPayed = isPayed;
	}
};

class Information
{

public:
	int FlourNumber;
	teachers kurator;
	residence data;

	Information(){};
	Information(int number, teachers kurator, residence obj){
		this->FlourNumber = number;
		this->kurator = kurator;
		data = obj;
	};
}Data[50];

class Payment
{
public:
	char period[20];
	float price;
	Payment(char period[20], float price){
		this->price = price;

		for (int i = 0; i < strlen(period); i++)
		{
			this->period[i] = period[i];
		}
		this->period[strlen(period)] = '\0';
	};

	Payment(){};
}infoList[10];

int menu();
void add_resident();
void add_paymentInfo();
void add_tchr();
void viewFile(char* file, int ind);
void viewFlour();
void writedata(char* file, int ind);
void getdata();
int num_rows;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("mode con cols=120 lines=30");//��������� ���� �������, ����� ����������� �������

	while (1)
		switch (menu())
	{
		case 1: add_resident(); break;
		case 2: add_paymentInfo(); break;
		case 3: add_tchr(); break;
		case 4: viewFile(residInfo, TOTAL_LIST); break;
		case 5: viewFlour(); break;
		case 6: viewFile(tchrs, TCHID); break;
		case 7: return 0;
		default:printf("�������� �����\n");
	}
	_getch();
}

int menu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	do
	{
		system("cls");//������� ���������� ������
		printf("-------------------------����-------------------------\n");
		printf("1. �������� ��������\n");
		printf("2. ��������� ������ �� ������\n");
		printf("3. ��������� ������ � ������������ \n");
		printf("4. ������ ������ �����������\n");
		printf("5. ������ ����������� �� ������\n");
		printf("6. ������ � ������������\n");
		printf("7. �����\n");
		printf("-------------------------------------------------------\n");
		printf("��� �����: ");
		scanf("%d", &choice);//���� ��������, ������� ����� ����������
		system("cls");
	} while (choice > 7);

	return choice;
}

void add_resident()
{
	int YesOrNot = 1;

	system("cls");
	printf("��������� ������ ���������\n");
	printf("---------------------------------------------------\n");
	int numFlour = 0;

	printf("���� (�� 1 �� 5): ");
	scanf("%d", &numFlour);

	char* filename = "";
	switch (numFlour)
	{
	case 1: {
				filename = "flour-1.txt";
				break;
	}
	case 2: {
				filename = "flour-2.txt";
				break;
	}
	case 3: {
				filename = "flour-3.txt";
				break;
	}
	case 4: {
				filename = "flour-4.txt";
				break;
	}
	case 5: {
				filename = "flour-5.txt";
				break;
	}
	default:
		break;
	}
	FILE* f = fopen(filename, "at");

	while (YesOrNot != 2)
	{
		system("cls");
		char name[20];
		char fname[20];
		char patername[20];
		char dateStart[20];
		char dateFinish[20];
		int numRoom;
		bool isMale;
		bool isPayed;

		printf("���: ");
		scanf("%s", name);
		fprintf(f, "%s\n", name);

		printf("�������: ");
		scanf("%s", fname);
		fprintf(f, "%s\n", fname);

		printf("��������: ");
		scanf("%s", patername);
		fprintf(f, "%s\n", patername);

		printf("���: \n");
		printf("---------\n");
		printf("1. �������\n");
		printf("2. �������\n");
		printf("---------\n");
		printf("�����: ");
		int ans;
		scanf("%d", &ans);
		switch (ans)
		{
		case 1:{
				   isMale = true;
				   fprintf(f, "�������\n");
				   break;
		}
		case 2:{
				   isMale = false;
				   fprintf(f, "�������\n");
				   break;
		}
		default:
			break;
		}
		printf("����� �������: ");
		scanf("%d", &numRoom);
		fprintf(f, "%d\n", numRoom);

		printf("���� ���������: ");
		scanf("%s", dateStart);
		fprintf(f, "%s\n", dateStart);

		printf("���� ���������: ");
		scanf("%s", dateFinish);
		fprintf(f, "%s\n", dateFinish);

		isPayed = false;
		fprintf(f, "�� ��������");
		residence infoResid = *new residence(name, fname, patername, dateStart, dateFinish, isMale, numRoom, isPayed);
		teachers emptyTeacher = *new teachers();
		Information newInfo = *new Information(numFlour, emptyTeacher, infoResid);
		Data[num_rows] = newInfo;
		num_rows++;
		do
		{
			printf("\n-------------------------\n");
			printf("���������� ���� ������? \n");
			printf("-------------------------\n");
			printf("1. ��\n");
			printf("2. ���\n");
			printf("-------------------------\n");
			printf("��� �����: ");
			scanf("%d", &YesOrNot);
		} while (YesOrNot>2);

	}
	fclose(f);
	writedata(residInfo, TOTAL_LIST);
	printf("������� Enter ��� �����������");
	_getch();
}

void add_paymentInfo()  //���������� ��������� ������� �������� �����������
{
	system("cls");
	printf("��������� ������ �� ������:\n");
	printf("---------------------------------------------------\n");
	int num_rows = 0;
	int ans_info = 1;
	Payment PayInfo;
	while (ans_info == 1)
	{
		char period[30];
		float price = 0.0;
		printf("\n");
		printf("������: ");
		scanf("%s", period);
		printf("����: ");
		scanf("%f", &price);

		PayInfo = *new Payment(period, price);
		infoList[num_rows] = PayInfo;
		num_rows++;
		do
		{
			printf("-------------------------------------------------------------------\n");
			printf("�������� ��� ������?\n");
			printf("-------------------------------------------------------------------\n");
			printf("1. ��\n");
			printf("2. ���\n");
			printf("-------------------------------------------------------------------\n");
			printf("�����: ");
			scanf("%d", &ans_info);
		} while (ans_info > 2);

	}

	FILE * f;
	f = fopen("payment Info.txt", "at");
	for (int i = 0; i < num_rows; i++)
	{
		fprintf(f, "%15s %5.2f\n", infoList[i].period, infoList[i].price);
	}
	fclose(f);
}

void add_tchr()
{
	int ans = 1;
	while (ans == 1 && num_rows <= NUMTCH)
	{
		system("cls");
		char name[20];
		char fname[20];
		char pater[20];
		char passportInfo[20];

		printf("��������� ������ � �����������\n");
		printf("---------------------------------------------------\n");
		printf("�������: ");
		scanf("%s", fname);
		printf("���: ");
		scanf("%s", name);
		printf("��������: ");
		scanf("%s", pater);
		printf("����� � ����� ��������: ");
		scanf("%s", passportInfo);

		teachers newTeacher = *new teachers(name, fname, pater, passportInfo);
		teachList[num_rows] = newTeacher;
		num_rows++;
		do
		{
			printf("\n-------------------------\n");
			printf("���������� ���� ������: \n");
			printf("-------------------------\n");
			printf("1. ��\n");
			printf("2. ���\n");
			printf("-------------------------\n");
			printf("��� �����: ");
			scanf("%d", &ans);
		} while (ans>2);
	}
	writedata(tchrs, TCHID);
}

void writedata(char* file, int ind)
{
	FILE *f;

	f = fopen(file, "at");//���� ������ ���  ������ � ����� �����

	if (f == NULL)
	{
		printf("���� ����� ������ ���������� ��� �� ����������\n");//���������, ���������� �� ����, ���� ���-�������� ���������
		return;
	}

	else if (ind == TOTAL_LIST)
	{
		for (int j = 0; j < num_rows; j++)
		{
			char* gender;
			if (Data[j].data.isMale){
				gender = "�������";
			}
			else{
				gender = "�������";
			}
			char* payed;
			if (Data[j].data.isPayed)
			{
				payed = "��������";
			}
			else{
				payed = "����������";
			}
			fprintf(f, "%d\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n", Data[j].FlourNumber,
				Data[j].data.name,
				Data[j].data.fname,
				Data[j].data.patername,
				gender,
				Data[j].data.room,
				Data[j].data.dateStart,
				Data[j].data.dateFinish,
				payed);
		}
		fclose(f);//��������� ����
	}

	else if (ind == TCHID)
	{
		for (int i = 0; i < num_rows; i++)
		{
			fprintf(f, "%s %s %s %s", teachList[i].fname, teachList[i].name, teachList[i].pater, teachList[i].passportInfo);
		}
		fclose(f);
	}
}

void viewFile(char* file_name, int ind)
{
	FILE *f;
	f = fopen(file_name, "r");//��� ������ ������ ��� ������
	if (f == NULL)
	{
		printf("���� ����� ������ ���������� ��� �� ����������\n��� ����������� ������� Enter");//���������, ���������� �� ����, ���� ���-�������� ���������
		_getch();
		return;
	}
	else
	{
		if (ind == TOTAL_LIST)
		{
			printf("����        !!���      !!�������   !!��������     !!���         !!������� !!���������  !!���������  !! ������ !!\n");
			printf("----------------------------------------------------------------------------------------------------------------\n");

			char str[50];
			int num_wd = 1;
			while (fgets(str, sizeof(str), f) != NULL)
			{
				str[strlen(str) - 1] = ' ';
				printf("%12s", str);
				if (num_wd % 9 == 0 && num_wd != 0)
					printf("\n");
				num_wd++;
			}
			fclose(f);
		}

		else if (ind == TCHID)
		{
			printf("�������    !!���     !!�������     !!�������\n");
			printf("--------------------------------------------------------------------------\n");

			char str[50];
			int num_wd = 1;
			while (fgets(str, sizeof(str), f) != NULL)
			{
				printf("%12s", str);
			}
			fclose(f);
		}
	}
	printf("\n������� Enter ��� �����������");
	_getch();
}

void viewFlour()
{
	int fl;
	system("cls");
	char* file = "";
	do
	{
		printf("�������� ����: ");
		scanf("%d", &fl);
	} while (fl>NUMFL);

	switch (fl)
	{
	case 1: file = fl1; break;
	case 2: file = fl2; break;
	case 3: file = fl3; break;
	case 4: file = fl4; break;
	case 5: file = fl5; break;
	default:
		break;
	}

	FILE *f = nullptr;
	f = fopen(file, "r");
	if (f == NULL)
	{
		printf("����� �� ����������\n������� Enter ��� �����������");
		_getch();
		return;
	}
	system("cls");
	printf("���      !!�������   !!��������     !!���         !!������� !!���������  !!���������  !! ������ !!\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	char str[50];
	int num_wd = 1;

	while (fgets(str, sizeof(str), f) != NULL)
	{
		str[strlen(str) - 1] = ' ';
		printf("%12s", str);
		if (num_wd % 8 == 0 && num_wd != 0)
			printf("\n");
		num_wd++;
	}
	printf("��� ����������� ������� Enter");
	_getch();
}


