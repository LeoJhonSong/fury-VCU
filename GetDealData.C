#include "MAIN.H"
#include "math.h"
/*************************************全局变量声明************************************/

/*************************************油门变量声明************************************/
int ac_ad_max[2] = { 145, 142 },ac_ad_min[2] = { 35, 25 };//最值   [0]为油门1；[1]为油门2  23, 35
int ac_w[10] =  { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };	//油门1加权  
int ac_ad[2]={0,0};//两路油门的AD值
int ac_normolize[2] = {0};//油门数据归一化值
unsigned int ac_data=0;//两油门整合后数据
int ac_final=0;//油门曲线调整后
ubyte acRealiableFlag=0,acUnRealiableCout=0; //油门数据可靠标志

/*************************************刹车变量声明************************************/

int br_ad=0,br_ad1=0,br_ad_max=540,br_ad_min=50,brAdFinal=0;  //  br_ad_min=	33


  //刹车的AD值	 最大值   最小值     最终值
void acDeal()
{
	get_ac_AD();
	DataDeal(ac_data);
//	ac_final=acChangeLimit(ac_final);
}

void get_ac_AD()
 {
 	int ac_temp_ad[4]={0,0,0,0};
	int i=0;

 	ADC1_vStartSeq0ReqChNum(0,0,0,2);
	while(!(ADC1_RCR2 & 0x1000));			//AI2，5V对应0x03FF。油门左采集		 
	ac_temp_ad[0]=((ADC1_RESR2>>2)&0x0300)>>8;	    //high 2bit
	ac_temp_ad[1]=((ADC1_RESR2>>2)&0x00ff);        	//low  8bit
	ac_ad[0] = ac_temp_ad[0] * 256 + ac_temp_ad[1];
	delay(500);	

	ADC1_vStartSeq0ReqChNum(0,0,0,4);
	while(!(ADC1_RCR4 & 0x1000));          	//AI3，5V对应0x03FF。
	ac_temp_ad[2]=((ADC1_RESR4>>2)&0x0300)>>8;		//high 2bit	  
	ac_temp_ad[3]=((ADC1_RESR4>>2)&0x00ff);			//low  8bit
	ac_ad[1]=ac_temp_ad[2]*256+ac_temp_ad[3];
	delay(500);

	
	//油门数据归一化处理 0~100

	for (i = 0; i < 2; i++)
	{
		ac_ad[i]=ac_ad[i]>ac_ad_max[i] ? ac_ad_max[i] : ac_ad[i];//实际数据限幅
		ac_ad[i] = ac_ad[i]<ac_ad_min[i] ? ac_ad_min[i] : ac_ad[i];
		ac_normolize[i] =(int)(100* (1.0*(ac_ad[i]-ac_ad_min[i]) / (ac_ad_max[i] - ac_ad_min[i])));
	}

	//油门数据整合
	 ac_data= (ac_normolize[0]+ac_normolize[1])/2;
	 //判断两路油门数据是否可靠
	 if(ac_normolize[0]-ac_normolize[1]>10||ac_normolize[1]-ac_normolize[0]>10){
	 	acUnRealiableCout++;
		if(acUnRealiableCout>20){//不可靠超过100ms，则切除动力
			acRealiableFlag=0; 
			acUnRealiableCout=0;
		}
	}
	 else 	acRealiableFlag=1;

 }
//void get_MostValue() //获取刹车和油门最值
//{
//	int i=0;
//	for (i = 0; i < 2; i++)
//	{
//		ac_br_max[i] = AD[i]> ac_br_max[i] ? AD[i] : ac_br_max[i];
//		ac_br_min[i] = AD[i]< ac_br_min[i] ? AD[i] : ac_br_min[i];
//	}
//}


/*******************************************************************************************/
/*************************************油门曲线调整*************************************/
/*******************************************************************************************/
int ac_old1=0,ac_old2=0,ac_old3=0,ac_old4=0;
void DataDeal(int acData)//油门曲线调整
{
	int ac_base= 10;//变权基值
	int ac_section = 0;//用于判断当前油门处于哪个区间
	int	ac_old= 0;//曲率改变前
	int ac_now= 0; //曲率改变后
	int i=0;

	ac_old = acData;		   

	ac_section = (int)(ac_old / ac_base);
	ac_now = 0;
	for (i = 0; i<ac_section; i++)//整数区间
		{
			ac_now += ac_w[i];
		}
	if (ac_old - ac_base * ac_section>0)//整数区间以外
			ac_now+= ROUND(1.0*ac_w[ac_section] * (ac_old % ac_base) / ac_base);
	ac_now=ac_now > 100 ? 100 : ac_now;
	ac_final=ac_now;

    ac_final =(int)(0.4*ac_final+ 0.2*ac_old1+0.2*ac_old2+0.1*ac_old3+0.1*ac_old4);
    ac_old1=ac_final; 
	ac_old2=ac_old1;
	ac_old3=ac_old2;
	ac_old4=ac_old3;

	
}

 /*******************************************************************************************/
/*************************************刹车部分总函数*************************************/
/*******************************************************************************************/
 void brDeal(){
 	int br_temp_ad[2]={0,0};
	ADC1_vStartSeq0ReqChNum(0,0,0,0);
   	while(!(ADC1_RCR0 & 0x1000));	       	//AI1，5V对应0x03FF。制动采集            			 
    br_temp_ad[0]=((ADC1_RESR0>>2)&0x0300)>>8;		//high 2bit
	br_temp_ad[1]=((ADC1_RESR0>>2)&0x00ff);	   		//low  8bit
	delay(500);	
	br_ad = br_temp_ad[0] * 256 + br_temp_ad[1];
	br_ad1=br_ad;
	if (br_ad < br_ad_min)	 
		br_ad = br_ad_min;			          				
	if (br_ad > br_ad_max)	 				 
		br_ad = br_ad_max;	
	brAdFinal = (int)(100* (1.0*(br_ad-br_ad_min) / (br_ad_max - br_ad_min)));	  
 }


void delay(int ms)
{	 int i=0,j=0;
	for(j=ms;j>0;j--)
		for(i=100;i>0;i--)
		{}
}