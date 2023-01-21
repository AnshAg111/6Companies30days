class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), ans=2;
        if(n==1 or n==2) return n;
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int c=2;
                for(int k=j+1; k<n; k++){
                    if((points[k][1]-points[i][1])*(points[j][0]-points[i][0])==(points[j][1]-points[i][1])*(points[k][0]-points[i][0])) c++;
                }
                if(ans<c) ans = c;
            }
        }
        return ans;
    }
};