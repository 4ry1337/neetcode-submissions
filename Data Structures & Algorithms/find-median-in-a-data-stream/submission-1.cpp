class MedianFinder {
 private:
  priority_queue<int> pq;

 public:
  MedianFinder() {}

  void addNum(int num) { pq.push(num); }

  double findMedian() {
    priority_queue<int> temp = pq;
    size_t s = temp.size();
    if (s % 2 == 1) {
      for (int i{}; i < s / 2; ++i) temp.pop();
      return temp.top();
    } else {
      for (int i{}; i < s / 2 - 1; ++i) temp.pop();
      double m1 = temp.top();
      temp.pop();
      double m2 = temp.top();
      return (m1 + m2) / 2;
    }
  }
};
