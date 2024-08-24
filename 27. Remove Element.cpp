//https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        int p=n-1;//pointer at last element
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)//when we encounter a val
            {
                while(p>i && nums[p]==val)//we find a number from behind not equal to val and swap it with nums[i]
                {
                    p--;//but that number should be greater than i 
                }
                swap(nums[i],nums[p]);
            }
        }
        int c=0;//counter
        for(int i=0;i<n;i++)
        if(nums[i]!=val)
        c++;

        return c;
    }
};
