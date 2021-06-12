#include "stack.h"

int main()
{
	pStack myStack = InitStack();
	Push(myStack, 1);
	Push(myStack, 2);
	Push(myStack, 3);
	Push(myStack, 4);
	Push(myStack, 5);
	while (empty(myStack))
	{
		cout << Top(myStack) << endl;;
		Pop(myStack);
	}
	system("pause");
	return 0;
}