#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define M 100
int n=0;																							 //定义一个全局变量
typedef struct people  
{  
	char id[10];//工号
    char name[10];//姓名  
    float money1;//岗位工资  
	float money2;//薪级工资
	float money3;//职务津贴
	float money4;//绩效工资
	float money;//应发工资
	float tax;//个人所得税
	float wages;//实发工资
}ZGGZ;//工资数据结构体


int menu_select()																					//功能选择模块
{  
    char c;  
    do  
    {  
        system("cls");  
        printf("\n\t\t**********工资管理系统**********\n");  
        printf("\t\t┌------------------------------┐\n");  
        printf("\t\t│        1.查询职工工资        │\n");  
        printf("\t\t│        2.修改职工工资        │\n");  
        printf("\t\t│        3.添加职工工资        │\n");  
        printf("\t\t│        4.删除职工工资        │\n");  
        printf("\t\t│        5.浏览职工工资        │\n");  
        printf("\t\t│        6.保存职工工资        │\n");  
        printf("\t\t│        7.退出                │\n");  
        printf("\t\t└------------------------------┘\n");  
        printf("\t\t请您选择(1-7):");      
        c=getchar();   
    }while(c<'1'||c>'7');//检查输入是否符合规范  
    return(c-'0');  
}  

int read(ZGGZ t[])																					//文件读取模块
{
	   int i;
       FILE *fp;//定义文件指针
       if ((fp = fopen("gx.dat", "rb")) == NULL)
       {
              printf("工资数据文件打开失败，请检查文件是否存在或损坏后重试!");
              return 0;
       }
	   fscanf(fp,"%d",&n);
	   for(i=0;i<n;i++)
		   fscanf(fp,"%10s%10s%f%f%f%f%f%f%f",t[i].id,t[i].name,&t[i].money1,&t[i].money2,&t[i].money3,&t[i].money4,&t[i].money,&t[i].tax,&t[i].wages);
       fclose(fp);
       return 0;
}

