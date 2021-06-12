#include "Stack.h"

int main()
{
	pStack myStark = InitStack();
	push(myStark, 1);
	push(myStark, 2);
	push(myStark, 3);
	push(myStark, 4);
	push(myStark, 5);
	while (empty(myStark))
	{
		cout << top(myStark) << endl;
		pop(myStark);
	}


	system("pause");
	return 0;
}