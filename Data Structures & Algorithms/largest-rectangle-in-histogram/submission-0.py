class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = [] # (idx, height)
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                index, height = stack.pop()
                max_area = max(max_area, height * (i - index))
                start = index
            stack.append([start, h])
        n = len(heights)
        while stack:
            index, height = stack.pop()
            max_area = max(max_area, height * (n - index))
        return max_area
        