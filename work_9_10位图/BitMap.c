#include"BitMap.h"
void BitMapInit(BitMap* bm, size_t range)
{
	bm->_bits = (size_t*)malloc(sizeof(char)*((range>3)+1));
	bm->_range = range;
	memset(bm->_bits, 0, range);
}
void BitMapSet(BitMap* bm, size_t x)
{
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	bm->_bits[index] =(bm->_bits[index] | (y << h));
}
void BitMapReset(BitMap* bm, size_t x)
{
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	bm->_bits[index] -= (y << h);
}
// x存在返回0，不存在返回-1 
int BitMapTest(BitMap* bm, size_t x)
{
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	y = y << h;
	if (y&(bm->_bits[index]))
		return 0;
	else
		return -1;
}