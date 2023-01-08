class Solution {
public:
int isoperator(string s)
    {
        if(s=="*") return 1;
        else if(s=="/") return 2;
        else if(s=="+") return 3;
        else if(s=="-") return 4;
          
        else return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int x, y, z;
        for(int i=0; i<tokens.size(); i++){
            if(isoperator(tokens[i])==0){
                if(tokens[i][0]=='-'){
                    int n=0, p=0;
                    for(int j=tokens[i].length()-1; j>=1; j--){
                        int r=(((int)(tokens[i][j]-'0'))%10)*pow(10, p);
                        n+=r;
                        p++;
                    }
                    s.push(n-2*n);
                }
                else{
                    int n=0, p=0;
                    for(int j=tokens[i].length()-1; j>=0; j--){
                        int r=(((int)(tokens[i][j]-'0'))%10)*pow(10, p);
                        n+=r;
                        p++;
                    }
                    s.push(n);
                }
            }
            else{
                x=s.top();
                s.pop();
                y=s.top();
                s.pop();
                switch(isoperator(tokens[i])){
                    case 1:
                    z=x*y;
                    break;
                    case 2:
                    z=y/x;
                    break;
                    case 3:
                    z=y+x;
                    break;
                    default:
                    z=y-x;
                    break;
                }
                s.push(z);
            }
        }
        return s.top();
    }
};