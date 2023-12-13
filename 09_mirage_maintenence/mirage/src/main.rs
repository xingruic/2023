use std::fs::read_to_string;
fn find_next(v: &Vec<i64>) -> i64 {
    if v.iter().all(|&x| x == v[0]) {
        return v[0];
    }
    let mut steps: Vec<i64> = vec![];
    for i in 0..(v.len() - 1) {
        steps.push(v[i + 1] - v[i]);
    }
    let x = find_next(&steps);
    // println!("{x}");
    return v.first().unwrap() - x;
}
fn main() {
    let lines: Vec<Vec<i64>> = read_to_string("mirage.in")
        .unwrap()
        .lines()
        .map(|line| {
            line.split(' ')
                .map(|num| num.parse::<i64>().unwrap())
                .collect()
        })
        .collect();
    let mut sum: i64 = 0;
    for i in lines.iter() {
        sum += find_next(i);
    }
    println!("{sum}");
}
