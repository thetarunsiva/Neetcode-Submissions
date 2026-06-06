class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> pos(strs.size(), 0);
        unordered_map<string, int> mpp;
        int cc = 0;
        for (int i = 0; i < strs.size(); i++) {
            string curr = strs[i];
            vector<int> a(26, 0);
            for (char j : curr) {
                int pp = j - 'a';
                a[pp]++;
            }
            string s = "";
            for (int i = 0; i < 26; i++) {
                s += to_string(a[i]) + ",";
            }
            cout << s << " ";
            if (mpp.contains(s)) {
                pos[i] = mpp[s];
            }
            else {
                pos[i] = cc;
                mpp[s] = pos[i];
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
