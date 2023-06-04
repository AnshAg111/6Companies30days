//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> isConnected, int n) {
        int provinces=0;
        // vector<vector<int>>adj(n);
        vector<bool>vis(n, false);
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                vis[i]=true;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int k=q.front();
                    q.pop();
                    for(int j=0; j<n; j++){
                        if(isConnected[k][j]==1 and vis[j]==false){
                            q.push(j);
                            vis[j]=true;
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends