//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        string r=s;
        reverse(r.begin(), r.end());
        int n=s.length();
        int lcs[n+1][n+1];
        for(int i=0; i<=n; i++) {
	        lcs[i][0]=0;
	        lcs[0][i]=0;
	    }
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=n; j++){
	            if(s[i-1]==r[j-1]) lcs[i][j]=1+lcs[i-1][j-1];
	            else lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
	        }
	    }
        return lcs[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends