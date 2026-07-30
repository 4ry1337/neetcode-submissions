class WordDictionary {
 private:
  struct Node {
    unordered_map<char, Node*> next;
    bool is_end = false;
  };
  Node* root;

 public:
  WordDictionary() { root = new Node(); }

  void addWord(string word) {
    Node* curr = root;
    for (auto& c : word) {
      if (!curr->next.contains(c)) {
        curr->next[c] = new Node();
      }
      curr = curr->next[c];
    }
    curr->is_end = true;
  }

  bool search_mp(Node* node, string word) {
    for (size_t i{}; i < word.size(); ++i) {
      auto& c = word[i];
      if (c == '.') {
        for (auto& [ch, mp] : node->next) {
          if (search_mp(mp, word.substr(i + 1))) return true;
        }
      }
      if (!node->next.contains(c)) return false;
      node = node->next[c];
    }
    return node->is_end;
  }

  bool search(string word) { return search_mp(root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
