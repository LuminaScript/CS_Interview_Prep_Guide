class Solution {
public:
  /**
   * Given an array `nums` of n integers, returns an array of all the unique quadruplets
   * [nums[a], nums[b], nums[c], nums[d]] such that:
   *
   * 0 <= a, b, c, d < n
   * a, b, c, and d are distinct.
   * nums[a] + nums[b] + nums[c] + nums[d] == target
   *
   * @param nums - The input array of integers.
   * @param target - The target sum to achieve with quadruplets.
   * @return A vector of vector of integers containing unique quadruplets that sum to the target.
   *         The result can be in any order.
   */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n - 3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicate i values
            for(int j = i + 1; j < n - 2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;  // Skip duplicate j values
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j + 1, high = n - 1;
                while(low < high){
                    int sum = nums[low] + nums[high];
                    if (sum < newTarget)
                        low++;
                    else if (sum > newTarget)
                        high--;
                    else {
                        res.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) low++; // Skip duplicate low values
                        while (low < high && nums[high] == nums[high - 1]) high--; // Skip duplicate high values
                        low++;
                        high--;
                    }
                }
            }
        }
        return res;
    }
};
