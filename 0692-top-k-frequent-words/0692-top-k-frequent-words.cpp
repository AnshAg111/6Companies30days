class Solution {
public:
    static bool compare(pair<string, int>a, pair<string, int>b){
        int x=a.second, y=b.second;
        if(x==y){
            string p=a.first, q=b.first;
            return p<q;
        }
        return x>y;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string, int>>v;
        vector<string>ans;
        map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        for(auto i:m){
            int x=i.second;
            string y=i.first;
            v.push_back(make_pair(y, x));
        }
        sort(v.begin(), v.end(), compare);
        for(int i=0; i<k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};