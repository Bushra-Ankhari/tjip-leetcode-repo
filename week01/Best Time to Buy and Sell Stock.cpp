 /// Time Complexity O(n)
 /// Space Complexity O(1)

class Solution {
public:

int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int profit = 0;  
      int maxprof;
      int minsell = INT_MAX;
      for(int sell=0;sell<n;sell++){
            minsell = min(prices[sell],minsell);
            maxprof = prices[sell]-minsell;
            profit = max(profit,maxprof);
      }
      return profit;
    }
};


/// Time Complexity O(n)
/// Space Complexity O(n)

class Solution {
public:

int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int profit = 0;
      vector<int>mxprofsofar(n);
      mxprofsofar[n-1] = prices[n-1];
      for(int i=n-2; i>=0; i--){
            mxprofsofar[i]= max(prices[i],mxprofsofar[i+1]);

      }
     // for(auto i: mxprofsofar){
      //  cout<<i<<" ";
     // }
      for(int buy=0;buy<n;buy++){
            int maxprof = mxprofsofar[buy]-prices[buy];
            profit = max(profit,maxprof);
      }
      return profit;
    }

};
