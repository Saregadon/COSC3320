use rand::Rng; //random
use std::time::Instant; //time measurement

fn fill(arr: &mut [i32]) { //fill array with mutible ints with 32 bits
    let mut rng = rand::thread_rng();
    for i in arr.iter_mut() {
        *i = rng.gen_range(1..=1000);
    }
}

fn binary_search(arr: &[i32], target: i32) -> Option<usize> { //binary search function
    let mut left = 0;
    let mut right = arr.len() - 1;

    while left <= right {
        let mid = left + (right - left) / 2;

        if arr[mid] == target {
            return Some(mid);
        } else if arr[mid] < target {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    None
}

fn main() {
    let arrays = vec![ //mutable arrays
        vec![0; 100],
        vec![0; 200],
        vec![0; 400],
        vec![0; 800],
        vec![0; 1600],
        vec![0; 3200],
        vec![0; 6400],
        vec![0; 12800],
        vec![0; 25600],
        vec![0; 51200],
    ];

    let target = 2_147_483_647; //impossible number to find

    let mut durations = Vec::new(); //time measurement

    for arr in &arrays { //main
        fill(&mut arr.clone());
        let start = Instant::now();
        for _ in 0..10_000_000 {
            let _ = binary_search(&arr, target);
        }
        let end = Instant::now();
        let duration = end.duration_since(start).as_nanos();
        durations.push(duration);
    }

    for (i, duration) in durations.iter().enumerate() {
        println!("Time {}: {} nanoseconds", i + 1, duration);
    }
}
