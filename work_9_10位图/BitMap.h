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
//精确算法    哈希
//近似算法    布隆过滤器（实现）
//定义一个函数指针、函数返回类型为int、参数为字符串

typedef int(*StrToInt)(const char*);
typedef struct BloomFilter {
	BitMap _bmp;
	int size;
	StrToInt HashFun[5];
}BloomFilter;
//字符串转化成整型的函数
int HashFun1(const char* str);
int HashFun2(const char* str);
int HashFun3(const char* str);
int HashFun4(const char* str);
int HashFun5(const char* str);

void BloomFilterInit(BloomFilter *BloomFilter, int total, StrToInt *hashfun);
//插入
void InsertBloomFilter(BloomFilter *BloomFilter, char *str);
//大小
int SizeBloomFilter(BloomFilter *BloomFilter);
//查询
int FindBloomFilter(BloomFilter* BloomFilter, char *str);
//删除
void DeleteBloomFilter(BloomFilter *BloomFilter, char *str);


//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
void BitMapSet3(BitMap* bm, size_t x);
int BitMapTest3(BitMap* bm, size_t x);

void BitMapAppearNoMoreTwice(BitMap*bm, size_t x);
#endif // __WEITU_H__



