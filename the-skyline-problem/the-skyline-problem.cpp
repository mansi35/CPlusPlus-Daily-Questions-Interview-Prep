class Solution {
public:
    vector<vector<int>> mergeSkylines(vector<vector<int>>& skyline1, vector<vector<int>>& skyline2) {
        int prevHeight1 = 0, prevHeight2 = 0, keypoint1 = 0, keypoint2 = 0;
        vector<vector<int>> result;
        while (keypoint1 < skyline1.size() and keypoint2 < skyline2.size()) {
            if (skyline1[keypoint1][0] < skyline2[keypoint2][0]) {
                prevHeight1 = skyline1[keypoint1][1];
                if (skyline1[keypoint1][1] < prevHeight2) {
                    skyline1[keypoint1][1] = prevHeight2;
                }
                result.push_back(skyline1[keypoint1]);
                keypoint1++;
            } else if (skyline2[keypoint2][0] < skyline1[keypoint1][0]) {
                prevHeight2 = skyline2[keypoint2][1];
                if (skyline2[keypoint2][1] < prevHeight1) {
                    skyline2[keypoint2][1] = prevHeight1;
                }
                result.push_back(skyline2[keypoint2]);
                keypoint2++;
            } else {
                prevHeight1 = skyline1[keypoint1][1];
                prevHeight2 = skyline2[keypoint2][1];
                if (skyline1[keypoint1][1] > skyline2[keypoint2][1]) {
                    result.push_back(skyline1[keypoint1]);
                } else {
                    result.push_back(skyline2[keypoint2]);
                }
                keypoint1++;
                keypoint2++;
            }
        }
        while (keypoint1 < skyline1.size()) {
            result.push_back(skyline1[keypoint1]);
            keypoint1++;
        }
        while (keypoint2 < skyline2.size()) {
            result.push_back(skyline2[keypoint2]);
            keypoint2++;
        }
        int current = 0;
        while (current < result.size()) {
            bool duplicate = true;
            int i = current + 1;
            while (i < result.size() and duplicate) {
                if (result[current][1] == result[i][1]) {
                    duplicate = true;
                    result.erase(result.begin() + i);
                } else {
                    duplicate = false;
                }
            }
            current++;
        }
        return result;
    }
    
    vector<vector<int>> buildSkyline(vector<vector<int>>& buildings, int start, int end) {
        vector<vector<int>> result;
        if (start == end) {
            result.push_back({ buildings[start][0], buildings[start][2] });
            result.push_back({ buildings[start][1], 0 });
            return result;
        }
        int mid = (start + end) / 2;
        vector<vector<int>> skyline1 = buildSkyline(buildings, start, mid);
        vector<vector<int>> skyline2 = buildSkyline(buildings, mid+1, end);
        result = mergeSkylines(skyline1, skyline2);
        return result;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0)
            return vector<vector<int>>();
        return buildSkyline(buildings, 0, buildings.size() - 1);
    }
};