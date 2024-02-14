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
- [Leetcode 240. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)

## Implicit Binary Search:

- [Leetcode 69. Sqrt(x)](https://leetcode.com/problems/sqrtx/)
- [Leetcode 540. Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
- [Leetcode 644. Maximum Average Subarray II](https://leetcode.com/problems/maximum-average-subarray-ii/)
- [Leetcode 528. Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight/)
- [Leetcode 1300. Sum of Mutated Array Closest to Target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)
- [Leetcode 1060. Missing Element in Sorted Array](https://leetcode.com/problems/missing-element-in-sorted-array/)
- [Leetcode 1062. Longest Repeating Substring](https://leetcode.com/problems/longest-repeating-substring/)
- [Leetcode 1891. Cutting Ribbons](https://leetcode.com/problems/cutting-ribbons/)
- [Leetcode 410. Split Array Largest Sum (similar to 1891)](https://leetcode.com/problems/split-array-largest-sum/)
