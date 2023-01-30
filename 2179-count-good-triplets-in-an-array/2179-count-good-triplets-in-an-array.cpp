#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size();
        vector<ll>pos(n);
        // unordered_map<int, int>m;
        for(int i=0; i<n; i++) pos[nums2[i]]=i;
        vector<ll>l(n), r(n);
        ordered_set s;
        // l.insert(m[nums1[0]]);
        // for(int i=2; i<n; i++) r.insert(m[nums1[i]]);
        long long ans=0;
        // for(int i=1; i<n-1; i++){
        //     int k=m[nums1[i]]; 
        //     int a=distance(l.begin(), l.lower_bound(k)), b=r.size()-distance(r.begin(), r.lower_bound(k));
        //     ans+=(a*b);
        //     l.insert(m[nums1[i]]);
        //     r.erase(m[nums1[i+1]]);
        // }
        for(ll i=0; i<n; i++){
            ll curr_pos=pos[nums1[i]];
            l[i]=s.order_of_key(curr_pos);
            s.insert(curr_pos);
        }
        s.clear();
        for(ll i=n-1; i>=0; i--){
            ll curr_pos=pos[nums1[i]];
            r[i]=s.size()-s.order_of_key(curr_pos);
            s.insert(curr_pos);
        }
        for(ll i=1; i<n-1; i++) ans+=l[i]*r[i];
        return ans;
    }
};