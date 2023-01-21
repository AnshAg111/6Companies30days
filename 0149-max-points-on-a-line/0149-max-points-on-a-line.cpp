class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), ans=2;
        if(n==1 or n==2) return n;
        vector<vector<double>>co(n, vector<double>(2));
        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++) co[i][j]=(double)points[i][j];
        }
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int c=2;
                for(int k=j+1; k<n; k++){
                    if((co[k][1]-co[i][1])*(co[j][0]-co[i][0])==(co[j][1]-co[i][1])*(co[k][0]-co[i][0])) c++;
                }
                if(ans<c) ans = c;
            }
        }
        return ans;
    }
};