#include "list.h"

int main()
{
	plistNode S = listInit();
	ListPushFront(S, 1);
	ListPushFront(S, 2);
	ListPushFront(S, 3);
	ListPushFront(S, 4);
	listPrintf(S);
	ListPopBack(S);
	listPrintf(S);
	system("pause");
	return 0;
}