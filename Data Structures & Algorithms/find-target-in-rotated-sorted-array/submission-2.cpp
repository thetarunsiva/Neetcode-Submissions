class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
        int l1 = 0, r1 = l-1;
        while (l1 <= r1) {
            int mid = l1 + (r1-l1)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l1 = mid + 1;
            else r1 = mid - 1;
        }
        int l2 = l, r2 = nums.size() - 1;
        while (l2 <= r2) {
            int mid = l2 + (r2-l2)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l2 = mid + 1;
            else r2 = mid - 1;
        }
        return -1;
    }
};
