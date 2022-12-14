#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N)
///Space complexity O(1)
static const int BASE = 997;
static const long long mod = 101103107109113LL;
long long gethash(string &s)
{
    long long H = 1; //__int128 H = 1;
    for(auto c : s)
    {
        H *=(BASE + c);
        if (H>=mod)
            H%=mod;
    }
    return H;
} // return long long (H);

bool isAnagram(string s, string t)
{
    return gethash(s) == gethash(t);
}

int main(){
    string s="nlcx", t="cxnl";
    cout<<isAnagram(s,t)<<endl;
return 0;
}
