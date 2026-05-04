impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let mut hs = HashMap::new();
        let mut ht = HashMap::new(); 
        s.chars().for_each(|c| { 
            *hs.entry(c).or_insert(0) += 1;
        });
        t.chars().for_each(|c| {
            *ht.entry(c).or_insert(0) += 1;
        });
        hs == ht
    }
}
