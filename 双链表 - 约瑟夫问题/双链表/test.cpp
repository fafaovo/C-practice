#include "list.h"

int main()
{
	plistNode S = listInit();
	for (int i = 1; i < 9; i++)
	{
		ListPushFront(S, i);
	}
	listPrintf(S);
	cout << sizeClist(S) << endl;
	cout << "Լɪ���������õ�" << Josephus(S, 4) << endl;
	system("pause");
	return 0;
}