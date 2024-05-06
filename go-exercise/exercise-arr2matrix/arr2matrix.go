package main

import (
	"errors"
	"fmt"
)

func ConvertToMatrix(input []int32) (error, [][]int32) {
	dataLen := int32(len(input))
	if (input == nil) || (dataLen == 0) {
		return errors.New("invalid Input"), nil
	}

	dp := make([][]int32, dataLen)
	for i := range dp {
		dp[i] = make([]int32, dataLen)
	}

	for i := int32(0); i < dataLen; i++ {
		dp[i][0] = input[i]
	}

	for j := int32(1); j < dataLen; j++ {
		dp[0][j] = dp[dataLen-1][j-1]
		for i := int32(1); i < dataLen; i++ {
			dp[i][j] = dp[i-1][j-1]
		}
	}

	return nil, dp
}

func CreateAndInitSlice(sliceLen int32) []int32 {
	if sliceLen == 0 {
		return nil
	}
	arr := make([]int32, sliceLen)
	for i := int32(0); i < sliceLen; i++ {
		arr[i] = int32(i + 1)
	}

	return arr
}

func OutPutMatrix(dp [][]int32) {
	for _, arr := range dp {
		for _, v := range arr {
			fmt.Printf("%v ", v)
		}
		fmt.Printf("\n")
	}
}

func main() {
	fmt.Println("=============== BEGIN ==================")
	fmt.Println("This is a program, convert arr to Matrix")
	arr := CreateAndInitSlice(10)
	if err, dp := ConvertToMatrix(arr); err != nil {
		fmt.Printf("convert failed, error %v\n", err.Error())
	} else {
		OutPutMatrix(dp)
	}
	fmt.Println("=============== END ==================")
}
