class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curmin=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){   
            curmin=min(prices[i],curmin);
            profit=max(profit,prices[i]-curmin);
        }
        return profit;
    }
};