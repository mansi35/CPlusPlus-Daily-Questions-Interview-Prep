class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;
        int n = arr.size();
        if (n < 3)
            return false;
        while (arr[i] < arr[i + 1] and i < n - 1) {
            i++;
        }
        if (i == 0 or i == n - 1)
            return false;
        while (i < n - 1) {
            if (arr[i] <= arr[i + 1])
                return false;
            i++;
        }
        return true;
    }
};