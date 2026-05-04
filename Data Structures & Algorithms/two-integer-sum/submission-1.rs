impl Solution {
pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut mp = HashMap::new();
    let target = target;
    for (i, n) in nums.iter().enumerate() {
        if let Some(k) = mp.get(n) {
            return vec![*k as i32, i as i32];
        };
        mp.insert(target - n, i);
    }
    vec![]
}
}
