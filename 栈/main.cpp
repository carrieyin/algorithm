#define  _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <vector>
#include <iostream>
using namespace std;
//进制转换
void convert(stack<char> &s, int n, int base)
{
	char digit[] = { '0', '1','2', '3','4', '5','6', '7','8', '9','A', 'B','C', 'D','E','F' };
	while (n > 0)
	{
		s.push(digit[n % base]);
		n /= base;
	}
}

//括号匹配 只保存左括号和右括号，可以推广到多种括号
//有没有另外的解法?实际上保存左括号数目，遇到右括号-1，结果为0就可以了，不需要
//但是如果是多个括号，上述的做法就会失效
bool paren(vector<char> v)
{
	stack<char> s;
	for (size_t i = 0; i < v.size(); i++)
	{
		char c = v.at[i];
		 if ('(' == c)
		{
			s.push(c);
		 }
		 else if (!s.empty())
		 {
			 s.pop();
		 }
		 else
		 {
			 return false;
		 }
	}
	
	return s.empty();
}

void test01()
{
	stack<char> s;
	convert(s, 32, 2);

	//注意s的size一直在变小，这么写是错误的
#if 0
	for (size_t i = 0; i < s.size(); i++)
	{
		cout << s.size();
		cout << s.top() << " ";
		s.pop();
	}

#endif
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

}
int main()
{
	test01();
}