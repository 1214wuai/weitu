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

int main()
{
	test();
	return 0;
}