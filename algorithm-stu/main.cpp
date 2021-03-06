#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
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
//冒泡排序1-最简版
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
	bool sorted = true;
	for (int i = low; i < high; i++)
	{
		if (v[i] > v[i+1])
		{
			sorted = false;
			swap(v[i], v[i + 1]);
		}
	}
	return sorted;
}

//冒泡排序算法2 比较过程中发现某一次排序全部都已经有序了，证明整个数组已经有序不需要再进行排序了
template<typename T>
void bubbleSort2(vector<T>& v, int low, int high)
{
	while (!bubble(v, low, high--));
}

//冒泡算法3，比较过程发现有一部分已经有序了，记住这个有序点，这部分下次不需要再进行比较
template<class T>
void bubbleSort3(vector<T>& v)
{
	int sortedLow = 0;
	for (int j = 0; j < v.size() - sortedLow; j++)
	{
		int sorted = 0;
		//sortedLow记录有序部分的最小的索引值，v.size() - sortedLow则为需要排序的区间
		for (int i = 0; ++i < v.size() - sortedLow; )
		{
			if (v[i - 1] > v[i])
			{
				sorted++;//这部分是记录无序部分的最大值
				swap(v[i - 1], v[i]);
			}
		}
		//更新sortedLow保持记录了有序部分的最小值
		sortedLow = sorted;
	}
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

void test10()
{
	vector<int> v = { 4,  8,68, 8, 32, 7,98 };
	bubbleSort3(v);
	for_each(v.begin(), v.end(), print);
}

//归并排序(向量和列表通用)
/*
分治策略
思想：
1.将待排序序列一分为二，时间o(1)
2.对于划分的子序列，分别递归排序
3.当子序列分别有序，合并有序子序列

以：4,  8,68, 8, 32, 7, 98为例
划分子序列[4, 8, 68, 8] [32, 7, 98]
划分子序列[4, 8][68, 8] [32, 7], [98]
划分子序列[4], [8],[68], [8], [32], [7], [98] 子序列有序
合并子序列[4, 8][8, 68] [7，32], [98]
合并子序列[4, 8，8, 68] [7，32, 98]
合并子序列[4, 7, 8，8, 32, 68, 98]
*/

void merge(int *a, int low, int mid, int high)
{
	int * A = a + low;
	int lb = mid - low;
	int * B = new int[lb];
	for (int i = 0; i < lb; i++)
	{
		B[i] = A[i];
	}
	int lc = high - mid;
	
	int * C = a + mid;
	//精简实现，因为C在A中，没有单独申请空间，所以当B合并完毕的时候，程序就可以结束,C不再拷贝
	/*for (int i = 0, j = 0, k = 0; (j < lb || k < lc);)
	{
		if ((j < lb) && ((lc <= k) || (B[j] <= C[k])))
		{
			A[i++] = B[j++];
		}
		if ((k < lc) && ((lb <= j) || (C[k] < B[j])))
		{
			A[i++] = C[k++];
		}
	}*/

	for (int i = 0, j = 0, k = 0; j < lb;)
	{
		//上面已经有j<lb判定可以删除重复的
		if ((lc <= k) || (B[j] <= C[k]))
		{
			A[i++] = B[j++];
		}
		//执行完B的合并，不再拷贝C
		if ((k < lc) && (C[k] < B[j]))
		{
			A[i++] = C[k++];
		}
	}

}

void mergeSort(int *a, int low, int high)
{
	if (high - low < 2)
	{
		return;
	}

    int mid = (high + low) >> 1;
	mergeSort(a, low, mid);
	mergeSort(a, mid, high);
	merge(a, low, mid, high);
}

void test11()
{
	int v[7] = { 4,  8, 68, 8, 32, 7,98 };
	mergeSort(v, 0, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << v[i] << endl;
	}
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
	//test09();
	//test10();
	test11();

}