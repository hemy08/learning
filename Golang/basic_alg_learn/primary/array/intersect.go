package array

import "sort"

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/
*/

func intersect(nums1 []int, nums2 []int) []int {
	// 排序
	sort.Ints(nums1)
	sort.Ints(nums2)

	n1, n2 := len(nums1), len(nums2)
	result := make([]int, 0)
	// 遍历，找到两张表都存在的，放入要返回的表中
	start := 0
	for i := 0; i < n1; i++ {
		v1 := nums1[i]
		for j := start; j < n2; j++ {
			v2 := nums2[j]
			// 表1的值比表2的值大，需要表二继续往后移
			if v1 > v2 {
				continue
			}

			// 找到了，表二下标后移，下次从当前值的后一个值开始找
			if v1 == v2 {
				result = append(result, v2)
				start = j + 1
			}

			// 表1比表2的值小,或者找到了一个交集，都跳出当前循环，表1继续往下，表二不动
			break
		}
	}

	return result
}

func intersectDoublePoint(nums1 []int, nums2 []int) []int {
	// 排序
	sort.Ints(nums1)
	sort.Ints(nums2)

	n1, n2 := len(nums1), len(nums2)
	result := make([]int, 0)
	// 遍历，找到两张表都存在的，放入要返回的表中
	i, j := 0, 0
	for i < n1 && j < n2 {
		v1 := nums1[i]
		v2 := nums2[j]
		// 表1的值比表2的值大，需要表二继续往后移
		if v1 > v2 {
			j++
		} else if v1 < v2 {
			// 表1比表2的值小，表1继续往下，表二不动
			i++
		} else {
			// 找到了，表二下标后移，下次从当前值的后一个值开始找
			result = append(result, v2)
			j++
			i++
		}
	}

	return result
}

func intersectHashMap(nums1 []int, nums2 []int) []int {
	// n1, n2 := len(nums1), len(nums2)
	// if n1 > n2 {
	// 	return intersectHashMap(nums2, nums1)
	// }

	result := make([]int, 0)
	hasMap := map[int]int{}

	for _, v := range nums1 {
		hasMap[v]++
	}

	for _, v := range nums2 {
		if hasMap[v] > 0 {
			result = append(result, v)
			hasMap[v]--
		}
	}

	return result
}
