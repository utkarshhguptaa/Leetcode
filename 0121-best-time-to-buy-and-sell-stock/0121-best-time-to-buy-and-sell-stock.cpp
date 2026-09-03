class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};