class MedianFinder {
 private:
  priority_queue<int, vector<int>, less<int>> lesser;
  priority_queue<int, vector<int>, greater<int>> greater;

 public:
  MedianFinder() {}

  void addNum(int num) {
    lesser.push(num);
    if (!greater.empty() && lesser.top() > greater.top()) {
      greater.push(lesser.top());
      lesser.pop();
    }
    if (lesser.size() > greater.size() + 1) {
      greater.push(lesser.top());
      lesser.pop();
    }
    if (greater.size() > lesser.size() + 1) {
      lesser.push(greater.top());
      greater.pop();
    }
  }

  double findMedian() {
    if (lesser.size() == greater.size()) {
      return (lesser.top() + greater.top()) / 2.0;
    } else if (lesser.size() > greater.size()) {
      return lesser.top();
    } else {
      return greater.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
