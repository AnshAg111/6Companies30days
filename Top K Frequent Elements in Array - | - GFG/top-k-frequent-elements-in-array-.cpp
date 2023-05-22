//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int n=nums.size();
        for(int i=0; i<n; i++) m[nums[i]]++;
        vector<pair<int, int>>v;
        vector<int>u;
        n=0;
        for(auto i:m){
            int x=i.first, y=i.second;
            v.push_back(make_pair(y, x));
            n++;
        }
        sort(v.begin(), v.end());
        for(int i=n-1; i>=n-k; i--){
            u.push_back(v[i].second);
        }
        return u;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends