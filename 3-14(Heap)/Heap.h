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

//��ʼ��
void HeapInit(Heap* hp, int* a, int n);

//��ӡ����
void HeapPrint(Heap* hp);

//���µ���
void AdJustDown(HDataType* hp, int n, int root);


////��������
void HeapPush(Heap* hp, int x);

//��ȥ��С��Ԫ��
void HeapPop(Heap* hp);

//��ȡ��һ��Ԫ��
int HeapTop(Heap* hp);