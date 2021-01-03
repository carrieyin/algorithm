#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<stdlib.h>

template<class T>
struct BinTreeNode
{
	BinTreeNode(const T& data)
		:_pleft(NULL)
		, _pright(NULL)
		, _data(data)
	{}
	BinTreeNode<T>* _pleft;
	BinTreeNode<T>* _pright;
	T _data;
};
template <class T>
class BinTree
{
	typedef BinTreeNode<T>* pNode;
	typedef BinTreeNode<T> Node;
public:
	BinTree()
		:root(NULL)
	{}
	//������������ǰ��
	BinTree(const T* array, size_t size, const T&invalid)//���캯��
	{
		size_t index = 0;
		CreateBinTree(root, array, size, index, invalid);
	}
	BinTree(const BinTree<T>& bt)//��������
	{
		root = CopyBinTree(bt.root);
	}
	BinTree<T>& operator=(const BinTree<T>& bt)//��ֵ���������
	{
		if (this != &bt)
		{
			root = CopyBinTree(bt.root);
		}
		return *this;
	}
	//����Ҫ�ú������
	void Destroy(pNode root)
	{
		if (NULL == root)
			return;
		Destroy(root->_pleft);
		Destroy(root->_pright);
		delete[] root;
		root = NULL;
	}
	~BinTree()//����
	{
		Destroy(root);
	}
	void PreOrder()
	{
		_PreOrder(root);
	}
	void InOrder()
	{
		_InOrder(root);
	}
	void PostOrder()
	{
		_PostOrder(root);
	}
	void LevelOrder()
	{
		_LevelOrder(root);
	}
	size_t Size()
	{
		return _Size(root);
	}
	size_t KSize(size_t k)
	{
		return _KSize(root, k);
	}
	size_t leaf()
	{
		return _leaf(root);
	}
	size_t Height()
	{
		return _Height(root);
	}
	pNode Find(const T& d)
	{
		return _Find(root, d);
	}
	pNode parent(pNode node)
	{
		return _parent(root, node);
	}
	pNode leftchild(pNode node)
	{
		return _leftchild(root, node);
	}
	pNode rightchild(pNode node)
	{
		return _rightchild(root, node);
	}
private:
	void CreateBinTree(pNode& root, const T* array, size_t size, size_t& index, const T&invalid)
	{
		if (index < size && invalid != array[index])
		{
			//���ڵ�
			pNode newNode = new Node(array[index]);
			CreateBinTree(newNode->_pleft, array, size, ++index, invalid);
			CreateBinTree(newNode->_pright, array, size, ++index, invalid);
			root = newNode;
		}
	}
	pNode CopyBinTree(pNode root)
	{
		pNode newroot = NULL;
		if (root)
		{
			newroot = new Node(root->_data);//���ڵ�
			if (root->_pleft)
			{
				newroot->_pleft = CopyBinTree(root->_pleft);//������
			}
			if (root->_pright)
			{
				newroot->_pright = CopyBinTree(root->_pright);//������
			}
		}
		return newroot;
	}
	void _PreOrder(pNode& root)//�ݹ�ǰ����������ڵ�+������+��������
	{
		if (root)
		{
			cout << root->_data << " ";
			_PreOrder(root->_pleft);
			_PreOrder(root->_pright);
		}
	}
	void _InOrder(pNode& root)//�ݹ����������������+���ڵ�+��������
	{
		if (root)
		{
			_InOrder(root->_pleft);
			cout << root->_data << " ";
			_InOrder(root->_pright);
		}
	}
	void _PostOrder(pNode& root)//�ݹ���������������+������+���ڵ㣩
	{
		if (root)
		{
			_PostOrder(root->_pleft);
			_PostOrder(root->_pright);
			cout << root->_data << " ";
		}
	}
	void _LevelOrder(pNode& root)//��α���
	{
		queue<pNode> q;
		if (root)
			q.push(root);
		while (!q.empty())
		{
			pNode pCur = q.front();
			q.pop();
			cout << pCur->_data << " ";
			if (pCur->_pleft)
				q.push(pCur->_pleft);
			if (pCur->_pright)
				q.push(pCur->_pright);
		}
		cout << endl;
	}
	size_t _Size(pNode root)//�ڵ�ĸ������õݹ飩
	{
		if (NULL == root)
			return 0;
		return _Size(root->_pleft) + _Size(root->_pright) + 1;
	}
	size_t _KSize(pNode root, size_t k)//����k��Ľڵ�ĸ���
	{
		if (NULL == root)
			return 0;
		if (k == 1)
			return 1;
		return _KSize(root->_pleft, k - 1) + _KSize(root->_pright, k - 1);
	}
	size_t _leaf(pNode root)//Ҷ�ӽڵ�ĸ���
	{
		if (NULL == root)
			return 0;
		if (NULL == root->_pleft && NULL == root->_pright)
			return 1;
		return _leaf(root->_pleft) + _leaf(root->_pright);
	}
	size_t _Height(pNode root)//�������ĸ߶�
	{
		if (NULL == root)
			return 0;
		if (NULL == root->_pleft && NULL == root->_pright)
			return 1;
		return _Height(root->_pleft) > _Height(root->_pright) ? _Height(root->_pleft) + 1 : _Height(root->_pright) + 1;
	}
	pNode _Find(pNode root, const T& d)//�ж�һ���ڵ��Ƿ��ڶ�������
	{
		if (root)
		{
			if (root->_data == d)
				return root;
			else
			{
				_Find(root->_pleft, d);
				_Find(root->_pright, d);
			}
		}
	}
	pNode _parent(pNode root, pNode node)//�Ҹ�ĸ�ڵ�
	{
		if (NULL == root || node == NULL || root == node)
			return NULL;
		if (node == root->_pleft || node == root->_pright)
			return root;
		if (root->_pleft)
			return _parent(root->_pleft, node);
		return _parent(root->_pright, node);
	}
	pNode _leftchild(pNode root, pNode node)//������
	{
		if (root == NULL || node == NULL)
			return NULL;
		if (root == node)
		{
			if (root->_pleft)
				return root->_pleft;
			return NULL;
		}
		if (root->_pleft)
			_leftchild(root->_pleft, node);
		if (root->_pright)
			_leftchild(root->_pright, node);


	}
	pNode _rightchild(pNode root, pNode node)//���Һ���
	{
		if (root == NULL || node == NULL)
			return NULL;
		if (root == node)
		{
			if (root->_pright)
				return root->_pright;
			return NULL;
		}
		if (root->_pleft)
			_rightchild(root->_pleft, node);
		if (root->_pright)
			_rightchild(root->_pright, node);
	}
private:
	pNode root;
};

