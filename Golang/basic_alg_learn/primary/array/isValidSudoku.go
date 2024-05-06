package array

/*
https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2f9gg/
*/

// isValidSudoku 暴力标记
func isValidSudoku(board [][]byte) bool {

	return isRowValidSudoku(board) && isColValidSudoku(board) && isSeqValidSudoku(board)
}

func isRowValidSudoku(board [][]byte) bool {
	for _, row := range board {
		hasMap := map[byte]byte{}
		for _, val := range row {
			if val == '.' {
				continue
			}
			if _, has := hasMap[val]; has {
				return false
			}
			hasMap[val] = val
		}
	}

	return true
}

func isColValidSudoku(board [][]byte) bool {
	for i := 0; i < 9; i++ {
		for hasMap, j := map[byte]byte{}, 0; j < 9; j++ {
			val := board[j][i]
			if val == '.' {
				continue
			}
			if _, has := hasMap[val]; has {
				return false
			}
			hasMap[val] = val
		}
	}
	return true
}

func isSeqValidSudoku(board [][]byte) bool {

	for i := 0; i < 9; i += 3 {
		for j := 0; j < 9; j += 3 {
			hasMap := map[byte]byte{}
			for m := 0; m < 3; m++ {
				for n := 0; n < 3; n++ {
					val := board[m+i][n+j]
					if val == '.' {
						continue
					}

					if _, has := hasMap[val]; has {
						return false
					}
					hasMap[val] = val
				}
			}
		}
	}
	return true
}
