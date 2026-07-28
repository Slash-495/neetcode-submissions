class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        int s1_freq[26] = {0};
        int window_freq[26] = {0};

        int s1_len = s1.length();
        int s2_len = s2.length();
        for(char c : s1){
            s1_freq[c-'a']++;
        }
        auto compareArrays = [&](int arr1[], int arr2[]){
            for(int i=0; i<26; i++){
                if(arr1[i]!=arr2[i]){
                    return false;
                }
            }
            return true;
        };
        for(int i=0; i<s1_len; i++){
            window_freq[s2[i]-'a']++;
        }
        if(compareArrays(s1_freq,window_freq)) return true;
        for(int i = s1_len; i< s2_len; i++){
            window_freq[s2[i]-'a']++;
            window_freq[s2[i-s1_len]-'a']--;
            if(compareArrays(s1_freq, window_freq)){
                return true;
            }
        }
    return false;
    }
};