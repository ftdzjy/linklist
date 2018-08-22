/*
 * File      : zlinklist.h
 * This file is the head file of linear list realization by link list
 * we should know that this code didnt code for multi thread project.
 *
 * Change Logs:
 * Date           Author       	Notes
 * 2018-08-06     zjy      		first version
 * 2018-08-17     zjy      		realize reverse function & add description @desc in function descript
 */

#ifndef __ZLINKLIST_H
#define __ZLINKLIST_H

#define ZLINKLIST_OK						0
#define ZLINKLIST_ERROR_NOSPACE				-1
#define ZLINKLIST_NOT_FIND					-2
#define ZLINKLIST_DEL_FAILED				-3
#define ZLINKLIST_FAIL						-4
typedef struct _zlinklist
{
	int						data;
	struct _zlinklist		*next;
}zlinknode,*zlinklist;

/*
@desc	为链表表头指针分配一个表头实体
@para	L: 				链表头指针的引用，引用的概念实际上就是，例如一个变量a，这个变量的地址是0x0880，b是a的引用，说明b的地址也是0x
						0880，估计内部实现通过一个指针来实现（该指针指向地址或者说指针类型），假设为c（* *c），这个变量的值是0x0880。
						通过打印地址也可以发现a和b的地址一样。
@ret	执行结果
*/
int zlinklist_init(zlinklist &L);
/*
@desc	删除一个链表，释放所占用的空间，包括表头实体
@para 	L:				链表头指针的引用
@ret	执行结果
*/
void zlinklist_destory(zlinklist &L);
/*
@desc	在链表L的尾巴添加一个节点
@para 	L:				链表头指针的引用
@para	src:			被添加到链表的数据
@ret	执行结果
*/
int zlinklist_add(zlinklist &L, int src);
/*
@desc	定位链表中的第i个节点
@para 	L:				链表头指针的引用
@para	i:				需要寻找的第i个节点
@para	des:			返回第i个节点的数据，从第0个节点开始
@ret	返回第i个节点
*/
zlinklist zlinklist_locate(zlinklist &L,int i,int &des);
/*
@desc	删除第i个节点
@para 	L:				链表头指针的引用
@para	i:				待删除的第i个节点
@para	des:			返回第i个节点的数据，从第0个节点开始
@ret	执行结果
*/
int zlinklist_delete(zlinklist &L,int i,int &data);
/*
@desc	删除第i个节点
@para 	L:				链表头指针的引用
@para	des:			待删除的结点
@ret	执行结果
*/
int zlinklist_delete(zlinklist &L, zlinklist &des, int &data);

/*
@desc	打印链表，包括每个节点的内存首地址及其数据，打印数据考虑由用户自行实现（使用vector?）
@para 	L:				链表头指针的引用
@para 	list_head:		链表标题
@ret	void
*/
void zlinklist_print(zlinklist &L,char list_head[]);
/*
@desc	链表的插入排序
@para 	L:				链表头指针的引用
@para 	keyVar:			关键字序号（例如第一个关键字为0，第二个为1）
@para 	s2b:			由小到大的排序
@ret	void
*/
void zlinklist_sortInsertion(zlinklist &L,int keyVar = 0,int s2b = 1);
/*
@desc	链表的冒泡排序，该算法要点是两两比较，假设从小到大排序，则大的沉底，每进行一次，当前最大的数都排好序
@para 	L:				链表头指针的引用
@para 	keyVar:			关键字序号（例如第一个关键字为0，第二个为1）
@para 	s2b:			由小到大的排序
@ret	void
*/
void zlinklist_sortBubble(zlinklist &L,int keyVar = 0,int s2b = 1);
/*
@desc	链表反转
@para 	L:				链表头指针的引用
@ret	void
*/
void zlinklist_reverse(zlinklist &L);
/*
@desc	链表的插入排序，该算法要点是假设前k个已经排好序，用第k+1个节点去和排好序的子链表比较，选择合适的位置
						插入，包括在子链表内部插入和不动（追加在子链表的尾部）
@para 	L:				链表头指针的引用
@para 	keyVar:			关键字序号（例如第一个关键字为0，第二个为1）
@para 	s2b:			由小到大的排序
@ret	void
*/
void zlinklist_sortInsert(zlinklist &L,int keyVar = 0,int s2b = 1);
/*
@desc	查找
@para 	L:				链表头指针的引用
@para 	keyVar:			关键值
@ret	zlinklist:	该节点的内存地址
*/
zlinklist zlinklist_find(zlinklist &L,int keyVar);



#endif