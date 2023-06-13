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

/*
DATA STRUCTURES USED - Vectors, Arrays

The provided code performs binary search on different mutable arrays of varying sizes and 
measures the execution time for each search operation. It uses the fill function to populate 
the arrays with random integers and the binary_search function to perform the binary 
search algorithm. The arrays are defined as a vector of mutable vectors (arrays). The 
code iterates over each array, fills it with random values, performs 10,000,000 search 
operations on each array, and records the duration of each search. The durations are stored 
in a separate vector (durations) and then displayed on the console.

Time Complexity:
The time complexity of the binary search algorithm is O(log n), where n is the size of the 
input array. In this code, binary search is performed 10,000,000 times for each array in 
the arrays vector. Therefore, the time complexity of the code can be considered as 
O(10,000,000 * log n), where n represents the size of each array.

Space Complexity:
The space complexity of the code is determined by the space used to store the arrays and the 
durations vector. The space required for the arrays is proportional to the total number of 
elements across all arrays. The space required for the durations vector is proportional to 
the number of arrays. Therefore, the space complexity can be considered as O(N), where N 
is the total number of elements across all arrays plus the number of arrays.

Run 1::
Time 1: 1.1925203 seconds
Time 2: 1.4850099 seconds
Time 3: 1.5953257 seconds
Time 4: 1.7131715 seconds
Time 5: 2.0921714 seconds
Time 6: 2.8639674 seconds
Time 7: 2.437687 seconds
Time 8: 2.4179654 seconds
Time 9: 2.577816 seconds
Time 10: 2.7117438 seconds

Run2::
Time 1: 1.6071248 seconds
Time 2: 1.4526246 seconds
Time 3: 1.7735745 seconds
Time 4: 1.9741895 seconds
Time 5: 1.9435543 seconds
Time 6: 2.2024632 seconds
Time 7: 2.1590178 seconds
Time 8: 2.1225288 seconds
Time 9: 2.5231159 seconds
Time 10: 2.7715585 seconds

Run3::
Time 1: 1.5025101 seconds
Time 2: 1.5018165 seconds
Time 3: 2.18645 seconds
Time 4: 2.513827 seconds
Time 5: 2.2210145 seconds
Time 6: 2.2992594 seconds
Time 7: 2.240435 seconds
Time 8: 2.5571263 seconds
Time 9: 2.4283183 seconds
Time 10: 2.4862328 seconds
*/