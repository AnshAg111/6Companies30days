class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans, s;
        if(numerator==0){
            ans.push_back('0');
            return ans;
        }
        long long nu=abs(numerator), d=abs(denominator);
        long long rem=nu%d, f=1 ,rev=0, q=nu/d, j=0;
        if((numerator<0 and denominator>0) or (numerator>0 and denominator<0)){
            ans.push_back('-');
            s.push_back('-');
            j++;   
        }
        long long p=q, n=0;
        unordered_map<long long, long long>r;
        while(q!=0){
            long long m=q%10;
            rev=rev*10+m;
            q/=10;
        }
        while(p!=0){
            n++;
            p/=10;
        }
        while(rev!=0){
            long long m=rev%10;
            char c=(char)(m+'0');
            ans.push_back(c);
            s.push_back(c);
            j++;
            rev/=10;
        }
        long long l=ans.length();
        for(long long i=0; i<n-l; i++){
            ans.push_back('0');
            s.push_back('0');
            j++;
        }
        if(ans.length()==0) {
            ans.push_back('0');
            s.push_back('0');
            j++;
        }
        ans.push_back('.');
        j++;
        r[rem]=j-1;
        l=ans.length();
        long long k=l;
        rem*=10;
        while(rem!=0){
            while(rem<d){
                ans.push_back('0');
                j++;
                rem*=10;
            }
            char ch=(char)(rem/d+'0');
            ans.push_back(ch);
            j++;
            rem=rem%d;
            if(r[rem]>0){
                f=0;
                k=r[rem];
                break;
            }
            r[rem]=j-1;
            rem*=10;
        }
        if(f==0){
            s.push_back('.');
            while(l<k+1) {
                s.push_back(ans[l]);
                l++;
            }
            s.push_back('(');
            for(long long i=k+1; i<ans.length(); i++) s.push_back(ans[i]);
            s.push_back(')');
            return s;
        }
        if(ans.length()==l) return s;
        return ans;
    }
};