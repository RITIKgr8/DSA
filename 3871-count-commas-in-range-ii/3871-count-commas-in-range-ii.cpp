class Solution {
public:
    long long countCommas(long long n) {
        long long x = 1000;
        long long ans = 0;
        while(n>=x){
            ans += (n-x)+1;
            x = x*1000;
        }
        return ans;
    }
};