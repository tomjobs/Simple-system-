//Created by tomjobs1804
//感谢：https://github.com/tomjobs/LIMS 框架看了网上博客 
//宏定义区
#include <stdio.h>//未完成
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>//getch 
//宏定义区

#define   len sizeof(struct Student)
#define   Password "1804"

//结构体声明区
typedef struct Student
{
    long num;	                    /* 每个学生的学号 */
    char name[10];            	/* 每个学生的姓名 */
    float score[10];	    /* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                      /* 每个学生的总成绩 */
    float aver;						/* 每个学生的平均成绩 */
    struct Student *next;
} STUDENT;

typedef struct member
{
    char name[30];
    char ID[20];
    char password[30];
    char sex[15];
    char password_key[30];
} MEMBER;

//菜单函数区
int   Menu(void);                                      //创建菜单
void  menu1();
void  menu2();
void  menu3();
void  AboutMe();//引用，致谢，本程序绝非是独立完成，而是在参考前人代码的基础加以改进才得到此程序。 

//工具函数区
int compare_password(char password[20]);/*密码比对函数 */
void clock_delay(); /*时间延时函数*/
void password_circle();/*密码框装饰函数*/
void find_account_circle();/*找回帐户弹出框函数*/

//会员信息系统函数区
int user_account(char account[20]);/*个人账户信息*/
void member_log_up();/*会员注册函数*/
int member_log_in(char account[20]);/*会员登录函数*/
void ADMIN_watch_member();/*查看会员信息函数*/
int check_repeat_ID(char id_account[20]);/*检查账户重复性函数*/
void find_account();/*账户找回函数*/

//成绩管理系统层级函数区
void  Print(STUDENT *head, int n, int m);                  
void  AverSumofEveryStudent(STUDENT *head, int n, int m);  //计算每门课程的总分和平均分
void  AverSumofEveryCourse(STUDENT *head, int n, int m);   //计算每个学生的总分和平均分
STUDENT  *SortbyScore(STUDENT *head, int n);				   //按每个学生的总分由高到低排出名次表
STUDENT  *Creat(int n, int m);   //创建链表并录入信息
STUDENT  *Creat1(int n, int m);  //创建链表 
STUDENT  *SortbyScore1(STUDENT *head);                  //学生成绩从低到高排出名次
STUDENT  *SortbyNum(STUDENT *head);                            //学号从小到大输出成绩
STUDENT  *SortbyName(STUDENT *head);                    //姓名字典顺序输出成绩
void  SearchbyNum(STUDENT *head, int n, int m);            //学号查询
void  SearchbyName(STUDENT *head, int n, int m);           //姓名查询学
void  statistic(STUDENT *head, int n, int m);      //按类别及比例输出
void  WritetoFile(STUDENT *head, int n, int m);            //将每个学生信息写入文件
STUDENT  *ReadfromFile(STUDENT *head, int *n, int *m);         //文件中读取信息 

