from sortedcontainers import *
from typing import List
class Solution:
    def bestRotation(self, nums: List[int]) -> int:
        n = len(nums)
        st = SortedList()

        res = -1
        pre = 0
        for i in range(2 * n - 1):
            st.add((i - nums[i % n]))
            if i >= n - 1:
                k = i - n + 1
                j = n - st.bisect_left(k)
                if j > pre:
                    res = k
                    pre = j
                st.remove(i - n + 1 - nums[i - n + 1])
        return res