#ifndef __WEITU_H__
#define __WEITU_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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



#endif // __WEITU_H__



