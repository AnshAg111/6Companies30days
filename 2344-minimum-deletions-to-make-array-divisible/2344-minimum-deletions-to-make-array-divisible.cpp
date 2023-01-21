class Solution {
public:
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
int findgcd(vector<int>arr, int n)
{
  int result = arr[0];
  for (int i = 1; i < n; i++)
  {
    result = gcd(arr[i], result);
  
    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int n=numsDivide.size(), m=nums.size(), c=0, i=0, f=0;
        int hcf=findgcd(numsDivide, n);
        for(i=0; i<m; i++){
            if(hcf%nums[i]==0){
                f=1;
                break;
            }
        }
        if(f==0) return -1;
        while(hcf%nums[c]!=0) c++;
        return c;
    }
};