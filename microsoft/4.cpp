class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0, s=0, n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
            s+=(i*nums[i]);
        }
        int max=s;
        for(int i=1; i<n; i++){
            s=s+sum-(n*nums[n-i]);
            if(max<s) max=s;
        }
        return max;
    }
};