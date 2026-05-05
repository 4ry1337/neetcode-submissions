impl Solution {
pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let k = k as usize;
    let mut bucket = vec![vec![]; nums.len() + 1];
    let mut mp = std::collections::HashMap::new();
    nums.into_iter().for_each(|n| {
        *mp.entry(n).or_insert(0usize) += 1;
    });
    mp.iter().for_each(|(&num, &cnt)| {
        bucket[cnt].push(num);
    });

    let mut res = Vec::new();
    (1..bucket.len()).rev().for_each(|i| {
        bucket[i].iter().for_each(|&num| {
            if res.len() == k {
                return;
            }
            res.push(num);
        })
    });
    res
}

}
