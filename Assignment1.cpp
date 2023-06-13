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
        cout << "Move " << count << ": move disk " << disk << " from " << source << " to " << dest << endl;
}

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

void HanoiA2_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    move(disk, A2, A3, count);
    move(disk, A3, A4, count);
    move(disk, A4, A5, count);
    HanoiA3_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
}

void HanoiA3_to_A5(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){ //fix
    if(disk == 1){
        move(disk, A3, A4, count);
        move(disk, A4, A5, count);
    }else if(disk >= 2){
        move(disk, A3, A4, count);
        move(disk, A4, A5, count);
    }
}
//helps with destination tracking and pushing forward into the 
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
*/