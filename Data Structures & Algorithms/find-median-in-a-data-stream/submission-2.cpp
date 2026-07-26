class MedianFinder {
 private:
  priority_queue<int> pq;

 public:
  MedianFinder() {}

  void addNum(int num) { pq.push(num); }

  double findMedian() {
    priority_queue<int> temp = pq;
    int s = temp.size();
    for (int i{}; i < s / 2 - 1; ++i) temp.pop();
    if (s % 2 == 1) {
      temp.pop();
      return temp.top();
    }
    double m1 = temp.top();
    temp.pop();
    double m2 = temp.top();
    return (m1 + m2) / 2;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
