#include "zlinklist.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

/*
* module global variable
*/


int zlinklist_init(zlinklist &L)
{
	L = (zlinklist)malloc(sizeof(zlinknode));
	if(L == NULL)
		return ZLINKLIST_ERROR_NOSPACE;
	//data
	L->data = 0;
	//next
	L->next = NULL;

	return ZLINKLIST_OK;
}

int zlinklist_add(zlinklist &L, int src)
{
	zlinklist	p = (zlinklist)malloc(sizeof(zlinknode));
	zlinklist	tail = NULL;

	if(p == NULL)
		return ZLINKLIST_ERROR_NOSPACE;
	//last
	tail = L;
	while(tail->next != NULL)
		tail = tail->next;
	//produce new nod
	p->data = src;
	p->next = NULL;
	//add to link
	tail->next = p;
	
	//head->data used to save length
	L->data += 1;

	return ZLINKLIST_OK;
}

zlinklist zlinklist_locate(zlinklist &L,int i,int &des)
{
	int			j;
	zlinklist	p = L;				//p是被找节点的前一个节点，因此这里为头结点
	
	if(p == NULL)
		return NULL;
	//locate
	for(j = 0; j < i && p->next != NULL; j++, p = p->next);
	if(p->next == NULL)
	{
		des = ZLINKLIST_NOT_FIND;
		return NULL;
	}
	p = p->next;
	des = p->data;

	return p;
}

zlinklist zlinklist_find(zlinklist &L,int keyVar)
{
	int			j;
	zlinklist	p = L->next;
	
	//
	for(j = 0; p != NULL; p = p->next)
	{
		if(p->data == keyVar)
			return p;
	}
	return NULL;
}
int zlinklist_delete(zlinklist &L,int i,int &data)
{
	int			j;
	zlinklist	p1 = L,p2 = L->next;	//p1代表i的前一个节点，p2为p

	//locate
	for(j = 0; j < i && p1->next != NULL; j++, p1 = p1->next);
	if(p1->next == NULL)
	{
		data = ZLINKLIST_NOT_FIND;
		return ZLINKLIST_DEL_FAILED;
	}
	//
	p2 = p1->next;
	p1->next = p2->next;

	L->data -= 1;
	free(p2);

	return ZLINKLIST_OK;
}

int zlinklist_delete(zlinklist &L, zlinklist &des,int &data)
{
	zlinklist p = L;
	
	if(p == NULL)
		return ZLINKLIST_FAIL;

	while(p->next != des && p->next != NULL)
		p = p->next;
	if(p->next != des)
		return ZLINKLIST_FAIL;
	p->next = des->next;	
	data = des->data;

	free(des);
	L->data -= 1;
	return 0;
}

void zlinklist_print(zlinklist &L,char list_head[])
{
	zlinklist	p = L;
	int			i = 0;
	
	cout << "\r\n--------- List:" << list_head << "---------\r\n";
	if(p == NULL)
		cout << "list is null\r\n";
	else
		p = p->next;
	while(p)
	{
		/*
		格式化输入出%
			'-':左对齐
			'3':占位
			'd':输出的数据类型
			'0':占位补零
		*/
		printf("No.%-3d: adress:%08x data:%d \r\n",i,p,p->data);

		i += 1;
		p = p->next;
	}
}

int zlinklist_length(zlinklist &L)
{
	int			i = 0;
	zlinklist	p = L->next;

	while(p)
	{
		p = p->next;
		i++;
	}

	return i;
}

void zlinklist_sortBubble(zlinklist &L,int keyVar,int s2b)
{
	int			i,j,key1,key2,mov_flag,exchang_flag;
	int			n = zlinklist_length(L);
	zlinklist	p1,p2,p1pre;
	
	//cout << "length:" << n;
	mov_flag = 1;//extra var for ending if sort is done
	for(i = 0; i < n -1 && mov_flag == 1; i++)
	{
		p1pre = L;
		p1 = p1pre->next;
		p2 = (p1 != NULL) ? p1->next : NULL;

		mov_flag = 0;//extra var for ending if sort is done
		j = 0;
		while(p2 != NULL && j < n - i - 1)
		{
			//get key value
			switch(keyVar)
			{
			case 0:key1 = p1->data;key2 = p2->data;break;
			case 1:break;
			case 2:break;
			default:break;
			}
			//exchange
			exchang_flag = (s2b == 1) ? (key1 > key2) : (key1 < key2);
			if(exchang_flag)
			{
				/*
				*	from:	(0)->(1)->(2)->(3)
				*	to:		(0)->(2)->(1)->(3)
				*/
				/*	(0)->(2)	*/
				p1pre->next = p2;
				/*	(1)->(3)	*/
				p1->next = p2->next;
				/*	(2)->(1)	*/
				p2->next = p1;
				
				//move flag
				mov_flag = 1;
				//move 2 step,ignore (2)->(1),jump to (1)->(3);
				p1pre = p2;
				p1 = p2->next;
				p2 = p2->next->next;
			}
			else
			{
				//move 1 step
				p1pre = p1;
				p1 = p2;
				p2 = p2->next;
			}
			j++;
		}
	}
}

void zlinklist_sortInsert(zlinklist &L,int keyVar,int s2b)
{
	int			key1,key2;
	int			n = zlinklist_length(L);
	zlinklist	pre,p,tail,test;
	
	tail = L->next;
	test = tail->next;
	while(tail && test)
	{		
		p = L->next;
		pre = L;

		while(test)
		{
			//get key value
			switch(keyVar)
			{
			case 0:key1 = p->data;key2 = test->data;break;
			case 1:break;
			case 2:break;
			default:break;
			}
			//printf("%d %d\n",key1,key2);
			//insert
			if(key1 > key2)
			{
				pre->next = test;
				tail->next = test->next;
				test->next = p;
				break;
			}
			else if(p == tail)
			{
				tail = test;
				break;
			}
			//next
			pre = p;
			p = p->next;
		}
		test = tail->next;
	}
}

void zlinklist_reverse(zlinklist &L)
{
	zlinklist p,tail,tailpre;

	tailpre = NULL;
	tail = L->next;

	while(tail)
	{
		p = tail->next;
		tail->next = tailpre;
		//next
		tailpre = tail;
		tail = p;
	}
	//update first;
	L->next = tailpre;
}

void zlinklist_destory(zlinklist &L)
{
	zlinklist p = L,tail;

	while(p)
	{
		tail = p;
		p = p->next;
		free(tail);
	}
	L = NULL;
}