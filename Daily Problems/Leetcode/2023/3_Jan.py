944. Delete Columns to Make Sorted 

In python

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        cnt = 0
        for i in zip(*strs):
            if list(i) != sorted(i):
                cnt+=1
        return cnt