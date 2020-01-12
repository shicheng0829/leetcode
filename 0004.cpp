class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int len = (m + n + 1) / 2;
        int lo = 0, hi = m;
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        while (lo <= hi)
        {
            int midA = (lo + hi) / 2;
            int midB = len - midA;
            int leftA = midA == 0 ? INT_MIN : nums1[midA - 1];
            int rightA = midA == m ? INT_MAX : nums1[midA];
            int leftB = midB == 0 ? INT_MIN : nums2[midB - 1];
            int rightB = midB == n ? INT_MAX : nums2[midB];
            // perfect
            if (leftA <= rightB && leftB <= rightA)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(leftA, leftB) + min(rightA, rightB)) * 1.0 / 2;
                }
                else
                {
                    return max(leftA, leftB);
                }
            }
            else if (leftA > rightB)
            {
                hi = midA - 1;
            }
            else
            {
                lo = midA + 1;
            }
        }
        return 0;
    }
};