/***************************************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
FileName: 设计.cpp
Author:唐海涌   Version :1.01   Date:2018.06.24
Description: 
Version: 1.01版
Function List: 
1.main（）函数主要是根据用户的指令调用各个功能函数。
2.read()函数主要是读取职工工资数据。
3.write()函数主要是保存职工工资数据。
4.void fin()函数主要是查询职工工资数据。
5.list()函数主要是浏览职工工资数据。
6.modify()函数主要是修改职工工资。
7.del()函数主要是删除职工工资数据。
8.add()函数主要是添加职工工资数据。
9.grsds()函数主要是计算个人所得税。
10.menu_select()函数主要是输出可供用户参照的菜单,并将用户输入的值返回至main函数中。
11.createlist()函数主要是作为子函数创建双向链表。
12.add_money()函数用来计算应发工资。     
13.add_money() 此函数用来计算应发工资。
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
	struct people *prior;
	struct people *next;
}ZGGZ;//工资数据结构体

/***************************************************************************
Function:menu_select()           
Description:输出可供用户参照的菜单,并将用户输入的值返回至main函数中
Calls:  暂无                  
Called By:main()函数。                  
Table Accessed: 暂无  
Table Updated: 暂无                    
Input: 暂无             
Output: 暂无           
Return:暂无         
Others:暂无         
***************************************************************************/
int menu_select()																					//功能选择模块
{  
    char c;  
    do  
    {  
        system("cls");  
	  printf("\n                            ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n\n");
	  printf("       请选择（1—7）：\n");
	  printf("        =========================================================================================================\n");
	  printf("       |                                                                                                         |\n");
	  printf("       |                                     1.查询职工工资记录                                                  |\n");
	  printf("       |                                     2.修改职工工资记录                                                  |\n");
	  printf("       |                                     3.添加职工工资记录                                                  |\n");
	  printf("       |                                     4.删除职工工资记录                                                  |\n");
	  printf("       |                                     5.浏览职工记录                                                      |\n"); 
	  printf("       |                                     6.保存数据到文件                                                    |\n");
	  printf("       |                                     7.退出系统                                                          |\n");
	  printf("       |                                                                                                         |\n");
	  printf("        =========================================================================================================\n\n"); 
	  printf("       你的选择是：");
        c=getche();   
    }while(c<'1'||c>'7');//检查输入是否符合规范
	printf("\n\n");
	system("pause"); 
    return(c-'0');  
}  

/********************************************
Function: createlist()
Description: 作为子函数创建双向链表
Calls By: main()
Table Accessed: 暂无       
Table Updated: 暂无    
Input: 数组作为形参，地址作为实参
Other: 地址为返回值
Return:暂无         
Others:暂无 
*********************************************/
ZGGZ *createlist(ZGGZ t[])       //创建有n个元素的双向链表 
{
    ZGGZ *head, *p, *q;
    head = (ZGGZ *)malloc(sizeof(ZGGZ));//为头部指针分配内存空间
	head->prior = head;
    head->next = head;
    p = head;
    for(int i=0;i<n;i++)//创建n个双向链表元素
    {
        q = (ZGGZ *)malloc(sizeof(ZGGZ));
		strcpy(q->id ,t[i].id);//把数组中的数据分配到双向链表数据域中
		strcpy(q->name,t[i].name);
		q->money1=t[i].money1;
		q->money2=t[i].money2;
		q->money3=t[i].money3;
		q->money4=t[i].money4;
		q->money=t[i].money;
		q->tax=t[i].tax;
		q->wages=t[i].wages;
        p->next = q;           //p的下节点指向q
		head->prior = q;       //head的前节点指向q
		q->prior = p;          //q的前节点指向p
        q->next = head;        //q的下节点指向head
        p = q;                 //q赋值给p
    }
    return head;
}

