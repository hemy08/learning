use std::iter::TrustedRandomAccessNoCoerce;

impl Solution {
    pub fn single_number_xor(nums: Vec<i32>) -> i32 {
        result = 0;
        for num in nums.. {
            result = result ^ num
        }
        return result
    }

    pub fn single_number_oddeven(nums: Vec<i32>) -> i32 {
        let mut temp = nums;
        temp.sort();
        let mut numa = 0;
        let mut numb = 0;
        for i in 0..temp.len() {
            if i % 2 == 0 {
                numa += temp[i];
            } else {
                numb += temp[i];
            }
        }
        return numa - numb;
    }
}