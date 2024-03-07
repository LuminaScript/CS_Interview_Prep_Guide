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
  
  
  Time O(4^N / sqrt(N)) + Space O(N) [_Explanation_](https://leetcode.com/problems/generate-parentheses/editorial/)
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
- [907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) 🟠 MEDIUM 🔵 Mono Stack 
  
  **Time O(N) + Space O(N)**
  ```cpp
  int sumSubarrayMins(vector<int>& arr) {
    int MOD = 1000000007;
    stack<int> stack;
    long minSum = 0;
    for(int i = 0; i <= arr.size(); i++){
        while(!stack.empty() && (i == arr.size() || arr[stack.top()] >= arr[i])){
            int mid = stack.top(); stack.pop();
            int leftBound = stack.empty() ? -1 : stack.top();
            int rightBound = i;
            long count = (mid - leftBound) * (rightBound - mid) % MOD;
            minSum += (count * arr[mid]) % MOD;
            minSum %= MOD;
        }
        stack.push(i);
    }
    return (int)minSum;
  }
  ```
- [Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) 🟠 MEDIUM 🔵 Mono Stack 
  ```cpp
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stack;
    vector<int> res(temperatures.size(), 0);
    for(int curDay = 0; curDay < temperatures.size(); curDay++){
        while(!stack.empty() && temperatures[stack.top()] < temperatures[curDay]){
            int prevDay = stack.top(); stack.pop();
            res[prevDay] = curDay - prevDay;
        }
        stack.push(curDay);
    }
    return res;
  }
  ```
- [Online Stock Span](https://leetcode.com/problems/online-stock-span/) 🟠 MEDIUM 🔵 Mono Stack
  
  **Time O(N) + Space O(N)**
  ```cpp
   stack<pair<int, int>> stack;
   StockSpanner() { }
   
   int next(int price) {
       int cnt = 1;
       while(!stack.empty() && stack.top().first <= price){
           cnt += stack.top().second;
           stack.pop();
       }
       stack.push({price, cnt});
       return cnt;
   }
  ```
- [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) 🟠 MEDIUM 🔵 Mono Stack

   **Time O(N) + Space O(N)**
  ```cpp
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stack;
    vector<int> res(nums.size(), -1);
    int n = nums.size();
    for(int curIdx = 0; curIdx < n * 2; curIdx++){
        int curVal = nums[curIdx % n];
        while(!stack.empty() && nums[stack.top()] < curVal){
            int prevIdx = stack.top(); stack.pop();
            res[prevIdx] = curVal;
        }
        stack.push(curIdx % n);
    }
    return res;
  }
  ```

### Queue
- [853. Car Fleet](https://leetcode.com/problems/car-fleet/)

  **Time O(N) + Space O(N)**
  ```cpp
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> nums; //position & speed
    for(int i = 0; i < position.size(); i++) nums.push_back({position[i], speed[i]});
    sort(nums.begin(), nums.end());
    for(auto p : nums)
        cout << "{" << p.first << ", " << p.second << "}, ";
    
    stack<double> stack;
    for(int i = nums.size() - 1; i >= 0; i--){
        double time = (target - nums[i].first) / (double)nums[i].second;
        if(stack.empty() || stack.top() < time) 
            stack.push(time); // since it will never catch up
    }
    return stack.size();
  }
  ```