/***************************************************************************
Function:read（）            
Description:用来读取文件“gx.dat”中的数据，并存到结构体zggz中           
Calls:  暂无                  
Called By:main()函数。                  
Table Accessed: 文件“gx.dat”          
Table Updated: 暂无                    
Input: 暂无             
Output: 暂无           
Return:暂无         
Others:暂无         
***************************************************************************/
int read(ZGGZ t[])																					//文件读取模块
{
	   int i;
       FILE *fp;//定义文件指针
       if ((fp = fopen("gx.dat", "rb")) == NULL)
       {
		   printf("该文件不存在,正在新建中");
           fopen("gx.dat", "wb+");
		   printf("创建成功，请及时输入数据");
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
Function:find（）           
Description:此数用来进行通过工号或者名字查询对应人的工资数据。               
Calls: 暂无               
Called By:main()函数。                  
Table Accessed: 结构体zggz。         
Table Updated: 暂无                    
Input:暂无               
Output:暂无            
Return:暂无          
Others:暂无         
***************************************************************************/
int find(ZGGZ *p)																					 //工资查询模块  
{  
	int j;  
    char m,flag='y';  
    while(flag!='n'&&flag!='N')  
    {  
		system("cls");
        printf("\n\t\t**********************************查询方式********************************\n");  
		printf("\n\t\t请您选择(1-3):\n");  
        printf("\t\t┌------------------------------------------------------------------------┐\n");  
        printf("\t\t│                                 1.查找工号                             │\n");  
        printf("\t\t│                                 2.查找姓名                             │\n");  
        printf("\t\t│                                 3.返回                                 │\n");    
        printf("\t\t└------------------------------------------------------------------------┘\n");  
        printf("\n\t\t请选择查询方式:");  
        m=getche();					//选择查询方式  
	
		do										//检查输入是否符合规范  
			{  
				j=0;  
				if(m!='1'&&m!='2'&&m!='3')  
				{     
					j=1;  
					printf("\n\t\t您输入的查询方式不存在,请重新输入:");  
					m=getche();		//不符合规范则重新选择查询方式  
				}  
			}while(j); 

		if(m=='1')								//工号查询
			{
				int flag=0;						//标记员工有没有存在
				char gonghao[10];
				printf("\n");
				printf("\n\t\t请输入要查询员工的编号：");
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
					printf("\n\t\t姓名:%s\n",q->name);  
					printf("\t\t岗位工资:%.2f\n",q->money1);  
					printf("\t\t薪级工资:%.2f\n",q->money2);  
					printf("\t\t职务津贴:%.2f\n",q->money3);  
					printf("\t\t绩效工资:%.2f\n",q->money4);  
					printf("\t\t应发工资:%.2f\n",q->money);
					printf("\t\t个人所得税:%.2f\n",q->tax);  
					printf("\t\t实发工资:%.2f\n",q->wages);  
				}
				else
				{
					printf("没有找到该编号的员工！\n");
				}
				printf("\n");
				system("pause");
			}

		if(m=='2')								//姓名查询
		{
			int flag=0;							//标记员工有没有存在
			char nm[10];
			printf("\n");
			printf("请输入要查询员工的姓名：");
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

							printf("\n\t\t工号:%s\n",q->id);  
							printf("\t\t岗位工资:%.2f\n",q->money1);  
							printf("\t\t薪级工资:%.2f\n",q->money2);  
							printf("\t\t职务津贴:%.2f\n",q->money3);  
							printf("\t\t绩效工资:%.2f\n",q->money4);  
							printf("\t\t应发工资:%.2f\n",q->money);
							printf("\t\t个人所得税:%.2f\n",q->tax);  
							printf("\t\t实发工资:%.2f\n",q->wages);  

			}
			else
			{
				printf("没有找到该姓名的员工！\n");
			}
			printf("\n");
			system("pause");
		}

		if(m=='3')							    	//返回
		{
			return 0;
		}

		printf("\t\t是否继续查询?(Y/N)");  
		scanf("\t\t%c",&flag);  
	}
	return 0;  
}  

