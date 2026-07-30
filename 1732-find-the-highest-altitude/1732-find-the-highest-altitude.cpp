class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max=0;
        int sum = 0;
        // vector<int> ans(n+1);
        for(int i=0;i<gain.size() ; i++){
            sum += gain[i];
            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};