class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2){
          return 0;
        }
        int buy = 0;
        int diff=0;
        for(int i=1;i<prices.size();i++)
        {
         if(prices[i]<prices[buy]){
            buy=i;
          }
          else if(diff<prices[i]-prices[buy]){
            diff=prices[i]-prices[buy];
          }
        }
        return diff;
    }
};