template <class T>
struct TreeNode
{
	TreeNode(T da):leftchild(NULL), rightchild(NULL), data(da){}
	T data;
	TreeNode* leftchild;
	TreeNode* rightchild;
};
template<class T>
class BinaryTree
{
public:
	typedef TreeNode<T>* PTNODE;
	BinaryTree(T* array, int length)
	{
		createBinTree(array, length);
	}
	void preTraverse()
	{
		stack<TreeNode<T>* > s;
		s.push(rootNode);
		TreeNode<T>* node = rootNode;
		while (node != NULL || !s.empty())
		{
			if (node == NULL)
			{
				node = s.top();
				s.pop();
			}
			cout << node->data << " , ";
			node = node->leftchild;
			s.push(node->rightchild);
		}
	}

private:
	void createBinTree(T* array, int length) {
		
		int index = 0;
		createTree(rootNode, array, index, length);
		//CreateBinTree(rootNode, array, index, length, '#');

	}
	
	void createTree(PTNODE &pnode, T* array, int& index, int length)
	{
		if (index < length && array[index] != '#')
		{
			//�ǿյĽڵ�ֵ�������ڵ�
			
			TreeNode<T>* node = new TreeNode<T>(array[index]);
			//�������ӽڵ�
			createTree(node->leftchild, array, ++index, length);
			//�����Һ��ӽڵ�
			createTree(node->rightchild, array, ++index, length);
			pnode = node;
		}

	}

	TreeNode<T> *rootNode;
	
} ;

void test01()
{
	char pStr[] = { 'A','B','D','#','#','#','C','E','#','#','F' };
	BinaryTree<char> bt1(pStr, sizeof(pStr) / sizeof(pStr[0]));
	bt1.preTraverse();
}

void test02()
{
	char pStr[] = { 'A','B','D','#','#','#','C','E','#','#','F' };
	BinTree<char> bt1(pStr, sizeof(pStr) / sizeof(pStr[0]), '#');

	cout << "�ݹ�ǰ�������" << endl;
	bt1.PreOrder();
}
int main()
{
	test02();
	test01();
	
	cout << endl;
}