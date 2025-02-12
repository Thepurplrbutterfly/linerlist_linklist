#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"

linklink list_create()
{
linklink H;
H=(linklink)malloc(sizeof(linklist));
if(H==NULL)
{
printf("the memory assigning failed!\n");
return H;
}
H->data=0;
H->next=NULL;
return H;
}

int list_bottominsert(linklink H, data_t value)
{
//构造新结点
linklink p; //为链表创建一个新结点(结构体)
  if((p=(linklink)malloc(sizeof(linklist)))==NULL) //判断内存动态分配是否成功
    { 
      printf("the memory assigning failed!\n");
      return -1;
    }
  p->data=value; //新建结点初始化
  p->next=NULL;

//在链表中插入新建结点前，需寻找尾结点
linklink q; //新建一个用于寻找尾结点的指针
q=H; //将该指针初始化为H
  while(q->next!=NULL) //寻找尾结点，尾结点的特征是结构体指针元素指向的是NULL，以此作为判断条件
  {                    //对结点进行遍历，直到找到尾结点
  q=q->next;
  }
  q->next=p;//找到尾结点，进行插值
return 0;
}

int list_showall(linklink H)
{
linklink q=H;
   while(q->next != NULL)
     {
        printf("%d ", q->next->data);
        q=q->next;
     }
putchar('\n');
return 0;
}

/*寻找结点位置函数*/
linklink list_locate(linklink H, int pos)
{
    linklink q = H;
	int i=-1;
	if(H==NULL)
	{
       printf("the memory assigning failed!\n");
	   return NULL;
	}
	if(pos==-1)
	{
       return H;
	}
	if(pos<-1)
	{
      printf("the pos is illegal!\n");
      return NULL;
	}
    while(i<pos)
	{
       q=q->next;
		if(q==NULL)
	   {
         printf("the pos is illegal!\n");
	     return NULL;
	   }
      i++;
	}
return q;
}

/*中间插入函数*/
int list_insert(linklink H, data_t value, int pos)
{
   if(H==NULL)
   {
      printf("the memory assigning failed!\n");
	  return -1;
   }
  linklink q = list_locate(H, pos-1);
  linklink p = (linklink)malloc(sizeof(linklist));
  if(p == NULL)
  {
     printf("the new node build  failed!\n");
	 return -1;
  }
  p->data = value;
  p->next = NULL;
  p->next=q->next;
  q->next=p;
  return 0;
}

/*删除节点函数*/
int list_delete(linklink H, int pos)
{
	if(H==NULL)
	{
       printf("the memory assigning failed!\n");
	   return -1;
	}
    linklink p = list_locate(H, pos-1);
    linklink q = p->next;
    p->next=q->next; //p->next=p->next->next;
    free(q);
    q=NULL;
    return 0;
}

/*释放整个链表函数-删除所有结点*/
int list_freelist(linklink H)
{
   if(H==NULL)
   {
      printf("the memory assigning failed!\n");
      return -1;
   }
  linklink p = H;
  printf("free:\n");
  while(H!=NULL)
  {
     p=H;
	 printf("%d ", p->data);
	 H=H->next;
	 free(p);
  }
  puts("");
  return 0;
}

/*链表反转函数*/
int list_inverse(linklink H)
{
//判断头结点是否存在
   if(H==NULL)
   {
     printf("the memory assigning failed!\n");
	 return -1;
   }
//判断是否仅存在头结点或只存在一个结点，这两种情况无需反转
   if(H->next==NULL||H->next->next==NULL)
   {
     printf("no need to inverse!\n");
	 return -1;
   }
//超过一个结点即需要反转的情况
   linklink p=H->next->next;
   linklink q;
   H->next->next==NULL;
   while(p!=NULL)
   {
     q=p;
	 p=p->next;
	 q->next=H->next;
	 H->next=q;
   }
   return 0;
}

/*求相邻两个节点值之和最大时头个节点的地址，并返回和*/
linklink list_summost(linklink H)
{
//判断头节点是否存在
if(H==NULL)
{
printf("the memory assigning failed!\n");
return NULL;
}
//判断节点个数是否超过两个
if(H->next->next==NULL||H->next->next->next==NULL)
{
printf("the node is less than 3!\n");
return H->next;
}
//当节点超过三个时
linklink p=H->next;
linklink q=H->next->next;
linklink r=p;
data_t sum=p->data+q->data;
while(q->next!=NULL)
   {
     q=q->next;
	 p=p->next;
	 if(sum<p->data+q->data)
	 {
       sum=p->data+q->data;
	   r=p;
	 }
   }
return r;
}

/*链表合并排序函数-按data从小到大*/
int list_mergeorder(linklink H1, linklink H2)
{
//判断头节点的内存是否分配成功
   if(H1==NULL&&H2==NULL)
   {
      printf("the memory assigning failing!\n");
      return -1;
   }
//判断两个链表中的节点数是否满足能够合并的条件
   if(H1->next==NULL||H2->next==NULL)
   {
     printf("the node number fails to satisfy the merging condition!\n");
	 return -1;
   }
//满足合并条件的情况
  linklink p=H1->next;
  linklink q=H2->next;
  linklink r=H1;
  H1->next==NULL;
  H2->next==NULL;
  while(p!=NULL&&q!=NULL)
  {
	if(p->next<=q->next)
	{
      r->next=p;
	  p=p->next;
	  r=r->next;
	  r->next=NULL;
	}
	else{
     r->next=q;
	 q=q->next;
	 r=r->next;
	 r->next==NULL;
	}
  }
  if(p==NULL)
  {
    r->next=q;
  }
  else{
    r->next=p;
  }
  return 0;
}

/*链表从小到大排序函数*/
int list_order(linklink H)
{
//判断头节点的内存分配是否成功
   if(H==NULL)
   {
      printf("the memory assigning fails!\n");
	  return -1;
   }
//判断链表是否为空以及其中节点个数是否大于1
  if(H->next==NULL||H->next->next==NULL)
  {
      printf("there is no need to order!\n");
	  return -1;
  }
//链表中节点个数大于1
  linklink p = H->next;
  linklink q = p->next;
  int i;
  while(p->next!=NULL)
  {
	q=p->next;
    while(q!=NULL)
	{
       if(q->data<p->data)
	   {
          i=q->data;
		  q->data=p->data;
		  p->data=i;
	   }
	   else{}
       q=q->next;
	}
	p=p->next;
  }
  return 0;
}

