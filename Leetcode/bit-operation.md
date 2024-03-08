- [67. Add Binary](https://leetcode.com/problems/add-binary/)
  ```cpp
  string addBinary(string a, string b) {
    string res;
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0){
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        carry = sum > 1 ? 1 : 0;
        res += to_string(sum % 2);
    }
    if(carry) res += to_string(carry);
    reverse(res.begin(), res.end());
    return res;
  }
  ```
- [136. Single Number](https://leetcode.com/problems/single-number) Medium
  ```c
  int singleNumber(int* nums, int numsSize) {
    uint32_t loner = 0;
    for(int i = 0; i <= 31; i++){
        uint32_t bitSum = 0;
        for(int j = 0; j < numsSize; j++){
            bitSum += (nums[j] >> i) & 1;
        }
        loner |= (bitSum % 2) << i;
    }
    return loner;
  }
  ```

- [137. Single Number II](https://leetcode.com/problems/single-number-ii) Medium
  ```c
  int singleNumber(int* nums, int numsSize) {
    uint32_t loner = 0;
    for(int i = 0; i < 32; i++) {
        uint32_t bitSum = 0;
        for(int j = 0; j < numsSize; j++) {
            bitSum += (nums[j] >> i) & 1;
        }
        loner |= (bitSum % 3) << i;
    }
    return loner;
  }
  ```
  
- [190. Reverse Bits](https://leetcode.com/problems/reverse-bits) Easy
  ```c
  uint32_t reverseBits(uint32_t n) {
      uint32_t rev = 0;
      for(int i = 31; i >= 0; i--){
          uint32_t lsb = n >> i & 0x1;
          rev |= lsb << (31 - i);
          n >> 1;
      }
      return rev;
  }
  ```
  
- [191. Numbers of 1 Bits](https://leetcode.com/problems/number-of-1-bits) Easy
  ```c
  int hammingWeight(uint32_t n) {
      int oneCnt = 0;
      for(int i = 0; i <= 31; i++){
          if((n >> i) & 1) oneCnt++;
      }
      return oneCnt;
  }
  ```

- [201. Bitwise And Of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range) Medium
  ```c
  int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    while(left < right){
        right >>= 1;
        left >>= 1;
        ++shift;
    }
    return left << shift;
  }
  ```
