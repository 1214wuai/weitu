#include"BitMap.h"
test()
{
	BitMap bm;
	BitMapInit(&bm, 10);
	
	BitMapSet(&bm, 2);
	int x1 = BitMapTest(&bm, 2);
	BitMapSet(&bm, 20);

	BitMapReset(&bm, 2);
	//BitMapSet(&bm, 8);
	BitMapSet(&bm, 7);
	BitMapSet(&bm, 6);
	BitMapSet(&bm, 5);
	int x2 = BitMapTest(&bm, 2);
	int x3 = BitMapTest(&bm, 8);
	int x4 = BitMapTest(&bm, 7);
	int x5 = BitMapTest(&bm, 6);
	int x6 = BitMapTest(&bm, 5);
	int x7 = BitMapTest(&bm, 4);
	int x8 = BitMapTest(&bm, 20);
	BitMapReset(&bm, 20);
	int x9 = BitMapTest(&bm, 20);


}
testBitMapOnceTime()
{
	BitMap bt;
	BitMapInit2(&bt, -1);//range是size_t型，-1存进去就是全1，表示整型最大数
	BitMapSet2(&bt, 1);
	BitMapSet2(&bt, 1);
	BitMapSet2(&bt, 99);//只能插入非负数
	BitMapSet2(&bt, 16);
	BitMapSet2(&bt, 16);
	BitMapSet2(&bt, 16);
	BitMapSet2(&bt, 88);
	BitMapSet2(&bt, 1024);
	BitMapSet2(&bt, 420000000);

	BitMapOnceTime(&bt, 99);
	BitMapOnceTime(&bt, 16);
	BitMapOnceTime(&bt, 88);
	BitMapOnceTime(&bt, 1024);
	BitMapOnceTime(&bt, 2024);
	BitMapOnceTime(&bt, 420000000);

	
}
testAppearNoMoreTwice()
{
	BitMap bt;
	BitMapInit2(&bt, -1);
	BitMapSet3(&bt, 1);
	BitMapSet3(&bt, 1);
	BitMapSet3(&bt, 1);
	BitMapSet3(&bt, 1);//只能插入非负数
	BitMapSet3(&bt, 17);
	BitMapSet3(&bt, 17);
	//BitMapSet3(&bt, 17);
	BitMapSet3(&bt, 88);
	BitMapSet3(&bt, 1024);
	BitMapSet3(&bt, 420000000);

	BitMapAppearNoMoreTwice(&bt, 1);
	BitMapAppearNoMoreTwice(&bt, 99);
	BitMapAppearNoMoreTwice(&bt, 17);
	BitMapAppearNoMoreTwice(&bt, 88);
	BitMapAppearNoMoreTwice(&bt, 420000000);
	BitMapAppearNoMoreTwice(&bt, 1024);

}

testBloomFilter()
{
	char* str1 = "ab";
	BloomFilter bmp;
	StrToInt hashfun[5] = { HashFun1 ,HashFun2,HashFun3,HashFun4,HashFun5 };
	BloomFilterInit(&bmp, 5, hashfun);
}
int main()
{
	int x = 2;
	x |= 1;
	//test();
	//testBitMapOnceTime();
	//testAppearNoMoreTwice();
	testBloomFilter();
	system("pause");
	return 0;
}