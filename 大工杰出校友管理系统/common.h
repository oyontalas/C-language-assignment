#ifndef _COMMON_H_
#define _COMMON_H_

/*
 * ������������
 */
typedef unsigned char       uint8;  /*  8 bits */
typedef unsigned short int	uint16; /* 16 bits */
typedef unsigned long int   uint32; /* 32 bits */

typedef char                int8;   /*  8 bits */
typedef short int			int16;  /* 16 bits */
typedef long  int           int32;  /* 32 bits */



/*
 * ȫ������
 */

struct alumni_information		//У����Ϣ�ṹ��
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


//ͨ�ñ�ͷ����
static int8 *title[10]={"����","��ѧ���","��У���","ϵ��","�о�����","���","��Ҫ�ɾ�1","��Ҫ�ɾ�2","��Ҫ�ɾ�3","���"};

//ϵͳһ���������ظ߶�����
static struct{int16 height;int16 width;} Pixel={16,8};

//�˻�������
static struct{int8 account[100];int8 password[100];} Manager={"������","123123"};


/*
 * ͨ��ͷ�ļ�
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <windows.h>
#include <conio.h>


/********************************************************************/
#endif