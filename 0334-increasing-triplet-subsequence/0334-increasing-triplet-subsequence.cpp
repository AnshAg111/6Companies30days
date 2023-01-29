class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(), x=INT_MAX, y=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]>x) return true;
            if(nums[i]>y) x=min(nums[i], x);
            y=min(nums[i], y);
        }
        return false;
    }
};