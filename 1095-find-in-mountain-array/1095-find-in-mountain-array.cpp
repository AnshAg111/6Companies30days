/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0, high=mountainArr.length()-1, mid, element, f=0, n=mountainArr.length();
        while(low<high){
            mid=(low+high)/2;
            element=mountainArr.get(mid);
            if(mid>0 and element<mountainArr.get(mid-1)){
                high=mid-1;
            }
            else if(mid<n and element<mountainArr.get(mid+1)){
                low=mid+1;
            }
            else {
                f=1;
                break;
            }
        }
        if(f==1) high=mid;
        low=0;
        int l=high+1, r=n-1;
        while(low<=high){
            mid=(low+high)/2;
            element=mountainArr.get(mid);
            if(element<target) low=mid+1;
            else if(element>target) high=mid-1;
            else return mid;
        }
        while(l<=r){
            mid=(l+r)/2;
            element=mountainArr.get(mid);
            if(element<target) r=mid-1;
            else if(element>target) l=mid+1;
            else return mid;
        }
        return -1;
    }
};