int main()
{
    int flag1 = 1,flag2 = 1,flag3 = 1;
    int n, m;
    int i;
    char choice1,choice2,choice3;
    STUDENT *head;  //定义头节点
    head = (STUDENT *)malloc(len);//头结点赋空间
    FILE *p1,*p2;

    system("title 1804tomjobs");

    //创建文件
    if((p1=fopen("student.txt","r"))==NULL)/*p1学生信息文件指针*/
    {
        p1=fopen("student.txt","w");
        fclose(p1);
    }
    if((p2=fopen("infomember.txt","r"))==NULL)/*p2是会员信息文件指针*/
    {
        p2=fopen("infomember.txt","w");
        fclose(p2);
    }
    
	while (flag1)//flag1控制外循环，用于跳出循环，下面的flag不同的值代表跳出不同的循环。 
    {
        system("cls");
        menu1();
        printf("\n请选择（1~4）：");
        //      scanf("%d",&choice1);//用scanf的话就不能起到阻挡非法字符的作用了 
        
        choice1 = getch();
        while(choice1!='1'&&choice1!='2'&&choice1!='3'&&choice1!=4)
            choice1=getch();//感谢lims:https://github.com/tomjobs/LIMS 的代码，此处的读入保证了限定性，本程序的会员界面也是膜他的程序。 
        printf("%c",choice1);
        fflush(stdin);
        
        /*------------------------学生------------------------*/ 
        if(choice1=='1')/*会员登录*/
        {
            int flag=0;
            char account1[20];
			char account_choice;
            system("cls");
            password_circle();
            fflush(stdin);
            gets(account1);
            flag=member_log_in(account1);/*账户登录函数*/
            if(flag==2)
            {
                system("cls");
                password_circle();
                fflush(stdin);
                gets(account1);
                flag=member_log_in(account1);/*账户登录函数*/
            }
            if(flag==1)//登录成功
            {
                while(flag2)
                {
                    menu2();
                    printf("\n");
                    printf("请您选择(1-6):");
                    choice3=getch();
                    while(choice3!='1'&&choice3!='2'&&choice3!='3'&&choice3!='4'&&choice3!='5'&&choice3!='6'&&choice3!='7'&&choice3!='8')
                        choice3=getch();
                    printf("%c",choice3);//输出缓存区
                    switch (choice3)
                    {
                    case '1':
                        system("cls");  //清屏
                        printf("\n\n\n");
                        Print(head, n, m);
                        break;
                    case '2':
                        system("cls");  //清屏
                        printf("\n\n\n");
                        printf("\t\t\tSort in ascending order by score:\n");
                        head = SortbyScore(head, n);
                        Print(head, n, m);
                        break;
                    case '3':
                        system("cls");  //清屏
                        statistic(head, n, m);
                        break;
                    case '4':
                        system("cls");  //清屏
                        printf("敬请期待\n"); 
                        break;
                    case '5':
                        system("cls");  //清屏
                        printf("敬请期待\n"); 
                        break;
                    case '6':
                        system("cls");  //清屏
                        printf("\n\n\n");
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tEnd!\n");
                        printf("\t\t\t******************************************************************************\n");
                        flag2 = 0;
                        break; 
                    default:
                        system("cls");  //清屏
                        printf("\n\n\n");
                        printf("\t\t\tError!\n");
					}

            }
            }
            else  //登录失败找回账号
            {
                system("cls");
                find_account_circle();/*装饰弹出框函数*/
                scanf("%d",&account_choice);
                printf("\n");
                if(account_choice=='Y'||account_choice=='y')
                    find_account();/*账户找回函数*/
            }
            flag2=1;
        }
        
        /*------------------------学生------------------------*/ 

        /*------------------------学生注册------------------------*/ 

        else if(choice1=='2')/*会员注册*/
        {
            system("cls");
            printf("\n\n\n\t\t\t正在进入用户注册界面...");
            clock_delay();
            member_log_up();//注册界面 
        }
        
        /*------------------------学生注册------------------------*/ 

        
       /*------------------------老师------------------------*/ 

		else if(choice1=='3')/*管理员登录*/
        {
            if(compare_password(Password))
            {
                printf("\n\n\t\t\t输入密码正确!\n\n\t\t\t\t进入管理员界面中\n");
                clock_delay();
                while(flag2)
                    {
                    menu3();
                    printf("\n");
                    printf("请选择(0~D):");
                    choice3=getch();
                    while(choice3!='1'&&choice3!='2'&&choice3!='3'&&choice3!='4'&&choice3!='5'&&choice3!='6'&&choice3!='7'&&choice3!='8'&&choice3!='9'&&choice3!='A'&&choice3!='B'&&choice3!='C'&&choice3!='D'&&choice3!='0')
                        choice3=getch();
                    printf("%c",choice3);//输出缓存区
                    
                    if (choice3 == '1')
                    {
                        system("cls");  //清屏
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tInput student number(n<30):\n\t\t\t"); //输入学生数
                        scanf("%d", &n);
                        printf("\t\t\tInput course number(m<=6):\n\t\t\t");
                        scanf("%d", &m);
                    }
                    switch (choice3)
                    {
                    case '1':
                        printf("\t\t\tInput student's ID, name and score:\n");
                        head = Creat(n, m);
                        system("cls"); 
                        break;
                    case '2':
                        system("cls"); 
                        AverSumofEveryStudent(head, n, m);
                        break;
                    case '3':
                        system("cls");  
                        AverSumofEveryCourse(head, n, m);
                        break;
                    case '4':
                        system("cls");  
                        printf("\n\n\n");
                        printf("\t\t\tSort in ascending order by score:\n");
                        head = SortbyScore(head, n);
                        Print(head, n, m);
                        break;
                    case '5':
                        system("cls"); 
                        printf("\n\n\n");
                        printf("\t\t\tSort in ascending order by score:\n");
                        head = SortbyScore1(head);
                        Print(head, n, m);
                        break;
                    case '6':
                        system("cls");  
                        printf("\n\n\n");
                        printf("\t\t\tSort in ascending order by number:\n");
                        head = SortbyNum(head);
                        Print(head, n, m);
                        break;
                    case '7':
                        system("cls");  
                        printf("\n\n\n");
                        printf("\t\t\tSort in dictionary order by name:\n");
                        head = SortbyName(head);
                        Print(head, n, m);
                        break;
                    case '8':
                        system("cls"); 
                        printf("\n\n\n");
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tInput the number you want to search:\n");
                        SearchbyNum(head, n, m);
                        break;
                    case '9':
                        system("cls"); 
                        printf("\n\n\n");
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tInput the name you want to search:\n");
                        SearchbyName(head, n, m);
                        break;
                    case 'A':
                        system("cls"); 
                        statistic(head, n, m);
                        break;
                    case 'B':
                        system("cls"); 
                        printf("\n\n\n");
                        Print(head, n, m);
                        break;
                    case 'C':
                        system("cls"); 
                        WritetoFile(head, n, m);
                        break;
                    case 'D':
                        system("cls");  
                        head = ReadfromFile(head, &n, &m);
                        break;
                    case '0':
                        system("cls");  
                        printf("\n\n\n");
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tEnd!\n");
                        printf("\t\t\t******************************************************************************\n");
                        flag2 = 0;
                        break; 
                    default:
                        system("cls"); 
                        printf("\n\n\n");
                        printf("\t\t\t******************************************************************************\n");
                        printf("\t\t\tInput error!\n");
                        printf("\t\t\t******************************************************************************\n");
						break;
                    }
                }
			


                }
                else
                {
                    printf("\n\n\t\t\t\t  --输入密码错误!--\n");
                    clock_delay();
                }
                flag2=1;
    }
    
        /*------------------------老师------------------------*/ 

            else if(choice1=='4')/*退出系统*/
            {
                flag1=0;
            }
        }
        return 0;
    }
    

