#include<ext/pb_ds/assoc_container.hpp>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL); cout.tie(NULL);

using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans=0;
        int n=nums1.size();
        oset<pair<int, int>>s;
        for(int i=0; i<n; i++){
            int k=nums1[i]-nums2[i]+diff;
            long long temp=s.order_of_key({k, INT_MAX});
            ans+=temp;
            s.insert({nums1[i]-nums2[i], i});
        }
        return ans;
    }
};