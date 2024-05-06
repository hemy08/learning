package sliding_window

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

var SlidingWindowTestData = []TestSlidingWindow{
	{
		nums:   []int{1, 3, -1, -3, 5, 3, 6, 7},
		k:      3,
		except: []int{3, 3, 5, 5, 6, 7},
	}, {
		nums:   []int{1},
		k:      1,
		except: []int{1},
	}, {
		nums:   []int{7, 2, 4},
		k:      2,
		except: []int{7, 4},
	},
}

// CompareSlices 比较两个 int 类型的切片是否相同
func CompareSlices(slice1, slice2 []int) bool {
	if len(slice1) != len(slice2) {
		return false
	}
	for i, v := range slice1 {
		if v != slice2[i] {
			return false
		}
	}
	return true
}

func Test_MaxSlidingWindow_Case1(t *testing.T) {
	for _, val := range SlidingWindowTestData {
		res := maxSlidingWindowBaoLi(val.nums, val.k)
		assert.Equal(t, CompareSlices(res, val.except), true)
	}
}

func Test_MaxSlidingWindow_Case2(t *testing.T) {
	for _, val := range SlidingWindowTestData {
		fmt.Printf("%v\n", val)
		res := maxSlidingWindowSort(val.nums, val.k)
		assert.Equal(t, CompareSlices(res, val.except), true)
	}
}

func Test_MaxSlidingWindow_Case3(t *testing.T) {
	for _, val := range SlidingWindowTestData {
		fmt.Printf("%v\n", val)
		res := maxSlidingWindowHeap(val.nums, val.k)
		assert.Equal(t, CompareSlices(res, val.except), true)
	}
}
