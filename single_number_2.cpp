#include <iostream>
using namespace std;

class Solution
{
    public:
	int singleNumber(int a[], int n)
	{
	    int c[32] = {0};
	    int ret = 0;
	    for(int i=0; i<32; i++)
	    {
		for(int j=0; j<n; j++)
		{
		    if((a[j]>>i) & 1)
		    {
			c[i]++;
		    }
		}
	    	ret |= (c[i]%3) << i;
	    }
	    return ret;
	}
};
int main()
{
    int case1[] = {1,1,1,2,3,3,3};
    Solution so;
    cout<<so.singleNumber(case1,sizeof(case1)/sizeof(int))<<endl;
}



