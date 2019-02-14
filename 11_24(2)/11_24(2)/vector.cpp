#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Date 
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;

};
template <class T>
void PrintVector(const vector<T> &v)
{
	for (auto e: v)
	{
		cout << e << " ";
		cout << endl;
	}
}
void TestVector()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	vector<int> v3(10);
	vector <Date> v4(10);

	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> v5(array, array + sizeof(array) / sizeof(array[0]));

	string str ( "hello");
	vector <char> v6(str.begin(), str.end());
	vector <char> v7(v6);

	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);
	PrintVector(v6);
	PrintVector(v7);


}
int main()
{
s	TestVector();
	return 0;
}