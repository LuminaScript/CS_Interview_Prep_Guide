### Stack
- [20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) 🟢 EASY 🔵 Stack

  **Time O(N) + Space O(N)**
  ```cpp
  bool isValid(string s) {
    stack<char> stack;
    for(auto c: s){
        if(c == '(' || c == '[' || c == '{')
            stack.push(c);
        else{
            if(stack.empty()) return false;
            char top = stack.top();
            if(top == '(' && c != ')' || (top == '{' && c != '}')|| (top == '[' && c != ']')) 
                return false;
            stack.pop();
        }
    }
    return stack.empty();
  }
  ```
- [155. Min Stack](https://leetcode.com/problems/min-stack/) 🟠 MEDIUM 🔵 Stack
  
  **Time O(1) + Space O(N)**
  ```cpp
  ::stack<int> stack;
  ::stack<pair<int, int>> minstack;
  MinStack() { }
  
  void push(int val) {
      stack.push(val);
      if(minstack.empty() || val < minstack.top().first) minstack.push({val, 1});
      else if(val == minstack.top().first) minstack.top().second++;
  }
  
  void pop() {
      if(stack.top() == minstack.top().first) minstack.top().second--;
      if(minstack.top().second == 0) minstack.pop();
      stack.pop();
  }
  
  int top() {
      return stack.top();
  }
  
  int getMin() {
      return minstack.top().first;
  }
  ```
- [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) 🟠 MEDIUM 🔵 Stack

  **Time O(N) + Space O(N)**
  ```cpp
  bool isOP(string c){
      return c == "+" || c == "-" || c == "*" || c == "/";
  }
  int calc(int a, string c, int b){
      if(c == "+") return a + b;
      if(c == "-") return a - b;
      if(c == "*") return a * b;
      if(c == "/") return a / b;
      return 0; 
  } 
  int evalRPN(vector<string>& tokens) {
      stack<string> op;
      stack<int> num;
      for(auto i : tokens){
          if(isOP(i)){
              int n1 = num.top();
              num.pop();
              int n2 = num.top();
              num.pop();
              num.push(calc(n2, i, n1));
          }else{
              num.push(stoi(i));
          }
      }
      return num.top();
  }
  ```
- [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) 🟠 MEDIUM 🔵 Stack 🔵 Backtrace
  
   #### Time Complexity Analysis

  The time complexity of this algorithm primarily depends on the number of valid parentheses combinations, which is catalan number `C_n`. The n-th catalan number is given by the formula:
  
  ```[C_n = \frac{1}{n+1} \binom{2n}{n}\]```
  
  which is asymptotically approximated by:
  
  ```\[C_n \approx \frac{4^n}{n^{3/2}\sqrt{\pi}}\]```
  
  Hence, the time complexity of the algorithm can be described as `O(4^n / sqrt(n))`, considering the exponential growth of the catalan numbers with respect to `n`. This reflects the nature of the problem as the number of valid combinations      grows exponentially with the increase in the number of pairs `n`.
  
  #### Space Complexity
  
  The space complexity of the algorithm is also significant as it stores all valid combinations. In the worst case, the space required to store these combinations also grows exponentially, leading to a space complexity of `O(4^n / sqrt(n))`.     Additionally, the recursive call stack's depth will be at most `2n`, contributing a linear factor to the space complexity.

  ```cpp
  vector<string> res;
  int n;
  void backtrack(int left, int leftcnt, string w){
      if(w.size() == n * 2){
          res.push_back(w);
          return ;
      }
      if(left == 0 && leftcnt < n) {
          backtrack(left + 1, leftcnt + 1, w + "(");
      }else{
          if(leftcnt < n) backtrack(left + 1, leftcnt + 1, w + "(");
          backtrack(left - 1, leftcnt, w + ")");
      }
  }
  vector<string> generateParenthesis(int n) {
      this->n = n;
      backtrack(0, 0, "");
      return res;
  }
  ```

### Mono Stack
- [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
- [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
- [Sum of Subarray Minimums (similar to 84)](https://leetcode.com/problems/sum-of-subarray-minimums/)

### Mono Queue
- [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) 
- [Online Stock Span](https://leetcode.com/problems/online-stock-span/) 
- [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) 

### Queue
- [Car Fleet](https://leetcode.com/problems/car-fleet/) 
