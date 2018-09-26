#include"BitMap.h"
void BitMapInit(BitMap* bm, size_t range)
{
	assert(bm);
	bm->_bits = (size_t*)malloc(sizeof(char)*((range>>3)+1));
	bm->_range = range;
	memset(bm->_bits, 0, range);
}
void BitMapSet(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	bm->_bits[index]  |= (y << h);
}
void BitMapReset(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	bm->_bits[index] &= (~(y << h));
}
// x存在返回0，不存在返回-1 
int BitMapTest(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t h = x % 8;
	size_t y = 1;
	y = y << h;
	if (y&(bm->_bits[index]))
		return 0;
	else
		return -1;
}
void BitMapInit2(BitMap* bm, size_t range)
{
	assert(bm);
	bm->_bits = (size_t*)malloc(sizeof(char)*((range >> 2) + 1));
	bm->_range = range;
	memset(bm->_bits, 0, ((range >> 2) + 1));
}
void BitMapSet2(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 4;//除以16
	size_t y = x % 8;
	if (BitMapTest2(bm, x) == -1)//没有出现
	{
		bm->_bits[index] |= (1 << y);
	}
	else if (BitMapTest2(bm, x) == 1)//出现一次
	{
		bm->_bits[index] |= (1 << (y + 1));
	}
	else//出现两次或两次以上
		;
}
void BitMapOnceTime(BitMap*bm, size_t x)
{
	/*assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;*/
	if (BitMapTest2(bm, x) == 2)//出现两次或两次以上
		printf("%u appear twice\n",x);
	if (BitMapTest2(bm, x) == -1)//没有出现
		printf("%u is't appear\n", x);
	if (BitMapTest2(bm,x)==1)//出现一次
		printf("%u appear once\n", x);

}
void BitMapReset2(BitMap* bm, size_t x)
{

}
// 
int BitMapTest2(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;
	//if ((((bm->_bits[index]) & (~(1 << y))) == (1<<y)) && (((bm->_bits[index]) & (~(1 << (y + 1)))) == (1 << (y + 1))))//出现两次以上
	//	return 2;
	//else if ((((bm->_bits[index]) & (~(1 << y))) == 0) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == 0))//没有出现
	//	return -1;
	//else if (((((bm->_bits[index]) & (~(1 << y))) == (1 << y)) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == 0)) ||
	//	((((bm->_bits[index]) & (~(1 << y))) == 0) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == (1 << (y + 1)))))//出现一次
	//	return 1;
	if ((((bm->_bits[index]) & ((1 << y))) != 0) && (((bm->_bits[index]) & ((1 << (y + 1)))) != 0))//出现两次以上
		return 2;
	else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0))//没有出现
		return -1;
	else if (((((bm->_bits[index]) & ((1 << y))) != 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0)) ||
		((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) != 0)))//出现一次
		return 1;
	else
		return 0;
}
void BitMapSet3(BitMap* bm, size_t x)//00一次  01一次 10两次  11三次
{
	assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;

	if (BitMapTest3(bm, x) == 0)
	{
		bm->_bits[index] |= (1 << (y-1));//00变成01
	}
	else if (BitMapTest3(bm, x) == 1)//01变成10
	{
		bm->_bits[index] &= (~(1 << (y-1)));
		bm->_bits[index] |= (1 << (y));
	}
	else if (BitMapTest3(bm, x) == 2)//10变成11
	{
		bm->_bits[index] |= (1 << (y-1));
	}
	else if (BitMapTest3(bm, x) == 3)
	{
		;
	}
	else
		return;
}
int BitMapTest3(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;
	//if ((((bm->_bits[index]) & ((1 << y))) != 0) && (((bm->_bits[index]) & ((1 << (y + 1)))) != 0))//出现两次以上
	//	return 3;
	//else if (((((bm->_bits[index]) & ((1 << y))) != 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0)))//出现两次
	//	return 2;
	//else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) != 0))//出现一次
	//	return 1;
	//else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0))//没有出现
	//	return 0;
	//else
	//	return -1;
	if ((((bm->_bits[index]) & ((1 << (y - 1)))) != 0) && (((bm->_bits[index]) & ((1 << (y )))) != 0))//出现两次以上
		return 3;
	else if (((((bm->_bits[index]) & ((1 << (y - 1)))) == 0) && ((((bm->_bits[index]) & ((1 << (y ))))) != 0)))//出现两次
		return 2;
	else if ((((bm->_bits[index]) & ((1 << (y - 1)))) != 0) && ((((bm->_bits[index]) & ((1 << (y ))))) == 0))//出现一次
		return 1;
	else if ((((bm->_bits[index]) & ((1 << (y - 1)))) == 0) && ((((bm->_bits[index]) & ((1 << (y ))))) == 0))//没有出现
		return 0;
	else
		return -1;
}
void BitMapAppearNoMoreTwice(BitMap*bm, size_t x) 
{
	if (BitMapTest3(bm, x) == 3)
	{
		printf("%u apper more than twice\n", x);
	}
	if ((BitMapTest3(bm, x) == 2) || (BitMapTest3(bm, x) == 1) || (BitMapTest3(bm, x) == 0))
	{
		printf("%u apper Nomore than twice\n", x);
	}
	else
		return;
	
}
///////////////////////////////////////////str转int的方法////////////////////////////////////////////////////////////
int HashFun1(const char* str)//相加
{
	assert(str);
	int hash = 0;
	while (*str)
	{
		hash += (*str++);
	}
	return hash;
}
int HashFun2(const char* str)
{
	assert(str);
	int hash = 0;
	while (*str)
	{
		hash *= (*str++);
	}
	return hash;
}
int HashFun3(const char* str)
{
	assert(str);
	int hash = 0;
	while (*str)
	{
		hash *= (*str++);
	}
	return hash;
}
int HashFun4(const char* str)
{
	assert(str);
	int hash = 0;
	while (*str)
	{
		hash *= (*str++);
	}
	return hash;
}
int HashFun5(const char* str)
{
	assert(str);
	int hash = 0;
	while (*str)
	{
		hash *= (*str++);
	}
	return hash;
}
																
