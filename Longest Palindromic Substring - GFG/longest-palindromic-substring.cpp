//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n=s.size();
        bool dp[n][n];
        int indi=0,indj=0;
        
        for(int gap=0;gap<n;gap++){
            
            for(int i=0,j=gap;j<n;i++,j++){
                
                if(gap==0) {
                    dp[i][j]=true;
                }else if(gap==1) {
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    
                    if((s[i]==s[j]) && dp[i+1][j-1]){   
                        dp[i][j]=true;
                    }else {
                        dp[i][j]=false;
                    }
                }
                
                if(dp[i][j]) {
                    if((j-i)>(indj-indi)){
                        indi=i;
                        indj=j;
                    }
                }
            }
            
        }
        return s.substr(indi,indj-indi+1); 
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends