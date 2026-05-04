impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let hs: HashSet<i32> = nums.iter().cloned().collect();
        hs.len() != nums.len()
    }
}
