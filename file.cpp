#include<iostream>
#include<stdlib.h>
#include<stdio.h>
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
}ZGGZ;//�������ݽṹ��


int menu_select()																					//����ѡ��ģ��
{  
    char c;  
    do  
    {  
        system("cls");  
        printf("\n\t\t**********���ʹ���ϵͳ**********\n");  
        printf("\t\t��------------------------------��\n");  
        printf("\t\t��        1.��ѯְ������        ��\n");  
        printf("\t\t��        2.�޸�ְ������        ��\n");  
        printf("\t\t��        3.���ְ������        ��\n");  
        printf("\t\t��        4.ɾ��ְ������        ��\n");  
        printf("\t\t��        5.���ְ������        ��\n");  
        printf("\t\t��        6.����ְ������        ��\n");  
        printf("\t\t��        7.�˳�                ��\n");  
        printf("\t\t��------------------------------��\n");  
        printf("\t\t����ѡ��(1-7):");      
        c=getchar();   
    }while(c<'1'||c>'7');//��������Ƿ���Ϲ淶  
    return(c-'0');  
}  

int read(ZGGZ t[])																					//�ļ���ȡģ��
{
	   int i;
       FILE *fp;//�����ļ�ָ��
       if ((fp = fopen("gz.dat", "rb")) == NULL)
       {
              printf("���������ļ���ʧ�ܣ������ļ��Ƿ���ڻ��𻵺�����!");
              return 0;
       }
	   fscanf(fp,"%d",&n);
	   for(i=0;i<n;i++)
		   fscanf(fp,"%10s%10s%f%f%f%f%f%f%f",t[i].id,t[i].name,&t[i].money1,&t[i].money2,&t[i].money3,&t[i].money4,&t[i].money,&t[i].tax,&t[i].wages);
       fclose(fp);
       return 0;
}

