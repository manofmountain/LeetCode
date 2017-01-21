class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return nums[0]
        left = self.majorityElement(nums[:len(nums) / 2)
        right = self.majorityElement(nums[len(nums) / 2):]
        if left == right:
            return left
        
        leftNum, rightNum = 0, 0
        for num in nums:
            if num == left:
                leftNum += 1
            elif num == right:
                rightNum += 1
        if leftNum > rightNum:
            return left
        return right

def majorityElement(self, nums):	
	return sorted(num)[len(num)/2]

# two pass + dictionary
def majorityElement1(self, nums):
    dic = {}
    for num in nums:
        dic[num] = dic.get(num, 0) + 1
    for num in nums:
        if dic[num] > len(nums)//2:
            return num

# one pass + dictionary
def majorityElement2(self, nums):
    dic = {}
    for num in nums:
        if num not in dic:
            dic[num] = 1
        if dic[num] > len(nums)//2:
            return num
        else:
            dic[num] += 1
			
# Sotring            
def majorityElement4(self, nums):
    nums.sort()
    return nums[len(nums)//2]
	
# Divide and Conquer
def majorityElement6(self, nums):
    if not nums:
        return None
    if len(nums) == 1:
        return nums[0]
    a = self.majorityElement(nums[:len(nums)//2])
    b = self.majorityElement(nums[len(nums)//2:])
    if a == b:
        return a
    return [b, a][nums.count(a) > len(nums)//2]
	
def majorityElement(self, nums):
    count, cand = 0, 0
    for num in nums:
        if num == cand:
            count += 1
        elif count == 0:
            cand, count = num, 1
        else:
            count -= 1
    return cand
	

			
