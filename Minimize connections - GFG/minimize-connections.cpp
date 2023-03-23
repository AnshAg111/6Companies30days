//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void dfs(int x, vector<bool>&vis, vector<int>graph[])
    {
        vis[x] = true;
        for (auto i : graph[x])
            if (!vis[i])
                dfs(i, vis, graph);
    }
        int minimumConnections(vector<vector<int>> &c,int n)
        {
            vector<int>graph[n];
            int s=c.size(), ans=0;
            if(s<n-1) return -1;
            for(int i=0; i<s; i++){
                graph[c[i][0]].push_back(c[i][1]);
                graph[c[i][1]].push_back(c[i][0]);
            }
            vector<bool>vis(n, false);
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    dfs(i, vis, graph);
                    ans++;
                }
            }
            return ans-1;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> c(m,vector<int> (2));
        for(auto &j:c)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(c,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends