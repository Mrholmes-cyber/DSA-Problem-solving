class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

       
        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        
        vector<int> total(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            for (int j = i; j <= n; j += i) {
                total[i] += freq[j];
            }
        }

       
        vector<pair<int, int>> offers;

        for (auto& item : items) {

            int factor = item[0];
            int price = item[1];

            int gain = total[factor] - 1;

            if (gain > 0 && 2LL * minPrice > price) {
                offers.push_back({price, gain});
            }
        }

    
        sort(offers.begin(), offers.end());

        long long ans = 0;
        long long remaining = budget;

       
        for (auto& offer : offers) {

            long long price = offer.first;
            long long gain = offer.second;

            long long take = min(gain, remaining / price);

            ans += 2 * take;

            remaining -= take * price;
        }

    
        ans += remaining / minPrice;

        return (int)ans;
    }
};