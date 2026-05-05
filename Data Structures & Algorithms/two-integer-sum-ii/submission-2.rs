impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut l = 0;
        let mut r = numbers.len().saturating_sub(1);
        while numbers[l] + numbers[r] != target {
            if numbers[l] + numbers[r] < target {
                l = l.saturating_add(1);
            }
            if numbers[l] + numbers[r] > target {
                r = r.saturating_sub(1);
            }
        }
        vec![l as i32 + 1, r as i32 + 1]
    }
}
