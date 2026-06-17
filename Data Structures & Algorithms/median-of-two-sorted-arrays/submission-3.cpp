class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size()) {
        return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = total / 2;  // Median is at the right half
        int l = 0;
        int r = m;
        int aLeft, aRight, bLeft, bRight;
        while (l <= r) {
            int mid = l + (r-l)/2;
            int smid = half - mid;
            aLeft = (mid == 0) ? INT_MIN : nums1[mid-1];
            bLeft = (smid == 0) ? INT_MIN : nums2[smid-1];
            aRight = (mid == m) ? INT_MAX : nums1[mid];
            bRight = (smid == n) ? INT_MAX : nums2[smid];
            if (aLeft <= bRight && bLeft <= aRight) {
                break;
            }
            else if (aLeft > bRight) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (total%2!=0) {
            double ans = min(aRight, bRight);
            return ans;
        }
        else {
            double ans1 = max(aLeft, bLeft);
            double ans2 = min(aRight, bRight);
            double ans = (ans1 + ans2) / 2.0;
            return ans;
        }
    }
};
