#include <iostream>
using namespace std;

#if 0
//	这种方式的缺点就是在堆上确实不能创建，但如果要求在任何位置都不能创建（除了栈），此时就有问题了，因为此时可以在全局作用域创建

class StackOnly
{
public:
	StackOnly()
	{

	}
private:
	void* operator new(size_t size);
};

StackOnly s;//既不在堆上也不在栈上，这种方式可以创建。
int main()
{
	//StackOnly* ps = new StackOnly;	函数没有实现这种方式不行

	//StackOnly* ps = (StackOnly*)malloc(sizeof(StackOnly));
	//new(ps) StackOnly;
	return 0;
}

#endif


//要让全局作用域也不能创建
class StackOnly
{
public:
	static StackOnly CreateInstrance()
	{
		//StackOnly t;
		//return t;
		//两种方式效率不同，上面这种方式，先创建一个对象，（在栈上）只能是值返回，值返回会创建一个临时变量，拷贝构造，会浪费时间
		//下面这种方式，和上面差别不大，但编译器可能会对其进行优化，会直接返回
		return StackOnly();//无名对象
	}
	StackOnly(const StackOnly&)
	{
		cout << "StackOnly(const StackOnly&):" << this << endl;
	}
private:
	StackOnly()
	{
		StackOnly s(StackOnly::CreateInstrance());

	}
	
};
class Test
{
	Test()
	{
		StackOnly::CreateInstrance();
	}
};
StackOnly s;//空间在数据段

int main()
{
	StackOnly::CreateInstrance ();
	return 0;
}


