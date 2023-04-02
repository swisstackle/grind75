struct MyStruct;
pub trait Solution {
        fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>>;
}
impl Solution for MyStruct {
         fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
            let mut matt = mat.clone();
            let mut queue: Vec<Vec<usize>> = vec![];
            let mut discovered: Vec<Vec<usize>> = vec![vec![0; matt[0].len()]; matt.len()];
            let mut distance: Vec<Vec<i32>> = vec![vec![0; matt[0].len()]; matt.len()];

            for (index1, row) in matt.iter_mut().enumerate() {
                for (index2, nr) in row.iter_mut().enumerate() {
                   if *nr == 0 {
                        discovered[index1][index2] = 1;
                        queue.push(vec![index1, index2, 0]);
                   }
                }
            }
            
            while queue.len() != 0 {
                let u : Vec<usize> = queue.remove(0);
                let x : usize = u[0];
                let y : usize = u[1];
                let dis: i32 = u[2] as i32;
                let diss : usize = u[2];

                if x + 1 < matt.len() && discovered[x+1][y] != 1 { 
                    distance[x + 1][y] = dis + 1;
                    discovered[x+1][y] = 1;
                    queue.push(vec![x + 1, y, diss + 1]);
                }
                if x > 0 && discovered[x-1][y] != 1 {
                    distance[x-1][y] = dis + 1;
                    discovered[x-1][y] = 1;
                    queue.push(vec![x - 1, y, diss + 1]);
                }
                if y + 1 < matt[0].len() && discovered[x][y+1] != 1 {
                    distance[x][y+1] = dis + 1;
                    queue.push(vec![x, y + 1,diss + 1]) ;    
                    discovered[x][y+1] = 1;
                }
                if y > 0 && discovered[x][y-1] != 1 {
                    distance[x][y - 1] = dis + 1;
                    queue.push(vec![x, y - 1, diss + 1]);
                    discovered[x][y-1] = 1;
                }
            }
            distance
         } 
}

pub fn main(){
    let mat : Vec<Vec<i32>> = vec![vec![0,1,1],vec![1,1,1],vec![1,1,1]]; 
    let updated =  MyStruct::update_matrix(mat);
    println!("{:?}", updated);  
}