int find(ZGGZ S[])																					 //工资查询模块  
{  
	int m,j;  
    char flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t***********查询方式************\n");  
        printf("\t\t┌------------------------------┐\n");  
        printf("\t\t│          1.查找工号          │\n");  
        printf("\t\t│          2.查找姓名          │\n");  
        printf("\t\t│          3.返回              │\n");    
        printf("\t\t└------------------------------┘\n");  
        printf("\n\t\t请选择查询方式:");  
        scanf("\t\t%d",&m);					//选择查询方式  
	
		do										//检查输入是否符合规范  
			{  
				j=0;  
				if(m!=1&&m!=2&&m!=3)  
				{     
					j=1;  
					printf("\t\t您输入的查询方式不存在,请重新输入:");  
					scanf("\t\t%d",&m);			//不符合规范则重新选择查询方式  
				}  
			}while(j); 

		if(m==1)								//工号查询
			{
				int i;							//现在查询员工序号
				int flag=0;						//标记员工有没有存在
				char gonghao[10];
				printf("\n");
				printf("请输入要查询员工的编号：");
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
					printf("\t\t姓名:%s\n",S[i].name);  
					printf("\t\t岗位工资:%f\n",S[i].money1);  
					printf("\t\t薪级工资:%f\n",S[i].money2);  
					printf("\t\t职务津贴:%f\n",S[i].money3);  
					printf("\t\t绩效工资:%f\n",S[i].money4);  
					printf("\t\t应发工资:%f\n",S[i].money);
					printf("\t\t个人所得税:%f\n",S[i].tax);  
					printf("\t\t实发工资:%f\n",S[i].wages);  
				}
				else
				{
					printf("没有找到该编号的员工！\n");
				}
				printf("\n");
				system("pause");
			}

		if(m==2)								//姓名查询
		{
			int i;								//现在查询员工序号
			int flag=0;							//标记员工有没有存在
			char nm[10];
			printf("\n");
			printf("请输入要查询员工的姓名：");
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
					for (i = 0; i < n; i++)			//防止出现重名状况
					{
						if (strcmp(S[i].name,nm)==0)
						{
							printf("\n\t\t工号:%s\n",S[i].id);  
							printf("\t\t岗位工资:%f\n",S[i].money1);  
							printf("\t\t薪级工资:%f\n",S[i].money2);  
							printf("\t\t职务津贴:%f\n",S[i].money3);  
							printf("\t\t绩效工资:%f\n",S[i].money4);  
							printf("\t\t应发工资:%f\n",S[i].money);
							printf("\t\t个人所得税:%f\n",S[i].tax);  
							printf("\t\t实发工资:%f\n",S[i].wages);  
						}
					}
				
			}
			else
			{
				printf("没有找到该姓名的员工！\n");
			}
			printf("\n");
			system("pause");
		}

		if(m==3)							    	//返回
		{
			return 0;
		}

		printf("\t\t是否继续查询?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

void add_money(ZGGZ S[])									//自检模块 计算应发工资       
{
	for(int i=0;i<n;i++)
		S[i].money=S[i].money1+S[i].money2+S[i].money3+S[i].money4;
}

void grsds(ZGGZ S[])										//自检模块 计算个人所得税       
{
	for(int i=0;i<n;i++)
	{
		if(S[i].money<500)																									//工资小于500时个人所得税																											
			S[i].tax=S[i].money*0.05;
		else if(S[i].money<2000)																							//工资大于500小于2000时个人所得税
			S[i].tax=(S[i].money-500)*0.1+500*0.05;	
		else if(S[i].money<5000)																							//工资大于2000小于5000时个人所得税
			S[i].tax=(S[i].money-2000)*0.15+1500*0.1+500*0.05;														     			
		else if(S[i].money<20000)																							//工资大于5000小于20000时个人所得税
			S[i].tax=(S[i].money-5000)*0.2+3000*0.15+1500*0.1+500*0.05;														    
		else if(S[i].money<40000)																							//工资大于20000小于40000时个人所得税
			S[i].tax=(S[i].money-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if(S[i].money<60000)																							//工资大于40000小于60000时个人所得税
			S[i].tax=(S[i].money-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     		
		else if(S[i].money<80000)																							//工资大于60000小于80000时个人所得税
			S[i].tax=(S[i].money-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		     				
		else if(S[i].money<100000)																							//工资大于80000小于100000时个人所得税
			S[i].tax=(S[i].money-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else																												//工资大于100000时个人所得税
			S[i].tax=(S[i].money-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}

void add_wages(ZGGZ S[])																									//自检模块 计算实发工资	       
{
	for(int i=0;i<n;i++)
		S[i].wages=S[i].money-S[i].tax;
}

int list(ZGGZ S[])																											//浏览模块
{
	
	int i=0;																												//当前浏览的位置
	char flag='y';																											//判断是否继续浏览
	int m,j;																												//选择浏览方式
	int k=10;																												//单次浏览最大数量,默认为10

		system("cls");
		printf("\n\t\t***********浏览方式************\n");  
		printf("\t\t┌------------------------------┐\n");  
		printf("\t\t│          1.分批次浏览        │\n");  
		printf("\t\t│          2.全部浏览          │\n");  
		printf("\t\t│          3.返回              │\n");    
		printf("\t\t└------------------------------┘\n");  
		printf("\n\t\t请选择查询方式:");  
		scanf("\t\t%d",&m);																									//选择浏览方式  
		do																													//检查输入是否符合规范  
		{  
			j=0;  
			if(m!=1&&m!=2&&m!=3)  
			{     
				j=1;  
				printf("\t\t您输入的浏览方式不存在,请重新输入:");  
				scanf("\t\t%d",&m);																							//不符合规范则重新选择浏览方式  
			}  
		}while(j); 

	if(m==1)																												//分批次浏览
	{
		printf("\n");
		printf("请输入单次浏览最大数量(默认为10):");
		scanf("%d",&k);
		printf("\n浏览结果如下:");
		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("工号:%s  %s\n",S[i].id,S[i].name);  
			printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
			printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].money,S[i].tax,S[i].wages);
			printf("\n");
			i++;		 
			if(i%k==0)
			{	
				printf("\n");
				printf("\t\t是否继续浏览?(Y/N)");  
				scanf("\t\t%c",&flag); 
			}
		}
		printf("\n工资数据已浏览完毕,即将自动返回主菜单\n\n");
	}
	
	if(m==2)																												//全部浏览
	{

		while(i<n && flag!='n' && flag!='N')					
		{
			printf("\n");
			printf("工号:%s  %s\n",S[i].id,S[i].name);  
			printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
			printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].money,S[i].tax,S[i].wages);
			printf("\n");
			i++;		 
		}
		printf("\n工资数据已浏览完毕,即将自动返回主菜单\n\n");
	}
	
	if(m==3)																												//返回
		{
			return 0;
		}
	return 0;
}

int modify(ZGGZ S[])                                                                                                        //修改模块
{
	int m,j;  
    char flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t***********修改方式************\n");  
        printf("\t\t┌------------------------------┐\n");  
        printf("\t\t│          1.检索工号          │\n");  
        printf("\t\t│          2.检索姓名          │\n");  
        printf("\t\t│          3.返回              │\n");    
        printf("\t\t└------------------------------┘\n");  
        printf("\n\t\t请选择查询方式:");  
        scanf("\t\t%d",&m);					//选择修改方式  
	
		do										//检查输入是否符合规范  
			{  
				j=0;  
				if(m!=1&&m!=2&&m!=3)  
				{     
					j=1;  
					printf("\t\t您输入的检索方式不存在,请重新输入:");  
					scanf("\t\t%d",&m);			//不符合规范则重新选择查询方式  
				}  
			}while(j); 

		if(m==1)								//工号查询
			{
				int i;							//现在查询员工序号
				int flag=0;						//标记员工有没有存在
				char gonghao[10];
				printf("\n");
				printf("请输入要修改数据员工的编号：");
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
					printf("原始数据如下：");
					printf("工号:%s  %s\n",S[i].id,S[i].name);  
					printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
					printf("应发工资:%f\t个人所得税:%f\t实发工资:%f\n",S[i].money,S[i].tax,S[i].wages);
					printf("请输入修改后的数据:\n");
					printf("\t\t岗位工资:");
					scanf("%f",&S[i].money1);  
					printf("\t\t薪级工资:"); 
					scanf("%f",&S[i].money2);
					printf("\t\t职务津贴:");  
					scanf("%f",&S[i].money3);
					printf("\t\t绩效工资:");  
					scanf("%f",&S[i].money4);
					add_money(S);
					grsds(S);
					add_wages(S);
					printf("修改后的数据如下：");
					printf("工号:%s  %s\n",S[i].id,S[i].name);  
					printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
					printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].money,S[i].tax,S[i].wages);
				}
				else
				{
					printf("没有找到该编号的员工！\n");
				}
				printf("\n");
				system("pause");
			}

		if(m==2)								//姓名查询
		{
			int i;								//现在查询员工序号
			int flag=0;							//标记员工有没有存在
			char nm[10];
			printf("\n");
			printf("请输入要查询员工的姓名：");
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
				printf("原始数据如下：");
				printf("工号:%s  %s\n",S[i].id,S[i].name);  
				printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
				printf("应发工资:%f\t个人所得税:%f\t实发工资:%f\n",S[i].money,S[i].tax,S[i].wages);
				printf("请输入修改后的数据:\n");
				printf("\t\t岗位工资:");
				scanf("%f",&S[i].money1);  
				printf("\t\t薪级工资:"); 
				scanf("%f",&S[i].money2);
				printf("\t\t职务津贴:");  
				scanf("%f",&S[i].money3);
				printf("\t\t绩效工资:");  
				scanf("%f",&S[i].money4);
				add_money(S);
				grsds(S);
				add_wages(S);
				printf("修改后的数据如下：");
				printf("工号:%s  %s\n",S[i].id,S[i].name);  
				printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
				printf("应发工资:%f\t个人所得税:%f\t实发工资:%f",S[i].money,S[i].tax,S[i].wages);
			}
			else
			{
				printf("没有找到该姓名的员工！\n");
			}
			printf("\n");
			system("pause");
		}

		if(m==3)							    	//返回
		{
			return 0;
		}

		printf("\t\t是否继续修改?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}

int write(ZGGZ t[])																											//保存模块
{
	int i;
    FILE *fp;//定义文件指针
    if ((fp = fopen("gz.dat", "w")) == NULL)
    {
        printf("数据保存成功，请检查文件是否存在或损坏后重试!");
		return 0;
    }
	fscanf(fp,"%d",&n);
	for(i=0;i<n;i++)
	{
		fprintf(fp,"总计%d人\n",n);
		fprintf(fp,"工号:%s  %10s\n",t[i].id,t[i].name);  
		fprintf(fp,"岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",t[i].money1,t[i].money2,t[i].money3,t[i].money4);  
		fprintf(fp,"应发工资:%f\t个人所得税:%f\t实发工资:%f\n",t[i].money,t[i].tax,t[i].wages);
	}
    fclose(fp);
	printf("\n数据保存成功\n\n");  
    return 0;
}

int add(ZGGZ S[])																			//	添加模板
{		
	int i;
	int flag;
	while(flag!='n'&&flag!='N')
	{
		i=n++;
		system("cls");
		printf("\n\t\t***********数据添加************\n\n");  
		printf("请输入职工基本信息:\n");
		printf("\t\t工号:"); 

		do{																					//防止出现工号相同的情况
			flag=0;
			scanf("%s",&S[i].id);
			for (int j = 0; j < i; j++)
			{
				if(strcmp(S[i].id,S[j].id)==0)
				{
					printf("工号已存在，请重新输入:");
					flag=1;
					break;
				}
			}
		}while(flag==1);

		printf("\t\t姓名:"); 
			scanf("%s",&S[i].name);
		printf("\t\t岗位工资:");
			scanf("%f",&S[i].money1);  
		printf("\t\t薪级工资:"); 
			scanf("%f",&S[i].money2);
		printf("\t\t职务津贴:");  
			scanf("%f",&S[i].money3);
		printf("\t\t绩效工资:");  
			scanf("%f",&S[i].money4);

		add_money(S);
		grsds(S);
		add_wages(S);

		printf("\n新增职工数据如下：");
			printf("工号:%s  %s\n",S[i].id,S[i].name);  
		printf("岗位工资:%f\t薪级工资:%f\t职务津贴:%f\t绩效工资:%f\n",S[i].money1,S[i].money2,S[i].money3,S[i].money4);  
			printf("应发工资:%f\t个人所得税:%f\t实发工资:%f\n",S[i].money,S[i].tax,S[i].wages);

		printf("\t\t是否继续添加?(Y/N)");  
		scanf("\t\t%c",&flag);  
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
            printf("\n\t\t查询职工工资数据\n");  
            find(adr);  
            system("pause");  
            break;  
        case 2:   
            modify(adr);  
            system("pause");  
            break;  
        case 3:   
            add(adr);  
            system("pause");  
            break;  
        case 4:  
            printf("\n\t\t功能尚未完善，请尽情期待\n");  
//            del();  
            system("pause");  
            break;  
        case 5:  
            list(adr);  
            system("pause");  
            break;  
        case 6:   
            write(adr);  
            system("pause");  
            break;  

        case 7:      
            printf("\n\t\t谢谢使用，再见!\n");  //结束程序      
            printf("\n\t\t");      
            system("pause");      
            exit(0);      
        }  
    }  

	return 0;
}