// 创建菜单


// 创建链表
    STUDENT *Creat(int n, int m)
    {
        STUDENT *head;//头结点 
        STUDENT *p1, *p2;//临时结点 
        int i, j;
        for (i = 1; i < n + 1; i++)
        {
            p1 = (STUDENT *)malloc(len);
            scanf("%ld", &p1->num);
            scanf("%s", p1->name);
            for (j = 0; j<m; j++)//输入成绩 
            {
                scanf("%f", &p1->score[j]);
            }
            p1->next = NULL;
            if (i == 1)
            {
                head = p2 = p1;
            }
            else
            {
                p2->next = p1;
                p2 = p1;
            }
        }
        return(head);
    }

    STUDENT *Creat1(int n, int m)
    {
        STUDENT *head;
        STUDENT *p1, *p2;
        int i, j;
        for (i = 1; i < n + 1; i++)
        {
            p1 = (STUDENT *)malloc(len);
            p1->next = NULL;
            if (i == 1)
            {
                head = p2 = p1;
            }
            else
            {
                p2->next = p1;
                p2 = p1;
            }
        }
        return(head);
    }

    void  AverSumofEveryStudent(STUDENT *head, int n, int m)
    {
        STUDENT *p;
        int i, j = 1;
        char ch;
        float sum;
        p = head;
        if (head != NULL)
        {
            printf("\t\t\t******************************************************************************\n");
            for (i = 0; i<m; i++)
            {
                p = head;
                sum = 0.0;
                do
                {
                    sum += p->score[i];
                    p = p->next;
                }
                while (p != NULL);

                printf("\t\t\tcourse %d:    sum=%.0f , aver=%.0f\n", j, sum, sum / n);
                j++;
            }
            printf("\t\t\t******************************************************************************\n");

        }
    }

    void  AverSumofEveryCourse(STUDENT *head, int n, int m)
    {
        STUDENT *p;
        int i, j;
        p = head;
        if (head != NULL)
        {
            printf("\n\n\n");
            printf("\t\t\t******************************************************************************\n");
            for (i = 0; i<n; i++)
            {
                p->sum = 0.0;
                for (j = 0; j<m; j++)
                {
                    p->sum += p->score[j];
                }
                p->aver = p->sum / m;
                printf("\t\t\tstudent %d:    sum=%.0f , aver=%.0f\n", i + 1, p->sum, p->aver);
                p = p->next;
            }
            printf("\t\t\t******************************************************************************\n");
        }
    }
    
