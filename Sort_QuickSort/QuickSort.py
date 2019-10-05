import numpy as np

amount = input("資料數量(輸入-1為自動隨機20筆測試,需要numpy) : ")
nums = []
if amount == "-1":
    nums = np.random.randint(10, 100, (20))
else:
    nums = input("輸入數字(不換行並以空格分開) : ")
    nums = [int(i) for i in nums.split(" ")]
    nums = nums[:5]
print("原始資料:", nums)
def Quicksort(f, l):
    if f > l:
        return
    target = nums[f]
    first = f
    last = l
    while first<last:
        while first < last and nums[last] >= target:
            last = last-1
        nums[first], nums[last] = nums[last], nums[first]
        while first < last and nums[first] <= target:
            first = first+1
        nums[first], nums[last] = nums[last], nums[first]
    Quicksort (f, last-1)
    Quicksort (last+1, l)

Quicksort(0, len(nums)-1)
print("排序資料:", nums)