class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()){
            return 0;
        }
        int char_counts[26] = {0};
        int left = 0;
        int right = 0;
        int max_len = 0;
        int max_freq = 0;
        for(int right = 0; right<s.length(); ++right){
            char_counts[s[right]-'A']++;
            max_freq = max(max_freq,char_counts[s[right]-'A']);
            while((right-left+1)-max_freq>k){
                char_counts[s[left]-'A']--;
                    left++;
                }
            max_len = max(max_len,right-left+1);
        }
        return max_len;
    }
};