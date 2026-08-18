class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int largest = nums[0];
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++;
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
        int big = -1;
        if(k==1){
            for(int j=0 ; j<n ; j++){
                if(nums[j]> big  &&  mp[nums[j]] == 1){
                    big = nums[j];
                }
            }
            return big;
        }
        else if(k==n){
            return largest;
        }
        else{
            if(mp[nums[0]] == 1 && mp[nums[n-1]]==1){
                if(nums[0]<nums[n-1]){
                    return nums[n-1];
                }else{
                    return nums[0];
                }
            }else if(mp[nums[0]] == 1){
                return nums[0];
            }else if(mp[nums[n-1]]==1){
                return nums[n-1];
            }
        }
        return -1;
    }
};