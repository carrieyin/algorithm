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
bool paren(vector<char>& v)
{
	stack<char> s;
	for (size_t i = 0; i < v.size(); i++)
	{
		char c = v.at(i);
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

//栈混洗序列判定
//其中origin是原序列 seq是混洗序列，判定seq是不是origin的混洗序列
bool isPermutationSeq(vector<int>& origin, vector<int>& seq)
{
	stack<int> a;
	int i = 0;  int j = 0;
	for ( ; i < origin.size(); i++)
	{
		int t = origin.at(i);
		a.push(t);
		
		while(!a.empty() && j < seq.size() && t == seq.at(j) )
		{
			a.pop();
			j++;
			if (!a.empty())
			{
				t = a.top();
			}			
		}
	}
	
	return a.empty();
}

//读取尽可能多的数字，因为计算时候可能有多位,本处先不考虑小数点
void readNumber(char *s, stack<float>& opnd)
{
	
}

void readoptr(char * S)
{
	
}

char compareOptr(char ch, char top)
{
	switch (ch) {
	case '+':
	case '-':
		if (top == '+' || top == '-' || top == '*' || top == '/')
			return '<';	//扫描的小于栈顶
		else
			return '>';	//扫描的大于栈顶
		break;
	case '*':
	case '/':
		if (top == '*' || top == '/')
			return '<';
		else
			return '>';
		break;
	case '(':
		if (top == ')') {
			printf("输入有误!\n");	exit(-1);
		}
		return '>';
		break;
	case ')':
		if (top == '(')
			return '=';
		else if (top == '#') {
			printf("输入有误!\n");
			exit(-1);
		}
		else {
			return '<';
		}
		break;
	case '#':
		return '<';
	}
}

int calc(int f, char op)
{
	int result;
	switch (op)
	{
	case '!':
		for (int i = 0; i < n; i++)
		{
			result *= i;
		}
		break;
	}
	return result;
}

float calc(float tempNum1, float tempNum2, char op)
{
	float result; 
	switch (op) {
	case '+':	result = tempNum1 + tempNum2;	break;
	case '-':	result = tempNum1 - tempNum2;	break;
	case '*':	result = tempNum1 * tempNum2;	break;
	case '/':	result = tempNum2 / tempNum1;	break;
	}

	return result;
}
//中缀表达式求值 s表达式
//主体思想是，将操作符和元素分开栈存放
//当运算符栈中遇到高优先级的运算符时，取出两个操作符和该运算符进行计算
float evaluate(char * S)
{
	stack<float> opnd; //操作数
	stack<char> optr;  //操作符
	optr.push('#'); //标识结束符
	while (!optr.empty()) //处理各个字符，直至运算符全部处理完毕
	{
		if (isdigit(*S))
		{
			readNumber(S, opnd);
		}
		else
		{
			switch (compareOptr(optr.top(), *S))
			{
			case '>': //栈顶优先级高，则进行计算
				char op = optr.top();
				if (op == '!')
				{
					float value = calc(opnd.top(), op);
					opnd.pop();
					opnd.push(value);
				}
				else
				{
					float value1 = opnd.top();
					opnd.pop();
					float value2 = opnd.top();
					opnd.pop();
					float value = calc(value1, value2,op);
					opnd.push(value);
				}
				break;

			case '<': //栈顶符号优先级低，则延迟计算，放入栈中
				optr.push(*S); S++; break;
			case '=':
				optr.pop(); S++;break;
			default:
				break;
			}
		}
	}
	
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

void test02()
{
	vector<int> v = { 1, 2, 3, 5, 6,7 };
	vector<int> seq = { 3, 2, 1, 5, 6, 7 };
	cout << isPermutationSeq(v, seq) << endl;
	vector<int> v1 = { 1, 2, 3, 5, 6,7 };
	vector<int> seq1 = { 3, 2, 1, 7, 5, 6 };
	cout << isPermutationSeq(v1, seq1) << endl;
	vector<int> v2 = { 1, 2, 3, 5, 6, 7 };
	vector<int> seq2 = { 1, 3, 2, 7, 6, 5 };
	cout << isPermutationSeq(v2, seq2) << endl;
}
int main()
{
	//test01();
	test02();
}