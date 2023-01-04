#include<bits/stdc++.h>
using namespace std;

///Time complexity O(N*M)
///Space complexity O(1)

int strStr(string haystack, string needle)
{
    if(haystack.length()>=needle.length())
    {
        int flag = 1;
        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            flag = 1;
            for(int j=0; j<needle.length(); j++)
            {
                if (haystack[j+i] != needle[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                return i;
        }

        return -1;
    }
    return -1;
}



int main()
{
    string s="aaa", t="aaaa";
    int res = strStr(s,t);

    cout<<res<<endl;

    return 0;
}
