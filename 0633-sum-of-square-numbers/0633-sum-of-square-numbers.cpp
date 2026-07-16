class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0;
        long long r = sqrt(c);
        while(l<=r){
            long long check = (l*l) + (r*r);
            if(check == c){
                return true;
            }else if(check < c){
                l++;
            }else{
                r--;
            }
        }
        return false;
    }
};