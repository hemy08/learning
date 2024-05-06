package binarytree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func helperLevelOrder(nodes []*TreeNode, data *[][]int) {
	if nodes == nil {
		return
	}

	var newNodes []*TreeNode
	var result []int
	for _, v := range nodes {
		if v == nil {
			return
		}

		if v.Left != nil {
			newNodes = append(newNodes, v.Left)
		}

		if v.Right != nil {
			newNodes = append(newNodes, v.Right)
		}
		result = append(result, v.Val)
	}
	*data = append(*data, result)
	helperLevelOrder(newNodes, data)
}

func levelOrder(root *TreeNode) [][]int {
	var data [][]int
	nodes := []*TreeNode{root}
	helperLevelOrder(nodes, &data)
	return data
}
