class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int left1,left2,right1,right2;
        int left = 0;
        int right = n;
        int total = (m+n);
        int half = (total+1)/2;
        int mid;
        int totalmid;
        
        while(left<=right){
            mid = (left+right)/2;
            totalmid = half-mid;
            left1 = (totalmid==0)? INT_MIN:nums1[totalmid-1];
            left2 = (mid==0)? INT_MIN:nums2[mid-1];
            right1 = (totalmid==m) ? INT_MAX:nums1[totalmid];
            right2 =  (mid==n) ? INT_MAX:nums2[mid];
            if(left1>right2) left = mid+1;
            else if(left2>right1) right = mid-1;
            else if(left1<=right2&&left2<=right1){
                if(total%2==1)return (double)max(left1,left2);
                else return (max(left1,left2)+min(right1,right2))/2.0;
                        
            }   
       
        }
        return-1;
   
        
    }
};
