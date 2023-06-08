//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isvalid(int i, int j, int n, int m, vector<vector<char>>&grid){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='O') return true;
        return false;
    }
    void dfs1(int i, int j, int n, int m, vector<vector<char>>&grid){
        grid[i][j]='#';
        int ax[4]={1, -1, 0, 0}, ay[4]={0, 0, 1, -1};
        for(int k=0; k<4; k++){
            int nx=i+ax[k], ny=j+ay[k];
            if(isvalid(nx, ny, n, m, grid)) dfs1(nx, ny, n, m, grid);
        }
    }
    void dfs2(int i, int j, int n, int m, vector<vector<char>>&grid){
        grid[i][j]='X';
        int ax[4]={1, -1, 0, 0}, ay[4]={0, 0, 1, -1};
        for(int k=0; k<4; k++){
            int nx=i+ax[k], ny=j+ay[k];
            if(isvalid(nx, ny, n, m, grid)) dfs2(nx, ny, n, m, grid);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid)
    {
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]=='O') dfs1(i, j, n, m, grid);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m;  j++){
                if(grid[i][j]=='O'){
                    dfs2(i, j, n, m, grid);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='#') grid[i][j]='O';
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends