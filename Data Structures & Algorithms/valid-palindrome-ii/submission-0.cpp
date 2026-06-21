class Solution {
public:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i =0;
        int j= s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else if(isPalindrome(s, i, j-1)){
                j--;
            }
            else if(isPalindrome(s,i+1,j)){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};