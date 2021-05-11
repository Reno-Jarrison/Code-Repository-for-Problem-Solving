class Solution {
public:
    vector<vector<int> > reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        vector<vector<int> > ans(people.size());
        for (auto x: people) {
            int pt = 0, pre = x[1];
            while (pre) {
                if (ans[pt].empty() || ans[pt][0] == x[0])
                    pre--;
                pt++;
            }
            while (!ans[pt].empty())
                pt++;
            ans[pt] = x;
        }
        return ans;
    }
};