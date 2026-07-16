class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int t = a%b ;
            a = b;
            b=t;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd(nums.size());
        int high = 0;
        for(int i=0 ; i<nums.size() ; i++){
            high = max(high , nums[i]);
            prefixGcd[i] = gcd(high , nums[i]);
        }
        // now sort
        sort(prefixGcd.begin() , prefixGcd.end());
        long long output = 0;
        for(int j=0; j<(nums.size())/2 ; j++){
            output = output + gcd(prefixGcd[j] , prefixGcd[(nums.size()-1) - j]);
        }
        return output;
    }
};