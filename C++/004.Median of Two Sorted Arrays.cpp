4. Median of Two Sorted Arrays
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid_len = (int)(len1+len2) /2+1;
        //create an array to store the values of half of nums1 and nums2.
        float store[mid_len] = {0};
        int k =0;
        int i=0,j=0;
        while(i<len1&&j<len2&&k<mid_len){
            if(nums1[i]<=nums2[j]){
                store[k++] = nums1[i++];
            }
            else if(nums2[j]<=nums1[i]){
                store[k++] = nums2[j++];
            }
        }
        while(i<len1&&k<mid_len){
            store[k++] = nums1[i++];

        }
         while(j<len2&&k<mid_len){
                store[k++] = nums2[j++];
        }
        if((len1+len2)%2==1)
            return store[mid_len-1];
        else
            return (store[mid_len-1]+store[mid_len-2]) /2;
    }
};