/*---------------------排序----------------------------*/ 

    STUDENT  *SortbyScore(STUDENT *head, int n)
    {
        STUDENT *endpt;    //控制循环比较
        STUDENT *p;        //临时指针变量
        STUDENT *p1, *p2;

        p1 = (STUDENT *)malloc(len);
        p1->next = head;//增加一个前驱结点，此网上代码做法 ，目的是便于比较 
        head = p1;      //head指向p1

        for (endpt = NULL; endpt != head; endpt = p)//
        {
            for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
            {
                if (p1->next->sum < p1->next->next->sum)
                {
                    p2 = p1->next->next;
                    p1->next->next = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p = p1->next->next;
                }
            }  //交换
        }

        p1 = head;              //把p1的信息去掉
        head = head->next;       //让head指向排序后的第一个节点
        free(p1);          //释放p1
        p1 = NULL;          //保证不产生野指针

        return head;
    }

    STUDENT  *SortbyScore1(STUDENT *head)
    {
        STUDENT *endpt;    //控制循环比较
        STUDENT *p;        //临时指针变量
        STUDENT *p1, *p2;

        p1 = (STUDENT *)malloc(len);
        p1->next = head;        
        head = p1;                

        for (endpt = NULL; endpt != head; endpt = p)
        {
            for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
            {
                if (p1->next->sum > p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
                {
                    p2 = p1->next->next;
                    p1->next->next = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p = p1->next->next;
                }
            }
        }

        p1 = head;              
        head = head->next;       
        free(p1);        
        p1 = NULL;         

        return head;
    }

	STUDENT  *SortbyNum(STUDENT *head)
    {
        STUDENT *endpt;    //控制循环比较
        STUDENT *p;        //临时指针变量
        STUDENT *p1, *p2;

        p1 = (STUDENT *)malloc(len);
        p1->next = head;        
        head = p1;                

        for (endpt = NULL; endpt != head; endpt = p)
        {
            for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
            {
                if (p1->next->num > p1->next->next->num)  //如果前面的节点键值比后面节点的键值大，则交换
                {
                    p2 = p1->next->next;
                    p1->next->next = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p = p1->next->next;
                }
            }
        }

        p1 = head;              //把p1的信息去掉
        head = head->next;       //让head指向排序后的第一个节点
        free(p1);          //释放p1
        p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

        return head;
    }
    STUDENT  *SortbyName(STUDENT *head)
    {
        STUDENT *endpt;    //控制循环比较
        STUDENT *p;        //临时指针变量
        STUDENT *p1, *p2;

        p1 = (STUDENT *)malloc(len);
        p1->next = head;        
        head = p1;                

        for (endpt = NULL; endpt != head; endpt = p)
        {
            for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
            {
                if (strcmp(p1->next->name, p1->next->next->name)>0)  
                {
                    p2 = p1->next->next;
                    p1->next->next = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;    
                    p = p1->next->next;   
                }
            }
        }

        p1 = head;              
        head = head->next;       
        free(p1);         
        p1 = NULL;          

        return head;
    }

/*---------------------排序----------------------------*/ 

    void Print(STUDENT *head, int n, int m)
    {
        STUDENT *p;
        p = head;

        if (head != NULL)//判断非空与否 
        {
            printf("******************************************************************************\n");
       		while (p != NULL);
			{

                printf("\t\t\t%ld\t%s\t", p->num, p->name);
                for (int i = 0; i<m; i++)
                {
                    printf("%.0lf\t", p->score[i]);
                }
                printf("%.0lf\t%.0lf\n", p->sum, p->sum / m);
                p = p->next;     //移到下一个节点
            }
            printf("******************************************************************************\n");
        }
    }


/*---------------------搜索----------------------------*/ 
    void  SearchbyNum(STUDENT *head, int n, int m)
    {
        long num;
        int i;
        int flag = 1;
        printf("\t\t\t");
        scanf("%ld", &num);
        STUDENT *p;
        p = head;
        if (head != NULL)
        {
            while (p != NULL)
            {
                if (p->num == num)
                {
                    printf("\t\t\t");
                    printf("%ld\t%s\t", p->num, p->name);
                    for (i = 0; i<m; i++)
                    {
                        printf("%.0f\t", p->score[i]);
                    }
                    printf("%.0f\t%.0f\n", p->sum, p->sum / m);
                    flag = 0;

                }
                p = p->next;

            }
            if (flag)
            {
                printf("Not found!\n");
            }
        }
        printf("******************************************************************************\n");

    }

    void  SearchbyName(STUDENT *head, int n, int m)
    {
        char name[10];
        int i;
        int flag = 1;
        printf("\t\t\t");
        scanf("%s", name);
        STUDENT *p;
        p = head;
        if (head != NULL)
        {
            while (p != NULL)
            {
                if (strcmp(name, p->name) == 0)
                {
                    printf("\t\t\t");
                    printf("%ld\t%s\t", p->num, p->name);
                    for (i = 0; i<m; i++)
                    {
                        printf("%.0f\t", p->score[i]);
                    }
                    printf("%.0f\t%.0f\n", p->sum, p->sum / m);
                    flag = 0;
                }
                p = p->next;

            }
            if (flag)
            {
                printf("\t\t\t");
                printf("Not found!\n");
            }
        }
        printf("\t\t\t******************************************************************************\n");

    }
/*---------------------搜索----------------------------*/ 

    void  statistic(STUDENT *head, int n, int m)//统计 
    {
        int num[6];
        STUDENT *p;
        p = head;
        int i, j;
        for (i = 0; i<m; i++)
        {
            p = head; // 不要忘了初始化，不然会炸
            for (j = 0; j<6; j++)  // 初始化
            {
                num[j] = 0;
            }
            while (p != NULL)
            {
                if (p->score[i]<60)
                {
                    num[0]++;
                }
                else if (p->score[i]<70)
                {
                    num[1]++;
                }
                else if (p->score[i]<80)
                {
                    num[2]++;
                }
                else if (p->score[i]<90)
                {
                    num[3]++;
                }
                else if (p->score[i]<100)
                {
                    num[4]++;
                }
                else
                {
                    num[5]++;
                }

                p = p->next;

            }
        }
            printf("\n\n\n");//百分制 
            printf("******************************************************************************\n");
            printf("\t\t\t* For course %d:\n", i + 1);
            printf("\t\t\t* <60\t%d\t%.2f%%\n", num[0], 100 * num[0] / 6.0);
            printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 60, 69, num[1], 100 * num[1] / 6.0);
            printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 70, 79, num[2], 100 * num[2] / 6.0);
            printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 80, 89, num[3], 100 * num[3] / 6.0);
            printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 90, 99, num[4], 100 * num[4] / 6.0);
            printf("\t\t\t* %d\t%d\t%.2f%%\n", 100, num[5], 100 * num[5] / 6.0);
            printf("******************************************************************************\n");
    	}
