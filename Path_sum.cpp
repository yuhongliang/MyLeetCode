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
		bool hasPathSum(TreeNode *root, int sum)
		{
		    if(!root)
		       return false;
		    if(!root->left && !root->right)
		       return root->val == sum;
		    return hasPathSum(root->left, sum - root->val)
		          || hasPathSum(root->right, sum - root->val);
		}
};

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
	TreeNode root(-2);
	int a[] = {0,-1,-1,-3};
	vector<int> data;
	for(size_t i=0; i<sizeof(a)/sizeof(int); i++)
	{
		data.push_back(a[i]);
	}
	makeTree(&root, 1, data);
	Solution so;
	cout<<so.hasPathSum(&root,-5);
}
