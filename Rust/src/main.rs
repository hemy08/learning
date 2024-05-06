mod example;
mod debug;


pub use self::example::guess_game::*;
pub use self::example::hello_world::*;
pub use self::debug::debug::*;
pub use self::debug::debug::Level::*;

fn main() {
    // guess_game_run();
    // guess_game_optimized();
    print_hello_world();
    console_out(ERROR,"ddddd");
}

#[cfg(test)]
mod tests {
    use super::example::guess_game::*;
    use super::example::hello_world::*;

    #[test]
    fn test_case_hello_world() {
        print_hello_world();
    }

    #[test]
    fn test_case_guess_game() {
        guess_game_run();
    }
}