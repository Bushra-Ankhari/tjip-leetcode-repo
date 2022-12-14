#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N)
///Space complexity O(1)

string decodeString (string s)
{
    stack<pair<string,int>>stk;
    stk.push({"", 1});
    int times = 0;

    for(auto c : s)
    {
        if(isdigit(c))
        {
            times = (times * 10) + (c - '0');
        }
        else if (c == '[')
        {
            stk.push({"", times});
            times = 0;
        }
        else if (c == ']')
        {
            int cnt = stk.top().second;
            string str = stk.top().first;
            stk.pop();
            while(cnt--)
            {
                stk.top().first += str;
            }
        }
        else
        {
            stk.top().first.push_back(c);
        }
    }
    return stk.top().first;
}

int main()
{
    string s="3[abc2[d]]";

    string res = decodeString(s);

    cout<<res<<endl;

    return 0;
}
