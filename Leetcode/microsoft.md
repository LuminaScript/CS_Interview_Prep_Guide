- [273. Integer to English Words](https://leetcode.com/problems/integer-to-english-words/) - 30.5% Hard
  ```cpp
  #include <vector>
  #include <string>
  using namespace std;
  vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  vector<string> tentwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  #define one(num) (digits[(num)])
  #define twoLessThan20(num) (tentwenty[(num) - 10])
  #define ten(num) (tens[(num)])
  
  class Solution {
  public:
      string two(int num) {
          if (!num) return "";
          else if (num < 10) return one(num);
          else if (num < 20) return twoLessThan20(num);
          else {
              int tenner = num / 10;
              int rest = num % 10;
              if (rest) return ten(tenner) + " " + one(rest);
              else return ten(tenner);
          }
      }
  
      string three(int num) {
          int hundred = num / 100;
          int rest = num % 100;
          string res = "";
          if (hundred && rest) res = one(hundred) + " Hundred " + two(rest);
          else if (!hundred && rest) res = two(rest);
          else if (hundred && !rest) res = one(hundred) + " Hundred";
          return res;
      }
  
      string numberToWords(int num) {
          if (num == 0) return "Zero";
  
          int billion = num / 1000000000;
          int million = (num % 1000000000) / 1000000;
          int thousand = (num % 1000000) / 1000;
          int remainder = num % 1000;
          string result = "";
  
          if (billion) result += three(billion) + " Billion";
          if (million) {
              if (!result.empty()) result += " ";
              result += three(million) + " Million";
          }
          if (thousand) {
              if (!result.empty()) result += " ";
              result += three(thousand) + " Thousand";
          }
          if (remainder) {
              if (!result.empty()) result += " ";
              result += three(remainder);
          }
  
          return result;
      }
  };

  ```
- [146. LRU Cache](https://leetcode.com/problems/lru-cache/) - 42.2% Medium
- [1405. Longest Happy String](https://leetcode.com/problems/longest-happy-string/) - 57.3% Medium
- [1647. Minimum Deletions to Make Character Frequencies Unique](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/) - 61.2% Medium
- [1822. Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/) - 65.3% Easy
- [138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/) - 55.5% Medium
- [722. Remove Comments](https://leetcode.com/problems/remove-comments/) - 38.5% Medium
- [545. Boundary of Binary Tree](https://leetcode.com/problems/boundary-of-binary-tree/) - 45.1% Medium
- [1386. Cinema Seat Allocation](https://leetcode.com/problems/cinema-seat-allocation/) - 41.7% Medium
- [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) - 58.5% Medium
- [277. Find the Celebrity](https://leetcode.com/problems/find-the-celebrity/) - 47.0% Medium
- [186. Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/) - 54.3% Medium
- [1448. Count Good Nodes in Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/) - 73.2% Medium
- [1239. Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/) - 54.1% Medium
- [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) - 48.8% Medium
- [1304. Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) - 76.3% Easy
- [348. Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) - 57.9% Medium
- [297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) - 56.5% Hard
- [253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) - 51.0% Medium
- [165. Compare Version Numbers](https://leetcode.com/problems/compare-version-numbers/) - 36.7% Medium
- [428. Serialize and Deserialize N-ary Tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/) - 66.7% Hard
- [218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/) - Hard
