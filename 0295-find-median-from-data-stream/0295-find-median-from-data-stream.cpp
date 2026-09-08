class MedianFinder {
    priority_queue<int> maxHeap;  
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        maxHeap.push(num);
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int x = maxHeap.top();
            maxHeap.pop();

            minHeap.push(x);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            int x = maxHeap.top();
            maxHeap.pop();

            minHeap.push(x);
        }
        else if (minHeap.size() > maxHeap.size()) {
            int x = minHeap.top();
            minHeap.pop();

            maxHeap.push(x);
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna