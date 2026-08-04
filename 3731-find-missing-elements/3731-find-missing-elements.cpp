class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx = 0;
        int min = 100;
        unordered_map <int , int> map;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] > mx){
                mx = nums[i];
            }
            if(nums[i] < min){
                min = nums[i];
            }
            map.insert({nums[i], 1});   // ya fir    map[nums[i]] = 1
        }
        vector<int> ans(((mx - min)- nums.size())+1);
        int index = 0;
        for(int j=min ; j<=mx ; j++){
            if(map.find(j) == map.end()){
                ans[index] = j;
                index++;
            }
        }
        return ans;
    }
};