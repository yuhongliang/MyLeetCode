#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for binary tree
struct TreeLinkNode {
     int val;
     TreeLinkNode *left;
     TreeLinkNode *right;
	 TreeLinkNode *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution 
{
	public:
		void connect(TreeLinkNode *root)
		{
			levelOrder(root);
		}
		void connect_r(TreeLinkNode* root)
		{
			connect_r(root, NULL);
		}
	private:
		void connect_r(TreeLinkNode *root, TreeLinkNode *righttree)
		{
			if(!root)
				return;
			else
				root->next = righttree;
			connect_r(root->left,root->right);
			if(righttree)
			{
				connect_r(root->right, righttree->left);
				connect_r(righttree->left, righttree->right);
			}

		}
	    void levelOrder(TreeLinkNode *root) 
		{
			if(!root)
				return ;
			queue<TreeLinkNode*> travQue[2];
			int index = 0;
			TreeLinkNode *p = root;
			travQue[index].push(p);
			while(!travQue[index].empty())
			{
				while(!travQue[index].empty())
				{
					p = travQue[index].front();
					travQue[index].pop();
					if(!travQue[index].empty())
						p->next = travQue[index].front();
					if(p->left)
						travQue[(index+1)%2].push(p->left);
					if(p->right)
						travQue[(index+1)%2].push(p->right);
				}
				index = (index+1)%2;
			}
		}
};

void printTree(TreeLinkNode *root)
{
	Solution so;
   	so.connect_r(root);
	TreeLinkNode *p = root;
	while(p)
	{
		TreeLinkNode *p_t = p;
		while(p_t)
		{
			cout<<p_t->val<<"-<";
			p_t = p_t->next;
		}
		p = p->left;
		cout<<endl;
	}
	cout<<endl;
}

void makeTree(TreeLinkNode *cur_node,size_t index, vector<int> &data)
{
	if(data[index]==-1)return;
	if(index*2<data.size() && data[2*index] != -1)
	{
		cur_node->left = new TreeLinkNode(data[2*index]);
		makeTree(cur_node->left, index*2, data);
	}
	if(index*2+1<data.size() && data[2*index+1] != -1)
	{
		cur_node->right = new TreeLinkNode(data[index*2+1]);
		makeTree(cur_node->right, index*2+1, data);
	}
}

int main()
{
	TreeLinkNode root(-1);
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> data;
	for(size_t i=0; i<sizeof(a)/sizeof(int); i++)
	{
		data.push_back(a[i]);
	}
	makeTree(&root, 1, data);
	printTree(&root);
	printTree(NULL);
}
