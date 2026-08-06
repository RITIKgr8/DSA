class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n < (n+10)){
            int temp = n;
            int mul = 1;
            while(temp > 0){
                int d = temp % 10;
                mul = mul * d;
                temp = temp / 10;
            }
            if(mul % t == 0){
                return n;
            }else{
                n ++;
            }
        }
        return n;
    }
};