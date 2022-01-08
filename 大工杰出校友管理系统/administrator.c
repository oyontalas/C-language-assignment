#include "include.h"



/************

功能1.添加新信息

*************/
/*————————————————————————————————*/

void data_saveing_form()//表格
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
//1行******************
	gotoxy(10,1);
	printf("┏");for(i=0;i<100;i++)printf("━");printf("┓");

//2行******************
	gotoxy(10,2);printf("┃");
	gotoxy(9+50-4,2);printf("校友信息");
	gotoxy(9+100-9,2);printf("序号：");
	//序号9+100-6,2  3
	gotoxy(111,2);printf("┃");
	
//3行******************
	gotoxy(10,3);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");

//4行******************
	gotoxy(10,4);printf("┃姓名┃");
	//姓名10+6,4  20
	gotoxy(10+6+20,4);printf("┃入学年份┃");
	//入学年份10+6+20+10,4  5
	gotoxy(10+6+20+10+5,4);printf("┃在校身份┃");
	//在校身份10+6+20+10+5+10，4 20
	gotoxy(10+6+20+10+5+10+20,4);printf("┃系别┃");
	//系别10+6+20+10+5+10+20+6，,4 20
	gotoxy(111,4);printf("┃");

//5行******************
	gotoxy(10,5);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10+5,3);printf("┰");
	gotoxy(10+6+20,3);printf("┰");
	gotoxy(10+6+20+9,3);printf("┰");
	gotoxy(10+6+20+10+5,3);printf("┰");
	gotoxy(10+6+20+10+5+9,3);printf("┰");
	gotoxy(10+6+20+10+5+10+20,3);printf("┰");
	gotoxy(10+6+20+10+5+10+20+5,3);printf("┰");
	gotoxy(10+5,5);printf("┸");
	gotoxy(10+6+20,5);printf("┸");
	gotoxy(10+6+20+9,5);printf("┸");
	gotoxy(10+6+20+10+5,5);printf("┸");
	gotoxy(10+6+20+10+5+9,5);printf("┸");
	gotoxy(10+6+20+10+5+10+20,5);printf("┸");
	gotoxy(10+6+20+10+5+10+20+5,5);printf("┸");

//6行******************
	gotoxy(10,6);printf("┃研究方向┃");
	//研究方向10+10,6
	gotoxy(111,6);printf("┃");

//7行******************
	gotoxy(10,7);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10+9,5);printf("┰");
	gotoxy(10+9,7);printf("┸");

//8-26行******************
	for(i=8;i<=26;i++)
	{
		gotoxy(10,i);printf("┃");
		gotoxy(111,i);printf("┃");
	}

//8，14，19，24行******************
	gotoxy(10,8);printf("┃简介：");
	//简介10+8,8
	gotoxy(10,14);printf("┃主要成就1:");
	//主要成就1 10+12,14
	gotoxy(10,19);printf("┃主要成就2:");
	//主要成就2 10+12,19
	gotoxy(10,24);printf("┃主要成就3:");
	//主要成就3 10+12,24

//13，18，23行******************
	gotoxy(10,13);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10,18);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10,23);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");

