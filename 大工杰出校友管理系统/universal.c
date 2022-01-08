#include"include.h"


/************

通用

*************/
/*————————————————————————————————*/

void gotoxy(int16 x,int16 y) //引用功能：控制台光标跳转
{
    COORD c;
    c.X=x-1;
    c.Y=y-1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void rectangle(uint16 x,uint16 y,uint16 width,uint16 height)//输出矩形，形参为矩形左上角位置x，y，宽度和高度
{
	uint16 i;
	gotoxy(x,y);
	printf("┏");for(i=0;i<width-1;i++)printf("━");printf("┓");
	for(i=1;i<height-1;i++)
	{
		gotoxy(x,y+i);printf("┃");
		gotoxy(x+width,y+i);printf("┃");
	}
	gotoxy(x,y+height-1);
	printf("┗");for(i=0;i<width-1;i++)printf("━");printf("┛");
	gotoxy(1,1);
}
void return_key()   //返回首页和返回上一层
{
	rectangle(3,1,6,3);
	rectangle(112,1,6,3);
	gotoxy(5,2);printf("首页");
	gotoxy(114,2);printf("返回");
	gotoxy(1,1);
}

/************

主界面表格

*************/
/*————————————————————————————————*/

void common_form()//通用操作界面
{
	uint16 i;
	rectangle(10,3,101,25);
	rectangle(10,2,101,27);
	gotoxy(10+50-13,8);printf("◤");gotoxy(10+50+13,8);printf("◥");
	gotoxy(10+50-11,9);printf("大工杰出校友信息管理系统");
	gotoxy(10+50-13,10);printf("◣");gotoxy(10+50+13,10);printf("◢");
	rectangle(99,4,10,3);gotoxy(101,5);printf("退出系统");
	rectangle(99,7,10,3);gotoxy(103,8);printf("返回");
	gotoxy(10,29);printf("作者：付艾肃，欢迎交流。");
	gotoxy(11,20);for(i=0;i<100;i++)printf(" ");//清空原有文字
	gotoxy(11,21);for(i=0;i<100;i++)printf(" ");//清空原有文字
	gotoxy(11,22);for(i=0;i<100;i++)printf(" ");//清空原有文字
	gotoxy(1,1);
}

void initial_key()//初始操作键
{
	uint16 i;
	rectangle(25,20,20,3);gotoxy(31,21);printf("管理员模式");
	rectangle(75,20,20,3);gotoxy(82,21);printf("访客模式");
	//删除返回键
	gotoxy(99,7);for(i=0;i<12;i++)printf(" ");//清空原有文字
	gotoxy(99,8);for(i=0;i<12;i++)printf(" ");//清空原有文字
	gotoxy(99,9);for(i=0;i<12;i++)printf(" ");//清空原有文字
	gotoxy(1,1);
}
void administrator_login()	//管理员登录
{
	uint16 i;
	gotoxy(32,19);printf("请登录管理员账户。");
	gotoxy(32,21);printf("账户：");
	gotoxy(38,22);for(i=0;i<20;i++)printf("￣");
	gotoxy(32,23);printf("密码：");
	gotoxy(38,24);for(i=0;i<20;i++)printf("￣");
	gotoxy(1,1);
}
void administrator_key()//管理员操作键
{
	rectangle(25,20,20,3);gotoxy(32,21);printf("普通查看");
	rectangle(50,20,20,3);gotoxy(57,21);printf("排序查看");
	rectangle(75,20,20,3);gotoxy(80,21);printf("添加校友信息");
	rectangle(25,23,20,3);gotoxy(30,24);printf("修改校友信息");
	rectangle(50,23,20,3);gotoxy(55,24);printf("删除校友信息");
	gotoxy(1,1);
}
void tourist_key()//游客操作键
{
	rectangle(25,20,20,3);gotoxy(32,21);printf("普通查看");
	rectangle(75,20,20,3);gotoxy(82,21);printf("排序查看");
	gotoxy(1,1);
}

/************

1.普通查看

*************/
/*————————————————————————————————*/


void data_display_form1(ALUMNI *head)//查看简略信息表格
{
	/*提供显示的光标位置*/
	//姓名9+50+2,2
	//序号9+100-14,2 
	uint16 i,k;
	uint16 name_i;			//用于姓名输出的循环量
	uint16 buf;				//数据块数量
	uint16 x=10,y=4,upper=4;//upper是表格上界，x，y是绝对光标坐标
	ALUMNI *p=head;
//1行******************
	gotoxy(10,1);
	printf("┏");for(i=0;i<100;i++)printf("━");printf("┓");
//2行******************
	gotoxy(10,2);printf("┃请鼠标点击并输入要查看的校友的姓名或者序号");
	gotoxy(9+60,2);printf("┋ 姓名查找┋");
	//姓名9+72,2
	gotoxy(9+80,2);printf("┋ 序号查找┋");
	//序号9+92,2 
	gotoxy(111,2);printf("┃");
//3行******************
	gotoxy(10,3);
	printf("┗");for(i=0;i<100;i++)printf("━");printf("┛");
	buf=p->number;
	while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
		p=p->link_ahead;
	for(k=1;buf>=k;k++)
	{
		if(!(y>upper+24&&x==61))
		{
			if(y==upper)
			{
				gotoxy(x+4,y);printf("序号");
				gotoxy(x+11,y);printf("姓名");
				gotoxy(x,y+1);
				printf("┏");for(i=0;i<49;i++)printf("━");printf("┓");
				y+=2;
			}
			if(y<=upper+24)
			{
				if(y-2!=upper)
				{
					gotoxy(x,y-1);printf("┣");
					gotoxy(x+50,y-1);printf("┫");
				}
				gotoxy(x,y);printf("┃    %u",p->number);
				gotoxy(x+10,y);
				for(name_i=0;p->name[name_i]!='\0'&&name_i<40;name_i++)
					printf("%c",p->name[name_i]);
				gotoxy(x+50,y);printf("┃");
				gotoxy(x,y+1);
				printf("┗");for(i=0;i<49;i++)printf("━");printf("┛");
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
void data_display_form2(ALUMNI *p)	//查看详细信息表格
{
	/*提供显示的光标位置*/
	//序号9+100-6,2  3
	//姓名10+6,4  20
	//入学年份10+6+20+10,4  5
	//在校身份10+6+20+10+5+10,4 20
	//系别10+6+20+10+5+10+20+6,4 20
	//研究方向10+10,6
	//简介10+8,8
	//主要成就1 10+12,14
	//主要成就2 10+12,19
	//主要成就3 10+12,24
	uint16 i;
	int16 add=0;//增加的长度
	int16 add4_max,add4_identity,add4_department;//在第四行增加的长度
	int16 add_introduction,add_major_achievements1,add_major_achievements2,add_major_achievements3;//对应信息增加的长度
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);//获取光标位置信息
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
	//全部初始化为零
	add4_max=add4_identity=add4_department=add_introduction=add_major_achievements1=add_major_achievements2=add_major_achievements3=0;
//1行******************
	gotoxy(10,1);
	printf("┏");for(i=0;i<100;i++)printf("━");printf("┓");

//2行******************
	gotoxy(10,2);printf("┃");
	gotoxy(9+50-4,2);printf("校友信息");
	gotoxy(9+100-9,2);printf("序号：");
	//序号9+100-6,2  3
	printf("%u",p->number);
	gotoxy(111,2);printf("┃");
	
//3行******************
	gotoxy(10,3);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");

//4行******************
	gotoxy(10,4);printf("┃姓名:");
	//姓名10+6,4  20
	for(i=0;p->name[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>10+6+20-2)
		{
			add4_max++;
			gotoxy(10,4+add4_max);printf("┃");
			gotoxy(10+6+20,4+add4_max);printf("┃");
			gotoxy(10+6+20+10+5,4+add4_max);printf("┃");
			gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("┃");
			gotoxy(111,4+add4_max);printf("┃");
			gotoxy(10+6,4+add4_max);
		}
		printf("%c",p->name[i]);
	}
	gotoxy(10+6+20,4);printf("┃入学年份:");
	//入学年份10+6+20+10,4  5
	gotoxy(10+6+20+10,4);printf("%u",p->year);
	gotoxy(10+6+20+10+5,4);printf("┃在校身份:");
	//在校身份10+6+20+10+5+10，4 20
	for(i=0;p->identity[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>10+6+20+10+5+10+20-2)
		{

			add4_identity++;
			if(add4_identity>add4_max)
			{
				add4_max=add4_identity;
				gotoxy(10,4+add4_max);printf("┃");
				gotoxy(10+6+20,4+add4_max);printf("┃");
				gotoxy(10+6+20+10+5,4+add4_max);printf("┃");
				gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("┃");
				gotoxy(111,4+add4_max);printf("┃");	
			}
			gotoxy(10+6+20+10+5+10,4+add4_identity);
		}
		printf("%c",p->identity[i]);
	}
	gotoxy(10+6+20+10+5+10+20,4);printf("┃系别:");
	//系别10+6+20+10+5+10+20+6，,4 20
	for(i=0;p->department[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>109)
		{

			add4_department++;
			if(add4_identity>add4_max)
			{
				add4_max=add4_department;
				gotoxy(10,4+add4_max);printf("┃");
				gotoxy(10+6+20,4+add4_max);printf("┃");
				gotoxy(10+6+20+10+5,4+add4_max);printf("┃");
				gotoxy(10+6+20+10+5+10+20,4+add4_max);printf("┃");
				gotoxy(111,4+add4_max);printf("┃");	
			}
			gotoxy(10+6+20+10+5+10+20+6,4+add4_department);
		}
		printf("%c",p->department[i]);
	}
	gotoxy(111,4);printf("┃");
	add=add4_max;
//5行******************
	gotoxy(10,5+add);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");

	gotoxy(10+6+20,3);printf("┰");

	gotoxy(10+6+20+10+5,3);printf("┰");

	gotoxy(10+6+20+10+5+10+20,3);printf("┰");


	gotoxy(10+6+20,5+add);printf("┸");

	gotoxy(10+6+20+10+5,5+add);printf("┸");

	gotoxy(10+6+20+10+5+10+20,5+add);printf("┸");


//6行******************
	gotoxy(111,6+add);printf("┃");	
	gotoxy(10,6+add);printf("┃研究方向：");
	//研究方向10+10,6
	for(i=0;p->desearch_areas[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>110)
		{
			add++;
			gotoxy(10,6+add);printf("┃");
			gotoxy(111,6+add);printf("┃");	
			gotoxy(10,6+add);printf(" ");
		}
		printf("%c",p->desearch_areas[i]);
	}

//7行******************
	gotoxy(10,7+add);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");


//8，14，19，24行******************
// 13，18，23行******************
	gotoxy(10,8+add);printf("┃简介：");
	//简介10+8,8
	for(i=0;p->introduction[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_introduction++;
			if(add_introduction>4)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->introduction[i]);
	}
	gotoxy(10,13+add);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");


	gotoxy(10,14+add);printf("┃主要成就1:");
	//主要成就1 10+12,14
	for(i=0;p->major_achievements[0][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements1++;
			if(add_major_achievements1>3)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[0][i]);
	}
	gotoxy(10,18+add);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");


	gotoxy(10,19+add);printf("┃主要成就2:");
	//主要成就2 10+12,19
	for(i=0;p->major_achievements[1][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements2++;
			if(add_major_achievements2>3)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[1][i]);
	}
	gotoxy(10,23+add);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");


	gotoxy(10,24+add);printf("┃主要成就3:");
	//主要成就3 10+12,24
	for(i=0;p->major_achievements[2][i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>110)
		{
			add_major_achievements3++;
			if(add_major_achievements3>2)
				add++;
			gotoxy(11, csbi.dwCursorPosition.Y+2);
		}
		printf("%c",p->major_achievements[2][i]);
	}



//8-26行******************
	for(i=8;i<=26+add;i++)
	{
		gotoxy(10,i);printf("┃");
		gotoxy(111,i);printf("┃");
	}

//27行******************
	gotoxy(10,27+add);
	printf("┗");for(i=0;i<100;i++)printf("━");printf("┛");
	gotoxy(1,1);
}

void data_display()//信息查看函数
{
	FILE *fp;			//作用于文件
	ALUMNI *head,*p;	//链表表头指针，链表扩充节点指针
	uint16 i;			//自增循环使用
	POINT *point;		//声明POINT结构体类存储鼠标坐标
	LPRECT rect;		//声明LPRECT结构体指针存储窗口坐标信息
	int16 buf;			//数据块数量
	HWND hwnd=FindWindow(NULL,"大工杰出校友信息管理系统");	//查找句柄之后保存在这里
	point=(POINT*)malloc(sizeof(POINT)+64);					//分配内存
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//为结构体指针分配内存空间
	fp=fopen("data.dat","rb");
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	if(fread(p,sizeof(ALUMNI),1,fp))
	{
		p->link_ahead=NULL;
		head=p;
		while(1)//将文件的数保存到链表里
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
		gotoxy(10,4);printf("还没有信息。");
		for(i=3;i>0;i--)
		{
			printf("%hd秒后返回上一步……",i);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		system("cls");
		fclose(fp);
		return;
	}
	fclose(fp);
	buf=head->number;//数据块数量
return_loop:
	data_display_form1(head);
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				return;
			}
			if(69*Pixel.width-Pixel.width/2<x&&x<80*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height+-Pixel.height/2)//点击输入姓名
			{
				uint16 i;
				int8 name[40];
				uint16 count=0;		//重名计数
				ALUMNI *temp=NULL;  //过程指针
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(9+60-4,2);
				for(i=0;i<40;i++)printf(" ");
			loop1:gotoxy(9+60+2,2);printf("姓名：");
				if(!scanf("%s",&name))
				{
					gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
					gotoxy(11,2);printf("输入错误，请重新输入。");
					fflush(stdin);
					goto loop1;
				}
				p=head;
				while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
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
							gotoxy(11,2);printf("%s有重名，序号为%hd,",temp->name,temp->number);
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
				loop3:gotoxy(9+60+2,2);printf("序号：");
					if(!scanf("%hd",&number)||number>buf)
					{
						gotoxy(9+60+6+2,2);printf("    ");
						gotoxy(9+80+2,2);printf("错误，重新输入！");
						fflush(stdin);
						goto loop3;
					}
					p=head;
					for(i=0;buf-number>i;i++)	//p指向指定节点
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
					gotoxy(11,2);printf("没有查到该校友。");
				}
				p=head;
				break;
			}
			if(89*Pixel.width-Pixel.width/2<x&&x<100*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height+-Pixel.height/2)//点击输入序号
			{
				uint16 i;
				int16 number;
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(9+60-4,2);
				for(i=0;i<40;i++)printf(" ");
			loop2:gotoxy(9+60+2,2);printf("序号：");
				if(!scanf("%hd",&number)||number>buf)
				{
					gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
					gotoxy(11,2);printf("输入错误或无此序号，请重新输入。");
					fflush(stdin);
					goto loop2;
				}
				for(i=0;buf-number>i;i++)	//p指向指定节点
					p=p->link_ahead;
				system("cls");
				data_display_form2(p);
				p=head;
				break;
			}
		}

	}
/******************跳转返回***********************/
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto return_loop;
			}
			
		}
	}
