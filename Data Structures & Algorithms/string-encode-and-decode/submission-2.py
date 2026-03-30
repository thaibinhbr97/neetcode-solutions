"""
dummy_input = ["Hello","World"]
",Hello,World," n * max(len(str)) = n * m
read until seeing a delimiter -> that is a consider a word -> append to
the result string 
Output: ["Hello","World"]

"5#Hello5#World"

"""
"""
5#Hello
 i
  2.  5
"""
class Solution:
    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        res = ""
        for s in strs:
            res += str(len(s)) + '#' + s
        return res
    def decode(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
        l = 0
        r = 0
        n = len(s)
        res = []
        print(s)
        while r < n:
            if r < n and s[r] != '#':
                r += 1
                continue
            if s[r] == '#':
                word_len = int(s[l:r])
                first_index = r + 1
                last_index = r + 1 + word_len
                word = s[first_index:last_index]
                res.append(word)
                r = last_index
                l = last_index

        return res
    