void BloomFilterInit(BloomFilter *BloomFilter, int total, StrToInt *hashfun)
{
	assert(BloomFilter);
	//BloomFilter->_bmp = (BitMap*)malloc(sizeof(char)*((total >> 3)+1));
	int i = 0;
	BitMapInit(&BloomFilter->_bmp, total * 5);//设置Bit位
	for (i = 0; i < 5; i++)
	{
		BloomFilter->HashFun[i] = hashfun[i];
	}
	BloomFilter->size = 0;
}
void InsertBloomFilter(BloomFilter *BloomFilter, char *str)
{
	int hash1 = 0;
	int hash2 = 0;
	int hash3 = 0;
	int hash4 = 0;
	int hash5 = 0;
	assert(BloomFilter);
	hash1 = BloomFilter->HashFun[0](str);
	hash2 = BloomFilter->HashFun[1](str);
	hash3 = BloomFilter->HashFun[2](str);
	hash4 = BloomFilter->HashFun[3](str);
	hash5 = BloomFilter->HashFun[4](str);
	BitMapSet(&BloomFilter->_bmp, hash1);
	BitMapSet(&BloomFilter->_bmp, hash2);
	BitMapSet(&BloomFilter->_bmp, hash3);
	BitMapSet(&BloomFilter->_bmp, hash4);
	BitMapSet(&BloomFilter->_bmp, hash5);

}
int SizeBloomFilter(BloomFilter *BloomFilter)
{

}
int FindBloomFilter(BloomFilter* BloomFilter, char *str)
{

}
void DeleteBloomFilter(BloomFilter *BloomFilter, char *str)
{

}