def convertToBase(self, num: int, BASE: int) -> str:
    if not num:
        return str(num)
    sign = num < 0
    num = abs(num)
    ans = []
    while (num):
        ans.append(str(num % BASE))
        num //= BASE
    return ("-" if sign else "") + "".join(ans[::-1])
