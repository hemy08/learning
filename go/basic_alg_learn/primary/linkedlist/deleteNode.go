package linkedlist

/*
 * https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnarn7/
 */

/**
 * Definition for singly-linked linkedlist.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func deleteNode(node *ListNode) {
	if node == nil {
		return
	}

	// 删除的是尾节点
	if node.Next == nil {
		node.Val = 0
		node = nil
		return
	}

	node.Val = node.Next.Val
	node.Next = node.Next.Next
}
