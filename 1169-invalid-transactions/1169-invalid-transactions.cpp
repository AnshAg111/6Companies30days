class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        int a[n], t[n];
        vector<string> name(n), city(n), ans;
        for(int i=0;i<n; i++){
            int j=0, d=0;
            while(transactions[i][j]!=',') {
                name[i].push_back(transactions[i][j]);
                j++;
            }
            j++;
            while(transactions[i][j]!=','){
                int k=(int)(transactions[i][j]-'0');
                d=d*10+k;
                j++;
            }
            j++;
            t[i]=d;
            d=0;
            while(transactions[i][j]!=','){
                int k=(int)(transactions[i][j]-'0');
                d=d*10+k;
                j++;
            }
            a[i]=d;
            j++;
            while(j<transactions[i].length()) {
                city[i].push_back(transactions[i][j]);
                j++;
            }
        }
        for(int i=0; i<n; i++){
            if(a[i]>1000) {
                ans.push_back(transactions[i]);
                continue;
            }
            for(int j=0; j<n; j++){
                if(abs(t[i]-t[j])<=60 and name[i]==name[j] and city[i]!=city[j]){
                    ans.push_back(transactions[i]);
                    break;
                }
            }
        }
        return ans;
    }
};