/******************跳转返回结束***********************/
}



/************

2.排序查看

*************/
/*————————————————————————————————*/


void data_display_pro_switch_data(ALUMNI *pi,ALUMNI *pj)			//交换节点数据函数
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
void data_display_pro_form1(int16 *judgment)//排序方式选择表格
{
	uint16 i;
	POINT *point;		//声明POINT结构体类存储鼠标坐标
	LPRECT rect;		//声明LPRECT结构体指针存储窗口坐标信息
	HWND hwnd=FindWindow(NULL,"大工杰出校友信息管理系统");	//查找句柄之后保存在这里
	point=(POINT*)malloc(sizeof(POINT)+64);					//分配内存
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//为结构体指针分配内存空间
	//1行******************
	gotoxy(10,1);
	printf("┏");for(i=0;i<100;i++)printf("━");printf("┓");
//2行******************
	gotoxy(10,2);printf("┃");
	gotoxy(9+50-6,2);printf("请选择排序方式");
	//姓名9+60+2,2
	gotoxy(111,2);printf("┃");
//3行******************
	gotoxy(10,3);
	printf("┗");for(i=0;i<100;i++)printf("━");printf("┛");
	rectangle(15,4,20,3);gotoxy(24,5);printf("姓名");
	rectangle(39,4,20,3);gotoxy(48-2,5);printf("入学年份");
	rectangle(63,4,20,3);gotoxy(72-2,5);printf("在校身份");
	rectangle(87,4,20,3);gotoxy(96,5);printf("系别");
	gotoxy(1,1);
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(15*Pixel.width-Pixel.width/2<x&&x<35*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//点击姓名
			{*judgment=0;break;}
			if(39*Pixel.width-Pixel.width/2<x&&x<59*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//点击入学年份
			{*judgment=1;break;}
			if(63*Pixel.width-Pixel.width/2<x&&x<83*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//点击在校身份
			{*judgment=2;break;}
			if(87*Pixel.width-Pixel.width/2<x&&x<107*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//点击系别
			{*judgment=3;break;}
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击首页
			{*judgment=-1;break;}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{*judgment=-1;break;}
		}
	}
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");//清空原有文字
	gotoxy(10,4);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,5);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,6);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(1,1);
	return;
}
void data_display_pro_form2(ALUMNI *head,int16 *judgment,uint16 buf)//排序查看简略信息表格
{
	/*提供显示的光标位置*/
	//序号9+90+2,2
	uint16 i,k;
	ALUMNI *pi,*pj,*p=head;			//用于简单选择排序
	uint16 name_i;					//用于姓名输出的循环量
	uint16 x=10,y=4,upper=4;		//upper是表格上界，x，y是绝对光标坐标
//2行******************
	switch(*judgment)
	{
		case 0:gotoxy(9+50-6,2);printf("校友姓名排序查看");break;
		case 1:gotoxy(9+50-8,2);printf("校友入学年份排序查看");break;
		case 2:gotoxy(9+50-8,2);printf("校友在校身份排序查看");break;
		case 3:gotoxy(9+50-6,2);printf("校友系别排序查看");break;
	}
	for(pi=head;pi->link_ahead!=NULL;pi=pi->link_ahead)		//p指向最后一个节点，即为最先输入的节点
		for(pj=pi->link_ahead;pj!=NULL;pj=pj->link_ahead)
			switch(*judgment)
			{
				case 0:if(strcmp(pj->name,pi->name)>0)data_display_pro_switch_data(pi,pj);break;
				case 1:if(pj->year>pi->year)data_display_pro_switch_data(pi,pj);break;
				case 2:if(strcmp(pj->identity,pi->identity)>0)data_display_pro_switch_data(pi,pj);break;
				case 3:if(strcmp(pj->department,pi->department)>0)data_display_pro_switch_data(pi,pj);break;
			}
	while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
		p=p->link_ahead;
	for(k=1;buf>=k;k++)
	{
		if(!(y>upper+24&&x==61))
		{
			if(y==upper)
			{
				gotoxy(x+2,y);printf("序号");
				gotoxy(x+22,y);
					switch(*judgment)
				{
					case 0:gotoxy(x+20,y);printf("姓名");break;
					case 1:gotoxy(x+10,y);printf("姓名");gotoxy(x+20,y);printf("入学年份");break;
					case 2:gotoxy(x+10,y);printf("姓名");gotoxy(x+20,y);printf("在校身份");break;
					case 3:gotoxy(x+10,y);printf("姓名");gotoxy(x+20,y);printf("系别");break;
				}
				gotoxy(x,y+1);
				printf("┏");for(i=0;i<49;i++)printf("━");printf("┓");
				y+=2;
			}
			if(y<=upper+24)
			{
				if(y-2!=upper)
				{
					gotoxy(x,y-1);printf("┣");
					gotoxy(x+50,y-1);printf("┫");
				}
				gotoxy(x,y);printf("┃ %u",p->number);
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
				gotoxy(x+50,y);printf("┃");
				gotoxy(x,y+1);
				printf("┗");for(i=0;i<49;i++)printf("━");printf("┛");
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

void data_display_pro()//信息排序查看函数
{
	
	FILE *fp;			//作用于文件
	ALUMNI *head,*p;	//链表表头指针，链表扩充节点指针
	uint16 i;			//自增循环使用
	POINT *point;		//声明POINT结构体类存储鼠标坐标
	LPRECT rect;		//声明LPRECT结构体指针存储窗口坐标信息
	int16 judgment;		//表格中鼠标点击位置判断
	uint16 buf;								//数据块数量
	HWND hwnd=FindWindow(NULL,"大工杰出校友信息管理系统");	//查找句柄之后保存在这里
	point=(POINT*)malloc(sizeof(POINT)+64);					//分配内存
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);					//为结构体指针分配内存空间
	fp=fopen("data.dat","rb");
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	if(fread(p,sizeof(ALUMNI),1,fp))
	{
		p->link_ahead=NULL;
		head=p;
		while(1)//将文件的数保存到链表里
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
		gotoxy(10,4);printf("还没有信息。");
		for(i=3;i>0;i--)
		{
			printf("%hd秒后返回上一步……",i);
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
	Sleep(50);									//防止连续点击效应
	data_display_pro_form2(head,&judgment,buf);
/******************跳转返回***********************/
	return_key();
	rectangle(112,4,6,3);
	gotoxy(114,5);printf("详查");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				goto return_loop;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&4*Pixel.height-Pixel.height/2<y&&y<6*Pixel.height-Pixel.height/2)//点击详细查看
			{
				uint16 i;
				int16 number;
				gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
				gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,4);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,5);for(i=0;i<7;i++)printf(" ");//清空原有文字
				gotoxy(112,6);for(i=0;i<7;i++)printf(" ");//清空原有文字
		loop1:	gotoxy(11,2);printf("请输入需要查看信息的校友序号：");
				if(!scanf("%hd",&number)||number>buf)
				{
					gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
					gotoxy(9+80+2,2);printf("错误，重新输入！");
					fflush(stdin);
					goto loop1;
				}
				p=head;
				for(i=0;i<buf;i++)	//p指向指定节点
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
/******************跳转返回结束***********************/
/******************跳转返回***********************/
	return_key();
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击首页
			{
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				rectangle(10,1,100,3);
				goto return_loop2;
			}
		}
	}
/******************跳转返回结束***********************/
}