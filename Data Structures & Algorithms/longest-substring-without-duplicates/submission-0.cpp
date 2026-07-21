class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        unordered_set<char> char_set;
        int left = 0;
        int right = 0;
        int max_len = 0;
        while(right<s.length()){
            while(char_set.count(s[right])){
                char_set.erase(s[left]);
                left++;
            }
            char_set.insert(s[right]);
            max_len = max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};