class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size(), n2 = nums2.size(), tot = (n1 + n2 + 1) / 2;
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n1, lx1, lx2, rx1, rx2;
        while (l <= r)
        {
            int mid1 = (l + r) / 2, mid2 = tot - mid1;
            lx1 = (mid1 == 0 ? INT_MIN : nums1[mid1-1]);
            rx1 = (mid1 == n1 ? INT_MAX : nums1[mid1]);
            lx2 = (mid2 == 0 ? INT_MIN : nums2[mid2-1]);
            rx2 = (mid2 == n2 ? INT_MAX : nums2[mid2]);
            if (lx1 <= rx2 && lx2 <= rx1)
                break;
            else if (lx2 > rx1)
                l = mid1 + 1;
            else if (lx1 > rx2)
                r = mid1 - 1;
        }
        if ((n1 + n2) & 1)
            return max(lx1, lx2);
        else
            return (max(lx1, lx2) + min(rx1, rx2)) / 2.0;
    }
};