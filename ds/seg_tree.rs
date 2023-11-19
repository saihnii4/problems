use std::vec::Vec;

struct SegmentTree {
    seg: Vec<f64>,
    arr: Vec<f64>
}

pub trait Seg {
    fn build(&mut self, id: usize, l : usize, r: usize);
}

impl Seg for SegmentTree {
    fn build(&mut self, id: usize, l: usize, r: usize) {
        if l == r { 
            self.seg[id] = self.arr[l];
            return;
        }
        let m = (l+r)/2;
        self.build(2*id+1, l, m);
        self.build(2*id+2, m+1,r);
    }
}

fn main() {
    println!("testign");
}
