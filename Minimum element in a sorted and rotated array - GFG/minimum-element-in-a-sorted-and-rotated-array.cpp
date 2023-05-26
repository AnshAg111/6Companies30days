//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int nums[], int n){
        int l=0, r=n-1;
        while(l<r){
            int mid=(l+r)/2;
            if(mid==l) break;
            if(nums[mid]<nums[l]){
                if(nums[mid-1]>nums[mid]) return nums[mid];
                r=mid-1;
            }
            else{
                if(nums[mid]<nums[r]) return nums[l];
                l=mid+1;
            }
        }
        return min(nums[l], nums[r]);
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends