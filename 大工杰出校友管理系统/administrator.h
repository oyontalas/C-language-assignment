#ifndef _ADMINISTRATOE_H_
#define _ADMINISTRATOE_H_

#include"common.h"
#include"include.h"

/*
 * 功能函数声明
 */
//******管理员函数*******
void data_saving();											//输入数据函数
void data_saveing_form();										//输入时用表格
void data_saveing_input(uint16 i,ALUMNI *p,uint16 *judgment);	//服务于data_saveing函数，键盘输入校友信息并且判断是否输入成功。
uint16 data_saveing_get_string(uint16 i,int8 *string);			//对应于表格有转行功能的字符数组赋值函数

void data_change();												//修改数据函数
void data_change_form(ALUMNI *p);								//修改详细信息表格

void data_delete();												//信息删除函数

/*谨慎使用*/
void renew();													//将数据初始化，防止不当操作操作导致数据丢失

#endif