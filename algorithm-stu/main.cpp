#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

//查找最长连续队列
/*例如 6， 56， 2， 7， 23， 8， 5， 8，最长为4*/
int test01()
{
	vector<int> vn = { 23, 8, 3, 9,1,65,7 };
	unordered_map<int, pair<int, int> > umap;
	int max = 0;
	for (int i = 0; i < vn.size(); i++)
	{
		int num = vn.at(i);
		if (umap.count(num))
		{
			continue;
		}

		int low = num;
		int high = num;

		unordered_map<int, pair<int, int>>::iterator it = umap.find(num - 1);
		if (it != umap.end())
		{
			low = it->second.first;
		}

		unordered_map<int, pair<int, int>>::iterator it1 = umap.find(num + 1);
		if (it1 != umap.end())
		{
			high = it1->second.second;
		}
		umap[num].first = low;
		umap[num].second = high;
		umap[low].second = high;
		umap[high].first = low;

		if (high - low + 1 > max)
		{
			max = high - low + 1;
		}
	}

	return max;
}

//最长连续队列的算法二：先排序再取最长队列
int test02()
{
	vector<int> vn = { 23, 8, 3, 9,1,65,7 };
	sort(vn.begin(), vn.end());
	int maxlen = 0;
	int temMaxLen = 1;
	for (int i = 1; i < vn.size(); i++)
	{
		if (vn[i] == vn[i - 1] + 1)
		{
			temMaxLen++;
		}
		else
		{
			temMaxLen = 1;
		}

		if (temMaxLen > maxlen)
		{
			maxlen = temMaxLen;
		}
	}

	return maxlen;
}

//减而治之
int test03()
{
	vector<int> v = { 4, 7, 8, 32, 7,9 };
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	return sum;
}

//分而治之
int sum(vector<int> v, int n)
{
	return n < 1 ? 0 : sum(v, n - 1) + v[n - 1];
}

int sumdivi(vector<int> v, int high, int low)
{
	if (low == high)
	{
		return v[low];
	}
	int mid = (low + high) >> 1;
	return sumdivi(v, low, mid) + sumdivi(v, mid + 1, high);
}

void test04()
{
	char a[200];
	//cin.getline(a, 200, " ");
	cin.getline(a, 200);
	
	cout<<a;

	int m, n,  b, c, d;
	int x = 0;
	x = x + 7;
}

//查找元素-方法1 二分查找--递归
template<class T>
int binsearchRecur(vector<T>& v, T e, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) >> 1;
		if (e < v[mid])
		{
			return binsearchRecur(v, e, low, mid);
		}
		else if (v[mid] < e)
		{
			return binsearchRecur(v, e, mid + 1, high);
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
//版本1：查找长度即：关键码的比较次数。 查找成功和查找失败的比较次数，以及平均的性能，作为算法的评估，性能o(logn)
//查找元素-方法1 二分查找--迭代
//优化版-待实现，分析以上我们查找成功和失败比较的递归深度是相同的，但是关键码的比较次数不同，具体的就是转向左分支为一次，右分支的为两次，通过递归深度的不同，对转向成本的不均衡进行补偿，平均查找长度可以补偿
//实际上我们可以去fibonacci数黄金比例来确认切割点
template<class T>
int binsearch(vector<T>& v, const T& e, int low, int high)
{
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (e < v[mid])
		{
			high = mid;
		}
		else if (v[mid] < e)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//语义符合版--希望search返回的位置是不大于e的最后一个元素的位置pos，这样insert的位置pos+1
template<class T>
int binsearch3(vector<T>& v, const T& e, int low, int high)
{
	while (low < high)
	{
		int mid = (low + high) >> 1;
		(e < v[mid]) ? high = mid : low = mid + 1;
		
	}
	return --low;
}

void test05()
{
	vector<int> v = { 4, 7, 8, 32, 68,98 };
	int ret =  binsearch(v, 8, 0, v.size());
	cout << "find:     " << ret << endl;
}

void test06()
{
	vector<int> v = { 4, 7, 8, 32, 68,98 };
	int ret = binsearchRecur(v, 8, 0, v.size());
	cout << "find:     " << ret << endl;
}

void test07()
{
	vector<int> v = { 4, 7, 8, 8, 32, 68,98 };
	int ret = binsearch3(v, 8, 0, v.size());
	cout << "find:     " << ret << endl;
}
//冒泡排序1
template<typename T>
void bubbleSort1(vector<T>& v)
{
	for (int j = 0; j < v.size() - 1; j++)
	{
		for (int i = 0; i < v.size() - 1 - j; i++)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
			}
		}
	}
	
}
template<class T>
bool bubble(vector<T>& v, int low, int high)
{
	bool sorted = false;
	for (int i = low; i < high; i++)
	{
		if (v[i] > v[i+1])
		{
			sorted = true;
			swap(v[i], v[i + 1]);
		}
	}
	if (!sorted)
	{
		return true;
	}
	return false;
}

template<typename T>
void bubbleSort2(vector<T>& v, int low, int high)
{
	while (!bubble(v, low, high--));
}

//为什么此处不能用模板？？
void print(int t)
{
	cout  << t << ",";

}
void test08()
{
	vector<int> v = { 4,  8,68, 8, 32, 7,98 };
	bubbleSort1(v);
	for_each(v.begin(), v.end(), print);
}

void test09()
{
	vector<int> v = { 4,  8,68, 8, 32, 7,98 };
	bubbleSort2(v, 0, v.size() - 1);
	for_each(v.begin(), v.end(), print);
}
int main()
{
	//cout << test01() << endl;;
	//cout << test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	test09();
}