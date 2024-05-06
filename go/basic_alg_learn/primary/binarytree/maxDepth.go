package binarytree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func PreorderBinaryTree(root *TreeNode, dep int, maxDep *int) {
	if dep > *maxDep {
		*maxDep = dep
	}
	if root == nil {
		return
	}
	PreorderBinaryTree(root.Left, dep+1, maxDep)
	PreorderBinaryTree(root.Right, dep+1, maxDep)
}

func maxDepth(root *TreeNode) int {
	depth := 0
	PreorderBinaryTree(root, 0, &depth)
	return depth
}

func maxDepth2(root *TreeNode) int {
	if root == nil {
		return 0
	}

	left := maxDepth2(root.Left)
	right := maxDepth2(root.Right)

	if left > right {
		return left + 1
	}

	return right + 1
}
