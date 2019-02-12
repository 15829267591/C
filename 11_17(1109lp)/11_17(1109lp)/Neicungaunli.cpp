#include <iostream>
using namespace std;

#if 0
class Test
{
public:
	Test(int date)
	{
		cout << "Test():" << this << endl;
		_data = date;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};
void * operator new(size_t size,const char * funcName,int lineNo)
{
	cout << funcName << ":" << lineNo << endl;
	return malloc(size);
}
//int * operator new(size_t size)
//{
//	return (int*)malloc(size);
//}


int main()
{
	Test* pt = new(__FUNCDNAME__,__LINE__)Test(10);
	//Test* pt = new Test[10];
	//delete[]pt;
	delete pt;
	return 0;
}

#endif

#if 0
class Test
{
public:
	Test(int date)
	{
		cout << "Test():" << this << endl;
		_data = date;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};
int main()
{
	//int array[10];

	//new(array + 3)int(3);


	Test* pt = (Test*)malloc(sizeof(Test));//此时只是与对象大小相等的空间而已
	new(pt) Test(10);
	/*
	void * operator new(size_t size,void* p)
	{
	return p;
	不需要申请空间，直接返回
	}
	call Test();
	*/

	//Test* pt = new Test(10);
	/*
	void * operator new(size_t size)
	{
	申请空间并返回
	}
	call Test();
	*/
	//一般情况用不到 ，创建单个对象用new，连续空间用new[].
	delete pt;
	/*pt->~Test();
	free(pt);*/
	return 0;
}
#endif

#if 0
class Test
{
public:
	Test(int date)
	{
		cout << "Test():" << this << endl;
		_data = date;
	}
	~Test()
	{
		//delete this;//不要再析构函数delete this
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = new Test(10);
	delete pt;
	return 0;
}
#endif


#if 0
class Solution
{

public:
		class Sum
	{
	public :
		Sum()
		{

		}

	private:
		static int _count;
		static int _total;
	};
		int sum_solution(int n)
		{
			return;
		}
private:


};
int main()
{

	return 0;
}
#endif


class Test
{
public:
	static Test* CreateInstrance(int data)
	{
		return  new Test(data);
	}
	//堆上创建不了，在栈上创建，但在栈上创建必须要有对象，也就是要依托对象调用，
	//此时没办法创建对象，所以把函数设为静态的，通过类来调用
	//这种方法只是禁掉了构造函数（不能创建对象），但不能禁掉拷贝构造
	~Test()
	{
		cout << "~Test():" << endl;
	}
private:
	Test(int date)
	{
		cout << "Test():" << this << endl;	
	}

	//因为构造函数是私有的，所以在堆上不能创建
private:
	int _data;
};
int main()
{
	Test* pt = Test::CreateInstrance(10);

	return 0;
}