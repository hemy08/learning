package linkedlist

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	// 先翻转链表，然后判断翻转后的俩链表是否相同
	var prev *ListNode
	curr := head
	cnt := 0
	for curr != nil {
		newHead := &ListNode{curr.Val, prev}
		curr = curr.Next
		prev = newHead
		cnt++
	}

	times := (cnt + 1) / 2
	for head != nil && prev != nil && times != 0 {
		if head.Val != prev.Val {
			return false
		}
		head, prev = head.Next, prev.Next
		times--
	}

	return true
}
