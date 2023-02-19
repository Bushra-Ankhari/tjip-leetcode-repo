///Time Complexity O(N)
///Space Complexity O(N) N= Number of char

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char>s;
        for(auto c: num)
        {
            while(!s.empty() && s.top() > c && k>0)
            {
                s.pop();
                k--;
            }
            if(!s.empty()|| c!='0')
                s.push(c);
        }

        while(!s.empty() && k)
        {
            s.pop();
            k--;
        }
        if(s.empty())
            return "0";

        string ans="";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        if (ans.length()==0)
            return "0";

        return ans;
    }
};
