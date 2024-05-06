package linkedlist

/*
 * https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn2925/
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	list := &ListNode{0, head}
	first, second, cnt := list, list.Next, 0
	// 如果删除的是尾节点
	if n == 1 {
		for first.Next != nil && first.Next.Next != nil {
			first = first.Next
		}
		first.Next = nil
		return list.Next
	}

	for first != nil {
		first = first.Next
		cnt++
		if cnt > n {
			second = second.Next
		}
	}
	second.Val = second.Next.Val
	second.Next = second.Next.Next

	return list.Next
}