/*---------------------文件----------------------------*/ 

    void  WritetoFile(STUDENT *head, int n, int m)
    {
        STUDENT *p;
        p = head;
        FILE *fp;
        int i, j;
        printf("\n\n\n");
        printf("\t\t\t******************************************************************************\n");
        if ((fp = fopen("student.txt", "w")) == NULL)
        {
            printf("\t\t\tFail to open student.txt\n");
            return;
        }
        fprintf(fp, "%d\t%d\n", n, m);
        for (i = 0; i<n; i++)
        {
            fprintf(fp, "%12ld%12s", p->num, p->name);
            for (j = 0; j<m; j++)
            {
                fprintf(fp, "%12.0f", p->score[j]);
            }
            fprintf(fp, "%12.0f%12.0f\n", p->sum, p->sum / m);

            p = p->next;
        }
        printf("\t\t\tExport Successfully!\n");
        fclose(fp);
        printf("\t\t\t******************************************************************************\n");

    }



//这里用了直接生成了一个新的链表，确保可以直接读取存好的数据
    STUDENT *ReadfromFile(STUDENT *head, int *n, int *m)
    {
        STUDENT *p;
        FILE *fp;
        int i, j;
        if ((fp = fopen("student.txt", "r")) == NULL)
        {
            printf("\t\t\tFail to open student.txt\n");
            return NULL;
        }
        fscanf(fp, "%d\t%d\n", n, m);
        head = Creat1(*n, *m);  //创建了一个空链表，并且赋给head
        p = head;
        for (i = 0; i<*n; i++)
        {
            fscanf(fp, "%12ld", &p->num);
            fscanf(fp, "%12s", p->name);
            for (j = 0; j<*m; j++)
            {
                fscanf(fp, "%12f", &p->score[j]);
            }
            fscanf(fp, "%12f%12f", &p->sum, &p->aver);

            p = p->next;

        }
        i = *n;
        j = *m;
        printf("\t\t\tImport Successfully!\n");
        fclose(fp);

        Print(head, i, j);

        return head;
    }