/***************************************************************************
Function:add_money()           
Description:此函数用来计算应发工资。                
Calls:               
Called By:add（）、modify（）。                
Table Accessed: 结构体zggz。         
Table Updated: 暂无                   
Input:传入的参数a是代表第几个员工。              
Output: 暂无            
Return: 返回计算好的个人所得税。        
Others: 暂无    
***************************************************************************/
void add_money(ZGGZ *p)									//自检模块 计算应发工资       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
		q->money=q->money1+q->money2+q->money3+q->money4;
}

/***************************************************************************
Function:grsds()           
Description:此函数用来计算个人所得税。                
Calls:               
Called By:add（）、modify（）。                
Table Accessed: 结构体zggz。         
Table Updated: 暂无                   
Input:传入的参数a是代表第几个员工。              
Output: 暂无            
Return: 返回计算好的个人所得税。        
Others: 暂无    
***************************************************************************/
void grsds(ZGGZ *p)										//自检模块 计算个人所得税       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
	{
		if(q->money<500)																									//工资小于500时个人所得税																											
			q->tax=q->money*0.05;
		else if(q->money<2000)																							//工资大于500小于2000时个人所得税
			q->tax=(q->money-500)*0.1+500*0.05;	
		else if(q->money<5000)																							//工资大于2000小于5000时个人所得税
			q->tax=(q->money-2000)*0.15+1500*0.1+500*0.05;														     			
		else if(q->money<20000)																							//工资大于5000小于20000时个人所得税
			q->tax=(q->money-5000)*0.2+3000*0.15+1500*0.1+500*0.05;														    
		else if(q->money<40000)																							//工资大于20000小于40000时个人所得税
			q->tax=(q->money-20000)*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;											     
		else if(q->money<60000)																							//工资大于40000小于60000时个人所得税
			q->tax=(q->money-40000)*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;								     		
		else if(q->money<80000)																							//工资大于60000小于80000时个人所得税
			q->tax=(q->money-60000)*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		     				
		else if(q->money<100000)																							//工资大于80000小于100000时个人所得税
			q->tax=(q->money-80000)*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;				
		else																												//工资大于100000时个人所得税
			q->tax=(q->money-100000)*0.45+20000*0.4+20000*0.35+20000*0.3+20000*0.25+15000*0.2+3000*0.15+1500*0.1+500*0.05;		
	}
}

/***************************************************************************
Function:add_wages()           
Description:此函数用来计算实发工资。                
Calls:               
Called By:add（）、modify（）。                
Table Accessed: 结构体zggz。         
Table Updated: 暂无                   
Input:传入的参数a是代表第几个员工。              
Output: 暂无            
Return: 返回计算好的个人所得税。        
Others: 暂无    
***************************************************************************/
void add_wages(ZGGZ *p)																									//自检模块 计算实发工资	       
{
	people *q=p;
	for (q=q->next; q!=p; q=q->next)
		q->wages=q->money-q->tax;
}

/***************************************************************************
Function:list（）           
Description:此函数用来浏览所有工资成员的数据           
Calls:暂无                   
Called By:main()函数。                  
Table Accessed: 结构体zggz。          
Table Updated: 暂无                    
Input: 暂无              
Output: 暂无           
Return: 暂无       
Others: 暂无       
***************************************************************************/
void list(ZGGZ *head)																											//浏览模块
{
	people *p;																										
	p = head;
	p = p->next;
	system("cls");
	printf("\n\t\t**********************************浏览模板********************************\n");  
	while(p!=head)					
	{
		printf("\n");
		printf("工号:%s  %s\n",p->id,p->name);  
		printf("岗位工资:%.2f\t薪级工资:%.2f\t职务津贴:%.2f\t绩效工资:%.2f\n",p->money1,p->money2,p->money3,p->money4);  
		printf("应发工资:%.2f\t个人所得税:%.2f\t实发工资:%.2f",p->money,p->tax,p->wages);
		printf("\n");
		p=p->next;		 
	}
	printf("\n工资数据已浏览完毕,即将自动返回主菜单\n\n");
}

