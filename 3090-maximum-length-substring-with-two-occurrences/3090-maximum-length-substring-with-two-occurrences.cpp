class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int i=0;
        while(i<s.size()){
            unordered_map<char , int> mp;
            int count = 0;
            for(int j=i ; j<s.size() ; j++){
                mp[s[j]]++;
                if(mp[s[j]] > 2){
                    break;
                }
                count++;
            }
            if(count > ans){
                ans = count;
            }
            i++;
        }
        return ans;
    }
};