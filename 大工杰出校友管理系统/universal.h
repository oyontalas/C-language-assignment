#ifndef _UNIVERSAL_H_
#define _UNIVERSAL_H_

#include"common.h"
#include"include.h"

//*******ͨ�ú���********
void gotoxy(int16 x,int16 y);										//���ù��ܣ�����̨�����ת
void rectangle(uint16 x,uint16 y,uint16 width,uint16 height);		//������Σ��β�Ϊ�������Ͻ�λ��x��y����Ⱥ͸߶�
void return_key();													//������ҳ�ͷ�����һ�㰴��



//*******���溯��********
void common_form();													//��������
void initial_key();													//��ʼ������
void administrator_login();											//����Ա��¼
void administrator_key();											//����Ա������
void tourist_key();													//�οͲ�����


//*******��ѯ����********
void data_display();												//��Ϣ�鿴����
void data_display_form1(ALUMNI *head);								//�鿴������Ϣ���
void data_display_form2(ALUMNI *p);									//�鿴��ϸ��Ϣ���

void data_display_pro();											//��Ϣ����鿴����
void data_display_pro_switch_data(ALUMNI *pi,ALUMNI *pj);			//�����ڵ����ݺ���
void data_display_pro_form1(int16 *judgment);						//����ʽѡ����
void data_display_pro_form2(ALUMNI *head,int16 *judgment,uint16 buf);//����鿴������Ϣ���
#endif