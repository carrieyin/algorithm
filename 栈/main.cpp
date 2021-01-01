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

//ջ��ϴ�����ж�
//����origin��ԭ���� seq�ǻ�ϴ���У��ж�seq�ǲ���origin�Ļ�ϴ����
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

//��ȡ�����ܶ�����֣���Ϊ����ʱ������ж�λ,�����Ȳ�����С����
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
			return '<';	//ɨ���С��ջ��
		else
			return '>';	//ɨ��Ĵ���ջ��
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
			printf("��������!\n");	exit(-1);
		}
		return '>';
		break;
	case ')':
		if (top == '(')
			return '=';
		else if (top == '#') {
			printf("��������!\n");
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
//��׺���ʽ��ֵ s���ʽ
//����˼���ǣ�����������Ԫ�طֿ�ջ���
//�������ջ�����������ȼ��������ʱ��ȡ�������������͸���������м���
float evaluate(char * S)
{
	stack<float> opnd; //������
	stack<char> optr;  //������
	optr.push('#'); //��ʶ������
	while (!optr.empty()) //��������ַ���ֱ�������ȫ���������
	{
		if (isdigit(*S))
		{
			readNumber(S, opnd);
		}
		else
		{
			switch (compareOptr(optr.top(), *S))
			{
			case '>': //ջ�����ȼ��ߣ�����м���
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

			case '<': //ջ���������ȼ��ͣ����ӳټ��㣬����ջ��
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