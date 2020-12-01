#define  _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

//�������������
/*���� 6�� 56�� 2�� 7�� 23�� 8�� 5�� 8���Ϊ4*/
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

//��������е��㷨������������ȡ�����
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

//������֮
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

//�ֶ���֮
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

//����Ԫ��-����1 ���ֲ���--�ݹ�
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
//�汾1�����ҳ��ȼ����ؼ���ıȽϴ����� ���ҳɹ��Ͳ���ʧ�ܵıȽϴ������Լ�ƽ�������ܣ���Ϊ�㷨������������o(logn)
//����Ԫ��-����1 ���ֲ���--����
//�Ż���-��ʵ�֣������������ǲ��ҳɹ���ʧ�ܱȽϵĵݹ��������ͬ�ģ����ǹؼ���ıȽϴ�����ͬ������ľ���ת�����֧Ϊһ�Σ��ҷ�֧��Ϊ���Σ�ͨ���ݹ���ȵĲ�ͬ����ת��ɱ��Ĳ�������в�����ƽ�����ҳ��ȿ��Բ���
//ʵ�������ǿ���ȥfibonacci���ƽ������ȷ���и��
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

//������ϰ�--ϣ��search���ص�λ���ǲ�����e�����һ��Ԫ�ص�λ��pos������insert��λ��pos+1
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
//ð������1
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

//Ϊʲô�˴�������ģ�壿��
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