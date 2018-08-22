#include "iostream"
#include "zlinklist.h"
#include "time.h"

using namespace std;

void main()
{
	zlinklist	head;
	zlinknode	*p = NULL;
	int			i,data;
	
	srand(time(NULL));



	zlinklist_init(head);
	
	for(i = 0; i < 5; i++)
		zlinklist_add(head, rand()%10);

	zlinklist_print(head,"init state");
//	zlinklist_sortBubble(head);
	zlinklist_sortInsert(head);
	zlinklist_print(head,"after bubble sort");
	
	zlinklist_reverse(head);
	zlinklist_print(head,"after reverse");

}