#include "include.h"



/************

����1.�������Ϣ

*************/
/*����������������������������������������������������������������*/

void data_saveing_form()//���
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
//1��******************
	gotoxy(10,1);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");

//2��******************
	gotoxy(10,2);printf("��");
	gotoxy(9+50-4,2);printf("У����Ϣ");
	gotoxy(9+100-9,2);printf("��ţ�");
	//���9+100-6,2  3
	gotoxy(111,2);printf("��");
	
//3��******************
	gotoxy(10,3);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");

//4��******************
	gotoxy(10,4);printf("��������");
	//����10+6,4  20
	gotoxy(10+6+20,4);printf("����ѧ��ݩ�");
	//��ѧ���10+6+20+10,4  5
	gotoxy(10+6+20+10+5,4);printf("����У��ݩ�");
	//��У���10+6+20+10+5+10��4 20
	gotoxy(10+6+20+10+5+10+20,4);printf("��ϵ��");
	//ϵ��10+6+20+10+5+10+20+6��,4 20
	gotoxy(111,4);printf("��");

//5��******************
	gotoxy(10,5);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10+5,3);printf("��");
	gotoxy(10+6+20,3);printf("��");
	gotoxy(10+6+20+9,3);printf("��");
	gotoxy(10+6+20+10+5,3);printf("��");
	gotoxy(10+6+20+10+5+9,3);printf("��");
	gotoxy(10+6+20+10+5+10+20,3);printf("��");
	gotoxy(10+6+20+10+5+10+20+5,3);printf("��");
	gotoxy(10+5,5);printf("��");
	gotoxy(10+6+20,5);printf("��");
	gotoxy(10+6+20+9,5);printf("��");
	gotoxy(10+6+20+10+5,5);printf("��");
	gotoxy(10+6+20+10+5+9,5);printf("��");
	gotoxy(10+6+20+10+5+10+20,5);printf("��");
	gotoxy(10+6+20+10+5+10+20+5,5);printf("��");

//6��******************
	gotoxy(10,6);printf("���о�����");
	//�о�����10+10,6
	gotoxy(111,6);printf("��");

//7��******************
	gotoxy(10,7);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10+9,5);printf("��");
	gotoxy(10+9,7);printf("��");

//8-26��******************
	for(i=8;i<=26;i++)
	{
		gotoxy(10,i);printf("��");
		gotoxy(111,i);printf("��");
	}

//8��14��19��24��******************
	gotoxy(10,8);printf("����飺");
	//���10+8,8
	gotoxy(10,14);printf("����Ҫ�ɾ�1:");
	//��Ҫ�ɾ�1 10+12,14
	gotoxy(10,19);printf("����Ҫ�ɾ�2:");
	//��Ҫ�ɾ�2 10+12,19
	gotoxy(10,24);printf("����Ҫ�ɾ�3:");
	//��Ҫ�ɾ�3 10+12,24

//13��18��23��******************
	gotoxy(10,13);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10,18);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10,23);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");

