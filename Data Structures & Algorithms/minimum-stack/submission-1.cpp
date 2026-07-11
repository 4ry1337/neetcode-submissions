class MinStack {
 private:
  stack<pair<int, int>> m_data;

 public:
  MinStack() {}

  void push(int val) {
    m_data.push({val, !m_data.empty() ? min(m_data.top().second, val) : val});
  }

  void pop() { m_data.pop(); }

  int top() { return m_data.top().first; }

  int getMin() { return m_data.top().second; }
};
