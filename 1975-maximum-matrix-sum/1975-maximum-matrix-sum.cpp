class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=INT_MAX, c=0;
        long long sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<0) c++;
                sum+=abs(matrix[i][j]);
                m=min(m, abs(matrix[i][j]));
            }
        }
        if(c%2!=0) return sum-2*m;
        return sum;
    }
};