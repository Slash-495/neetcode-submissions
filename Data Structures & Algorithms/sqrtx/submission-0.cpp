class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        if(x==0) return 0;
        if(x==1) return 1;
        long long ans = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            long long square = (long long)mid*mid;
            if(square == x){
                return mid;
            }
            else if(square <= x){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
