class Solution {
public:
    int maxLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int len = j - i + 1;

                // Case 1: Single element
                if (len == 1) {
                    if (nums[i] == 1) {
                        ans = max(ans, 1);
                    }
                    continue;
                }

                // Case 2: Two elements
                if (len == 2) {
                    ans = max(ans, 2);
                    continue;
                }

                // Case 3: Three or more elements
                bool valid = true;

                for (int a = i; a <= j; a++) {
                    for (int b = a + 1; b <= j; b++) {

                        if (gcd(nums[a], nums[b]) != 1) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) {
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};