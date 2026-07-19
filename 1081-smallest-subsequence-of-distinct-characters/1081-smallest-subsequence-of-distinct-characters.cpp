class Solution {
public:
    string smallestSubsequence(string s) {
        int lastOccurrence[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        vector<bool> inStack(26, false);
        string stack; // used as a stack, but string supports pop_back/back
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue; // already included, skip
            
            // Pop characters that are greater than current char,
            // but only if they appear later in the string again
            while (!stack.empty() && stack.back() > c && lastOccurrence[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            
            stack.push_back(c);
            inStack[c - 'a'] = true;
        }
        
        return stack;
    }
};