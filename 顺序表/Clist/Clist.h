#include <iostream>
using namespace std;
#include <stdlib.h>

#define List_MAX 40
//顺序表需要 顺序表结构体 增删查改 初始化函数

typedef int CListtype;

typedef struct CList
{
	CListtype* MyList;
	int size;
} CList, *PCList;

//初始化
PCList InitCList1();

//任意位置插入 列表位置插入
bool SeqListInsert(PCList List, int pos, CListtype item);

//打印顺序表
bool seqListPrint(PCList List);

//任意位置删除 
bool SeqListErase(PCList List, int pos);

//释放
bool DeleteSeqList(PCList List);

//查找
int SeqListFind(PCList List, CListtype item);

//修改
int SeqListModify(PCList List, CListtype pos, CListtype item);