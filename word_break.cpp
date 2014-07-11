#include <iostream>
#include <unordered_set>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict)
        {
                if(dict.size() == 0)
                        return false;
                const int len = 1+s.size();
                bool f[len];
                memset(f,false,sizeof(bool)*len);
                f[0]=true;
                for(int i=1; i<len; i++)
                        for(int j=i-1; j>=0; j--)
                        {

                                if(f[j] && dict.find(s.substr(j,i-j))!=dict.end())
                                {
                                        f[i] = true;
                                        break;
                                }
                        }
                return f[len-1];
        }
};

int main()
{
	Solution so;
	string s = "abcdef";
	cout<<s<<endl;
	string tmp;
	unordered_set<string> dict;
	while(cin>>tmp)
	{
		dict.insert(tmp);
	}
	cout<<so.wordBreak(s,dict)<<endl;
}
