class Solution:
    def singleNumber_XOR(self, nums: List[int]) -> int:
        result = 0
        for num in nums:
            result = result ^ num
        return result

    def singleNumber_OddEvenDigits(self, nums: List[int]) -> int:
        numa,numb = 0,0
        nums.sort()
        flags = True
        for num in nums:
            if flags:
                numa += num
            else:
                numb += num
            flags = not flags
        return numa - numb

    def singleNumber_AdjacentTwoNumbers(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 1):
            if i%2 == 0:
                if nums[i] != nums[i + 1]:
                    return nums[i]
        return nums[0]