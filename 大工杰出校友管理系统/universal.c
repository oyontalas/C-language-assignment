#include"include.h"


/************

ͨ��

*************/
/*����������������������������������������������������������������*/

void gotoxy(int16 x,int16 y) //���ù��ܣ�����̨�����ת
{
    COORD c;
    c.X=x-1;
    c.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void rectangle(uint16 x,uint16 y,uint16 width,uint16 height)//������Σ��β�Ϊ�������Ͻ�λ��x��y����Ⱥ͸߶�
{
	uint16 i;
	gotoxy(x,y);
	printf("��");for(i=0;i<width-1;i++)printf("��");printf("��");
	for(i=1;i<height-1;i++)
	{
		gotoxy(x,y+i);printf("��");
		gotoxy(x+width,y+i);printf("��");
	}
	gotoxy(x,y+height-1);
	printf("��");for(i=0;i<width-1;i++)printf("��");printf("��");
	gotoxy(1,1);
}
void return_key()   //������ҳ�ͷ�����һ��
{
	rectangle(3,1,6,3);
	rectangle(112,1,6,3);
	gotoxy(5,2);printf("��ҳ");
	gotoxy(114,2);printf("����");
	gotoxy(1,1);
}

/************

��������

*************/
/*����������������������������������������������������������������*/

void common_form()//ͨ�ò�������
{
	uint16 i;
	rectangle(10,3,101,25);
	rectangle(10,2,101,27);
	gotoxy(10+50-13,8);printf("��");gotoxy(10+50+13,8);printf("��");
	gotoxy(10+50-11,9);printf("�󹤽ܳ�У����Ϣ����ϵͳ");
	gotoxy(10+50-13,10);printf("��");gotoxy(10+50+13,10);printf("��");
	rectangle(99,4,10,3);gotoxy(101,5);printf("�˳�ϵͳ");
	rectangle(99,7,10,3);gotoxy(103,8);printf("����");
	gotoxy(10,29);printf("���ߣ������࣬��ӭ������");
	gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//���ԭ������
	gotoxy(11,21);for(i=0;i<100;i++)printf(" ");//���ԭ������
	gotoxy(11,22);for(i=0;i<100;i++)printf(" ");//���ԭ������
	gotoxy(1,1);
}

void initial_key()//��ʼ������
{
	uint16 i;
	rectangle(25,20,20,3);gotoxy(31,21);printf("����Աģʽ");
	rectangle(75,20,20,3);gotoxy(82,21);printf("�ÿ�ģʽ");
	//ɾ�����ؼ�
	gotoxy(99,7);for(i=0;i<12;i++)printf(" ");//���ԭ������
	gotoxy(99,8);for(i=0;i<12;i++)printf(" ");//���ԭ������
	gotoxy(99,9);for(i=0;i<12;i++)printf(" ");//���ԭ������
	gotoxy(1,1);
}
void administrator_login()	//����Ա��¼
{
	uint16 i;
	gotoxy(32,19);printf("���¼����Ա�˻���");
	gotoxy(32,21);printf("�˻���");
	gotoxy(38,22);for(i=0;i<20;i++)printf("��");
	gotoxy(32,23);printf("���룺");
	gotoxy(38,24);for(i=0;i<20;i++)printf("��");
	gotoxy(1,1);
}
void administrator_key()//����Ա������
{
	rectangle(25,20,20,3);gotoxy(32,21);printf("��ͨ�鿴");
	rectangle(50,20,20,3);gotoxy(57,21);printf("����鿴");
	rectangle(75,20,20,3);gotoxy(80,21);printf("���У����Ϣ");
	rectangle(25,23,20,3);gotoxy(30,24);printf("�޸�У����Ϣ");
	rectangle(50,23,20,3);gotoxy(55,24);printf("ɾ��У����Ϣ");
	gotoxy(1,1);
}
void tourist_key()//�οͲ�����
{
	rectangle(25,20,20,3);gotoxy(32,21);printf("��ͨ�鿴");
	rectangle(75,20,20,3);gotoxy(82,21);printf("����鿴");
	gotoxy(1,1);
}

/************

1.��ͨ�鿴

*************/
/*����������������������������������������������������������������*/


void data_display_form1(ALUMNI *head)//�鿴������Ϣ���
{
	/*�ṩ��ʾ�Ĺ��λ��*/
	//����9+50+2,2
	//���9+100-14,2 
	uint16 i,k;
	uint16 name_i;			//�������������ѭ����
	uint16 buf;				//���ݿ�����
	uint16 x=10,y=4,upper=4;//upper�Ǳ���Ͻ磬x��y�Ǿ��Թ������
	ALUMNI *p=head;
//1��******************
	gotoxy(10,1);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
//2��******************
	gotoxy(10,2);printf("���������������Ҫ�鿴��У�ѵ������������");
	gotoxy(9+60,2);printf("�� �������ҩ�");
	//����9+72,2
	gotoxy(9+80,2);printf("�� ��Ų��ҩ�");
	//���9+92,2 
	gotoxy(111,2);printf("��");
//3��******************
	gotoxy(10,3);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
	buf=p->number;
	while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
		p=p->link_ahead;
	for(k=1;buf>=k;k++)
	{
		if(!(y>upper+24&&x==61))
		{
			if(y==upper)
			{
				gotoxy(x+4,y);printf("���");
				gotoxy(x+11,y);printf("����");
				gotoxy(x,y+1);
				printf("��");for(i=0;i<49;i++)printf("��");printf("��");
				y+=2;
			}
			if(y<=upper+24)
			{
				if(y-2!=upper)
				{
					gotoxy(x,y-1);printf("��");
					gotoxy(x+50,y-1);printf("��");
				}
				gotoxy(x,y);printf("��    %u",p->number);
				gotoxy(x+10,y);
				for(name_i=0;p->name[name_i]!='\0'&&name_i<40;name_i++)
					printf("%c",p->name[name_i]);
				gotoxy(x+50,y);printf("��");
				gotoxy(x,y+1);
				printf("��");for(i=0;i<49;i++)printf("��");printf("��");
				p=p->link_back;
				y+=2;
			}
			if(y>upper+24&&x!=61)
			{
				y=upper;
				x=61;
			}
		}
		else
		{
			upper+=28;
			x=10;
			y=upper;
		}
	}
	gotoxy(1,1);
}
void data_display_form2(ALUMNI *p)	//�鿴��ϸ��Ϣ���
{
	/*�ṩ��ʾ�Ĺ��λ��*/
	//���9+100-6,2  3
	//����10+6,4  20
	//��ѧ���10+6+20+10,4  5
	//��У���10+6+20+10+5+10,4 20
	//ϵ��10+6+20+10+5+10+20+6,4 20
	//�о�����10+10,6
	//���10+8,8
	//��Ҫ�ɾ�1 10+12,14
	//��Ҫ�ɾ�2 10+12,19
	//��Ҫ�ɾ�3 10+12,24
	uint16 i;
	int16 add=0;//���ӵĳ���
	int16 add4_max,add4_identity,add4_department;//�ڵ��������ӵĳ���
	int16 add_introduction,add_major_achievements1,add_major_achievements2,add_major_achievements3;//��Ӧ��Ϣ���ӵĳ���
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���λ����Ϣ
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
	//ȫ����ʼ��Ϊ��
	add4_max=add4_identity=add4_department=add_introduction=add_major_achievements1=add_major_achievements2=add_major_achievements3=0;
//1��******************
	gotoxy(10,1);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");

//2��******************
	gotoxy(10,2);printf("��");
	gotoxy(9+50-4,2);printf("У����Ϣ");
	gotoxy(9+100-9,2);printf("��ţ�");
	//���9+100-6,2  3
	printf("%u",p->number);
	gotoxy(111,2);printf("��");
	
//3��******************
	gotoxy(10,3);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");

//4��******************
	gotoxy(10,4);printf("������:");
	//����10+6,4  20
	for(i=0;p->name[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>10+6+20-2)
		{
			add4_max++;
			gotoxy(10,4+add4_max);printf("��");
			gotoxy(10+6+20,4+add4_max);printf("��");
			gotoxy(10+6+20+10+5,4+add4_max);printf("��");
			gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("��");
			gotoxy(111,4+add4_max);printf("��");
			gotoxy(10+6,4+add4_max);
		}
		printf("%c",p->name[i]);
	}
	gotoxy(10+6+20,4);printf("����ѧ���:");
	//��ѧ���10+6+20+10,4  5
	gotoxy(10+6+20+10,4);printf("%u",p->year);
	gotoxy(10+6+20+10+5,4);printf("����У���:");
	//��У���10+6+20+10+5+10��4 20
	for(i=0;p->identity[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>10+6+20+10+5+10+20-2)
		{

			add4_identity++;
			if(add4_identity>add4_max)
			{
				add4_max=add4_identity;
				gotoxy(10,4+add4_max);printf("��");
				gotoxy(10+6+20,4+add4_max);printf("��");
				gotoxy(10+6+20+10+5,4+add4_max);printf("��");
				gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("��");
				gotoxy(111,4+add4_max);printf("��");	
			}
			gotoxy(10+6+20+10+5+10,4+add4_identity);
		}
		printf("%c",p->identity[i]);
	}
	gotoxy(10+6+20+10+5+10+20,4);printf("��ϵ��:");
	//ϵ��10+6+20+10+5+10+20+6��,4 20
	for(i=0;p->department[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>109)
		{

			add4_department++;
			if(add4_identity>add4_max)
			{
				add4_max=add4_department;
				gotoxy(10,4+add4_max);printf("��");
				gotoxy(10+6+20,4+add4_max);printf("��");
				gotoxy(10+6+20+10+5,4+add4_max);printf("��");
				gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("��");
				gotoxy(111,4+add4_max);printf("��");	
			}
			gotoxy(10+6+20+10+5+10+20+6,4+add4_department);
		}
		printf("%c",p->department[i]);
	}
	gotoxy(111,4);printf("��");
	add=add4_max;
//5��******************
	gotoxy(10,5+add);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");

	gotoxy(10+6+20,3);printf("��");

	gotoxy(10+6+20+10+5,3);printf("��");

	gotoxy(10+6+20+10+5+10+20,3);printf("��");


	gotoxy(10+6+20,5+add);printf("��");

	gotoxy(10+6+20+10+5,5+add);printf("��");

	gotoxy(10+6+20+10+5+10+20,5+add);printf("��");


//6��******************
	gotoxy(111,6+add);printf("��");	
	gotoxy(10,6+add);printf("���о�����");
	//�о�����10+10,6
	for(i=0;p->desearch_areas[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>110)
		{
			add++;
			gotoxy(10,6+add);printf("��");
			gotoxy(111,6+add);printf("��");	
			gotoxy(10,6+add);printf(" ");
		}
		printf("%c",p->desearch_areas[i]);
	}

//7��******************
	gotoxy(10,7+add);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");


//8��14��19��24��******************
// 13��18��23��******************
	gotoxy(10,8+add);printf("����飺");
	//���10+8,8
	for(i=0;p->introduction[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_introduction++;
			if(add_introduction>4)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->introduction[i]);
	}
	gotoxy(10,13+add);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");


	gotoxy(10,14+add);printf("����Ҫ�ɾ�1:");
	//��Ҫ�ɾ�1 10+12,14
	for(i=0;p->major_achievements[0][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements1++;
			if(add_major_achievements1>3)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[0][i]);
	}
	gotoxy(10,18+add);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");


	gotoxy(10,19+add);printf("����Ҫ�ɾ�2:");
	//��Ҫ�ɾ�2 10+12,19
	for(i=0;p->major_achievements[1][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements2++;
			if(add_major_achievements2>3)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[1][i]);
	}
	gotoxy(10,23+add);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");


	gotoxy(10,24+add);printf("����Ҫ�ɾ�3:");
	//��Ҫ�ɾ�3 10+12,24
	for(i=0;p->major_achievements[2][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements3++;
			if(add_major_achievements3>2)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[2][i]);
	}



//8-26��******************
	for(i=8;i<=26+add;i++)
	{
		gotoxy(10,i);printf("��");
		gotoxy(111,i);printf("��");
	}

//27��******************
	gotoxy(10,27+add);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
	gotoxy(1,1);
}

void data_display()//��Ϣ�鿴����
{
	FILE *fp;			//�������ļ�
	ALUMNI *head,*p;	//�����ͷָ�룬��������ڵ�ָ��
	uint16 i;			//����ѭ��ʹ��
	POINT *point;		//����POINT�ṹ����洢�������
	LPRECT rect;		//����LPRECT�ṹ��ָ��洢����������Ϣ
	int16 buf;			//���ݿ�����
	HWND hwnd=FindWindow(NULL,"�󹤽ܳ�У����Ϣ����ϵͳ");	//���Ҿ��֮�󱣴�������
	point=(POINT*)malloc(sizeof(POINT)+64);					//�����ڴ�
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//Ϊ�ṹ��ָ������ڴ�ռ�
	fp=fopen("data.dat","rb");
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	if(fread(p,sizeof(ALUMNI),1,fp))
	{
		p->link_ahead=NULL;
		head=p;
		while(1)//���ļ��������浽������
		{
			p=(ALUMNI *)malloc(sizeof(ALUMNI));
			fread(p,sizeof(ALUMNI),1,fp);
			if(!feof(fp))
			{
				p->link_ahead=head;
				head->link_back=p;
				head=p;
				p->link_back=NULL;
			}
			else
			{
				free(p);
				p=head;
				break;
			}
		}
	}
	else
	{
		gotoxy(10,4);printf("��û����Ϣ��");
		for(i=3;i>0;i--)
		{
			printf("%hd��󷵻���һ������",i);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		system("cls");
		fclose(fp);
		return;
	}
	fclose(fp);
	buf=head->number;//���ݿ�����
return_loop:
	data_display_form1(head);
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				return;
			}
			if(69*Pixel.width-Pixel.width/2<x&&x<80*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height+-Pixel.height/2)//�����������
			{
				uint16 i;
				int8 name[40];
				uint16 count=0;		//��������
				ALUMNI *temp=NULL;  //����ָ��
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(9+60-4,2);
				for(i=0;i<40;i++)printf(" ");
			loop1:gotoxy(9+60+2,2);printf("������");
				if(!scanf("%s",&name))
				{
					gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
					gotoxy(11,2);printf("����������������롣");
					fflush(stdin);
					goto loop1;
				}
				p=head;
				while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
					p=p->link_ahead;
				while(p!=NULL)
				{
					for(i=0;p->name[i]!='\0';i++)
						if(p->name[i]!=name[i])
							break;
					if(p->name[i]=='\0'&&name[i]=='\0')
					{
						count++;
						if(temp!=NULL&&count==2)
						{
							gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
							gotoxy(11,2);printf("%s�����������Ϊ%hd,",temp->name,temp->number);
						}
						if(count>1)
						{
							printf("%hd,",p->number);
						}
						else
							temp=p;
					}

					p=p->link_back;
				}
				if(count>1)
				{
					int16 buf=head->number;
					int16 number;
					printf("\b.");
				loop3:gotoxy(9+60+2,2);printf("��ţ�");
					if(!scanf("%hd",&number)||number>buf)
					{
						gotoxy(9+60+6+2,2);printf("    ");
						gotoxy(9+80+2,2);printf("�����������룡");
						fflush(stdin);
						goto loop3;
					}
					p=head;
					for(i=0;buf-number>i;i++)	//pָ��ָ���ڵ�
						p=p->link_ahead;
					system("cls");
					data_display_form2(p);
					break;
				}	
				if(count==1)
				{
					system("cls");
					data_display_form2(temp);
				}
				if(!count)
				{
					gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
					gotoxy(11,2);printf("û�в鵽��У�ѡ�");
				}
				p=head;
				break;
			}
			if(89*Pixel.width-Pixel.width/2<x&&x<100*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height+-Pixel.height/2)//����������
			{
				uint16 i;
				int16 number;
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(9+60-4,2);
				for(i=0;i<40;i++)printf(" ");
			loop2:gotoxy(9+60+2,2);printf("��ţ�");
				if(!scanf("%hd",&number)||number>buf)
				{
					gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
					gotoxy(11,2);printf("���������޴���ţ����������롣");
					fflush(stdin);
					goto loop2;
				}
				for(i=0;buf-number>i;i++)	//pָ��ָ���ڵ�
					p=p->link_ahead;
				system("cls");
				data_display_form2(p);
				p=head;
				break;
			}
		}

	}
