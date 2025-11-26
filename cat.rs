use std::io::{self, Read, Write};

fn main() -> io::Result<()> {
    let mut stdin = io::stdin();
    let mut stdout = io::stdout();
    let mut buffer = [0u8; 4096];

    loop {
        let n = stdin.read(&mut buffer)?;
        if n == 0 { break; }
        stdout.write_all(&buffer[..n])?;
    }
    Ok(())
}
