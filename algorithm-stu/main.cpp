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
int main()
{
	//cout << test01() << endl;;
	cout << test02();
}