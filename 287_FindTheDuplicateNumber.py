##30.25%
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i, size = 0, len(nums)
        while i < size:
            while nums[i] != i + 1:
                index = nums[i]
                if nums[i] == nums[index - 1]:
                    return nums[i]
                nums[i], nums[index - 1] = nums[index - 1], nums[i]
            i += 1
        return nums[-1]
		
def findArrayDuplicate(array):
    assert len(array) > 0

    # The "tortoise and hare" step.  We start at the end of the array and try
    # to find an intersection point in the cycle.
    slow = len(array) - 1
    fast = len(array) - 1

    # Keep advancing 'slow' by one step and 'fast' by two steps until they
    # meet inside the loop.
    while True:
        slow = array[slow]
        fast = array[array[fast]]

        if slow == fast:
            break

    # Start up another pointer from the end of the array and march it forward
    # until it hits the pointer inside the array.
    finder = len(array) - 1
    while True:
        slow   = array[slow]
        finder = array[finder]

        # If the two hit, the intersection index is the duplicate element.
        if slow == finder:
            return slow