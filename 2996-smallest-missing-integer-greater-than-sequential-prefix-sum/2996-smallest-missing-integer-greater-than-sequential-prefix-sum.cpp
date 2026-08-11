class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i=1;
        while(i<nums.size() && nums[i] == nums[i-1]+1){
            sum = sum + nums[i];
            i++;
        }
        unordered_set <int> mp(nums.begin() , nums.end());
        while(mp.find(sum) != mp.end()){
            sum++;
        }
        return sum;
    }
};