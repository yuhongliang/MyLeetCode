#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution 
{
	public:
	    bool isValid(string s) 
		{
			string left = "([{";
			string right = ")]}";
			stack<char> stk;

			for(size_t i=0; i<s.size(); i++)
			{
				auto c=s[i];
				if(left.find(c) != string::npos)
					stk.push(c);
				else if(stk.empty() || stk.top()!=left[right.find(c)])
					return false;
				else
					stk.pop();
			}
			return stk.empty();
	    }
};

int main()
{
	string s = "()]{}";
	Solution so;
	cout<<so.isValid(s)<<endl;
	return 0;
}
