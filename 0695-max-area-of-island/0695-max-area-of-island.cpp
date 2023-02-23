class Solution {
public:
//function to check area of an encountered island
    void r(vector<vector<int>>&v,int i,int j,int &c){
        if(v[i][j]==1){
            c++;
            v[i][j]=2;
            if(i>=1)r(v,i-1,j,c);
            if(j>=1)r(v,i,j-1,c);
            if(i+1<v.size())r(v,i+1,j,c);
            if(j+1<v[i].size())r(v,i,j+1,c);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c=0,m=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    c=0;
                    r(grid,i,j,c);//to count the area of the island
                    m=max(m,c);//store max area 
                }
            }
        }
        return m;
    }
};