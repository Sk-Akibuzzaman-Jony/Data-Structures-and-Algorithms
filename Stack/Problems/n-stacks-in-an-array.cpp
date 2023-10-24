// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0

#include <bits/stdc++.h> 
class NStack
{
public:
    int* arr;
    int* top;
    int* next;

    int freeSpot;

    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for(int i = 0; i < N; i++){
            top[i] = -1;
        }

        for(int i = 0; i<S; i++){
            next[i] = i+1;
        }
        next[S-1] = -1;

        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow
        if(freeSpot == -1){
            return false;
        }

        //get index
        int index = freeSpot;

        //update free spot 
        freeSpot = next[index];

        //insert value
        arr[index] = x;

        //update next arr
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;


    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow
        if(top[m-1] == -1){
            return -1;
        }

        // pop is literry the opposite of push

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];

    }
};
