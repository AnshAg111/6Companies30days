class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size(), ans=0;
        if(n==1 or n==2) return 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(j==i) continue;
        //         int d=(points[j][1]-points[i][1])*(points[j][1]-points[i][1])+(points[j][0]-points[i][0])*(points[j][0]-points[i][0]);
        //         for(int k=0; k<n; k++){
        //             if(k==j or k==i) continue;
        //             int l=(points[k][1]-points[i][1])*(points[k][1]-points[i][1])+(points[k][0]-points[i][0])*(points[k][0]-points[i][0]);
        //             if(d==l) ans++;
        //         }
        //     }
        // }
        int dist[n][n];
        for(int i=0; i<n; i++) dist[i][i]=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                dist[i][j]=pow((points[i][1]-points[j][1]), 2)+pow((points[i][0]-points[j][0]), 2);
                dist[j][i]=dist[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n-1; j++){
                if(i==j) continue;
                for(int k=j+1; k<n; k++){
                    if(i==k) continue;
                    if(dist[i][j]==dist[i][k]) ans+=2;
                }
            }
        }
        return ans;
    }
};