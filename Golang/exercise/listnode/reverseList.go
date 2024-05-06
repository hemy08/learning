package listnode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	prev := &ListNode{0, nil}
	temp := head
	for temp != nil {
		nextNode := temp.Next
		temp.Next = prev.Next
		prev.Next = temp
		temp = nextNode
	}
	return prev.Next
}
