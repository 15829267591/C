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


	Test* pt = (Test*)malloc(sizeof(Test));//��ʱֻ��������С��ȵĿռ����
	new(pt) Test(10);
	/*
	void * operator new(size_t size,void* p)
	{
	return p;
	����Ҫ����ռ䣬ֱ�ӷ���
	}
	call Test();
	*/

	//Test* pt = new Test(10);
	/*
	void * operator new(size_t size)
	{
	����ռ䲢����
	}
	call Test();
	*/
	//һ������ò��� ����������������new�������ռ���new[].
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
		//delete this;//��Ҫ����������delete this
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
	//���ϴ������ˣ���ջ�ϴ���������ջ�ϴ�������Ҫ�ж���Ҳ����Ҫ���ж�����ã�
	//��ʱû�취�����������԰Ѻ�����Ϊ��̬�ģ�ͨ����������
	//���ַ���ֻ�ǽ����˹��캯�������ܴ������󣩣������ܽ�����������
	~Test()
	{
		cout << "~Test():" << endl;
	}
private:
	Test(int date)
	{
		cout << "Test():" << this << endl;	
	}

	//��Ϊ���캯����˽�еģ������ڶ��ϲ��ܴ���
private:
	int _data;
};
int main()
{
	Test* pt = Test::CreateInstrance(10);

	return 0;
}