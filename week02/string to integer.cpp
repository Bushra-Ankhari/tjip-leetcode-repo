#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N)
///Space complexity O(1)
int myAtoi(string str)
{
    long long res=0;
    int i=0;
    while(i<str.size()&&str[i]==' ')
        i++;
    bool neg=false;
    if(str[i]=='-')
        neg=true,i++;
    else if(str[i]=='+')
        i++;
    while(i<str.size()&&isdigit(str[i]))
    {
        res=res*10+str[i++]-'0';
        if(res>INT_MAX)
            return neg?INT_MIN:INT_MAX;
    }
    return neg?-res:res;
}

int main()
{
    string s = "4193 with words";
    int res = myAtoi(s);

    cout<<res<<endl;

    return 0;
}
