class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    array<int, 26> ts;
    for (auto& task : tasks) ts[task - 'A']++;
    priority_queue<int> pq;
    for (int i{}; i < 26; ++i) {
      if (ts[i] > 0) pq.push(ts[i]);
    }
    int res = 0;
    queue<pair<int, int>> q;
    while (!pq.empty() || !q.empty()) {
      res++;
      if (pq.empty()) {
        res = q.front().second;
      } else {
        int cnt = pq.top() - 1;
        pq.pop();
        if (cnt > 0) {
          q.push({cnt, res + n});
        }
      }
      if (!q.empty() && q.front().second == res) {
        pq.push(q.front().first);
        q.pop();
      }
    }
    return res;
  }
};
