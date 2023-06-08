//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isvalid(int i, int j, int n, int m, vector<vector<char>>&grid){
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]=='1') return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<char>>&grid){
        grid[i][j]='0';
        int ax[8]={1, -1, 0, 0, -1, -1, 1, 1}, ay[8]={0, 0, 1, -1, -1, 1, -1, 1};
        for(int k=0; k<8; k++){
            int nx=i+ax[k], ny=j+ay[k];
            if(isvalid(nx, ny, n, m, grid)) dfs(nx, ny, n, m, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;  j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends