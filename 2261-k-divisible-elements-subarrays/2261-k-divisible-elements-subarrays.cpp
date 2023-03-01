class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>m;
        int n=nums.size(), ans=0;
        for(int i=0; i<nums.size(); i++){
            int c=0;
            vector<int>v;
            for(int j=i; j<nums.size(); j++){
                v.push_back(nums[j]);
                if(nums[j]%p==0) c++;
                if(c<=k) m.insert(v);
            }
        }
        for(auto& i:m){
            ans++;
        }
        return ans;
    }
};