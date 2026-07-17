class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[d] = count of numbers divisible by d
        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cnt[d] += freq[j];
        }

        // gcdPairs[d] = number of pairs whose gcd is exactly d
        vector<long long> gcdPairs(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            gcdPairs[d] = cnt[d] * (cnt[d] - 1) / 2;
            for (int j = d * 2; j <= mx; j += d)
                gcdPairs[d] -= gcdPairs[j];
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            prefix[d] = prefix[d - 1] + gcdPairs[d];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};