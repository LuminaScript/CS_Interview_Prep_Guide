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
