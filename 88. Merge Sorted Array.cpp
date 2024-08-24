class Solution {
public:
    //we traverse from back to front placing the larger element at the end of nums1 using 3 pointer 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int p1=m-1;//pointer at last non zero elemet of nums1
        int p2=n-1;// pointer at last non zero element of nums2
        int p=m+n-1;// pointer at end of array nums1
        while(p1>=0 && p2>=0)
        {
            if(nums1[p1]>nums2[p2])
            {
                nums1[p--]=nums1[p1--];
            }
            else
            {
                nums1[p--]=nums2[p2--];
            }
        }

        while(p1>=0)
        {
            nums1[p--]=nums1[p1--];
        }
        while(p2>=0)
        {
            nums1[p--]=nums2[p2--];
        }

        


    }
};
