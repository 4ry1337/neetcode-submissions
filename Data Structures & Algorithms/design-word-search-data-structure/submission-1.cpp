class TrieNode {
public:
    unordered_map<char, TrieNode*> mp;
    bool end;
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* head = root;
        for(char c : word) {
            if(head->mp.find(c) == head->mp.end()) {
                head->mp[c] = new TrieNode();
            }
            head = head->mp[c];
        }
        head->end = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* head = root;
        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(auto &[c, node] : head->mp) {
                    if(dfs(word, i + 1, node)) return true;
                }
                return false;
            } else {
                if(head->mp.find(c) == head->mp.end()) return false;
                head = head->mp[c];
            }
        }
        return head->end;
    }
};
