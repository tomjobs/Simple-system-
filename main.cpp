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
#include<stack>
#include<queue>
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

struct student* fanzhuan1(struct student *head)
{
    struct student* newlist;
    struct student* tmp;
    
    if(head==NULL||(tmp = (struct student*)malloc(sizeof(struct student)))==NULL)
    {
        return NULL;
    }
    
    newlist->score = head->score;//先仅赋上score
    newlist->next = NULL;
    
    while(head->next != NULL)
    {
        tmp = newlist->next;
        newlist->next = head->next;
        head->next = head->next->next;
        newlist->next->next = tmp;
    }
    
    free(head);
    return newlist;
}

struct student* fanzhuan2(struct student *head)//将每次的节点放在这玩意后面
{
    
    struct student* tmp = NULL;
    struct student* p = NULL;
        
    if(head==NULL)
    {
        return NULL;
    }
    
    tmp = head;
    while(tmp->next != NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

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
        if(fwrite(p,sizeof(struct student),1,fp)!=1)
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
        p1=(struct student *)malloc(sizeof(struct student));
        if(n==0)                                     //判断链表开头
            head=p1;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
        else
            p2->next=p1;;
        fread(p1,sizeof(struct student),1,fp);
        p2=p1;
        n+=1;
    }while(p2->next!=NULL);
    fclose(fp);
    printf("读取完成!\n\n");
    system("pause");
    system("cls");
}


//队列
struct QNode    //定义队列结点的数据结构
{
    QNode *next; //指针域,指向下一个结点
    double data;    //数据域，存储队列信息
};

struct LinkQueue    //定义队列的数据结构
{
    QNode *front;      //队首指针,指向QNode类型的指针
    QNode *rear;       //队尾指针
};

void InitQueue(LinkQueue &Q)     //构造一个空的队列
{
    QNode *q;
    q = new QNode;    //申请一个结点的空间
    q->next = NULL;   //当作头结点
    //队首与队尾指针都指向这个结点，指针域为NULL
    Q.front = q;
    Q.rear = q;
}

int IsEmpty(LinkQueue &Q)    //判断队列是否为空
{
    if (Q.rear == Q.front)
        return 0;
    else
        return 1;
}

void EnQueue(LinkQueue &Q,double e)     //从队列尾部插入元素
{
    QNode *p;    //新创建一个结点
    p = new QNode;
    p->next = NULL;
    p->data = e;  //输入数据信息
    //将新结点插入队列尾部
    Q.rear->next = p;
    Q.rear = p;       //设置新的尾结点
}

void DeQueue(LinkQueue &Q, double &e)   //从队列首部删除一个结点
{
    QNode *p;
    p = Q.front->next;
    e = p->data;    //保存要出队列的数据
    Q.front->next = p->next;       //将下一个结点当作头结点后面链接的第一个结点
    if (Q.rear == p)    //如果要删除的元素即为尾结点，则将头指针赋予尾指针，一同指向头结点，表示队列为空
        Q.rear = Q.front;
    delete p;
}

void DestoryQueue(LinkQueue &Q)       //销毁一个队列
{
    while (Q.front)
    {
        Q.rear = Q.front;    //从头节点开始，一个一个删除队列结点，释放空间
        delete Q.front;
        Q.front = Q.rear;
    }
}

void solve2()
{
    LinkQueue *Q;  //定义一个队列Q
    Q = new LinkQueue;
    InitQueue(*Q);
    cout << "开始往队列里输入数据，以-1作为结束符" << endl;
    cout << "请输入一个数：" << endl;
    double a, x;
    cin >> a;
    while (a != -1)
    {
        EnQueue(*Q, a);
        cout << "请输入一个数：" << endl;
        cin >> a;
    }
    //输出队列元素,队首->队尾
    QNode *p;
    p = Q->front->next;
    if (p == NULL)     //如果为空表，直接退出
    {
        cout << "队列为空！" << endl;
        return ;
    }
    cout << "队列数据依次为：" << endl;
    while (p!=NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    //删除队列元素
    while (!IsEmpty(*Q))
    {
        DeQueue(*Q, x);
        cout << x << " ";
    }
    //释放内存空间
    delete Q->front;
    delete Q;
}

//栈
//stack.h
class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Stack();
    void Push(int data);//入栈
    void Pop();//出栈
    void Print();//打印栈
private:
    Node *top;//栈顶
    Node *buttom;//栈底
    int size;//栈元素数量
};



//
//class bignum
//{
//    
//};
//
//字符串
char T[1000];
char P[100];
char f[101];
char f2[101];

void find(char *T,char *P,char *f)
{
    int n = strlen(T);
    int m = strlen(P);
    int j = 0;
    for(int i = 0;i<n;i++)
    {
        while(j&&T[i]!=P[j])
            j = f[j];
        if(T[i] == P[j])j++;
        if(j==m)printf("%d\n",i-m+1);
    }
}

void getFail(char *P,int *f)
{
    int m = strlen(P);
    f[0] = f[1] = 0;
    f2[0] = f2[1] = 0;
    for(int i = 1;i<m;i++)
    {
        int j = f2[i];
        while(j&&P[i]!=P[j])j = f2[j];
        f2[i+1] = f[i+1] = (P[i]==P[j])?j+1:0;
        if(f[i+1]==j+1&&P[i+1]==P[j+1])f[i+1] = f[j+1];
    }
}

