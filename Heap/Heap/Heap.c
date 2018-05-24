#include"Heap.h"
//堆的初始化
void InitHeap(Heap* hp/*, Compare com*/)
{
	assert(hp);
	hp->_array = NULL;
	hp->_size = 0;
	hp->_capacity = 0;
	//hp->_com = com;
}

//交换节点所存储的值
void Swap(HDataType* first, HDataType* second)
{
	HDataType tmp = 0;
	tmp = *first;
	*first = *second;
	*second = tmp;
}
//void CreateHeap_Personal(Heap* hp, HDataType* array, int size)
//{
//	HDataType Parent = 0;
//	HDataType Cur = 0;
//	assert(hp);
//	hp->_array = array;
//	hp->_size = size;
//	Parent = hp->_size / 2;//寻找第一个叶子节点
//	Cur = hp->_size;
//	//找到的第一个叶子节点有左孩子，不是叶子节点
//	if (Parent * 2 + 1 < hp->_size)
//	{
//		if (hp->_array[Parent] > hp->_array[Parent * 2 + 1])
//			Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 1]);
//	}
//
//	//进入肯定有两个孩子的双亲节点中的最后一个双亲节点
//	Parent--;
//
//	while (Parent >= 0)//从后向前依次判断
//	{
//		//找出两个孩子节点中较小的一个
//		if (hp->_array[Parent * 2 + 1] < hp->_array[Parent * 2 + 2])
//		{
//			//进来说明左孩子较小，判断双亲与左孩子谁大谁小
//			if (hp->_array[Parent]>hp->_array[Parent * 2 + 1])
//			{
//				Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 1]);
//				Cur = Parent * 2 + 1;
//			}
//		}
//		else
//		{
//			if (hp->_array[Parent] > hp->_array[Parent * 2 + 2])
//			{
//				Swap(&hp->_array[Parent], &hp->_array[Parent * 2 + 2]);
//				Cur = Parent * 2 + 2;
//			}
//		}
//		//判断左孩子是不是大于右孩子
//	/*		if (hp->_array[Parent * 2 + 1] > hp->_array[Parent * 2 + 2])
//				Swap(&hp->_array[Parent * 2 + 1], &hp->_array[Parent * 2 + 2]);*/
//		//判断字树是否满足堆的性质	
//		while (Cur < hp->_size/2)
//		{
//			//交换双亲与两个孩子中较小的一个
//			if (hp->_array[Cur * 2 + 1]<hp->_array[Cur * 2 + 2])
//			{
//				if (hp->_array[Cur] > hp->_array[Cur * 2 + 1])
//				{
//					Swap(&hp->_array[Cur], &hp->_array[Cur * 2 + 1]);
//				}
//				if (Cur * 2 + 1 < hp->_size)
//					Cur = Cur * 2 + 1;
//				else
//					Cur = hp->_size;
//			}
//			else
//			{
//				if (hp->_array[Cur] > hp->_array[Cur * 2 + 2])
//				{
//					Swap(&hp->_array[Cur], &hp->_array[Cur * 2 + 2]);
//				}
//				if (Cur * 2 + 2 < hp->_size)
//					Cur = Cur * 2 + 2;
//				else
//					Cur = hp->_size;
//			}
//			//判断左孩子是不是大于右孩子
//		/*	if (hp->_array[Cur * 2 + 1] > hp->_array[Cur * 2 + 2])
//				Swap(&hp->_array[Cur * 2 + 1], &hp->_array[Cur * 2 + 2]);*/
//		} 
//		Parent--;
//	}
//}
void PrintHeap(Heap hp)
{
	int size = 0;
	size = hp._size;
	while (size > 0)
	{
		printf("%d   ", hp._array[hp._size - size]);
		size--;
	}
	printf("\n");
}
void CreateHeap(Heap* hp, HDataType* array, int size/*, Compare com*/)
{
	int i = 0;
	int Root = 0;
	if (NULL == hp)
	{
		assert(0);
		return;
	}
	//给堆开辟空间
	hp->_capacity = MAXSIZE;
	hp->_array = (HDataType*)malloc(sizeof(HDataType)*hp->_capacity);
	if (NULL == hp->_array)
	{
		assert(0);
		return;
	}
	//将数组赋给堆
	hp->_size = size;
	for (i = size - 1; i >= 0; i--)
	{
		hp->_array[i] = array[i];
	}
	//com指明要创建一个小堆
	//整理堆
	Root = (size - 2) / 2;
	for (; Root >= 0; --Root)
	{
		_AdjustDown(hp, Root);
	}
}

//大堆的调整函数

//小堆的调整函数
void _AdjustDown(Heap* hp, int Root)
{
	int Parent = 0;
	int Child = 0;
	Parent = Root;
	Child = Parent * 2 + 1;
	
	while (Child < hp->_size)
	{
		//判断他的右孩子是否存在
		if (Child + 1 <= hp->_size - 1)
		{
			//找出两个孩子中较小的一个
			if (hp->_array[Child] > hp->_array[Child + 1])
				Child += 1;
		}

		//较小的孩子与双亲节点比较，如果双亲节点较大就交换
		if (hp->_array[Parent] > hp->_array[Child])
		{
			Swap(&hp->_array[Parent], &hp->_array[Child]);
		}
		Parent = Child;
		Child = Parent * 2 + 1;
	}
}
//检测堆中是否还有可用空间
void _CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		realloc(hp->_array, sizeof(HDataType)*(hp->_capacity * 2));
		if (NULL == hp->_array)
		{
			assert(0);
			return;
		}
	}
}
//在堆中插入一个元素
void InsertHeap(Heap* hp, HDataType data)
{
	int Parent = 0;
	int Child = 0;
	assert(hp);
	if (hp->_size >= hp->_capacity)
		return;

	//插入时，首先要检测堆中是否还有可用空间
	_CheckCapacity(hp);

	//将要插入的数据连接在堆的末尾
	hp->_array[hp->_size] = data;
	hp->_size++;

	//调整堆
	Parent = (hp->_size - 2) / 2;
	Child = Parent * 2 + 1;
	while (0 <= Parent)
	{
		_AdjustDown(hp, Parent);
		Parent = ((Parent - 1) >> 1);
	}
}
//检测一个堆是否为空堆
int EmptyHeap(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}
//获取堆中元素个数
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
//删除堆顶元素 
//直接删除堆顶的元素，然后把堆中最末尾的元素放在堆顶，再进行堆调整
void DeleteHeapTop(Heap* hp)
{
	assert(hp);
	if (EmptyHeap(hp))
	{
		assert(0);
		return;
	}
	//用堆末尾的元素覆盖堆顶的元素
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	//进行堆调整
	_AdjustDown(hp, 0);
}
void DestoryHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}
///////////////////////////////////////////////////////////////测试函数
void TestHeap()
{
	Heap hp;
	HDataType array[] = {53,17,78,9,45,65,87,23,31};
	//CreateHeap_Personal(&hp, array, sizeof(array)/sizeof(array[0]));
	CreateHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	InsertHeap(&hp, 1);
	PrintHeap(hp);
	DeleteHeapTop(&hp);
	PrintHeap(hp);
}

