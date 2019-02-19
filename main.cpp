//宏定义区
#include <stdio.h>//未完成
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
//宏定义区
#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
#define   LEN sizeof(struct Student)
#define   ADMIN_password "1804"

//结构体声明区
typedef struct Student
{
    long num;	                    /* 每个学生的学号 */
    char name[MAX_LEN];            	/* 每个学生的姓名 */
    float score[COURSE_NUM];	    /* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                      /* 每个学生的总成绩 */
    float aver;						/* 每个学生的平均成绩 */
    struct Student *next;
} STU;

typedef struct member
{
    char name[30];
    char ID[20];
    char password[30];
    char sex[15];
    char password_key[30];
}MEMBER;

typedef struct bookgrasp/*会员借出的书籍信息*/
{
	char number[15];/*图书编号*/
    char name[30];/*图书名称*/
    char author[20];/*作者*/
    char press[30];/*出版社*/
    char category[20]; /*类别*/
    float price;/*单价*/
 	char account[30];/*借书者ID*/
}BOOKGRASP;
//菜单函数区
int   Menu(void);                                      //创建菜单
void  menu1();
void  menu2();
void  menu3();
void  AboutMe();//引用 致谢

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
void display_memberbook();/*查看所有图书借阅信息函数*/
int check_repeat_ID(char id_account[20]);/*检查账户重复性函数*/
void find_account();/*账户找回函数*/

//成绩管理系统层级函数区
void  Print(STU *head, int n, int m);                  //打印函数
void  AverSumofEveryStudent(STU *head, int n, int m);  //计算每门课程的总分和平均分
void  AverSumofEveryCourse(STU *head, int n, int m);   //计算每个学生的总分和平均分
STU  *SortbyScore(STU *head, int n);				   //按每个学生的总分由高到低排出名次表
STU  *Creat(int n, int m);   //创建链表并录入信息
STU  *Creat1(int n, int m);
STU  *SortbyScore1(STU *head, int n);                  //按每个学生的总分由低到高排出名次表
STU  *SortbyNum(STU *head);                            //按学号由小到大排出成绩表
STU  *SortbyName(STU *head, int n);                    //按姓名的字典顺序排出成绩表
void  SearchbyNum(STU *head, int n, int m);            //按学号查询学生排名及其考试成绩
void  SearchbyName(STU *head, int n, int m);           //按姓名查询学生排名及其考试成绩
void  StatisticAnalysis(STU *head, int n, int m);      //按类别及比例输出
void  WritetoFile(STU *head, int n, int m);            //将每个学生的纪录信息写入文件
STU  *ReadfromFile(STU *head, int *n, int *m);         //从文件中读出每个学生的纪录信息并显示

