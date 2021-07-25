class Solution {
public:
    bool canSplit(vector<int> &sweetness, int K, int mid) {
        int chunks = 0, sum = 0;
        for (int i = 0; i < sweetness.size(); i++) {
            sum += sweetness[i];
            if (sum >= mid) {
                chunks += 1;
                sum = 0;
            }
        }
        return chunks >= K+1;
    }

    int maximizeSweetness(vector<int> &sweetness, int K) {
        int left = 1, right = accumulate(sweetness.begin(), sweetness.end(), 0);
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (canSplit(sweetness, K, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
