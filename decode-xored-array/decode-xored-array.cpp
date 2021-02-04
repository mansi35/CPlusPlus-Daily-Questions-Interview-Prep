class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        for (auto element: encoded) {
            first = first xor element;
            result.push_back(first);
        }
        return result;
    }
};