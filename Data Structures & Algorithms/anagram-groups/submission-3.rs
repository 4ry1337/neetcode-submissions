impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut mp: HashMap<[u8; 26], Vec<String>> = HashMap::new();
        strs.into_iter().for_each(|s| {
            let mut counter = [0u8; 26];
            s.bytes().for_each(|c| {
                counter[(c - b'a') as usize ] += 1;
            });
            mp.entry(counter).or_default().push(s);
        });
        mp.into_values().collect()
    }
}
