- [LeetCode 1. Two Sum](https://leetcode.com/problems/two-sum/) **[MED]**
  ```cpp
  vector<int> twoSum(vector<int>& nums, int target) {
     sort(nums.begin(), nums.end());
     int left = 0, right = nums.size() - 1;
     while(left < right){
         int sum = nums[left] + nums[right];
         if(sum == target) return {left, right};
         else if(sum > target) right--;
         else left++;
     }
     return {left, right};
  }
  ```
- [LeetCode 409. Longest Palindrome](https://leetcode.com/problems/longest-palindrome/) **[MED]**
  ```cpp
   int longestPalindrome(string s) {
       unordered_map<char, int> mp;
       int len = 0;
       bool foundsingle = false;
       
       for(auto c : s) mp[c]++;
   
       for(auto p : mp){
           len += (p.second / 2) * 2;
           if(p.second % 2 == 1) foundsingle = true;
       }
       return foundsingle ? len + 1 : len;
   }
   ```
- [LeetCode 146. LRU Cache (Use OrderedDict in Python)](https://leetcode.com/problems/lru-cache/)
- [LeetCode 128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) **[MED]**
  ```cpp
  int longestConsecutive(vector<int>& nums) {
     unordered_set<int> st(nums.begin(), nums.end());
     int maxLen = 0;
     for(int n : nums){
         if(st.find(n - 1) == st.end()){
             int curLen = 1;
             int curN = n;
             while(st.find(curN + 1) != st.end()){
                 curN++; 
                 curLen++;
             }
             maxLen = max(maxLen, curLen);
         }
     }
     return maxLen;
  }
  ```
- [LeetCode 380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) **[MED]**

  > All Operations Must Run in ```O(1)```
  ```cpp
  class RandomizedSet {
  public:
    unordered_map<int , int> mp; // val -> list index
    vector<int> list;        
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = list.size();
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int lastVal = list[list.size() - 1];
        int curIdx = mp[val];
        list[curIdx] = lastVal;
        mp[lastVal] = curIdx;
        list.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return list[rand() % list.size()];
    }
   };

  ```
- [LeetCode 49. Group Anagrams](https://leetcode.com/problems/group-anagrams/) **[MED]**
  
  **Time Complexity: ```O(NK)``` + Space Complexity : ```O(NK)```**
  ```cpp
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; 
        vector<vector<string>> res; 

        for(string w : strs) {
            vector<int> count(26, 0); 
            for(char c : w) count[c - 'a']++; 
            
            string key = "";
            for(int i = 0; i < 26; ++i) {
                key += string(count[i], 'a' + i);
            }
            mp[key].push_back(w); 
        }

        for(auto p : mp) res.push_back(p.second);
        
        return res;
  }
  ```
- [LeetCode 350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/) **[EASY]**

  **Time Complexity: ```O(N + M)``` + Space Complexity : ```O(min(N, M))```**
  ```cpp
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
     
     unordered_map<int, int> mp;
     for(auto n : nums1) mp[n]++;
   
     vector<int> res;
     for(auto n : nums2){
         if(mp.find(n) != mp.end()){
             res.push_back(n);
             mp[n]--;
             if(mp[n] == 0) mp.erase(n);
         }
     }
     return res;
  }
  ```
- [LeetCode 299. Bulls and Cows](https://leetcode.com/problems/bulls-and-cows/)
- [LeetCode 348. Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) [MED]
  ```cpp
  class TicTacToe {
  public:
       vector<int> rows;
       vector<int> cols;
       int diagonal = 0;
       int anti_diagonal = 0;
       int n;
       TicTacToe(int dim) {
           n = dim;
           rows = vector(n, 0);
           cols = vector(n, 0);
       }
       
       int move(int row, int col, int player) {
           int curpt = player == 1 ? 1 : -1;
           rows[row] += curpt;
           cols[col] += curpt;
           if(row == col) diagonal += curpt;
           if(n - row - 1== col) anti_diagonal += curpt;
   
           if(rows[row] == n || cols[col] == n || diagonal == n || anti_diagonal == n) return 1;
           else if(rows[row] == -n || cols[col] == -n || diagonal == -n || anti_diagonal == -n) return 2;
           else return 0;
       }
  };
  ```

Each link directs you to the problem statement and solution platform on LeetCode, facilitating easy access and practice.
