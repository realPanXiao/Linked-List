#include <stdio.h>
#include <stdlib.h>
typedef struct LNode//构造结构体
{
	int data;//数据
	struct LNode *next;//指针指向后继
}LNode,*LinkList;//结构体类型名称,结构体指针名称
LinkList creat()//构造函数
{
	int i;//循环变量
	LinkList pnew;//用于指向新构造的节点
	LinkList phead=(LinkList)malloc(sizeof(LNode));//头指针,指向第一个节点
	LinkList ptail=phead;//尾指针,暂时指向第一个节点
	phead->next=NULL;//第一个节点后继为空
	phead->data=0;//第一个节点数据为零
	for(i=1;i<10;i++)//连续构造九次节点
	{
		pnew=(LinkList)malloc(sizeof(LNode));
		ptail->next=pnew;//原节点指向新节点
		ptail=pnew;//活动节点往后移
		ptail->data=i;
	}
	ptail->next=NULL;//最后的节点指向空
	return phead;//返回头结点
}
LinkList findlast(LinkList p)//找到最后一个节点函数,参数为头指针
{
	LinkList tail=p;//尾节点
	while(tail->next!=NULL)//结束条件为后继为空,找到最后的节点
	{
		tail=tail->next;
	}
	return tail;//返回尾节点
}
LinkList newfirst(LinkList p,int a)//在第一个元素前插入新数据,参数为头指针,新数据
{
	LinkList pnew=(LinkList)malloc(sizeof(LNode));//创建一个新空间
	pnew->data=a;
	pnew->next=p;//新节点指向原第一个节点
	p=pnew;//更新头指针
	return p;
}
LinkList newlast(LinkList p,int a)//在最后一个元素后插入新数据,参数为尾指针,新数据
{
	LinkList pnew=(LinkList)malloc(sizeof(LNode));
	pnew->data=a;
	pnew->next=NULL;//新节点指向空
	p->next=pnew;//尾指针后继为新节点
	p=pnew;//更新尾节点
	return p;
}
LinkList deletefirst(LinkList p)//删除第一个节点,参数为头指针
{
	p=p->next;//更新头结点
	return p;
}
LinkList deletelast(LinkList p)//删除最后一个节点,参数为头指针
{
	LinkList t=p;
	while(t->next->next!=NULL)//结束条件是到达倒数第二个节点
	{
		t=t->next;//满足条件,往后推进
	}
	t->next=NULL;//倒数第二个节点指向空,代表新的尾节点
	return t;
}
int search(LinkList p,int a)//查找是否含特定元素,参数为头指针,特定元素数据
{
	int i=0;//代表特定元素数量
	LinkList s=p;
	do
	{
		if(s->data==a)//判断数据是否相同
		{
			i++;//如果满足条件,则数量加一
		}
		s=s->next;
	}
	while(s!=NULL);//遍历整个链表,到尾节点结束
	return i;//返回特定元素数量
}
LinkList pushfront(LinkList p,int a,int b)//在表中特定元素(默认为一个)之前插入数据,参数为头指针,特定元素数据,新数据
{
	LinkList s=p;
	LinkList pnew;
	if(s->data==a)//判断第一个元素数据是否相同
	{
		p=newfirst(p,b);//满足条件,则用已有函数在第一个元素前添加
	}
	else
	{
		while(s->next->data!=a)//结束条件为下一个元素的数据与特定数据相等
		{
			s=s->next;
		}
		pnew=(LinkList)malloc(sizeof(LNode));
		pnew->next=s->next;//新节点的后继等于特定节点
		pnew->data=b;
		s->next=pnew;//特定节点的前驱的后继为新节点
	}
	return p;//返回头指针
}
LinkList pushbehind(LinkList p,int a,int b)//在特定元素(默认一个)之后插入新数据,参数为头指针,特定元素数据,新数据
{
	LinkList s=p;
	LinkList pnew=(LinkList)malloc(sizeof(LNode));
	while(s->data!=a)//结束条件为某节点数据与特定数据相等
	{
		s=s->next;
	}
	if(s->next==NULL)//如果特定节点为尾节点
	{
		s->next=pnew;//尾节点后继为新节点
		pnew->next=NULL;//新节点后继为空
		pnew->data=b;
	}
	else//特定节点不是尾节点
	{
		pnew->next=s->next;//新节点后继为特定节点后继
		pnew->data=b;
		s->next=pnew;//特定节点的后继为新节点
	}
	return p;
}
LinkList deleteone(LinkList p,int a)//删除某个特定元素(默认为一个),参数为头指针,特定数据
{
	LinkList s=p;
	if(s->data==a)//判断第一个节点数据是否符合
	{
		p=p->next;//满足条件,头指针更新
		s=p;
	}
	else//第一个节点不是特定元素
	{
		while(s->next->data!=a)//结束条件为下一个节点数据符合
		{
			s=s->next;//遍历整个链表
		}
		s->next=s->next->next;//符合节点的后继指针指向原后继的后继
	}
	return p;
}
void traverse(LinkList p)//遍历整个元素,参数为头指针
{
	LinkList i=p;
	while(i->next!=NULL)//结束条件为指向最后一个节点
	{
		printf("%d ",i->data);//输出数据
		i=i->next;//遍历整个链表
	}
	printf("%d\n",i->data);//最后一个节点没有输出,补全
}
LinkList fan(LinkList p)//反转链表,参数为头指针
{
	LinkList k;
	LinkList s=p;
	LinkList t;
	int n=0;//储存节点个数
	int i;int j;//循环变量
	while(s->next!=NULL)//结束条件为最后一个节点
	{
		n++;
		s=s->next;
	}
	n++;//补充没有算入得最后一个节点
	t=s;
	for(i=n-2;i>0;i--)//循环n-2次
	{
		k=p;
		for(j=0;j<i;j++)//从头节点循环至当前节点的上一个
		{
			k=k->next;
		}
		s->next=k;//当前节点后继重置
		s=s->next;//更新循环指针
	}
	s->next=p;//第二个节点指向头结点
	p->next=NULL;//头结点后继指向空,代表新的为节点
	p=t;//头指针反转
	return p;
}
int main()
{
	char n;//接收字符,判断要执行的命令
	int x;int y;//接收节点数据
	LinkList h;//代表头指针
	LinkList t;//代表尾指针
	scanf("%c",&n);
	while(n!='z')//结束条件为'z'
	{
		if(n=='a')//条件成立,执行构造
		{
			h=creat();
			t=findlast(h);//找到尾节点,给尾指针赋值
		}
		if(n=='b')//执行在第一个元素前插入数据
		{
			scanf("%d",&x);//接收新数据
			h=newfirst(h,x);
		}
		if(n=='B')//执行在最后一个元素之后插入新数据
		{
			scanf("%d",&x);//接收新数据
			t=newlast(t,x);
		}
		if(n=='c')//执行删除第一个元素
		{
			h=deletefirst(h);
		}
		if(n=='C')//执行删除最后一个元素
		{
			t=deletelast(h);
		}
		if(n=='d')//执行查找表中是否含有特定元素
		{
			scanf("%d",&x);//接收特定元素
			if(search(h,x)==0)//判断返回特定元素数量是否为零
				printf("no\n");//代表没有
			else
				printf("yes\n");//代表有
		}
		if(n=='e')//执行向表中特定元素之前插入数据
		{
			scanf("%d",&x);//接收特定元素数据
			scanf("%d",&y);//接收新节点数据
			h=pushfront(h,x,y);
		}
		if(n=='E')//执行向表中特定元素之后插入数据
		{
			scanf("%d",&x);//接收特定元素数据
			scanf("%d",&y);//接收新节点数据
			h=pushbehind(h,x,y);
		}
		if(n=='f')//执行删除表中特定元素
		{
			scanf("%d",&x);//接收特定元素数据
			h=deleteone(h,x);
		}
		if(n=='g')//执行遍历整个链表
		{
			traverse(h);
		}
		if(n=='h')//整形反转链表
		{
			h=fan(h);
		}
		getchar();//吸收上一个回车
		scanf("%c",&n);//接收命令
	}
}
