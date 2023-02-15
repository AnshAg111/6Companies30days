class Solution {
public:
    static bool compare(pair<int, int>a, pair<int, int>b){
        int x=a.second, y=b.second;
        return x>y;
    }
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>m;
        vector<pair<int, int>>v;
        int k=0, n=barcodes.size();
        if(n==1 or n==2) return barcodes;
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            m[barcodes[i]]++;
        }
        for(auto i:m){
            int x=i.first, y=i.second;
            v.push_back(make_pair(x, y));
        }
        sort(v.begin(), v.end(), compare);
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[i].second; j++){
                ans[k]=v[i].first;
                k+=2;
                if(k>=n) k=1;
            }
        }
        return ans;
    }
};