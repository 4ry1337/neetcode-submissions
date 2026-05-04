impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut mp: HashMap<[u8; 26], Vec<String>> = HashMap::new();
        strs.iter().for_each(|str| {
            let mut counter = [0u8; 26];
            str.bytes().for_each(|c| {
                counter[(c - b'a') as usize ] += 1;
            });
            mp.entry(counter).or_insert_with(Vec::new).push(str.clone());
        });
        mp.into_values().collect()
    }
}
