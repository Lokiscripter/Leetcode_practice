import random


class RandomizedSet:

    def __init__(self):
        self.nums = [] # 保存数据
        self.pos = {} # 保存值和索引的映射关系

    def insert(self, val: int) -> bool:
        if val not in self.pos:
            self.nums.append(val)
            self.pos[val] = len(self.nums)-1
            return True
        return False

    def remove(self, val: int) -> bool:
        if val in self.pos:
            idx,last = self.pos[val],self.nums[-1]
            self.nums[idx],self.pos[last] = last,idx
            self.nums.pop(-1)
            del self.pos[val]
            return True
        return False

    def getRandom(self) -> int:
        return random.choice(self.nums)