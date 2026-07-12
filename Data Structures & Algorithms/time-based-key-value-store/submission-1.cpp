class TimeMap {
 private:
  unordered_map<string, vector<pair<int, string>>> m_data;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    m_data[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = m_data.find(key);
    if (it == m_data.end()) return "";
    auto& v = it->second;
    int base = 0, size = v.size();
    while (size > 1) {
      int half = size / 2;
      int mid = base + half;
      if (timestamp >= v[mid].first) {
        base = mid;
      }
      size -= half;
    }
    if (v[base].first > timestamp) return "";
    return v[base].second;
  }
};
