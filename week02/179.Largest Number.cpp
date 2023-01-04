#include<bits/stdc++.h>
using namespace std;

///Time complexity O(NlogN)
///Space complexity O(N)

bool static compare(string a, string b){
   return (a+b>b+a)? true : false;
}
string largestNumber(vector<int>& nums)
{
    vector<string>str;
    string largest;
    for(auto x: nums)
    {
        str.push_back(to_string(x));
    }
    sort(str.begin(), str.end(), compare);
    for(auto x: str){
        largest+=x;
    }
    int i=0;
    for(; largest[i]=='0' && i<largest.size()-1;) i++;
    return largest.substr(i);
}

int main()
{
    vector<int>nums{3,30,34,9,5,4};
    string res = largestNumber(nums);

    cout<<res<<endl;

    return 0;
}
