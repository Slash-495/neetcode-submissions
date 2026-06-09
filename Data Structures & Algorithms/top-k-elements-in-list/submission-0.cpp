class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto &num : nums){
            mp[num]++;
        }
        for(auto &it: mp){
            int ele = it.first;
            int freq = it.second;
            bucket[freq].push_back(ele);
        }
        for(int i=n; i>=0; i--){
            if(bucket[i].size() == 0) continue;
            while(bucket[i].size()>0 && k>0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};
