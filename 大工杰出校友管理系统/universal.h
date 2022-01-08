#ifndef _UNIVERSAL_H_
#define _UNIVERSAL_H_

#include"common.h"
#include"include.h"

//*******通用函数********
void gotoxy(int16 x,int16 y);										//引用功能：控制台光标跳转
void rectangle(uint16 x,uint16 y,uint16 width,uint16 height);		//输出矩形，形参为矩形左上角位置x，y，宽度和高度
void return_key();													//返回首页和返回上一层按键



//*******界面函数********
void common_form();													//操作界面
void initial_key();													//初始操作键
void administrator_login();											//管理员登录
void administrator_key();											//管理员操作键
void tourist_key();													//游客操作键


//*******查询函数********
void data_display();												//信息查看函数
void data_display_form1(ALUMNI *head);								//查看简略信息表格
void data_display_form2(ALUMNI *p);									//查看详细信息表格

void data_display_pro();											//信息排序查看函数
void data_display_pro_switch_data(ALUMNI *pi,ALUMNI *pj);			//交换节点数据函数
void data_display_pro_form1(int16 *judgment);						//排序方式选择表格
void data_display_pro_form2(ALUMNI *head,int16 *judgment,uint16 buf);//排序查看简略信息表格
#endif