/*---------------------文件----------------------------*/ 

/*---------------------菜单----------------------------*/ 

    void menu1()
    {
        system("color E9");
        printf("\n\n");
        printf("\t\t\t *=======================================*\n");
        printf("\t\t\t|  * - * - * Create BY tom jobs * - * - *  |\n");
        printf("\t\t\t| *                                     * |\n");
        printf("\t\t\t| |   [1]   学生登录                     | |\n");
        printf("\t\t\t| *                                     * |\n");
        printf("\t\t\t| |   [2]   学生注册                     | |\n");
        printf("\t\t\t| *                                     * |\n");
        printf("\t\t\t|     [3]   老师登录                    * |\n");
        printf("\t\t\t| *                                     * |\n");
        printf("\t\t\t| |   [4]   退出系统                     | |\n");
        printf("\t\t\t| *                                     * |\n");
        printf("\t\t\t|  * - * - * - * - * - * - * - * - * -  *  |\n");
        printf("\t\t\t *=======================================*\n");
    }
    void menu2()
    {
        system("color BC");
        printf("\n\n");
        printf("\t\t\t *=====================================*\n");
        printf("\t\t\t| | * - * - * -学-生-界-面- * - * - * | |\n");
        printf("\t\t\t| *                                   * |\n");
        printf("\t\t\t| |  [1]   输出成绩               | |\n");
        printf("\t\t\t| *  [2]   排名查询                   * |\n");
        printf("\t\t\t| |  [3]   成绩统计                   | |\n");
        printf("\t\t\t| *  [4]   老师评价               * |\n");
        printf("\t\t\t| *  [5]   意见反馈           * |\n");
        printf("\t\t\t| *  [6]   退出用户界面               * |\n");
        printf("\t\t\t| |                                   | |\n");
        printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
        printf("\t\t\t *=====================================*\n");
    }


