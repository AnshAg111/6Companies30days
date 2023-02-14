class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n, vector<int>(n, -1));
        int city, m=INT_MAX;
        for(int i=0; i<edges.size(); i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i <n; i++)
            {
                for (int j = 0; j <n; j++)
                {
                    if(i==j) continue;
                    if (matrix[i][k] != -1 and matrix[k][j] != -1)
                    {
                        if (matrix[i][j] == -1)
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        else
                            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(matrix[i][j]!=-1 and matrix[i][j]<=distanceThreshold) c++;
            }
            if(c<=m){
                m=c;
                city=i;
            }
        }
        return city;
    }
};