package byhash

import (
	"fmt"
	"sort"
)

type twoSumData struct {
	nums      []int
	target    int
	hashTable map[int]int
}

func (t *twoSumData) twoSumBase() []int {
	n := len(t.nums)
	if n <= 1 {
		return nil
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if t.nums[i]+t.nums[j] == t.target {
				return []int{i, j}
			}
		}
	}

	return nil
}

func (t *twoSumData) twoSumHashTable() []int {
	n := len(t.nums)
	if n <= 1 {
		return nil
	}

	for i := 0; i < n; i++ {
		if j, ok := t.hashTable[t.target-t.nums[i]]; ok {
			return []int{i, j}
		}
		t.hashTable[t.nums[i]] = i
	}

	return nil
}

/*
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
 * 167. 两数之和 II - 输入有序数组
 * 给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
 * 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
 * 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
 * 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
 * 你所设计的解决方案必须只使用常量级的额外空间。
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers 按 非递减顺序 排列
 * -1000 <= target <= 1000
 * 仅存在一个有效答案
 */619676
func (t *twoSumData) twoSumForSortNums() []int {
	nums := t.nums
	n := len(nums)

	left, right := 0, n-1
	for left < right {
		sum := nums[left] + nums[right]
		if sum == t.target {
			return []int{left + 1, right + 1}
		} else if sum < t.target {
			left++
		} else {
			right--
		}
	}
	return nil
}

/*
 * https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked
 * 1. 两数之和
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案
 */
func twoSum(nums []int, target int) []int {
	data := &twoSumData{
		nums:      nums,
		target:    target,
		hashTable: make(map[int]int),
	}
	return data.twoSumHashTable()
}

/*
 * https://leetcode.cn/problems/two-sum-iii-data-structure-design/description/
 * 170. 两数之和 III - 数据结构设计
 * 设计一个接收整数流的数据结构，该数据结构支持检查是否存在两数之和等于特定值。
 * 实现 TwoSum 类：
 * TwoSum() 使用空数组初始化 TwoSum 对象
 * void add(int number) 向数据结构添加一个数 number
 * boolean find(int value) 寻找数据结构中是否存在一对整数，使得两数之和与给定的值相等。如果存在，返回 true ；否则，返回 false 。
 * -10^5 <= number <= 10^5
 * -2^31 <= value <= 2^31 - 1
 * 最多调用 10^4 次 add 和 find
 */

type TwoSum struct {
	nums   []int
	target int
}

func Constructor() TwoSum {
	return TwoSum{
		nums:   make([]int, 0),
		target: 0,
	}
}

func (this *TwoSum) Add(number int) {
	this.nums = append(this.nums, number)
}

func (this *TwoSum) Find(value int) bool {
	this.target = value
	sort.Ints(this.nums)
	left, right := 0, len(this.nums)-1
	for left < right {
		sum := this.nums[left] + this.nums[right]
		if sum == this.target {
			return true
		} else if sum < this.target {
			left++
		} else {
			right--
		}
	}

	return false
}

/**
 * Your TwoSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * param_2 := obj.Find(value);
 */

type threeSumData struct {
	nums   []int
	n      int
	target int
	res    [][]int
	first  int
	second int
	third  int
}

// 题解参考 https://leetcode.cn/problems/3sum/solutions/284681/san-shu-zhi-he-by-leetcode-solution/
// 排序+双指针
// 固定B值，获取C值
func (t *threeSumData) threeSumWithFixC(target int) {
	// b取值得到了，取c的值，b在c的左侧，c肯定大于b的，c从后面往前去，因为排序了，所以正常情况，b+c>= target
	for t.second < t.third {
		if t.nums[t.second]+t.nums[t.third] <= target {
			break
		}
		t.third--
	}
}

// 固定A值，取B+C = target
func (t *threeSumData) threeSumWithFixB(target int) {
	t.third = t.n - 1
	for second := t.first + 1; second < t.n; second++ {
		// 取一个b的值，去掉重复的
		if second > t.first+1 && t.nums[second] == t.nums[second-1] {
			continue
		}

		t.second = second
		// fmt.Printf("second %v\n", second)
		t.threeSumWithFixC(target)

		// 如果指针重合，随着 b 后续的增加
		// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
		if t.second == t.third {
			return
		}

		if t.nums[t.second]+t.nums[t.third] == target {
			t.res = append(t.res, []int{t.nums[t.first], t.nums[t.second], t.nums[t.third]})
		}
	}
}

func (t *threeSumData) threeSumWithFixA() {
	// 3 <= nums.length <= 3000
	// -10^5 <= nums[i] <= 10^5
	if t.n <= 2 {
		return
	}

	// 数组排序
	sort.Ints(t.nums)

	// 取a值，
	for first := 0; first < t.n; first++ {
		// 取一个a值，如果当前值与上一个值一样，则跳过
		if first > 0 && t.nums[first] == t.nums[first-1] {
			continue
		}

		// 已经取了a值，按照题目，a + b + c = target，那么剩余 b + c = target - a
		t.first = first
		remain := t.target - t.nums[first]
		// fmt.Printf("first %v\n", first)
		// a取值固定了，取b值，b在a值的后面
		t.threeSumWithFixB(remain)
	}
}

