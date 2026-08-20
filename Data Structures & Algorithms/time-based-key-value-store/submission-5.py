class TimeMap:

    def __init__(self):
        self.store = dict();

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.store:
            self.store[key] = []
        self.store[key].append((value, timestamp))

    # 1 2 5 100
    # timestamp: 6
    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        left = 0
        right = len(self.store[key]) - 1
        res = ""
        while left <= right:
            mid = left + (right - left) // 2
            if self.store[key][mid][1] <= timestamp:
                res = self.store[key][mid][0]
                left = mid + 1
            else:
                right = mid - 1
        return res


