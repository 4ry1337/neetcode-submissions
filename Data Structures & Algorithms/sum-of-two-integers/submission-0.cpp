class Solution {
 public:
  int getSum(int a, int b) {
    int res = 0;
    int carry = 0;
    for (int i = 0; i < 32; i++) {
      int bit_a = (a >> i) & 1;
      int bit_b = (b >> i) & 1;
      res |= ((bit_a ^ bit_b ^ carry) << i);
      carry = (bit_a + bit_b + carry) > 1;
    }
    return res;
  }
};
