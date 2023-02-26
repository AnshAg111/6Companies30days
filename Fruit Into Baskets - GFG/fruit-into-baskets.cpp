//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        unordered_map<int,int>m;
        int count=0;
        int prev=-1,pc=0,first,second=-1;
        int maxCount=0;
        for(int i=0;i<n;i++){
         int s=m.size();

         if((m.find(fruits[i])!=m.end()) || s<2 ){
             m[fruits[i]]++;
             count++;
             if(s==0)first=fruits[i];
             else if(second==-1 || second==fruits[i]) second=fruits[i];
             else {
             first=second;
             second=fruits[i];
             }

             if(fruits[i]==prev || prev==-1) pc++;
             else pc=1;
            
         }
         else {
         maxCount=max(maxCount,count);
         count=pc+1;
         pc=1;
         m.erase(first);
         first=second;
         second=fruits[i];
         m[fruits[i]]++;
         }
         prev=fruits[i];

        }
        return max(maxCount,count);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends