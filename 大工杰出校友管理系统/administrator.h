#ifndef _ADMINISTRATOE_H_
#define _ADMINISTRATOE_H_

#include"common.h"
#include"include.h"

/*
 * ���ܺ�������
 */
//******����Ա����*******
void data_saving();											//�������ݺ���
void data_saveing_form();										//����ʱ�ñ��
void data_saveing_input(uint16 i,ALUMNI *p,uint16 *judgment);	//������data_saveing��������������У����Ϣ�����ж��Ƿ�����ɹ���
uint16 data_saveing_get_string(uint16 i,int8 *string);			//��Ӧ�ڱ����ת�й��ܵ��ַ����鸳ֵ����

void data_change();												//�޸����ݺ���
void data_change_form(ALUMNI *p);								//�޸���ϸ��Ϣ���

void data_delete();												//��Ϣɾ������

/*����ʹ��*/
void renew();													//�����ݳ�ʼ������ֹ�������������������ݶ�ʧ

#endif