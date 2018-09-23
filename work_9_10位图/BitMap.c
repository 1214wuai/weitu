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
// x���ڷ���0�������ڷ���-1 
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
	size_t index = x >> 4;//����16
	size_t y = x % 8;
	if (BitMapTest2(bm, x) == -1)//û�г���
	{
		bm->_bits[index] |= (1 << y);
	}
	else if (BitMapTest2(bm, x) == 1)//����һ��
	{
		bm->_bits[index] |= (1 << (y + 1));
	}
	else//�������λ���������
		;
}
void BitMapOnceTime(BitMap*bm, size_t x)
{
	/*assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;*/
	if (BitMapTest2(bm, x) == 2)//�������λ���������
		printf("%u appear twice\n",x);
	if (BitMapTest2(bm, x) == -1)//û�г���
		printf("%u is't appear\n", x);
	if (BitMapTest2(bm,x)==1)//����һ��
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
	//if ((((bm->_bits[index]) & (~(1 << y))) == (1<<y)) && (((bm->_bits[index]) & (~(1 << (y + 1)))) == (1 << (y + 1))))//������������
	//	return 2;
	//else if ((((bm->_bits[index]) & (~(1 << y))) == 0) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == 0))//û�г���
	//	return -1;
	//else if (((((bm->_bits[index]) & (~(1 << y))) == (1 << y)) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == 0)) ||
	//	((((bm->_bits[index]) & (~(1 << y))) == 0) && ((((bm->_bits[index]) & (~(1 << (y + 1))))) == (1 << (y + 1)))))//����һ��
	//	return 1;
	if ((((bm->_bits[index]) & ((1 << y))) != 0) && (((bm->_bits[index]) & ((1 << (y + 1)))) != 0))//������������
		return 2;
	else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0))//û�г���
		return -1;
	else if (((((bm->_bits[index]) & ((1 << y))) != 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0)) ||
		((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) != 0)))//����һ��
		return 1;
	else
		return 0;
}
void BitMapSet3(BitMap* bm, size_t x)//00һ��  01һ�� 10����  11����
{
	assert(bm);
	size_t index = x >> 4;
	size_t y = x % 8;

	if (BitMapTest3(bm, x) == 0)
	{
		bm->_bits[index] |= (1 << (y-1));//00���01
	}
	else if (BitMapTest3(bm, x) == 1)//01���10
	{
		bm->_bits[index] &= (~(1 << (y-1)));
		bm->_bits[index] |= (1 << (y));
	}
	else if (BitMapTest3(bm, x) == 2)//10���11
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
	//if ((((bm->_bits[index]) & ((1 << y))) != 0) && (((bm->_bits[index]) & ((1 << (y + 1)))) != 0))//������������
	//	return 3;
	//else if (((((bm->_bits[index]) & ((1 << y))) != 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0)))//��������
	//	return 2;
	//else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) != 0))//����һ��
	//	return 1;
	//else if ((((bm->_bits[index]) & ((1 << y))) == 0) && ((((bm->_bits[index]) & ((1 << (y + 1))))) == 0))//û�г���
	//	return 0;
	//else
	//	return -1;
	if ((((bm->_bits[index]) & ((1 << (y - 1)))) != 0) && (((bm->_bits[index]) & ((1 << (y )))) != 0))//������������
		return 3;
	else if (((((bm->_bits[index]) & ((1 << (y - 1)))) == 0) && ((((bm->_bits[index]) & ((1 << (y ))))) != 0)))//��������
		return 2;
	else if ((((bm->_bits[index]) & ((1 << (y - 1)))) != 0) && ((((bm->_bits[index]) & ((1 << (y ))))) == 0))//����һ��
		return 1;
	else if ((((bm->_bits[index]) & ((1 << (y - 1)))) == 0) && ((((bm->_bits[index]) & ((1 << (y ))))) == 0))//û�г���
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