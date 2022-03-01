import typing

# https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
def convert(self, s: str, numRows: int) -> str:
    if numRows == 1:
        return s
    res = ["" for _ in range(numRows)]
    cur_row, going_down = 0, -1
    for c in s:
        res[cur_row]+=c
        if cur_row == 0 or cur_row == numRows -1:
            going_down = -going_down
        cur_row += going_down
    return "".join(res)
