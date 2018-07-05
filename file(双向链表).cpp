/***************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: ���.cpp
Author:�ƺ�ӿ   Version :1.01   Date:2018.06.24
Description: 
Version: 1.01��
Function List: 
1.main����������Ҫ�Ǹ����û���ָ����ø������ܺ�����
2.read()������Ҫ�Ƕ�ȡְ���������ݡ�
3.write()������Ҫ�Ǳ���ְ���������ݡ�
4.void fin()������Ҫ�ǲ�ѯְ���������ݡ�
5.list()������Ҫ�����ְ���������ݡ�
6.modify()������Ҫ���޸�ְ�����ʡ�
7.del()������Ҫ��ɾ��ְ���������ݡ�
8.add()������Ҫ�����ְ���������ݡ�
9.grsds()������Ҫ�Ǽ����������˰��
10.menu_select()������Ҫ������ɹ��û����յĲ˵�,�����û������ֵ������main�����С�
11.createlist()������Ҫ����Ϊ�Ӻ�������˫������
12.add_money()������������Ӧ�����ʡ�     
13.add_money() �˺�����������Ӧ�����ʡ�
History: 
<author> <time> <version > <desc>
David 96/10/12 1.0 build this moudle
***************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
#define M 100
int n=0;																							 //����һ��ȫ�ֱ���
typedef struct people  
{  
	char id[10];//����
    char name[10];//����  
    float money1;//��λ����  
	float money2;//н������
	float money3;//ְ�����
	float money4;//��Ч����
	float money;//Ӧ������
	float tax;//��������˰
	float wages;//ʵ������
	struct people *prior;
	struct people *next;
}ZGGZ;//�������ݽṹ��

/***************************************************************************
Function:menu_select()           
Description:����ɹ��û����յĲ˵�,�����û������ֵ������main������
Calls:  ����                  
Called By:main()������                  
Table Accessed: ����  
Table Updated: ����                    
Input: ����             
Output: ����           
Return:����         
Others:����         
***************************************************************************/
int menu_select()																					//����ѡ��ģ��
{  
    char c;  
    do  
    {  
        system("cls");  
	  printf("\n                            ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n\n");
	  printf("       ��ѡ��1��7����\n");
	  printf("        =========================================================================================================\n");
	  printf("       |                                                                                                         |\n");
	  printf("       |                                     1.��ѯְ�����ʼ�¼                                                  |\n");
	  printf("       |                                     2.�޸�ְ�����ʼ�¼                                                  |\n");
	  printf("       |                                     3.���ְ�����ʼ�¼                                                  |\n");
	  printf("       |                                     4.ɾ��ְ�����ʼ�¼                                                  |\n");
	  printf("       |                                     5.���ְ����¼                                                      |\n"); 
	  printf("       |                                     6.�������ݵ��ļ�                                                    |\n");
	  printf("       |                                     7.�˳�ϵͳ                                                          |\n");
	  printf("       |                                                                                                         |\n");
	  printf("        =========================================================================================================\n\n"); 
	  printf("       ���ѡ���ǣ�");
        c=getche();   
    }while(c<'1'||c>'7');//��������Ƿ���Ϲ淶
	printf("\n\n");
	system("pause"); 
    return(c-'0');  
}  

/********************************************
Function: createlist()
Description: ��Ϊ�Ӻ�������˫������
Calls By: main()
Table Accessed: ����       
Table Updated: ����    
Input: ������Ϊ�βΣ���ַ��Ϊʵ��
Other: ��ַΪ����ֵ
Return:����         
Others:���� 
*********************************************/
ZGGZ *createlist(ZGGZ t[])       //������n��Ԫ�ص�˫������ 
{
    ZGGZ *head, *p, *q;
    head = (ZGGZ *)malloc(sizeof(ZGGZ));//Ϊͷ��ָ������ڴ�ռ�
	head->prior = head;
    head->next = head;
    p = head;
    for(int i=0;i<n;i++)//����n��˫������Ԫ��
    {
        q = (ZGGZ *)malloc(sizeof(ZGGZ));
		strcpy(q->id ,t[i].id);//�������е����ݷ��䵽˫��������������
		strcpy(q->name,t[i].name);
		q->money1=t[i].money1;
		q->money2=t[i].money2;
		q->money3=t[i].money3;
		q->money4=t[i].money4;
		q->money=t[i].money;
		q->tax=t[i].tax;
		q->wages=t[i].wages;
        p->next = q;           //p���½ڵ�ָ��q
		head->prior = q;       //head��ǰ�ڵ�ָ��q
		q->prior = p;          //q��ǰ�ڵ�ָ��p
        q->next = head;        //q���½ڵ�ָ��head
        p = q;                 //q��ֵ��p
    }
    return head;
}

