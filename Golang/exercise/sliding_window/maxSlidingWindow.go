package sliding_window

import (
	"container/heap"
	"fmt"
	"sort"
)

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/sliding-window-maximum/solutions/543426/hua-dong-chuang-kou-zui-da-zhi-by-leetco-ki6m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// maxSlidingWindowBaoLi 暴力解法
func maxSlidingWindowBaoLi(nums []int, k int) []int {
	var lenInput = len(nums)
	if (lenInput == 1) || (k == 1) {
		return nums
	}

	result := make([]int, lenInput-k+1)
	for i := 0; i <= lenInput-k; i++ {
		maxCur := nums[i]
		for j := 0; j < k; j++ {
			if nums[i+j] > maxCur {
				maxCur = nums[i+j]
			}
		}
		result[i] = maxCur
	}

	return result
}

func maxSlidingWindowSort(nums []int, k int) []int {
	var lenInput = len(nums)
	if (lenInput == 1) || (k == 1) {
		return nums
	}

	result := make([]int, lenInput-k+1)
	for i := 0; i <= lenInput-k; i++ {
		numTmp := make([]int, k)
		// fmt.Printf("numTmp %v, nums %v\n", numTmp, nums)
		copy(numTmp, nums[i:i+k])
		sort.Ints(numTmp)
		// fmt.Printf("numTmp %v, nums %v\n", numTmp, nums)
		result[i] = numTmp[k-1]
	}

	// fmt.Printf("%v\n", result)
	return result
}

var a []int

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool  { return a[h.IntSlice[i]] > a[h.IntSlice[j]] }
func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{} {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}

func maxSlidingWindowHeap(nums []int, k int) []int {
	a = nums
	q := &hp{make([]int, k)}
	for i := 0; i < k; i++ {
		q.IntSlice[i] = i
		fmt.Printf("%v\n", q)
	}
	heap.Init(q)
	fmt.Printf("%v\n", q)

	n := len(nums)
	ans := make([]int, 1, n-k+1)
	ans[0] = nums[q.IntSlice[0]]
	fmt.Printf("%v\n", ans)
	for i := k; i < n; i++ {
		fmt.Printf("%v\n", q)
		heap.Push(q, i)
		for q.IntSlice[0] <= i-k {
			heap.Pop(q)
		}
		ans = append(ans, nums[q.IntSlice[0]])
	}
	return ans
}
