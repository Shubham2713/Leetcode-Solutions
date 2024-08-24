// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;// to go one by one

        for(int j=0;j<n;j++)
        {
            if(nums[i]!=nums[j])// if the elements are different
            {
                i++;// the go to next position 
                nums[i]=nums[j];// assign that number
            }
        }
        return i+1;// for the last number, as we have 0 index so we add 1 
    }
};
