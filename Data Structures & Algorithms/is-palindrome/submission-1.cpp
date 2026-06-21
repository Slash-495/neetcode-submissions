class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(),s.end(),[](char c){
            return !isalnum(c);
        }),s.end());
        for(char &c : s){
            c= tolower(c);
        }
        string r = s;
        reverse(r.rbegin(),r.rend());
        if(s==r){
            return true;
        }
        return false;
    }
};
