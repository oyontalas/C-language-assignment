#ifndef _COMMON_H_
#define _COMMON_H_

/*
 * 数据类型声明
 */
typedef unsigned char       uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int   uint32; /* 32 bits */

typedef char                int8;   /*  8 bits */
typedef short int			int16;  /* 16 bits */
typedef long  int           int32;  /* 32 bits */



/*
 * 全局声明
 */

struct alumni_information		//校友信息结构体
{
	uint16	number;
	int16	year;
	int8	name[20];
	int8	identity[200];
	int8	department[200];
	int8	desearch_areas[200];
	int8	introduction[5000];
	int8	major_achievements[3][3000];
	struct alumni_information *link_ahead,*link_back;
};
typedef struct alumni_information ALUMNI;


//通用表头汉字
static int8 *title[10]={"姓名","入学年份","在校身份","系别","研究领域","简介","主要成就1","主要成就2","主要成就3","序号"};

//系统一个光标的像素高度与宽度
static struct{int16 height;int16 width;} Pixel={16,8};

//账户与密码
static struct{int8 account[100];int8 password[100];} Manager={"管理者","123123"};


/*
 * 通用头文件
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <windows.h>
#include <conio.h>


/********************************************************************/
#endif