#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
	public:
	    vector< vector<int> > levelOrder(TreeNode *root) 
		{
			vector<vector<int>> result;
			if(!root)
				return result;
			queue<TreeNode*> travQue[2];
			int index = 0;
			TreeNode *p = root;
			travQue[index].push(p);
			while(!travQue[index].empty())
			{
				vector<int> levRest;
				while(!travQue[index].empty())
				{
					p = travQue[index].front();
					travQue[index].pop();
					levRest.push_back(p->val);
					if(p->left)
						travQue[(index+1)%2].push(p->left);
					if(p->right)
						travQue[(index+1)%2].push(p->right);
				}
				index = (index+1)%2;
				result.push_back(levRest);
			}
			return result;
		}
};

void printTree(TreeNode *root)
{
	Solution so;
	vector<vector<int>> ret;
   	ret	= so.levelOrder(root);
	for(size_t i=0; i<ret.size(); i++)
	{
		vector<int> leveRest = ret[i];
		for(size_t j=0; j<leveRest.size(); j++)
		{
			cout<<leveRest[j];
		}
		cout<<endl;
	}
	cout<<endl;
}

void makeTree(TreeNode *cur_node,size_t index, vector<int> &data)
{
	if(data[index]==-1)return;
	if(index*2<data.size() && data[2*index] != -1)
	{
		cur_node->left = new TreeNode(data[2*index]);
		makeTree(cur_node->left, index*2, data);
	}
	if(index*2+1<data.size() && data[2*index+1] != -1)
	{
		cur_node->right = new TreeNode(data[index*2+1]);
		makeTree(cur_node->right, index*2+1, data);
	}
}

int main()
{
	TreeNode root(-1);
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
