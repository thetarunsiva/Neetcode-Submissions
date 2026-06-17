class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        for (int i : nums1) a.push_back(i);
        for (int i : nums2) a.push_back(i);
        sort(a.begin(), a.end());
        if ((nums1.size() + nums2.size()) % 2 == 0) {
            int s1 = (nums1.size() + nums2.size()) / 2;
            int s2 = s1 - 1;
            double aa = (double) (a[s1] + a[s2]) / 2;
            return aa;
        }
        else {
            int s1 = ((nums1.size() + nums2.size()) - 1) / 2;
            cout << s1;
            return (double)a[s1];
        }
    }
};
