class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), c=0;
        vector<vector<int>>mat, adj[n*n];
        for(int i=0; i<n; i++){
            vector<int>v;
            for(int j=0; j<n; j++){
                v.push_back(c);
                c++;
            }
            mat.push_back(v);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vector<vector<int>>v;
                vector<int>p, q, r, s;
                if(i-1>=0){
                    p.push_back(mat[i-1][j]);
                    if(grid[i-1][j]<=grid[i][j]) p.push_back(0);
                    else p.push_back(grid[i-1][j]);
                    v.push_back(p);
                }
                if(i+1<n){
                    q.push_back(mat[i+1][j]);
                    if(grid[i+1][j]<=grid[i][j]) q.push_back(0);
                    else q.push_back(grid[i+1][j]);
                    v.push_back(q);
                }
                if(j-1>=0){
                    r.push_back(mat[i][j-1]);
                    if(grid[i][j-1]<=grid[i][j]) r.push_back(0);
                    else r.push_back(grid[i][j-1]);
                    v.push_back(r);
                }
                if(j+1<n){
                    s.push_back(mat[i][j+1]);
                    if(grid[i][j+1]<=grid[i][j]) s.push_back(0);
                    else s.push_back(grid[i][j+1]);
                    v.push_back(s);
                }
                adj[mat[i][j]]=v;
            }
        }
        set<pair<int, int>>st;
        vector<int>dist(n*n);
        for(int i=0; i<n*n; i++){
            dist[i]=INT_MAX;
        }
        dist[0]=grid[0][0];
        st.insert(make_pair(grid[0][0], 0));
        // st.insert(make_pair(0, 0));
        while(!st.empty()){
            auto top=*(st.begin());
            int nd=top.first;
            int tn=top.second;
            st.erase(st.begin());
            for(auto i:adj[tn]){
        // cout<<i[1]<<endl;
                if(max(nd,i[1])<dist[i[0]]){
                    dist[i[0]]=max(nd,i[1]);
                    st.insert(make_pair(dist[i[0]], i[0]));
                }
            }
        }
        return dist[n*n-1];
    }
};