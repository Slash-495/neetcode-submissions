class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int res = 0;
        int m = 0;
        for(int n : nums){
            mp[n]++;
            if(mp[n]>m){
                res = n;
                m = mp[n];
            }
        }
    return res;
    }
};