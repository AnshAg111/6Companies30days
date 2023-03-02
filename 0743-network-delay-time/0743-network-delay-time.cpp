class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int, int>>s;
        vector<int>dist(n);
        int w=1000000000;
        vector<vector<int>>adj[n];
        for(int i=0; i<n; i++){
            vector<vector<int>>v;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                vector<int>u;
                u.push_back(j);
                u.push_back(w);
                v.push_back(u);
            }
            adj[i]=v;
        }
        for(int i=0; i<times.size(); i++){
            if(times[i][0]<times[i][1]){
                adj[times[i][0]-1][times[i][1]-2][1]=times[i][2];
            }
            else adj[times[i][0]-1][times[i][1]-1][1]=times[i][2];
        }
        for(int i=0; i<n; i++){
            dist[i]=w;
        }
        dist[k-1]=0;
        s.insert(make_pair(0, k-1));
        while(!s.empty()){
            auto top=*(s.begin());
            int nd=top.first;
            int tn=top.second;
            s.erase(s.begin());
            for(auto i:adj[tn]){
                if(nd+i[1]<dist[i[0]]){
                    dist[i[0]]=nd+i[1];
                    s.insert(make_pair(dist[i[0]], i[0]));
                }
            }
        }
        int m=*max_element(dist.begin(), dist.end());
        if(m==1000000000) m=-1;
        return m;
    }
};