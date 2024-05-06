package binarytree

import "math"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// root左侧，左--右--根
func helperPreOrder(root *TreeNode, data *[]int) {
	if root == nil {
		*data = append(*data, math.MaxInt64)
		return
	}

	helperPreOrder(root.Left, data)
	helperPreOrder(root.Right, data)
	*data = append(*data, root.Val)
}

// root右侧，右--左--根
func helperPostOrder(root *TreeNode, data *[]int) {
	if root == nil {
		*data = append(*data, math.MaxInt64)
		return
	}

	helperPostOrder(root.Right, data)
	helperPostOrder(root.Left, data)
	*data = append(*data, root.Val)
}

func isSymmetric(root *TreeNode) bool {
	var left, right []int

	// root左侧进行前序遍历
	helperPreOrder(root.Left, &left)
	// root右侧进行后序遍历
	helperPostOrder(root.Right, &right)
	if len(left) != len(right) {
		return false
	}

	for i := 0; i < len(left); i++ {
		if left[i] != right[i] {
			return false
		}
	}

	return true
}
