///Time complexity O(n)
///Space complexity O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int Profit = 0;
     for (int i=1; i<prices.size(); i++)
        {
            if (prices[i]>prices[i-1]){
                Profit += (prices[i] - prices[i-1]);
        }
    }
    return Profit; }

};
