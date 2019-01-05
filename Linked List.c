#include <stdio.h>
#include <stdlib.h>
typedef struct LNode//����ṹ��
{
	int data;//����
	struct LNode *next;//ָ��ָ����
}LNode,*LinkList;//�ṹ����������,�ṹ��ָ������
LinkList creat()//���캯��
{
	int i;//ѭ������
	LinkList pnew;//����ָ���¹���Ľڵ�
	LinkList phead=(LinkList)malloc(sizeof(LNode));//ͷָ��,ָ���һ���ڵ�
	LinkList ptail=phead;//βָ��,��ʱָ���һ���ڵ�
	phead->next=NULL;//��һ���ڵ���Ϊ��
	phead->data=0;//��һ���ڵ�����Ϊ��
	for(i=1;i<10;i++)//��������Ŵνڵ�
	{
		pnew=(LinkList)malloc(sizeof(LNode));
		ptail->next=pnew;//ԭ�ڵ�ָ���½ڵ�
		ptail=pnew;//��ڵ�������
		ptail->data=i;
	}
	ptail->next=NULL;//���Ľڵ�ָ���
	return phead;//����ͷ���
}
LinkList findlast(LinkList p)//�ҵ����һ���ڵ㺯��,����Ϊͷָ��
{
	LinkList tail=p;//β�ڵ�
	while(tail->next!=NULL)//��������Ϊ���Ϊ��,�ҵ����Ľڵ�
	{
		tail=tail->next;
	}
	return tail;//����β�ڵ�
}
LinkList newfirst(LinkList p,int a)//�ڵ�һ��Ԫ��ǰ����������,����Ϊͷָ��,������
{
	LinkList pnew=(LinkList)malloc(sizeof(LNode));//����һ���¿ռ�
	pnew->data=a;
	pnew->next=p;//�½ڵ�ָ��ԭ��һ���ڵ�
	p=pnew;//����ͷָ��
	return p;
}
LinkList newlast(LinkList p,int a)//�����һ��Ԫ�غ����������,����Ϊβָ��,������
{
	LinkList pnew=(LinkList)malloc(sizeof(LNode));
	pnew->data=a;
	pnew->next=NULL;//�½ڵ�ָ���
	p->next=pnew;//βָ����Ϊ�½ڵ�
	p=pnew;//����β�ڵ�
	return p;
}
LinkList deletefirst(LinkList p)//ɾ����һ���ڵ�,����Ϊͷָ��
{
	p=p->next;//����ͷ���
	return p;
}
LinkList deletelast(LinkList p)//ɾ�����һ���ڵ�,����Ϊͷָ��
{
	LinkList t=p;
	while(t->next->next!=NULL)//���������ǵ��ﵹ���ڶ����ڵ�
	{
		t=t->next;//��������,�����ƽ�
	}
	t->next=NULL;//�����ڶ����ڵ�ָ���,�����µ�β�ڵ�
	return t;
}
int search(LinkList p,int a)//�����Ƿ��ض�Ԫ��,����Ϊͷָ��,�ض�Ԫ������
{
	int i=0;//�����ض�Ԫ������
	LinkList s=p;
	do
	{
		if(s->data==a)//�ж������Ƿ���ͬ
		{
			i++;//�����������,��������һ
		}
		s=s->next;
	}
	while(s!=NULL);//������������,��β�ڵ����
	return i;//�����ض�Ԫ������
}
LinkList pushfront(LinkList p,int a,int b)//�ڱ����ض�Ԫ��(Ĭ��Ϊһ��)֮ǰ��������,����Ϊͷָ��,�ض�Ԫ������,������
{
	LinkList s=p;
	LinkList pnew;
	if(s->data==a)//�жϵ�һ��Ԫ�������Ƿ���ͬ
	{
		p=newfirst(p,b);//��������,�������к����ڵ�һ��Ԫ��ǰ���
	}
	else
	{
		while(s->next->data!=a)//��������Ϊ��һ��Ԫ�ص��������ض��������
		{
			s=s->next;
		}
		pnew=(LinkList)malloc(sizeof(LNode));
		pnew->next=s->next;//�½ڵ�ĺ�̵����ض��ڵ�
		pnew->data=b;
		s->next=pnew;//�ض��ڵ��ǰ���ĺ��Ϊ�½ڵ�
	}
	return p;//����ͷָ��
}
LinkList pushbehind(LinkList p,int a,int b)//���ض�Ԫ��(Ĭ��һ��)֮�����������,����Ϊͷָ��,�ض�Ԫ������,������
{
	LinkList s=p;
	LinkList pnew=(LinkList)malloc(sizeof(LNode));
	while(s->data!=a)//��������Ϊĳ�ڵ��������ض��������
	{
		s=s->next;
	}
	if(s->next==NULL)//����ض��ڵ�Ϊβ�ڵ�
	{
		s->next=pnew;//β�ڵ���Ϊ�½ڵ�
		pnew->next=NULL;//�½ڵ���Ϊ��
		pnew->data=b;
	}
	else//�ض��ڵ㲻��β�ڵ�
	{
		pnew->next=s->next;//�½ڵ���Ϊ�ض��ڵ���
		pnew->data=b;
		s->next=pnew;//�ض��ڵ�ĺ��Ϊ�½ڵ�
	}
	return p;
}
LinkList deleteone(LinkList p,int a)//ɾ��ĳ���ض�Ԫ��(Ĭ��Ϊһ��),����Ϊͷָ��,�ض�����
{
	LinkList s=p;
	if(s->data==a)//�жϵ�һ���ڵ������Ƿ����
	{
		p=p->next;//��������,ͷָ�����
		s=p;
	}
	else//��һ���ڵ㲻���ض�Ԫ��
	{
		while(s->next->data!=a)//��������Ϊ��һ���ڵ����ݷ���
		{
			s=s->next;//������������
		}
		s->next=s->next->next;//���Ͻڵ�ĺ��ָ��ָ��ԭ��̵ĺ��
	}
	return p;
}
void traverse(LinkList p)//��������Ԫ��,����Ϊͷָ��
{
	LinkList i=p;
	while(i->next!=NULL)//��������Ϊָ�����һ���ڵ�
	{
		printf("%d ",i->data);//�������
		i=i->next;//������������
	}
	printf("%d\n",i->data);//���һ���ڵ�û�����,��ȫ
}
LinkList fan(LinkList p)//��ת����,����Ϊͷָ��
{
	LinkList k;
	LinkList s=p;
	LinkList t;
	int n=0;//����ڵ����
	int i;int j;//ѭ������
	while(s->next!=NULL)//��������Ϊ���һ���ڵ�
	{
		n++;
		s=s->next;
	}
	n++;//����û����������һ���ڵ�
	t=s;
	for(i=n-2;i>0;i--)//ѭ��n-2��
	{
		k=p;
		for(j=0;j<i;j++)//��ͷ�ڵ�ѭ������ǰ�ڵ����һ��
		{
			k=k->next;
		}
		s->next=k;//��ǰ�ڵ�������
		s=s->next;//����ѭ��ָ��
	}
	s->next=p;//�ڶ����ڵ�ָ��ͷ���
	p->next=NULL;//ͷ�����ָ���,�����µ�Ϊ�ڵ�
	p=t;//ͷָ�뷴ת
	return p;
}
int main()
{
	char n;//�����ַ�,�ж�Ҫִ�е�����
	int x;int y;//���սڵ�����
	LinkList h;//����ͷָ��
	LinkList t;//����βָ��
	scanf("%c",&n);
	while(n!='z')//��������Ϊ'z'
	{
		if(n=='a')//��������,ִ�й���
		{
			h=creat();
			t=findlast(h);//�ҵ�β�ڵ�,��βָ�븳ֵ
		}
		if(n=='b')//ִ���ڵ�һ��Ԫ��ǰ��������
		{
			scanf("%d",&x);//����������
			h=newfirst(h,x);
		}
		if(n=='B')//ִ�������һ��Ԫ��֮�����������
		{
			scanf("%d",&x);//����������
			t=newlast(t,x);
		}
		if(n=='c')//ִ��ɾ����һ��Ԫ��
		{
			h=deletefirst(h);
		}
		if(n=='C')//ִ��ɾ�����һ��Ԫ��
		{
			t=deletelast(h);
		}
		if(n=='d')//ִ�в��ұ����Ƿ����ض�Ԫ��
		{
			scanf("%d",&x);//�����ض�Ԫ��
			if(search(h,x)==0)//�жϷ����ض�Ԫ�������Ƿ�Ϊ��
				printf("no\n");//����û��
			else
				printf("yes\n");//������
		}
		if(n=='e')//ִ��������ض�Ԫ��֮ǰ��������
		{
			scanf("%d",&x);//�����ض�Ԫ������
			scanf("%d",&y);//�����½ڵ�����
			h=pushfront(h,x,y);
		}
		if(n=='E')//ִ��������ض�Ԫ��֮���������
		{
			scanf("%d",&x);//�����ض�Ԫ������
			scanf("%d",&y);//�����½ڵ�����
			h=pushbehind(h,x,y);
		}
		if(n=='f')//ִ��ɾ�������ض�Ԫ��
		{
			scanf("%d",&x);//�����ض�Ԫ������
			h=deleteone(h,x);
		}
		if(n=='g')//ִ�б�����������
		{
			traverse(h);
		}
		if(n=='h')//���η�ת����
		{
			h=fan(h);
		}
		getchar();//������һ���س�
		scanf("%c",&n);//��������
	}
}
