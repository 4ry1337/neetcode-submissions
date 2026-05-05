impl Solution {
pub fn is_palindrome(s: String) -> bool {
    let bytes = s.as_bytes();
    let mut l = 0i32;
    let mut r = s.len() as i32 - 1;
    while l < r {
        while l < r && !bytes[l as usize].is_ascii_alphanumeric() {
            l += 1;
        }
        while l < r && !bytes[r as usize].is_ascii_alphanumeric() {
            r -= 1;
        }
        if bytes[l as usize].to_ascii_lowercase() != bytes[r as usize].to_ascii_lowercase() {
            return false;
        }
        l += 1;
        r -= 1;
    }
    true
}
}