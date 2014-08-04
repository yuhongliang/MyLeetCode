#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;
		if(numRows<1)
			return result;

		vector<int> tmp_res(1,1);
		result.push_back(tmp_res);

		for(int i=1; i<numRows; i++)
		{
			tmp_res.clear();
			tmp_res.push_back(1);
			for(int j=0; j<i-1; j++)
			{
				tmp_res.push_back(result[i-1][j]+result[i-1][j+1]);
			}
			tmp_res.push_back(1);
			result.push_back(tmp_res);
		}
		return result;
	}
};

int main()
{
	Solution so;
	vector<vector<int>> ret = so.generate(2);
	for(int i=0; i<ret.size();i++)
	{
		for(int j=0; j<ret[i].size(); j++)
		{
			cout<<ret[i][j];
		}
		cout<<endl;
	}
	return 0;
}

