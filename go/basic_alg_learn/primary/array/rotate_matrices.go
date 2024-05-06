package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnhhkv/
*/

func rotateMatrix(matrix [][]int) {
	n := len(matrix[0])
	newMatrix := make([][]int, n)
	for i := 0; i < n; i++ {
		newMatrix[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			newMatrix[j][i] = matrix[i][j]
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			matrix[i][j] = newMatrix[i][n-j-1]
		}
	}
}
