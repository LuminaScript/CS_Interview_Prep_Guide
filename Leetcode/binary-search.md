# Basic Knowledge

Binary search is a fundamental technique with a time complexity of O(logN). Common binary search problems can be categorized into explicit and implicit types.

## Explicit Binary Search:

- [Leetcode 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
  ```cpp
  int findBound(vector<int>& nums, int target, bool isLower){
      int n = nums.size();
      int left = 0, right = n - 1;
      while(left <= right){
          int mid = left + (right - left) / 2;
          int mid_val = nums[mid];
          if(mid_val == target){
              if(isLower){
                  if(mid == 0 || (mid - 1 >= 0 && nums[mid - 1] < target)){
                      return mid;
                  }else{
                      right = mid - 1;
                  }
              }else{
                  if(mid == n - 1 || (mid + 1 < n && nums[mid + 1] > target)){
                      return mid;
                  }else{
                      left = mid + 1;
                  }
              }
          }
          else if(mid_val < target){
              left = mid + 1;
          }else{
              right = mid - 1;
          }
      }
      return -1;
  }
     
  vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> res(2, -1);
      int n = nums.size();
      if(n == 0) return res;
      res[0] = findBound(nums, target, true);
      res[1] = findBound(nums, target, false);
      return res;
  }
  ```
- [Leetcode 33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
  ```cpp
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return mid;
        if(nums[left] <= nums[mid]){ // left is sorted
            if(target < nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }else{ // right is sorted
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid -1 ;
        }
    }
    return -1;
  }
  ```
- [Leetcode 1095. Find in Mountain Array](https://leetcode.com/problems/find-in-mountain-array/)
  ```cpp
  int findInMountainArray(int target, MountainArray &mountainArr) {
      int peak = findPeak(mountainArr);
      int index = binarySearchAsc(mountainArr, 0, peak, target);
      if (index != -1) {
          return index;
      }
      return binarySearchDesc(mountainArr, peak + 1, mountainArr.length() - 1, target);
  }

  int findPeak(MountainArray &mountainArr) {
      int left = 0, right = mountainArr.length() - 1;
      while (left < right) {
          int mid = left + (right - left) / 2;
          if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
              // Ascending part
              left = mid + 1;
          } else {
              // Descending part
              right = mid;
          }
      }
      return left;
  }

  int binarySearchAsc(MountainArray &mountainArr, int left, int right, int target) {
      while (left <= right) {
          int mid = left + (right - left) / 2;
          int midVal = mountainArr.get(mid);
          if (midVal == target) {
              return mid;
          } else if (midVal < target) {
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }
      return -1;
  }

  int binarySearchDesc(MountainArray &mountainArr, int left, int right, int target) {
      while (left <= right) {
          int mid = left + (right - left) / 2;
          int midVal = mountainArr.get(mid);
          if (midVal == target) {
              return mid;
          } else if (midVal > target) {
              left = mid + 1;
          } else {
              right = mid - 1;
          }
      }
      return -1;
  }

  ```
- [Leetcode 162. Find Peak Element](https://leetcode.com/problems/find-peak-element/)

  **Solution 1(Smartest)**
  ```cpp
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < nums[mid + 1]) left = mid + 1;
        else right = mid;
    }
    return left;
  }
  ```

  **Solution 2**
  ```cpp
  int findPeakElement(vector<int>& nums) {
      int n = nums.size(); 
      int left = 0, right = n - 1;
      while(left < right){
          int mid = left + (right - left) / 2;
          int mid_val = nums[mid];
          if((mid == 0 || mid_val >= nums[mid - 1]) && (mid >= n - 1 || (mid_val >= nums[mid + 1]))){
              return mid;
          }
          if(mid == 0 || mid == n - 1){
              mid == 0 ? left = 1 : right = n - 2;
              continue;
          }
  
          else if(mid_val <= nums[mid - 1]){
              right = mid - 1;
          }else{
              left = mid + 1;
          }
      }
      return left;
  }
  ```


- [Leetcode 278. First Bad Version](https://leetcode.com/problems/first-bad-version/)
  ```cpp
  int firstBadVersion(int n) {
      int left = 1, right = n;
      while(left <= right){
          int mid = left + (right - left) / 2;
          if(!isBadVersion(mid)) left = mid + 1;
          else right = mid - 1;
      }
      return left;
  }
  ```
- [Leetcode 74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)
  ```cpp
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty() || matrix[0].empty()) return false;

      int row = 0;
      int col = matrix[0].size() - 1;

      while (row < matrix.size() && col >= 0) {
          if (matrix[row][col] == target) {
              return true;
          } else if (matrix[row][col] > target) {
              // Move left
              col--;
          } else {
              // Move down
              row++;
          }
      }

      return false;
  }

  ```
- [Leetcode 240. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)
  ```cpp
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int row = 0;
    int col = matrix[0].size() - 1;
    
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    
    return false;
  }
  ```

## Implicit Binary Search:

- [Leetcode 69. Sqrt(x)](https://leetcode.com/problems/sqrtx/)
  ```cpp
  int mySqrt(int x) {
    if(x < 2) return x;
    int left = 2, right = x / 2;
    while(left <= right){
        int mid = (left + right) / 2;
        long y = (long)mid * mid;
        if(y < x) left = mid + 1;
        else if( y > x) right = mid - 1;
        else return mid;
    }
    return right;
  }
  ```
- [Leetcode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
  ```cpp
  int singleNonDuplicate(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      while(left < right){
          int mid = (left + right) / 2;
          if(mid % 2 == 1) mid--;
          if(nums[mid] != nums[mid+1]) right = mid;
          else left = mid + 2;
      }
      return nums[left];
      
  }
  ```
- [Leetcode 644. Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/)

  Detailed Solution Explanation: https://leetcode.com/problems/maximum-average-subarray-ii/solutions/4732642/c-bs-great-detailed-explanation

  ```cpp
  bool check(vector<int>& nums, double mid, int k){
      double sum = 0, prev = 0, min_sum = 0;
      for(int i = 0; i < k; i++){
          sum += nums[i] - mid;
      }
      if(sum >= 0) return true;
      for(int i = k; i < nums.size(); i++){
          sum += nums[i] - mid;
          prev += nums[i - k] - mid;
          min_sum = min(prev, min_sum);
          if(sum >= min_sum) return true;
      }
      return false;
  }
  double findMaxAverage(vector<int>& nums, int k) {
      double max_val = INT_MIN, min_val = INT_MAX;
      for(auto n : nums){
          max_val = max_val > n ? max_val : n;
          min_val = min_val < n ? min_val : n;
      }
      double prev_mid = max_val, error = INT_MAX;
      while(error > 0.00001){
          double mid = (max_val + min_val) * 0.5;
          if(check(nums, mid, k)) min_val = mid;
          else max_val = mid;
          error = abs(prev_mid - mid);
          prev_mid = mid;
      }
      return min_val;
  }
  ```
- [Leetcode 528. Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)
- [Leetcode 1300. Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)
- [Leetcode 1060. Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/)
- [Leetcode 1062. Longest Repeating Substring](https://leetcode.com/problems/longest-repeating-substring/)
- [Leetcode 1891. Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons/)
- [Leetcode 410. Split Array Largest Sum (similar to 1891)](https://leetcode.com/problems/split-array-largest-sum/)
