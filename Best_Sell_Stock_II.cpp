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
			int profit = 0;
			for(size_t i=1; i<prices.size(); i++)
			{
				if(prices[i] - prices[i-1] > 0)
				{
					profit+=prices[i]-prices[i-1];
				}
			}
			return profit;
		}
};

int main()
{
	Solution so;
	int a[]={2,9,1,2,3,4,5};
	vector<int> prices(a,a+sizeof(a)/sizeof(int));
	cout<<so.maxProfit(prices)<<endl;;
}
