#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			if(prices.empty())
				return 0;
			vector<int> dp(prices.size(),0);
			int cur_min = prices[0];
			for(size_t i=1; i<prices.size(); i++)
			{
				dp[i] = std::max(dp[i-1],prices[i]-cur_min);
				cur_min = std::min(cur_min, prices[i]);
			}
			return dp[prices.size()-1];
		}
};

int main()
{
	Solution so;
	int a[]={2,9,1,2,3,4,5};
	vector<int> prices(a,a+sizeof(a)/sizeof(int));
	cout<<so.maxProfit(prices)<<endl;;
}
