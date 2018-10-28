/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArrayList.cpp
 * Author: Dell
 * 
 * Created on October 27, 2018, 5:17 PM
 */

#include "ArrayList.h"

ArrayList::ArrayList() {
    this->totalLength = 5;
    this->arr = new int[this->totalLength];
    this->index = 0;
    this->len = 0;
}

void ArrayList::insertAtStart(int value) {
    this->insertAt(0, value);
}

void ArrayList::insertAtEnd(int value) {
    insertAt(this->index, value);
}



void ArrayList::insertAt(int index, int value) {
    
    // check if array is full.
    if(this->index == this->totalLength) {
        incSizeBy(10);
    }
    
    
    // check if the index is valid.
    if(index < 0) {
        return;
    }
    
    // if index passed in is the location where the next element is to be inserted.
    
    if(index != this->index) {
        shiftRightFrom(index);
    }
    
    
    if(index > this->index) {
        index = this->index;
    }
    
    
    this->arr[index] = value;
    this->index++;
    this->len++;

}






void ArrayList::deleteFromStart() {
    deleteAt(0);
}

void ArrayList::deleteFromEnd() {
    deleteAt(this->len - 1);
}

void ArrayList::deleteAt(int index) {
    // check if array is empty
    
    if(this->index == 0 || this->len == 0)
        return;
    
    
    // check if index is at end
    if(index != this->len-1) {
        shiftLeftFrom(index);
    }
    
    this->index--;
    this->len--;
}





// SORT LIST


void ArrayList::sortList() {
    // This function is using selection sort.
    
//    int *p = nullptr;
    int p = 0;
    
//    for(int i  = 0 ; i < 2 ; i++) {
//        cout << *(p + i) << "," ;
//    }
//    
//    cout<< endl<< endl<< endl<< endl;
    int sorted = 0;
    for(int i = 0 ; i < this->len ; i++) {
        p = getSmallest(i);
//        cout << "\n{" << *(p + 1) << "}\n";
        if(i != p) {
            this->swap(&this->arr[sorted], &this->arr[p]);
            
        }
        
        sorted++;
    }
    
}




void ArrayList::shiftRightFrom(int loc) {
    for(int i = this->index ; i > loc ; i--) {
        this->arr[i] = this->arr[i - 1];
    }
}


void ArrayList::shiftLeftFrom(int loc) {
    for(int i = loc ; i < this->index-1 ; i++) {
        this->arr[i] = this->arr[i + 1];
    }
}



void ArrayList::incSizeBy(int newSize) {
    // create a new array.
    int *tempArr = new int[this->totalLength + newSize];
    
    // copy the array data into new array
    for(int i = 0 ; i < this->totalLength ; i++) {
        tempArr[i] = this->arr[i];
    }
    
    // update the total size
    
    this->totalLength += newSize;
    
    // store the new array reference into the arr pointer.
    
    this->arr = tempArr;
    
    
    // delete the new array pointer.
    
    tempArr = nullptr;
    
//    if(tempArr == NULL && tempArr == nullptr) {
//        cout << "SHIT";
//    }
    
//    cout << endl << arr << endl << tempArr;
}



// BUGS IN HERE BECAUSE OF STATIC ARRAY.

int* ArrayList::getSmallestInList(int loc) {
    static int smallest[2] = {loc, this->arr[loc]};
    
    
    for(int i = loc ; i < this->len ; i++) {
        if(this->arr[i] < smallest[1]) {
            smallest[1] = this->arr[i];
            smallest[0] = i;
        }
    }
    
    
    cout << "\n{" << *(smallest) << " , " << *(smallest + 1) << "}\n";
    
    
    return smallest;
}



int ArrayList::getSmallest(int loc) {
    int smallest = loc;
    for(int i = loc ; i < this->len ; i++) {
        if(this->arr[i] < this->arr[smallest]) {
            smallest = i;
        }
    }
    
    return smallest;
}


void ArrayList::swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



ArrayList::~ArrayList() {
    if(this->arr != nullptr) {
        delete arr;
    }
}

