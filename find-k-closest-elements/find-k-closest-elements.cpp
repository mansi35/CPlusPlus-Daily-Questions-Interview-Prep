class Solution {
public:
    int binarySearch(vector<int> arr, int low, int high, int x) {
        if (arr[high] <= x)
            return high;
        if (arr[low] > x)
            return low;
        int mid = (low + high)/2;
        if (arr[mid] <= x && arr[mid+1] > x)
            return mid;
        if(arr[mid] < x)
            return binarySearch(arr, mid+1, high, x);

        return binarySearch(arr, low, mid - 1, x);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = binarySearch(arr, 0, n-1, x);
        int r = l+1;
        vector<int> result;
        int count = 0;
        if (arr[l] == x) {
            result.push_back(arr[l--]);
            count++;
        }
        while (l >= 0 && r < n && count < k) {
            if (x - arr[l] <= arr[r] - x)
                result.push_back(arr[l--]);
            else
                result.push_back(arr[r++]);
            count++;
        }
        while (count < k && l >= 0) {
            result.push_back(arr[l--]);
            count++;
        }
        while (count < k && r < n) {
            result.push_back(arr[r++]);
            count++;
        }
        sort(result.begin(), result.end());
        return result;
    }
};