#include <iostream>

using namespace std;

void move(int disk, char source, char dest, int &count);
void Hanoi(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiS_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiA5_to_A3(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiA2_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiA3_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiA4_to_D(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);
void HanoiFin(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count);

void move(int disk, char source, char dest, int &count) {
    count++;
    if (count <= 100 || count > count - 100) {
        cout << "Move " << count << ": move disk " << disk << " from " << source << " to " << dest << endl;
    }
}
//initializes k - 1 disks and continues to begin the tower
void Hanoi(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if(disk == 1){
        move(disk, Start, A1, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
        move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }else if(disk >= 2){
        HanoiS_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, Start, A1, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
        move(disk, A3, A4, count);
        HanoiA4_to_D(disk, Start, A1, A2, A3, A4, A5, Dest, count);
        HanoiFin(disk, Start, A1, A2, A3, A4, A5, Dest, count);
    }
}

//Starts the original disk which starts n = 1
void HanoiS_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if(disk == 1){
        move(disk, Start, A1, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
        move(disk, A3, A4, count);
        move(disk, A4, A5, count);
    }else if(disk >= 2){
        HanoiS_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, Start, A1, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
        move(disk, A3, A4, count);
        HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, A4, A5, count);
        //HanoiA2_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        HanoiA3_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
    }
} //for n = 4, move 24 must be move disk 3 from 4 to 5

//Moves disk where k - 1 == n faster to the auxiliary which is 3
void HanoiA5_to_A3(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if (disk == 1){
        move(disk, A5, A1, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
    }else if(disk >= 2){
        HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, A5, A1, count);
        HanoiA3_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, A1, A2, count);
        move(disk, A2, A3, count);
        move(disk, A3, A4, count);
        //HanoiA4_to_D(disk, Start, A1, A2, A3, A4, A5, Dest, count);
        //move(disk, A5, A1, count);
        //move(disk, A1, A2, count);
    }
}
//presents option to go deeper as well as move disks to peg #5
void HanoiA2_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    move(disk, A2, A3, count);
    move(disk, A3, A4, count);
    move(disk, A4, A5, count);
    HanoiA3_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
}
//presents faster option to have smaller disks go to peg #5 faster
void HanoiA3_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){ //fix
    if(disk == 1){
        move(disk, A3, A4, count);
        move(disk, A4, A5, count);
    }else if(disk >= 2){
        move(disk, A3, A4, count);
        move(disk, A4, A5, count);
    }
}
//helps with destination tracking and pushing forward into the k-1 disk
void HanoiA4_to_D(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if(disk == 1){
        move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }else if(disk == 2){
        HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, A4, A5, count);
    }else if(disk >= 3){
        move(disk, A4, Dest, count);
        HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
    }
}
    //exit code to follow through with destinations
 void HanoiFin(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if(disk <= 0) return;
    if(disk == 1){
        move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }else if(disk == 2){
        //move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }
    HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
    HanoiFin(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
}

int main(){
    int n = 0; //test how many disks you'd like to play with
    int count = 0;

    cout << "Please enter how many disks we will be playing with today: " << endl;
    cin >> n;

    Hanoi(n, 'S', 'A1', 'A2', 'A3', 'A4', 'A5', 'D', count); //Edges in row
    cout << "Total moves for the disk was: "<< count << endl;
    return 0;
}

//valid moves
// S -> A1 -> A2 -> A3 -> A4 -> A5 -> A1 -> A4 -> D
//all moves will be 7 steps at least
//no H4->D disk-1

/*
HYPOTHESIS - I believe the amount of moves, given the material we've studied will skyrocket
given that the time complexity is O(2^n). I would say that n = 10 will result in more than
50,000 moves.

This code provides a solver for the classic Towers of Hanoi problem. The Towers of Hanoi 
is a mathematical puzzle that involves moving a stack of disks from one tower to another, 
using auxiliary towers, with the constraint that a larger disk must never be placed on 
top of a smaller disk.
The code is implemented in C++ and follows a recursive approach to solve the problem. 
It utilizes several helper functions to break down the problem into smaller subproblems 
and perform the necessary moves.
The main function, main(), prompts the user to enter the number of disks they want to 
play with. It then calls the Hanoi() function with the specified number of disks and the 
tower labels ('S', 'A1', 'A2', 'A3', 'A4', 'A5', 'D') representing the source tower, 
auxiliary towers, and destination tower, respectively. The function also initializes a 
counter variable count to keep track of the total number of moves.
The Hanoi() function is the primary recursive function that solves the Towers of Hanoi 
problem. It takes the number of disks, the tower labels, and the count as parameters. 
The function is divided into base cases and recursive cases.
In the base case (disk == 1), the function directly moves the disk from the source tower 
to the destination tower using a series of move() function calls. The move() function 
increments the count and prints the details of the move.
In the recursive cases (disk >= 2), the function follows a specific sequence of moves 
to solve the problem. It first recursively calls HanoiS_to_A5() to move disk-1 disks 
from the source tower to the auxiliary tower A5. Then it performs a series of moves 
to move the largest disk from the source tower to the destination tower via the auxiliary 
towers A1, A2, A3, and A4. After that, it recursively calls HanoiA4_to_D() to move the 
remaining disks from A4 to the destination tower. Finally, it calls HanoiFin() to handle 
the remaining disks and complete the solution.
The other helper functions (HanoiS_to_A5(), HanoiA5_to_A3(), HanoiA2_to_A5(), HanoiA3_to_A5(), 
HanoiA4_to_D(), HanoiFin()) are used to handle specific move sequences within the recursive 
cases of Hanoi().
At the end of the main() function, the total number of moves (count) is printed as the output.

Time Complexity:
The time complexity of the code is determined by the number of moves required to 
solve the Towers of Hanoi problem for a given number of disks (n). The time complexity 
can be represented as O(2^n), where n is the number of disks. This is because each 
disk can be moved twice (once from the source to an auxiliary tower and once from 
the auxiliary tower to the destination) and there are 2^n - 1 total moves required 
to solve the problem.

Space Complexity:
The space complexity of the code is O(1). It does not utilize any additional data 
structures that grow with the input size (n). The space required is constant, as 
it only uses a few variables to keep track of the state of the algorithm (such as 
disk, source, dest, and count). The space complexity does not depend on the number 
of disks being used.

Please enter how many disks we will be playing with today: 
1
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to D
Total moves for the disk was: 5

Please enter how many disks we will be playing with today: 
2
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 2 from 4 to D
Move 15: move disk 1 from 5 to 1
Move 16: move disk 1 from 1 to 2
Move 17: move disk 1 from 2 to 3
Move 18: move disk 1 from 3 to 4
Move 19: move disk 1 from 4 to D
Total moves for the disk was: 19

Please enter how many disks we will be playing with today: 
3
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 3 from 4 to D
Move 21: move disk 1 from 5 to 1
Move 22: move disk 1 from 1 to 2
Move 23: move disk 1 from 2 to 3
Move 24: move disk 2 from 5 to 1
Move 25: move disk 1 from 3 to 4
Move 26: move disk 1 from 4 to 5
Move 27: move disk 2 from 1 to 2
Move 28: move disk 2 from 2 to 3
Move 29: move disk 2 from 3 to 4
Move 30: move disk 1 from 5 to 1
Move 31: move disk 1 from 1 to 2
Move 32: move disk 1 from 2 to 3
Move 33: move disk 2 from 5 to 1
Move 34: move disk 1 from 3 to 4
Move 35: move disk 1 from 4 to 5
Move 36: move disk 2 from 1 to 2
Move 37: move disk 2 from 2 to 3
Move 38: move disk 2 from 3 to 4
Move 39: move disk 2 from 4 to D
Move 40: move disk 1 from 5 to 1
Move 41: move disk 1 from 1 to 2
Move 42: move disk 1 from 2 to 3
Move 43: move disk 1 from 3 to 4
Move 44: move disk 1 from 4 to D
Total moves for the disk was: 44

Please enter how many disks we will be playing with today: 
4
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 4 from 4 to D
Move 37: move disk 1 from 5 to 1
Move 38: move disk 1 from 1 to 2
Move 39: move disk 1 from 2 to 3
Move 40: move disk 2 from 5 to 1
Move 41: move disk 1 from 3 to 4
Move 42: move disk 1 from 4 to 5
Move 43: move disk 2 from 1 to 2
Move 44: move disk 2 from 2 to 3
Move 45: move disk 2 from 3 to 4
Move 46: move disk 3 from 5 to 1
Move 47: move disk 2 from 3 to 4
Move 48: move disk 2 from 4 to 5
Move 49: move disk 3 from 1 to 2
Move 50: move disk 3 from 2 to 3
Move 51: move disk 3 from 3 to 4
Move 52: move disk 1 from 5 to 1
Move 53: move disk 1 from 1 to 2
Move 54: move disk 1 from 2 to 3
Move 55: move disk 2 from 5 to 1
Move 56: move disk 1 from 3 to 4
Move 57: move disk 1 from 4 to 5
Move 58: move disk 2 from 1 to 2
Move 59: move disk 2 from 2 to 3
Move 60: move disk 2 from 3 to 4
Move 61: move disk 3 from 5 to 1
Move 62: move disk 2 from 3 to 4
Move 63: move disk 2 from 4 to 5
Move 64: move disk 3 from 1 to 2
Move 65: move disk 3 from 2 to 3
Move 66: move disk 3 from 3 to 4
Move 67: move disk 1 from 5 to 1
Move 68: move disk 1 from 1 to 2
Move 69: move disk 1 from 2 to 3
Move 70: move disk 2 from 5 to 1
Move 71: move disk 1 from 3 to 4
Move 72: move disk 1 from 4 to 5
Move 73: move disk 2 from 1 to 2
Move 74: move disk 2 from 2 to 3
Move 75: move disk 2 from 3 to 4
Move 76: move disk 2 from 4 to D
Move 77: move disk 1 from 5 to 1
Move 78: move disk 1 from 1 to 2
Move 79: move disk 1 from 2 to 3
Move 80: move disk 1 from 3 to 4
Move 81: move disk 1 from 4 to D
Total moves for the disk was: 81

Please enter how many disks we will be playing with today: 
5
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 5 from 4 to D
Move 59: move disk 1 from 5 to 1
Move 60: move disk 1 from 1 to 2
Move 61: move disk 1 from 2 to 3
Move 62: move disk 2 from 5 to 1
Move 63: move disk 1 from 3 to 4
Move 64: move disk 1 from 4 to 5
Move 65: move disk 2 from 1 to 2
Move 66: move disk 2 from 2 to 3
Move 67: move disk 2 from 3 to 4
Move 68: move disk 3 from 5 to 1
Move 69: move disk 2 from 3 to 4
Move 70: move disk 2 from 4 to 5
Move 71: move disk 3 from 1 to 2
Move 72: move disk 3 from 2 to 3
Move 73: move disk 3 from 3 to 4
Move 74: move disk 4 from 5 to 1
Move 75: move disk 3 from 3 to 4
Move 76: move disk 3 from 4 to 5
Move 77: move disk 4 from 1 to 2
Move 78: move disk 4 from 2 to 3
Move 79: move disk 4 from 3 to 4
Move 80: move disk 1 from 5 to 1
Move 81: move disk 1 from 1 to 2
Move 82: move disk 1 from 2 to 3
Move 83: move disk 2 from 5 to 1
Move 84: move disk 1 from 3 to 4
Move 85: move disk 1 from 4 to 5
Move 86: move disk 2 from 1 to 2
Move 87: move disk 2 from 2 to 3
Move 88: move disk 2 from 3 to 4
Move 89: move disk 3 from 5 to 1
Move 90: move disk 2 from 3 to 4
Move 91: move disk 2 from 4 to 5
Move 92: move disk 3 from 1 to 2
Move 93: move disk 3 from 2 to 3
Move 94: move disk 3 from 3 to 4
Move 95: move disk 4 from 5 to 1
Move 96: move disk 3 from 3 to 4
Move 97: move disk 3 from 4 to 5
Move 98: move disk 4 from 1 to 2
Move 99: move disk 4 from 2 to 3
Move 100: move disk 4 from 3 to 4
Move 101: move disk 1 from 5 to 1
Move 102: move disk 1 from 1 to 2
Move 103: move disk 1 from 2 to 3
Move 104: move disk 2 from 5 to 1
Move 105: move disk 1 from 3 to 4
Move 106: move disk 1 from 4 to 5
Move 107: move disk 2 from 1 to 2
Move 108: move disk 2 from 2 to 3
Move 109: move disk 2 from 3 to 4
Move 110: move disk 3 from 5 to 1
Move 111: move disk 2 from 3 to 4
Move 112: move disk 2 from 4 to 5
Move 113: move disk 3 from 1 to 2
Move 114: move disk 3 from 2 to 3
Move 115: move disk 3 from 3 to 4
Move 116: move disk 1 from 5 to 1
Move 117: move disk 1 from 1 to 2
Move 118: move disk 1 from 2 to 3
Move 119: move disk 2 from 5 to 1
Move 120: move disk 1 from 3 to 4
Move 121: move disk 1 from 4 to 5
Move 122: move disk 2 from 1 to 2
Move 123: move disk 2 from 2 to 3
Move 124: move disk 2 from 3 to 4
Move 125: move disk 2 from 4 to D
Move 126: move disk 1 from 5 to 1
Move 127: move disk 1 from 1 to 2
Move 128: move disk 1 from 2 to 3
Move 129: move disk 1 from 3 to 4
Move 130: move disk 1 from 4 to D
Total moves for the disk was: 130

Please enter how many disks we will be playing with today: 
6
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 1 from 5 to 1
Move 59: move disk 1 from 1 to 2
Move 60: move disk 1 from 2 to 3
Move 61: move disk 2 from 5 to 1
Move 62: move disk 1 from 3 to 4
Move 63: move disk 1 from 4 to 5
Move 64: move disk 2 from 1 to 2
Move 65: move disk 2 from 2 to 3
Move 66: move disk 2 from 3 to 4
Move 67: move disk 3 from 5 to 1
Move 68: move disk 2 from 3 to 4
Move 69: move disk 2 from 4 to 5
Move 70: move disk 3 from 1 to 2
Move 71: move disk 3 from 2 to 3
Move 72: move disk 3 from 3 to 4
Move 73: move disk 4 from 5 to 1
Move 74: move disk 3 from 3 to 4
Move 75: move disk 3 from 4 to 5
Move 76: move disk 4 from 1 to 2
Move 77: move disk 4 from 2 to 3
Move 78: move disk 4 from 3 to 4
Move 79: move disk 5 from 4 to 5
Move 80: move disk 4 from 3 to 4
Move 81: move disk 4 from 4 to 5
Move 82: move disk 6 from S to 1
Move 83: move disk 6 from 1 to 2
Move 84: move disk 6 from 2 to 3
Move 85: move disk 6 from 3 to 4
Move 86: move disk 6 from 4 to D
Move 87: move disk 1 from 5 to 1
Move 88: move disk 1 from 1 to 2
Move 89: move disk 1 from 2 to 3
Move 90: move disk 2 from 5 to 1
Move 91: move disk 1 from 3 to 4
Move 92: move disk 1 from 4 to 5
Move 93: move disk 2 from 1 to 2
Move 94: move disk 2 from 2 to 3
Move 95: move disk 2 from 3 to 4
Move 96: move disk 3 from 5 to 1
Move 97: move disk 2 from 3 to 4
Move 98: move disk 2 from 4 to 5
Move 99: move disk 3 from 1 to 2
Move 100: move disk 3 from 2 to 3
Move 101: move disk 3 from 3 to 4
Move 102: move disk 4 from 5 to 1
Move 103: move disk 3 from 3 to 4
Move 104: move disk 3 from 4 to 5
Move 105: move disk 4 from 1 to 2
Move 106: move disk 4 from 2 to 3
Move 107: move disk 4 from 3 to 4
Move 108: move disk 5 from 5 to 1
Move 109: move disk 4 from 3 to 4
Move 110: move disk 4 from 4 to 5
Move 111: move disk 5 from 1 to 2
Move 112: move disk 5 from 2 to 3
Move 113: move disk 5 from 3 to 4
Move 114: move disk 1 from 5 to 1
Move 115: move disk 1 from 1 to 2
Move 116: move disk 1 from 2 to 3
Move 117: move disk 2 from 5 to 1
Move 118: move disk 1 from 3 to 4
Move 119: move disk 1 from 4 to 5
Move 120: move disk 2 from 1 to 2
Move 121: move disk 2 from 2 to 3
Move 122: move disk 2 from 3 to 4
Move 123: move disk 3 from 5 to 1
Move 124: move disk 2 from 3 to 4
Move 125: move disk 2 from 4 to 5
Move 126: move disk 3 from 1 to 2
Move 127: move disk 3 from 2 to 3
Move 128: move disk 3 from 3 to 4
Move 129: move disk 4 from 5 to 1
Move 130: move disk 3 from 3 to 4
Move 131: move disk 3 from 4 to 5
Move 132: move disk 4 from 1 to 2
Move 133: move disk 4 from 2 to 3
Move 134: move disk 4 from 3 to 4
Move 135: move disk 5 from 5 to 1
Move 136: move disk 4 from 3 to 4
Move 137: move disk 4 from 4 to 5
Move 138: move disk 5 from 1 to 2
Move 139: move disk 5 from 2 to 3
Move 140: move disk 5 from 3 to 4
Move 141: move disk 1 from 5 to 1
Move 142: move disk 1 from 1 to 2
Move 143: move disk 1 from 2 to 3
Move 144: move disk 2 from 5 to 1
Move 145: move disk 1 from 3 to 4
Move 146: move disk 1 from 4 to 5
Move 147: move disk 2 from 1 to 2
Move 148: move disk 2 from 2 to 3
Move 149: move disk 2 from 3 to 4
Move 150: move disk 3 from 5 to 1
Move 151: move disk 2 from 3 to 4
Move 152: move disk 2 from 4 to 5
Move 153: move disk 3 from 1 to 2
Move 154: move disk 3 from 2 to 3
Move 155: move disk 3 from 3 to 4
Move 156: move disk 4 from 5 to 1
Move 157: move disk 3 from 3 to 4
Move 158: move disk 3 from 4 to 5
Move 159: move disk 4 from 1 to 2
Move 160: move disk 4 from 2 to 3
Move 161: move disk 4 from 3 to 4
Move 162: move disk 1 from 5 to 1
Move 163: move disk 1 from 1 to 2
Move 164: move disk 1 from 2 to 3
Move 165: move disk 2 from 5 to 1
Move 166: move disk 1 from 3 to 4
Move 167: move disk 1 from 4 to 5
Move 168: move disk 2 from 1 to 2
Move 169: move disk 2 from 2 to 3
Move 170: move disk 2 from 3 to 4
Move 171: move disk 3 from 5 to 1
Move 172: move disk 2 from 3 to 4
Move 173: move disk 2 from 4 to 5
Move 174: move disk 3 from 1 to 2
Move 175: move disk 3 from 2 to 3
Move 176: move disk 3 from 3 to 4
Move 177: move disk 1 from 5 to 1
Move 178: move disk 1 from 1 to 2
Move 179: move disk 1 from 2 to 3
Move 180: move disk 2 from 5 to 1
Move 181: move disk 1 from 3 to 4
Move 182: move disk 1 from 4 to 5
Move 183: move disk 2 from 1 to 2
Move 184: move disk 2 from 2 to 3
Move 185: move disk 2 from 3 to 4
Move 186: move disk 2 from 4 to D
Move 187: move disk 1 from 5 to 1
Move 188: move disk 1 from 1 to 2
Move 189: move disk 1 from 2 to 3
Move 190: move disk 1 from 3 to 4
Move 191: move disk 1 from 4 to D
Total moves for the disk was: 191

Please enter how many disks we will be playing with today: 
7
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 1 from 5 to 1
Move 59: move disk 1 from 1 to 2
Move 60: move disk 1 from 2 to 3
Move 61: move disk 2 from 5 to 1
Move 62: move disk 1 from 3 to 4
Move 63: move disk 1 from 4 to 5
Move 64: move disk 2 from 1 to 2
Move 65: move disk 2 from 2 to 3
Move 66: move disk 2 from 3 to 4
Move 67: move disk 3 from 5 to 1
Move 68: move disk 2 from 3 to 4
Move 69: move disk 2 from 4 to 5
Move 70: move disk 3 from 1 to 2
Move 71: move disk 3 from 2 to 3
Move 72: move disk 3 from 3 to 4
Move 73: move disk 4 from 5 to 1
Move 74: move disk 3 from 3 to 4
Move 75: move disk 3 from 4 to 5
Move 76: move disk 4 from 1 to 2
Move 77: move disk 4 from 2 to 3
Move 78: move disk 4 from 3 to 4
Move 79: move disk 5 from 4 to 5
Move 80: move disk 4 from 3 to 4
Move 81: move disk 4 from 4 to 5
Move 82: move disk 6 from S to 1
Move 83: move disk 6 from 1 to 2
Move 84: move disk 6 from 2 to 3
Move 85: move disk 6 from 3 to 4
Move 86: move disk 1 from 5 to 1
Move 87: move disk 1 from 1 to 2
Move 88: move disk 1 from 2 to 3
Move 89: move disk 2 from 5 to 1
Move 90: move disk 1 from 3 to 4
Move 91: move disk 1 from 4 to 5
Move 92: move disk 2 from 1 to 2
Move 93: move disk 2 from 2 to 3
Move 94: move disk 2 from 3 to 4
Move 95: move disk 3 from 5 to 1
Move 96: move disk 2 from 3 to 4
Move 97: move disk 2 from 4 to 5
Move 98: move disk 3 from 1 to 2
Move 99: move disk 3 from 2 to 3
Move 100: move disk 3 from 3 to 4
... (Could not get to work so this was done by hand)
Move 164: move disk 2 from 3 to 4
Move 165: move disk 2 from 4 to 5
Move 166: move disk 3 from 1 to 2
Move 167: move disk 3 from 2 to 3
Move 168: move disk 3 from 3 to 4
Move 169: move disk 4 from 5 to 1
Move 170: move disk 3 from 3 to 4
Move 171: move disk 3 from 4 to 5
Move 172: move disk 4 from 1 to 2
Move 173: move disk 4 from 2 to 3
Move 174: move disk 4 from 3 to 4
Move 175: move disk 5 from 5 to 1
Move 176: move disk 4 from 3 to 4
Move 177: move disk 4 from 4 to 5
Move 178: move disk 5 from 1 to 2
Move 179: move disk 5 from 2 to 3
Move 180: move disk 5 from 3 to 4
Move 181: move disk 6 from 5 to 1
Move 182: move disk 5 from 3 to 4
Move 183: move disk 5 from 4 to 5
Move 184: move disk 6 from 1 to 2
Move 185: move disk 6 from 2 to 3
Move 186: move disk 6 from 3 to 4
Move 187: move disk 1 from 5 to 1
Move 188: move disk 1 from 1 to 2
Move 189: move disk 1 from 2 to 3
Move 190: move disk 2 from 5 to 1
Move 191: move disk 1 from 3 to 4
Move 192: move disk 1 from 4 to 5
Move 193: move disk 2 from 1 to 2
Move 194: move disk 2 from 2 to 3
Move 195: move disk 2 from 3 to 4
Move 196: move disk 3 from 5 to 1
Move 197: move disk 2 from 3 to 4
Move 198: move disk 2 from 4 to 5
Move 199: move disk 3 from 1 to 2
Move 200: move disk 3 from 2 to 3
Move 201: move disk 3 from 3 to 4
Move 202: move disk 4 from 5 to 1
Move 203: move disk 3 from 3 to 4
Move 204: move disk 3 from 4 to 5
Move 205: move disk 4 from 1 to 2
Move 206: move disk 4 from 2 to 3
Move 207: move disk 4 from 3 to 4
Move 208: move disk 5 from 5 to 1
Move 209: move disk 4 from 3 to 4
Move 210: move disk 4 from 4 to 5
Move 211: move disk 5 from 1 to 2
Move 212: move disk 5 from 2 to 3
Move 213: move disk 5 from 3 to 4
Move 214: move disk 1 from 5 to 1
Move 215: move disk 1 from 1 to 2
Move 216: move disk 1 from 2 to 3
Move 217: move disk 2 from 5 to 1
Move 218: move disk 1 from 3 to 4
Move 219: move disk 1 from 4 to 5
Move 220: move disk 2 from 1 to 2
Move 221: move disk 2 from 2 to 3
Move 222: move disk 2 from 3 to 4
Move 223: move disk 3 from 5 to 1
Move 224: move disk 2 from 3 to 4
Move 225: move disk 2 from 4 to 5
Move 226: move disk 3 from 1 to 2
Move 227: move disk 3 from 2 to 3
Move 228: move disk 3 from 3 to 4
Move 229: move disk 4 from 5 to 1
Move 230: move disk 3 from 3 to 4
Move 231: move disk 3 from 4 to 5
Move 232: move disk 4 from 1 to 2
Move 233: move disk 4 from 2 to 3
Move 234: move disk 4 from 3 to 4
Move 235: move disk 1 from 5 to 1
Move 236: move disk 1 from 1 to 2
Move 237: move disk 1 from 2 to 3
Move 238: move disk 2 from 5 to 1
Move 239: move disk 1 from 3 to 4
Move 240: move disk 1 from 4 to 5
Move 241: move disk 2 from 1 to 2
Move 242: move disk 2 from 2 to 3
Move 243: move disk 2 from 3 to 4
Move 244: move disk 3 from 5 to 1
Move 245: move disk 2 from 3 to 4
Move 246: move disk 2 from 4 to 5
Move 247: move disk 3 from 1 to 2
Move 248: move disk 3 from 2 to 3
Move 249: move disk 3 from 3 to 4
Move 250: move disk 1 from 5 to 1
Move 251: move disk 1 from 1 to 2
Move 252: move disk 1 from 2 to 3
Move 253: move disk 2 from 5 to 1
Move 254: move disk 1 from 3 to 4
Move 255: move disk 1 from 4 to 5
Move 256: move disk 2 from 1 to 2
Move 257: move disk 2 from 2 to 3
Move 258: move disk 2 from 3 to 4
Move 259: move disk 2 from 4 to D
Move 260: move disk 1 from 5 to 1
Move 261: move disk 1 from 1 to 2
Move 262: move disk 1 from 2 to 3
Move 263: move disk 1 from 3 to 4
Move 264: move disk 1 from 4 to D

Please enter how many disks we will be playing with today: 
8
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 1 from 5 to 1
Move 59: move disk 1 from 1 to 2
Move 60: move disk 1 from 2 to 3
Move 61: move disk 2 from 5 to 1
Move 62: move disk 1 from 3 to 4
Move 63: move disk 1 from 4 to 5
Move 64: move disk 2 from 1 to 2
Move 65: move disk 2 from 2 to 3
Move 66: move disk 2 from 3 to 4
Move 67: move disk 3 from 5 to 1
Move 68: move disk 2 from 3 to 4
Move 69: move disk 2 from 4 to 5
Move 70: move disk 3 from 1 to 2
Move 71: move disk 3 from 2 to 3
Move 72: move disk 3 from 3 to 4
Move 73: move disk 4 from 5 to 1
Move 74: move disk 3 from 3 to 4
Move 75: move disk 3 from 4 to 5
Move 76: move disk 4 from 1 to 2
Move 77: move disk 4 from 2 to 3
Move 78: move disk 4 from 3 to 4
Move 79: move disk 5 from 4 to 5
Move 80: move disk 4 from 3 to 4
Move 81: move disk 4 from 4 to 5
Move 82: move disk 6 from S to 1
Move 83: move disk 6 from 1 to 2
Move 84: move disk 6 from 2 to 3
Move 85: move disk 6 from 3 to 4
Move 86: move disk 1 from 5 to 1
Move 87: move disk 1 from 1 to 2
Move 88: move disk 1 from 2 to 3
Move 89: move disk 2 from 5 to 1
Move 90: move disk 1 from 3 to 4
Move 91: move disk 1 from 4 to 5
Move 92: move disk 2 from 1 to 2
Move 93: move disk 2 from 2 to 3
Move 94: move disk 2 from 3 to 4
Move 95: move disk 3 from 5 to 1
Move 96: move disk 2 from 3 to 4
Move 97: move disk 2 from 4 to 5
Move 98: move disk 3 from 1 to 2
Move 99: move disk 3 from 2 to 3
Move 100: move disk 3 from 3 to 4
... (Could not get to work so this was done by hand)
Move 249: move disk 2 from 3 to 4
Move 250: move disk 2 from 4 to 5
Move 251: move disk 3 from 1 to 2
Move 252: move disk 3 from 2 to 3
Move 253: move disk 3 from 3 to 4
Move 254: move disk 4 from 5 to 1
Move 255: move disk 3 from 3 to 4
Move 256: move disk 3 from 4 to 5
Move 257: move disk 4 from 1 to 2
Move 258: move disk 4 from 2 to 3
Move 259: move disk 4 from 3 to 4
Move 260: move disk 5 from 5 to 1
Move 261: move disk 4 from 3 to 4
Move 262: move disk 4 from 4 to 5
Move 263: move disk 5 from 1 to 2
Move 264: move disk 5 from 2 to 3
Move 265: move disk 5 from 3 to 4
Move 266: move disk 6 from 5 to 1
Move 267: move disk 5 from 3 to 4
Move 268: move disk 5 from 4 to 5
Move 269: move disk 6 from 1 to 2
Move 270: move disk 6 from 2 to 3
Move 271: move disk 6 from 3 to 4
Move 272: move disk 1 from 5 to 1
Move 273: move disk 1 from 1 to 2
Move 274: move disk 1 from 2 to 3
Move 275: move disk 2 from 5 to 1
Move 276: move disk 1 from 3 to 4
Move 277: move disk 1 from 4 to 5
Move 278: move disk 2 from 1 to 2
Move 279: move disk 2 from 2 to 3
Move 280: move disk 2 from 3 to 4
Move 281: move disk 3 from 5 to 1
Move 282: move disk 2 from 3 to 4
Move 283: move disk 2 from 4 to 5
Move 284: move disk 3 from 1 to 2
Move 285: move disk 3 from 2 to 3
Move 286: move disk 3 from 3 to 4
Move 287: move disk 4 from 5 to 1
Move 288: move disk 3 from 3 to 4
Move 289: move disk 3 from 4 to 5
Move 290: move disk 4 from 1 to 2
Move 291: move disk 4 from 2 to 3
Move 292: move disk 4 from 3 to 4
Move 293: move disk 5 from 5 to 1
Move 294: move disk 4 from 3 to 4
Move 295: move disk 4 from 4 to 5
Move 296: move disk 5 from 1 to 2
Move 297: move disk 5 from 2 to 3
Move 298: move disk 5 from 3 to 4
Move 299: move disk 1 from 5 to 1
Move 300: move disk 1 from 1 to 2
Move 301: move disk 1 from 2 to 3
Move 302: move disk 2 from 5 to 1
Move 303: move disk 1 from 3 to 4
Move 304: move disk 1 from 4 to 5
Move 305: move disk 2 from 1 to 2
Move 306: move disk 2 from 2 to 3
Move 307: move disk 2 from 3 to 4
Move 308: move disk 3 from 5 to 1
Move 309: move disk 2 from 3 to 4
Move 310: move disk 2 from 4 to 5
Move 311: move disk 3 from 1 to 2
Move 312: move disk 3 from 2 to 3
Move 313: move disk 3 from 3 to 4
Move 314: move disk 4 from 5 to 1
Move 315: move disk 3 from 3 to 4
Move 316: move disk 3 from 4 to 5
Move 317: move disk 4 from 1 to 2
Move 318: move disk 4 from 2 to 3
Move 319: move disk 4 from 3 to 4
Move 320: move disk 1 from 5 to 1
Move 321: move disk 1 from 1 to 2
Move 322: move disk 1 from 2 to 3
Move 323: move disk 2 from 5 to 1
Move 324: move disk 1 from 3 to 4
Move 325: move disk 1 from 4 to 5
Move 326: move disk 2 from 1 to 2
Move 327: move disk 2 from 2 to 3
Move 328: move disk 2 from 3 to 4
Move 329: move disk 3 from 5 to 1
Move 330: move disk 2 from 3 to 4
Move 331: move disk 2 from 4 to 5
Move 332: move disk 3 from 1 to 2
Move 333: move disk 3 from 2 to 3
Move 334: move disk 3 from 3 to 4
Move 335: move disk 1 from 5 to 1
Move 336: move disk 1 from 1 to 2
Move 337: move disk 1 from 2 to 3
Move 338: move disk 2 from 5 to 1
Move 339: move disk 1 from 3 to 4
Move 340: move disk 1 from 4 to 5
Move 341: move disk 2 from 1 to 2
Move 342: move disk 2 from 2 to 3
Move 343: move disk 2 from 3 to 4
Move 344: move disk 2 from 4 to D
Move 345: move disk 1 from 5 to 1
Move 346: move disk 1 from 1 to 2
Move 347: move disk 1 from 2 to 3
Move 348: move disk 1 from 3 to 4
Move 349: move disk 1 from 4 to D
Total moves for the disk was: 349

Please enter how many disks we will be playing with today: 
9
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 1 from 5 to 1
Move 59: move disk 1 from 1 to 2
Move 60: move disk 1 from 2 to 3
Move 61: move disk 2 from 5 to 1
Move 62: move disk 1 from 3 to 4
Move 63: move disk 1 from 4 to 5
Move 64: move disk 2 from 1 to 2
Move 65: move disk 2 from 2 to 3
Move 66: move disk 2 from 3 to 4
Move 67: move disk 3 from 5 to 1
Move 68: move disk 2 from 3 to 4
Move 69: move disk 2 from 4 to 5
Move 70: move disk 3 from 1 to 2
Move 71: move disk 3 from 2 to 3
Move 72: move disk 3 from 3 to 4
Move 73: move disk 4 from 5 to 1
Move 74: move disk 3 from 3 to 4
Move 75: move disk 3 from 4 to 5
Move 76: move disk 4 from 1 to 2
Move 77: move disk 4 from 2 to 3
Move 78: move disk 4 from 3 to 4
Move 79: move disk 5 from 4 to 5
Move 80: move disk 4 from 3 to 4
Move 81: move disk 4 from 4 to 5
Move 82: move disk 6 from S to 1
Move 83: move disk 6 from 1 to 2
Move 84: move disk 6 from 2 to 3
Move 85: move disk 6 from 3 to 4
Move 86: move disk 1 from 5 to 1
Move 87: move disk 1 from 1 to 2
Move 88: move disk 1 from 2 to 3
Move 89: move disk 2 from 5 to 1
Move 90: move disk 1 from 3 to 4
Move 91: move disk 1 from 4 to 5
Move 92: move disk 2 from 1 to 2
Move 93: move disk 2 from 2 to 3
Move 94: move disk 2 from 3 to 4
Move 95: move disk 3 from 5 to 1
Move 96: move disk 2 from 3 to 4
Move 97: move disk 2 from 4 to 5
Move 98: move disk 3 from 1 to 2
Move 99: move disk 3 from 2 to 3
Move 100: move disk 3 from 3 to 4
... (Could not get to work so this was done by hand)
Move 346: move disk 2 from 3 to 4
Move 347: move disk 2 from 4 to 5
Move 348: move disk 3 from 1 to 2
Move 349: move disk 3 from 2 to 3
Move 350: move disk 3 from 3 to 4
Move 351: move disk 4 from 5 to 1
Move 352: move disk 3 from 3 to 4
Move 353: move disk 3 from 4 to 5
Move 354: move disk 4 from 1 to 2
Move 355: move disk 4 from 2 to 3
Move 356: move disk 4 from 3 to 4
Move 357: move disk 5 from 5 to 1
Move 358: move disk 4 from 3 to 4
Move 359: move disk 4 from 4 to 5
Move 360: move disk 5 from 1 to 2
Move 361: move disk 5 from 2 to 3
Move 362: move disk 5 from 3 to 4
Move 363: move disk 6 from 5 to 1
Move 364: move disk 5 from 3 to 4
Move 365: move disk 5 from 4 to 5
Move 366: move disk 6 from 1 to 2
Move 367: move disk 6 from 2 to 3
Move 368: move disk 6 from 3 to 4
Move 369: move disk 1 from 5 to 1
Move 370: move disk 1 from 1 to 2
Move 371: move disk 1 from 2 to 3
Move 372: move disk 2 from 5 to 1
Move 373: move disk 1 from 3 to 4
Move 374: move disk 1 from 4 to 5
Move 375: move disk 2 from 1 to 2
Move 376: move disk 2 from 2 to 3
Move 377: move disk 2 from 3 to 4
Move 378: move disk 3 from 5 to 1
Move 379: move disk 2 from 3 to 4
Move 380: move disk 2 from 4 to 5
Move 381: move disk 3 from 1 to 2
Move 382: move disk 3 from 2 to 3
Move 383: move disk 3 from 3 to 4
Move 384: move disk 4 from 5 to 1
Move 385: move disk 3 from 3 to 4
Move 386: move disk 3 from 4 to 5
Move 387: move disk 4 from 1 to 2
Move 388: move disk 4 from 2 to 3
Move 389: move disk 4 from 3 to 4
Move 390: move disk 5 from 5 to 1
Move 391: move disk 4 from 3 to 4
Move 392: move disk 4 from 4 to 5
Move 393: move disk 5 from 1 to 2
Move 394: move disk 5 from 2 to 3
Move 395: move disk 5 from 3 to 4
Move 396: move disk 1 from 5 to 1
Move 397: move disk 1 from 1 to 2
Move 398: move disk 1 from 2 to 3
Move 399: move disk 2 from 5 to 1
Move 400: move disk 1 from 3 to 4
Move 401: move disk 1 from 4 to 5
Move 402: move disk 2 from 1 to 2
Move 403: move disk 2 from 2 to 3
Move 404: move disk 2 from 3 to 4
Move 405: move disk 3 from 5 to 1
Move 406: move disk 2 from 3 to 4
Move 407: move disk 2 from 4 to 5
Move 408: move disk 3 from 1 to 2
Move 409: move disk 3 from 2 to 3
Move 410: move disk 3 from 3 to 4
Move 411: move disk 4 from 5 to 1
Move 412: move disk 3 from 3 to 4
Move 413: move disk 3 from 4 to 5
Move 414: move disk 4 from 1 to 2
Move 415: move disk 4 from 2 to 3
Move 416: move disk 4 from 3 to 4
Move 417: move disk 1 from 5 to 1
Move 418: move disk 1 from 1 to 2
Move 419: move disk 1 from 2 to 3
Move 420: move disk 2 from 5 to 1
Move 421: move disk 1 from 3 to 4
Move 422: move disk 1 from 4 to 5
Move 423: move disk 2 from 1 to 2
Move 424: move disk 2 from 2 to 3
Move 425: move disk 2 from 3 to 4
Move 426: move disk 3 from 5 to 1
Move 427: move disk 2 from 3 to 4
Move 428: move disk 2 from 4 to 5
Move 429: move disk 3 from 1 to 2
Move 430: move disk 3 from 2 to 3
Move 431: move disk 3 from 3 to 4
Move 432: move disk 1 from 5 to 1
Move 433: move disk 1 from 1 to 2
Move 434: move disk 1 from 2 to 3
Move 435: move disk 2 from 5 to 1
Move 436: move disk 1 from 3 to 4
Move 437: move disk 1 from 4 to 5
Move 438: move disk 2 from 1 to 2
Move 439: move disk 2 from 2 to 3
Move 440: move disk 2 from 3 to 4
Move 441: move disk 2 from 4 to D
Move 442: move disk 1 from 5 to 1
Move 443: move disk 1 from 1 to 2
Move 444: move disk 1 from 2 to 3
Move 445: move disk 1 from 3 to 4
Move 446: move disk 1 from 4 to D
Total moves for the disk was: 446

Please enter how many disks we will be playing with today: 
10
Move 1: move disk 1 from S to 1
Move 2: move disk 1 from 1 to 2
Move 3: move disk 1 from 2 to 3
Move 4: move disk 1 from 3 to 4
Move 5: move disk 1 from 4 to 5
Move 6: move disk 2 from S to 1
Move 7: move disk 2 from 1 to 2
Move 8: move disk 2 from 2 to 3
Move 9: move disk 2 from 3 to 4
Move 10: move disk 1 from 5 to 1
Move 11: move disk 1 from 1 to 2
Move 12: move disk 1 from 2 to 3
Move 13: move disk 2 from 4 to 5
Move 14: move disk 1 from 3 to 4
Move 15: move disk 1 from 4 to 5
Move 16: move disk 3 from S to 1
Move 17: move disk 3 from 1 to 2
Move 18: move disk 3 from 2 to 3
Move 19: move disk 3 from 3 to 4
Move 20: move disk 1 from 5 to 1
Move 21: move disk 1 from 1 to 2
Move 22: move disk 1 from 2 to 3
Move 23: move disk 2 from 5 to 1
Move 24: move disk 1 from 3 to 4
Move 25: move disk 1 from 4 to 5
Move 26: move disk 2 from 1 to 2
Move 27: move disk 2 from 2 to 3
Move 28: move disk 2 from 3 to 4
Move 29: move disk 3 from 4 to 5
Move 30: move disk 2 from 3 to 4
Move 31: move disk 2 from 4 to 5
Move 32: move disk 4 from S to 1
Move 33: move disk 4 from 1 to 2
Move 34: move disk 4 from 2 to 3
Move 35: move disk 4 from 3 to 4
Move 36: move disk 1 from 5 to 1
Move 37: move disk 1 from 1 to 2
Move 38: move disk 1 from 2 to 3
Move 39: move disk 2 from 5 to 1
Move 40: move disk 1 from 3 to 4
Move 41: move disk 1 from 4 to 5
Move 42: move disk 2 from 1 to 2
Move 43: move disk 2 from 2 to 3
Move 44: move disk 2 from 3 to 4
Move 45: move disk 3 from 5 to 1
Move 46: move disk 2 from 3 to 4
Move 47: move disk 2 from 4 to 5
Move 48: move disk 3 from 1 to 2
Move 49: move disk 3 from 2 to 3
Move 50: move disk 3 from 3 to 4
Move 51: move disk 4 from 4 to 5
Move 52: move disk 3 from 3 to 4
Move 53: move disk 3 from 4 to 5
Move 54: move disk 5 from S to 1
Move 55: move disk 5 from 1 to 2
Move 56: move disk 5 from 2 to 3
Move 57: move disk 5 from 3 to 4
Move 58: move disk 1 from 5 to 1
Move 59: move disk 1 from 1 to 2
Move 60: move disk 1 from 2 to 3
Move 61: move disk 2 from 5 to 1
Move 62: move disk 1 from 3 to 4
Move 63: move disk 1 from 4 to 5
Move 64: move disk 2 from 1 to 2
Move 65: move disk 2 from 2 to 3
Move 66: move disk 2 from 3 to 4
Move 67: move disk 3 from 5 to 1
Move 68: move disk 2 from 3 to 4
Move 69: move disk 2 from 4 to 5
Move 70: move disk 3 from 1 to 2
Move 71: move disk 3 from 2 to 3
Move 72: move disk 3 from 3 to 4
Move 73: move disk 4 from 5 to 1
Move 74: move disk 3 from 3 to 4
Move 75: move disk 3 from 4 to 5
Move 76: move disk 4 from 1 to 2
Move 77: move disk 4 from 2 to 3
Move 78: move disk 4 from 3 to 4
Move 79: move disk 5 from 4 to 5
Move 80: move disk 4 from 3 to 4
Move 81: move disk 4 from 4 to 5
Move 82: move disk 6 from S to 1
Move 83: move disk 6 from 1 to 2
Move 84: move disk 6 from 2 to 3
Move 85: move disk 6 from 3 to 4
Move 86: move disk 1 from 5 to 1
Move 87: move disk 1 from 1 to 2
Move 88: move disk 1 from 2 to 3
Move 89: move disk 2 from 5 to 1
Move 90: move disk 1 from 3 to 4
Move 91: move disk 1 from 4 to 5
Move 92: move disk 2 from 1 to 2
Move 93: move disk 2 from 2 to 3
Move 94: move disk 2 from 3 to 4
Move 95: move disk 3 from 5 to 1
Move 96: move disk 2 from 3 to 4
Move 97: move disk 2 from 4 to 5
Move 98: move disk 3 from 1 to 2
Move 99: move disk 3 from 2 to 3
Move 100: move disk 3 from 3 to 4
... (Could not get to work so this was done by hand)
Move 455: move disk 2 from 3 to 4
Move 456: move disk 2 from 4 to 5
Move 457: move disk 3 from 1 to 2
Move 458: move disk 3 from 2 to 3
Move 459: move disk 3 from 3 to 4
Move 460: move disk 4 from 5 to 1
Move 461: move disk 3 from 3 to 4
Move 462: move disk 3 from 4 to 5
Move 463: move disk 4 from 1 to 2
Move 464: move disk 4 from 2 to 3
Move 465: move disk 4 from 3 to 4
Move 466: move disk 5 from 5 to 1
Move 467: move disk 4 from 3 to 4
Move 468: move disk 4 from 4 to 5
Move 469: move disk 5 from 1 to 2
Move 470: move disk 5 from 2 to 3
Move 471: move disk 5 from 3 to 4
Move 472: move disk 6 from 5 to 1
Move 473: move disk 5 from 3 to 4
Move 474: move disk 5 from 4 to 5
Move 475: move disk 6 from 1 to 2
Move 476: move disk 6 from 2 to 3
Move 477: move disk 6 from 3 to 4
Move 478: move disk 1 from 5 to 1
Move 479: move disk 1 from 1 to 2
Move 480: move disk 1 from 2 to 3
Move 481: move disk 2 from 5 to 1
Move 482: move disk 1 from 3 to 4
Move 483: move disk 1 from 4 to 5
Move 484: move disk 2 from 1 to 2
Move 485: move disk 2 from 2 to 3
Move 486: move disk 2 from 3 to 4
Move 487: move disk 3 from 5 to 1
Move 488: move disk 2 from 3 to 4
Move 489: move disk 2 from 4 to 5
Move 490: move disk 3 from 1 to 2
Move 491: move disk 3 from 2 to 3
Move 492: move disk 3 from 3 to 4
Move 493: move disk 4 from 5 to 1
Move 494: move disk 3 from 3 to 4
Move 495: move disk 3 from 4 to 5
Move 496: move disk 4 from 1 to 2
Move 497: move disk 4 from 2 to 3
Move 498: move disk 4 from 3 to 4
Move 499: move disk 5 from 5 to 1
Move 500: move disk 4 from 3 to 4
Move 501: move disk 4 from 4 to 5
Move 502: move disk 5 from 1 to 2
Move 503: move disk 5 from 2 to 3
Move 504: move disk 5 from 3 to 4
Move 505: move disk 1 from 5 to 1
Move 506: move disk 1 from 1 to 2
Move 507: move disk 1 from 2 to 3
Move 508: move disk 2 from 5 to 1
Move 509: move disk 1 from 3 to 4
Move 510: move disk 1 from 4 to 5
Move 511: move disk 2 from 1 to 2
Move 512: move disk 2 from 2 to 3
Move 513: move disk 2 from 3 to 4
Move 514: move disk 3 from 5 to 1
Move 515: move disk 2 from 3 to 4
Move 516: move disk 2 from 4 to 5
Move 517: move disk 3 from 1 to 2
Move 518: move disk 3 from 2 to 3
Move 519: move disk 3 from 3 to 4
Move 520: move disk 4 from 5 to 1
Move 521: move disk 3 from 3 to 4
Move 522: move disk 3 from 4 to 5
Move 523: move disk 4 from 1 to 2
Move 524: move disk 4 from 2 to 3
Move 525: move disk 4 from 3 to 4
Move 526: move disk 1 from 5 to 1
Move 527: move disk 1 from 1 to 2
Move 528: move disk 1 from 2 to 3
Move 529: move disk 2 from 5 to 1
Move 530: move disk 1 from 3 to 4
Move 531: move disk 1 from 4 to 5
Move 532: move disk 2 from 1 to 2
Move 533: move disk 2 from 2 to 3
Move 534: move disk 2 from 3 to 4
Move 535: move disk 3 from 5 to 1
Move 536: move disk 2 from 3 to 4
Move 537: move disk 2 from 4 to 5
Move 538: move disk 3 from 1 to 2
Move 539: move disk 3 from 2 to 3
Move 540: move disk 3 from 3 to 4
Move 541: move disk 1 from 5 to 1
Move 542: move disk 1 from 1 to 2
Move 543: move disk 1 from 2 to 3
Move 544: move disk 2 from 5 to 1
Move 545: move disk 1 from 3 to 4
Move 546: move disk 1 from 4 to 5
Move 547: move disk 2 from 1 to 2
Move 548: move disk 2 from 2 to 3
Move 549: move disk 2 from 3 to 4
Move 550: move disk 2 from 4 to D
Move 551: move disk 1 from 5 to 1
Move 552: move disk 1 from 1 to 2
Move 553: move disk 1 from 2 to 3
Move 554: move disk 1 from 3 to 4
Move 555: move disk 1 from 4 to D
Total moves for the disk was: 555
*/