class LRUCache {
 private:
  struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  };

 private:
  int m_capacity;
  unordered_map<int, Node*> m_cache;
  Node* m_left;
  Node* m_right;

  void remove(Node* node) {
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  void insert(Node* node) {
    Node* prev = m_right->prev;
    prev->next = node;
    node->prev = prev;
    node->next = m_right;
    m_right->prev = node;
  }

 public:
  LRUCache(int capacity) : m_capacity(capacity) {
    m_cache.clear();
    m_left = new Node(0, 0);
    m_right = new Node(0, 0);
    m_left->next = m_right;
    m_right->prev = m_left;
  }

  int get(int key) {
    if (m_cache.find(key) != m_cache.end()) {
      Node* curr = m_cache[key];
      remove(curr);
      insert(curr);
      return curr->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (m_cache.find(key) != m_cache.end()) {
      remove(m_cache[key]);
    }
    Node* new_node = new Node(key, value);
    m_cache[key] = new_node;
    insert(new_node);
    if (m_cache.size() > m_capacity) {
      Node* lru = m_left->next;
      remove(lru);
      m_cache.erase(lru->key);
      delete lru;
    }
  }
};
