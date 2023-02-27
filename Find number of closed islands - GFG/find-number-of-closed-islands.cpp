//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool isvalid(int i, int j, int n, int m, vector<vector<int>>&matrix){
        if(i>=0 and i<n and j>=0 and j<m and matrix[i][j]==1) return true;
        return false;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>>&matrix){
        matrix[i][j]=0;
        int ax[4]={1, -1, 0, 0}, ay[4]={0, 0, 1, -1};
        for(int k=0; k<4; k++){
            int nx=i+ax[k], ny=j+ay[k];
            if(isvalid(nx, ny, n, m, matrix)) dfs(nx, ny, n, m, matrix);
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j==0 or i==n-1 or j==m-1){
                    if(matrix[i][j]==1) dfs(i, j, n, m, matrix);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m;  j++){
                if(matrix[i][j]==1){
                    ans++;
                    dfs(i, j, n, m, matrix);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends