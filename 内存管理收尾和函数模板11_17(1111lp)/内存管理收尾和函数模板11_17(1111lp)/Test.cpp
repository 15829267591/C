#include <iostream>
using namespace std;

#if 0
//	���ַ�ʽ��ȱ������ڶ���ȷʵ���ܴ����������Ҫ�����κ�λ�ö����ܴ���������ջ������ʱ���������ˣ���Ϊ��ʱ������ȫ�������򴴽�

class StackOnly
{
public:
	StackOnly()
	{

	}
private:
	void* operator new(size_t size);
};

StackOnly s;//�Ȳ��ڶ���Ҳ����ջ�ϣ����ַ�ʽ���Դ�����
int main()
{
	//StackOnly* ps = new StackOnly;	����û��ʵ�����ַ�ʽ����

	//StackOnly* ps = (StackOnly*)malloc(sizeof(StackOnly));
	//new(ps) StackOnly;
	return 0;
}

#endif


//Ҫ��ȫ��������Ҳ���ܴ���
class StackOnly
{
public:
	static StackOnly CreateInstrance()
	{
		//StackOnly t;
		//return t;
		//���ַ�ʽЧ�ʲ�ͬ���������ַ�ʽ���ȴ���һ�����󣬣���ջ�ϣ�ֻ����ֵ���أ�ֵ���ػᴴ��һ����ʱ�������������죬���˷�ʱ��
		//�������ַ�ʽ���������𲻴󣬵����������ܻ��������Ż�����ֱ�ӷ���
		return StackOnly();//��������
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
StackOnly s;//�ռ������ݶ�

int main()
{
	StackOnly::CreateInstrance ();
	return 0;
}


