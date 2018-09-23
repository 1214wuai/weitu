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
// x存在返回0，不存在返回-1 
int BitMapTest(BitMap* bm, size_t x);
//附加题
//1.给定100亿个整数，设计算法找到只出现一次的整数
void BitMapInit2(BitMap* bm, size_t range);
void BitMapSet2(BitMap* bm, size_t x);
void BitMapOnceTime(BitMap*bm, size_t x);
void BitMapReset2(BitMap* bm, size_t x);

//2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集

//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
void BitMapSet3(BitMap* bm, size_t x);
int BitMapTest3(BitMap* bm, size_t x);

void BitMapAppearNoMoreTwice(BitMap*bm, size_t x);
#endif // __WEITU_H__



