class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>sum;
        priority_queue<int>q;
        int m=grid.size();
        for(int i=0; i<m; i++){
            int  n=grid[i].size();
            for(int j=0; j<n; j++){
                int k=0;
                while(2*k+i<m and j-k>=0 and j+k<n){
                    int s=grid[i][j], x=i, y=j;
                    for(int z=1; z<=k; z++){
                        x++;
                        y--;
                        s+=grid[x][y];
                    }
                    for(int z=1; z<=k; z++){
                        x++;
                        y++;
                        s+=grid[x][y];
                    }
                    for(int z=1; z<=k; z++){
                        x--;
                        y++;
                        s+=grid[x][y];
                    }
                    for(int z=1; z<k; z++){
                        x--;
                        y--;
                        s+=grid[x][y];
                    }
                    q.push(s);
                    k++;
                }
            }
        }
        while(sum.size()<3 and !q.empty()){
            int p=q.top();
            q.pop();
            if(!q.empty() and p==q.top()) continue;
            sum.push_back(p);
            
        }
        return sum;
    }
};