/******************��ת����***********************/
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto return_loop;
			}
			
		}
	}
/******************��ת���ؽ���***********************/
}



/************

2.����鿴

*************/
/*����������������������������������������������������������������*/


void data_display_pro_switch_data(ALUMNI *pi,ALUMNI *pj)			//�����ڵ����ݺ���
{
	ALUMNI temp;
	temp.number=pi->number;pi->number=pj->number;pj->number=temp.number;
	temp.year=pi->year;pi->year=pj->year;pj->year=temp.year;
	strcpy(temp.name,pi->name);strcpy(pi->name,pj->name);strcpy(pj->name,temp.name);
	strcpy(temp.identity,pi->identity);strcpy(pi->identity,pj->identity);strcpy(pj->identity,temp.identity);
	strcpy(temp.department,pi->department);strcpy(pi->department,pj->department);strcpy(pj->department,temp.department);
	strcpy(temp.desearch_areas,pi->desearch_areas);strcpy(pi->desearch_areas,pj->desearch_areas);strcpy(pj->desearch_areas,temp.desearch_areas);
	strcpy(temp.introduction,pi->introduction);strcpy(pi->introduction,pj->introduction);strcpy(pj->introduction,temp.introduction);
	strcpy(temp.major_achievements[0],pi->major_achievements[0]);strcpy(pi->major_achievements[0],pj->major_achievements[0]);strcpy(pj->major_achievements[0],temp.major_achievements[0]);
	strcpy(temp.major_achievements[1],pi->major_achievements[1]);strcpy(pi->major_achievements[1],pj->major_achievements[1]);strcpy(pj->major_achievements[1],temp.major_achievements[1]);
	strcpy(temp.major_achievements[2],pi->major_achievements[2]);strcpy(pi->major_achievements[2],pj->major_achievements[2]);strcpy(pj->major_achievements[2],temp.major_achievements[2]);
}
void data_display_pro_form1(int16 *judgment)//����ʽѡ����
{
	uint16 i;
	POINT *point;		//����POINT�ṹ����洢�������
	LPRECT rect;		//����LPRECT�ṹ��ָ��洢����������Ϣ
	HWND hwnd=FindWindow(NULL,"�󹤽ܳ�У����Ϣ����ϵͳ");	//���Ҿ��֮�󱣴�������
	point=(POINT*)malloc(sizeof(POINT)+64);					//�����ڴ�
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//Ϊ�ṹ��ָ������ڴ�ռ�
	//1��******************
	gotoxy(10,1);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
//2��******************
	gotoxy(10,2);printf("��");
	gotoxy(9+50-6,2);printf("��ѡ������ʽ");
	//����9+60+2,2
	gotoxy(111,2);printf("��");
//3��******************
	gotoxy(10,3);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
	rectangle(15,4,20,3);gotoxy(24,5);printf("����");
	rectangle(39,4,20,3);gotoxy(48-2,5);printf("��ѧ���");
	rectangle(63,4,20,3);gotoxy(72-2,5);printf("��У���");
	rectangle(87,4,20,3);gotoxy(96,5);printf("ϵ��");
	gotoxy(1,1);
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(15*Pixel.width-Pixel.width/2<x&&x<35*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//�������
			{*judgment=0;break;}
			if(39*Pixel.width-Pixel.width/2<x&&x<59*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//�����ѧ���
			{*judgment=1;break;}
			if(63*Pixel.width-Pixel.width/2<x&&x<83*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//�����У���
			{*judgment=2;break;}
			if(87*Pixel.width-Pixel.width/2<x&&x<107*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//���ϵ��
			{*judgment=3;break;}
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ҳ
			{*judgment=-1;break;}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{*judgment=-1;break;}
		}
	}
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");//���ԭ������
	gotoxy(10,4);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,5);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,6);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(1,1);
	return;
}
void data_display_pro_form2(ALUMNI *head,int16 *judgment,uint16 buf)//����鿴������Ϣ���
{
	/*�ṩ��ʾ�Ĺ��λ��*/
	//���9+90+2,2
	uint16 i,k;
	ALUMNI *pi,*pj,*p=head;			//���ڼ�ѡ������
	uint16 name_i;					//�������������ѭ����
	uint16 x=10,y=4,upper=4;		//upper�Ǳ���Ͻ磬x��y�Ǿ��Թ������
//2��******************
	switch(*judgment)
	{
		case 0:gotoxy(9+50-6,2);printf("У����������鿴");break;
		case 1:gotoxy(9+50-8,2);printf("У����ѧ�������鿴");break;
		case 2:gotoxy(9+50-8,2);printf("У����У�������鿴");break;
		case 3:gotoxy(9+50-6,2);printf("У��ϵ������鿴");break;
	}
	for(pi=head;pi->link_ahead!=NULL;pi=pi->link_ahead)		//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
		for(pj=pi->link_ahead;pj!=NULL;pj=pj->link_ahead)
			switch(*judgment)
			{
				case 0:if(strcmp(pj->name,pi->name)>0)data_display_pro_switch_data(pi,pj);break;
				case 1:if(pj->year>pi->year)data_display_pro_switch_data(pi,pj);break;
				case 2:if(strcmp(pj->identity,pi->identity)>0)data_display_pro_switch_data(pi,pj);break;
				case 3:if(strcmp(pj->department,pi->department)>0)data_display_pro_switch_data(pi,pj);break;
			}
	while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
		p=p->link_ahead;
	for(k=1;buf>=k;k++)
	{
		if(!(y>upper+24&&x==61))
		{
			if(y==upper)
			{
				gotoxy(x+2,y);printf("���");
				gotoxy(x+22,y);
					switch(*judgment)
				{
					case 0:gotoxy(x+20,y);printf("����");break;
					case 1:gotoxy(x+10,y);printf("����");gotoxy(x+20,y);printf("��ѧ���");break;
					case 2:gotoxy(x+10,y);printf("����");gotoxy(x+20,y);printf("��У���");break;
					case 3:gotoxy(x+10,y);printf("����");gotoxy(x+20,y);printf("ϵ��");break;
				}
				gotoxy(x,y+1);
				printf("��");for(i=0;i<49;i++)printf("��");printf("��");
				y+=2;
			}
			if(y<=upper+24)
			{
				if(y-2!=upper)
				{
					gotoxy(x,y-1);printf("��");
					gotoxy(x+50,y-1);printf("��");
				}
				gotoxy(x,y);printf("�� %u",p->number);
				gotoxy(x+18,y);
				switch(*judgment)
				{
					case 0:gotoxy(x+18,y);for(name_i=0;p->name[name_i]!='\0'&&name_i<20;name_i++)printf("%c",p->name[name_i]);break;
					case 1:gotoxy(x+8,y);for(name_i=0;p->name[name_i]!='\0'&&name_i<10;name_i++)printf("%c",p->name[name_i]);
						gotoxy(x+20,y);printf("%hd",p->year);break;
					case 2:gotoxy(x+8,y);for(name_i=0;p->name[name_i]!='\0'&&name_i<10;name_i++)printf("%c",p->name[name_i]);
						gotoxy(x+18,y);for(name_i=0;p->identity[name_i]!='\0'&&name_i<30;name_i++)printf("%c",p->identity[name_i]);break;
					case 3:gotoxy(x+8,y);for(name_i=0;p->name[name_i]!='\0'&&name_i<10;name_i++)printf("%c",p->name[name_i]);
						gotoxy(x+18,y);for(name_i=0;p->department[name_i]!='\0'&&name_i<30;name_i++)printf("%c",p->department[name_i]);break;
				}
				gotoxy(x+50,y);printf("��");
				gotoxy(x,y+1);
				printf("��");for(i=0;i<49;i++)printf("��");printf("��");
				p=p->link_back;
				y+=2;
			}
			if(y>upper+24&&x!=61)
			{
				y=upper;
				x=61;
			}
		}
		else
		{
			upper+=28;
			x=10;
			y=upper;
		}
	}
	gotoxy(1,1);
}

