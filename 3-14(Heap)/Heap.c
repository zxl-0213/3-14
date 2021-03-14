#include"Heap.h"


void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}



void HeapInit(Heap* hp, int* a, int n)
{
	hp->a = (HDataType*)malloc(sizeof(HDataType) * n);
	if (hp->a == NULL)
	{
		exit(-1);
	}
	memcpy(hp->a, a, sizeof(HDataType) * n);
	hp->size = n;
	hp->capacity = n;

	//½¨¶Ñ
	for (int root = (n - 2) / 2; root >= 0; root--)
	{
		AdJustDown(hp->a, hp->size, root);
	}
}

void AdJustDown(HDataType* a, int n, int root)
{
	int parent = root;
	int child = 2 * root + 1;
	while (child<n)
	{
		if (child+1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void AdJustUp(Heap* hp)
{
	int child = hp->size - 1;
	int parent = (hp->size - 2) / 2;
	while (child > 0)
	{
		if (hp->a[child] < hp->a[parent])
		{
			int temp = hp->a[parent];
			hp->a[parent] = hp->a[child];
			hp->a[child] = temp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}


void HeapPush(Heap* hp, int x)
{
	if (hp->size == hp->capacity)
	{
		int capacity = hp->capacity * 2;
		hp->a = (HDataType*)realloc(hp->a, sizeof(HDataType) * capacity);
	}
	if (hp->a  == NULL)
		exit(-1);
	hp->a[hp->size] = x;
	hp->size++;
	AdJustUp(hp);
}



void HeapPop(Heap* hp)
{
	int end = hp->size - 1;
	
	int temp = hp->a[0];
	hp->a[0] = hp->a[end];
	hp->a[end] = temp;
	hp->size--;
	AdJustDown(hp->a, hp->size, 0);

}


int HeapTop(Heap* hp)
{
	return hp->a[0];
}
