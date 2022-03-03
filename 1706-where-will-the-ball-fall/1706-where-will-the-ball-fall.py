import typing


def findBall(self, grid):
    """
    :type grid: List[List[int]]
    :rtype: List[int]
    """
    M, N = len(grid), len(grid[0])
    res = []
    for col in range(N):
        res.append(self.dfs(grid, 0, col))
    return res


def dfs(self, grid, i, j):
    M, N = len(grid), len(grid[0])
    # 第 1 种情况：到达最右端，卡住
    if grid[i][j] == 1 and j == N - 1:
        return -1
    # 第 2 种情况：到达最左端，卡住
    if grid[i][j] == -1 and j == 0:
        return -1
    # 第 3、4 种情况：形成 V 型，无法下落
    if grid[i][j] != grid[i][j + grid[i][j]]:
        return -1
    # 第 6 种情况：到达最后一行，需要继续下落
    if i == M - 1:
        return j + grid[i][j]
    # 第 5 种情况：未到达最后一行，继续下落
    return self.dfs(grid, i + 1, j + grid[i][j])
