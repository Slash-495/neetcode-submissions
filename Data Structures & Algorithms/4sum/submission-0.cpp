class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Basic check: need at least 4 elements
        if (n < 4) {
            return result;
        }

        // The outer loop iterates up to n-4 (0-indexed) to ensure there are at least 3 elements after nums[i]
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // Pruning 1 (for 'i'): If smallest possible sum starting with nums[i] is already > target, break.
            // Smallest sum is nums[i] + nums[i+1] + nums[i+2] + nums[i+3]
            // Cast to long long to prevent potential overflow during sum calculation before comparison.
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            // Pruning 2 (for 'i'): If largest possible sum starting with nums[i] is already < target, continue.
            // Largest sum is nums[i] + nums[n-3] + nums[n-2] + nums[n-1]
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) {
                continue;
            }


            // The second loop iterates up to n-3 (0-indexed) to ensure there are at least 2 elements after nums[j]
            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                // Pruning 3 (for 'j'): If smallest possible sum with nums[i] and nums[j] is > target, break.
                // Smallest sum is nums[i] + nums[j] + nums[j+1] + nums[j+2]
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                // Pruning 4 (for 'j'): If largest possible sum with nums[i] and nums[j] is < target, continue.
                // Largest sum is nums[i] + nums[j] + nums[n-2] + nums[n-1]
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long current_sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (current_sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // Skip duplicates for left
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        // Skip duplicates for right
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (current_sum > target) {
                        right--;
                    } else { // current_sum < target
                        left++;
                    }
                }
            }
        }
        return result;
    }
};