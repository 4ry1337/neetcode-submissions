class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* head = root;
        for(auto c : word) {
            if(head->children.find(c) == head->children.end()) head->children[c] = new TrieNode();
            head = head->children[c];
        }
        head->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* head = root;
        for(char c : word) {
            if(head->children.find(c) == head->children.end()) return false;
            head = head->children[c];
        }
        return head->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* head = root;
        for(char c : prefix) {
            if(head->children.find(c) == head->children.end()) return false;
            head = head->children[c];
        }
        return true;
    }
};
