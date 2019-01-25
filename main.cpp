//
//  main.cpp
//  hello nihao
//
//  Created by Macx on 19/1/25.
//  Copyright (c) 2019年 Macx. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

int n=0;

//顺序表
struct student//list
{
    char name[20];           //名字
    char num[20];            //学号
    char Class[20];          //班级
    char mayor[20];          //专业
    int age;                 //年龄
    int score;               //成绩
    struct student *next;
}*head,*p,*p1,*p2;       //head表示开头  p表示不同位置的数据

void find1 ()
{
    char name[20];
    printf("请输入要查找的姓名：");
    scanf("%s",name);
    p=head;
    do
    {
        if(strcmp(name,p->name)==0)
        {
            printf("\n信息已被找到：\n姓名\t学号\t\t班级\t年龄\t专业\t\t成绩\n");
            printf("%-8s%-16s%-8s%-8d%-16s%-8d\n\n",p->name,p->num,p->Class,p->age,p->mayor,p->score);
        }
        p=p->next;                            ////指针指向下一个节点
    }while(p!=NULL);
}

void find2 ()
{
    char num[20];
    printf("请输入要查找的学号：");
    scanf("%s",num);
    p=head;
    do
    {
        //指针指向开头
        if(strcmp(num,p->num)==0)
        {
            printf("\n信息已被找到：\n姓名\t学号\t\t班级\t年龄\t专业\t\t成绩\n");
            printf("%-8s%-16s%-8s%-8d%-16s%-8d\n\n",p->name,p->num,p->Class,p->age,p->mayor,p->score);
        }
        p=p->next;                            //指针指向下一个节点
    }while(p!=NULL);
}

void sortlist()
{}

void fanzhuan()
{}

void lianije()
{}

void add()                    //添加
{
    p1=(struct student *)malloc(sizeof(struct student));         //开辟存储空间
    if(n==0)                                     //判断链表开头
        head=p1;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
    else p2->next=p1;                            //n!=0 就它们连接起来
    printf("请输入学生基本信息：\n姓名：");
    scanf("%s",p1->name);
    printf("学号：");
    scanf("%s",p1->num);
    printf("年龄：");
    scanf("%d",&p1->age);
    printf("班级：");
    scanf("%s",p1->Class);
    printf("专业：");
    scanf("%s",p1->mayor);
    printf("成绩：");
    scanf("%d",&p1->score);
    p2=p1;                                       //p2指向p1所在的地址
    p2->next = NULL;                              //链表结束标志
    n++;                                       //n判断是不是第一个数据
    
}

void print()
{
    if(n!=0)
    {
        p=head;//p先指向开头
        
        printf("姓名\t学号\t\t班级\t年龄\t专业\t\t成绩\n");
        //只要p指向的内存区域有数据 就打印内容
        
        while(p!=NULL)
        {
            printf("%-8s%-16s%-8s%-8d%-16s%-8d\n",p->name,p->num,p->Class,p->age,p->mayor,p->score);
            p=p->next;
        }
    }
    
    else
        printf("There is no data\n");
}

void find()           //查找
{
    void find1();//name
    void find2();//num
    if(n!=0)
    {
        int inf;
        printf("1.按姓名查找\n2.按学号查询\n");
        scanf("%d",&inf);
        switch(inf)
        {
            case 1:
                find1();
                break;
            case 2:
                find2();
                break;
        }
    }
    else
    {
        printf("Can not find since you have no add data\n");
    }
}

void Delete()
{
    if(n!=0)
    {
        struct student *f,*l;                              //定义新的指针 f使用来指向要删除的数据用来释放内存!
        char name[20];
        printf("请输入要删除的姓名：");
        scanf("%s",name);
        p=head;
        if(strcmp(head->name,name)==0)
        {f=head;head=head->next;free(f);}
        else
        {
            
            //不满足if表示这不是要删除的那一个节点，l暂时指向p  之后p再指向下一个节点，如果这个是要删除的节点那么l指向这个节点的next的地址
            while(p!=NULL)
            {
                if(strcmp(p->name,name)==0)
                {f=p;l->next=p->next;free(f);break;}
                l=p;
                p=p->next;
            }
        }
    }
    else
        printf("******您还没有添加数据哟!\n");
    printf("数据已经被删除\n");
    
}

