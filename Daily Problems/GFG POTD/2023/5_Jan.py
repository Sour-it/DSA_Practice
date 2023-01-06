Find the longest string 
In Python

class Solution():
    def longestString(self, arr, n):
        arr.sort(key=len)
        val = {''}
        for st in arr:
            if st[:-1] in val:
                val.add(st)
        return min(val, key=lambda x: (-len(x), x))