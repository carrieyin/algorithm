#define  _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <vector>
#include <iostream>
using namespace std;
//����ת��
void convert(stack<char> &s, int n, int base)
{
	char digit[] = { '0', '1','2', '3','4', '5','6', '7','8', '9','A', 'B','C', 'D','E','F' };
	while (n > 0)
	{
		s.push(digit[n % base]);
		n /= base;
	}
}

//����ƥ�� ֻ���������ź������ţ������ƹ㵽��������
//��û������Ľⷨ?ʵ���ϱ�����������Ŀ������������-1�����Ϊ0�Ϳ����ˣ�����Ҫ
//��������Ƕ�����ţ������������ͻ�ʧЧ
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

	//ע��s��sizeһֱ�ڱ�С����ôд�Ǵ����
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