//27��******************
	gotoxy(10,27);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
}
uint16 data_saveing_get_string(uint16 i,int8 *string)//��Ӧ�ڱ����ת�й��ܵ��ַ����鸳ֵ����
{
	uint16 j;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
	for(j=0;(string[j]=getch())!='\r';j++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
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
void data_saveing_input(uint16 i,ALUMNI *p,uint16 *judgment)//����data_saveing����ĺ����������ж�������ֵ
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
	FILE *fp;//�����ڼ���������ļ�
	ALUMNI *head,*p;//�����ͷָ�룬��������ڵ�ָ��
	uint16 i;//����ѭ������û�к���
	uint16 judge=0;//�ж��������
	uint16 judgment[9];//����ɹ������жϰ�����
	POINT *point;//����POINT�ṹ����洢�������
	LPRECT rect;//����LPRECT�ṹ��ָ��洢����������Ϣ
	HWND hwnd=FindWindow(NULL,"�󹤽ܳ�У����Ϣ����ϵͳ");//���Ҿ��֮�󱣴�������
	point=(POINT*)malloc(sizeof(POINT)+64);//�����ڴ�
	rect=(LPRECT)malloc(sizeof(LPRECT)+64);//Ϊ�ṹ��ָ������ڴ�ռ�
	p=(ALUMNI *)malloc(sizeof(ALUMNI));
	p->link_back=NULL;
	p->link_ahead=NULL;
	head=p;
	data_saveing_form();
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("�Ƿ�ȷ����ʼ�����Ϣ��");
	return_key();
	gotoxy(5,2);printf("��ʼ");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ʼ
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				return;
			}
		}
	}
	while(1)
	{
		data_saveing_form();
		gotoxy(10,28);printf("��ʾ�����������룬����һ�ּ�����һ�֡�");
		gotoxy(9+100-9,2);printf("      ");
loop2:
		for(i=0;i<9;i++)
			data_saveing_input(i,p,judgment);
loop1:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
		for(i=0;i<9;i++)
			if(!judgment[i])
				break;
		if(i!=9)
		{
			gotoxy(10,28);
			printf("�������У�ѵ�");
			for(i=0;i<9;i++)
				if(!judgment[i])
					printf("%s��",title[i]);
			printf("\b\b��Ϣ�������������롣");
			gotoxy(1,1);
			for(i=0;i<9;i++)
				if(!judgment[i])
					data_saveing_input(i,p,judgment);
			goto loop1;
		}
return_loop2:
		gotoxy(3,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(3,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(3,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(112,1);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(112,2);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(112,3);for(i=0;i<7;i++)printf(" ");//���ԭ������
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(34,28);
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		gotoxy(10,29);printf("����ɹ����Ƿ�������룿");printf("��  �������멧��  �������멧��  �޸���Ϣ��               Ctrl+Alt����ݼ������롣��");
		gotoxy(34,30);
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		gotoxy(1,1);
		while(1)
		{
			GetWindowRect(hwnd,rect);
			GetCursorPos(point);

			if(GetAsyncKeyState(VK_LBUTTON))//�������������
			{
				int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
				if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//�����������
				{
					system("cls");
					p=(ALUMNI *)malloc(sizeof(ALUMNI));
					p->link_ahead=head;
					head->link_back=p;
					head=p;
					p->link_back=NULL;
					goto loop_continue;
				}
				if(45*Pixel.width+Pixel.width/2<x&&x<56*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//�����������
	return_loop1:{
					ALUMNI temp;//�������ݿ飬����ȡ���
					fp=fopen("data.dat","rb");	//�ж��Ƿ�Ϊ���ļ���
					fseek(fp,0,SEEK_END);
					if(ftell(fp)==NULL)			//����ǵĻ�����Ŵ�1��ʼ
						i=1;
					else						//������ǣ���ȡ���buf�����
					{				
						fseek(fp,-sizeof(ALUMNI),SEEK_END);//��ȡ���
						fread(&temp,sizeof(ALUMNI),1,fp);
						i=temp.number+1;
						
					}
					fclose(fp);	
					fp=fopen("data.dat","ab+");
					fseek(fp,0,SEEK_END);
					while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
						p=p->link_ahead;
					while(p!=NULL)				//��ʼ���α��浽�ļ���
					{
						p->number=i;
						fwrite(p,sizeof(ALUMNI),1,fp);
						p=p->link_back;
						i++;
					}
					fclose(fp);
					gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(10,28);printf("����ɹ���");
					for(i=3;i>0;i--)
					{
						printf("%hd��󷵻���ҳ����",i);
						Sleep(1000);
						printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
					}
					judge++;
					break;
				}
				if(57*Pixel.width+Pixel.width/2<x&&x<68*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)//����޸���Ϣ
				{
					break;
					gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
					gotoxy(1,1);
					goto loop2;//���ص�����׶�
				}
			}

			if(GetAsyncKeyState(VK_MENU)&&GetAsyncKeyState(VK_CONTROL))           //ctrl+alt����������
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
		if(judge)//�˳�����
		{system("cls");break;}
		loop_change2:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);printf("������Ҫ�޸ĵ���Ϣ�Ŀ�ͼ��");
		gotoxy(1,1);
		while(1)
		{
			GetWindowRect(hwnd,rect);
			GetCursorPos(point);
			if(GetAsyncKeyState(VK_LBUTTON))//�������������
			{
				int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
				if(11*Pixel.width-Pixel.width/2<x&&x<(10+6+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//�����������
					{data_saveing_input(0,p,judgment);break;}
				if((10+6+20)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//���������У���
					{data_saveing_input(1,p,judgment);break;}
				if((10+6+20+10+5)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//���������У���
					{data_saveing_input(2,p,judgment);break;}
				if((10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//�������ϵ��
					{data_saveing_input(3,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&5*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//��������о�����
					{data_saveing_input(4,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<14*Pixel.height-Pixel.height/2)//���������
					{data_saveing_input(5,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&13*Pixel.height-Pixel.height/2<y&&y<18*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�1
					{data_saveing_input(6,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�2
					{data_saveing_input(7,p,judgment);break;}
				if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<27*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�3
					{data_saveing_input(8,p,judgment);break;}
			}
		}
		loop_change1:
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
		for(i=0;i<9;i++)
			if(!judgment[i])
				break;
		if(i!=9)
		{
			gotoxy(10,28);
			printf("�������У�ѵ�");
		for(i=0;i<9;i++)
				if(!judgment[i])
					printf("%s��",title[i]);
			printf("\b\b��Ϣ�������������롣");
			gotoxy(1,1);
			for(i=0;i<9;i++)
				if(!judgment[i])
					data_saveing_input(i,p,judgment);
			goto loop_change1;
		}
		gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
		gotoxy(34,28);printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		gotoxy(10,29);printf("�޸ĳɹ����Ƿ�����޸ģ�");printf("��  �����޸ĩ�");
		gotoxy(34,30);printf("��");for(i=0;i<10;i++)printf("��");printf("��");
		gotoxy(1,1);
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
					goto return_loop1;
				}
				if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
				{
					goto return_loop2;
				}
				if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)	//��������޸�
					goto loop_change2;
			}
		}
	/******************��ת���ؽ���***********************/
	loop_continue:;
	}
}
/*����������������������������������������������������������������*/



/************

����2.�޸���Ϣ

*************/
/*����������������������������������������������������������������*/

void data_change_form(ALUMNI *p)	//�鿴��ϸ��Ϣ���
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
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ���λ����Ϣ
    CONSOLE_SCREEN_BUFFER_INFO csbi,csbi0;
	GetConsoleScreenBufferInfo(h, &csbi0);
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
	gotoxy(10,4);printf("�������� ");
	//����10+6,4  20
	for(i=0;p->name[i]!='\0';i++)
	{
		GetConsoleScreenBufferInfo(h, &csbi);//��ȡ���λ����Ϣ
		if(csbi.dwCursorPosition.X+1>10+6+20-2)
		{
			break;
		}
		printf("%c",p->name[i]);
	}
	gotoxy(10+6+20,4);printf("����ѧ��ݩ�");
	//��ѧ���10+6+20+10,4  5
	gotoxy(10+6+20+10+5,4);printf("����У��ݩ�");
	//��У���10+6+20+10+5+10��4 20
	gotoxy(10+6+20+10+5+10+20,4);printf("��ϵ��");
	//ϵ��10+6+20+10+5+10+20+6��,4 20
	gotoxy(111,4);printf("��");

//5��******************
	gotoxy(10,5);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10+5,3);printf("��");
	gotoxy(10+6+20,3);printf("��");
	gotoxy(10+6+20+9,3);printf("��");
	gotoxy(10+6+20+10+5,3);printf("��");
	gotoxy(10+6+20+10+5+9,3);printf("��");
	gotoxy(10+6+20+10+5+10+20,3);printf("��");
	gotoxy(10+6+20+10+5+10+20+5,3);printf("��");
	gotoxy(10+5,5);printf("��");
	gotoxy(10+6+20,5);printf("��");
	gotoxy(10+6+20+9,5);printf("��");
	gotoxy(10+6+20+10+5,5);printf("��");
	gotoxy(10+6+20+10+5+9,5);printf("��");
	gotoxy(10+6+20+10+5+10+20,5);printf("��");
	gotoxy(10+6+20+10+5+10+20+5,5);printf("��");

//6��******************
	gotoxy(10,6);printf("���о�����");
	//�о�����10+10,6
	gotoxy(111,6);printf("��");

//7��******************
	gotoxy(10,7);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10+9,5);printf("��");
	gotoxy(10+9,7);printf("��");

//8-26��******************
	for(i=8;i<=26;i++)
	{
		gotoxy(10,i);printf("��");
		gotoxy(111,i);printf("��");
	}

//8��14��19��24��******************
	gotoxy(10,8);printf("����飺");
	//���10+8,8
	gotoxy(10,14);printf("����Ҫ�ɾ�1:");
	//��Ҫ�ɾ�1 10+12,14
	gotoxy(10,19);printf("����Ҫ�ɾ�2:");
	//��Ҫ�ɾ�2 10+12,19
	gotoxy(10,24);printf("����Ҫ�ɾ�3:");
	//��Ҫ�ɾ�3 10+12,24

//13��18��23��******************
	gotoxy(10,13);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10,18);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");
	gotoxy(10,23);printf("��");
	for(i=0;i<100;i++)
		printf("��");
	printf("��");

//27��******************
	gotoxy(10,27);
	printf("��");for(i=0;i<100;i++)printf("��");printf("��");
	gotoxy(1,1);
}
void data_change()//�޸����ݺ���
{
	FILE *fp;			//�������ļ�
	ALUMNI *head,*p;	//�����ͷָ�룬��������ڵ�ָ��
	uint16 i;			//����ѭ��ʹ��
	uint16 judgment[9];	//����ɹ������жϰ�����
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
			printf("%hd��󷵻���ҳ����",i);
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
	gotoxy(11,2);printf("�Ƿ�ȷ����ʼ�޸ģ�");
	return_key();
	gotoxy(5,2);printf("��ʼ");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ʼ
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				return;
			}
		}
	}
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("��������Ҫ�޸���Ϣ��У����ţ�");
	{
		int16 number;
loop3:	if(!scanf("%hd",&number)||number>buf)
		{
			gotoxy(9+60+6+2,2);printf("    ");
			gotoxy(9+80+2,2);printf("�����������룡");
			fflush(stdin);
			goto loop3;
		}
		p=head;
		for(i=0;buf-number>i;i++)	//pָ��ָ���ڵ�
			p=p->link_ahead;
	}
	system("cls");
	data_change_form(p);
loop2:
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,29);printf("������Ҫ�޸ĵ���Ϣ�Ŀ�ͼ��");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(11*Pixel.width-Pixel.width/2<x&&x<(10+6+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//�����������
				{data_saveing_input(0,p,judgment);break;}
			if((10+6+20)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//���������У���
				{data_saveing_input(1,p,judgment);break;}
			if((10+6+20+10+5)*Pixel.width-Pixel.width/2<x&&x<(10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//���������У���
				{data_saveing_input(2,p,judgment);break;}
			if((10+6+20+10+5+10+20)*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&3*Pixel.height-Pixel.height/2<y&&y<5*Pixel.height-Pixel.height/2)//�������ϵ��
				{data_saveing_input(3,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&5*Pixel.height-Pixel.height/2<y&&y<7*Pixel.height-Pixel.height/2)//��������о�����
				{data_saveing_input(4,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&7*Pixel.height-Pixel.height/2<y&&y<14*Pixel.height-Pixel.height/2)//���������
				{data_saveing_input(5,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&13*Pixel.height-Pixel.height/2<y&&y<18*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�1
				{data_saveing_input(6,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&18*Pixel.height-Pixel.height/2<y&&y<23*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�2
				{data_saveing_input(7,p,judgment);break;}
			if(10*Pixel.width-Pixel.width/2<x&&x<111*Pixel.width-Pixel.width/2&&23*Pixel.height-Pixel.height/2<y&&y<27*Pixel.height-Pixel.height/2)//���������Ҫ�ɾ�3
				{data_saveing_input(8,p,judgment);break;}
		}
	}
	loop1:
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
	for(i=0;i<9;i++)
		if(!judgment[i])
			break;
	if(i!=9)
	{
		gotoxy(10,28);
		printf("�������У�ѵ�");
	for(i=0;i<9;i++)
			if(!judgment[i])
				printf("%s��",title[i]);
		printf("\b\b��Ϣ�������������롣");
		gotoxy(1,1);
		for(i=0;i<9;i++)
			if(!judgment[i])
				data_saveing_input(i,p,judgment);
		goto loop1;
	}
	gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
	gotoxy(34,28);printf("��");for(i=0;i<10;i++)printf("��");printf("��");
	gotoxy(10,29);printf("�޸ĳɹ����Ƿ�����޸ģ�");printf("��  �����޸ĩ�               Ctrl+Alt����ݼ������롣��");
	gotoxy(34,30);printf("��");for(i=0;i<10;i++)printf("��");printf("��");
	gotoxy(1,1);
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
				fp=fopen("data.dat","wb");
				while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
					p=p->link_ahead;
				while(p!=NULL)				//��ʼ���α��浽�ļ���
				{
					fwrite(p,sizeof(ALUMNI),1,fp);
					p=p->link_back;
					i++;
				}
				fclose(fp);
				gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,28);printf("����ɹ���");
				for(i=3;i>0;i--)
				{
					printf("%hd��󷵻���ҳ����",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				system("cls");
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				gotoxy(10,28);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,29);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,30);for(i=0;i<111;i++)printf(" ");//���ԭ������
				gotoxy(10,28);printf("�޸ĳɹ���");
				for(i=3;i>0;i--)
				{
					printf("%hd��󷵻���һ������",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				system("cls");
				goto return_loop;
			}
			if(33*Pixel.width+Pixel.width/2<x&&x<44*Pixel.width+Pixel.width/2&&27*Pixel.height+Pixel.height/2<y&&y<29*Pixel.height+Pixel.height/2)	//��������޸�
				goto loop2;
		}
		if(GetAsyncKeyState(VK_MENU)&&GetAsyncKeyState(VK_CONTROL))																					//ctrl+alt�����������޸�
			goto loop2;
	}
/******************��ת���ؽ���***********************/
}



/************

����3.ɾ����Ϣ

*************/
/*����������������������������������������������������������������*/

void data_delete()//��Ϣɾ������
{
	FILE *fp;			//�������ļ�
	ALUMNI *head,*p;	//�����ͷָ�룬��������ڵ�ָ��
	uint16 i;			//����ѭ��ʹ��
	POINT *point;		//����POINT�ṹ����洢�������
	LPRECT rect;		//����LPRECT�ṹ��ָ��洢����������Ϣ
	int16 judgment;		//����������λ���ж�
	uint16 buf;			//���ݿ�����
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
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<100;i++)printf(" ");
	gotoxy(11,2);printf("�Ƿ�ȷ����ʼɾ����");
	return_key();
	gotoxy(5,2);printf("��ʼ");
	gotoxy(1,1);
	while(1)
	{
		GetWindowRect(hwnd,rect);
		GetCursorPos(point);
		if(GetAsyncKeyState(VK_LBUTTON))//�������������
		{
			int16 x=point->x-rect->left-6,y=point->y-rect->top-30;//�����λ�ö��ڿ���̨���������
			if(3*Pixel.width-Pixel.width/2<x&&x<9*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//�����ʼ
			{
				system("cls");
				break;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//���������һ��
			{
				system("cls");
				return;
			}
		}
	}
return_loop:
	data_display_form1(head);
	gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
loop3:gotoxy(11,2);printf("��������Ҫɾ����Ϣ��У����ţ�");
	{
		int16 number;
		if(!scanf("%hd",&number)||number>buf)
		{
			gotoxy(11,2);for(i=0;i<99;i++)printf(" ");
			gotoxy(9+80+2,2);printf("�����������룡");
			fflush(stdin);
			goto loop3;
		}
		p=head;
		for(i=0;buf-number>i;i++)	//pָ��ָ���ڵ�
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
	gotoxy(11,2);printf("�Ƿ����ɾ����");
/******************��ת����***********************/
	return_key();
	gotoxy(114,2);printf("����");
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
				fp=fopen("data.dat","wb");
				p=head;
				while(p->link_ahead!=NULL)	//pָ�����һ���ڵ㣬��Ϊ��������Ľڵ�
					p=p->link_ahead;
				i=1;
				while(p!=NULL)				//��ʼ���α��浽�ļ���
				{
					p->number=i;
					fwrite(p,sizeof(ALUMNI),1,fp);
					p=p->link_back;
					i++;
				}
				fclose(fp);
				gotoxy(10,3);printf("ɾ���ɹ���");
				for(i=3;i>0;i--)
				{
					printf("%hd��󷵻���ҳ����",i);
					Sleep(1000);
					printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				}
				return;
			}
			if(112*Pixel.width-Pixel.width/2<x&&x<118*Pixel.width-Pixel.width/2&&1*Pixel.height-Pixel.height/2<y&&y<3*Pixel.height-Pixel.height/2)//����ɾ��
			{
				system("cls");
				goto return_loop;
			}
		}
	}
/******************��ת���ؽ���***********************/
}




/************

���ݸ�ԭ����				*****����ʹ��*****

*************/
/*����������������������������������������������������������������*/
void renew()//�����ݳ�ʼ������ֹ�������������������ݶ�ʧ
{
	FILE *fp;			//�������ļ�
	//ALUMNI *head,*p;	//�����ͷָ�룬��������ڵ�ָ��
	ALUMNI alumni1={/*���*/1,/*��ѧ���*/1984,/*����*/"�곤��",/*��У���*/"��������ѧУ��������������",/*ϵ��*/"����",/*�о�����*/"�߷��Ӽ��临�ϲ��ϳ��ͼӹ���ģ���Ż�������������������ۡ���������ֵģ�ⷽ�����о�����",/*���*/"�곤�꣬�й���Ա�����壬1963��6�³��������������ˣ��й���ѧԺԺʿ�����ҽܳ������ѧ�������ߣ���973����Ŀ��ϯ��ѧ�ҡ����ι����г��ල�����ֵܾ����Ա������֪ʶ��Ȩ�־ֳ���������ǡ�",/*��Ҫ�ɾ�1*/"���ϳ��͹�����ֵģ�⡣�곤��Ժʿ��չ��ע�ܳ�����ά��������ѹ����ȴ���������εȹ��̵�����ģ�ͺ���ֵ���㷽�����ر���ע�ܡ�עѹ��΢ע�ܵȳ��͹��̳���/��ѹ����ѧģ�͡���ȴ�����ı߽�Ԫ�������ۣ���Ӧ������Ʒ�������Ρ����ͺ�ģ��һ�廯��͸�����ϳ������ѧ��ΪԤ��ȼ������ۺͷ�������Ͻᾧ��ȡ���΢�ṹ�ݻ��Ķ�߶ȷ������۵ȣ����ֿ���������֪ʶ��Ȩ����ģCAE����� [9]  ��Ϊ��һ����ˣ���سɹ���ע�ܳ���ģ�߼���Ʒ�����������̵ļ�������ɼ��������1996��ȹ��ҿƼ��������Ƚ���",/*��Ҫ�ɾ�2*/"����ģ���Ż���������졣�곤��Ժʿ���������ϳ��ͷ����ԡ���̬��˲̬����Ϻͷ����ϵͳ����������ȷ����Ļ������ۺ��㷨���ر���ע��ģ��ȴϵͳ�����ȱ߽�Ԫ�������ۣ�����ǰ��λ�á��ٶȺ�ѹ������Ʊ���Ӱ�����״����������Ԫ�������۵ȣ���չ�����������Ϊ�ĳ��͹��ա�ģ������Լ���Ʒ�ṹ��Ƶ�һ�廯�Ż�ģ�ͣ��Լ�������Ʒ�ṹ��̬�����ܿ��Ƶĳ��͹����Ż��Ͷ�Ŀ��ģ���Ż�������ۺͷ����������ϵ�����Ͻṹ��Ʒ�����͡��������ԡ����������ԡ��͡����տ��Ƽ�ģ���Ż����ȹؼ����⡣ [9]  ��Ϊ��һ����ˣ���سɹ�������ģ�����ľۺ���ӹ���ģ���Ż������Ӧ�á����2003��ȹ��ҿƼ��������Ƚ��� [10]",/*��Ҫ�ɾ�3*/"����ս�Բ�Ʒ�����ơ��곤��Ժʿ��������ˡ����ߡ����պ����ͷ���洰�����ƣ������Ƶ�ͷ���洰�߱��˸ߵ��»����µĸ߿�������ܡ����ӻ����µķ����������͸߹���͸���ʵ����⹦�ܣ�Ϊ�ҹ�������ջ������ͻ������ [11]  ��2009���ٻ��й����˺��칤��ͻ�����׽����� [8]  �ڴ˻����ϣ������Ŷ��ֳе�������ҹ�����š��� ����ʮһ�����ẽ��Աͷ���洰��̫�չ���վ�����洰���������񣬽���˺�����Ʒ�ĸ��ٳ����Ϊ����������ֵ�������ۡ��ߵ��»����������Ⱥ�����ʷ��΢�ṹ�������������ơ����ӻ����µķ�����ΪԤ��ȹؼ����⣬Ϊ�ҹ�����Ա�����ڹ�פ���ṩ�˱��ϡ������Ŷӻ���ˡ��ռ�ʵ����������ͻ������Э��λ����2017�꣩ [12]  �����˺���ս�Բ�Ʒ�������⣬�����Ŷ�Ŀǰ�����ֳе����ҹ����ս�Բ�Ʒ�����������ѳ�Ϊ�ҹ�ս���ø߷��Ӽ��临�ϲ��ϲ�Ʒ���Ƶ���Ҫ������ [2]"};
	ALUMNI alumni2={/*���*/2,/*��ѧ���*/1977,/*����*/"������",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"���󹤳���ѧ",/*�о�����*/"ʯ��",/*���*/"��������1957��3�³�����Ӣ����³ŵ����ѧ���󹤳�ѧ��ʿ����ǰ�����ּ̾������޹�˾���³������ֹ̾������޹�˾��ϯ���������ж��³����й���ɽ���������ţ��ɷ����޹�˾���³��ȡ��������ڳ���ʯ�ͻ��عɷ����޹�˾�����ܾ�������ۺ��ɷ����޹�˾���³����й���ɽ���������ţ��ɷ����޹�˾�ܾ�����������������޹�˾��ϯ�����ּ̾������޹�˾���ܲá����ּ̾������޹�˾�ܲá���ְ��",/*��Ҫ�ɾ�1*/"2010��8��23�գ����ּ̾������޹�˾������ٿ��ɲ���ᣬ������ȥ�������ּ̾��Ŷ��³�ְ���ɸ��������Ρ�ͬʱ��ȥ���������ּ̾����ܲ�ְ��������쵣�����ּ̾��Ŷ��¡��ܲá�",/*��Ҫ�ɾ�2*/"2014��4�£����λ��󣨼��ţ����޹�˾���³������ٵ������ּ̾��Ŷ��³�ְ��",/*��Ҫ�ɾ�3*/"2020��7�£����ٵ��λ��󣨼��ţ����޹�˾���³�ְ��"};
	ALUMNI alumni3={/*���*/3,/*��ѧ���*/1984,/*����*/"���Ĳ�",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"����רҵ",/*�о�����*/"���̽����е",/*���*/"���Ĳ������̻�еר�ҡ��߼�����ʦ��������һ�ع��ɷ����޹�˾�ܲá�1984���ҵ�ں��ϴ�ѧ��е��������רҵ����ѧѧʿѧλ�� ��ҵ�󱻷��䵽�˱�����ҵ����Դ��е���ŷֳ���������Դ�з��ų����������Ĳ����Ⱥ��ڴ�������ѧ����רҵ����ŷ������ѧԺ���̹���רҵѧϰ����ѧ˶ʿѧλ���й����̻�е��ҵЭ����й������е��ҵЭ�᳣�����¡�����Ժ������ҵ���ŷ�չ�о����ĵ�һ�����»����¡�����ʡ����ó����֯�о������¡������豸������Э���Ա�����Ͻ�ְͨҵ����ѧԺ��ְ��Ժ������ɳ�й������ϻḱ�᳤����ɳ����Ӫ�����о��ḱ�᳤��2002�꣬���Ĳ������ٻ��й�������Ӫ�Ƽ���ҵ�ҽ�������2002���Ͼ������ܳ���ҵ�ҽ�����2012��10��1�գ���һ�����������߰°����CFIUS��18�����Ĳ��ڱ����ٿ�ý�幵ͨ�ᣬ�й�ר�ҳƣ������˾������������ί�Ǹû������������ĵ�һ�Σ�ʷ��ǰ����",/*��Ҫ�ɾ�1*/"��һ�ع��ɷ����޹�˾���й����̻�е��ҵ��һ�����е���Ӫ��ҵ��Ҳ�Ǻ���ʡ��һ�����е���Ӫ��ҵ��������ƷΪ���̽����е����������е���й��г�ռ���ʵ�һ������ȫ����˽��ڡ�",/*��Ҫ�ɾ�2*/"2010���CCTV���й�����������20����ѡ��������ʽ�ҿ���ɴ��������ߵ���һ�ع��ܲ����Ĳ�ȴ������ѡ����Ȼֹ������ʽ��ѡ�ˣ�ȴ�������Ĳ������ò��͵�һ�ˡ��ļ�ֵ���ڡ���Ȳƾ����͡���ѡ�У����Ĳ���ѹ��������ʼ�������ھ�����������������������ȣ���ӽ�50%������֧���������Ĳ���Ϊ���ˡ���Ȳƾ����͡��ý�������ߵ��ˡ�",/*��Ҫ�ɾ�3*/"2011��5��31�գ��ձ���ͬͨ���硢�ձ����������硢�������š��������ŵ�20����ձ�Ȩ������ý���ŵ�����һ�ع���ɳ��ҵ԰����Ϥ���ձ�ý���Ŵ˷����ã�һ����Ϊ�˸�л�Ժ˵�վʩ��Ԯ�ֵ��й���Ԯ��������һ����Ҳ��Ϊ�����ձ����ڽ�һ���˽⡰��һ�ع�������й���ҵ��"};
	ALUMNI alumni4={/*���*/4,/*��ѧ���*/1997,/*����*/"˾��",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"��е����ѧԺ��е������켰���Զ���רҵ",/*�о�����*/"�����������еѧϵ��е����",/*���*/"˾�£��У����壬1979��12����������פ����ˣ�1998��12���뵳��2004��8�²μӹ������о���ѧ����˶ʿѧλ�����ι����Ž���ʡί��ǡ�",/*��Ҫ�ɾ�1*/"2018��04�¡���2019��01�£��Ͼ����ػ���ί����ǣ�����������������������",/*��Ҫ�ɾ�2*/"2019��01�¡���2020��05�£��Ͼ����ػ���ί����ǡ�����",/*��Ҫ�ɾ�3*/"2020��05�¡����������Ž���ʡί��ǡ�"};
	ALUMNI alumni5={/*���*/5,/*��ѧ���*/2004,/*����*/"�������ᡤľ���︦",/*��У���*/"����ѧѧʿ",/*ϵ��*/"����������ѧ",/*�о�����*/"���",/*���*/"�������ᡤľ���︦��������³ľ�룬��������ʦ��ĸ����ҽ�������ﻹ���������ã�һ�������Ѿ���������һ�����û����ϴ�ѧ���������ᡤľ���︦˵����������Ǵ�С�ϸ�Ҫ�󣬼ǵ��ں�С��ʱ�����Ͷ������ǵĶ��������������ڴ�С���󣬺ܶ����鶼���Լ������������磺��ʲô��ѧ����ʲô��������ѧ��ҵ���������ڵػ��ǻ��½�����Щ���ڳɳ��еġ�������¡��������Լ������⡣����δ�����������ᡤľ���︦˵��������30��֮ǰ������ӣ��������Լ�ѧϰ����֪ʶ����������о��������ۿ������о�������һ��Ҫ������һ��ע�Ὠ��ʦ������ҵ3�����ϵĲ��ܱ����ģ����ѹ������꣬����һ��ʱ�䣬������һ���Ҵ���úø�ϰ����ȡһ��ͨ������",/*��Ҫ�ɾ�1*/"��ʲ�ϳ��������ַ����죬һ�״��ӳ���ѧ������Զ���۲��ң�80�����и߹�ռ���Ƭ�۲���Զ���۲���",/*��Ҫ�ɾ�2*/"�ܳ��ɾͽ�����ѽ���������ס�����ر𽱡����꽨��ʦ�����������۽�����ί���ر𽱡���ʲ�ϳǰ����ַ����졢���������̬�ǽ����߹�Ԣ��̨��88ˮ��ԭס�����ؽ���̨�壩3����Ŀ��Χ����ס�����ر𽱡������գ���ʲ�ϳǰ����ַ����졢���������̬�ǽ����߹�Ԣ��á���ס�����ر𽱡���",/*��Ҫ�ɾ�3*/"��ʲ�ϳ��������о��ͷ�ò�����о�����ʲ��̨��ӿ���ӹ̱������о���"};
	ALUMNI alumni6={/*���*/6,/*��ѧ���*/1967,/*����*/"������",/*��У���*/"���̹���˶ʿѧʿ",/*ϵ��*/"���̹���",/*�о�����*/"���̹���",/*���*/"�����ԣ��У����壬1955��3������ɽ������ˣ���ְ�о���ѧ�������̹���˶ʿѧλ�� 1969��6�²μӹ�����1973��7�¼����й������������ι�����ҵ�־ֳ���������ǡ�2017��10��14�գ��й���������ʮ�˽�����ίԱ����ߴ�ȫ����鰴�յ��¹涨�������ݲ�����ίԱ���ίԱ������Ϊ����ίԱ��ίԱ��",/*��Ҫ�ɾ�1*/"2015.06����2015.07��������ҵ�־ֳ���",/*��Ҫ�ɾ�2*/"�й���ѧ���ʮһ�����»����³�",/*��Ҫ�ɾ�3*/"�й�������ʮ�Ĵ�ʮ����ʮ�ߴ�ʮ�˴����ʮ�˽�����ίԱ���Ž�ȫ���˴�����˽�ȫ����ЭίԱ��������ʮ�������볣ί��"};
	ALUMNI alumni7={/*���*/7,/*��ѧ���*/1978,/*����*/"��Т��",/*��У���*/"���ڣ���ʿ�о�����ʦ",/*ϵ��*/"��ϸ����רҵ",/*�о�����*/"1���������ӫ��̽�� 2��������Ⱦ�ϡ����ϼ��乤ҵӦ��",/*���*/"��Т�����У�1962���������ʿѧλ�����ڣ���ʿ�о�����ʦ�����ҽܳ�����������ߣ�2007��������Ժѧ���������Ա��2009-�����й���ѧԺԺʿ(2017)�����ξ�ϸ���������ص�ʵ�������Σ�����ʡ��ϸ�������̼����������Ρ����˴����и���ί��",/*��Ҫ�ɾ�1*/"210 Guanghui Cheng , Jiangli Fan*, Wen Sun , Jianfang Cao, Chong Hu , and Xiaojun Peng*. A Near-infrared Fluorescent Probe for Selective Detection of HClO Based on Se-sensitized Aggregation of Heptamethine Cyanine Dye, Chem. Commun., 2014, 50 (8), 1018-1020.",/*��Ҫ�ɾ�2*/"209 Jiangli Fan*, Huijuan Dong, Mingming Hu, Jingyun Wang, Hua Zhang, Hao Zhu, Wen Sun, Xiaojun Peng*. Fluorescence Imaging Lysosome Changes During Cell Division and Apoptosis with a Nile Blue Based Near-infrared Emission, Chem. Commun., 2014, 50 (7), 882-884.",/*��Ҫ�ɾ�3*/"208 Hao Zhu, Jiangli Fan,* Shiling Zhang, Jianfang Cao, Kedong Song, Dan Ge, Huijuan Dong, Jingyun Wang, and Xiaojun Peng*a. Ratiometric Fluorescence Imaging of Lysosomal Zn2+ Release under Oxidative Stress in Neural Stem Cells, Biomater. Sci., 2014, 2 (1), 89-97."};
	ALUMNI alumni8={/*���*/8,/*��ѧ���*/1976,/*����*/"������",/*��У���*/"��ҵ����У����",/*ϵ��*/"��е���칤�ռ��豸",/*�о�����*/"��ҵ����У����",/*���*/"��������������ίԭ��ί��ͳս��ԭ����������У�ѻ�־Ը�ߡ�1976�ꡪ1980�꣬���ƾͶ�����У��е���칤�ռ��豸רҵ����ҵ����У�������Ⱥ���Уѧ�������鳤��У��ί����ǡ���ǣ�����δ����й����������ڹ���֧��ĸУ��չ����2016��8�·���ȫ����Ͷ�뵽У�ѹ����У������ڶ�У��Ϊ����У�ѻ�Ľ���ͷ�չ������Ҫ���ס�",/*��Ҫ�ɾ�1*/"������ĸУ���������ر�ĸУ���˶�����һֱ��ǣ�ҡ������Ǵ�У�����ĵط���ĸУһֱ�ڴ��ڴ���У����ѡһλУ�ѹ�����������2016�꣬������������ԭ���뿪�쵼��λ����ĸУ�쵼�ҵ�����������ǣͷ����У�ѻṤ��ʱ�������ؽ��������룬�Ӵ�ȫ����Ͷ��У�ѻṤ��֮�С��ط�У�ѻ�����ϵУ����ĸУ�Լ��ط���������Ŧ����У�ѻṤ��������չ��������ͣ����һ���Ե������ϣ�У�ѻ�ĸ��������Ƿ���ֻ�аѷ����������ˡ�����λ�ˣ�У�ѻ���ܳ�����������������˵������У�ѻ�һ���˾�������˼���о������������У�ѻṤ��Ҫ��֡�����У�ѡ�����ĸУ������ط�������ᷢչ������ּ�����ڡ��������ѳ�Ϊ����У�ѻ����µĹ�ʶ�������Ե�ϵ��ʵ���ȡ���˿�ϲ�ɹ���",/*��Ҫ�ɾ�2*/"У�ѻ����ǣ�ߴ��ţ��ٳ���ĸУ������д��������ġ����������ݿƼ����޹�˾����ۼ��Ź��������д����ݲ�ҵ�о�Ժ��Ŀ������������ѧ�����ϵĳ������־��÷�չ����ʽ�������Ͷ����ǿ⣻�����ٽ�ĸУ������������»�����������ȫ��λ�������ٳɺ������Э�飻�������пƼ����Ƽ�����ѧ������ƽ�������ֵĵ��µ���������ɱ�����Ŀ���ٽ�У�غ�����Ӯ��������ʡ����ν�ר��ѧ�߸�½��У�ѹ�ְ���߷�����ɽ����е��ʵ�ò�����ο���ʵ�ؿ��죬Ϊ�������ұ������ʹ�԰������ɽ�������˹ؼ����ã���֯�йط���У������Ф���У�ѵ��δ��һ��ǵĽ������������ʵ�ؿ��죬�ٳ��˰������ĸУ����ѧԺ��������ȫ���ˡ����ء���һϵ�л���Ͻ��������񡱹����������롣",/*��Ҫ�ɾ�3*/"�ḻ��ʵ�����ʹ����У�ѻ����������������չУ������ʵ���������У�ѳɳ�֮·�����ţ���У�������Լ�����������������������Уѧ��ѧ�ý�������Ϊ����ȫ���ˡ�����Ҫ��������֯���質ΰ����� �ܶ�ΰ��ʱ������ף���й�����70���������ɽ����ڡ����ĸ���Ұ��㡱���ź����У���У������ӯ���������ڴ���20������УУ�ѻṲͬ��֯�����Ƕ���׷���ˡ�����������ʱ����2020���ܴ����������������Ϊ �����ܴ�������һ�����㣻�����Ƕ���׷���ˡ�����������ǰ�塱����һ�������˶�ͽ����ᡢ��У�ѱ�����ë������ƹ����������Ϊһ�������˶�������У�ѻ��Ʒ�ƻ���߽����ۻ������ģ�ΪУ�Ѽ�������չ����ҽ����������֯У����ҵ�߽�ĸУ��ƸУ�ѣ�����ѧ��ѧ�ô��´�ҵ����չ������ѧ��ӭ�㣬У�ѽ����ϴ�ѧ��ӭ�ӱ�����������ѧ���ĸУУ��70����֮�ʣ���֯��У�ѿ�չ���ط�ĸУ���ɾ͡�����ĸУ���ɳ�����У���ͬʱ��֯300����У�Ѳμ�У�챼���ջ������ΪУʷ����������Ժ���ĵ��ܾ������ 30���ƿ��ô󹤶�Ůʼ�ղ������ģ���֯�̻��߽�ĸУ���߷��ص�У�ѡ�����ӭ�¡��´��Űݻ�ȵȣ���һ�������������Ļ���ô���У�ѻ��Ϊ��ϵ����У�ѵ�Ŧ�����ٽ�����������ƽ̨��չʾУ�ѲŻ�����̨������У�Ѵ��к�ɫ���򣬲������ġ��ܷ����ϵ���Ҫ���塣"};
	ALUMNI alumni9={/*���*/9,/*��ѧ���*/1990,/*����*/"��־��",/*��У���*/"���κ���һԺһ�������鸱�鳤���鳤�����������������Ρ������ε�ְ",/*ϵ��*/"������ѧרҵ",/*�о�����*/"������ṹ���Ƽ���",/*���*/"��־�⣬1990�ꡪ1992��˶ʿ�Ͷ�����У������ѧרҵ���й����ػ�������о�Ժ��ϯר�ҡ��ͺ����帱��ʦ�����κ���һԺһ�������鸱�鳤���鳤�����������������Ρ������ε�ְ���Ǻ���һԺһ������У�����ĺ���ṹǿ�ȷ��������������Ρ�������Ƽ�һ�Ƚ�1����Ƚ�1�����Ƽ�����һ�Ƚ�1����Ƚ�1����Ƚ�3��Ⱥ���Ϊ������ṹ������ơ��������ʦ���������쵼���μ����й����ػ�������о�Ժ���󲿷ֺ����ͺŵ����ƹ������ڶ�������ͺ����ƹ����У���Ϊ���������ˣ���֯����˶������ṹ���Ƽ������غͶ����ش�Ԥ���о����⡣",/*��Ҫ�ɾ�1*/"ǰ�����Ա�Ӽ��ֵ���̫�պ�NASA�������ֵǡ�Լ��ѷ����ʱ��������ͳ�����һ���ؼ����飺������ͨ������ӡ����̵�̫�ռ����ɾ�ʹ���������ϵ�������������������Ŀ��̫�ճɾ�Խ��Խ��������Ϊ���쵼�������Ҫ��־��������֮��21���͵����磬���켼�����Ǵ����������ԡ�",/*��Ҫ�ɾ�2*/"��־��Ҳ���ഺ���׸����й��ĺ�����ҵ�����������Ӱ�ӵ㼸�������ĳ�̬����λ�ձ�ҵʱ������С���Ӱ����˰�ͷ�������������ƣ�ʼ�ղ������һ˿���������磬�������˵����Ρ�����ϸʵ��ֵ�������ÿһ�̡��й����ػ�������о�Ժ��ϯר�ҳƺš������Ƽ�һ�Ƚ�������Ƽ�����һ�Ƚ�������Щ����������־�����ึ����֤����",/*��Ҫ�ɾ�3*/"Ȼ���������ı����������ᣬ���ҶԼ���ʼ�ջ����п�Ƿ�ġ�����־�������˼��ˣ�����Ů���ϸ��е�ʱ���Ҿ���֪�������ĸ��༶����һ�Σ�Ů����ͬ���ͬѧ�۲ͣ������ҳ�ҲһͬС�ۣ�Ů��ͬѧ�ļҳ�������־�ⶼʮ�־��ȣ������˽⵽�������Լ�û�ܹ�Ů������ѧ���ͺͼҳ��ᣬ���ϵļҳ�����ΪŮ�������ڡ����׼�ͥ����"};
	ALUMNI alumni10={/*���*/10,/*��ѧ���*/1980,/*����*/"ʷ۔",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"��������רҵ",/*�о�����*/"��������",/*���*/"ʷ۔��������ҵ��ѧ������ѧԺ����ϵ���ڣ�1980�ꡪ1984�꣬���ƾͶ�����У��������רҵ��1997��񶫾���ҵ��ѧ��ѧ��ʿѧλ���Ƕ�����ҵ��ѧ��ѧ����������ʷ����λ��ý���ְλ���й���ѧ�ߡ�2007�꣬�����Ļ���Ŭ���£��ٳ��˶�����ҵ��ѧ������ѧ������У�Ľ������Ϲ�������ǿ��רҵ��������ģʽ��������ҵ��ѧί���շ���ʦ��פ�������ѧУ����רҵ�Ρ�2018�꣬���ִٳ���У�������Ϲ��̣�����ǿ����רҵ�붫����ҵ��ѧ�ġ�3+2������������Ŀ��Ϊ��У����ѧ�Ʒ�չ���˲�����������������",/*��Ҫ�ɾ�1*/"7��ѧϰ���������ϲ�����չ�����ջ��˳ɾ�Ҳ�ջ������š��ܷ���רҵ���и���ͻ�ƣ�ʷ۔һֱ��˼������Ŭ�������ڵ�ʱ�ܵõ�һ�γ�������Ļ��ᣬ�Ҿ����Լ��ر����ˡ��� �����ݴ�ѧ�ӽ��ڼ䣬��Ϊ�ۺ�����ͻ��������ѡ�ι��ɸ��ձ�������ʿѧλ���˴λ����ȫ��ʷ۔�ļ�֡�",/*��Ҫ�ɾ�2*/"��Ϊ��������ƣ�������̨�豸�ڸ������ܵ������ϲ������ر����ƣ�ʷ۔һ����ʵ�飬һ�ߺͳ������ָĽ������������ܶ������ҹҹ������������̨�豸��ȫ����������ܣ��������豸�ĸ����Ƚ����ܣ����Ե���Ӧ�ֵ�ȥʹ���豸���ʵ���ˡ���̨�豸ٲȻ�ѳ�Ϊ�������ܵ�ս�ѣ�����һ�𲢼���ս̽���������ϵ�����Ͱ����ʵ���о�����������������������뷨���Լ����ĵõ��Ŀɿ����ݺͽ����ʱ���Ʒ����������������ǽ̿����мȶ��Ľ��ۣ��������ܹ�����̵���ᵽ���о���һ�����Ϸ񶨡����ϴ��µĹ��̡���������̨�豸��ʷ۔����������������ͻ�ѧ��������������ķ������ɹ��غϳ�����ƽ��״̬�²����ڵ������ܵ�̼����������ϲ���������̬������ĵ��γɻ��ƺ��ȶ����ƣ�Ϊ����̬���ϵ�Ӧ�õ춨�˻�����ͬʱ�Խ����ͷǾ�̼�����׸���Ĥ�Ͷ�㱡Ĥ�����ܣ��ر��ǵ�ѧ���ܺʹ�ѧ���ܽ�����ϵͳ�о���Ϊ���ֽṹ�Ĳ���Ӧ���ṩ�����ۻ�������Щ�ɹ�Ҳ����˳������˲�ʿѧλ��",/*��Ҫ�ɾ�3*/"2007�꣬��Դ�������ѧ���Ͽ�ѧ�빤��ѧԺ����ǿ����İ�ѧ��ɫ����ʷ۔����У��λ��ʦ��Ŭ��֮�£������ԡ�����רҵ�����Ĵ�ѧ�ڽ�����������ǣ���ˡ������۶Դ󹤻��Ƕ��������ڹ��ʺ��������ϵ�һ����Ⱥ������������ڱ��ƽ������档֮��� 10��䣬��ʷ۔��Э���ٽ�֮�£����Ͽ�ѧ�빤��ѧԺ½��ӭ���˰����������ˮ���ؽ��ڡ���ɽ������ڵȲ���רҵ�����8λ����֪��ר�ҽ��ڣ����Ǻ�ʷ۔һ��վ���ϴ󹤵Ľ��ã�Ϊ��ѧ���Ͽ�500ѧʱ������ѧ��160����������ʮ�ָ�л��Щ֧�ְ�����У�����Ķ������ͬ�¡��󹤵���ʦ�����ѡ�û�����ǵ�֧��������Щ���ǲ����ܵġ���Ҳʮ����ο�ؿ�����Щ����������ѧ�����ǳ����㣬��ҵ�������������������ǳ���Ծ����"};
	ALUMNI alumni11={/*���*/11,/*��ѧ���*/1982,/*����*/"��Ԫ��",/*��У���*/"��ȼ��רҵ��ʿ",/*ϵ��*/"��ȼ��רҵ",/*�о�����*/"��ȼ��",/*���*/"1974����Ԫ�����Ĵ���Ϊһ��֪�౻�Ƽ��ϴ󹤶��飬���Ǹ��������������Ȼ����ϧ�����֮���׵�ѧϰ���ᡣ�����Ķ���ʮ�ֺ��䣬����Щ��ȼ�Ϻ�������������һ����ȱ��ů��ÿ��ֻ����һ������Сʱ���յ��Ľ��Ҹ������˴���ס�������γ¼�����ʦ���������������Ԫ��ʱ˵��:�������ܿ���һ���������¡���ͦ�ߵ��������Ƕ�ѧϰ�����¼��ȵ���ϰ���ﳣ������һ���ˡ���������ѧ��ʼ�Ҿ������ĸûѧ��ʲô���������뾲�������úö��飬���ڴ�ѧ���Ǽ����ܵ��ĸ���Ҳ̫�ࡣ����Ԫ�ܸп���˵��",/*��Ҫ�ɾ�1*/"2004�꣬��Ԫ�������ع����˸ճ����ĳɶ����ص��繫˾���쵼�����Ŷӿ����������ͻ��ĺ��Ĳ����������ȼ������ϵͳ������ʮ�����Ŭ�����Ⱥ�ɹ��ؿ����˵�����ʽ����ú͸�ѹ����ϵͳ�Ȳ�Ʒ��ʵ���˲�ҵ�������г�Ҳռ��һϯ֮�ء�Ȼ������Ҳ��ʶ�����¹���������ҵ�����������㲿�������ڵļ�����������Ʒ�Ʒ���������ڿ���Ԥ����ʱ�������Գ�Խ����¢�ϵ�λҲ���Դ��ơ���ҵҪ����ͷ�չ����ø�����г�����������辶��",/*��Ҫ�ɾ�2*/"2019��12�£��ڴ�������ѧ����ɽ�۹ȱ����ڶ���У�ѿƼ���ҵ�����У���Ԫ�ܺ��Ŷӿ����Ĵ������ͻ���ѹ����ϵͳ���ڶ������Ʒ����ӱ�����������ʹ��ھ�����Ŀ�����ڵ�������ͷȡ�ý׶��Գɹ���Ϊ������Ͷ���춨�˼�ʵ�Ļ�����",/*��Ҫ�ɾ�3*/"���ڣ��Ѿ�65�����Ԫ��ÿ���Ծɹ���9-10��Сʱ������Ȼ����ʮ�����Ŭ��������ȡ����һЩ�ɹ������Ա�������˾�����Ĺ����ͷ�����ǵ���ҵ����һ����С����������Բ��ͻ���ѹ����ϵͳ�����������ҵ����¢�ϵľ��棬δ����ϣ�����������������������ܴﵽ10%���ҵ��г��ݶ���ڴ�����������һϸ��������һ���������صĵ�λ����"};
	ALUMNI alumni12={/*���*/12,/*��ѧ���*/2009,/*����*/"����",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"������Ϣ����רҵ",/*�о�����*/"������",/*���*/"��������Ϊ����������ǫ�͡������ϸ��˵ĵ�һӡ��ǰ��Դ�������¼������������������Ǳ����Դ������ʡ����ƺ��봫ͳӡ��������ᴴҵ�����󲻷�����Ϊ90�����ϱ�ͬ���˶༸�ֳ������أ���Ϊ��ҵ�ߣ��������˼��ַ��������Ψ����̸����Կ���һ�㱻��������ŵĲ���Ұ��������־��",/*��Ҫ�ɾ�1*/"˶ʿ��ҵ������ֱ�ӽ�פ���׶�Entrepreneur First������������һ��Ϊ�о���� ְ����ʿ�ṩ��ҵ��Դ��ƽ̨�������������ϻ���Rafel��ʶ�����˶�������ҵ���Ĺ���һ�ļ��ϣ����������ź��г�������ײ��Open CosmosӦ�˶�����Open Cosmos�����������棬̫���ǿ��ŵģ�˽����ҵҲ����ʹ�����ǣ�ʵ�����ǵ����á����á� ",/*��Ҫ�ɾ�2*/"����������������ƽ���󹤽�������ʵ���ң�Ϊѧ�ߺʹ�ҵ�ߴƽ̨�������ǿ���һ�����ܶ��������飬����������������������²���������������������������ϣ������һ������ʵ���ң�����������Уʦ���Լ����У�ѣ����ú��켼���ٽ������ڸ���������о���չ����",/*��Ҫ�ɾ�3*/"����Open Cosmos��Ӣ������ŷ���г����Ȳ���չ�������������𽥽�Ŀ��ת����ڡ�2018������½������ڼ��Һ��պ�������Ĺ�˾ǩ��ս�Ժ���Э�飬�����ִ����¹�˾����Ӫң��װ�ã�Ϊ�ͻ��ռ����ݣ������Ϣ����Ӧ���ڻ�������ľ������������"};
	ALUMNI alumni13={/*���*/13,/*��ѧ���*/1995,/*����*/"̷��",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"Ӧ������ѧרҵ",/*�о�����*/"����",/*���*/"���Ͻ�����ʵ�����¡����ס�������ɫ�Ĵ��֣�ʮ����Ŀ����������ʡ��������������Ӧ�ü����ص�ʵ���ҵİ�ǽ�ϡ���������ȷ���Ĺ������񣬺�����ɣ���ȡ�����Ǵ󹤣��Žᡢ��ȡ����ʵ�����¡���˵�⻰����ʵ���ҳ������Σ���УУ��̷�������41������ѳ�Ϊ�ҹ������Ƽ�ר�ҡ���ɫ���������������ǿ���Ĺ���ʹ������������У�ŵ���һ�̣���ָ�����������������ռ䷢��̽������ʮ���������Ӵ󹤵����������й���̫�ա���������У95��У�ѡ���̷����",/*��Ҫ�ɾ�1*/"ȥ��3�£�һ�򡰹������׵�������¯���������ڼ������������Ƴɹ��������ű�ý��㷺��������һ��������¯���������ڹ̷ϴ���ʾ��������Ŀ����ʱ���ڽ����γ������ȶ����г�30�죬��˹���Σ������¯���޺�������Ŀհף��л���Ⱦ��ٻ��ʿɴ�99.99%����־��Σ�ϴ���ġ��ռ����������������������ڼ����ڹ�����ʽ���빤��Ӧ�ý׶Ρ�",/*��Ҫ�ɾ�2*/"��Plasma Science & Technology������IEEE-TPS�������й����湤�̡���������ƽ�������ˣ�����ʡ�������ϻ��ʮ��ίԱ�������������ѧ����Э���Ա��1995��-1999�걾�ƾͶ�����УӦ������ѧרҵ��1999��-2006������У������������רҵ����˶ʿ����ʿ�����ڴ��º��պ���������弼��Ӧ���о����е�����ɹ�����Ȼ��ѧ����4�װ��Ԥ����Ŀ7�����973������863�����������������ƹ��ֻ������С������ƹ������ú������Ŀ�������������Ƽ�����һ�Ƚ������ҿƼ��������Ƚ�������ʡ����Ƽ����ǣ����������ƹ����±���������Ŷӣ�����ѧ�ߴ����Ŷӡ�����ѧ������50��ƪ����Ȩר��6�����7�����꼼����Ա��2015����������ѧԺ�������պ�����µ���������ϼ�������ʵ���ҡ�",/*��Ҫ�ɾ�3*/"̫�ջ����У����ƽ���������ͬ�������£��õ������巽ʽ���ռ䶯�������Աȳ��滯ѧ�ƽ��ɵø��졢��Զ�����á�����չ���죬�������С���̽������δ֪�ռ䣬��չ��������̫�յĽŲ������춯���Ǿ��������ء������ѧ�����˵�������й�����������ж���й��������̨���ж�󡱣�����Ը����Զ��ãã���棬���躽��ǿ������ʷʹ����Ҫ�����������о������Ӹ�Ч���������������߱ȳ塢���������ĺ��춯����̷��˵��������һֱ��ͬ�������ܣ�ϣ���ҹ�����δ��ʮ�����ܹ��ﵽ�����������ʮ������Ͷ��ʹ�ã����ڹ���ǰ�С���"};
	ALUMNI alumni14={/*���*/14,/*��ѧ���*/1993,/*����*/"�¹���",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"���̽���",/*�о�����*/"������һ�š�",/*���*/"2017��5��25�գ��ҹ����������˵硰����һ�š�ȫ���׶�ʾ�����̡����к˼��Ÿ���˵�5�Ż�����ǰ15�����񷶥��װ���ڵ�װ�ֳ��������ֳ���ָ�ӳ¹��ŵ������Ѿ�˻�ƣ������ڷ���ȷ�Ϸ��٣�ָ������ƽ�����������̨�������������¼Ƭ��һƬ�β���ʱ������޲�Ϊ֮��ܡ��ж�����ʵ��������˼������ǣ������ֳ���ָ�ӳ¹����Ǵ�93��У�ѡ�",/*��Ҫ�ɾ�1*/"��ɽ�˵�վ���ܶ���������ʾ�����ú��ܽ��衰728���̡������ص���Ŀ�����й���½��һ���˵�վ����ǰ�й�û�����ú��ܽ������ؾ��飬һ�ж�Ҫ����ǰ�У���ҲΪ�й����ú˵�ķ�չ�����˻�����������һ�����˵��˲š���ҵʱ��ֵ��ɽ������ˮ�ѹ��̿������¹��Ų��빤��ȫ���̵ĵ��Թ������������ڰ�װʩ���׶��ѱ�¶���������ڰ����Σ�����¹�����ֻ���ڵ��Խ׶���취��ʱ����������Ϊ��֤��ɽ�˵�վ��200���ϵͳȫ���������У���Ҫ����һ��ͨ��ϵͳ���ٽ�����ϵͳ��ϵ��ԣ�Ȼ���ٽ�����ϵͳ��ϵ��ԣ����ȫ��ϵͳ��ϵ��ԣ����ѹأ�������ۣ�ȷ�������������������һ�¡��¹��Ÿп��������Թ����з��ֲ����������10000���ࡱ��һ���ʱ����¹��ź����й��̽�����һ��û��ûҹ�ع���������û����ĩ����ҹ˯�ڹ����ֳ�Ҳ�Ǽҳ��㷹�����˽��ŵĹ��̵��ԣ��¹��Ż������з����ⷽ4λ���������ܾ�������ع���������ڹ����ֳ����������ǡ��ܲ�ǰ������2002�꣬��ɽ������ˮ��1�Ż�������Ͷ����ҵ���У���Ȼ��Ŀ�깤����ǰ��43�죡����Ϊֹ���¹��Ż����������������м�������ˮ��",/*��Ҫ�ɾ�2*/"�����ǹ��ҵ�һ��ש��������Ҫ����ᡣ��2004��ף��¹��ű��������ź˵����޹�˾������AP1000�˵繤�̽��裬���𹤳���Ŀ�Ľ��ȿ��ƺ�Ͷ�ʿ��ơ���δ�Ӵ���Ͷ����ع����ĳ¹��ţ�ƾ����ˡ���ѧϰ�����������������������������Ŀ��Ͷ�ʿ����������ģ���ƾ���Ӳ��רҵ������ѡ��ҵ��ר�ҿ⡱��2009��4��19�գ����ź˵�1�Ż��鿪����ʱ�ι���Ժ����������ǿ���Ե��ֳ���������������������ο�ʡ�����������¹������ֵ���Ƭ�������ź˵�չ���ĵ�һ�ž��գ�Ҳӳ���ų¹���Ϊ����ʸ־����ĳ��ġ�",/*��Ҫ�ɾ�3*/"�ݹ�����˵緢չ���������ݹ�˾��AP1000�������˵���ͣ��ӿ�ʼ���赽Ͷ������ʮ��ʱ�䡣������EPR�˵���Ŀ��2004���ڷ���������������δͶ������ͬ���ǵ������˵���ҹ�������һ�š����������Ԥ������ɣ�����������ʱ�䡣Ϊ��ʵ����һĿ�꣬�й��˵��˶��ڽ߾�ȫ����2017��5��25�գ�����˵�5�Ż�����ǰ15����ɵ�װ������ζ�Ÿù��̴�����ʩ���׶�ȫ��ת���豸��װ�׶Σ��¹�����Ϊ���ҽ�����һ������Ĵ����ΪĿǰȫ�������׶Ѻ˵罨����Ψһ���Ϲ��ڵĹ��̣���ݳɼ��ı����ǳ¹��żᶨ����������Ϊ���й��˵��Ϊ������ǿ����"};
	ALUMNI alumni15={/*���*/15,/*��ѧ���*/1983,/*����*/"������",/*��У���*/"��������ѧѧʿ",/*ϵ��*/"�����������ȴ���רҵ",/*�о�����*/"��������ѧ-���ݴ�ѧŷ�ķ�У��е������켰���Զ���רҵ���ƽ�����Ŀ",/*���*/"�����񣬴�����ŵ��������޹�˾�ܾ���1983��-1987��Ͷ�����У�����������ȴ���רҵ��1987��-1990��˶ʿ�Ͷ�����У��������רҵ��2011�꣬���������ֿ���ĸУ�������������ƴ�ѧ���������ĸУѧ���ص㣬ȷ�����Լ��ݴ�ѧŷ�ķ�У��UCI��Ϊ����������������Ĳ�иŬ�����ƶ��£�2013��5����У��UCIǩ���������¼��ͬ�����ڣ���У��һ��ѧ����UCI�μ����ڿ�����Ŀ�����UCI����У��еѧԺ���ܾ�ѧ���ֱ�չ��2�ܶ��ڿγ���Ŀ������Ŀ��˳����չ���ꡣ2014��ף�UCI����У����ѧ������еѧԺǩ����3+2��ĿЭ�飬�Ǽ��ݴ�ѧ��ʷ�ϵ�һ��������ѧǩ����3+2��ĿЭ�顣2015�꣬UCI��½���뻯����ѧ�������ѧԺǩ��3+2��ĿЭ�顣2017��4�£�UCIУ���ʴ����Ÿ�������Уǩ�����ϰ�ѧЭ�飬���������ٰ조��������ѧ-���ݴ�ѧŷ�ķ�У��е������켰���Զ���רҵ���ƽ�����Ŀ�����������й�����Ұ��һ���˲š�",/*��Ҫ�ɾ�1*/"2017��4��10�գ���ӭ����һλ����Ŀ��ˡ����������ݴ�ѧŷ�ķ�УУ��Howard Gillman���������磬������У����Howard Gillman��ǩ��У�����½ⱸ��¼����ǩ�����ϰ�ѧЭ�飬���������ٰ조��������ѧ-���ݴ�ѧŷ�ķ�У��е������켰���Զ���רҵ���ƽ�����Ŀ�����������й�����Ұ��һ���˲š�",/*��Ҫ�ɾ�2*/" ��Ȼ֪������һ�����������ȴ��Ĺ�����Ȼ������������ֻ�ж��������Ұ��ġ���ǵ�ʱ�������������û�нӵ��������棬����������ϰ��µģ������ȡ���2004��7�£����Ҷԡ�����ó�׷����������޶����䲼ʵʩ���˴��޶���ȡ������ó��ӪȨ���ż����ƣ���������ó�׾�Ӫ�ߵķ�Χ���󵽸��ˡ��������ڴ��Ĵ����������ˡ�",/*��Ҫ�ɾ�3*/"���������ȫ���ƶ��£�2013��5�£����ݴ�ѧŷ�ķ�У��ѧԺԺ��Gregory Washington����������У����ǩ���½ⱸ��¼��������У��������㡣���˫���Ի��Ͽγ����Ҫ������ʵ����һ�ö�3+2Э��ϸ�ڣ�2014��11�£���У����ѧ������ݴ�ѧŷ�ķ�У��ѧԺ��ʽǩ��3+2Э�飬Э�����ݹ涨����У������Ϣ���������ѧ���������̡��������ѧ�빤�̺�����ҽѧ����3��רҵ����������Уѧϰ3���������3+2Э����UCI��ѧ��Ҫ�������Ҫ�󣬿���UCI��ѧԺ��ɵ�4ѧ���ѧϰ���������UCI��1��˶ʿ�γ̡�ѧ���������У����ѧλ��UCI˶ʿѧλ�������������ݴ�ѧ��10����У�е�һ�����й���Уǩ������Э�飬�������ҵĵ�һ���׶��Գɹ������˺���У��еѧԺ������ѧԺ�����ѧԺҲ½������ݴ�ѧŷ�ķ�Уǩ����3+2Э�顣"};
	ALUMNI alumni16={/*���*/16,/*��ѧ���*/1939,/*����*/"�ϵ���",/*��У���*/"���ϵ������ϵ����",/*ϵ��*/"���ϵ",/*�о�����*/"���ߵ�",/*���*/"1934�꣬�ϵ��Ա�ҵ���ྩ��ѧ����ϵ�о���Ժ����У�ν̣�1939�꣬�������廪��ѧ�����ߵ����о�Ա��1941�꣬������˹̹����ѧ���ϵ˶ʿ��ҵ��1944�꣬������������ѧԺ����ϵ��ʿ��ҵ��1947�꣬���Ͼ������ѧ����ϵ���ڣ�1949�꣬�δ�����ѧ���ϵ������ϵ���Σ�1952�꣬�����żҿھ�ί��У������1961�꣬�������״﹤��ѧԺ��Ժ����1963�꣬����Ϊͨ�ű�����ѧԺ���θ�Ժ�����������У���Σ�1972�꣬������ͨ�Ź��̼���ѧУ��У����1978����1988�����Ͼ�ͨ�Ź���ѧԺ��Ժ���� [2]",/*��Ҫ�ɾ�1*/"����ս��ʱ�ڣ��й�����־Ը����ǰ�������˿ӵ�ͨ�ŵ����⣬��ʱ�����϶Ե������ߵ粨���о���Ӧ�û�û��ȡ��ͻ���Խ�չ���ϵ���һ���������ܽ�սʿ��ʹ��������ߵľ��飬��һ��������ϣ������㣬�������Ͻ����о�̽�֣�д����һƪ���ӵ����ߡ���ר�ۣ��Կӵ�ͨ�ŵĵ粨������ʽ���Կӵ����ߵķ������������ʽ�ṹ����μ���ȶ�����������ʹ���������ڵ����ܹ�ʵʩͨ�����硱��������������ҵ��˴𰸣�Ϊ����Ԯ��ʱ��Ұսͨ�����繱����һ��������",/*��Ҫ�ɾ�2*/"20����50���ĩ���ϵ��Բ����������״�ͳ�Զ���״�ȵ����ƹ���������˽������Ŵ�����Ϊ���ջ�ǰ��������״����ܵ����˼�롣 [6]",/*��Ҫ�ɾ�3*/"20����50-60������ϵ�����Ե�ʱ�й��״���ھ������ٶ�ģ�����⣬�о���������ñ��뼼���������һ���⣬������˼��ֱ��뷽���� [4]"};
	ALUMNI alumni17={/*���*/17,/*��ѧ���*/1948,/*����*/"������",/*��У���*/"������ѧ��ѧԺԺ�����滯ѧ�о����������й���ѧԺ������ѧ�����о���ǰ��",/*ϵ��*/"����",/*�о�����*/"����",/*���*/"������ͬ־1940�������Ӱ��»��������������μӴ���������Ȼ��ѧ�о��ᡣ1940����1941��μӳﱸ�ҵ�����ĵ�һ�����ƴ�ѧ �� �Ӱ���Ȼ��ѧԺ�ν�����������1942����1943�����¸�������������������ҵ�ָ��ֳ���1945����1946���ν��켽������ҵ��ʵ��������1947���δ������ض���ҵר��ѧУ��У����1948����1950���δ�����ѧ��ѧԺԺ�����滯ѧ�о����������й���ѧԺ������ѧ�����о���ǰ����1950����1981���δ�������ѧУ����1981����δ�������ѧ����У���� [1]",/*��Ҫ�ɾ�1*/"1980��5�£���Сƽ����ʱ�뿨����ͳ���Э�飬��������Ҫ�ڿƼ��Ͽ�չ���������ҹ�����һ����ѵ���ģ�ѧϰ�о������ִ��������֪ʶ�ͼ����������ҹ��ִ�����ҵ����ͿƼ������˲š���֪��Ϣ������ҹ�����������ҵ����Ҿ�ί����ظ����ˣ�����˰�������İ쵽����ȥ������Ϊ����ѧУ��չ����ѧ�Ƶ��������������Ľ���õ��˹���������ί�������������ͬ����ʱ�Ĵ�����ѧԺҪ��������ģ���Ӳ������˵���������أ�û���ִ����Ľ��ң�û�����������ר���д�����������˵�����԰�ѧ�������£�����Ҫð���ա����ɣ�����ʹ����һ����Ҳ����ȥ�ˡ���8��18�գ����й���ҵ�Ƽ����������ѵ���ġ���ʽ��ѧ��������ĳ�Ϊ�ĸ￪�ź��ҹ�ѧϰ�����������Ƚ�����˼�롢���ۺ;���ĵ�һ�����ڡ�������30������ѧƸ���˰���ŵ��������ѧ���������˹�����������ڵ�130��λ���ڡ�ר�������Ρ���ѵ���Ĳ��Ϸ�չ׳��2002�꣬�����ѵ���س�Ϊԭ���Ҿ�óίȷ���ġ�ȫ����ҵ��Ӫ��������ѵ�ص���ء����������Ҿ�óί��������ѧԺ����2006��1��13�գ��й������߼�����ѧԺ�ڴ�������ѧ���ƣ��������ѳ�Ϊȫ��������߲�����˲ŵĻ��ء�",/*��Ҫ�ɾ�2*/"��������֯�����һ�ݽ����飬��������˵����������Ϊ����ȫ��700�����ߵ�ԺУ�У�ѡ��50�����һ����Ϻá�ʦ��������ǿ����ѧ�����Ϳ���ˮƽ�ϸߣ��������������ϸߵĴ�ѧ�����������������ϸ��˶ʿ����ʿ�о�������ģҲ�ϴ��ԺУ����Ϊ�ߵȽ��������ս���ص㡣����������������������ҹ��ľ��ô�����󸺵����෴ȴ������ٺ͸�����Ч�شٽ��ص㾭�ý��衣����������ļ�ֵ�����κ�һ���ص㾭�ý�����Ŀ�ľ���Ч�����ܱ���ġ���Ϊ��Ϊ����Ͷ�ʵ���Ч���ǳ�Զ�ģ������������Թ����ġ���",/*��Ҫ�ɾ�3*/"��������ʿ���¸ߵȽ���������������ͣ�Ϊ��������ѧ�����й����������ִ���ĵ�һ�������ѧ�Ĵ�������չ��׳�������˲���ĥ��Ĺ��ס����ڳ��ڵĸߵȽ���ʵ���У�׼ȷ���ս������ɣ�����ĸﴴ�£��γ���һ��ȫ��ϵͳ���к��й�ʵ�ʡ��ľ��й���ɫ�Ľ���˼����ϵ���ѳ�Ϊ�й��ߵȽ�����ҵ�ı���Ƹ���"};
	//ALUMNI alumni18={/*���*/18,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni19={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni20={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni21={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni22={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni23={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni24={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni25={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni26={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni27={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni28={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni29={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
	//ALUMNI alumni30={/*���*/8,/*��ѧ���*/,/*����*/"",/*��У���*/"",/*ϵ��*/"",/*�о�����*/"",/*���*/"",/*��Ҫ�ɾ�1*/"",/*��Ҫ�ɾ�2*/"",/*��Ҫ�ɾ�3*/""};
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