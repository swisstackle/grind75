use std::{vec::Vec};
pub trait Solution {
   fn insert(&self, intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>>;
}
impl Solution for SolutionImpl{
    fn insert(&self, intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut intervals = intervals.clone();
        let (mut new_start, mut new_end) = (new_interval[0], new_interval[1]);
        let mut i = 0;
        while i < intervals.len() {
            let (start, end) = (intervals[i][0], intervals[i][1]);
            if new_end < start {
                break;
            } else if new_start <= end && new_end >= start {
                new_start = std::cmp::min(new_start, start);
                new_end = std::cmp::max(new_end, end);
                intervals.remove(i);
            } else {
                i += 1;
            }
        }
        intervals.insert(i, vec![new_start, new_end]);
        intervals
    }
}
struct SolutionImpl;


fn main() {
    let solution = SolutionImpl;
    let intervals: Vec<Vec<i32>> = vec![vec![2,6],vec![7,9]];
    let new_interval: Vec<i32> = vec![15,18];
    
    let result = solution.insert(intervals, new_interval);
    println!("{:?}", result);
}



