class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        for(int i = 0; i < n.size(); i++) {
            heap.push({n[i], i});
            if (i >= k - 1) {
                while(heap.top().second <= i - k) {
                    heap.pop();
                }
                res.push_back(heap.top().first);
            }
        }
        return res;
    }
};
