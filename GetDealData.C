#include "MAIN.H"
#include "math.h"
/*************************************ȫ�ֱ�������************************************/

/*************************************���ű�������************************************/
int ac_ad_max[2] = { 145, 142 },ac_ad_min[2] = { 35, 25 };//��ֵ   [0]Ϊ����1��[1]Ϊ����2  23, 35
int ac_w[10] =  { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };	//����1��Ȩ  
int ac_ad[2]={0,0};//��·���ŵ�ADֵ
int ac_normolize[2] = {0};//�������ݹ�һ��ֵ
unsigned int ac_data=0;//���������Ϻ�����
int ac_final=0;//�������ߵ�����
ubyte acRealiableFlag=0,acUnRealiableCout=0; //�������ݿɿ���־

/*************************************ɲ����������************************************/

int br_ad=0,br_ad1=0,br_ad_max=540,br_ad_min=50,brAdFinal=0;  //  br_ad_min=	33


  //ɲ����ADֵ	 ���ֵ   ��Сֵ     ����ֵ
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
	while(!(ADC1_RCR2 & 0x1000));			//AI2��5V��Ӧ0x03FF��������ɼ�		 
	ac_temp_ad[0]=((ADC1_RESR2>>2)&0x0300)>>8;	    //high 2bit
	ac_temp_ad[1]=((ADC1_RESR2>>2)&0x00ff);        	//low  8bit
	ac_ad[0] = ac_temp_ad[0] * 256 + ac_temp_ad[1];
	delay(500);	

	ADC1_vStartSeq0ReqChNum(0,0,0,4);
	while(!(ADC1_RCR4 & 0x1000));          	//AI3��5V��Ӧ0x03FF��
	ac_temp_ad[2]=((ADC1_RESR4>>2)&0x0300)>>8;		//high 2bit	  
	ac_temp_ad[3]=((ADC1_RESR4>>2)&0x00ff);			//low  8bit
	ac_ad[1]=ac_temp_ad[2]*256+ac_temp_ad[3];
	delay(500);

	
	//�������ݹ�һ������ 0~100

	for (i = 0; i < 2; i++)
	{
		ac_ad[i]=ac_ad[i]>ac_ad_max[i] ? ac_ad_max[i] : ac_ad[i];//ʵ�������޷�
		ac_ad[i] = ac_ad[i]<ac_ad_min[i] ? ac_ad_min[i] : ac_ad[i];
		ac_normolize[i] =(int)(100* (1.0*(ac_ad[i]-ac_ad_min[i]) / (ac_ad_max[i] - ac_ad_min[i])));
	}

	//������������
	 ac_data= (ac_normolize[0]+ac_normolize[1])/2;
	 //�ж���·���������Ƿ�ɿ�
	 if(ac_normolize[0]-ac_normolize[1]>10||ac_normolize[1]-ac_normolize[0]>10){
	 	acUnRealiableCout++;
		if(acUnRealiableCout>20){//���ɿ�����100ms�����г�����
			acRealiableFlag=0; 
			acUnRealiableCout=0;
		}
	}
	 else 	acRealiableFlag=1;

 }
//void get_MostValue() //��ȡɲ����������ֵ
//{
//	int i=0;
//	for (i = 0; i < 2; i++)
//	{
//		ac_br_max[i] = AD[i]> ac_br_max[i] ? AD[i] : ac_br_max[i];
//		ac_br_min[i] = AD[i]< ac_br_min[i] ? AD[i] : ac_br_min[i];
//	}
//}


/*******************************************************************************************/
/*************************************�������ߵ���*************************************/
/*******************************************************************************************/
int ac_old1=0,ac_old2=0,ac_old3=0,ac_old4=0;
void DataDeal(int acData)//�������ߵ���
{
	int ac_base= 10;//��Ȩ��ֵ
	int ac_section = 0;//�����жϵ�ǰ���Ŵ����ĸ�����
	int	ac_old= 0;//���ʸı�ǰ
	int ac_now= 0; //���ʸı��
	int i=0;

	ac_old = acData;		   

	ac_section = (int)(ac_old / ac_base);
	ac_now = 0;
	for (i = 0; i<ac_section; i++)//��������
		{
			ac_now += ac_w[i];
		}
	if (ac_old - ac_base * ac_section>0)//������������
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
/*************************************ɲ�������ܺ���*************************************/
/*******************************************************************************************/
 void brDeal(){
 	int br_temp_ad[2]={0,0};
	ADC1_vStartSeq0ReqChNum(0,0,0,0);
   	while(!(ADC1_RCR0 & 0x1000));	       	//AI1��5V��Ӧ0x03FF���ƶ��ɼ�            			 
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