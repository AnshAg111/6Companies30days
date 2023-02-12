class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool>vis(n, false);
        int f=0;
        for(int i=0; i<n-1; i++){
            for(int j=0; j<k-1; j++){
                while(vis[f]==true){
                    if(f==n-1) f=0;
                    else f++;
                }
                if(f==n-1) f=0;
                else f++;
            }
            while(vis[f]==true){
                if(f==n-1) f=0;
                else f++;
            }
            vis[f]=true;
            if(f==n-1) f=0;
            else f++;
        }
        for(int i=0; i<n; i++){
            if(vis[i]==false){
                f=i;
                break;
            }
        }
        return f+1;
    }
};