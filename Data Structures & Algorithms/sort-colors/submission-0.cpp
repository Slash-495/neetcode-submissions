class Solution {
public:
    int partition(vector<int> &nums,int low,int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
            }
            while(nums[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void qs(vector<int> &nums, int low,int high){
        if(low<high){
            int pi = partition(nums, low, high);
            qs(nums,low,pi-1);
            qs(nums,pi+1, high);
        }
    }
    vector<int> sortColors(vector<int>& nums) {
        qs(nums,0,nums.size()-1);
        return nums;
    }
};