class Solution(object):
    def rob(self, nums):
        nums_length = len(nums)
        max_sum = []
        if(nums_length == 1):
            return nums[0]
        if(nums_length == 2):
            return max(nums[1],nums[0])
        if(nums_length == 3):
            return max(nums[0] + nums[2], nums[1])
        max_sum.append(nums[0])
        max_sum.append(nums[1])
        max_sum.append(nums[0] + nums[2])
        for i in range(3,nums_length):
            max_sum.append(max(nums[i] + max_sum[i-2],nums[i] + max_sum[i-3]))
        return max(max_sum[nums_length-1],max_sum[nums_length-2])
