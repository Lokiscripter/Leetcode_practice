import typing


def nearestPalindromic(self, n: str) -> str:
    m = len(n)
    candidates = [10 ** (m - 1) - 1, 10 ** m + 1]
    selfprefix = int(n[:(m+1)//2])
    for x in range(selfprefix-1,selfprefix+2):
        y = str(x)
        z = y + y[-(m & 1)-1::-1]
        candidates.append(int(z))
    ans = -1
    selfNumber = int(n)
    for candidate in candidates:
        if candidate != selfNumber:
            if ans == -1 or \
                    abs(candidate - selfNumber) < abs(ans - selfNumber) or \
                    abs(candidate - selfNumber) == abs(ans - selfNumber) and candidate < ans:
                ans = candidate
    return str(ans)
