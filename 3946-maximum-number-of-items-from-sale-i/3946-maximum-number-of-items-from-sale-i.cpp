class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
        }

      
        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i != j &&
                    items[j][0] % items[i][0] == 0) {

                    freeCnt[i]++;
                }
            }
        }

     
        vector<int> dp(budget + 1, -1);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            int price = items[i][1];

            int gain = 1 + freeCnt[i];

            for (int j = budget; j >= price; j--) {

                if (dp[j - price] != -1) {

                    dp[j] = max(
                        dp[j],
                        dp[j - price] + gain
                    );
                }
            }
        }

       
        int ans = budget / minPrice;

        for (int spent = 0; spent <= budget; spent++) {

            if (dp[spent] == -1) {
                continue;
            }

            int remaining = budget - spent;

            int extra = remaining / minPrice;

            ans = max(ans, dp[spent] + extra);
        }

        return ans;
    }
};