class Solution {
public:
    // remove duplicates by copying each elements
    int removeDuplicates_slow(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int k = n;
        for(int i = 1; i < k;){
            if(nums[i] == nums[i - 1]) cnt++;
            else cnt = 0;
            if(cnt == 2){
                k--;
                if(i < n - 1){
                    for(int j = i; j < n - 1; j++) nums[j] = nums[j  + 1];
                }
                cnt--;
                continue;
            }
            i++;
        }
        return k;
        
    }

    // slow & fast pointer
    int removeDuplicates_fast(vector<int>& nums) {
        int j = 1;
        int cnt = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) cnt++;
            else cnt = 0;
            if(cnt < 2){
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

