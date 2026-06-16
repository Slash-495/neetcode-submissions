class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int threshold = n/3;
        for(auto e: mp){
            int element = e.first;
            int count = e.second;

            if(count>threshold){
                ans.push_back(element);
            }
        }
        return ans;
    }
};