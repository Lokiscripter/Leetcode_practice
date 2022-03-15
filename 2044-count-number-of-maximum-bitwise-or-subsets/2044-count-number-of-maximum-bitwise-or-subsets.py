from typing import List


def countMaxOrSubsets(self, nums: List[int]) -> int:
    maxOr = 0
    cnt = 0
    for num in nums:
        maxOr |= num

    def dfs(pos: int, orVal: int) -> None:
        nonlocal maxOr, cnt
        if orVal == maxOr:
            cnt += 1 << (len(nums) - pos)
            return
        if pos == len(nums):
            return
        dfs(pos + 1, orVal | nums[pos])
        dfs(pos + 1, orVal)

    dfs(0, 0)
    return cnt
