class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        // Smallest power of two strictly greater than maxVal.
        // XOR of values < SIZE is always < SIZE.
        int SIZE = 1;
        while (SIZE <= maxVal) SIZE <<= 1;

        // Step 1: all achievable pairwise XORs (i <= j, repetition allowed)
        vector<char> pairXor(SIZE, 0);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                pairXor[nums[i] ^ nums[j]] = 1;

        // Step 2: XOR each achievable pair value with every element again
        vector<char> tripleXor(SIZE, 0);
        for (int v = 0; v < SIZE; v++) {
            if (!pairXor[v]) continue;
            for (int x : nums)
                tripleXor[v ^ x] = 1;
        }

        // Step 3: count unique triplet XOR values
        int ans = 0;
        for (int v = 0; v < SIZE; v++)
            ans += tripleXor[v];

        return ans;
    }
};