void menu3()
    {


        printf("\n\n");
        printf("\t\t\t| | * - * - *          老—师-界-面           * -   * -   * -  *\n");
        printf("                         学生成绩管理系统\n");
        printf("*********************************************************************\n");
        printf("*       Management for Students' scores                            *\n");
        printf("*       1. 输入学生信息                                            *\n");
        printf("*       2. 课程平均分                                              *\n");
        printf("*       3. 学生平均分                                              *\n");
        printf("*       4. 成绩降序                                                *\n");
        printf("*       5. 成绩升序                                                *\n");
        printf("*       6. 学号排序                                                *\n");
        printf("*       7. 名字排序                                                *\n");
        printf("*       8. 学号搜索                                                *\n");
        printf("*       9. 名字搜索                                                *\n");
        printf("*       A. 成绩统计                                                *\n");
        printf("*       B. 成绩展示                                                *\n");
        printf("*       C. 写入文件                                                *\n");
        printf("*       D. 读取文件                                                *\n");
        printf("*       0. 退出                                                    *\n");
        printf("*********************************************************************\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("*****************输入你的选择********************:");
    }
/*---------------------菜单----------------------------*/ 

/*---------------------账户----------------------------*/ 

    void member_log_up()
    {
        char choice1,choice2;
        int flag=1;
        FILE *p2;
        MEMBER member;

        while(1)
        {
            system("cls");
            fflush(stdin);

            printf("输入您想注册的ID名:");
            gets(member.ID);

            if(check_repeat_ID(member.ID))
            {
                printf("该ID已被注册！请重新注册^_^\n");
                printf("按任意键重新注册\n\n");
                getch();
                flag=1;
            }
            else
            {
                flag=0;
                printf("输入您的密码(不要告知他人):");
                gets(member.password);

                printf("输入找回密码的密钥(以免忘记账户或密码不能登陆！):");
                gets(member.password_key);

                printf("输入您的姓名:");
                gets(member.name);

                printf("输入您的性别(男士输入male,女士输入female):");
                gets(member.sex);

                printf("是否保存这次注册信息(y/n):");
                choice1=getch();
                while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
                    choice1=getch();
                printf("%c",choice1);
                printf("\n");
                if(choice1=='Y'||choice1=='y')
                {
                    p2=fopen("infomember.txt","a");
                    fprintf(p2,"%s %s %s %s %s\n",member.ID,member.password,
                            member.password_key,member.name,member.sex);
                    fclose(p2);
                    printf("\n您的账户已注册成功！\n");
                }
                else
                {
                    printf("\n您的注册信息未保存!\n");
                }
                printf("\n是否继续注册会员(y/n):");
                choice2=getch();
                while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
                    choice2=getch();
                printf("%c",choice2);
                printf("\n");
            }
            if(choice2=='Y'||choice2=='y'||flag==1)
                continue;
            else
                break;
        }
    }


    void find_account()/*账户找回函数*/
    {
        FILE *p2;
        MEMBER member[100];
        int number,n,k=3,flag=1,mark=0;
        char choice='0';
        char vacancy[10]="";
        char search[30],compare[30],new_password[20];

        system("cls");
        fflush(stdin);
        printf("输入您的姓名:");
        gets(search);
        p2=fopen("infomember.txt","r");
        number=0;
        while(!feof(p2))
        {
            fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
                   member[number].password_key,member[number].name,member[number].sex);
            number++;
        }
        fclose(p2);
        if(strcmp(member[0].ID,vacancy)==0)
        {
            printf("系统中还没有任何会员信息!\n\n");
        }
        else
        {
            for(n=0; n<number; n++)
                if(strcmp(member[n].name,search)==0)
                {
                    mark=1;
                    while(flag)
                    {
                        printf("请输入您的密钥:");
                        fflush(stdin);
                        gets(compare);
                        if(strcmp(member[n].password_key,compare)==0)
                        {
                            printf("\n");
                            printf("|------------------------------个人信息------------------------------|\n");
                            printf("|姓名        性别      ID                  密码	                     |\n");
                            printf("|%-12s%-10s%-20s%-26s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);

                            printf("\n是否需要修改密码(y/n):");
                            fflush(stdin);
                            choice=getch();
                            while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                                choice=getch();
                            printf("%c",choice);
                            printf("\n");
                            if(choice=='Y'||choice=='y')
                            {
                                printf("\n请输入新密码：");
                                fflush(stdin);
                                gets(new_password);
                                strcpy(member[n].password,new_password);
                                flag=0;
                            }
                            else
                                flag=0;
                        }
                        else
                        {
                            --k;/*密码输入次数count*/
                            if(k!=0)
                            {
                                printf("\n\n\n\t\t您的密码输入有误!\n\t\t您还有%d次机会重新输入密码！",k);
                                printf("您是否要继续输入密码(y/n):");
                                fflush(stdin);
                                while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                                    choice=getch();
                                printf("%c",choice);
                                printf("\n");
                                if(choice=='Y'||choice=='y')
                                    flag=1;
                                else
                                    flag=0;
                            }
                            else
                            {
                                printf("您输入次数已用完！正在退回主界面...");
                                flag=0;
                            }
                        }
                    }
                }
        }
        if(mark==0)
        {
            printf("您并未注册本系统会员!\n");
        }
        else
        {
            if(choice!='0'&&choice!='n'&&choice!='N')
            {
                p2=fopen("infomember.txt","w");
                for(n=0; n<number; n++)
                    fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
                            member[n].password_key,member[n].name,member[n].sex);
                fclose(p2);
                printf("您已成功找回/修改账户!\n");
            }
        }
        printf("\n\n按任意键回到主菜单!\n");
        fflush(stdin);
        getch();
    }

    int member_log_in(char account[15])/*会员登录函数*/
    {
        FILE *p2;
        MEMBER member[100];
        char choice1,choice2;
        int flag1=0,flag2=1,n,k=3;
        int number;

        p2=fopen("infomember.txt","r");
        number=0;
        while(!feof(p2))
        {
            fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
                   member[number].password_key,member[number].name,member[number].sex);
            number++;
        }
        fclose(p2);
        for(n=0; n<number; n++)
            if(strcmp(member[n].ID,account)==0)
            {
                flag1=1;
                break;
            }
        if(flag1)
        {
            while(flag2)
            {
                if(compare_password(member[n].password))/* 调用会员密码比对函数 */
                {
                    printf("\n\n\n\t\t\t   核对正确！正在进入会员界面...");
                    clock_delay();
                    return 1;
                }
                else
                {
                    --k;/*密码输入次数count*/
                    if(k!=0)
                    {
                        printf("\n\n\n\t\t\t   您的密码输入有误!还有%d次机会重新输入密码！",k);
                        printf("\n\t\t\t   您是否要继续输入密码(y/n):");
                        fflush(stdin);
                        choice1=getch();
                        while(choice1!='Y'&&choice1!='y'&&choice1!='N'&&choice1!='n')
                            choice1=getch();
                        printf("%c",choice1);
                        printf("\n");
                        if(choice1=='Y'||choice1=='y')
                            flag2=1;
                        else
                            return 0;
                    }
                    else
                    {
                        printf("\n\n\t\t\t   您输入次数已用完！按任意键退出...");
                        fflush(stdin);
                        getch();
                        return 0;
                    }
                }
            }
            flag2=1;
        }
        else
        {
            printf("\n\n\n\t\t\t  该ID还未注册,是否需要注册会员(y/n):");
            
            choice2=getch();
            while(choice2!='Y'&&choice2!='y'&&choice2!='N'&&choice2!='n')
                choice2=getch();
            printf("%c",choice2);
            
            printf("\n");
            if(choice2=='Y'||choice2=='y')
            {
                member_log_up();
                return 2;
            }
            else
                return 0;
        }
    }

    int compare_password(char *password)/*密码比对函数 */
    {
        int i=0;
        char compare[20],c;
        fflush(stdin);
        printf("\n\t\t\t   密码(password):");
        while((c=getch())!=13)//\r是将光标移到该行首位
        {
            if(c==8&&i>0)
            {
                printf("\b \b");//清除*号和错符
                i--;
                continue;
            }
            if(c!=8)
            {
                compare[i++]=c;
                putchar('*');
            }
        }
        compare[i]='\0';
        if(strcmp(password,compare)==0)
        {
            printf("\a");  //响铃
            return 1;
        }
        else
        {
            printf("\a");  //响铃
            return 0;
        }
    }

    int check_repeat_ID(char *id_account)/*查重函数*/
    {
        FILE *p2;
        MEMBER member[100];
        int flag1=0,flag2=1,n,number;

        p2=fopen("infomember.txt","r");
        number=0;
        while(!feof(p2))
        {
            fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
                   member[number].password_key,member[number].name,member[number].sex);
            number++;
        }
        fclose(p2);
        for(n=0; n<number; n++)
            if(strcmp(member[n].ID,id_account)==0)
            {
                flag1=1;
                break;
            }
        if(flag1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void password_circle()
    {
        system("cls");
        printf("\n\n\n\t\t\t***================================*** \n");
        printf("\t\t\t                                   \n");
        printf("\t\t\t   账户 (account):");
    }
    
    
    void clock_delay()//延时 
    {
        clock_t tm;
        tm=clock();
        while(clock()<tm+1000);
    }
    
    void find_account_circle()//找回账户 
    {
        printf("\n\n\n\n");
        printf("\t\t\t===============H-E-L-P===================\n");
        printf("\t\t\t|                                       |\n");
	    printf("\t\t\t|                                       |\n");
        printf("\t\t\t* 您需不需要通过密钥找回账户？(输入y/n) *\n");
        printf("\t\t\t|                                       |\n");
        printf("\t\t\t|                                       |\n");
		printf("\t\t\t=========================================\n");
        printf("\n\t\t\t您的选择是:");
    }
    
    /*---------------------账户----------------------------*/ 
