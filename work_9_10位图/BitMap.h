#ifndef __WEITU_H__
#define __WEITU_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct BitMap
{
	size_t* _bits;
	size_t _range;
}BitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, size_t x);
void BitMapReset(BitMap* bm, size_t x);
// x���ڷ���0�������ڷ���-1 
int BitMapTest(BitMap* bm, size_t x);
//������
//1.����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�����
void BitMapInit2(BitMap* bm, size_t range);
void BitMapSet2(BitMap* bm, size_t x);
void BitMapOnceTime(BitMap*bm, size_t x);
void BitMapReset2(BitMap* bm, size_t x);

//2.�������ļ����ֱ���100�ڸ�����������ֻ��1G�ڴ棬����ҵ������ļ�����

//3.1���ļ���100�ڸ�int��1G�ڴ棬����㷨�ҵ����ִ���������2�ε���������
void BitMapSet3(BitMap* bm, size_t x);
int BitMapTest3(BitMap* bm, size_t x);

void BitMapAppearNoMoreTwice(BitMap*bm, size_t x);
#endif // __WEITU_H__