/***************************************************************************
Function:read����            
Description:������ȡ�ļ���gx.dat���е����ݣ����浽�ṹ��zggz��           
Calls:  ����                  
Called By:main()������                  
Table Accessed: �ļ���gx.dat��          
Table Updated: ����                    
Input: ����             
Output: ����           
Return:����         
Others:����         
***************************************************************************/
int read(ZGGZ t[])																					//�ļ���ȡģ��
{
	   int i;
       FILE *fp;//�����ļ�ָ��
       if ((fp = fopen("gx.dat", "rb")) == NULL)
       {
		   printf("���ļ�������,�����½���");
           fopen("gx.dat", "wb+");
		   printf("�����ɹ����뼰ʱ��������");
		   getchar();
			return 0;
       }
	   fscanf(fp,"%d",&n);
	   for(i=0;i<n;i++)
		   fscanf(fp,"%10s%10s%f%f%f%f%f%f%f",t[i].id,t[i].name,&t[i].money1,&t[i].money2,&t[i].money3,&t[i].money4,&t[i].money,&t[i].tax,&t[i].wages);
       fclose(fp);
       return 0;
}

/***************************************************************************
Function:find����           
Description:������������ͨ�����Ż������ֲ�ѯ��Ӧ�˵Ĺ������ݡ�               
Calls: ����               
Called By:main()������                  
Table Accessed: �ṹ��zggz��         
Table Updated: ����                    
Input:����               
Output:����            
Return:����          
Others:����         
***************************************************************************/
int find(ZGGZ *p)																					 //���ʲ�ѯģ��  
{  
	int j;  
    char m,flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t**********************************��ѯ��ʽ********************************\n");  
		printf("\n\t\t����ѡ��(1-3):\n");  
        printf("\t\t��------------------------------------------------------------------------��\n");  
        printf("\t\t��                                 1.���ҹ���                             ��\n");  
        printf("\t\t��                                 2.��������                             ��\n");  
        printf("\t\t��                                 3.����                                 ��\n");    
        printf("\t\t��------------------------------------------------------------------------��\n");  
        printf("\n\t\t��ѡ���ѯ��ʽ:");  
        m=getche();					//ѡ���ѯ��ʽ  
	
		do										//��������Ƿ���Ϲ淶  
			{  
				j=0;  
				if(m!='1'&&m!='2'&&m!='3')  
				{     
					j=1;  
					printf("\n\t\t������Ĳ�ѯ��ʽ������,����������:");  
					m=getche();		//�����Ϲ淶������ѡ���ѯ��ʽ  
				}  
			}while(j); 

		if(m=='1')								//���Ų�ѯ
			{
				int flag=0;						//���Ա����û�д���
				char gonghao[10];
				printf("\n");
				printf("\n\t\t������Ҫ��ѯԱ���ı�ţ�");
				scanf("%s",gonghao);
				people *q=p;
				for (q=q->next; q!=p; q=q->next)
				{
					if (strcmp(q->id,gonghao)==0)
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					printf("\n\t\t����:%s\n",q->name);  
					printf("\t\t��λ����:%.2f\n",q->money1);  
					printf("\t\tн������:%.2f\n",q->money2);  
					printf("\t\tְ�����:%.2f\n",q->money3);  
					printf("\t\t��Ч����:%.2f\n",q->money4);  
					printf("\t\tӦ������:%.2f\n",q->money);
					printf("\t\t��������˰:%.2f\n",q->tax);  
					printf("\t\tʵ������:%.2f\n",q->wages);  
				}
				else
				{
					printf("û���ҵ��ñ�ŵ�Ա����\n");
				}
				printf("\n");
				system("pause");
			}

		if(m=='2')								//������ѯ
		{
			int flag=0;							//���Ա����û�д���
			char nm[10];
			printf("\n");
			printf("������Ҫ��ѯԱ����������");
			scanf("%s",nm);
			people *q=p;
			for (q=q->next; q!=p; q=q->next)
			{
				if (strcmp(q->name,nm)==0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{

							printf("\n\t\t����:%s\n",q->id);  
							printf("\t\t��λ����:%.2f\n",q->money1);  
							printf("\t\tн������:%.2f\n",q->money2);  
							printf("\t\tְ�����:%.2f\n",q->money3);  
							printf("\t\t��Ч����:%.2f\n",q->money4);  
							printf("\t\tӦ������:%.2f\n",q->money);
							printf("\t\t��������˰:%.2f\n",q->tax);  
							printf("\t\tʵ������:%.2f\n",q->wages);  

			}
			else
			{
				printf("û���ҵ���������Ա����\n");
			}
			printf("\n");
			system("pause");
		}

		if(m=='3')							    	//����
		{
			return 0;
		}

		printf("\t\t�Ƿ������ѯ?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

/***************************************************************************
Function:add_money()           
Description:�˺�����������Ӧ�����ʡ�                
Calls:               
Called By:add������modify������                
Table Accessed: �ṹ��zggz��         
Table Updated: ����                   
Input:����Ĳ���a�Ǵ���ڼ���Ա����              
Output: ����            
Return: ���ؼ���õĸ�������˰��        
Others: ����    
***************************************************************************/
void add_money(ZGGZ *p)									//�Լ�ģ�� ����Ӧ������       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
		q->money=q->money1+q->money2+q->money3+q->money4;
}

/***************************************************************************
Function:grsds()           
Description:�˺������������������˰��                
Calls:               
Called By:add������modify������                
Table Accessed: �ṹ��zggz��         
Table Updated: ����                   
Input:����Ĳ���a�Ǵ���ڼ���Ա����              
Output: ����            
Return: ���ؼ���õĸ�������˰��        
Others: ����    
***************************************************************************/
void grsds(ZGGZ *p)										//�Լ�ģ�� �����������˰       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
	{
		if(q->money<500)																									//����С��500ʱ��������˰																											
			q->tax=q->money*0.05;
		else if(q->money<2000)																							//���ʴ���500С��2000ʱ��������˰
			q->tax=(q->money-500)*0.1+500*0.05;	
		else if(q->money<5000)																							//���ʴ���2000С��5000ʱ��������˰
			q->tax=(q->money-2000)*0.15+1500*0.1+500*0.05;														     			
		else if(q->money<20000)																							//���ʴ���5000С��20000ʱ��������˰
			q->tax=(q->money-5000)*0.2+3000*0.15+1500*0.1+500*0.05;														    
		else if(q->money<40000)																							//���ʴ���20000С��40000ʱ��������˰
			q->tax=(q->money-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if(q->money<60000)																							//���ʴ���40000С��60000ʱ��������˰
			q->tax=(q->money-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     		
		else if(q->money<80000)																							//���ʴ���60000С��80000ʱ��������˰
			q->tax=(q->money-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		     				
		else if(q->money<100000)																							//���ʴ���80000С��100000ʱ��������˰
			q->tax=(q->money-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else																												//���ʴ���100000ʱ��������˰
			q->tax=(q->money-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}

/***************************************************************************
Function:add_wages()           
Description:�˺�����������ʵ�����ʡ�                
Calls:               
Called By:add������modify������                
Table Accessed: �ṹ��zggz��         
Table Updated: ����                   
Input:����Ĳ���a�Ǵ���ڼ���Ա����              
Output: ����            
Return: ���ؼ���õĸ�������˰��        
Others: ����    
***************************************************************************/
void add_wages(ZGGZ *p)																									//�Լ�ģ�� ����ʵ������	       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
		q->wages=q->money-q->tax;
}

/***************************************************************************
Function:list����           
Description:�˺�������������й��ʳ�Ա������           
Calls:����                   
Called By:main()������                  
Table Accessed: �ṹ��zggz��          
Table Updated: ����                    
Input: ����              
Output: ����           
Return: ����       
Others: ����       
***************************************************************************/
void list(ZGGZ *head)																											//���ģ��
{
	people *p;																										
	p = head;
	p = p->next;
	system("cls");
	printf("\n\t\t**********************************���ģ��********************************\n");  
	while(p!=head)					
	{
		printf("\n");
		printf("����:%s  %s\n",p->id,p->name);  
		printf("��λ����:%.2f\tн������:%.2f\tְ�����:%.2f\t��Ч����:%.2f\n",p->money1,p->money2,p->money3,p->money4);  
		printf("Ӧ������:%.2f\t��������˰:%.2f\tʵ������:%.2f",p->money,p->tax,p->wages);
		printf("\n");
		p=p->next;		 
	}
	printf("\n����������������,�����Զ��������˵�\n\n");
}

/***************************************************************************
Function:modify����          
Description:�˺��������޸�ְ���������ݣ�ͨ���ж��������߹�����ɸѡ��ָ�������ݡ�            
Calls��grsds����������                 
Called By:main()������                  
Table Accessed: �ṹ��zggz��          
Table Updated: ����                   
Input: ����             
Output: ����          
Return: ����      
Others: ����      
***************************************************************************/
int modify(ZGGZ *p)                                                                                                        //�޸�ģ��
{
	int flag=0;						//���Ա����û�д���
	char gonghao[10];
	printf("\n");
	printf("������Ҫ�޸�����Ա���ı�ţ�");
	scanf("%s",gonghao);
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
	{
		if (strcmp(q->id,gonghao)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{	
		printf("ԭʼ�������£�");
		printf("����:%s  %s\n",q->id,q->name);  
		printf("��λ����:%.2f\tн������:%.2f\tְ�����:%.2f\t��Ч����:%.2f\n",q->money1,q->money2,q->money3,q->money4);  
		printf("Ӧ������:%.2f\t��������˰:%.2f\tʵ������:%.2f\n",q->money,q->tax,q->wages);
		printf("�������޸ĺ������:\n");
		float a[4];															//������ʱ�����鴢���û����������
		printf("\t\t��λ����:");
		scanf("%f",&a[0]);  
		printf("\t\tн������:"); 
		scanf("%f",&a[1]);
		printf("\t\tְ�����:");  
		scanf("%f",&a[2]);
		printf("\t\t��Ч����:");  
		scanf("%f",&a[3]);														//����ʱ�����е��˸�ֵ��ȥ
		q->money1=a[0];
		q->money2=a[1];
		q->money3=a[2];
		q->money4=a[3];
		add_money(p);
		grsds(p);
		add_wages(p);
		printf("�޸ĺ���������£�");
		printf("����:%s  %s\n",q->id,q->name);  
		printf("��λ����:%.2f\tн������:%.2f\tְ�����:%.2f\t��Ч����:%.2f\n",q->money1,q->money2,q->money3,q->money4);  
		printf("Ӧ������:%.2f\t��������˰:%.2f\tʵ������:%.2f",q->money,q->tax,q->wages);
	}
	else
	{
		printf("û���ҵ��ñ�ŵ�Ա����\n");
	}
	printf("\n");
	system("pause");
	printf("\t\t�Ƿ�����޸�?(Y/N)");  
	scanf("\t\t%c",&flag);  
	return 0;  
}
/***************************************************************************
Function:write����           
Description:�������ṹ���е����ݱ������ļ���gx.dat���С�                
Calls:  ����                   
Called By:main()������                 
Table Accessed: �ļ���gx.dat��       
Table Updated: ����                 
Input:����               
Output:����            
Return:����        
Others:����         
***************************************************************************/
int write(ZGGZ *p)																											//����ģ��
{
    FILE *fp;//�����ļ�ָ��
    if ((fp = fopen("gx.dat", "w")) == NULL)
    {
        printf("���ݱ���ʧ�ܣ������ļ��Ƿ���ڻ��𻵺�����!");
		return 0;
    }
	fscanf(fp,"%d",&n);
	people *q=p;
	fprintf(fp,"%d",n);
	for(q=q->next; q!=p; q=q->next)
	{
		fprintf(fp,"%10s%10s %f %f %f %f %f %f %f\n",q->id,q->name,q->money1,q->money2,q->money3,q->money4,q->money,q->tax,q->wages);  
	}
    fclose(fp);
	printf("\n���ݱ���ɹ�\n\n");  
    return 0;
}

/***************************************************************************
Function:add����          
Description:�˺�����������ְ��������Ϣ��              
Calls:����                   
Called By:main()������                   
Table Accessed: �ṹ��zggz��          
Table Updated: ����                     
Input: ����            
Output: ����           
Return: ����       
Others: ����     
***************************************************************************/
int add(ZGGZ *head)																			//	���ģ��
{		
	n++;
	system("cls");
	printf("\n\t\t**********************************�������********************************\n");  
	people *p=head,*t=head,*q,a;
    p=p->next;
	if(n == 100)
	{
		printf("���������������Զ��������˵�");
		return 0;
	}
	else
	{
		printf("����¼���û���Ϣ:\n");//ͨ�����Ż��������в���
		printf("���ţ�");
		scanf("%s", &a.id);//����
		while(p!=head)//�жϹ�����ͬ�Ĳ������
		{ 
			if(strcmp(p->id,a.id)==0)
			{
				printf("�����Ѵ��ڣ���������������\n");
				return 0;
			}
			else
			{
				p=p->next;
			}
		}
	printf("������");
	scanf("%s",&a.name);//����
	printf("��λ���ʣ�");
	scanf("%f",&a.money1);//��λ����
	printf("н�����ʣ�");
	scanf("%f",&a.money2);//н������
	printf("ְ�������");
	scanf("%f",&a.money3);//ְ�����
	printf("��Ч���ʣ�");
	scanf("%f",&a.money4);//��Ч����
	q = (people *)malloc(sizeof(people));
	strcpy(q->id ,a.id);//�������е����ݷ��䵽˫��������������
	strcpy(q->name,a.name);
	q->money1=a.money1;
	q->money2=a.money2;
	q->money3=a.money3;
	q->money4=a.money4;

	p->prior->next= q;           
	head->prior = q;       //head��ǰ�ڵ�ָ��q
	q->prior = p->prior;          //q��ǰ�ڵ�ָ��p
	q->next = head;        //q���½ڵ�ָ��head 

	add_money(head);
	grsds(head);
	add_wages(head);
	printf("����ְ����ϢΪ��\n");
	printf("���ţ�%s\t������%s\t��λ���ʣ�%.2f\n",q->id,q->name,q->money1);
	printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->money2,q->money3,q->money4);
	printf("н�����ʣ�%.2f\tְ�������%.2f\t��Ч���ʣ�%.2f\n",q->money,q->tax,q->wages);
	printf("������,�����Զ��������˵�\n");
	}
	return 0;
}

/***************************************************************************
Function:del����            
Description:�˺�������ɾ����ѡ�����ݡ�               
Calls:����             
Called By:main()������                   
Table Accessed: �ṹ��zggz��        
Table Updated: ����                     
Input: ����             
Output: ����           
Return: ����      
Others: ����      
***************************************************************************/
int del(ZGGZ *head)						//ɾ��ģ��
{
	int m=0;						//ɾ����־��
	int j;
	char flag;
	char gonghao[10];
	while(flag!='n'&&flag!='N')
	{
		system("cls"); 
		people *p = head, *q;
		p = p->next;
		printf("\n\t\t**********************************����ɾ��********************************\n");  
		printf("\n");
		printf("������Ҫɾ��Ա���Ĺ��ţ�");
		scanf("%s",gonghao);
		for (; p!=head;  p=p->next)
		{
			if (strcmp(p->id,gonghao)==0)
			{
				m = 1;
				break;
			}
		}
		if (m)
		{
			printf("\n�Ѳ�ѯ����λΪ%s��ְ��������������%s\n",p->id,p->name);
			printf("�Ƿ�ȷ��ɾ����Ա����Ϣ?(Y/N)");  
			scanf("\t\t%c",&flag);
			do																													//��������Ƿ���Ϲ淶  
			{  
				j=0;  
				if(flag!='Y' && flag!='y' && flag!='N' && flag!='n')  
				{     
					j=1;  
					printf("�����루Y/N��\n");  
					scanf("\t\t%c",&flag);																							//�����Ϲ淶������ѡ�������ʽ  
				}  
			}while(j); 
		}
		else
		{
			printf("û���ҵ��ù��ŵ�Ա����\n");
		}
		if(flag=='y' || flag=='Y')											//ȷ��ɾ��
		{
			n--;
			q = p->next;
            (p->prior)->next = p->next;
            (p->next)->prior = p->prior;
            free(p);
            p = q;
            n=n-1;
			add_money(head);
			grsds(head);
			add_wages(head);
			printf("\nɾ���ɹ�\n");
		}
		flag='y';
		printf("�Ƿ����ɾ������?(Y/N)\n");
		scanf("\t\t%c",&flag);
	}
	printf("�����������˵�");
	return 0;
}

/***************************************************************************
Function:main����           
Description:������������ʵ�ָ��ֲ��������ø����������в�����               
Calls:add(),del(),fin(),fin(),list(),modify(),read(),write(),add_money(),add_wages()            
Called By:�ޡ�                 
Table Accessed: �ṹ��zggz��         
Table Updated: ����                    
Input: ����              
Output: ����          
Return: ����        
Others: ����      
***************************************************************************/
int main()
{
	
	ZGGZ adr[M];
	read(adr);
	people *head;
	head=createlist(adr);
	add_money(head);
	grsds(head);
	add_wages(head);
	for(;;)  
    {  
        switch(menu_select())  
        {  
        case 1:  
            find(head);  
            system("pause");  
            break;  
        case 2:   
            modify(head);  
            system("pause");  
            break;  
        case 3:   
            add(head);  
            system("pause");  
            break;  
        case 4:   
            del(head);  
            system("pause");  
            break;  
        case 5:  
            list(head);  
            system("pause");  
            break;  
        case 6:   
            write(head);  
            system("pause");  
            break;  

        case 7:      
            printf("\n\t\tллʹ�ã��ټ�!\n");  //��������      
            printf("\n\t\t");      
            system("pause");      
            exit(0);      
        }  
    }  

	return 0;
}