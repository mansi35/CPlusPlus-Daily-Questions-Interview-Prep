class Solution {
    priority_queue<int> leftheap;
    priority_queue<int, vector<int>, greater<int>> rightheap;
    double median = INT_MIN;
public:
    void addNum(int num) {
        if (leftheap.size() == 0 and rightheap.size() == 0) {
            leftheap.push(num);
            median = num;
        }
        else if (leftheap.size() > rightheap.size()) {
            if (num < median) {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(num);
            }
            else {
                rightheap.push(num);
            }
            median = (leftheap.top() + rightheap.top()) / 2.0;
        }
        
        else if (leftheap.size() == rightheap.size()) {
            if (num < median) {
                leftheap.push(num);
                median = leftheap.top();
            }
            else {
                rightheap.push(num);
                median = rightheap.top();
            }
        }
        else {
            if (num > median) {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(num);
            }
            else {
                leftheap.push(num);
            }
            median = (leftheap.top() + rightheap.top()) / 2.0;
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int num: nums1)
            addNum(num);
        for (int num: nums2)
            addNum(num);
        return median;
    }
};