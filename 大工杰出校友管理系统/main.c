
#include "include.h"
#include"administrator.h"
#include"universal.h"

void main()
{
	POINT *point;		//����POINT�ṹ����洢�������
	LPRECT rect;		//����LPRECT�ṹ��ָ��洢����������Ϣ
	HWND hwnd;			//����HWND�ṹ��ָ�뱣����
	uint16 login_judgment=0;								//�ж��Ƿ��¼����¼Ϊ1��δ��¼Ϊ0
	SetConsoleTitle("�󹤽ܳ�У����Ϣ����ϵͳ");
	Sleep(50);												//˯��ʹ����ı�ɹ�
	hwnd=FindWindow(NULL,"�󹤽ܳ�У����Ϣ����ϵͳ");		//���Ҿ��֮�󱣴�������
	point=(POINT*)malloc(sizeof(POINT)+64);					//�����ڴ�
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//Ϊ�ṹ��ָ������ڴ�ռ�
	
	//renew();          //     ***********���ݸ�ԭ������ʹ��*************






/************************************  ��ʼ����  ********************************************/
loop_to_initial:
	system("cls");
	common_form();
	initial_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return ;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				if(login_judgment)
					goto loop_to_administrator;
				else
					goto loop_to_administrator_login;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto loop_to_tourist;
			}
		}
	}

/************************************  ��ʼ�������  ********************************************/







/************************************  ����Ա��¼����  ********************************************/
loop_to_administrator_login:
	system("cls");
	common_form();
	administrator_login();
	rectangle(60,18,10,3);gotoxy(62,19);printf("�����¼");
	gotoxy(1,1);
loop_to_administrator_login_wrong:
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������

			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto loop_to_initial;
			}
			if(60*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<21*Pixel.height-Pixel.height/2)//�����¼
			{
				uint16 i;
				gotoxy(99,4);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(99,5);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(99,6);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(99,7);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(99,8);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(99,9);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(60,18);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(60,19);for(i=0;i<12;i++)printf(" ");//���ԭ������
				gotoxy(60,20);for(i=0;i<12;i++)printf(" ");//���ԭ������
				break;
			}
		}
	}
	{
		uint16 i;
		int8 c;
		int8 account[100],password[100];
		gotoxy(38,21);scanf("%s",account);getchar();
		gotoxy(38,23);
		for(i=0;(c=getch())!='\r';)//�����������*����
		{
			if (i>0&&c=='\b')
			{--i;putchar('\b');putchar(' ');putchar('\b');}
			else if(i||c!='\b')
			{password[i++]=c;putchar('*');}
		}
		putchar('\n');
		password[i] = '\0';
		for(i=0;Manager.account[i]!='\0';i++)
			if(Manager.account[i]!=account[i])
				break;
		if(Manager.account[i]!='\0'||account[i]!='\0')
		{
			system("cls");
			common_form();
			administrator_login();
			gotoxy(11,18);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(11,19);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(30,19);printf("�˺Ż���������Ƿ��µ�¼��");
			rectangle(60,18,10,3);gotoxy(62,19);printf("���µ�¼");
			gotoxy(1,1);
			goto loop_to_administrator_login_wrong;
		}
		for(i=0;Manager.password[i]!='\0';i++)
			if(Manager.password[i]!=password[i])
				break;
		if(Manager.password[i]!='\0'||password[i]!='\0')
		{
			system("cls");
			common_form();
			administrator_login();
			gotoxy(11,18);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(11,19);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//���ԭ������
			gotoxy(30,19);printf("�˺Ż���������Ƿ��µ�¼��");
			rectangle(60,18,10,3);gotoxy(62,19);printf("���µ�¼");
			gotoxy(1,1);
			goto loop_to_administrator_login_wrong;
		}
		login_judgment++;
		goto loop_to_administrator;
	}

/************************************  ����Ա��¼�������  ********************************************/








/************************************  ����Ա����  ********************************************/

loop_to_administrator:
	system("cls");
	common_form();
	administrator_key();
	if(login_judgment)
	{
		rectangle(75,23,20,3);
		gotoxy(82,24);printf("�˳���¼");
		gotoxy(1,1);
	}
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto loop_to_initial;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//�����ͨ�鿴
			{
				system("cls");
				data_display();
				goto loop_to_administrator;
			}
			if(50*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//�������鿴
			{
				system("cls");
				data_display_pro();
				goto loop_to_administrator;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//���
			{
				system("cls");
				data_saving();
				goto loop_to_administrator;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//�����ͨ�鿴
			{
				system("cls");
				data_change();
				goto loop_to_administrator;
			}
			if(50*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//�������鿴
			{
				system("cls");
				data_delete();
				goto loop_to_administrator;
			}
			if(login_judgment)
				if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//���
				{
					system("cls");
					login_judgment--;
					goto loop_to_initial;
				}
		}
	}

/************************************  ����Ա�������  ********************************************/








/************************************  �οͽ���  ********************************************/

loop_to_tourist:
	system("cls");
	common_form();
	tourist_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//�����ҳ
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				goto loop_to_initial;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//�����ͨ�鿴
			{
				system("cls");
				data_display();
				goto loop_to_tourist;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//�������鿴
			{
				system("cls");
				data_display_pro();
				goto loop_to_tourist;
			}
		}	
	}
}

/************************************  �οͽ���  ********************************************/