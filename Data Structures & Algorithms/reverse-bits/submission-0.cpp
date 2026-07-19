class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = n;
    for (uint32_t i = 0; i < 16; i++) {
      bool right = res & (1 << i), left = res & (1 << (31 - i));
      if (right) res |= (1 << (31 - i));
      else res &= ~(1 << (31 - i));
      if (left) res |= (1 << i);
      else res &= ~(1 << i);
    }
    return res;
  }
};
