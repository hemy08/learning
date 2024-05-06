package byhash

import (
	"fmt"
	"sort"
)

// https://leetcode.cn/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-100-liked
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
func longestConsecutive(nums []int) int {
	// 如果数组为空，或者只有一个元素，直接返回数组长度
	if len(nums) <= 1 {
		return len(nums)
	}

	// 去重
	numSet := map[int]bool{}
	for _, num := range nums {
		numSet[num] = true
	}

	// 排序
	numTemp := make([]int, 0)
	for num := range numSet {
		numTemp = append(numTemp, num)
	}
	sort.Ints(numTemp)
	fmt.Printf("numTemp %v --> ", numTemp)

	// 暴力解法
	longestStreak := 0
	for begin := range numTemp {
		// 当剩余的个数，小于当前最大长度，则后面不可能有满足条件的更大的值，返回
		if begin+longestStreak > len(numTemp) {
			return longestStreak + 1
		}
		temp := BinarySearchMatch(numTemp, begin, longestStreak)
		if longestStreak < temp {
			longestStreak = temp
		}
	}
	return longestStreak + 1
}

// BinarySearchMatch 使用二分法查找切片中的元素
// 参数：
// arr - 已排序的切片
// target - 要查找的目标值
// 返回值：
// index - 目标值在切片中的索引，如果不存在则返回-1
func BinarySearchMatch(numTemp []int, begin, cur int) int {
	longestStreak := cur
	// 当前最大可用差值
	curMaxDiff := len(numTemp) - begin - 1
	// 使用二分法的理念，查询满足条件的数据
	for end := len(numTemp) - 1; end > begin; {
		// fmt.Printf("begin %v, end %v, curMaxDiff %v\n", begin, end, curMaxDiff)
		// 索引差值超过最大值，返回，end超过数组范围，返回
		if curMaxDiff >= len(numTemp) || end >= len(numTemp) {
			break
		}
		// 差值为0时，有可能会遗漏一个，判断end的下一个是否满足条件
		if curMaxDiff == 0 {
			if end < len(numTemp)-1 && numTemp[end+1]-numTemp[begin] == end+1-begin {
				longestStreak = end + 1 - begin
			}
			if end > begin && numTemp[end-1]-numTemp[begin] == end-1-begin {
				longestStreak = end - 1 - begin
			}
			break
		}
		// 数值差值
		valDiff := numTemp[end] - numTemp[begin]
		// 索引差值
		indexDiff := end - begin

		// 二分法找到合适的索引end
		// 索引差值 < 数值差值，数值太大了，中间有不连续的，往前移动curMaxDiff/2
		if valDiff > indexDiff && indexDiff != 0 {
			curMaxDiff = curMaxDiff / 2
			end = end - curMaxDiff
			continue
		}

		// 索引差值 > 数值差值，这种不可能存在，因为已经去重了
		// 索引差值 = 数值差值，后面可能还有满足条件的，继续找
		if valDiff == indexDiff {
			// 刷新最大值
			if longestStreak > valDiff {
				break
			}

			longestStreak = valDiff
			// end后移curMaxDiff/2
			curMaxDiff = curMaxDiff / 2
			end = end + curMaxDiff
			continue
		}
	}

	return longestStreak
}

// longestConsecutiveOfficially 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/longest-consecutive-sequence/solutions/276931/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
func longestConsecutiveOfficially(nums []int) int {
	numSet := map[int]bool{}
	for _, num := range nums {
		numSet[num] = true
	}
	fmt.Printf("numSet %v --> ", numSet)
	longestStreak := 0
	for num := range numSet {
		if !numSet[num-1] {
			currentNum := num
			currentStreak := 1
			for numSet[currentNum+1] {
				currentNum++
				currentStreak++
			}
			if longestStreak < currentStreak {
				longestStreak = currentStreak
			}
		}
	}
	return longestStreak
}

// longestConsecutiveMutated 官方题解变种
func longestConsecutiveMutated(nums []int) int {
	// 如果数组为空，或者只有一个元素，直接返回数组长度
	if len(nums) <= 1 {
		return len(nums)
	}

	// 去重
	numSet := map[int]bool{}
	for _, num := range nums {
		numSet[num] = true
	}

	// 排序
	numTemp := make([]int, 0)
	for num := range numSet {
		numTemp = append(numTemp, num)
	}
	sort.Ints(numTemp)
	fmt.Printf("numTemp %v --> ", numTemp)

	// 暴力解法
	longestStreak := 0
	for num := range numTemp {
		if num < len(numTemp)-1 && numTemp[num]+1 == numTemp[num+1] {
			currentNum := num
			currentStreak := 1
			for currentNum < len(numTemp)-1 && numTemp[currentNum]+1 == numTemp[currentNum+1] {
				currentNum++
				currentStreak++
			}
			if longestStreak < currentStreak {
				longestStreak = currentStreak
			}
		}
	}
	return longestStreak
}
