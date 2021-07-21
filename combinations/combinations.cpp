class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,int index,int n,int k) {
        if (index == n+1) {
            if (temp.size() == k)
                ans.push_back(temp);
            return ;
        }

        temp.push_back(index);
        solve(ans, temp, index+1, n, k); 
        temp.pop_back();
        solve(ans, temp, index+1, n, k);

    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans,temp,1,n,k);

        return ans;

    }
};