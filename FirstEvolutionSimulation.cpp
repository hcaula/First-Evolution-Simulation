#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    double left;
    double right;
    double average //hello;
};

Node table[100];
int genNum = 0;

void sortWorld(){
    bool swaped = true;
    while (swaped){
        swaped = false;
        for (int i = 0; i < 100; i++){
            if (table[i].average < table[i+1].average){
                Node t = table[i];
                table[i] = table[i+1];
                table[i+1] = t;
                swaped = true;
            }
        }
    }
}

void showWorld(){
    double smallest = 10000;
    double biggest = -1;
    double sum = 0;
    cout << "Generation " << genNum << "\n";
    for(int i = 0; i < 100; i++){
        if (table[i].average < smallest){
            smallest = table[i].average;
        }
        if (table[i].average > biggest){
            biggest = table[i].average;
        }
        sum = sum + table[i].average;
        cout << table[i].average << " ";
        if (i == 99){
            cout << "\n";
        }
    }
    cout << "Worst: " << smallest
    << "\nAverage: " << (sum/100)
    << "\nBest: " << biggest << "\n\n";
}

void reproduce(){
    genNum++;
    for(int i = 0; i < 50; i = i + 2){
        table[i+50].left = table[i].left;
        table[i+50].right = table[i+1].left;
        table[i+50].average = (table[i+50].left+table[i+50].right)/2;
        table[i+51].left = table[i].right;
        table[i+51].right = table[i+1].right;
        table[i+51].average = (table[i+51].left+table[i+51].right)/2;
    }
    sortWorld();
    showWorld();
}

void createWorld(){
    for(int i = 0; i < 100; i++){
        Node N;
        N.left = (rand() % 10000);
        N.right = (rand() % 10000);
        N.average = (N.left + N.right)/2;
        table[i] = N;
    }
    sortWorld();
    showWorld();
}

void doItTill(int n){
    createWorld();
    while (genNum < n){
        reproduce();
    }
}

int main() {
    doItTill(15);
    return 0;
}