struct trie
{};

//查找

//struct Node
//{
//    int nVal;
//    Node *pLeft;
//    Node *pRight;
//    
//    Node(int val,Node* left=NULL,Node * right=NULL):nVal(val),pLeft(left),pRight(right){}; //构造
//};
//// 析构
//void DestroyTree(Node *pRoot)
//{
//    if (pRoot==NULL)
//        return;
//    
//    Node* pLeft=pRoot->pLeft;
//    Node* pRight=pRoot->pRight;
//    
//    delete pRoot;
//    pRoot =NULL;
//    
//    DestroyTree(pLeft);
//    DestroyTree(pRight);
//    
//}
//
//
//// 用queue实现的BFS
//void BFS(Node *pRoot)
//{
//    if (pRoot==NULL)
//        return;
//    
//    queue<Node*> Q;
//    
//    Q.push(pRoot);
//    
//    while(!Q.empty())
//    {
//        
//        Node *node = Q.front();
//        
//        cout<<node->nVal<<"->";
//        if (node->pLeft!=NULL)
//        {
//            Q.push(node->pLeft);
//        }
//        
//        if (node->pRight!=NULL)
//        {
//            Q.push(node->pRight);
//        }
//        
//        Q.pop();
//    }
//    
//    cout<<endl;
//}
//
//
//// DFS的递归实现
//void DFS_Recursive(Node* pRoot)
//{
//    if (pRoot==NULL)
//        return;
//    
//    cout<<pRoot->nVal<<" ";
//    
//    if (pRoot->pLeft!=NULL)
//        DFS_Recursive(pRoot->pLeft);
//    
//    
//    if (pRoot->pRight!=NULL)
//        DFS_Recursive(pRoot->pRight);
//    
//}
//
//// DFS的迭代实现版本（stack）
//void DFS_Iterative(Node* pRoot)
//{
//    if (pRoot==NULL)
//        return;
//    
//    stack<Node*> S;
//    S.push(pRoot);
//    
//    while (!S.empty())
//    {
//        Node *node=S.top();
//        cout<<node->nVal<<",";
//        
//        S.pop();
//        
//        if (node->pRight!=NULL)
//        {
//            S.push(node->pRight);
//        }
//        
//        if (node->pLeft!=NULL)
//        {
//            S.push(node->pLeft);
//        }
//        
//    }
//    
//}
//
//
//// 打印树的信息
//void PrintTree(Node* pRoot)
//{
//    if (pRoot==NULL)
//        return;
//    
//    cout<<pRoot->nVal<<" ";
//    
//    if (pRoot->pLeft!=NULL)
//    {
//        PrintTree(pRoot->pLeft);
//    }
//    
//    if (pRoot->pRight!=NULL)
//    {
//        PrintTree(pRoot->pRight);
//    }
//}
//
//void solve3()
//{
//    Node *node1=new Node(4);
//    Node *node2=new Node(5);
//    Node *node3=new Node(6);
//    
//    Node* node4=new Node(2,node1,node2);
//    Node* node5=new Node(3,node3);
//    Node* node6=new Node(1,node4,node5);
//    
//    
//    Node* pRoot = node6;
//    //PrintTree(pRoot);
//    //DFS_Recursive(pRoot);
//    
//    DFS_Iterative(pRoot);
//    DestroyTree(pRoot);
//    
//}


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
#define INF 1e8
const int maxn = 1000 + 5;
int d[maxn];
int dist[maxn][maxn];
bool done[maxn];

void dijksra()
{
    memset(done,0,sizeof(done));
    for(int i = 1;i<=n;i++)d[i] = i == s?0:INF;
    for(int i = 1;i<=n;i++)
    {
        int x,min_dist = INF;
        for(int y = 1;y<=n;y++)
        {
            if(!done[y]&&min_dist>=d[y])
                min_dist = d[x=y];
            done[x] = true;
            for(int y = 1;y<=n;y++)d[y] = min(d[y],d[x]+dist[x][y]);
        }
    }
}


//线段树

const int maxn = 50000 + 5;

int sum[maxn*4];
#define lson i*2 ,l ,m
#define rson i*2+1,m+1,r

void PushUp(int i)
{
    sum[i] = sum[i*2] + sum[i*2+1];
}

void build(int i,int l,int r)
{
    if(l==r)
    {
        scanf("%d",&sum[i]);
        return ;
    }
    int m = (l+r)/2;
    build(lson);
    build(rson);
    PushUp(i);
}

int query(int ql,int qr,int l,int r)
{
    if(ql<=l&&r<=qr)return sum[i];
    int m = (l+r)/2;
    int res = 0;
    if(ql<=m) res += query(ql,qr,lson);
    if(m<qr) res += query(ql,qr,rson);
        return res;
}

void update(int id,int val,int i,int l,int r)
{
    if(l==r)
    {
        sum[i] += val;
        return ;
    }
    int m = (l+r)/2;
    if(id<=m)update(id,val,lson);
    else update(id,val,rson);
    PushUp(i);
}





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



