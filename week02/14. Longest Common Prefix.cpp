#include<bits/stdc++.h>
using namespace std;
///Appraoch 2:
///Time complexity O(NlogN) where N=size of input vector
///Space complexity O(1)
string longestCommonPrefix(vector<string>& strs)
{
    int len = strs.size();
    string res = "";
    sort(strs.begin(),strs.end());
    string first = strs[0];
    string last = strs[len-1];
    for(int i=0; i<first.size(); i++)
    {
        if(first[i] == last[i])
        {
            res+=first[i];
        }
        else
        {
            return res;
        }
    }
    return res;
}

int main()
{
    vector<string> strs{"dog","dig","deracecar","decar","dior"};
    string res = longestCommonPrefix(strs);

    cout<<res<<endl;

    return 0;
}
