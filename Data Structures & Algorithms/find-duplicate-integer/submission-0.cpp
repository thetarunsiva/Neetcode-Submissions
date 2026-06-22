class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        slow = nums[slow];
        fast = nums[nums[fast]];
        // Find the breaking point..
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // Getting to the entrance..
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
