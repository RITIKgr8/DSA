class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int l = 0;
        int count = 0;
        // sliding window
        for(int r=0 ; r<nums.size() ; r++){
            mp[nums[r]] = mp[nums[r]] + 1;       // or mp[nums[r]]++
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            count = max(count, (r-l) + 1);
        }
        return count;
    }
};