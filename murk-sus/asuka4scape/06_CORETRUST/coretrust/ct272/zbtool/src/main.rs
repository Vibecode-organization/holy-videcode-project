use std::env;
use std::fs::File;
use std::io::{BufReader, BufWriter};

fn main() {
    // usage: zbtool <xattr> <resourcefork> <out>
    let a: Vec<String> = env::args().collect();
    if a.len() != 4 {
        eprintln!("usage: zbtool <decmpfs-xattr> <resourcefork> <out>");
        std::process::exit(2);
    }
    let xattr = std::fs::read(&a[1]).expect("xattr");
    let hdr = zbitmap::decmpfs::parse_header(&xattr).expect("parse header");
    eprintln!("algo={} size={}", hdr.algo, hdr.size);
    let r = BufReader::new(File::open(&a[2]).expect("rsrc"));
    let w = BufWriter::new(File::create(&a[3]).expect("out"));
    let n = zbitmap::decmpfs::decode_rsrc(hdr, r, w).expect("decode");
    println!("wrote {} bytes ({})", n, a[3]);
}
