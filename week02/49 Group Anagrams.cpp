#include<bits/stdc++.h>
using namespace std;
///Appraoch 3:
///Time complexity O(NK) where N=size of input vector and K is the size of biggest string
///Space complexity O(N)
static const int BASE = 997;
static const long long mod = 101103107109113LL;
long long gethash(string &s)
{
    long long H = 1;
    for(auto c : s)
    {
        H *=(BASE + c);
        if (H>=mod)
            H%=mod;
    }
    return H;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> ans;
    unordered_map<long long, vector<string>>mp;
    for(int i=0; i<strs.size(); i++)
    {
        string tmp = strs[i];
        long long has = gethash(strs[i]);
        if(mp.find(has) == mp.end())
        {
            vector<string> tmp2;
            mp.insert(make_pair(has, tmp2));
        }
        mp[has].push_back(strs[i]);
    }
    for(auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;

}

int main()
{
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for(auto i : res)
    {
        for(int j=0; j<i.size(); j++)
        {
            cout<<i[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