/***************************************************************************
Function:modify（）          
Description:此函数用来修改职工工资数据，通过判断姓名或者工号来筛选出指定的数据。            
Calls：grsds（）函数。                 
Called By:main()函数。                  
Table Accessed: 结构体zggz。          
Table Updated: 暂无                   
Input: 暂无             
Output: 暂无          
Return: 暂无      
Others: 暂无      
***************************************************************************/
int modify(ZGGZ *p)                                                                                                        //修改模块
{
	int flag=0;						//标记员工有没有存在
	char gonghao[10];
	printf("\n");
	printf("请输入要修改数据员工的编号：");
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
		printf("原始数据如下：");
		printf("工号:%s  %s\n",q->id,q->name);  
		printf("岗位工资:%.2f\t薪级工资:%.2f\t职务津贴:%.2f\t绩效工资:%.2f\n",q->money1,q->money2,q->money3,q->money4);  
		printf("应发工资:%.2f\t个人所得税:%.2f\t实发工资:%.2f\n",q->money,q->tax,q->wages);
		printf("请输入修改后的数据:\n");
		float a[4];															//定义临时的数组储存用户输入的数据
		printf("\t\t岗位工资:");
		scanf("%f",&a[0]);  
		printf("\t\t薪级工资:"); 
		scanf("%f",&a[1]);
		printf("\t\t职务津贴:");  
		scanf("%f",&a[2]);
		printf("\t\t绩效工资:");  
		scanf("%f",&a[3]);														//将临时数组中的人赋值进去
		q->money1=a[0];
		q->money2=a[1];
		q->money3=a[2];
		q->money4=a[3];
		add_money(p);
		grsds(p);
		add_wages(p);
		printf("修改后的数据如下：");
		printf("工号:%s  %s\n",q->id,q->name);  
		printf("岗位工资:%.2f\t薪级工资:%.2f\t职务津贴:%.2f\t绩效工资:%.2f\n",q->money1,q->money2,q->money3,q->money4);  
		printf("应发工资:%.2f\t个人所得税:%.2f\t实发工资:%.2f",q->money,q->tax,q->wages);
	}
	else
	{
		printf("没有找到该编号的员工！\n");
	}
	printf("\n");
	system("pause");
	printf("\t\t是否继续修改?(Y/N)");  
	scanf("\t\t%c",&flag);  
	return 0;  
}
/***************************************************************************
Function:write（）           
Description:用来将结构体中的数据保存至文件“gx.dat”中。                
Calls:  暂无                   
Called By:main()函数。                 
Table Accessed: 文件“gx.dat”       
Table Updated: 暂无                 
Input:暂无               
Output:暂无            
Return:暂无        
Others:暂无         
***************************************************************************/
int write(ZGGZ *p)																											//保存模块
{
    FILE *fp;//定义文件指针
    if ((fp = fopen("gx.dat", "w")) == NULL)
    {
        printf("数据保存失败，请检查文件是否存在或损坏后重试!");
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
	printf("\n数据保存成功\n\n");  
    return 0;
}

/***************************************************************************
Function:add（）          
Description:此函数用来增加职工工资信息。              
Calls:暂无                   
Called By:main()函数。                   
Table Accessed: 结构体zggz。          
Table Updated: 暂无                     
Input: 暂无            
Output: 暂无           
Return: 暂无       
Others: 暂无     
***************************************************************************/
int add(ZGGZ *head)																			//	添加模板
{		
	n++;
	system("cls");
	printf("\n\t\t**********************************数据添加********************************\n");  
	people *p=head,*t=head,*q,a;
    p=p->next;
	if(n == 100)
	{
		printf("人数已满，即将自动返回主菜单");
		return 0;
	}
	else
	{
		printf("请你录入用户信息:\n");//通过工号或姓名进行查找
		printf("工号：");
		scanf("%s", &a.id);//工号
		while(p!=head)//判断工号相同的不能添加
		{ 
			if(strcmp(p->id,a.id)==0)
			{
				printf("工号已存在，请重新输入命令\n");
				return 0;
			}
			else
			{
				p=p->next;
			}
		}
	printf("姓名：");
	scanf("%s",&a.name);//姓名
	printf("岗位工资：");
	scanf("%f",&a.money1);//岗位工资
	printf("薪级工资：");
	scanf("%f",&a.money2);//薪级工资
	printf("职务津贴：");
	scanf("%f",&a.money3);//职务津贴
	printf("绩效工资：");
	scanf("%f",&a.money4);//绩效工资
	q = (people *)malloc(sizeof(people));
	strcpy(q->id ,a.id);//把数组中的数据分配到双向链表数据域中
	strcpy(q->name,a.name);
	q->money1=a.money1;
	q->money2=a.money2;
	q->money3=a.money3;
	q->money4=a.money4;

	p->prior->next= q;           
	head->prior = q;       //head的前节点指向q
	q->prior = p->prior;          //q的前节点指向p
	q->next = head;        //q的下节点指向head 

	add_money(head);
	grsds(head);
	add_wages(head);
	printf("新增职工信息为：\n");
	printf("工号：%s\t姓名：%s\t岗位工资：%.2f\n",q->id,q->name,q->money1);
	printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->money2,q->money3,q->money4);
	printf("薪级工资：%.2f\t职务津贴：%.2f\t绩效工资：%.2f\n",q->money,q->tax,q->wages);
	printf("添加完毕,即将自动返回主菜单\n");
	}
	return 0;
}

