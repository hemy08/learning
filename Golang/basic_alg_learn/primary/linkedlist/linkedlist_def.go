package linkedlist

import (
	"errors"
	"fmt"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type LinkList struct {
	Head   *ListNode
	Length uint32
}

func NewLinkList() *LinkList {
	return &LinkList{
		Head:   &ListNode{0, nil},
		Length: 0,
	}
}

func NewLinkNode(value int) *ListNode {
	return &ListNode{
		Val:  value,
		Next: nil,
	}
}

func (l *ListNode) GetNext() *ListNode {
	return l.Next
}

func (l *ListNode) GetValue() int {
	return l.Val
}

// Add 从链表头部添加元素
func (l *LinkList) Add(val int) *LinkList {
	node := NewLinkNode(val)
	node.Next = l.Head
	l.Head = node
	l.Length++
	return l
}

// Append 从链表尾部添加元素
func (l *LinkList) Append(val int) *LinkList {
	node := NewLinkNode(val)
	if l.IsEmpty() {
		l.Head = node
	} else {
		cur := l.Head
		for cur.Next != nil {
			cur = cur.Next
		}
		cur.Next = node
	}

	l.Length++
	return l
}

// Insert 在指定位置插入元素
func (l *LinkList) Insert(i uint32, node *ListNode) error {
	if i < 0 || node == nil || i > l.Length {
		return errors.New("index out of range or node is nil")
	}

	preItem := (*l).Head
	for j := uint32(0); j < i; j++ {
		preItem = preItem.Next
	}

	node.Next = preItem.Next
	preItem.Next = node

	l.Length++

	return nil
}

// Delete 删除节点
func (l *LinkList) Delete(node *ListNode) error {
	if nil == node {
		return errors.New("node is nil")
	}

	pre := l.Head
	cur := l.Head.Next

	for nil != cur {
		if cur.Val == node.Val {
			break
		}
		pre = cur
		cur = cur.Next
	}

	if nil == cur {
		return errors.New("not find node")
	}

	pre.Next = cur.Next
	node = nil
	l.Length--

	return nil
}

// DeleteVal 删除某个元素
func (l *LinkList) DeleteVal(val int) *LinkList {
	// 头节点
	if l.Head.Val == val {
		l.Head = l.Head.Next
		l.Length--
		return l
	}

	cur := l.Head
	for cur != nil {
		if cur.Val == val {
			cur = cur.Next
			l.Length--
		}

		if cur.Next == nil {
			break
		}
		cur = cur.Next
	}

	return l
}

// FindByIndex 获取指定节点
func (l LinkList) FindByIndex(index uint32) (*ListNode, error) {
	if index < 0 || index >= l.Length {
		return nil, errors.New("out of range")
	}

	preItem := l.Head.Next
	for i := uint32(0); i < index; i++ {
		preItem = preItem.Next
	}

	return preItem, nil
}

// Contain 是否存在某个元素
func (l LinkList) Contain(val int) bool {
	cur := l.Head
	for cur != nil {
		if cur.Val == val {
			return true
		}
		cur = cur.Next
	}
	return false
}

func (l LinkList) Print() {
	pre := l.Head.Next

	for nil != pre {
		fmt.Printf("%v\n", pre.GetValue())
		pre = pre.Next
	}
}

func (l LinkList) IsEmpty() bool {
	return l.Head == nil
}

func (l LinkList) GetLength() uint32 {
	return l.Length
}
