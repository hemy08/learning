package string

import (
	"fmt"
	"regexp"
	"testing"

	"github.com/stretchr/testify/assert"
)

type dataExpBytes struct {
	input  []byte
	except []byte
}

type ClassDataTest struct {
	dString []string
	dInts   []int
	dByte   []byte
	expBool bool
	expInt  int
	expByte []byte
	expStr  string
}

func Test_ReverseString_Case(t *testing.T) {
	testData := []ClassDataTest{
		{
			dByte:   []byte{'h', 'e', 'l', 'l', 'o'},
			expByte: []byte{'o', 'l', 'l', 'e', 'h'},
		}, {
			dByte:   []byte{'H', 'a', 'n', 'n', 'a', 'h'},
			expByte: []byte{'h', 'a', 'n', 'n', 'a', 'H'},
		},
	}

	for i, v := range testData {
		fmt.Println("++++TEST : index ", i, " input: ", string(v.dByte), " expBool: ", string(v.expByte))
		reverseString(v.dByte)
		assert.Equal(t, v.expByte, v.dByte)
	}
}

func Test_ReverseInt_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dInts: []int{123, 321}},
		{dInts: []int{-123, -321}},
		{dInts: []int{1534236469, 0}},
		{dInts: []int{-2147483412, -2143847412}},
	}

	for i, v := range testData {
		res := reverseInt(v.dInts[0])
		fmt.Println("++++TEST : index ", i, " input: ", v.dInts[0], " except: ", v.dInts[1], " result: ", res)
		assert.Equal(t, v.dInts[1], res)
	}
}

func Test_FirstUniqChar_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"leetcode"}, expInt: 0},
		{dString: []string{"loveleetcode"}, expInt: 2},
		{dString: []string{"aabb"}, expInt: -1},
	}

	for i, v := range testData {
		res := firstUniqChar(v.dString[0])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expInt: ", v.expInt, " result: ", res)
		assert.Equal(t, v.expInt, res)
	}
}

func Test_IsAnagram_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"anagram", "nagaram"}, expBool: true},
		{dString: []string{"rat", "car"}, expBool: false},
	}

	for i, v := range testData {
		res := isAnagram(v.dString[0], v.dString[1])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expBool: ", v.expBool, " result: ", res)
		assert.Equal(t, v.expBool, res)
	}
}

func Test_IsAnagram_SortComp(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"anagram", "nagaram"}, expBool: true},
		{dString: []string{"rat", "car"}, expBool: false},
	}

	for i, v := range testData {
		res := isAnagramSortComp(v.dString[0], v.dString[1])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expBool: ", v.expBool, " result: ", res)
		assert.Equal(t, v.expBool, res)
	}
}

func Test_IsPalindrome_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"A man, a plan, a canal: Panama"}, expBool: true},
		{dString: []string{"ratrace a car"}, expBool: false},
		{dString: []string{""}, expBool: true},
	}

	for i, v := range testData {
		res := isPalindrome(v.dString[0])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expBool: ", v.expBool, " result: ", res)
		assert.Equal(t, v.expBool, res)
	}
}

func Test_RegMatching(t *testing.T) {
	apiNameReg := "^[a-zA-Z][a-zA-Z0-9_-]{0,6}$"
	match, err := regexp.Match(apiNameReg, []byte("d45-_de"))
	if err != nil {
		fmt.Println("regexp api name failed.", err)
	}

	fmt.Println("match ", match)
}

func Test_MyAtoi_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{" -42"}, expInt: -42},
		{dString: []string{"4193 with words"}, expInt: 4193},
		{dString: []string{"-91283472332"}, expInt: -2147483648},
		{dString: []string{"1"}, expInt: 1},
		{dString: []string{"-1"}, expInt: -1},
		{dString: []string{"-"}, expInt: 0},
		{dString: []string{"+"}, expInt: 0},
		{dString: []string{""}, expInt: 0},
	}

	for i, v := range testData {
		res := myAtoi(v.dString[0])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expInt: ", v.expInt, " result: ", res)
		assert.Equal(t, v.expInt, res)
	}
}

