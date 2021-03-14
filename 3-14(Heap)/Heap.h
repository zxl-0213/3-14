#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* a;
	int size;
	int capacity;
}Heap;

//初始化
void HeapInit(Heap* hp, int* a, int n);

//打印函数
void HeapPrint(Heap* hp);

//向下调整
void AdJustDown(HDataType* hp, int n, int root);


////增加数据
void HeapPush(Heap* hp, int x);

//减去最小的元素
void HeapPop(Heap* hp);

//读取第一个元素
int HeapTop(Heap* hp);