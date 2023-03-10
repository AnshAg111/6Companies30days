// class Solution {
// public:
    class Solution {
public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         vector<int> vis(nums.size(), 0);
//         int tot_sum = accumulate(nums.begin(), nums.end(), tot_sum);
//         if(k > nums.size() or tot_sum % k) return false;
//         return backTrack(nums, vis, tot_sum / k, 0, 0, k);
//     }
    
//     bool backTrack(vector<int> &nums, vector<int> &vis, int target, int cur_sum, int idx, int k) {
//         if(k == 1) return true;
        
//         if(idx >= nums.size() or cur_sum > target) return false;
        
//         if(cur_sum == target) return backTrack(nums, vis, target, 0, 0, k - 1);

//         for(int i = idx; i < nums.size(); i++) {
//             if(vis[i] == 1 or nums[i] + cur_sum > target) continue;
            
//             vis[i] = 1;
//             if(backTrack(nums, vis, target, cur_sum + nums[i], i + 1, k)) return true;
//             vis[i] = 0;
//         }
        
//         return false;

//         // We can also do it recursively like below, but recursive calls will be more time consuming than iteration.
//         // bool a = false, b = false;

//         // a = backTrack(nums, vis, target, cur_sum, idx + 1, k);
//         // if(!vis[idx]) {
//         //     vis[idx] = 1;
//         //     b = backTrack(nums, vis, target, cur_sum + nums[idx], idx + 1, k);
//         //     vis[idx] = 0;
//         // }

//         // return a|b;
//     }
// };

    bool solve(vector<int>&a, int n, int k, int s, int start, vector<bool>&visited, int sum){
        // if(c==k-1){
        //     ans=true;
        //     return;
        // }
        if(k==1) return true;
        if(s>sum or start>=n) return false;
        if(s==sum){
            return solve(a, n, k-1, 0, 0, visited, sum);
        }
        for(int i=start; i<n; i++){
            if(visited[i] == true or a[i] + s > sum) continue;
                visited[i]=true;
                if(solve(a, n, k, s+a[i], i+1, visited, sum)) return true;
                visited[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=0, n=nums.size();
        for(int i=0; i<n; i++){
            s+=nums[i];
        }
        if(s%k!=0) return false;
        int sum=s/k;
        vector<bool>visited(n, false);
        return solve(nums, n, k, 0, 0, visited, sum);
    }
};