func (t *threeSumData) threeSumWithTarget() {
	// 3 <= nums.length <= 3000
	// -10^5 <= nums[i] <= 10^5
	if t.n <= 2 {
		return
	}

	// 数组排序
	sort.Ints(t.nums)

	// 取a值，
	for first := 0; first < t.n; first++ {
		// 取一个a值，如果当前值与上一个值一样，则跳过
		if first > 0 && t.nums[first] == t.nums[first-1] {
			continue
		}

		// 双指针，左侧取一个b值，右侧从后端往迁移
		third := t.n - 1
		// 已经取了a值，按照题目，a + b + c = 0，那么剩余 b + c = -a
		remain := t.target - t.nums[first]
		// fmt.Printf("first %v\n", first)
		// a取值固定了，取b值，b在a值的后面
		for second := first + 1; second < t.n; second++ {
			// 取一个b的值，去掉重复的
			if second > first+1 && t.nums[second] == t.nums[second-1] {
				continue
			}

			// b取值得到了，取c的值，b在c的左侧，c肯定大于b的，c从后面往前去，因为排序了，所以正常情况，b+c>= target
			// fmt.Printf("second %v\n", second)
			for second < third {
				if t.nums[second]+t.nums[third] <= remain {
					break
				}
				third--
			}

			// 如果指针重合，随着 b 后续的增加
			// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
			if second == third {
				break
			}

			if t.nums[second]+t.nums[third] == remain {
				t.res = append(t.res, []int{t.nums[first], t.nums[second], t.nums[third]})
			}
		}
	}
}

/*
 * https://leetcode.cn/problems/3sum/description/
 * 15. 三数之和
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
 * 你返回所有和为 0 且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 */
func threeSum(nums []int) [][]int {
	data := &threeSumData{
		nums:   nums,
		n:      len(nums),
		target: 0,
		res:    make([][]int, 0),
		first:  0,
		second: 0,
		third:  0,
	}
	data.threeSumWithFixA()
	// data.threeSumWithTarget()
	return data.res
}

type fourSumData struct {
	nums                         []int
	n, target                    int
	res                          [][]int
	first, second, third, fourth int
}

func (t *fourSumData) fourSumWithFixC() {
	nums := t.nums
	n := t.n
	// 双指针
	for left, right := t.second+1, n-1; left < right; {
		if sum := nums[t.first] + nums[t.second] + nums[left] + nums[right]; sum == t.target {
			t.res = append(t.res, []int{nums[t.first], nums[t.second], nums[left], nums[right]})
			fmt.Printf("%v %v %v %v\n", t.first, t.second, left, right)
			for left++; left < right && nums[left] == nums[left-1]; left++ {
			}
			for right--; left < right && nums[right] == nums[right+1]; right-- {
			}
		} else if sum < t.target {
			left++
		} else {
			right--
		}
	}
}

func (t *fourSumData) fourSumWithFixB() {
	nums := t.nums
	n := t.n
	for second := t.first + 1; second < n-2; second++ {
		// 连续的四个值，和大于target时，则四元组肯定不满足条件
		if nums[t.first]+nums[second]+nums[second+1]+nums[second+2] > t.target {
			return
		}
		// a、b、c 和 d 互不相同，如果相同，或者 A+B+最大的两个值，不满足条件，则以当前值为a值，不会再有满足条件的四元组
		if second > t.first+1 && nums[second] == nums[second-1] || nums[t.first]+nums[second]+nums[n-2]+nums[n-1] < t.target {
			continue
		}
		t.second = second
		t.fourSumWithFixC()
	}
}

func (t *fourSumData) fourSumWithFixA() {
	nums := t.nums
	sort.Ints(t.nums)
	n := t.n
	for first := 0; first < n-3; first++ {
		// 连续的四个值，和大于target时，则四元组肯定不满足条件
		if nums[t.first]+nums[t.first+1]+nums[t.first+2]+nums[t.first+3] > t.target {
			return
		}

		// a、b、c 和 d 互不相同，如果相同，或者A+最大的三个值，不满足条件，则以当前值为a值，不会再有满足条件的四元组
		if t.first > 0 && nums[t.first] == nums[t.first-1] || nums[t.first]+nums[n-3]+nums[n-2]+nums[n-1] < t.target {
			continue
		}

		t.first = first
		t.fourSumWithFixB()
	}

	return
}

func (t *fourSumData) fourSumWithTarget() {
	sort.Ints(t.nums)
	n := t.n
	nums := t.nums
	for i := 0; i < n-3 && nums[i]+nums[i+1]+nums[i+2]+nums[i+3] <= t.target; i++ {
		if i > 0 && nums[i] == nums[i-1] || nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < t.target {
			continue
		}
		for j := i + 1; j < n-2 && nums[i]+nums[j]+nums[j+1]+nums[j+2] <= t.target; j++ {
			if j > i+1 && nums[j] == nums[j-1] || nums[i]+nums[j]+nums[n-2]+nums[n-1] < t.target {
				continue
			}
			for left, right := j+1, n-1; left < right; {
				if sum := nums[i] + nums[j] + nums[left] + nums[right]; sum == t.target {
					t.res = append(t.res, []int{nums[i], nums[j], nums[left], nums[right]})
					for left++; left < right && nums[left] == nums[left-1]; left++ {
					}
					for right--; left < right && nums[right] == nums[right+1]; right-- {
					}
				} else if sum < t.target {
					left++
				} else {
					right--
				}
			}
		}
	}
	return
}

/*
 * https://leetcode.cn/problems/4sum/
 * 18. 四数之和
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 */
func fourSum(nums []int, target int) [][]int {
	data := &fourSumData{
		nums:   nums,
		n:      len(nums),
		target: target,
		res:    make([][]int, 0),
	}
	data.fourSumWithTarget()
	return data.res
}
