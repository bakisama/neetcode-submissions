class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            indices = {}
            for i, n in enumerate(nums):
                complement = target - n
                if complement in indices:
                    return [indices[complement], i]
                indices[n] = i