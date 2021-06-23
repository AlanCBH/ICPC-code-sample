class Solution {
public:
    int find_pivot(vector<int> &nums, int low, int high) {
        if (high < low) {
            return -1;
        }
        if (low == high) {
            return low;
        }
        int mid = (low+high)/2;
        if (mid < high && nums[mid] > nums[mid+1]) {
            return mid;
        }
        if (nums[mid] < nums[low] ) {
            return find_pivot(nums, low, mid);  
        } 
        if (nums[mid] > nums[high]) {
            return find_pivot(nums,mid,high);
        }
        return -1;
        
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int key) {
        if (high < low) {
            return -1;
        }
        int mid = (low + high)/2;
        if (key == nums[mid]) {
            return mid;
        }
        if (key > nums[mid]) {
            return binarySearch(nums,mid+1,high,key);
        }
        return binarySearch(nums, low, (mid-1), key);
    }
    int search(vector<int>& nums, int target) {
        //int res;
        cout << 0;
        int pivot = find_pivot(nums,0,nums.size()-1);
        cout << pivot;
        if (pivot == -1) {
            return binarySearch(nums,0,nums.size()-1,target);
        }
        int res = binarySearch(nums,0,pivot,target);
        if (res == -1) {
            return binarySearch(nums,pivot+1,nums.size()-1,target);
        }
        return res;
    }
};