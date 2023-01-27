class Solution {
public:
    int mod=1e9+7;
    int countNicePairs(vector<int>& nums) {
        int n=nums.size(), ans;
        long long pairs=0;
        map<int, long long>m;
        for(int i=0; i<n; i++){
            int rev=0, x=nums[i];
            while(x!=0){
                int rem=x%10;
                rev=rev*10+rem;
                x/=10;
            }
            nums[i]=nums[i]-rev;
            m[nums[i]]++;
        }
        for(auto i:m){
            long long x=i.second;
            pairs+=((x*(x-1))/2);
            pairs=pairs%mod;
        }
        ans=pairs;
        return ans;
    }
};