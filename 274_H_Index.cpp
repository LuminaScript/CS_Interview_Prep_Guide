class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1, 0);
        for(auto c: citations){
            cnt[min(n, c)]++;
        }
        int k = n;
        for(int s = cnt[n]; k > s; s+= cnt[k]){
            k--;
        }
        return k;
   