int find(ZGGZ S[])																					 //���ʲ�ѯģ��  
{  
	int m,j;  
    char flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t***********��ѯ��ʽ************\n");  
        printf("\t\t��------------------------------��\n");  
        printf("\t\t��          1.���ҹ���          ��\n");  
        printf("\t\t��          2.��������          ��\n");  
        printf("\t\t��          3.����              ��\n");    
        printf("\t\t��------------------------------��\n");  
        printf("\n\t\t��ѡ���ѯ��ʽ:");  
        scanf("\t\t%d",&m);					//ѡ���ѯ��ʽ  
	
		do										//��������Ƿ���Ϲ淶  
			{  
				j=0;  
				if(m!=1&&m!=2&&m!=3)  
				{     
					j=1;  
					printf("\t\t������Ĳ�ѯ��ʽ������,����������:");  
					scanf("\t\t%d",&m);			//�����Ϲ淶������ѡ���ѯ��ʽ  
				}  
			}while(j); 

		if(m==1)								//���Ų�ѯ
			{
				int i;							//���ڲ�ѯԱ�����
				int flag=0;						//���Ա����û�д���
				char gonghao[10];
				printf("\n");
				printf("������Ҫ��ѯԱ���ı�ţ�");
				scanf("%s",gonghao);
				for (i = 0; i < n; i++)
				{
					if (strcmp(S[i].id,gonghao)==0)
					{
						flag = 1;
						break;
					}
				}
				if (flag)
				{
					printf("\t\t����:%s\n",S[i].name);  
					printf("\t\t��λ����:%f\n",S[i].money1);  
					printf("\t\tн������:%f\n",S[i].money2);  
					printf("\t\tְ�����:%f\n",S[i].money3);  
					printf("\t\t��Ч����:%f\n",S[i].money4);  
					printf("\t\tӦ������:%f\n",S[i].money);
					printf("\t\t��������˰:%f\n",S[i].tax);  
					printf("\t\tʵ������:%f\n",S[i].wages);  
				}
				else
				{
					printf("û���ҵ��ñ�ŵ�Ա����\n");
				}
				printf("\n");
				system("pause");
			}

		if(m==2)								//������ѯ
		{
			int i;								//���ڲ�ѯԱ�����
			int flag=0;							//���Ա����û�д���
			char nm[10];
			printf("\n");
			printf("������Ҫ��ѯԱ����������");
			scanf("%s",nm);
			for (i = 0; i < n; i++)
			{
				if (strcmp(S[i].name,nm)==0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
			{
				printf("\t\t����:%s\n",S[i].id);  
				printf("\t\t��λ����:%f\n",S[i].money1);  
				printf("\t\tн������:%f\n",S[i].money2);  
				printf("\t\tְ�����:%f\n",S[i].money3);  
				printf("\t\t��Ч����:%f\n",S[i].money4);  
				printf("\t\tӦ������:%f\n",S[i].money);
				printf("\t\t��������˰:%f\n",S[i].tax);  
				printf("\t\tʵ������:%f\n",S[i].wages);  
			}
			else
			{
				printf("û���ҵ���������Ա����\n");
			}
			printf("\n");
			system("pause");
		}

		if(m==3)							    	//����
		{
			return 0;
		}

		printf("\t\t�Ƿ������ѯ?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

void add_money(ZGGZ S[])									//�Լ�ģ�� ����Ӧ������       
{
	for(int i=0;i<n;i++)
		S[i].money=S[i].money1+S[i].money2+S[i].money3+S[i].money4;
}

void grsds(ZGGZ S[])										//�Լ�ģ�� �����������˰       
{
	for(int i=0;i<n;i++)
	{
		if(S[i].money<500)																									//����С��500ʱ��������˰																											
			S[i].tax=S[i].money*0.05;
		else if(S[i].money<2000)																							//���ʴ���500С��2000ʱ��������˰
			S[i].tax=(S[i].money-500)*0.1+500*0.05;	
		else if(S[i].money<5000)																							//���ʴ���2000С��5000ʱ��������˰
			S[i].tax=(S[i].money-2000)*0.15+1500*0.1+500*0.05;														     			
		else if(S[i].money<20000)																							//���ʴ���5000С��20000ʱ��������˰
			S[i].tax=(S[i].money-5000)*0.2+3000*0.15+1500*0.1+500*0.05;														    
		else if(S[i].money<40000)																							//���ʴ���20000С��40000ʱ��������˰
			S[i].tax=(S[i].money-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if(S[i].money<60000)																							//���ʴ���40000С��60000ʱ��������˰
			S[i].tax=(S[i].money-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     		
		else if(S[i].money<80000)																							//���ʴ���60000С��80000ʱ��������˰
			S[i].tax=(S[i].money-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		     				
		else if(S[i].money<100000)																							//���ʴ���80000С��100000ʱ��������˰
			S[i].tax=(S[i].money-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else																												//���ʴ���100000ʱ��������˰
			S[i].tax=(S[i].money-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}

void add_wages(ZGGZ S[])																									//�Լ�ģ�� ����ʵ������	       
{
	for(int i=0;i<n;i++)
		S[i].wages=S[i].money-S[i].tax;
}

int list(ZGGZ S[])																											//���ģ��
{
	
	int i=0;																												//��ǰ�����λ��
	char flag='y';																											//�ж��Ƿ�������
	int m,j;																												//ѡ�������ʽ
	int k=10;																												//��������������,Ĭ��Ϊ10

		system("cls");
		printf("\n\t\t***********�����ʽ************\n");  
		printf("\t\t��------------------------------��\n");  
		printf("\t\t��          1.���������        ��\n");  
		printf("\t\t��          2.ȫ�����          ��\n");  
		printf("\t\t��          3.����              ��\n");    
		printf("\t\t��------------------------------��\n");  
		printf("\n\t\t��ѡ���ѯ��ʽ:");  
		scanf("\t\t%d",&m);																									//ѡ�������ʽ  
		do																													//��������Ƿ���Ϲ淶  
		{  
			j=0;  
			if(m!=1&&m!=2&&m!=3)  
			{     
				j=1;  
				printf("\t\t������������ʽ������,����������:");  
				scanf("\t\t%d",&m);																							//�����Ϲ淶������ѡ�������ʽ  
			}  
		}while(j); 

	if(m==1)																												//���������
	{
		printf("\n");
		printf("�����뵥������������(Ĭ��Ϊ10):");
		scanf("%d",&k);
		printf("\n����������:");
		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("����:%s  %s\n",S[i].id,S[i].name);  
			printf("��λ����:%f\tн������:%f\tְ�����:%f\t��Ч����:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
			printf("Ӧ������:%f\t��������˰:%f\tʵ������:%f",S[i].money,S[i].tax,S[i].wages);
			printf("\n");
			i++;		 
			if(i%k==0)
			{	
				printf("\n");
				printf("\t\t�Ƿ�������?(Y/N)");  
				scanf("\t\t%c",&flag); 
			}
		}
		printf("\n����������ȫ��������,�����Զ��������˵�\n\n");
	}
	
	if(m==2)																												//ȫ�����
	{

		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("����:%s  %s\n",S[i].id,S[i].name);  
			printf("��λ����:%f\tн������:%f\tְ�����:%f\t��Ч����:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
			printf("Ӧ������:%f\t��������˰:%f\tʵ������:%f",S[i].money,S[i].tax,S[i].wages);
			printf("\n");
			i++;		 
		}
		printf("\n����������ȫ��������,�����Զ��������˵�\n\n");
	}
	
	if(m==3)																												//����
		{
			return 0;
		}
	return 0;
}

int main()
{
	
	ZGGZ adr[M];
	read(adr);
	add_money(adr);
	grsds(adr);
	add_wages(adr);
	for(;;)  
    {  
        switch(menu_select())  
        {  
        case 1:  
            printf("\n\t\t��ѯְ����������\n");  
            find(adr);  
            system("pause");  
            break;  
        case 2:  
            printf("\n\t\t������δ���ƣ��뾡���ڴ�\n");   
//            modify();  
            system("pause");  
            break;  
        case 3:  
            printf("\n\t\t������δ���ƣ��뾡���ڴ�\n");  
//            add()  
            system("pause");  
            break;  
        case 4:  
            printf("\n\t\t������δ���ƣ��뾡���ڴ�\n");  
//            del();  
            system("pause");  
            break;  
        case 5:  
            list(adr);  
            system("pause");  
            break;  
        case 6:  
            printf("\n\t\t������δ���ƣ��뾡���ڴ�\n");  
//            write();  
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