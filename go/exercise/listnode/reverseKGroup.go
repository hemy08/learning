package listnode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseListNode(head, tail *ListNode) (*ListNode, *ListNode) {
	prev := tail.Next
	temp := head
	for prev != tail {
		nextNode := temp.Next
		temp.Next = prev
		prev = temp
		temp = nextNode
	}
	return tail, head
}

func getLastNode(head *ListNode, nodeNum int) *ListNode {
	for nodeNum > 1 {
		nodeNum--
		head = head.Next
		if head == nil {
			break
		}
	}

	return head
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	protect := ListNode{0, head}
	firstNode := &protect

	if k == 1 {
		return head
	}

	for head != nil {
		lastNode := getLastNode(head, k)
		if lastNode == nil {
			return protect.Next
		}
		tempHead, tempTail := reverseListNode(head, lastNode)
		firstNode.Next = tempHead
		firstNode = tempTail
		head = tempTail.Next
	}
	return protect.Next
}
