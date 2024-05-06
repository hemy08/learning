package linkedlist

/*
 * https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnnhm6/
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	list := &ListNode{0, head}

	cur := head
	for cur != nil {
		tmp := cur.Next
		cur.Next = list.Next
		list.Next = cur
		cur = tmp
	}

	return list.Next
}

func reverseList2(head *ListNode) *ListNode {
	var prev *ListNode
	curr := head
	for curr != nil {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}
