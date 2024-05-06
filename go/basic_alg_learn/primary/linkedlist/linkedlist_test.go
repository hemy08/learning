package linkedlist

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type ClassDataTest struct {
	dString []string
	dInts   []int
	dByte   []byte
	expBool bool
	expInt  int
	expByte []byte
	expStr  string
}

// Test_DeleteNode_Case1 删除中间节点
func Test_DeleteNode_Case1(t *testing.T) {
	l := NewLinkList()
	l.Append(1).Append(2).Append(3).Append(4).Append(5)
	node, _ := l.FindByIndex(2)
	// 如果删除的是尾节点会怎么样？
	deleteNode(node)
	assert.Equal(t, l.Contain(3), false)
}

// Test_DeleteNode_Case2 删除尾节点
func Test_DeleteNode_Case2(t *testing.T) {
	l := NewLinkList()
	l.Append(1).Append(2).Append(3).Append(4).Append(5)
	node, _ := l.FindByIndex(4)
	// 如果删除的是尾节点会怎么样？
	deleteNode(node)
	assert.Equal(t, l.Contain(5), false)
}

// Test_removeNthFromEnd_Case1
func Test_removeNthFromEnd_Case1(t *testing.T) {
	l := NewLinkList()
	l.Append(1).Append(2).Append(3).Append(4).Append(5)
	removeNthFromEnd(l.Head, 2)
	assert.Equal(t, l.Contain(4), false)
}

// Test_removeNthFromEnd_Case2 只有一个节点
func Test_removeNthFromEnd_Case2(t *testing.T) {
	l := NewLinkList()
	l.Append(1)
	removeNthFromEnd(l.Head, 1)
	assert.Equal(t, l.Contain(1), false)
}

// Test_reverseList_Case1
func Test_reverseList_Case1(t *testing.T) {
	l := NewLinkList()
	l.Append(1).Append(2).Append(3).Append(4).Append(5)
	l.Head = reverseList(l.Head)
	assert.Equal(t, l.Head.Val, 5)
}

// Test_mergeTwoLists_Case1
func Test_mergeTwoLists_Case1(t *testing.T) {
	l1 := NewLinkList().Append(1).Append(2).Append(4)
	l2 := NewLinkList().Append(1).Append(3).Append(4)
	node := mergeTwoLists(l1.Head.Next, l2.Head.Next)
	l3 := NewLinkList().Append(1).Append(1).Append(2).Append(3).Append(4).Append(4)
	exp := l3.Head.Next
	for node != nil && exp != nil {
		assert.Equal(t, node.Val, exp.Val)
		node = node.Next
		exp = exp.Next
	}
}

// Test_mergeTwoLists_Case2
func Test_mergeTwoLists_Case2(t *testing.T) {
	node := mergeTwoLists(nil, nil)
	assert.Equal(t, node, (*ListNode)(nil))
}

// Test_isPalindrome_Case1
func Test_isPalindrome_Case1(t *testing.T) {
	l1 := NewLinkList().Append(1).Append(2).Append(2).Append(1)
	l2 := NewLinkList().Append(1).Append(2)
	l3 := NewLinkList().Append(1).Append(1).Append(2).Append(1)

	assert.Equal(t, true, isPalindrome(l1.Head.Next))
	assert.Equal(t, false, isPalindrome(l2.Head.Next))
	assert.Equal(t, false, isPalindrome(l3.Head.Next))
}

// Test_hasCycle_Case1
func Test_hasCycle_Case1(t *testing.T) {
	l := NewLinkList().Append(1).Append(2).Append(3).Append(4)
	node, _ := l.FindByIndex(1)
	tmp := l.Head.Next
	for tmp.Next != nil {
		tmp = tmp.Next
	}
	tmp.Next = node

	assert.Equal(t, true, hasCycle(l.Head.Next))
}