/***************************************************************************
Function:del（）            
Description:此函数用来删除所选定数据。               
Calls:暂无             
Called By:main()函数。                   
Table Accessed: 结构体zggz。        
Table Updated: 暂无                     
Input: 暂无             
Output: 暂无           
Return: 暂无      
Others: 暂无      
***************************************************************************/
int del(ZGGZ *head)						//删除模块
{
	int m=0;						//删除标志量
	int j;
	char flag;
	char gonghao[10];
	while(flag!='n'&&flag!='N')
	{
		system("cls"); 
		people *p = head, *q;
		p = p->next;
		printf("\n\t\t**********************************数据删除********************************\n");  
		printf("\n");
		printf("请输入要删除员工的工号：");
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
			printf("\n已查询到工位为%s的职工，他的名字是%s\n",p->id,p->name);
			printf("是否确定删除该员工信息?(Y/N)");  
			scanf("\t\t%c",&flag);
			do																													//检查输入是否符合规范  
			{  
				j=0;  
				if(flag!='Y' && flag!='y' && flag!='N' && flag!='n')  
				{     
					j=1;  
					printf("请输入（Y/N）\n");  
					scanf("\t\t%c",&flag);																							//不符合规范则重新选择浏览方式  
				}  
			}while(j); 
		}
		else
		{
			printf("没有找到该工号的员工！\n");
		}
		if(flag=='y' || flag=='Y')											//确认删除
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
			printf("\n删除成功\n");
		}
		flag='y';
		printf("是否继续删除操作?(Y/N)\n");
		scanf("\t\t%c",&flag);
	}
	printf("即将返回主菜单");
	return 0;
}

/***************************************************************************
Function:main（）           
Description:利用主函数来实现各种操作，调用各个函数进行操作。               
Calls:add(),del(),fin(),fin(),list(),modify(),read(),write(),add_money(),add_wages()            
Called By:无。                 
Table Accessed: 结构体zggz。         
Table Updated: 暂无                    
Input: 暂无              
Output: 暂无          
Return: 暂无        
Others: 暂无      
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
            printf("\n\t\t谢谢使用，再见!\n");  //结束程序      
            printf("\n\t\t");      
            system("pause");      
            exit(0);      
        }  
    }  

	return 0;
}