#include "Queue.h"

int main()
{
	pQueue myQueue = InitQueue();
	push(myQueue, 1);
	push(myQueue, 2);
	push(myQueue, 3);
	push(myQueue, 4);
	push(myQueue, 5);
	while (empty(myQueue))
	{
		cout << top(myQueue) << endl;
		pop(myQueue);
	}

	system("pause");
	return 0;
}