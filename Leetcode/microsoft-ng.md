#### Past OA

## Handmade Items Processing Time Calculator

#### Problem Statement

Given `N` clients who have ordered `N` handmade items, where the `K-th` client ordered exactly one item that takes `T[K]` hours to make. There is only one employee responsible for crafting these items, and their workflow is as follows:

1. Spend 1 hour making the first item.
2. If the item is finished, deliver it.
3. If the item is NOT finished, place it after ALL REMAINING ITEMS for further work.
4. The employee then proceeds to the next item in line.

The challenge is to calculate the total time that clients need to wait for all ordered items to be completed and delivered.

#### Example

Consider `T = [3, 1, 2]`, representing the hours needed to make each item for three different clients.

- The 1st item takes 3 hours to make.
- The 2nd item takes 1 hour.
- The 3rd item takes 2 hours.

#### Solution

```cpp
int timecalc(vector<int> T){
 	queue<int> wait;
  int total_time = 0;
  for(auto t : T) wait.push(t);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    cur -= 1;
    if(cur > 0) q.push(cur);
    total_time++
  }
  return total_time;
}
```

