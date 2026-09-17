class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n, INF);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int ans = INF;
        int minLen = INF;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(mp.find(sum - target) != mp.end()) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                if(start > 0 && best[start - 1] != INF) {
                    ans = min(ans, best[start - 1] + len);
                }

                minLen = min(minLen, len);
            }

            best[i] = minLen;
            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};