void data_display_pro()//��Ϣ����鿴����
{
	
	FILE *fp;			//�������ļ�
	ALUMNI *head,*p;	//�����ͷָ�룬��������ڵ�ָ��
	uint16 i;			//����ѭ��ʹ��
	POINT *point;		//����POINT�ṹ����洢�������
	LPRECT rect;		//����LPRECT�ṹ��ָ��洢����������Ϣ
	int16 judgment;		//����������λ���ж�
	uint16 buf;								//���ݿ�����
	HWND hwnd=FindWindow(NULL,"�󹤽ܳ�У����Ϣ����ϵͳ");	//���Ҿ��֮�󱣴�������
	point=(POINT*)malloc(sizeof(POINT)+64);					//�����ڴ�
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//Ϊ�ṹ��ָ������ڴ�ռ�
	fp=fopen("data.dat","rb");
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	if(fread(p,sizeof(ALUMNI),1,fp))
	{
		p->link_ahead=NULL;
		head=p;
		while(1)//���ļ��������浽������
		{
			p=(ALUMNI *)malloc(sizeof(ALUMNI));
			fread(p,sizeof(ALUMNI),1,fp);
			if(!feof(fp))
			{
				p->link_ahead=head;
				head->link_back=p;
				head=p;
				p->link_back=NULL;
			}
			else
			{
				free(p);
				p=head;
				break;
			}
		}
	}
	else
	{
		gotoxy(10,4);printf("��û����Ϣ��");
		for(i=3;i>0;i--)
		{
			printf("%hd��󷵻���һ������",i);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		system("cls");
		fclose(fp);
		return;
	}
	fclose(fp);
	buf=head->number;
return_loop:
	data_display_pro_form1(&judgment);
	if(judgment==-1)
		return;
return_loop2:
	Sleep(50);									//��ֹ�������ЧӦ
	data_display_pro_form2(head,&judgment,buf);
/******************��ת����***********************/
	return_key();
	rectangle(112,4,6,3);
	gotoxy(114,5);printf("���");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto return_loop;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//�����ϸ�鿴
			{
				uint16 i;
				int16 number;
				gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,4);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,5);for(i=0;i<7;i++)printf(" ");//���ԭ������
				gotoxy(112,6);for(i=0;i<7;i++)printf(" ");//���ԭ������
		loop1:	gotoxy(11,2);printf("��������Ҫ�鿴��Ϣ��У����ţ�");
				if(!scanf("%hd",&number)||number>buf)
				{
					gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
					gotoxy(9+80+2,2);printf("�����������룡");
					fflush(stdin);
					goto loop1;
				}
				p=head;
				for(i=0;i<buf;i++)	//pָ��ָ���ڵ�
				{
					if(p->number==number)
						break;
					p=p->link_ahead;
				}
				system("cls");
				data_display_form2(p);
				p=head;
				break;
			}
		}
	}
/******************��ת���ؽ���***********************/
/******************��ת����***********************/
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				rectangle(10,1,100,3);
				goto return_loop2;
			}
		}
	}
/******************��ת���ؽ���***********************/
}