#include"Heap.h"
/*void HeapSort(int* a,int n)
{
	//½¨¶Ñ
	for (int root = (n - 2) / 2; root >= 0; root--)
	{
		AdJustDown(a, n, root);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	//½µÐò
	int end = n - 1;
	while (end > 0)
	{
		int temp = a[end];
		a[end] = a[0];
		a[0] = temp;
		AdJustDown(a,end,0);
		end--;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}*/
int main()
{
	Heap hp;
	int a[10] = { 13,45,11,34,45,66,40,55,78,24 };
	//HeapSort(a,10);
	HeapInit(&hp, a, 10);
	HeapPrint(&hp);

	HeapPush(&hp, 99);
	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);


	int ret = HeapTop(&hp);
	printf("%d", ret);


	return 0;
}