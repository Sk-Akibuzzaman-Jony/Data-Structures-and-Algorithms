//https://www.codingninjas.com/studio/problems/n-queue-using-array_1170053?leftPanelTab=0

#include <bits/stdc++.h> 
class NQueue{
public:
    int* arr;
    int* next;
    int* front;
    int* rear;
    int freeSpot;
    NQueue(int n, int s){
        arr = new int[s];
        next = new int[s];
        front = new int[n];
        rear = new int[n];
        freeSpot = 0;

        for(int i = 0; i < s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
        for(int i = 0; i < n; i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        //overflow check
        if(freeSpot == -1) {
            return false;
        }
        
        //get index
        int index = freeSpot;

        //update free spot 
        freeSpot = next[index];

        if(front[m-1] == -1){
            front[m-1] = index;
        } else {
            next[rear[m-1]] = index;
        }

        // update next
        next[index] = -1;

        //update rear 
        rear[m-1] = index;

        //insert element
        arr[index] = x;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //underflow check
        if(front[m-1] == -1){
            return -1;
        }

        //get index
        int index = front[m-1];

        //move front
        front[m-1] = next[index];

        if (front[m-1] == -1) {
            rear[m-1] = -1;  // Update rear when the last element is removed.
        }

        //removing the link with index and freeSpot update
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
