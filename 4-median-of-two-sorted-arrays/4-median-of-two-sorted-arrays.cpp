class Solution {
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
    double median = INT_MIN;
public:
    void addNum(int num) {
        if (leftHeap.size() == 0 && rightHeap.size() == 0) {
            leftHeap.push(num);
            median = num;
        } else if (leftHeap.size() > rightHeap.size()) {
            if (num < median) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            } else
                rightHeap.push(num);
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        } else if (leftHeap.size() == rightHeap.size()) {
            if (num < median) {
                leftHeap.push(num);
                median = leftHeap.top();
            } else {
                rightHeap.push(num);
                median = rightHeap.top();
            }
        } else {
            if (num > median) {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            } else
                leftHeap.push(num);
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto num: nums1)
            addNum(num);
        for (auto num: nums2)
            addNum(num);
        return median;
    }
};