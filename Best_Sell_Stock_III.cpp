#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			const size_t n = prices.size();
			if(n < 2)
				return 0;

			vector<int> f(n, 0);
			int cur_min = prices[0];
			for(size_t i=1; i<n; i++)
			{
				f[i] = std::max(prices[i]-cur_min, f[i-1]);
				cur_min = std::min(cur_min, prices[i]);
			}

			vector<int> g(n,0);
			int cur_max =  prices[n-1];
			for(int i=n-2; i>=0; i--)
			{
				g[i] = std::max(g[i+1], cur_max-prices[i]);
				cur_max = std::max(cur_max, prices[i]);
			}

			int profit = 0;
			for(size_t i=0; i<n; i++)
			{
				profit = max(profit, g[i]+f[i]);
			}
			return profit;
		}
};

int main()
{
	Solution so;
	int a[]={2,9,1,2,8,4,5};
	vector<int> prices(a,a+sizeof(a)/sizeof(int));
	cout<<so.maxProfit(prices)<<endl;;
}
