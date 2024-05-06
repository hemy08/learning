package binarytree

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_BinaryTree_MaxDepth_Case1(t *testing.T) {
	root := &TreeNode{
		Val: 3,
		Left: &TreeNode{
			Val:   9,
			Left:  nil,
			Right: nil,
		},
		Right: &TreeNode{
			Val:   20,
			Left:  &TreeNode{Val: 15, Left: nil, Right: nil},
			Right: &TreeNode{Val: 7, Left: nil, Right: nil},
		},
	}

	res := maxDepth(root)
	assert.Equal(t, 3, res)
	println("res :", res)
}

func Test_BinaryTree_MaxDepth_Case2(t *testing.T) {
	root := &TreeNode{
		Val:   1,
		Left:  nil,
		Right: &TreeNode{Val: 2, Left: nil, Right: nil},
	}

	res := maxDepth(root)
	assert.Equal(t, 2, res)
	println("res :", res)
}

func Test_BinaryTree_IsSymmetric_Case1(t *testing.T) {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val:   2,
			Left:  nil,
			Right: &TreeNode{Val: 3, Left: nil, Right: nil}},
		Right: &TreeNode{
			Val:   2,
			Left:  nil,
			Right: &TreeNode{Val: 3, Left: nil, Right: nil}},
	}

	res := isSymmetric(root)
	assert.Equal(t, false, res)
	println("res :", res)
}

func Test_BinaryTree_IsSymmetric_Case2(t *testing.T) {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val:   0,
			Left:  nil,
			Right: nil},
		Right: nil,
	}

	res := isSymmetric(root)
	assert.Equal(t, false, res)
	println("res :", res)
}

func Test_BinaryTree_IsSymmetric_Case3(t *testing.T) {
	root := &TreeNode{
		Val: 1,
		Left: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val:   2,
				Left:  nil,
				Right: nil},
			Right: nil},
		Right: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val:   2,
				Left:  nil,
				Right: nil},
			Right: nil},
	}

	res := isSymmetric(root)
	assert.Equal(t, false, res)
	println("res :", res)
}

func Test_BinaryTree_IsSymmetric_Case4(t *testing.T) {
	root := &TreeNode{
		Val: 5,
		Left: &TreeNode{
			Val:  4,
			Left: nil,
			Right: &TreeNode{
				Val: 1,
				Left: &TreeNode{
					Val:   2,
					Left:  nil,
					Right: nil},
				Right: nil}},
		Right: &TreeNode{
			Val:  1,
			Left: nil,
			Right: &TreeNode{
				Val: 4,
				Left: &TreeNode{
					Val:   2,
					Left:  nil,
					Right: nil},
				Right: nil}},
	}

	res := isSymmetric(root)
	assert.Equal(t, false, res)
	println("res :", res)
}