int main()
{
    int flag1 = 1,flag2 = 1,flag3 = 1;
    int n, m;
    int i;
    int choice1,choice2,choice3;
    STU *head;  //定义头节点
    head = (STU *)malloc(LEN);//头结点赋空间
    FILE *p1,*p2,*p3;

    system("title 1804tomjobs");
    //创建文件
    if((p1=fopen("library.txt","r"))==NULL)/*p1是图书管理系统的书籍信息文件指针*/
    {
        p1=fopen("library.txt","w");
        fclose(p1);
    }
    if((p2=fopen("infomember.txt","r"))==NULL)/*p2是图书管理系统的会员个人信息文件指针*/
    {
        p2=fopen("infomember.txt","w");
        fclose(p2);
    }
    if( (p3=fopen("memberbook.txt","r"))==NULL)/*p3是图书管理系统的会员书籍信息文件指针*/
    {
        p3=fopen("memberbook.txt","w");
        fclose(p3);
    }

    while (flag1)
    {
        menu1();
        printf("\n请您选择（1~5）：");
        scanf("%d",&choice1);

        if(choice1==1)/*会员登录*/
        {
            int flag=0;
            char account1[20],account_choice;
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
                i = Menu();
                if (i == 1)
                {
                    system("cls");  //清屏
                    printf("\t\t\t******************************************************************************\n");
                    printf("\t\t\tInput student number(n<30):\n"); //输入学生数
                    printf("\t\t\t");
                    scanf("%d", &n);
                    printf("\t\t\tInput course number(m<=6):\n");
                    printf("\t\t\t");
                    scanf("%d", &m);
                }
                switch (i)
                {
                case 1:
                    printf("\t\t\tInput student's ID, name and score:\n");
                    head = Creat(n, m);
                    system("cls");  //清屏
                    break;
                case 2:
                    system("cls");  //清屏
                    AverSumofEveryStudent(head, n, m);
                    break;
                case 3:
                    system("cls");  //清屏
                    AverSumofEveryCourse(head, n, m);
                    break;
                case 4:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\tSort in ascending order by score:\n");
                    head = SortbyScore(head, n);
                    Print(head, n, m);
                    break;
                case 5:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\tSort in ascending order by score:\n");
                    head = SortbyScore1(head, n);
                    Print(head, n, m);
                    break;
                case 6:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\tSort in ascending order by number:\n");
                    head = SortbyNum(head);
                    Print(head, n, m);
                    break;
                case 7:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\tSort in dictionary order by name:\n");
                    head = SortbyName(head, n);
                    Print(head, n, m);
                    break;
                case 8:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\t******************************************************************************\n");
                    printf("\t\t\tInput the number you want to search:\n");
                    SearchbyNum(head, n, m);
                    break;
                case 9:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\t******************************************************************************\n");
                    printf("\t\t\tInput the name you want to search:\n");
                    SearchbyName(head, n, m);
                    break;
                case 10:
                    system("cls");  //清屏
                    StatisticAnalysis(head, n, m);
                    break;
                case 11:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    Print(head, n, m);
                    break;
                case 12:
                    system("cls");  //清屏
                    WritetoFile(head, n, m);
                    break;
                case 13:
                    system("cls");  //清屏
                    head = ReadfromFile(head, &n, &m);
                    break;
                case 0:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\t******************************************************************************\n");
                    printf("\t\t\tEnd of program!\n");
                    printf("\t\t\t******************************************************************************\n");
                    return 0;
                default:
                    system("cls");  //清屏
                    printf("\n\n\n");
                    printf("\t\t\t******************************************************************************\n");
                    printf("\t\t\tInput error!\n");
                    printf("\t\t\t******************************************************************************\n");

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
            flag2=1,flag3=1;//这是什么鬼？？
        }

        else if(choice1==2)/*会员注册*/
        {
            system("cls");
            printf("\n\n\n\t\t\t正在进入用户注册界面...");
            clock_delay();
            member_log_up();
        }
        else if(choice1==3)/*退出系统*/
        {
            flag1=0;
        }
    }
    return 0;
}
// 创建菜单
int   Menu(void)
{
    int i;
    system("title 学生成绩管理系统V7.0  By wyxiang");
    printf("\n\n");
    printf("\t\t\t                         学生成绩管理系统\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\t\t\t*                Management for Students' scores                             *\n");
    printf("\t\t\t*                1.  Input record                                            *\n");
    printf("\t\t\t*                2.  Caculate total and average score of every course        *\n");
    printf("\t\t\t*                3.  Caculate total and average score of every student       *\n");
    printf("\t\t\t*                4.  Sort in descending order by score                       *\n");
    printf("\t\t\t*                5.  Sort in ascending order by score                        *\n");
    printf("\t\t\t*                6.  Sort in ascending order by number                       *\n");
    printf("\t\t\t*                7.  Sort in dictionary order by name                        *\n");
    printf("\t\t\t*                8.  Search by number                                        *\n");
    printf("\t\t\t*                9.  Search by name                                          *\n");
    printf("\t\t\t*                10. Statistic analysis                                      *\n");
    printf("\t\t\t*                11. List record                                             *\n");
    printf("\t\t\t*                12. Write to a file                                         *\n");
    printf("\t\t\t*                13. Read from a file                                        *\n");
    printf("\t\t\t*                0.  Exit                                                    *\n");
    printf("\t\t\t******************************************************************************\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t*****************Please Input your choice:");
    scanf("%d", &i);
    return i;
}

// 创建链表
STU *Creat(int n, int m)
{
    STU *head;
    STU *p1, *p2;
    int i, j;
    // system("cls");
    for (i = 1; i < n + 1; i++)
    {
        p1 = (STU *)malloc(LEN);
        printf("\t\t\t");
        scanf("%ld", &p1->num);
        printf("\t\t\t");
        scanf("%s", p1->name);
        for (j = 0; j<m; j++)
        {
            printf("\t\t\t");
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

STU *Creat1(int n, int m)
{
    STU *head;
    STU *p1, *p2;
    int i, j;
    // system("cls");
    for (i = 1; i < n + 1; i++)
    {
        p1 = (STU *)malloc(LEN);
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

void  AverSumofEveryStudent(STU *head, int n, int m)
{
    STU *p;
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

void  AverSumofEveryCourse(STU *head, int n, int m)
{
    STU *p;
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

STU  *SortbyScore(STU *head, int n)
{
    STU *endpt;    //控制循环比较
    STU *p;        //临时指针变量
    STU *p1, *p2;

    p1 = (STU *)malloc(LEN);
    p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
    head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

    for (endpt = NULL; endpt != head; endpt = p)//
    {
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
        {
            if (p1->next->sum < p1->next->next->sum)  //如果前面的节点键值比后面节点的键值大，则交换
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

STU  *SortbyScore1(STU *head, int n)
{
    STU *endpt;    //控制循环比较
    STU *p;        //临时指针变量
    STU *p1, *p2;

    p1 = (STU *)malloc(LEN);
    p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
    head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

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

    p1 = head;              //把p1的信息去掉
    head = head->next;       //让head指向排序后的第一个节点
    free(p1);          //释放p1
    p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

    return head;
}

STU *SortbyNum(STU *head)
{
    STU *first;    //为原链表剩下用于直接插入排序的节点头指针
    STU *t;        //临时指针变量：插入节点
    STU *p, *q;     //临时指针变量

    first = head->next;      //原链表剩下用于直接插入排序的节点链表：可根据图12来理解
    head->next = NULL;       //只含有一个节点的链表的有序链表：可根据图11来理解

    while (first != NULL)        //遍历剩下无序的链表
    {
        //注意：这里for语句就是体现直接插入排序思想的地方
        for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //无序节点在有序链表中找插入的位置

        first = first->next; //无序链表中的节点离开，以便它插入到有序链表中

        if (q == head)      //插在第一个节点之前
        {
            head = t;
        }
        else            //p是q的前驱
        {
            p->next = t;
        }
        t->next = q;     //完成插入动作
        //first = first->next;
    }
    return head;
}

STU  *SortbyName(STU *head, int n)
{
    STU *endpt;    //控制循环比较
    STU *p;        //临时指针变量
    STU *p1, *p2;

    p1 = (STU *)malloc(LEN);
    p1->next = head;        //注意理解：我们增加一个节点，放在第一个节点的前面，主要是为了便于比较。因为第一个节点没有前驱，我们不能交换地址
    head = p1;                 //让head指向p1节点，排序完成后，我们再把p1节点释放掉

    for (endpt = NULL; endpt != head; endpt = p)
    {
        for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
        {
            if (strcmp(p1->next->name, p1->next->next->name)>0)  //如果前面的节点键值比后面节点的键值大，则交换
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;     //结合第4点理解
                p = p1->next->next;   //结合第6点理解
            }
        }
    }

    p1 = head;              //把p1的信息去掉
    head = head->next;       //让head指向排序后的第一个节点
    free(p1);          //释放p1
    p1 = NULL;          //p1置为NULL，保证不产生“野指针”，即地址不确定的指针变量

    return head;
}


void Print(STU *head, int n, int m)
{
    STU *p;
    int i;
    p = head;

    if (head != NULL)        //只要不是空链表，就输出链表中所有节点
    {
        printf("\t\t\t******************************************************************************\n");
        do
        {

            printf("\t\t\t%ld\t%s\t", p->num, p->name);
            for (i = 0; i<m; i++)
            {
                printf("%.0f\t", p->score[i]);
            }
            printf("%.0f\t%.0f\n", p->sum, p->sum / m);
            p = p->next;     //移到下一个节点
        }
        while (p != NULL);
        printf("\t\t\t******************************************************************************\n");
    }
}

void  SearchbyNum(STU *head, int n, int m)
{
    long num;
    int i;
    int flag = 1;
    printf("\t\t\t");
    scanf("%ld", &num);
    STU *p;
    p = head;
    if (head != NULL)
    {
        do
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
        while (p != NULL);
        if (flag)
        {
            printf("\t\t\t");
            printf("Not found!\n");
        }
    }
    printf("\t\t\t******************************************************************************\n");

}

void  SearchbyName(STU *head, int n, int m)
{
    char name[MAX_LEN];
    int i;
    int flag = 1;
    printf("\t\t\t");
    scanf("%s", name);
    STU *p;
    p = head;
    if (head != NULL)
    {
        do
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
        while (p != NULL);
        if (flag)
        {
            printf("\t\t\t");
            printf("Not found!\n");
        }
    }
    printf("\t\t\t******************************************************************************\n");

}

void  StatisticAnalysis(STU *head, int n, int m)
{
    int a[6];
    STU *p;
    p = head;
    int i, j;
    for (i = 0; i<m; i++)
    {
        p = head; // 不要忘了初始化，不然会炸
        for (j = 0; j<6; j++)  // 初始化
        {
            a[j] = 0;
        }
        do
        {
            if (p->score[i]<60)
            {
                a[0]++;
            }
            else if (p->score[i]<70)
            {
                a[1]++;
            }
            else if (p->score[i]<80)
            {
                a[2]++;
            }
            else if (p->score[i]<90)
            {
                a[3]++;
            }
            else if (p->score[i]<100)
            {
                a[4]++;
            }
            else
            {
                a[5]++;
            }

            p = p->next;

        }
        while (p != NULL);
        printf("\n\n\n");
        printf("\t\t\t******************************************************************************\n");
        printf("\t\t\t* For course %d:\n", i + 1);
        printf("\t\t\t* <60\t%d\t%.2f%%\n", a[0], 100 * a[0] / 6.0);
        printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 60, 69, a[1], 100 * a[1] / 6.0);
        printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 70, 79, a[2], 100 * a[2] / 6.0);
        printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 80, 89, a[3], 100 * a[3] / 6.0);
        printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 90, 99, a[4], 100 * a[4] / 6.0);
        printf("\t\t\t* %d\t%d\t%.2f%%\n", 100, a[5], 100 * a[5] / 6.0);
        printf("\t\t\t******************************************************************************\n");

    }
}

void  WritetoFile(STU *head, int n, int m)
{
    STU *p;
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
STU *ReadfromFile(STU *head, int *n, int *m)
{
    STU *p;
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

void menu1()
{
    system("color E9");
    printf("\n\n");
    printf("\t\t\t *=======================================*\n");
    printf("\t\t\t|  * - * - * Crazy BY tom jobs * - * - *  |\n");
    printf("\t\t\t| *                                     * |\n");
    printf("\t\t\t| |   [1]   会员登录                     | |\n");
    printf("\t\t\t| *                                     * |\n");
    printf("\t\t\t| |   [2]   会员注册                     | |\n");
    printf("\t\t\t| *                                     * |\n");
    printf("\t\t\t| |   [3]   退出系统                     | |\n");
    printf("\t\t\t| *                                     * |\n");
    printf("\t\t\t|  * - * - * - * - * - * - * - * - * - *  |\n");
    printf("\t\t\t *=======================================*\n");
}
void menu2()
{
    system("color BC");
    printf("\n\n");
    printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -会-员-界-面- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   查找图书信息               | |\n");
    printf("\t\t\t| *  [2]   借阅图书                   * |\n");
    printf("\t\t\t| |  [3]   归还图书                   | |\n");
    printf("\t\t\t| *  [4]   书库所有图书信息           * |\n");
    printf("\t\t\t| |  [5]   价位书籍推荐               | |\n");
    printf("\t\t\t| *  [6]   图书受欢迎度排行榜         * |\n");
    printf("\t\t\t| |  [7]   您的账户信息               | |\n");
    printf("\t\t\t| *  [8]   退出用户界面               * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
    printf("\t\t\t *=====================================*\n");
}

void menu3()//暂时不弄管理员了
{
    system("color 1D");
    printf("\n\n");
    printf("\t\t\t *======================================*\n");
    printf("\t\t\t| | * - * - * 管-理-员-界-面 * - * - * | |\n");
    printf("\t\t\t| *                                    * |\n");
    printf("\t\t\t| |  [1]   添加图书                    | |\n");
    printf("\t\t\t| *  [2]   删减图书                    * |\n");
    printf("\t\t\t| |  [3]   修改图书信息                | |\n");
    printf("\t\t\t| *  [4]   查找图书信息                * |\n");
    printf("\t\t\t| |  [5]   显示全部图书信息            | |\n");
    printf("\t\t\t| *  [6]   显示所有会员信息            * |\n");
    printf("\t\t\t| |  [7]   显示所有借阅信息            | |\n");
    printf("\t\t\t| *  [8]   退出管理员界面              * |\n");
    printf("\t\t\t| |                                    | |\n");
    printf("\t\t\t| * - * - * - * - * -- * - * - * - * - * |\n");
    printf("\t\t\t *======================================*\n");
}

void AboutMe()
{
    system("cls");
    printf("Code:  fuujiro\n");
    printf("Debug: fuujiro\n");
    printf("\n\n\t\t使用帮助请查看用户手册或程序猿手册!");
    printf("\n\n");
    printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
    printf(" | Fenrari做的图书馆这个版本让大家见笑了,里面可能会有些傻傻的地方或者bug! |\n");
    printf(" * 如果大家发现了,一定要联系我哦!我的邮箱是fengziyang97@163.com,笔芯!!!   *\n");
    printf(" |                                ^_^                                     |\n");
    printf(" ^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^**^*^*^*^*^*^*^*^*^\n");
    printf("\n\n按任意键退出.");
    getch();
}

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

int user_account(char account[20])
{
    FILE *p2,*p3;
    int n,number,booknumber,flag=0,i,flag2=1,count=0;
    char new_password[20],key[30],choice;
    MEMBER member[100];
    BOOKGRASP bookgrasp[100];
    system("cls");

    p2=fopen("infomember.txt","r");
    number=0;
    while(!feof(p2))
    {
        fscanf(p2,"%s %s %s %s %s\n",member[number].ID,member[number].password,
               member[number].password_key,member[number].name,member[number].sex);
        number++;
    }
    fclose(p2);

    p3=fopen("memberbook.txt","r");
    booknumber=0;
    while(!feof(p3))
    {
        fscanf(p3,"%s %s %s %s %s %f %s\n",
               bookgrasp[booknumber].number,bookgrasp[booknumber].name,bookgrasp[booknumber].author,bookgrasp[booknumber].press,
               bookgrasp[booknumber].category,&bookgrasp[booknumber].price,bookgrasp[booknumber].account);
        booknumber++;
    }
    fclose(p3);
    if(bookgrasp[0].price<=1e-8)
    {
        printf("当前图书馆未有任何借书信息");
        flag=0;
        printf("\n\n按任意键返回!\n");
        getch();
    }
    else
    {
        for(n=0; n<number; n++)
            if(strcmp(member[n].ID,account)==0)
            {
                i=0;
                printf("\n");
                printf("|---------------------------个人信息-------------------------|\n");
                printf("|姓名        性别      ID              密码                  |\n");
                printf("|%-12s%-10s%-16s%-22s%|\n",member[n].name,member[n].sex,member[n].ID,member[n].password);
                printf("|                                                            |\n");
                printf("|----------------------------图书借阅信息--------------------|\n");
                printf("|编号  书名        作者      出版社          类别    单价    |\n");

                while(i<booknumber)
                {
                    if(strcmp(bookgrasp[i].account,account)==0)
                    {
                        printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n",bookgrasp[i].number,
                               bookgrasp[i].name,bookgrasp[i].author,bookgrasp[i].press,
                               bookgrasp[i].category,bookgrasp[i].price);
                        count++;
                    }
                    i++;
                }
                if(strcmp(member[n].sex,"male")==0)
                    printf("\n%s先生，您当前借阅的书籍共有%d本。",member[n].name,count);
                else if(strcmp(member[n].sex,"female")==0)
                    printf("\n%s女士，您当前借阅的书籍共有%d本。",member[n].name,count);
                else
                    printf("\n%s，您当前借阅的书籍共有%d本。",member[n].name,count);

                if(bookgrasp[0].price<=1e-8)
                    printf("\n而图书馆内共有0本书籍正在被借阅。\n");
                else
                    printf("\n而图书馆内共有%d本书籍正在被借阅。\n",booknumber);

                printf("\nPS:是否需要修改密码(y/n):");
                fflush(stdin);
                choice=getch();
                while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
                    choice=getch();
                printf("%c",choice);
                printf("\n");
                if(choice=='Y'||choice=='y')
                {
                    printf("\n请输入修改密码的密钥(user_key):");
                    fflush(stdin);
                    gets(key);
                    if(strcmp(member[n].password_key,key)==0)
                    {
                        printf("请输入新密码：");
                        fflush(stdin);
                        gets(new_password);
                        strcpy(member[n].password,new_password);
                        flag=1;
                        p2=fopen("infomember.txt","w");
                        for(n=0; n<number; n++)
                            fprintf(p2,"%s %s %s %s %s\n",member[n].ID,member[n].password,
                                    member[n].password_key,member[n].name,member[n].sex);
                        fclose(p2);
                    }
                    else
                    {
                        printf("\n输入密钥错误!");
                    }
                }
                else
                    flag=0;
            }

    }
    if(flag==1)
    {
        printf("\n密码修改成功！");
        printf("\n按任意键返回!\n");
        getch();
        return 1;
    }
    else
    {
        return 0;
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

void password_circle()/*画框函数*/
{
    system("cls");
    printf("\n\n\n\t\t\t***================================*** \n");
    printf("\t\t\t                                   \n");
    printf("\t\t\t   账户 (account):");
}
void clock_delay()/*时间延时函数*/
{
    clock_t tm;
    tm=clock();
    while(clock()<tm+1000);
}
void find_account_circle()/*找回账户弹出框函数*/
{
	printf("\n\n\n\n");
	printf("\t\t\t===============H-E-L-P===================\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t* 您需不需要通过密钥找回账户？(输入y/n) *\n");
	printf("\t\t\t|                                       |\n");
	printf("\t\t\t=========================================\n");
	printf("\n\t\t\t您的选择是:");
}
