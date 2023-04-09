//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isvalid(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1) return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>>&grid){
        grid[i][j]=0;
        int ax[4]={1, -1, 0, 0}, ay[4]={0, 0, 1, -1};
        for(int k=0; k<4; k++){
            int nx=i+ax[k], ny=j+ay[k];
            if(isvalid(nx, ny, n, m, grid)) dfs(nx, ny, n, m, grid);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]==1) dfs(i, j, n, m, grid);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends