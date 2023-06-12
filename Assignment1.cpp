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
        HanoiA2_to_A5(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
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
        HanoiA4_to_D(disk, Start, A1, A2, A3, A4, A5, Dest, count);
        move(disk, A5, A1, count);
        move(disk, A1, A2, count);
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

 void HanoiFin(int disk, char Start, char A1, char A2, char A3, char A4, char A5, char Dest, int &count){
    if(disk <= 0) return;
    if(disk == 1){
        move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }else if(disk == 2){
        move(disk, A3, A4, count);
        move(disk, A4, Dest, count);
    }
    HanoiA5_to_A3(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);//changed
    HanoiFin(disk-1, Start, A1, A2, A3, A4, A5, Dest, count);
}

int main(){
    int n = 0; //test how many disks you'd like to play with
    int count = 0;

    cout << "Please enter how many disks we will be playing with today: " << endl;
    cin >> n;

    Hanoi(n, 'S', 'A1', 'A2', 'A3', 'A4', 'A5', 'D', count);
    cout << "Total moves for the disk was: "<< count << endl;
    return 0;
}

    //valid moves
    // S -> A1 -> A2 -> A3 -> A4 -> A5 -> A1 -> A4 -> D
    //all moves will be 7 steps at least
    //no H4->D disk-1