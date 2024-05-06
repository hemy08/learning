package linkedlist

import (
	"fmt"
	"sort"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

const maxArrLen = 102400

type IntList []int

func (x IntList) Len() int           { return len(x) }
func (x IntList) Less(i, j int) bool { return x[i] > x[j] }
func (x IntList) Swap(i, j int)      { x[i], x[j] = x[j], x[i] }

func sortList(head *ListNode) *ListNode {
	s := head
	count, i := 0, 0
	tmp := make([]int, maxArrLen)

	for count != maxArrLen && s != nil {
		tmp = append(tmp, s.Val)
		s = s.Next
		count++
	}

	fmt.Printf("%v\n", tmp)
	sort.Ints(IntList(tmp))
	s = head
	for i <= count && s != nil {
		s.Val = tmp[i]
		s = s.Next
		i++
	}
	return head
}
