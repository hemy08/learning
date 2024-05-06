
pub enum Level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL,
}
fn print_debug(msg: &str) {
	println!("DEBUG: {}", &msg);
}

fn print_info(msg: &str) {
	println!("INFO: {}", &msg);
}

fn print_warning(msg: &str) {
	println!("WARNING: {}", &msg);
}

fn print_error(msg: &str) {
	println!("ERROR: {}", &msg);
}

fn print_critical(msg: &str) {
	println!("CRITICAL: {}", &msg);
}
/*
pub macro_rules! console_out {
    () => {
        $crate::print!("\n")
    };
    ($($arg:tt)*) => {{
        $crate::io::_print($crate::format_args_nl!($($arg)*));
    }};
}*/
pub fn console_out(level:Level, msg: &str) {
	match level {
		Level::DEBUG => print_debug(msg),
		Level::INFO => print_info(msg),
		Level::WARNING => print_warning(msg),
		Level::ERROR => print_error(msg),
		Level::CRITICAL => print_critical(msg),
	}
}
