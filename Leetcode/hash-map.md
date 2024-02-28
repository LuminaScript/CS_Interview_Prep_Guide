-  **Two Sum** - [LeetCode 1](https://leetcode.com/problems/two-sum/)
-  **Longest Palindrome**  - [LeetCode 409](https://leetcode.com/problems/longest-palindrome/)
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
  
3. **LRU Cache** - [LeetCode 146](https://leetcode.com/problems/lru-cache/) (Use `OrderedDict` in Python)
4. **Longest Consecutive Sequence** - [LeetCode 128](https://leetcode.com/problems/longest-consecutive-sequence/)
5. **Set Matrix Zeroes** - [LeetCode 73](https://leetcode.com/problems/set-matrix-zeroes/)
6. **Insert Delete GetRandom O(1)** - [LeetCode 380](https://leetcode.com/problems/insert-delete-getrandom-o1/)
7. **Group Anagrams** - [LeetCode 49](https://leetcode.com/problems/group-anagrams/)
8. **Intersection of Two Arrays II** - [LeetCode 350](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
9. **Bulls and Cows** - [LeetCode 299](https://leetcode.com/problems/bulls-and-cows/)
10. **Design Tic-Tac-Toe** - [LeetCode 348](https://leetcode.com/problems/design-tic-tac-toe/)

Each problem link leads to the official LeetCode page
