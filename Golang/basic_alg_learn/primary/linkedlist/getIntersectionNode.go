package linkedlist

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}

	na := headA
	for na != nil {
		nb := headB
		for nb != nil {
			if na == nb {
				return na
			}
			nb = nb.Next
		}
		na = na.Next
	}

	return nil
}
