class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l = 0 
        r = len(heights) - 1
        max_water = 0
        while l < r:
            width = r - l;
            water = min(heights[r], heights[l]) * width
            max_water = max(max_water, water)
            
            if (heights[r] > heights[l]):
                l += 1
            else:
                r -= 1

        return max(max_water, water)        