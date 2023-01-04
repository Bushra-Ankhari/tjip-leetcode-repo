#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N)
///Space complexity O(N)

vector<int> index_of[26];
bool is_subseq(string &wd)
{
    int last_index = -1;
    for(int i = 0; i<wd.size(); i++)
    {
        int ch = wd[i]-'a';
        auto it =lower_bound(index_of[ch].begin(),index_of[ch].end(),last_index+1);
        if(it ==index_of[ch].end())
            return false;
        last_index = *it;
    }
    return true;
}
int numMatchingSubseq(string s, vector<string>& words)
{
    for(int i=0; i<26; i++)
        index_of[i].clear();
    for(int i=0; i<s.size(); i++)
    {
        index_of[s[i]-'a'].push_back(i);
    }
    int matches = 0;
    for(auto &wd : words)
    {
        matches += is_subseq(wd);
    }
    return matches;
}
int main()
{
    string s = "abcde";
    vector<string>words{"a","bb","acd","ace"};

    int res = numMatchingSubseq(s,words);

    cout<<res<<endl;

    return 0;
}

