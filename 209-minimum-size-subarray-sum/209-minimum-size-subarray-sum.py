from typing import List


def minSubArrayLen(self, target: int, nums: List[int]) -> int:
    n = len(nums)
    left, right = 0, 0
    ans = n + 1
    sum = 0
    while right < n:
        sum += nums[right]
        right += 1
        while sum >= target:
            ans = min(ans, right - left)
            sum -= nums[left]
            left += 1
    if ans == n + 1:
        return 0
    else:
        return ans
