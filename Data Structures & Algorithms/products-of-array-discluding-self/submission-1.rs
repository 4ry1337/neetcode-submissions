impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut pre = 1;
        let mut suf = 1;
        let mut res = vec![1; nums.len()];
        for i in  0..nums.len() {
            let left = i;
            let right = (nums.len() - 1) - i;
            res[left] *= pre;
            res[right] *= suf;
            pre *= nums[left];
            suf *= nums[right];
        }
        res
    }
}