func Test_MyStrStr_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"", ""}, expInt: 0},
		{dString: []string{"a", ""}, expInt: 0},
		{dString: []string{"", "a"}, expInt: -1},
		{dString: []string{"hello", "ll"}, expInt: 2},
		{dString: []string{"mississippi", "issi"}, expInt: 1},
		{dString: []string{"mississippi", "a"}, expInt: -1},
	}

	for i, v := range testData {
		res := strStr(v.dString[0], v.dString[1])
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expInt: ", v.expInt, " result: ", res)
		assert.Equal(t, v.expInt, res)
	}
}

func Test_CountAndSay_Case(t *testing.T) {
	testData := []ClassDataTest{
		{dInts: []int{1}, expStr: "1"},
		{dInts: []int{2}, expStr: "11"},
		{dInts: []int{3}, expStr: "21"},
		{dInts: []int{4}, expStr: "1211"},
		{dInts: []int{5}, expStr: "111221"},
		{dInts: []int{6}, expStr: "312211"},
		{dInts: []int{7}, expStr: "13112221"},
		{dInts: []int{8}, expStr: "1113213211"},
		{dInts: []int{9}, expStr: "31131211131221"},
		{dInts: []int{10}, expStr: "13211311123113112211"},
		{dInts: []int{11}, expStr: "11131221133112132113212221"},
		{dInts: []int{12}, expStr: "3113112221232112111312211312113211"},
		{dInts: []int{13}, expStr: "1321132132111213122112311311222113111221131221"},
		{dInts: []int{14}, expStr: "11131221131211131231121113112221121321132132211331222113112211"},
		{dInts: []int{15}, expStr: "311311222113111231131112132112311321322112111312211312111322212311322113212221"},
		{dInts: []int{30}, expStr: "311311222113111231133211121312211231131112311211133112111312211213211312111322211231131122111213122112311311222112111331121113112221121113122113121113222112132113213" +
			"22123211211131211121332211231131122211311122122111312211213211312111322211231131122211311123113322112111331121113112221121113122113111231133221121113122113121113222123211211131211121332211" +
			"21321132132211331121321132213211231132132211211131221232112111312212221121123222112311311222113111231133211121321321122111312211312111322211213211321322123211211131211121332211231131122211" +
			"31112311332111213122112311311123112112322211211133112111311222112111312211311123113322112111312211312111322111213122112311311123112112322211211131221131211132221232112111312111213111213211" +
			"23113213221121113122123211211131221222112112322211213211321322113311213212312311211131122211213211321322113221321132132211231131122211331121321232221121113122113121122132112311321322112111" +
			"31221131211322113321132211221121332211231131122211311123113321112131221123113111231121113311211131221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111" +
			"32221121321132122311211131122211213211321322113312221131122112211131221131211132221232112111312111213111213211231132132211211131221232112111312212221121123222112132113213221133112132123123" +
			"11211131122211213211321322113221321132132211231131122211331121321232221121113122113121122132112311321322112111312211312113221133211322112211213322112132113213221133112132123123112111311222" +
			"11213211331121321123123211231131122211211131221131112311332211213211321223112111311222112132113213221123123211231132132211231131122211311123113322112111312211312111322111213122112311311123" +
			"11211232221121321132132211331221122311311222112111312211311123113322112132113213221133122211332111213112221133211322112211213322112311311222113111231133211121312211231131112311211133112111" +
			"31221121321131211132221123113112211121312211231131122211211133112111311222112111312211312111322211213211321322123211211131211121332211231131122211311123113321112131221123113111231121123222" +
			"11322311311222113111231133211121312211231131112311211232221121113122113121113222123211211131221132211131221121321131211132221123113112211121312211231131122113221122112133221121321132132211" +
			"33112132123123112111312111312212231131122211311123113322112111312211312111322111213122112311311123112112322211213211321322113311213212312311211131221132231121113311211131221121321131112311" +
			"32231121113213221231221132221222112112322211211131221131211132221232112111312111213111213211231132132211211131221232112111312211213111213122112132113213221123113112221133112132123222112111" +
			"31221131211221321123113213221121113122113121113222112131112131221121321131211132221121321132132211331121321232221123113112221131112311322311211131122211213211331121321122112133221121113122" +
			"11312111322212311222122132113213221123113112221133112132123222112111312211312111322212321121113121112133221121311121312211213211312111322211213211321322123211211131211121332211213211321322" +
			"11331121321231231121113112221121321133112132112211213322112311311222113111231133211121312211231131122211322311311222112111312211311123113322112132113212231121113112221121321132122211322212" +
			"22112112322211211131221131211132221232112111312111213111213211231131112311311221122132113213221133112132123222112311311222113111231132231121113112221121321133112132112211213322112111312211" +
			"31211132221232112111312111213111213211231132132211211131221232112111312212221121123222112131112131221121321131211132221121321132132212321121113121112133221121321132132211331121321132213211" +
			"23113213221121113122123211211131221222112112322211213211321322113311213212312311211131122211213211331121321123123211231131122211211131221131112311332211213211321223112111311222112132113212" +
			"22113222122211211232221123113112221131112311332111213122112311311123112111331121113122112132113121113222112311311221112131221123113112221121113311211131122211211131221131211132221121321132" +
			"13221232112111312111213322112311311222113111231133211121321321122111312211312111322211213211321322123211211131211121332211213211321322113311213212312311211131221132231121113311211131221222" +
			"11211232221121321132132211331121321232221132231131122211311123113321112131221123113111231121123222112111312211312111322212321121113121112131112132112311321322112111312211312112213211231132" +
			"13221123113112221131112211322212322211231131122211322111312211312111322211213211321322113311213211331121113122122211211132213211231131122212322211331222113112211"},
	}

	for i, v := range testData {
		res := countAndSay(v.dInts[0])
		fmt.Println("++++TEST : index ", i, " dInts: ", v.dInts, " result: ", res)
		assert.Equal(t, v.expStr, res)
	}
}

