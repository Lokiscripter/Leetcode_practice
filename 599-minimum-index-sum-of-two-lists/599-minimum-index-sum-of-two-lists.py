from typing import List
import math


def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
    index = {s: i for i, s in enumerate(list1)}
    ans = []
    indexSum = math.inf
    for i, s in enumerate(list2):
        if s in index:
            j = index[s]
            if i + j < indexSum:
                indexSum = i + j
                ans = [s]
            elif i + j == indexSum:
                ans.append(s)
    return ans;
