#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N)
///Space complexity O(N)

bool isValid(string s)
{
    stack<char>stk;
    for(auto c: s)
    {
        if(c=='[' || c=='{' || c=='(' )
        {
            stk.push(c);
        }
        else if(c=='}')
        {
            if(stk.empty() || !(stk.top()=='{'))
            {
                return false;
            }
            stk.pop();
        }
        else if(c==']')
        {
            if(stk.empty() || !(stk.top()=='['))
            {
                return false;
            }
            stk.pop();
        }
        else if(c==')')
        {
            if(stk.empty() || !(stk.top()=='('))
            {
                return false;
            }
            stk.pop();
        }
    }
    return (stk.empty());
}
int main()
{
    string s="){";
    bool res = isValid(s);

    cout<<res<<endl;

    return 0;
}
