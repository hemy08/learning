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

func checkSubTreeValidBST(root *TreeNode, min, max int) bool {
	if root == nil {
		return true
	}

	if root.Val <= min || root.Val >= max {
		return false
	}

	left := checkSubTreeValidBST(root.Left, min, root.Val)
	right := checkSubTreeValidBST(root.Right, root.Val, max)

	return left && right
}

func isValidBST(root *TreeNode) bool {
	return checkSubTreeValidBST(root, math.MinInt64, math.MaxInt64)
}
