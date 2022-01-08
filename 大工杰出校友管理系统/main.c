
#include "include.h"
#include"administrator.h"
#include"universal.h"

void main()
{
	POINT *point;		//声明POINT结构体类存储鼠标坐标
	LPRECT rect;		//声明LPRECT结构体指针存储窗口坐标信息
	HWND hwnd;			//声明HWND结构体指针保存句柄
	uint16 login_judgment=0;								//判断是否登录，登录为1，未登录为0
	SetConsoleTitle("大工杰出校友信息管理系统");
	Sleep(50);												//睡眠使句柄改变成功
	hwnd=FindWindow(NULL,"大工杰出校友信息管理系统");		//查找句柄之后保存在这里
	point=(POINT*)malloc(sizeof(POINT)+64);					//分配内存
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//为结构体指针分配内存空间
	
	//renew();          //     ***********数据复原，谨慎使用*************






/************************************  初始界面  ********************************************/
loop_to_initial:
	system("cls");
	common_form();
	initial_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return ;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				if(login_judgment)
					goto loop_to_administrator;
				else
					goto loop_to_administrator_login;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto loop_to_tourist;
			}
		}
	}

/************************************  初始界面结束  ********************************************/







/************************************  管理员登录界面  ********************************************/
loop_to_administrator_login:
	system("cls");
	common_form();
	administrator_login();
	rectangle(60,18,10,3);gotoxy(62,19);printf("点击登录");
	gotoxy(1,1);
loop_to_administrator_login_wrong:
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标

			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto loop_to_initial;
			}
			if(60*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<21*Pixel.height-Pixel.height/2)//点击登录
			{
				uint16 i;
				gotoxy(99,4);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(99,5);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(99,6);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(99,7);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(99,8);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(99,9);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(60,18);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(60,19);for(i=0;i<12;i++)printf(" ");//清空原有文字
				gotoxy(60,20);for(i=0;i<12;i++)printf(" ");//清空原有文字
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
		for(i=0;(c=getch())!='\r';)//密码密码回显*符号
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
			gotoxy(11,18);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(11,19);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(30,19);printf("账号或密码错误，是否常新登录？");
			rectangle(60,18,10,3);gotoxy(62,19);printf("重新登录");
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
			gotoxy(11,18);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(11,19);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//清空原有文字
			gotoxy(30,19);printf("账号或密码错误，是否常新登录？");
			rectangle(60,18,10,3);gotoxy(62,19);printf("重新登录");
			gotoxy(1,1);
			goto loop_to_administrator_login_wrong;
		}
		login_judgment++;
		goto loop_to_administrator;
	}

/************************************  管理员登录界面结束  ********************************************/








/************************************  管理员界面  ********************************************/

loop_to_administrator:
	system("cls");
	common_form();
	administrator_key();
	if(login_judgment)
	{
		rectangle(75,23,20,3);
		gotoxy(82,24);printf("退出登录");
		gotoxy(1,1);
	}
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto loop_to_initial;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击普通查看
			{
				system("cls");
				data_display();
				goto loop_to_administrator;
			}
			if(50*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击排序查看
			{
				system("cls");
				data_display_pro();
				goto loop_to_administrator;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击
			{
				system("cls");
				data_saving();
				goto loop_to_administrator;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//点击普通查看
			{
				system("cls");
				data_change();
				goto loop_to_administrator;
			}
			if(50*Pixel.width-Pixel.width/2<x&&x<70*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//点击排序查看
			{
				system("cls");
				data_delete();
				goto loop_to_administrator;
			}
			if(login_judgment)
				if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<26*Pixel.height-Pixel.height/2)//点击
				{
					system("cls");
					login_judgment--;
					goto loop_to_initial;
				}
		}
	}

/************************************  管理员界面结束  ********************************************/








/************************************  游客界面  ********************************************/

loop_to_tourist:
	system("cls");
	common_form();
	tourist_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return ;
			}
			if(99*Pixel.width-Pixel.width/2<x&&x<109*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<10*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto loop_to_initial;
			}
			if(25*Pixel.width-Pixel.width/2<x&&x<45*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击普通查看
			{
				system("cls");
				data_display();
				goto loop_to_tourist;
			}
			if(75*Pixel.width-Pixel.width/2<x&&x<95*Pixel.width-Pixel.width/2&&20*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击排序查看
			{
				system("cls");
				data_display_pro();
				goto loop_to_tourist;
			}
		}	
	}
}

/************************************  游客界面  ********************************************/