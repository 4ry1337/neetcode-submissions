impl Solution {
pub fn length_of_longest_substring(s: String) -> i32 {
    let bytes = s.as_bytes();

    let mut res = 0;

    let mut l = 0;
    let mut mp = HashSet::new();

    for r in 0..bytes.len() {
        while l < r && mp.contains(&bytes[r]) {
            mp.remove(&bytes[l]);
            l += 1;
        }
        mp.insert(bytes[r]);
        res = res.max(mp.len());
    }

    res as i32
}
}
