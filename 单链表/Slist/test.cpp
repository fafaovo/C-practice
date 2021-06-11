#include "Slist.h"

int main()
{
	pSList S = NULL;
	SListAppointPushBack(&S, 1, 0);
	SListAppointPushBack(&S, 2, 1);
	SListAppointPushBack(&S, 3, 2);
	SListAppointPushBack(&S, 4, 3);
	SListAppointPushBack(&S, 5, 4);
	SListPrint(S);

	SListAppointPopBack(&S, 4);
	SListAppointPopBack(&S, 3);
	SListAppointPopBack(&S, 2);
	SListAppointPopBack(&S, 1);
	SListAppointPopBack(&S, 0);
	SListPrint(S);
	system("pause");
	return 0;
}