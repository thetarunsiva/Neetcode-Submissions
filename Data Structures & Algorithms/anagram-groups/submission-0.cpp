class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> pos(strs.size(), 0);
        unordered_map<string, int> mpp;
        int cc = 0;
        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            if (mpp.contains(curr)) {
                pos[i] = mpp[curr];
            }
            else {
                pos[i] = cc;
                mpp[curr] = pos[i];
                cc++;
            }
        }
        vector<vector<string>> ans(cc);
        for (int i = 0; i < pos.size(); i++) { 
            ans[pos[i]].push_back(strs[i]);
        }
        return ans;
    }
};