//27行******************
	gotoxy(10,27);
	printf("┗");for(i=0;i<100;i++)printf("━");printf("┛");
}
uint16 data_saveing_get_string(uint16 i,int8 *string)//对应于表格有转行功能的字符数组赋值函数
{
	uint16 j;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
	for(j=0;(string[j]=getch())!='\r';j++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		switch(i)
		{
		case 0:if(csbi.dwCursorPosition.X+1>10+6+20-2)gotoxy(10+7,4);printf("%c",string[j]);break;
		case 2:if(csbi.dwCursorPosition.X+1>10+6+20+10+5+10+20-2)gotoxy(10+6+20+10+5+11,4);printf("%c",string[j]);break;
		case 3:if(csbi.dwCursorPosition.X+1>110)gotoxy(10+6+20+10+5+10+20+6,4);printf("%c",string[j]);break;
		case 4:if(csbi.dwCursorPosition.X+1>110)gotoxy(10+11,6);printf("%c",string[j]);break;
		case 5:if(csbi.dwCursorPosition.X+1>110)gotoxy(11, csbi.dwCursorPosition.Y+2);
				if(csbi.dwCursorPosition.Y+1==13)gotoxy(10+7,8);printf("%c",string[j]);break;
		case 6:if(csbi.dwCursorPosition.X+1>110)gotoxy(11, csbi.dwCursorPosition.Y+2);
				if(csbi.dwCursorPosition.Y+1==18)gotoxy(10+11,14);printf("%c",string[j]);break;
		case 7:if(csbi.dwCursorPosition.X+1>110)gotoxy(11, csbi.dwCursorPosition.Y+2);
				if(csbi.dwCursorPosition.Y+1==23)gotoxy(10+11,19);printf("%c",string[j]);break;
		case 8:if(csbi.dwCursorPosition.X+1>110)gotoxy(11, csbi.dwCursorPosition.Y+2);
				if(csbi.dwCursorPosition.Y+1==27)gotoxy(10+11,24);printf("%c",string[j]);break;
		}
	}
	string[j]='\0';//printf("%s",string);
	return 1;
}
void data_saveing_input(uint16 i,ALUMNI *p,uint16 *judgment)//辅助data_saveing输入的函数，并对判断条件赋值
{
	fflush(stdin);
	switch(i)
	{
	case 0:gotoxy(10+7,4);judgment[0]=data_saveing_get_string(0,p->name);break;
	case 1:gotoxy(10+6+20+10,4);judgment[1]=scanf("%hd",&(p->year));break;
	case 2:gotoxy(10+6+20+10+5+10,4);judgment[2]=data_saveing_get_string(2,p->identity);break;
	case 3:gotoxy(10+6+20+10+5+10+20+6,4);judgment[3]=data_saveing_get_string(3,p->department);break;
	case 4:gotoxy(10+11,6);judgment[4]=data_saveing_get_string(4,p->desearch_areas);break;
	case 5:gotoxy(10+7,8);judgment[5]=data_saveing_get_string(5,p->introduction);break;
	case 6:gotoxy(10+11,14);judgment[6]=data_saveing_get_string(6,p->major_achievements[0]);break;
	case 7:gotoxy(10+11,19);judgment[7]=data_saveing_get_string(7,p->major_achievements[1]);break;
	case 8:gotoxy(10+11,24);judgment[8]=data_saveing_get_string(8,p->major_achievements[2]);break;
	}
}
void data_saving()
{
	FILE *fp;//作用于即将保存的文件
	ALUMNI *head,*p;//链表表头指针，链表扩充节点指针
	uint16 i;//自增循环量，没有含义
	uint16 judge=0;//判断输入结束
	uint16 judgment[9];//输入成功与否的判断按条件
	POINT *point;//声明POINT结构体类存储鼠标坐标
	LPRECT rect;//声明LPRECT结构体指针存储窗口坐标信息
	HWND hwnd=FindWindow(NULL,"大工杰出校友信息管理系统");//查找句柄之后保存在这里
	point=(POINT*)malloc(sizeof(POINT)+64);//分配内存
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);//为结构体指针分配内存空间
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	p->link_back=NULL;
	p->link_ahead=NULL;
	head=p;
	data_saveing_form();
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("是否确定开始添加信息？");
	return_key();
	gotoxy(5,2);printf("开始");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击开始
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				return;
			}
		}
	}
	while(1)
	{
		data_saveing_form();
		gotoxy(10,28);printf("提示：请认真输入，输入一字即保存一字。");
		gotoxy(9+100-9,2);printf("      ");
loop2:
		for(i=0;i<9;i++)
			data_saveing_input(i,p,judgment);
loop1:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
		for(i=0;i<9;i++)
			if(!judgment[i])
				break;
		if(i!=9)
		{
			gotoxy(10,28);
			printf("您输入的校友的");
			for(i=0;i<9;i++)
				if(!judgment[i])
					printf("%s，",title[i]);
			printf("\b\b信息有误，请重新输入。");
			gotoxy(1,1);
			for(i=0;i<9;i++)
				if(!judgment[i])
					data_saveing_input(i,p,judgment);
			goto loop1;
		}
return_loop2:
		gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//清空原有文字
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(34,28);
		printf("┏");for(i=0;i<10;i++)printf("━");printf("┓");
		printf("┏");for(i=0;i<10;i++)printf("━");printf("┓");
		printf("┏");for(i=0;i<10;i++)printf("━");printf("┓");
		gotoxy(10,29);printf("输入成功。是否继续输入？");printf("┃  继续输入┃┃  结束输入┃┃  修改信息┃               Ctrl+Alt键快捷继续输入。。");
		gotoxy(34,30);
		printf("┗");for(i=0;i<10;i++)printf("━");printf("┛");
		printf("┗");for(i=0;i<10;i++)printf("━");printf("┛");
		printf("┗");for(i=0;i<10;i++)printf("━");printf("┛");
		gotoxy(1,1);
		while(1)
		{
			GetWindowRect(hwnd,rect);
			GetCursorPos(point);

			if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
			{
				int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
				if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//点击继续输入
				{
					system("cls");
					p=(ALUMNI *)malloc(sizeof(ALUMNI));
					p->link_ahead=head;
					head->link_back=p;
					head=p;
					p->link_back=NULL;
					goto loop_continue;
				}
				if(45*Pixel.width+Pixel.width/2<x&&x<56*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//点击结束输入
	return_loop1:{
					ALUMNI temp;//保存数据块，并提取序号
					fp=fopen("data.dat","rb");	//判断是否为空文件，
					fseek(fp,0,SEEK_END);
					if(ftell(fp)==NULL)			//如果是的话，序号从1开始
						i=1;
					else						//如果不是，提取最后buf的序号
					{				
						fseek(fp,-sizeof(ALUMNI),SEEK_END);//提取序号
						fread(&temp,sizeof(ALUMNI),1,fp);
						i=temp.number+1;
						
					}
					fclose(fp);	
					fp=fopen("data.dat","ab+");
					fseek(fp,0,SEEK_END);
					while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
						p=p->link_ahead;
					while(p!=NULL)				//开始依次保存到文件里
					{
						p->number=i;
						fwrite(p,sizeof(ALUMNI),1,fp);
						p=p->link_back;
						i++;
					}
					fclose(fp);
					gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(10,28);printf("保存成功！");
					for(i=3;i>0;i--)
					{
						printf("%hd秒后返回首页……",i);
						Sleep(1000);
						printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					}
					judge++;
					break;
				}
				if(57*Pixel.width+Pixel.width/2<x&&x<68*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//点击修改信息
				{
					break;
					gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
					gotoxy(1,1);
					goto loop2;//返回到输入阶段
				}
			}

			if(GetAsyncKeyState(VK_MENU)&&GetAsyncKeyState(VK_CONTROL))           //ctrl+alt，继续输入
			{
				system("cls");
				p=(ALUMNI *)malloc(sizeof(ALUMNI));
				p->link_ahead=head;
				head->link_back=p;
				head=p;
				p->link_back=NULL;
				goto loop_continue;
			}
		}
		if(judge)//退出函数
		{system("cls");break;}
		loop_change2:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);printf("请点击需要修改的信息的框图。");
		gotoxy(1,1);
		while(1)
		{
			GetWindowRect(hwnd,rect);
			GetCursorPos(point);
			if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
			{
				int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
				if(11*Pixel.width-Pixel.width/2<x&&x<(10+6+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入姓名
					{data_saveing_input(0,p,judgment);break;}
				if((10+6+20)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入入校年份
					{data_saveing_input(1,p,judgment);break;}
				if((10+6+20+10+5)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入在校身份
					{data_saveing_input(2,p,judgment);break;}
				if((10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入系别
					{data_saveing_input(3,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&5*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击输入研究领域
					{data_saveing_input(4,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<14*Pixel.height-Pixel.height/2)//点击输入简介
					{data_saveing_input(5,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&13*Pixel.height-Pixel.height/2<y&&y<18*Pixel.height-Pixel.height/2)//点击输入主要成就1
					{data_saveing_input(6,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击输入主要成就2
					{data_saveing_input(7,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<27*Pixel.height-Pixel.height/2)//点击输入主要成就3
					{data_saveing_input(8,p,judgment);break;}
			}
		}
		loop_change1:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
		for(i=0;i<9;i++)
			if(!judgment[i])
				break;
		if(i!=9)
		{
			gotoxy(10,28);
			printf("您输入的校友的");
		for(i=0;i<9;i++)
				if(!judgment[i])
					printf("%s，",title[i]);
			printf("\b\b信息有误，请重新输入。");
			gotoxy(1,1);
			for(i=0;i<9;i++)
				if(!judgment[i])
					data_saveing_input(i,p,judgment);
			goto loop_change1;
		}
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
		gotoxy(34,28);printf("┏");for(i=0;i<10;i++)printf("━");printf("┓");
		gotoxy(10,29);printf("修改成功。是否继续修改？");printf("┃  继续修改┃");
		gotoxy(34,30);printf("┗");for(i=0;i<10;i++)printf("━");printf("┛");
		gotoxy(1,1);
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
					goto return_loop1;
				}
				if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
				{
					goto return_loop2;
				}
				if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)	//点击继续修改
					goto loop_change2;
			}
		}
	/******************跳转返回结束***********************/
	loop_continue:;
	}
}
/*————————————————————————————————*/



/************

功能2.修改信息

*************/
/*————————————————————————————————*/

void data_change_form(ALUMNI *p)	//查看详细信息表格
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
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);//获取光标位置信息
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
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
	gotoxy(10,4);printf("┃姓名┃ ");
	//姓名10+6,4  20
	for(i=0;p->name[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//获取光标位置信息
		if(csbi.dwCursorPosition.X+1>10+6+20-2)
		{
			break;
		}
		printf("%c",p->name[i]);
	}
	gotoxy(10+6+20,4);printf("┃入学年份┃");
	//入学年份10+6+20+10,4  5
	gotoxy(10+6+20+10+5,4);printf("┃在校身份┃");
	//在校身份10+6+20+10+5+10，4 20
	gotoxy(10+6+20+10+5+10+20,4);printf("┃系别┃");
	//系别10+6+20+10+5+10+20+6，,4 20
	gotoxy(111,4);printf("┃");

//5行******************
	gotoxy(10,5);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10+5,3);printf("┰");
	gotoxy(10+6+20,3);printf("┰");
	gotoxy(10+6+20+9,3);printf("┰");
	gotoxy(10+6+20+10+5,3);printf("┰");
	gotoxy(10+6+20+10+5+9,3);printf("┰");
	gotoxy(10+6+20+10+5+10+20,3);printf("┰");
	gotoxy(10+6+20+10+5+10+20+5,3);printf("┰");
	gotoxy(10+5,5);printf("┸");
	gotoxy(10+6+20,5);printf("┸");
	gotoxy(10+6+20+9,5);printf("┸");
	gotoxy(10+6+20+10+5,5);printf("┸");
	gotoxy(10+6+20+10+5+9,5);printf("┸");
	gotoxy(10+6+20+10+5+10+20,5);printf("┸");
	gotoxy(10+6+20+10+5+10+20+5,5);printf("┸");

//6行******************
	gotoxy(10,6);printf("┃研究方向┃");
	//研究方向10+10,6
	gotoxy(111,6);printf("┃");

//7行******************
	gotoxy(10,7);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10+9,5);printf("┰");
	gotoxy(10+9,7);printf("┸");

//8-26行******************
	for(i=8;i<=26;i++)
	{
		gotoxy(10,i);printf("┃");
		gotoxy(111,i);printf("┃");
	}

//8，14，19，24行******************
	gotoxy(10,8);printf("┃简介：");
	//简介10+8,8
	gotoxy(10,14);printf("┃主要成就1:");
	//主要成就1 10+12,14
	gotoxy(10,19);printf("┃主要成就2:");
	//主要成就2 10+12,19
	gotoxy(10,24);printf("┃主要成就3:");
	//主要成就3 10+12,24

//13，18，23行******************
	gotoxy(10,13);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10,18);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");
	gotoxy(10,23);printf("┠");
	for(i=0;i<100;i++)
		printf("┈");
	printf("┨");

//27行******************
	gotoxy(10,27);
	printf("┗");for(i=0;i<100;i++)printf("━");printf("┛");
	gotoxy(1,1);
}
void data_change()//修改数据函数
{
	FILE *fp;			//作用于文件
	ALUMNI *head,*p;	//链表表头指针，链表扩充节点指针
	uint16 i;			//自增循环使用
	uint16 judgment[9];	//输入成功与否的判断按条件
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
			printf("%hd秒后返回首页……",i);
			Sleep(1000);
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		}
		system("cls");
		fclose(fp);
		return;
	}
	fclose(fp);
	buf=head->number;
return_loop:
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("是否确定开始修改？");
	return_key();
	gotoxy(5,2);printf("开始");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击开始
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				return;
			}
		}
	}
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("请输入需要修改信息的校友序号；");
	{
		int16 number;
loop3:	if(!scanf("%hd",&number)||number>buf)
		{
			gotoxy(9+60+6+2,2);printf("    ");
			gotoxy(9+80+2,2);printf("错误，重新输入！");
			fflush(stdin);
			goto loop3;
		}
		p=head;
		for(i=0;buf-number>i;i++)	//p指向指定节点
			p=p->link_ahead;
	}
	system("cls");
	data_change_form(p);
loop2:
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,29);printf("请点击需要修改的信息的框图。");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(11*Pixel.width-Pixel.width/2<x&&x<(10+6+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入姓名
				{data_saveing_input(0,p,judgment);break;}
			if((10+6+20)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入入校年份
				{data_saveing_input(1,p,judgment);break;}
			if((10+6+20+10+5)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入在校身份
				{data_saveing_input(2,p,judgment);break;}
			if((10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//点击输入系别
				{data_saveing_input(3,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&5*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//点击输入研究领域
				{data_saveing_input(4,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<14*Pixel.height-Pixel.height/2)//点击输入简介
				{data_saveing_input(5,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&13*Pixel.height-Pixel.height/2<y&&y<18*Pixel.height-Pixel.height/2)//点击输入主要成就1
				{data_saveing_input(6,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//点击输入主要成就2
				{data_saveing_input(7,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<27*Pixel.height-Pixel.height/2)//点击输入主要成就3
				{data_saveing_input(8,p,judgment);break;}
		}
	}
	loop1:
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
	for(i=0;i<9;i++)
		if(!judgment[i])
			break;
	if(i!=9)
	{
		gotoxy(10,28);
		printf("您输入的校友的");
	for(i=0;i<9;i++)
			if(!judgment[i])
				printf("%s，",title[i]);
		printf("\b\b信息有误，请重新输入。");
		gotoxy(1,1);
		for(i=0;i<9;i++)
			if(!judgment[i])
				data_saveing_input(i,p,judgment);
		goto loop1;
	}
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
	gotoxy(34,28);printf("┏");for(i=0;i<10;i++)printf("━");printf("┓");
	gotoxy(10,29);printf("修改成功。是否继续修改？");printf("┃  继续修改┃               Ctrl+Alt键快捷继续输入。。");
	gotoxy(34,30);printf("┗");for(i=0;i<10;i++)printf("━");printf("┛");
	gotoxy(1,1);
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
				fp=fopen("data.dat","wb");
				while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
					p=p->link_ahead;
				while(p!=NULL)				//开始依次保存到文件里
				{
					fwrite(p,sizeof(ALUMNI),1,fp);
					p=p->link_back;
					i++;
				}
				fclose(fp);
				gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,28);printf("保存成功！");
				for(i=3;i>0;i--)
				{
					printf("%hd秒后返回首页……",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//清空原有文字
				gotoxy(10,28);printf("修改成功！");
				for(i=3;i>0;i--)
				{
					printf("%hd秒后返回上一步……",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				system("cls");
				goto return_loop;
			}
			if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)	//点击继续修改
				goto loop2;
		}
		if(GetAsyncKeyState(VK_MENU)&&GetAsyncKeyState(VK_CONTROL))																					//ctrl+alt，继续继续修改
			goto loop2;
	}
/******************跳转返回结束***********************/
}



/************

功能3.删除信息

*************/
/*————————————————————————————————*/

void data_delete()//信息删除函数
{
	FILE *fp;			//作用于文件
	ALUMNI *head,*p;	//链表表头指针，链表扩充节点指针
	uint16 i;			//自增循环使用
	POINT *point;		//声明POINT结构体类存储鼠标坐标
	LPRECT rect;		//声明LPRECT结构体指针存储窗口坐标信息
	int16 judgment;		//表格中鼠标点击位置判断
	uint16 buf;			//数据块数量
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
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("是否确定开始删除？");
	return_key();
	gotoxy(5,2);printf("开始");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//如果鼠标左键按下
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//鼠标点击位置对于控制台的相对坐标
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击开始
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//点击返回上一层
			{
				system("cls");
				return;
			}
		}
	}
return_loop:
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
loop3:gotoxy(11,2);printf("请输入需要删除信息的校友序号；");
	{
		int16 number;
		if(!scanf("%hd",&number)||number>buf)
		{
			gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
			gotoxy(9+80+2,2);printf("错误，重新输入！");
			fflush(stdin);
			goto loop3;
		}
		p=head;
		for(i=0;buf-number>i;i++)	//p指向指定节点
			p=p->link_ahead;
	}
	system("cls");
	if(p->link_back!=NULL&&p->link_ahead!=NULL)
	{
		p->link_ahead->link_back=p->link_back;
		p->link_back->link_ahead=p->link_ahead;
	}
	else
	{
		if(p==head)
		{
			head=p->link_ahead;
			p->link_ahead->link_back=NULL;
		}
		else
			p->link_back->link_ahead=NULL;
	}
	buf--;
	p=head;
	for(i=buf;i>0;p=p->link_ahead,i--)
		p->number=i;
	system("cls");
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("是否继续删除？");
/******************跳转返回***********************/
	return_key();
	gotoxy(114,2);printf("继续");
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
				fp=fopen("data.dat","wb");
				p=head;
				while(p->link_ahead!=NULL)	//p指向最后一个节点，即为最先输入的节点
					p=p->link_ahead;
				i=1;
				while(p!=NULL)				//开始依次保存到文件里
				{
					p->number=i;
					fwrite(p,sizeof(ALUMNI),1,fp);
					p=p->link_back;
					i++;
				}
				fclose(fp);
				gotoxy(10,3);printf("删除成功！");
				for(i=3;i>0;i--)
				{
					printf("%hd秒后返回首页……",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//继续删除
			{
				system("cls");
				goto return_loop;
			}
		}
	}
/******************跳转返回结束***********************/
}




/************

数据复原函数				*****谨慎使用*****

*************/
/*————————————————————————————————*/
void renew()//将数据初始化，防止不当操作操作导致数据丢失
{
	FILE *fp;			//作用于文件
	//ALUMNI *head,*p;	//链表表头指针，链表扩充节点指针
	ALUMNI alumni1={/*序号*/1,/*入学年份*/1984,/*姓名*/"申长雨",/*在校身份*/"大连理工大学校长（副部长级）",/*系别*/"化工",/*研究领域*/"高分子及其复合材料成型加工、模具优化设计与制造等领域的理论、技术和数值模拟方法的研究工作",/*简介*/"申长雨，中共党员，汉族，1963年6月出生，河南南阳人，中国科学院院士，国家杰出青年科学基金获得者，“973”项目首席科学家。现任国家市场监督管理总局党组成员，国家知识产权局局长、党组书记。",/*主要成就1*/"塑料成型过程数值模拟。申长雨院士发展了注塑成型三维流动、保压、冷却、翘曲变形等过程的数理模型和数值计算方法，特别是注塑、注压、微注塑等成型过程充填/保压的数学模型、冷却分析的边界元计算理论，内应力与制品翘曲变形、成型和模具一体化、透明塑料成型与光学行为预测等计算理论和方法，耦合结晶、取向等微结构演化的多尺度分析理论等；主持开发出自主知识产权塑料模CAE软件。 [9]  作为第一完成人，相关成果“注塑成型模具及制品设计与分析过程的计算机集成技术”获得1996年度国家科技进步二等奖。",/*主要成就2*/"塑料模具优化设计与制造。申长雨院士构建了塑料成型非线性、稳态和瞬态、耦合和非耦合系统的设计灵敏度分析的基本理论和算法，特别是注塑模冷却系统灵敏度边界元分析理论，熔体前沿位置、速度和压力对设计变量影响的形状灵敏度有限元分析理论等；发展了面向服役行为的成型工艺、模具设计以及制品结构设计的一体化优化模型，以及基于制品结构形态和性能控制的成型工艺优化和多目标模具优化设计理论和方法，解决了系列塑料结构制品“成型”、“成性”、“服役性”和“工艺控制及模具优化”等关键问题。 [9]  作为第一完成人，相关成果“基于模拟仿真的聚合物加工及模具优化设计与应用”获得2003年度国家科技进步二等奖。 [10]",/*主要成就3*/"国家战略产品的研制。申长雨院士主持完成了“神七”出舱航天服头盔面窗的研制，所研制的头盔面窗具备了高低温环境下的高抗冲击性能、恶劣环境下的防辐射能力和高光谱透过率等特殊功能，为我国航天出舱活动做出了突出贡献 [11]  ，2009年荣获“中国载人航天工程突出贡献奖”。 [8]  在此基础上，研制团队又承担完成了我国“神九”和 “神十一”交会航天员头盔面窗、太空工作站航天面窗的研制任务，解决了航天制品的高速冲击行为的试验与数值计算理论、高低温环境条件下热和力历史—微结构—寿命关联机制、复杂环境下的服役行为预测等关键难题，为我国航天员中期在轨驻留提供了保障。研制团队获得了“空间实验室任务贡献突出的外协单位”（2017年） [12]  。除了航天战略产品的研制外，研制团队目前还主持承担着我国多个战略产品的研制任务，已成为我国战略用高分子及其复合材料产品研制的重要力量。 [2]"};
	ALUMNI alumni2={/*序号*/2,/*入学年份*/1977,/*姓名*/"傅育宁",/*在校身份*/"大连理工大学学士",/*系别*/"海洋工程力学",/*研究领域*/"石油",/*简介*/"傅育宁，1957年3月出生，英国布鲁诺尔大学海洋工程学博士。此前任招商局集团有限公司董事长、招商局国际有限公司主席、招商银行董事长、中国南山开发（集团）股份有限公司董事长等。曾任深圳赤湾石油基地股份有限公司常务副总经理、赤湾港航股份有限公司董事长、中国南山开发（集团）股份有限公司总经理、香港友联银行有限公司主席、招商局集团有限公司副总裁、招商局集团有限公司总裁、等职务",/*主要成就1*/"2010年8月23日，招商局集团有限公司在香港召开干部大会，宣布免去秦晓招商局集团董事长职务，由傅育宁接任。同时免去傅育宁招商局集团总裁职务，任命李建红担任招商局集团董事、总裁。",/*主要成就2*/"2014年4月，调任华润（集团）有限公司董事长，不再担任招商局集团董事长职务。",/*主要成就3*/"2020年7月，不再担任华润（集团）有限公司董事长职务。"};
	ALUMNI alumni3={/*序号*/3,/*入学年份*/1984,/*姓名*/"向文波",/*在校身份*/"大连理工大学学士",/*系别*/"材料专业",/*研究领域*/"工程建设机械",/*简介*/"向文波，工程机械专家、高级工程师，现任三一重工股份有限公司总裁。1984年毕业于湖南大学机械工程铸造专业，获工学学士学位， 毕业后被分配到了兵器工业部洪源机械厂九分厂，曾任涟源市阀门厂厂长。向文波又先后在大连理工大学材料专业和中欧国际商学院工商管理专业学习，获工学硕士学位，中国工程机械工业协会和中国建设机械工业协会常务理事、国务院中外企业集团发展研究中心第一届理事会理事、湖南省世界贸易组织研究会理事、美国设备制造商协会会员、湖南交通职业技术学院兼职副院长、长沙市工商联合会副会长、长沙市民营经济研究会副会长。2002年，向文波先生荣获“中国优秀民营科技企业家奖”、“2002年紫荆花杯杰出企业家奖”。2012年10月1日，三一集团在美起诉奥巴马和CFIUS，18日向文波在北京召开媒体沟通会，有关专家称，外国公司起诉美国外资委是该机构成立以来的第一次，史无前例。",/*主要成就1*/"三一重工股份有限公司是中国工程机械行业第一家上市的民营企业、也是湖南省第一家上市的民营企业，主导产品为工程建设机械。混凝土机械在中国市场占有率第一，已完全替代了进口。",/*主要成就2*/"2010年度CCTV“中国经济年度人物”20名候选人名单正式揭开面纱，呼声最高的三一重工总裁向文波却意外落选。虽然止步于正式候选人，却无损向文波“经济博客第一人”的价值。在“年度财经博客”评选中，向文波以压倒性优势始终稳坐冠军宝座，与其他竞争对手相比，其接近50%的网络支持率让向文波成为新浪“年度财经博客”得奖呼声最高的人。",/*主要成就3*/"2011年5月31日，日本共同通信社、日本经济新闻社、朝日新闻、产经新闻等20余家日本权威主流媒体团到访三一重工长沙产业园。据悉，日本媒体团此番到访，一方面为了感谢对核电站施以援手的中国救援力量，另一方面也是为了让日本民众进一步了解“三一重工”这家中国企业。"};
	ALUMNI alumni4={/*序号*/4,/*入学年份*/1997,/*姓名*/"司勇",/*在校身份*/"大连理工大学学士",/*系别*/"机械工程学院机械设计制造及其自动化专业",/*研究领域*/"精密仪器与机械学系机械工程",/*简介*/"司勇，男，汉族，1979年12月生，河南驻马店人，1998年12月入党，2004年8月参加工作，研究生学历，硕士学位。现任共青团江苏省委书记。",/*主要成就1*/"2018年04月——2019年01月，南京市秦淮区委副书记，区政府副区长、代理区长",/*主要成就2*/"2019年01月——2020年05月，南京市秦淮区委副书记、区长",/*主要成就3*/"2020年05月——，共青团江苏省委书记。"};
	ALUMNI alumni5={/*序号*/5,/*入学年份*/2004,/*姓名*/"帕孜来提·木特里甫",/*在校身份*/"建筑学学士",/*系别*/"建筑与艺术学",/*研究领域*/"设计",/*简介*/"帕孜来提·木特里甫出生在乌鲁木齐，父亲是老师，母亲是医生，家里还有两个妹妹，一个妹妹已经工作，另一个妹妹还在上大学。帕孜来提·木特里甫说，家里对我们从小严格要求，记得在很小的时候家里就锻炼我们的独立能力，以至于从小到大，很多事情都是自己做决定，比如：上什么大学，找什么工作，大学毕业后是留在内地还是回新疆，这些对于成长中的“终身大事”，都是自己拿主意。对于未来，帕孜来提·木特里甫说，“想在30岁之前结婚生子，还想让自己学习更多知识，有想过考研究生，无论考不考研究生，我一定要报考‘一级注册建筑师’，从业3年以上的才能报考的，我已工作两年，还有一年时间，利用这一年我打算好好复习，争取一次通过。”",/*主要成就1*/"喀什老城区阿霍街坊改造，一米大视场光学天文望远镜观测室，80厘米中高轨空间碎片观测望远镜观测室",/*主要成就2*/"杰出成就奖、最佳建筑奖、居住建筑特别奖、青年建筑师奖、建筑评论奖及组委会特别奖。喀什老城阿霍街坊改造、天津中新生态城建设者公寓和台湾88水灾原住民部落重建（台湾）3个项目入围“居住建筑特别奖”，最终，喀什老城阿霍街坊改造、天津中新生态城建设者公寓获得“居住建筑特别奖”。",/*主要成就3*/"喀什老城区抗震研究和风貌保护研究、喀什高台民居抗震加固保护性研究。"};
	ALUMNI alumni6={/*序号*/6,/*入学年份*/1967,/*姓名*/"赵树丛",/*在校身份*/"工商管理硕士学士",/*系别*/"工商管理",/*研究领域*/"工商管理",/*简介*/"赵树丛，男，汉族，1955年3月生，山东诸城人，在职研究生学历，工商管理硕士学位， 1969年6月参加工作，1973年7月加入中国共产党。曾任国家林业局局长、党组书记。2017年10月14日，中国共产党第十八届中央委员会第七次全体会议按照党章规定，决定递补中央委员会候补委员赵树丛为中央委员会委员。",/*主要成就1*/"2015.06——2015.07，国家林业局局长。",/*主要成就2*/"中国林学会第十一届理事会理事长",/*主要成就3*/"中国共产党十四大、十六大、十七大、十八大代表，十八届中央委员。九届全国人大代表，八届全国政协委员，共青团十三届中央常委。"};
	ALUMNI alumni7={/*序号*/7,/*入学年份*/1978,/*姓名*/"彭孝军",/*在校身份*/"教授，博士研究生导师",/*系别*/"精细化工专业",/*研究领域*/"1、生物分子荧光探针 2、功能性染料、颜料及其工业应用",/*简介*/"彭孝军，男，1962年出生，博士学位，教授，博士研究生导师。国家杰出青年基金获得者（2007），国务院学科评议组成员（2009-），中国科学院院士(2017)。现任精细化工国家重点实验室主任，辽宁省精细化工工程技术中心主任。民盟大连市副主委。",/*主要成就1*/"210 Guanghui Cheng , Jiangli Fan*, Wen Sun , Jianfang Cao, Chong Hu , and Xiaojun Peng*. A Near-infrared Fluorescent Probe for Selective Detection of HClO Based on Se-sensitized Aggregation of Heptamethine Cyanine Dye, Chem. Commun., 2014, 50 (8), 1018-1020.",/*主要成就2*/"209 Jiangli Fan*, Huijuan Dong, Mingming Hu, Jingyun Wang, Hua Zhang, Hao Zhu, Wen Sun, Xiaojun Peng*. Fluorescence Imaging Lysosome Changes During Cell Division and Apoptosis with a Nile Blue Based Near-infrared Emission, Chem. Commun., 2014, 50 (7), 882-884.",/*主要成就3*/"208 Hao Zhu, Jiangli Fan,* Shiling Zhang, Jianfang Cao, Kedong Song, Dan Ge, Huijuan Dong, Jingyun Wang, and Xiaojun Peng*a. Ratiometric Fluorescence Imaging of Lysosomal Zn2+ Release under Oxidative Stress in Neural Stem Cells, Biomater. Sci., 2014, 2 (1), 89-97."};
	ALUMNI alumni8={/*序号*/8,/*入学年份*/1976,/*姓名*/"董长海",/*在校身份*/"毕业后留校工作",/*系别*/"机械制造工艺及设备",/*研究领域*/"毕业后留校工作",/*简介*/"董长海，大连市委原常委、统战部原部长，大连校友会志愿者。1976年—1980年，本科就读于我校机械制造工艺及设备专业。毕业后留校工作，先后担任校学生会秘书长，校团委副书记、书记，后调任大连市工作。他长期关心支持母校发展，自2016年8月份起，全身心投入到校友工作中，带领众多校友为大连校友会的建设和发展做出重要贡献。",/*主要成就1*/"得益于母校的培养，回报母校成了董长海一直的牵挂。大连是大工校友最多的地方，母校一直期待在大连校友中选一位校友工作的领军人物。2016年，董长海因年龄原因离开领导岗位。当母校领导找到董长海请他牵头大连校友会工作时，他愉快地接受了邀请，从此全身心投入校友会工作之中。地方校友会是联系校友与母校以及地方的桥梁和纽带，校友会工作怎样开展？“不能停留在一般性的联谊上，校友会的根本任务是服务，只有把服务工作做好了、做到位了，校友会才能充满活力。”董长海说。他与校友会一班人经过认真思考研究，鲜明提出，校友会工作要坚持“服务校友、服务母校、服务地方经济社会发展”的宗旨。现在“三服务”已成为大连校友会上下的共识，创造性的系列实践活动取得了可喜成果。",/*主要成就2*/"校友会积极牵线搭桥，促成了母校与大连市大数据中心、大连云数据科技有限公司、天港集团共建大连市大数据产业研究院项目，打造政产研学用相结合的城市数字经济发展开放式、创新型顶层智库；积极促进母校与大连金州湾新机场商务区的全方位交流，促成合作框架协议；积极向市科技局推荐电信学部刘东平教授主持的低温等离子体消杀灭菌项目，促进校地合作共赢；邀请地质、旅游界专家学者赴陆凯校友挂职的瓦房店驼山乡进行地质地貌及旅游开发实地考察，为大连国家滨海地质公园新增驼山景区起到了关键作用；组织有关方面校友深入肖天斌校友担任村第一书记的金普新区八里村实地考察，促成了八里村与母校建艺学院共建“三全育人”基地。这一系列活动不断将“三服务”工作推向深入。",/*主要成就3*/"丰富多彩的主题活动使大连校友会的凝聚力倍增。开展校友育人实践活动，成立校友成长之路报告团，让校友们用自己的亲身经历和人生感悟，与在校学弟学妹交流，成为“三全育人”的重要力量；组织《歌唱伟大祖国 奋斗伟大时代》庆祝新中国成立70周年主题登山活动，在“祖国母亲我爱你”的呐喊声中，让校友热泪盈眶；邀请在大连20多所高校校友会共同组织“我们都是追梦人·奋力奔跑新时代”2020奔跑大连团体接力赛，成为 “奔跑大连”的一个亮点；“我们都是追梦人·不忘初心向前冲”纪念一二·九运动徒步大会、“校友杯”羽毛球赛、乒乓球赛，成为一二·九运动纪念日校友会的品牌活动；走进东港会议中心，为校友及家属开展大型医疗义诊活动；组织校友企业走进母校招聘校友，帮助学弟学妹创新创业；开展“理工大学欢迎你，校友接你上大学”迎接北三市新生入学活动；母校校庆70周年之际，组织老校友开展“重返母校看成就·我与母校共成长”返校活动，同时组织300多名校友参加校庆奔跑日活动；发起为校史馆屈伯川老院长的雕塑捐赠活动， 30万善款让大工儿女始终不忘初心；组织商会走进母校、走访重点校友、敬老迎新、新春团拜会等等，这一项项主题鲜明的活动，让大连校友会成为联系凝聚校友的纽带、促进交流合作的平台、展示校友才华的舞台，引领校友传承红色基因，不忘初心、奋发向上的重要载体。"};
	ALUMNI alumni9={/*序号*/9,/*入学年份*/1990,/*姓名*/"阳志光",/*在校身份*/"历任航天一院一部工程组副组长、组长、室主任助理、副主任、室主任等职",/*系别*/"计算力学专业",/*研究领域*/"弹箭体结构研制技术",/*简介*/"阳志光，1990年—1992年硕士就读于我校计算力学专业。中国运载火箭技术研究院首席专家、型号总体副总师。历任航天一院一部工程组副组长、组长、室主任助理、副主任、室主任等职，是航天一院一部与我校共建的航天结构强度分析中心首任主任。获国防科技一等奖1项，三等奖1项；获航天科技进步一等奖1项，二等奖1项，三等奖3项。先后作为弹箭体结构主管设计、主任设计师、主管室领导，参加了中国运载火箭技术研究院绝大部分航天型号的研制工作，在多个航天型号研制过程中，作为技术负责人，组织完成了多项弹箭体结构研制技术攻关和多项重大预先研究课题。",/*主要成就1*/"前苏联宇航员加加林登上太空后，NASA负责人林登·约翰逊给了时任美国总统肯尼迪一个关键建议：“苏联通过令人印象深刻的太空技术成就使其在世界上的威望超过了美国，炫目的太空成就越来越被人们认为是领导世界的主要标志”。简言之，21世纪的世界，航天技术就是大国的形象代言。",/*主要成就2*/"阳志光也将青春奉献给了中国的航天事业。数年来，加班加点几乎是他的常态。这位刚毕业时秀气的小伙子熬出了白头发，熬出了皱纹，始终不变的是一丝不苟的作风，将航天人的责任、严慎细实坚持到工作的每一刻。中国运载火箭技术研究院首席专家称号、国防科技一等奖、航天科技进步一等奖——这些荣誉正是阳志光辛苦付出的证明。",/*主要成就3*/"然而，荣誉的背后总有辛酸，“我对家里始终还是有亏欠的。”阳志光想起了家人，“我女儿上高中的时候，我竟不知道他在哪个班级。”一次，女儿与同班的同学聚餐，几个家长也一同小聚，女儿同学的家长见到阳志光都十分惊讶，他才了解到，由于自己没管过女儿的上学接送和家长会，班上的家长都认为女儿生长在“单亲家庭”。"};
	ALUMNI alumni10={/*序号*/10,/*入学年份*/1980,/*姓名*/"史蹟",/*在校身份*/"大连理工大学学士",/*系别*/"金属材料专业",/*研究领域*/"金属材料",/*简介*/"史蹟，东京工业大学物质理工学院材料系教授，1980年—1984年，本科就读于我校金属材料专业，1997年获东京工业大学工学博士学位，是东京工业大学工学部百余年历史中首位获得教授职位的中国籍学者。2007年，在他的积极努力下，促成了东京工业大学金属工学科与我校的金属材料工程日语强化专业联合培养模式，东京工业大学委派日方老师长驻或短期来学校讲授专业课。2018年，他又促成我校金属材料工程（日语强化）专业与东京工业大学的“3+2”联合培养项目，为我校材料学科发展、人才培养贡献了力量。",/*主要成就1*/"7年学习积淀，工作上不断拓展，他收获了成就也收获了自信。能否在专业上有更大突破？史蹟一直在思考，在努力。“在当时能得到一次出国深造的机会，我觉得自己特别幸运。” 在兰州大学从教期间，因为综合能力突出，他被选拔公派赴日本攻读博士学位，此次机会成全了史蹟的坚持。",/*主要成就2*/"因为是自行设计，所以这台设备在各个功能的整合上并不是特别完善，史蹟一边做实验，一边和厂家商讨改进方案。经过很多个日日夜夜，他搞清了这台设备的全部构造和性能，整合了设备的各种先进功能，可以得心应手地去使用设备完成实验了。这台设备俨然已成为他最亲密的战友，与他一起并肩作战探索金属材料的世界和奥妙。“实验研究，可以让人萌生出更多的想法，自己用心得到的可靠数据和结果有时能推翻以往的论文甚至是教科书中既定的结论，这让我能够更深刻地体会到做研究是一个不断否定、不断创新的过程。”利用这台设备，史蹟采用物理气相沉积和化学气相沉积共沉积的方法，成功地合成了热平衡状态下不存在的镍和钴的碳化物，在理论上阐明了亚稳态化合物的的形成机制和稳定机制，为亚稳态材料的应用奠定了基础。同时对金属和非晶碳的纳米复合膜和多层薄膜的性能，特别是电学性能和磁学性能进行了系统研究，为这种结构的材料应用提供了理论基础。这些成果也让他顺利获得了博士学位。",/*主要成就3*/"2007年，针对大连理工大学材料科学与工程学院日语强化班的办学特色，在史蹟和两校各位老师的努力之下，两个以“理工”专业见长的大学在金属材料领域牵手了。这无论对大工还是东工大都是在国际合作教育上的一次深度合作，尤其是在本科教育层面。之后的 10年间，在史蹟的协调促进之下，材料科学与工程学院陆续迎来了包括东工大的水流徹教授、丸山俊夫教授等材料专业领域的8位世界知名专家教授，他们和史蹟一起站在上大工的讲堂，为大工学子上课500学时，培养学生160余名。“我十分感谢那些支持帮助两校合作的东工大的同事、大工的老师和朋友。没有他们的支持所有这些都是不可能的。我也十分欣慰地看到这些联合培养的学生都非常优秀，毕业后他们在中日两国都非常活跃”。"};
	ALUMNI alumni11={/*序号*/11,/*入学年份*/1982,/*姓名*/"朱元宪",/*在校身份*/"内燃机专业博士",/*系别*/"内燃机专业",/*研究领域*/"内燃机",/*简介*/"1974年朱元宪在四川作为一名知青被推荐上大工读书，在那个特殊的年代里，他显然很珍惜这个来之不易的学习机会。东北的冬天十分寒冷，而那些年燃料和其它生活物资一样短缺，暖气每天只能烧一、两个小时，空荡的教室更是让人待不住。班主任陈家骅老师多年后回忆起当年的朱元宪时说道:“我总能看见一个穿军大衣、个挺高的男生在那儿学习，零下几度的自习室里常常就他一个人。”“从中学开始我就遇上文革，没学到什么东西，真想静下心来好好读书，但在大学的那几年受到的干扰也太多。”朱元宪感慨地说。",/*主要成就1*/"2004年，朱元宪受邀回国加盟刚成立的成都威特电喷公司，领导技术团队开发汽车柴油机的核心部件——电控燃油喷射系统。经过十余年的努力，先后成功地开发了电控组合式单体泵和高压共轨系统等产品并实现了产业化，在市场也占有一席之地。然而，他也意识到，德国博世等企业在汽车核心零部件领域内的技术、质量和品牌方面的优势在可以预见的时间内难以超越，其垄断地位也难以打破。企业要生存和发展，获得更多的市场，必须另辟蹊径。",/*主要成就2*/"2019年12月，在大连理工大学“冰山慧谷杯”第二届校友科技创业大赛中，朱元宪和团队开发的船舶柴油机高压共轨系统在众多参赛作品中脱颖而出，获得天使组冠军。项目终于在第三个年头取得阶段性成果，为接下来投产奠定了坚实的基础。",/*主要成就3*/"现在，已经65岁的朱元宪每天仍旧工作9-10个小时。“虽然经过十几年的努力，我们取得了一些成果，但对比像博世公司这样的国外巨头，我们的企业还是一个‘小贝贝’。面对柴油机高压共轨系统领域里国外企业几近垄断的局面，未来我希望我们在汽车发动机领域能达到10%左右的市场份额，而在船舶发动机这一细分领域夺得一个举足轻重的地位。”"};
	ALUMNI alumni12={/*序号*/12,/*入学年份*/2009,/*姓名*/"赖晗",/*在校身份*/"大连理工大学学士",/*系别*/"电子信息工程专业",/*研究领域*/"造卫星",/*简介*/"“年轻有为”，“儒雅谦和”是赖晗给人的第一印象，前者源于他精致简练的履历，后者则是本人自带的气质。他似乎与传统印象里的年轻创业者形象不符，作为90后，赖晗比同龄人多几分成熟稳重，作为创业者，他又少了几分锋利与张扬，唯有言谈间可以窥得一点被温柔包裹着的勃勃野心与熊熊志向。",/*主要成就1*/"硕士毕业后，赖晗直接进驻了伦敦Entrepreneur First孵化器。那是一个为有经验的 职场人士提供创业资源的平台。在那里，赖晗与合伙人Rafel相识，两人对卫星商业化的构想一拍即合，当技术自信和市场经验碰撞，Open Cosmos应运而生。Open Cosmos，即开放宇宙，太空是开放的，私人企业也可以使用卫星，实现卫星的民用、商用。 ",/*主要成就2*/"最近，赖晗正着手推进与大工建立联合实验室，为学者和创业者搭建平台。“我们可以一起做很多好玩的事情，”对于这项合作，赖晗兴致勃勃，“航天可以深入各个领域，我希望建设一个航天实验室，用来帮助在校师生以及广大校友，利用航天技术促进他们在各自领域的研究进展。”",/*主要成就3*/"随着Open Cosmos在英国乃至欧洲市场的稳步发展，近两年赖晗逐渐将目光转向国内。2018年起，他陆续与国内几家航空航天领域的公司签订战略合作协议，并着手创立新公司，主营遥感装置，为客户收集数据，监测信息，可应用于环境、土木、船舶等领域。"};
	ALUMNI alumni13={/*序号*/13,/*入学年份*/1995,/*姓名*/"谭畅",/*在校身份*/"大连理工大学学士",/*系别*/"应用物理学专业",/*研究领域*/"航天",/*简介*/"“严谨、求实、创新、奉献”几个蓝色的大字，十分醒目地贴在陕西省等离子体物理与应用技术重点实验室的白墙上。“这是我确立的工作精神，很眼熟吧，它取自我们大工，团结、进取、求实、创新。”说这话的是实验室常务副主任，我校校友谭畅，年仅41岁的他已成为我国国防科技专家。红色基因锻造了他航天强国的国防使命，从迈进大工校门的那一刻，便指引他向更广阔的宇宙空间发起探索，二十几年来，从大工到西安，从中国到太空。他就是我校95级校友——谭畅。",/*主要成就1*/"去年3月，一则“国内首套等离子体炉渣气化熔融技术在西安研制成功”的新闻被媒体广泛报道。这一等离子体炉渣气化熔融固废处理示范工程项目，当时已在江苏盐城连续稳定运行超30天，填补了国内危废领域炉渣无害化处理的空白，有机污染物焚毁率可达99.99%，标志着危废处理的“终极技术”等离子体气化熔融技术在国内正式进入工程应用阶段。",/*主要成就2*/"《Plasma Science & Technology》、《IEEE-TPS》、《中国表面工程》、《火箭推进》审稿人，陕西省青年联合会第十届委员，西安市青年科学技术协会会员。1995年-1999年本科就读于我校应用物理学专业，1999年-2006年在我校等离子体物理专业攻读硕士、博士。长期从事航空航天等离子体技术应用研究，承担并完成国家自然科学基金4项，装备预研项目7项，国防973、军口863、创新特区、国防科工局基础科研、国防科工局民用航天等项目若干项。曾获国防科技进步一等奖，国家科技进步二等奖，陕西省青年科技新星，陕西国防科工创新标兵，国防团队，三秦学者创新团队。发表学术论文50余篇，授权专利6项，培养7名青年技术人员。2015年起，与物理学院共建航空航天低温等离子体诊断技术联合实验室。",/*主要成就3*/"太空环境中，在推进剂质量相同的条件下，用等离子体方式做空间动力，可以比常规化学推进飞得更快、更远、更久。“发展航天，动力先行。”探索宇宙未知空间，拓展人类征服太空的脚步，航天动力是决定性因素。航天科学家早就说过：“中国火箭的能力有多大，中国航天的舞台就有多大”，而面对更深更远的茫茫宇宙，建设航天强国的历史使命需要我们致力于研究出更加高效、更大推力、更高比冲、更长寿命的航天动力。谭畅说，“我们一直在同国际赛跑，希望我国能在未来十年内能够达到上天的条件，十五年内投入使用，走在国际前列。”"};
	ALUMNI alumni14={/*序号*/14,/*入学年份*/1993,/*姓名*/"陈国才",/*在校身份*/"大连理工大学学士",/*系别*/"工程建设",/*研究领域*/"“华龙一号”",/*简介*/"2017年5月25日，我国自主三代核电“华龙一号”全球首堆示范工程——中核集团福清核电5号机组提前15天完成穹顶吊装。在吊装现场，工程现场总指挥陈国才的声音已经嘶哑，但仍在反复确认风速，指导“配平”。中央电视台《大国重器》纪录片这一片段播出时，大家无不为之振奋、感动。其实，更令大工人激动的是，工程现场总指挥陈国才是大工93级校友。",/*主要成就1*/"秦山核电站是周恩来总理批示的民用核能建设“728工程”国家重点项目，是中国大陆第一座核电站，此前中国没有民用核能建设的相关经验，一切都要摸索前行，但也为中国商用核电的发展打下了基础，培育了一大批核电人才。毕业时正值秦山三期重水堆工程开建，陈国才参与工程全过程的调试管理工作。由于在安装施工阶段已暴露出工程拖期半年的危机，陈国才们只好在调试阶段想办法将时间抢回来。为保证秦山核电站的200多个系统全部正常运行，需要先逐一打通各系统，再将几个系统组合调试，然后再将部分系统组合调试，最后全部系统组合调试，层层把关，环环相扣，确保设计数据与试验数据一致。陈国才感慨到“调试过程中发现并解决的问题10000有余”。一年多时间里，陈国才和所有工程建设者一起没日没夜地工作，几乎没有周末，连夜睡在工程现场也是家常便饭。除了紧张的工程调试，陈国才还负责将中方和外方4位调试领域总经理的文秘工作，大家在工程现场看到他总是“跑步前进”。2002年，秦山三期重水堆1号机组终于投入商业运行，竟然比目标工期提前了43天！迄今为止，陈国才还是忘不了那天眼中激动的泪水。",/*主要成就2*/"“我是国家的一块砖，哪里需要哪里搬。”2004年底，陈国才被调到三门核电有限公司，从事AP1000核电工程建设，负责工程项目的进度控制和投资控制。从未接触过投资相关工作的陈国才，凭借大工人“擅学习”的能力，三年里，竟将整个工程项目的投资控制熟稔于心，并凭借过硬的专业能力入选行业“专家库”。2009年4月19日，三门核电1号机组开工，时任国务院副总理的李克强亲自到现场宣布开工，并与大家握手慰问。那张总理与陈国才握手的照片成了三门核电展厅的第一张巨照，也映射着陈国才为国家矢志建设的初心。",/*主要成就3*/"纵观世界核电发展，美国西屋公司的AP1000第三代核电堆型，从开始建设到投产用了十年时间。法国的EPR核电项目于2004年在芬兰开工，至今仍未投产。而同样是第三代核电的我国“华龙一号”，如果能在预期内完成，将仅用五年时间。为了实现这一目标，中国核电人都在竭尽全力。2017年5月25日，福清核电5号机组提前15天完成吊装，这意味着该工程从土建施工阶段全面转入设备安装阶段，陈国才们为国家交上了一份满意的答卷。作为目前全球三代首堆核电建设中唯一不拖工期的工程，这份成绩的背后，是陈国才坚定的声音：“为了中国核电成为世界最强！”"};
	ALUMNI alumni15={/*序号*/15,/*入学年份*/1983,/*姓名*/"任晓民",/*在校身份*/"大连理工大学学士",/*系别*/"金属材料与热处理专业",/*研究领域*/"大连理工大学-加州大学欧文分校机械设计制造及其自动化专业本科教育项目",/*简介*/"任晓民，大连赛诺五金矿产有限公司总经理。1983年-1987年就读于我校金属材料与热处理专业，1987年-1990年硕士就读于我校金属材料专业。2011年，任晓民着手开拓母校与美国著名理工科大学合作，结合母校学科特点，确定了以加州大学欧文分校（UCI）为合作对象。在任晓民的不懈努力和推动下，2013年5月我校与UCI签署合作备忘录，同年暑期，我校第一批学生赴UCI参加暑期科研项目。随后，UCI与我校机械学院、管经学部分别开展了2周短期课程项目，该项目已顺利开展三年。2014年底，UCI与我校电信学部、机械学院签订了3+2项目协议，是加州大学历史上第一次与国外大学签订的3+2项目协议。2015年，UCI又陆续与化环生学部和软件学院签订3+2项目协议。2017年4月，UCI校长率代表团赴连与我校签署联合办学协议，决定合作举办“大连理工大学-加州大学欧文分校机械设计制造及其自动化专业本科教育项目”，培养具有国际视野的一流人才。",/*主要成就1*/"2017年4月10日，大工迎来了一位特殊的客人——美国加州大学欧文分校校长Howard Gillman。当天下午，郭东明校长与Howard Gillman续签两校合作谅解备忘录，并签署联合办学协议，决定合作举办“大连理工大学-加州大学欧文分校机械设计制造及其自动化专业本科教育项目”，培养具有国际视野的一流人才。",/*主要成就2*/" 虽然知道春天一定会来，但等待的过程依然让人忐忑，“只有订单能让我安心。最焦虑的时候，如果连续两天没有接到订单传真，我心里就七上八下的，不安稳。”2004年7月，国家对《对外贸易法》进行了修订并颁布实施，此次修订，取消了外贸经营权的门槛限制，并将对外贸易经营者的范围扩大到个人。任晓民期待的春天终于来了。",/*主要成就3*/"在任晓民的全力推动下，2013年5月，加州大学欧文分校工学院院长Gregory Washington教授来访我校，并签署谅解备忘录，这是两校合作的起点。随后，双方对互认课程提出要求并逐步落实，逐一敲定3+2协议细节，2014年11月，我校电信学部与加州大学欧文分校工学院正式签署3+2协议，协议内容规定：我校电子信息与电气工程学部电气工程、计算机科学与工程和生物医学工程3个专业本科生在我校学习3年后，如满足3+2协议中UCI的学分要求和外语要求，可在UCI工学院完成第4学年的学习，随后再在UCI读1年硕士课程。学生将获得我校本科学位和UCI硕士学位。这是美国加州大学共10所分校中第一次与中国高校签订此类协议，“这是我的第一个阶段性成果。”此后，我校机械学院、化工学院和软件学院也陆续与加州大学欧文分校签订了3+2协议。"};
	ALUMNI alumni16={/*序号*/16,/*入学年份*/1939,/*姓名*/"毕德显",/*在校身份*/"电机系及电信系主任",/*系别*/"电机系",/*研究领域*/"无线电",/*简介*/"1934年，毕德显毕业于燕京大学物理系研究生院，留校任教；1939年，在昆明清华大学任无线电所研究员。1941年，从美国斯坦福大学电机系硕士毕业；1944年，从美国加州理工学院物理系博士毕业；1947年，任南京中央大学物理系教授；1949年，任大连大学电机系及电信系主任；1952年，调任张家口军委工校工作；1961年，任重庆雷达工程学院副院长，1963年，更名为通信兵工程学院后任副院长，被授予大校军衔；1972年，任重庆通信工程技术学校副校长；1978年至1988年任南京通信工程学院副院长。 [2]",/*主要成就1*/"朝鲜战争时期，中国人民志愿军在前线遇到了坑道通信的难题，当时国际上对地下无线电波的研究和应用还没有取得突破性进展。毕德显一方面认真总结战士们使用埋地天线的经验，另一方面查资料，搞演算，从理论上进行研究探讨，写出了一篇“坑道天线”的专论，对坑道通信的电波传播方式，对坑道天线的辐射机理、基本形式结构及如何架设等都作了描述，使“天线埋在地下能够实施通信联络”的问题从理论上找到了答案，为抗美援朝时的野战通信联络贡献了一份力量。",/*主要成就2*/"20世纪50年代末，毕德显参与了气象雷达和超远程雷达等的研制工作，提出了将参量放大器作为接收机前端以提高雷达性能的设计思想。 [6]",/*主要成就3*/"20世纪50-60年代，毕德显针对当时中国雷达存在距离与速度模糊问题，研究提出了利用编码技术来解决这一问题，并提出了几种编码方法。 [4]"};
	ALUMNI alumni17={/*序号*/17,/*入学年份*/1948,/*姓名*/"屈伯川",/*在校身份*/"大连大学工学院院长，兼化学研究所所长（中国科学院大连化学物理研究所前身）",/*系别*/"化工",/*研究领域*/"化工",/*简介*/"屈伯川同志1940年曾任延安新华化工厂厂长并参加创立边区自然科学研究会。1940年至1941年参加筹备我党创办的第一个理工科大学 — 延安自然科学院任教育处处长；1942年至1943年任陕甘宁边区政府建设厅工业局副局长；1945年至1946年任晋察冀军区工业部实验所所长1947年任大连“关东工业专门学校”校长，1948年至1950年任大连大学工学院院长，兼化学研究所所长（中国科学院大连化学物理研究所前身）；1950年至1981年任大连理工大学校长。1981年后任大连理工大学名誉校长。 [1]",/*主要成就1*/"1980年5月，邓小平访美时与卡特总统达成协议，中美两国要在科技上开展合作，在我国创办一个培训中心，学习研究美国现代化管理的知识和技术，培养我国现代化工业管理和科技管理人才。得知信息后，他连夜赶往北京，找到国家经委的相关负责人，提出了把这个中心办到大连去，他认为这是学校发展管理学科的良好契机。他的建议得到了国家三个部委和美方代表的赞同。当时的大连工学院要办这个中心，从硬件上来说是困难重重，没有现代化的教室，没有像样的外国专家招待所。屈伯川说：“对办学有利的事，就是要冒点险。不干，机会就错过；一闯，也就上去了。”8月18日，“中国工业科技管理大连培训中心”正式开学。这个中心成为改革开放后我国学习和引进国外先进管理思想、理论和经验的第一个窗口。美方从30多所大学聘请了包括诺贝尔经济学奖获得者伦斯·克莱茵在内的130多位教授、专家来讲课。培训中心不断发展壮大。2002年，这个培训基地成为原国家经贸委确定的“全国企业经营管理者培训重点基地”——“国家经贸委大连经理学院”。2006年1月13日，中国大连高级经理学院在大连理工大学揭牌，如今大连已成为全国培养最高层管理人才的基地。",/*主要成就2*/"屈伯川组织起草了一份建议书，建议书中说：“我们认为，从全国700余所高等院校中，选出50所左右基础较好、师资力量较强、教学质量和科研水平较高，既能培养质量较高的大学本科生，又能培养合格的硕士、博士研究生，规模也较大的院校，作为高等教育建设的战略重点。”这样做，“不仅不会对我国的经济带来多大负担，相反却会大大加速和更加有效地促进重点经济建设。他们所创造的价值不是任何一个重点经济建设项目的经济效益所能比拟的。因为作为智力投资的总效益是长远的，其意义是难以估量的。”",/*主要成就3*/"屈伯川博士从事高等教育工作半个多世纪，为大连理工大学这所中国共产党亲手创办的第一所正规大学的创建、发展和壮大做出了不可磨灭的贡献。他在长期的高等教育实践中，准确把握教育规律，锐意改革创新，形成了一套全面系统、切合中国实际、颇具中国特色的教育思想体系，已成为中国高等教育事业的宝贵财富。"};
	//ALUMNI alumni18={/*序号*/18,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni19={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni20={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni21={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni22={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni23={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni24={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni25={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni26={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni27={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni28={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni29={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	//ALUMNI alumni30={/*序号*/8,/*入学年份*/,/*姓名*/"",/*在校身份*/"",/*系别*/"",/*研究领域*/"",/*简介*/"",/*主要成就1*/"",/*主要成就2*/"",/*主要成就3*/""};
	fp=fopen("data.dat","wb");
	fwrite(&alumni1,sizeof(ALUMNI),1,fp);
	fwrite(&alumni2,sizeof(ALUMNI),1,fp);
	fwrite(&alumni3,sizeof(ALUMNI),1,fp);
	fwrite(&alumni4,sizeof(ALUMNI),1,fp);
	fwrite(&alumni5,sizeof(ALUMNI),1,fp);
	fwrite(&alumni6,sizeof(ALUMNI),1,fp);
	fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	fwrite(&alumni8,sizeof(ALUMNI),1,fp);
	fwrite(&alumni9,sizeof(ALUMNI),1,fp);
	fwrite(&alumni10,sizeof(ALUMNI),1,fp);
	fwrite(&alumni11,sizeof(ALUMNI),1,fp);
	fwrite(&alumni12,sizeof(ALUMNI),1,fp);
	fwrite(&alumni13,sizeof(ALUMNI),1,fp);
	fwrite(&alumni14,sizeof(ALUMNI),1,fp);
	fwrite(&alumni15,sizeof(ALUMNI),1,fp);
	fwrite(&alumni16,sizeof(ALUMNI),1,fp);
	fwrite(&alumni17,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);
	//fwrite(&alumni7,sizeof(ALUMNI),1,fp);

	fclose(fp);
}