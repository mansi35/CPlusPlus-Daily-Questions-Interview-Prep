class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int currPassengerPos = 0;
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = buses.size();
        int m = passengers.size();
        set<int> st;
        for (auto p: passengers)
        {
            st.insert(p);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int currbus = buses[i];
            int count = 0;
            int x;
            
            while (currPassengerPos < passengers.size() && count < capacity && passengers[currPassengerPos] <= currbus)
            {
                x = passengers[currPassengerPos];
                currPassengerPos++;
                if (st.find(x-1) == st.end())
                    ans = x - 1; 
                count++;
            }
            
            if (count < capacity)
            {
                while (st.find(currbus) != st.end())
                {
                    currbus--;
                }
                ans = max(ans, currbus);
            }
            
        }
        return ans;
    }
};
