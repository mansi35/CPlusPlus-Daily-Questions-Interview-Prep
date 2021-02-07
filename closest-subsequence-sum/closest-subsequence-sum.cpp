class Solution {
public:
    int getLower(vector<int> &sums, int target){
        int lo = 0, hi = sums.size()-1;
        int answer = -1;
        while(lo <= hi){
            int mid = lo +(hi-lo)/2;
            if(sums[mid] <= target){
                answer = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return answer;
    }
    
    int getUpper(vector<int> &sums, int target){
        int lo = 0, hi = sums.size()-1;
        int answer = -1;
        while(lo <= hi){
            int mid = lo +(hi-lo)/2;
            if(sums[mid] >= target){
                answer = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return answer;
    }
    
    int getClosest(vector<int> &sums, int target){
        int upper = getUpper(sums, target);
        int lower = getLower(sums, target);
        if(lower == -1) {
            return sums[upper];
        }
        if(upper == -1) {
            return sums[lower];
        }
        return abs(target - sums[lower]) < abs(sums[upper] - target) ? sums[lower] : sums[upper];
    }
    
    vector<int> getSubSeqSums(vector<int> &nums, int leftindex, int rightIndex) {
        vector<int> answer;
        answer.push_back(nums[leftindex]);
        answer.push_back(0);
        for (int i = leftindex+1; i < rightIndex; i++) {
            vector<int> temp;
            for (auto sum: answer) {
                temp.push_back(sum + nums[i]);
                temp.push_back(sum);
            }
            answer = temp;
        }
        return answer;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int> dpFirstHalf = getSubSeqSums(nums, 0, nums.size()/2);
        vector<int> dpSecondHalf = getSubSeqSums(nums, nums.size()/2, nums.size());
        sort(dpSecondHalf.begin(), dpSecondHalf.end());
        int minAbs = INT_MAX;
        for(auto sum : dpFirstHalf){
            int closest = getClosest(dpSecondHalf, goal-sum);
            minAbs = min(minAbs, abs(goal - sum - closest));
        }
        return minAbs;
    }
};