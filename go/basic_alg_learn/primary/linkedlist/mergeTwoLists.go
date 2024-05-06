package linkedlist

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	list := &ListNode{0, nil}
	inlist := list
	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			inlist.Next = l1
			l1 = l1.Next
		} else {
			inlist.Next = l2
			l2 = l2.Next
		}

		inlist = inlist.Next
	}

	for l1 != nil {
		inlist.Next = l1
		l1 = l1.Next
		inlist = inlist.Next
	}

	for l2 != nil {
		inlist.Next = l2
		l2 = l2.Next
		inlist = inlist.Next
	}

	return list.Next
}
