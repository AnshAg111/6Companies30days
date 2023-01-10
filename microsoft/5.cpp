class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        // vector<vector<int>>v(n, vector<int>(n+1, 0));
        // for(int i=n-1; i>=0; i--){
        //     for(int j=i-1; j>=-1; j--){
        //         int len=v[i+1][j+1];
        //         if(j==-1 || nums[i]>nums[j]) len=max(len, 1+v[i+1][i+1]);
        //         v[i][j+1]=len;
        //     }
        // }
        // return v[0][0];
        vector<int>v(n, 1), h(n);
        int m=1, l=0;
        for(int i=0; i<n; i++){
            h[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 and 1+v[j]>v[i]) {
                    v[i]=max(v[i], 1+v[j]);
                    h[i]=j;
                }
            }
            if(v[i]>m){
                m=v[i];
                l=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[l]);
        while(h[l]!=l){
            l=h[l];
            temp.push_back(nums[l]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};