func Test_LongestCommonPrefix_Horizontal(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"flower", "flow", "flight"}, expStr: "fl"},
		{dString: []string{"dog", "racecar", "car"}, expStr: ""},
		{dString: []string{"", ""}, expStr: ""},
	}

	for i, v := range testData {
		res := longestCommonPrefixHorizontal(v.dString)
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expStr: ", v.expStr, " result: ", res)
		assert.Equal(t, v.expStr, res)
	}
}

func Test_LongestCommonPrefix_Vertical(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"flower", "flow", "flight"}, expStr: "fl"},
		{dString: []string{"dog", "racecar", "car"}, expStr: ""},
		{dString: []string{"", ""}, expStr: ""},
	}

	for i, v := range testData {
		res := longestCommonPrefixVertical(v.dString)
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expStr: ", v.expStr, " result: ", res)
		assert.Equal(t, v.expStr, res)
	}
}

func Test_LongestCommonPrefix_DivideAndConquer(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"flower", "flow", "flight"}, expStr: "fl"},
		{dString: []string{"dog", "racecar", "car"}, expStr: ""},
		{dString: []string{"", ""}, expStr: ""},
	}

	for i, v := range testData {
		res := longestCommonPrefixDivideAndConquer(v.dString)
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expStr: ", v.expStr, " result: ", res)
		assert.Equal(t, v.expStr, res)
	}
}

func Test_LongestCommonPrefix_BinarySearch(t *testing.T) {
	testData := []ClassDataTest{
		{dString: []string{"flower", "flow", "flight"}, expStr: "fl"},
		{dString: []string{"dog", "racecar", "car"}, expStr: ""},
		{dString: []string{"", ""}, expStr: ""},
	}

	for i, v := range testData {
		res := longestCommonPrefixBinarySearch(v.dString)
		fmt.Println("++++TEST : index ", i, " dString: ", v.dString, " expStr: ", v.expStr, " result: ", res)
		assert.Equal(t, v.expStr, res)
	}
}
