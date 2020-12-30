#define  _CRT_SECURE_NO_WARNINGS

#include <stack>
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

int main()
{
	stack<char> s;
	convert(s, 32, 2);
	
	//注意s的size一直在变小，这么写是错误的
#if 0
    for (size_t i = 0; i < s.size(); i++)
	{
		cout << s.size();
		cout << s.top() <<" ";
		s.pop();
	}

#endif
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

}