#include <iostream>
#include <vector>
#include <stack>
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
	    vector<int> preorderTraversal(TreeNode *root) 
		{
			vector<int> result;
			const TreeNode *p = root;
			stack<const TreeNode*> s;
			if(p) s.push(p);

			while(!s.empty())
			{
				p = s.top();
				s.pop();
				result.push_back(p->val);
				if(p->right) s.push(p->right);
				if(p->left) s.push(p->left);
			}
			return result;
		}
};

void printTree(TreeNode *root)
{
	Solution so;
	vector<int> ret;
   	ret	= so.postorderTraversal(root);
	for(size_t i=0; i<ret.size(); i++)
	{
		cout<<ret[i];
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
}
