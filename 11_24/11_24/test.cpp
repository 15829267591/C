#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			//str = "";			//如果字符串为空，处理方式：1、直接把字符串给成空串
														//  2、断言
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		//if (nullptr == str) //这种方式更容易理解
		//{
		//	_str = new char[1];
		//	*_str = '\0';
		//}
		//else
		//{
		//	_str = new char[strlen(str) + 1];
		//	strcpy(_str, str);
		//}
	}
	String(const String& s)             //拷贝构造函数
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
	String& operator = (const String& s)   //返回引用？
	{
		if (this != &s)
		{
			char *pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[]_str;
			_str = pStr;
		}// 此处的&是取地址 上面参数是引用
		return *this;
	}

private:
	char* _str;
};
#endif 
#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str); 
	}
	//拷贝构造函数
	String(const String& s)
		:_str(nullptr)
	{
		String strTemp(s._str);  //strTemp(s) 
		swap(_str,strTemp._str); // swap 是库中的函数 namespace std中

	}
	//String& operator =(String &s)
	//{
	//	if (this != &s)
	//	{
	//		String strTemp(s);
	//		swap(_str, strTemp._str);
	//	}
	//     return *this;
	//}

	String & operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
int main()
{
	return 0;
}
#endif

	class String
	{
	public:
		typedef char* Iterator;
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			
				str = "";
			
			_size = strlen(str);
			_str = new char[_size+1];
			_capacity = _size;
			strcpy(_str, str);

		}
		String(const String& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)

		{
			strcpy(_str, s._str);
		}
		String& operator = (const String& s)
		{
			if (this != &s)
			{
				char* pStr = new char[s._capacity + 1];
				strcpy(pStr, s._str);
				delete[]_str;
				_str = pStr;
				_size = s._size;
				_capacity = s._capacity;

			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
			}
		}

		///////////////////////////////////////////////////////////
				//////////////////迭代器
		Iterator Begin()
		{
			return _str;
		}
		Iterator End()
		{
			return _str + _size;
		}
		Iterator RBegin()
		{
			return End();
		}
		Iterator REnd()
		{
			return Begin();
		}
		void PushBack(char c)
		{
			Reserve(_size + 1);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void PushBack2(char c)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void Append(const char* str)
		{
			int len = strlen(str);
			if (len > _capacity - _size)
			{
				Reserve(_capacity * 2 + len);

			}
			strcat(_str, str);
			_size = _size + len;
		}
		char& operator[](size_t index)
		{
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			return _str[index];
		}
		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
		void Swap(String& s)
		{
			swap(_str,s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_str()const
		{
			return _str;
		}
		size_t Size()const
		{
			return _size;
		}
		size_t Capacity()const
		{ 
			return _capacity;
		}
		bool Empty()const
		{
			return 0 == _size;
		}
		void Resize(size_t newSize, char c )
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				delete[]_str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		bool operator<(const String& s)
		{
			const char* _tmp = _str;
			const char* tmp = s._str;
			while (*_tmp != '\0' && *tmp != '\0'&& *_tmp == *tmp)
			{
				_tmp++;
				tmp++;
			}
			if (*_tmp < *tmp)
				return true;
			return false;
		}
		bool operator<=(const String& s)
		{
			if (*this < s || *this == s)
			{
				return true;
			}
			return false;
		}
		bool operator>(const String& s)
		{
			const char * _tmp = _str;
			const char *tmp = s._str;
			if (*_tmp != '\0' && *tmp != '\0' && *_tmp == *tmp)
			{
				_tmp++;
				tmp++;
			}
			if (*_tmp > * tmp)
				return true;
			return  false;

		}
		bool operator>=(const String& s)
		{
			if (*this > s || *this > s)
			{
				return true;
			}
			return false;
		}
		bool operator==(const String& s)
		{
			const char*_tmp = _str;
			const char* tmp = s._str;
			while (*_tmp == *tmp)
			{
				if (*_tmp == '\0'&& *tmp == '\0')
				{
					return true;
				}
				_tmp++;
				tmp++;
			}
			return false;

		}
		bool operator!=(const String& s)
		{
			if (!(*this == s))
				return true;
			return false;
		}
		friend ostream& operator<<(ostream& _cout, const String& s)
		{

		}
		friend istream& operator>>(istream& _cout, String& s);
		int find(char c, size_t pos = 0)

		{
			for (int i = pos; i < _size; ++i)
			{
				if (c == _str[i])
					return true;
			}
			return false;
		}
		int rfind(char c)
		{
			int i = 0;
			for (i < _size - 1; i >= 0; --i)
			{
				if (c == _str[i])
				{
					return true;
				}
				return false;
			}
		}
		size_t Find(char c, size_t pos = 0)const;
		size_t Find(const char* s, size_t pos = 0)const
		{

		}

		//String& Insert(size_t pos, char c)
		//{
		//	if (pos > _size)
		//	{
		//		printf("输入有误！");
		//		return;
		//	 }
		//	else
		//	{
		//		if (_size + 1 > _capacity)
		//			Reserve(_capacity * 2);
		//	}
		//	_str[_size + 1] = '\0';
		//	for (int i = _size; i > (int)pos; --i)
		//	{
		//		_str[i] = _str[i - 1];
		//	}
		//	_str[pos] = c;
		//	_size++;

		//}

	private:			
		char* _str;
		size_t _size;
		size_t _capacity;
		const static int npos;

	};
	const int String::npos = -1;

	void TestString1()
	{
		String s1;
		String s2("hello bit");
		String s3(s2);

		s1 = s3;
		//cout << s1 << endl;
		//cout << s2 << endl;
		//cout << s3 << endl;

	}


	int main()
	{
		TestString1();
		return 0;
	}