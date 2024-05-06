package binarytree

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type BinaryTree struct {
	root       *TreeNode
	leafNums   int
	kthNums    int
	preOrder   []int
	inOrder    []int
	postOrder  []int
	levelOrder [][]int

	balance     bool
	validBST    bool
	isSymmetric bool
}

func NewBinaryTree() *BinaryTree {
	return &BinaryTree{
		root:      &TreeNode{0, nil, nil},
		preOrder:  []int{},
		inOrder:   []int{},
		postOrder: []int{},
	}
}

// GetNodeNum 计算二叉树节点个数
func (b *BinaryTree) GetNodeNum(root *TreeNode) int {
	if root == nil {
		return 0
	} else {
		return b.GetNodeNum(root.Left) + b.GetNodeNum(root.Right) + 1
	}
}

func NewTreeNode(val int) *TreeNode {
	return &TreeNode{
		val, nil, nil,
	}
}

// GetTreeDepth 计算二叉树的深度
func (b *BinaryTree) GetTreeDepth() int {
	if b.root == nil {
		return 0
	}
	return GetDepth(b.root)
}

// GetPreorderTraversal 前序遍历： 根-> 左子树 -> 右子树
func (b *BinaryTree) GetPreorderTraversal() []int {
	if b.root == nil {
		return nil
	}

	PreorderTraversal(b.root, b.preOrder)
	return b.preOrder
}

// GetInorderTraversal 中序： 左子树-> 根 -> 右子树
func (b *BinaryTree) GetInorderTraversal() []int {
	if b.root == nil {
		return nil
	}
	InorderTraversal(b.root, b.inOrder)
	return b.inOrder
}

// GetPostorderTraversal 后序： 左子树-> 右子树 ->  根
func (b *BinaryTree) GetPostorderTraversal() []int {
	if b.root == nil {
		return nil
	}
	PostorderTraversal(b.root, b.postOrder)
	return b.postOrder
}

// GetLeafNums 求叶子节点个数
func (b *BinaryTree) GetLeafNums() int {
	b.leafNums = getLeafNums(b.root)
	return b.leafNums
}

// GetKthNodeNum 求 K 层节点个数
func (b *BinaryTree) GetKthNodeNum(k int) int {
	b.kthNums = getKthNodeNum(b.root, k)
	return b.kthNums
}

// IsBalancedTree 判断是否平衡二叉树
func (b *BinaryTree) IsBalancedTree() bool {
	b.balance = isBalancedTree(b.root)
	return b.balance
}

// IsValidBST 判断是否二叉搜索树
func (b *BinaryTree) IsValidBST() bool {
	b.validBST = isValidBST(b.root)
	return b.validBST
}

// IsSymmetric 判断是否对称二叉树
func (b *BinaryTree) IsSymmetric() bool {
	b.isSymmetric = isSymmetric(b.root)
	return b.isSymmetric
}

// LevelOrder 层序遍历
func (b *BinaryTree) LevelOrder() [][]int {
	b.levelOrder = levelOrder(b.root)
	return b.levelOrder
}

// PreorderTraversal 前序遍历： 根-> 左子树 -> 右子树
func PreorderTraversal(root *TreeNode, res []int) {
	if root == nil {
		return
	}
	res = append(res, root.Val)
	PreorderTraversal(root.Left, res)
	PreorderTraversal(root.Right, res)
}

// InorderTraversal 中序： 左子树-> 根 -> 右子树
func InorderTraversal(root *TreeNode, res []int) {
	if root == nil {
		return
	}
	InorderTraversal(root.Left, res)
	res = append(res, root.Val)
	InorderTraversal(root.Right, res)
}

// PostorderTraversal 后序： 左子树-> 右子树 ->  根
func PostorderTraversal(root *TreeNode, res []int) {
	if root == nil {
		return
	}
	PostorderTraversal(root.Left, res)
	PostorderTraversal(root.Right, res)
	res = append(res, root.Val)
}

func GetDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var maxDegree = 0
	if GetDepth(root.Left) > GetDepth(root.Right) {
		maxDegree = GetDepth(root.Left)
	} else {
		maxDegree = GetDepth(root.Right)
	}
	return maxDegree + 1
}

// GetKthNodeNum 求 K 层节点个数
func getKthNodeNum(root *TreeNode, k int) int {
	if root == nil {
		return 0
	}
	if k == 1 {
		return 1
	}
	return getKthNodeNum(root.Left, k-1) + getKthNodeNum(root.Right, k-1)
}

func getLeafNums(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return 1
	}
	return getLeafNums(root.Left) + getLeafNums(root.Right)
}

func isBalancedTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	lde := GetDepth(root.Left)
	rde := GetDepth(root.Right)
	flag := false
	if (math.Abs(float64(lde - rde))) <= 1 {
		flag = true
	} else {
		flag = false
	}
	return flag && isBalancedTree(root.Left) && isBalancedTree(root.Right)
}
