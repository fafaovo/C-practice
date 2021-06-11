#include "Clist.h"

int main()
{
	PCList MyCList = InitCList1();
	SeqListInsert(MyCList, 0, 0);
	SeqListInsert(MyCList, 0, 1);
	SeqListInsert(MyCList, 0, 2);
	SeqListInsert(MyCList, 0, 3);
	SeqListInsert(MyCList, 0, 4);
	SeqListInsert(MyCList, 0, 5);
	SeqListInsert(MyCList, 0, 6);
	seqListPrint(MyCList);
	int cur = SeqListFind(MyCList, 6);
	cout << MyCList->MyList[cur] << endl;
	SeqListModify(MyCList, 4, 1);
	seqListPrint(MyCList);
	SeqListErase(MyCList,0);
	SeqListErase(MyCList, 0);
	SeqListErase(MyCList, 0);
	SeqListErase(MyCList, 0);
	seqListPrint(MyCList);
	system("pause");
	return 0;
}