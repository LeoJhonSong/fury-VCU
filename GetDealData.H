#ifndef _GetData_H_
#define _GetData_H_

#include  "ADC1.H"

#define  ROUND(n)	((int)(n+0.5))
/*************************************外部引用变量声明************************************/
extern int ac_final,brAdFinal;
extern int ac_ad[2],br_ad,br_ad1;//两路油门的AD值
extern unsigned int ac_data;
extern ubyte acRealiableFlag;
/*************************************函数声明************************************/
void acDeal();//油门部分总函数
void get_ac_AD();//获取两路油门的AD值
void DataDeal(int acData);//油门曲线调整
void delay(int ms);
void brDeal();//刹车部分总函数
int acChangeLimit(int ac); //油门变化率限制

#endif 
