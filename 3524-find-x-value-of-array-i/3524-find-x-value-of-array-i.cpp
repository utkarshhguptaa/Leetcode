class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);

        for (int num : nums) {
            int mod = num % k;
            vector<long long> newDp(k, 0);

            newDp[mod] = 1;

            for (int r = 0; r < k; r++) {
                int newMod = (r * mod) % k;
                newDp[newMod] += dp[r];
            }

            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};