void amend()
{
    if(n!=0)
    {
        int c;
        char name[20];
        printf("请输入要修改的姓名：");
        scanf("%s",name);
        p = head;
        do
        {
            if(strcmp(name,p->name)==0)
            {
                printf("\n被修改人信息如下：\n姓名\t学号\t\t班级\t年龄\t专业\t\t成绩\n");
                printf("%-8s%-16s%-8s%-8d%-16s%-8d\n",p->name,p->num,p->Class,p->age,p->mayor,p->score);
                break;
            }
            p=p->next;                            ////指针指向下一个节点
        }while(p!=NULL);
        
        printf("\n\n1.修改姓名\n2.修改学号\n3.修改班级\n4.修改年龄\n5.修改专业\n6.修改成绩\n7.退出修改\n\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("姓名修改为：");
                scanf("%s",p->name);break;
            case 2:
                printf("学号修改为：");
                scanf("%s",p->num);break;
            case 3:
                printf("班级修改为：");
                scanf("%s",p->Class);break;
            case 4:
                printf("年龄修改为：");
                scanf("%d",&p->age);break;
            case 5:
                printf("专业修改为：");
                scanf("%s",p->mayor);break;
            case 6:
                printf("成绩修改为：");
                scanf("%d",&p->score);break;
            case 7:
                break;
        }
        printf("\n\n操作成功!\n\n");
    }
    else
        printf("******您还没有添加数据哟!\n");
    
}

void save()
{
    FILE *fp;
    struct student *p;
    if((fp=fopen("C:\\数据内容\\data.txt","wb"))==NULL)
        printf("Can not open the file!");
    p = head;
    while(p!=NULL)
    {
        if(fwrite(p,Length,1,fp)!=1)
        {
            printf("写入数据出错\n");
            fclose(fp);
            break;
        }
        p=p->next;
    }
    fclose(fp);
    printf("存储完成\n");
}

void read()
{
    FILE *fp;
    if((fp=fopen("C:\\数据内容\\data.txt","rb+"))==NULL)
    {printf("Can not open file!");exit(0);}
    do
    {
        p1=(struct student *)malloc(Length);
        if(n==0)                                     //判断链表开头
            head=p1;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
        else
            p2->next=p1;;
        fread(p1,Length,1,fp);
        p2=p1;
        n+=1;
    }while(p2->next!=NULL);
    fclose(fp);
    printf("读取完成!\n\n");
    system("pause");
    system("cls");
}

class stack1
{
public:
    
};

class queen
{
public:
    
};

class bignum
{
    
};

//字符串
void kmp()
{}
struct trie
{};

//查找
struct binary_tree
{};

struct hashmap
{};

struct redblacktree
{};

//排序
void quicksort()
{}
void bubblesort()
{}
void mergesort()
{}
void selectsort()
{}

//图论
void buildgra()//建图
{}
void hamiton()
{}
void mintree()
{}
void kruskal()
{}
void dijksra()
{}
void thtree()
{}




int main()                                  //主函数
{
    int inf=1;
    
    while(inf!=0)
    {
        printf("〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          2.显示全部信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          3.查找学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          4.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          5.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          6.保存学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          7.读取学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
        printf("〓〓〓〓〓〓〓〓〓★  ☆          0.  退出系统          ☆  ★〓〓〓〓〓〓〓〓〓\n");
        
        
        printf("请选择：");
        scanf("%d",&inf);
        if(inf>=0&&inf<=9)
        {
            switch(inf)
            {
                case 1://添加
                    add();
                    break;
                case 2://打印
                    print();
                    break;
                case 3://查找
                    find();
                    break;
                case 4://删除
                    Delete();
                    break;
                case 5://修改
                    amend();
                    break;
                case 6://保存
                    save();
                    break;
                case 7://读取
                    read();
                    break;
                    
            }
        }
        else
        {
            printf(" 您输入的不符合要求，将返回主菜单!\n");
        }
    }
}



