extern crate rand;

use std::io;
use std::cmp::Ordering;
use self::rand::Rng;
use std::io::stdin;
use ::{console_out, INFO};

pub fn guess_game_run() {
    println!("Guess the number!");
    let secret_number = rand::thread_rng().gen_range(1, 101);
    println!("The secret number is: {}", secret_number);

    loop {
        println!("Please input your guess.");
        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .ok()
            .expect("failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Please input an number !!!");
                continue;
            }
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less    => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal   => {
                println!("You win!");
                break;
            }
        }
    }
}

fn generate_secret_num() -> u32 {//1
    let secret_number = rand::thread_rng().gen_range(1, 101);
    println!("INFO: 当前生成的随机数是：{}", secret_number);
    console_out(INFO,"当前生成的随机数是：{}");
    return secret_number
}

fn get_input_num() -> u32 {
    let mut input_str = String::new();
    let stdin_object = stdin();
    stdin_object.read_line(&mut input_str).unwrap();
    input_str.trim().parse().unwrap()
}

fn check_input(secret_num: u32, input_num: u32) -> bool {
    let mut is_equ_flag = false;
    if input_num < secret_num {
        console_out(INFO,"太小了！");
    } else if input_num > secret_num {
        console_out(INFO,"太大了！");
    } else {
        console_out(INFO,"恭喜您，猜对了！");
        is_equ_flag = true;
    }
    is_equ_flag
}

pub fn guess_game_optimized() {
    let secret_num = generate_secret_num();//生成秘密数字
    console_out(INFO,"请输入0到100的数字：");
    loop {
        let input_num = get_input_num();//获取用户输入
        if check_input(secret_num, input_num) { //判断输入数字是否和秘密数字相等，相等，则退出
            break;
        }
        console_out(INFO,"请重新输入0到100的数字：");
    }
}

#[test]
fn it_works() {
    println!("Guess the number!");
}


#[test]
fn test_case_guess_game() {
    guess_game_optimized();
}