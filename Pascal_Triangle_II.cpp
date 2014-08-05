#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> ret;
		for(int i=0; i<=rowIndex; i++)
		{
			for(int j=i-1; j>0;j--)
			{
				ret[j] = ret[j-1]+ret[j];
			}
			ret.push_back(1);
		}
		return ret;
	}
};

int main()
{
	Solution so;
	vector<int> ret = so.getRow(5);
	for(size_t i=0; i<ret.size();i++)
	{
		cout<<ret[i];
	}
	cout<<endl;
	return 0;
}

