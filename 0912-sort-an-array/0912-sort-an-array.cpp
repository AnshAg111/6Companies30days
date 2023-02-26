class Solution {
public:
    int partition(vector<int>&nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low + 1;
        int j = high;
        int temp;

        do
        {
            while (nums[i] <= pivot)
            {
                i++;
            }

            while (nums[j] > pivot)
            {
                j--;
            }

            if (i < j)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        } while (i < j);
        temp = nums[low];
        nums[low] = nums[j];
        nums[j] = temp;
        return j;
    }

    void sortarr(vector<int>&nums, int low, int high)
    {
        int partitionIndex; 

        if (low < high)
        {
            partitionIndex = partition(nums, low, high); 
            sortarr(nums, low, partitionIndex - 1); 
            sortarr(nums, partitionIndex + 1, high); 
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0; i<n; i++){
            q.push(nums[i]);
        }
        for(int i=0; i<n; i++){
            nums[i]=q.top();
            q.pop();
        }
        return nums;
    }
};