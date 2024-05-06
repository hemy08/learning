package array

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

type dataExpInt struct {
	input  []int
	except int
}

type dataStepExpIntArr struct {
	input  []int
	number int
	except []int
}

type dataExpIntArr struct {
	input  []int
	except []int
}

type dataExpBool struct {
	input  []int
	except bool
}

type data2ExpIntArr struct {
	input1 []int
	input2 []int
	except []int
}

type dataExpMatrix struct {
	input  [][]int
	except [][]int
}

func Test_RemoveDuplicates_Case1(t *testing.T) {
	testDada := []dataExpInt{
		{[]int{1, 1, 2}, 2},
		{[]int{1}, 1},
		{[]int{}, 0},
		{[]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5},
	}

	for i, v := range testDada {
		res := removeDuplicates(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_RemoveDuplicates_DoublePoint(t *testing.T) {
	testDada := []dataExpInt{
		{[]int{1, 1, 2}, 2},
		{[]int{1}, 1},
		{[]int{}, 0},
		{[]int{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5},
	}

	for i, v := range testDada {
		res := removeDuplicatesDoublePoint(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

var maxProfitData = []dataExpInt{
	{[]int{7, 1, 5, 3, 6, 4}, 7},
	{[]int{1, 2, 3, 4, 5}, 4},
	{[]int{7, 6, 4, 3, 1}, 0},
}

func Test_MaxProfit_Case1(t *testing.T) {
	for i, v := range maxProfitData {
		res := maxProfit(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_MaxProfit_Optimization(t *testing.T) {
	for i, v := range maxProfitData {
		res := maxProfitOptimization(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_MaxProfit_DP(t *testing.T) {
	for i, v := range maxProfitData {
		res := maxProfitDP(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_MaxProfit_DP2(t *testing.T) {
	for i, v := range maxProfitData {
		res := maxProfitDP2(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_RotateArray_Copy(t *testing.T) {
	rotateArrayData := []dataStepExpIntArr{
		{[]int{1, 2, 3, 4, 5, 6, 7}, 3, []int{5, 6, 7, 1, 2, 3, 4}},
		{[]int{-1}, 2, []int{-1}},
		{[]int{-1, 2, 3}, 0, []int{-1, 2, 3}},
	}

	for i, v := range rotateArrayData {
		rotateCopy(v.input, v.number)
		fmt.Println("++++TEST : index ", i, " data: ", v)
		assert.Equal(t, v.except, v.input)
	}
}

func Test_RotateArray_BySlice(t *testing.T) {
	rotateArrayData := []dataStepExpIntArr{
		{[]int{1, 2, 3, 4, 5, 6, 7}, 3, []int{5, 6, 7, 1, 2, 3, 4}},
		{[]int{-1}, 2, []int{-1}},
		{[]int{-1, 2, 3}, 0, []int{-1, 2, 3}},
	}

	for i, v := range rotateArrayData {
		rotateBySlice(v.input, v.number)
		fmt.Println("++++TEST : index ", i, " data: ", v)
		assert.Equal(t, v.except, v.input)
	}
}

func Test_RotateArray_ByNewNums(t *testing.T) {
	rotateArrayData := []dataStepExpIntArr{
		{[]int{1, 2, 3, 4, 5, 6, 7}, 3, []int{5, 6, 7, 1, 2, 3, 4}},
		{[]int{-1}, 2, []int{-1}},
		{[]int{-1, 2, 3}, 0, []int{-1, 2, 3}},
	}

	for i, v := range rotateArrayData {
		rotateByNewNums(v.input, v.number)
		fmt.Println("++++TEST : index ", i, " data: ", v)
		assert.Equal(t, v.except, v.input)
	}
}

func Test_ContainsDuplicate_Case(t *testing.T) {
	dataDuplicateData := []dataExpBool{
		{[]int{1, 2, 3, 1}, true},
		{[]int{1, 2, 3, 4}, false},
		{[]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},
	}

	for i, v := range dataDuplicateData {
		res := containsDuplicate(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_ContainsDuplicate_HashMap(t *testing.T) {
	dataDuplicateData := []dataExpBool{
		{[]int{1, 2, 3, 1}, true},
		{[]int{1, 2, 3, 4}, false},
		{[]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},
	}

	for i, v := range dataDuplicateData {
		res := containsDuplicateHashMap(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_SingleNumber_Map(t *testing.T) {
	dataDuplicateData := []dataExpInt{
		{[]int{2, 2, 1}, 1},
		{[]int{4, 1, 2, 1, 2}, 4},
		{[]int{-1}, -1},
	}

	for i, v := range dataDuplicateData {
		res := singleNumber(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_SingleNumber_Array(t *testing.T) {
	dataDuplicateData := []dataExpInt{
		{[]int{2, 2, 1}, 1},
		{[]int{4, 1, 2, 1, 2}, 4},
		{[]int{-1}, -1},
	}

	for i, v := range dataDuplicateData {
		res := singleNumberArr(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_SingleNumber_Array2(t *testing.T) {
	dataDuplicateData := []dataExpInt{
		{[]int{2, 2, 1}, 1},
		{[]int{4, 1, 2, 1, 2}, 4},
		{[]int{-1}, -1},
	}

	for i, v := range dataDuplicateData {
		res := singleNumberArr2(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_SingleNumber_Bitwise(t *testing.T) {
	dataDuplicateData := []dataExpInt{
		{[]int{2, 2, 1}, 1},
		{[]int{4, 1, 2, 1, 2}, 4},
		{[]int{-1}, -1},
	}

	for i, v := range dataDuplicateData {
		res := singleNumberBitwise(v.input)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_Intersect_SortArr(t *testing.T) {
	dataDuplicateData := []data2ExpIntArr{
		{[]int{4, 9, 5}, []int{9, 4, 9, 8, 4}, []int{4, 9}},
		{[]int{1, 2, 2, 1}, []int{2, 2}, []int{2, 2}},
		{[]int{1, 2, 2, 1}, []int{2}, []int{2}},
	}

	for i, v := range dataDuplicateData {
		res := intersect(v.input1, v.input2)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_Intersect_DoublePoint(t *testing.T) {
	dataDuplicateData := []data2ExpIntArr{
		{[]int{4, 9, 5}, []int{9, 4, 9, 8, 4}, []int{4, 9}},
		{[]int{1, 2, 2, 1}, []int{2, 2}, []int{2, 2}},
		{[]int{1, 2, 2, 1}, []int{2}, []int{2}},
	}

	for i, v := range dataDuplicateData {
		res := intersectDoublePoint(v.input1, v.input2)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_Intersect_HashMap(t *testing.T) {
	dataDuplicateData := []data2ExpIntArr{
		{[]int{4, 9, 5}, []int{9, 4, 9, 8, 4}, []int{9, 4}},
		{[]int{1, 2, 2, 1}, []int{2, 2}, []int{2, 2}},
		{[]int{1, 2, 2, 1}, []int{2}, []int{2}},
	}

	for i, v := range dataDuplicateData {
		res := intersectHashMap(v.input1, v.input2)
		fmt.Println("++++TEST : index ", i, " data: ", v, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_PlusOne_Array(t *testing.T) {
	dataDuplicateData := []dataExpIntArr{
		{[]int{4, 9, 5}, []int{4, 9, 6}},
		{[]int{1, 2, 2, 1}, []int{1, 2, 2, 2}},
		{[]int{1}, []int{2}},
		{[]int{9}, []int{1, 0}},
		{[]int{1, 9}, []int{2, 0}},
		{[]int{9, 9, 9, 9}, []int{1, 0, 0, 0, 0}},
		{[]int{9, 9, 8, 9}, []int{9, 9, 9, 0}},
	}

	for i, v := range dataDuplicateData {
		res := plusOne(v.input)
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_PlusOne_ArrayCheck(t *testing.T) {
	dataDuplicateData := []dataExpIntArr{
		{[]int{4, 9, 5}, []int{4, 9, 6}},
		{[]int{1, 2, 2, 1}, []int{1, 2, 2, 2}},
		{[]int{1}, []int{2}},
		{[]int{9}, []int{1, 0}},
		{[]int{1, 9}, []int{2, 0}},
		{[]int{9, 9, 9, 9}, []int{1, 0, 0, 0, 0}},
		{[]int{9, 9, 8, 9}, []int{9, 9, 9, 0}},
	}

	for i, v := range dataDuplicateData {
		res := plusOneCheck(v.input)
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_PlusOne_Simples(t *testing.T) {
	dataDuplicateData := []dataExpIntArr{
		{[]int{4, 9, 5}, []int{4, 9, 6}},
		{[]int{1, 2, 2, 1}, []int{1, 2, 2, 2}},
		{[]int{1}, []int{2}},
		{[]int{9}, []int{1, 0}},
		{[]int{1, 9}, []int{2, 0}},
		{[]int{9, 9, 9, 9}, []int{1, 0, 0, 0, 0}},
		{[]int{9, 9, 8, 9}, []int{9, 9, 9, 0}},
	}

	for i, v := range dataDuplicateData {
		res := plusOneSimples(v.input)
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_MoveZeroes_Case1(t *testing.T) {
	dataDuplicateData := []dataExpIntArr{
		{[]int{0, 1, 0, 3, 12}, []int{1, 3, 12, 0, 0}},
	}

	for i, v := range dataDuplicateData {
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except)
		moveZeroes(v.input)
		assert.Equal(t, v.except, v.input)
	}
}

func Test_TwoSum_Case1(t *testing.T) {
	dataDuplicateData := []dataStepExpIntArr{
		{[]int{2, 7, 11, 15}, 9, []int{0, 1}},
		{[]int{3, 2, 4}, 6, []int{1, 2}},
		{[]int{3, 3}, 6, []int{0, 1}},
	}

	for i, v := range dataDuplicateData {
		res := twoSum(v.input, v.number)
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_TwoSum_HashMap(t *testing.T) {
	dataDuplicateData := []dataStepExpIntArr{
		{[]int{2, 7, 11, 15}, 9, []int{1, 0}},
		{[]int{3, 2, 4}, 6, []int{2, 1}},
		{[]int{3, 3}, 6, []int{1, 0}},
	}

	for i, v := range dataDuplicateData {
		res := twoSumHashMap(v.input, v.number)
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except, " result: ", res)
		assert.Equal(t, v.except, res)
	}
}

func Test_RotateMatrix_Case(t *testing.T) {
	dataDuplicateData := []dataExpMatrix{
		{
			[][]int{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
			[][]int{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}},
		}, {
			[][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
			[][]int{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}},
		}, {
			[][]int{{1}},
			[][]int{{1}},
		}, {
			[][]int{{1, 2}, {3, 4}},
			[][]int{{3, 1}, {4, 2}},
		},
	}

	for i, v := range dataDuplicateData {
		fmt.Println("++++TEST : index ", i, " input: ", v.input, " except: ", v.except)
		rotateMatrix(v.input)
		assert.Equal(t, v.except, v.input)
	}
}
