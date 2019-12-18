//
// Created by Lukas Jaklitsch on 12/17/19.
//

#include "PendingQueue.h"
#include <cstddef>
#include <stdexcept>

// Class Constructor
PendingQueue::PendingQueue() : myFront(nullptr), myBack(nullptr), mySize(0) {}

// Copy Constructor
// pre: Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
PendingQueue::PendingQueue(const PendingQueue &rhs) :
        myFront(nullptr), myBack(nullptr), mySize(rhs.mySize) {

    if (rhs.myFront != nullptr) {
        myFront = new Node;
        myFront->betSlip = rhs.myFront->betSlip;
        NodePtr newPtr(myFront);

        for (NodePtr origPtr = rhs.myFront->next;
                origPtr != nullptr;
                origPtr = origPtr->next
                ) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->betSlip = origPtr->betSlip;
        }

        newPtr->next = nullptr;
        myBack = newPtr;
    }
}

// Class Destructor3
// Destroys a queue
// pre: Class object exists
// post: Class object does not exist
PendingQueue::~PendingQueue() {
    NodePtr tmp;
    while (myFront != nullptr) {
        tmp = myFront;
        myFront = myFront->next;
        delete tmp;
    }
    myBack = nullptr;
    mySize = 0;
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const PendingQueue &PendingQueue::operator=(const PendingQueue &rhs) {
    if (this != &rhs) {
        PendingQueue tmp(rhs);
        std::swap(myFront, tmp.myFront);
        std::swap(myBack, tmp.myBack);
        std::swap(mySize, tmp.mySize);
    }
    return *this;
}

// isEmpty
// Checks if the queue is empty
// pre: A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
bool PendingQueue::isEmpty() const {
    return mySize == 0;
}

// enqueue
// enqueues an item to back of the queue.
// pre: DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
void PendingQueue::enqueue(const ItemType &item) {
    PendingQueue::NodePtr tmp = new Node;
    tmp->betSlip = item;
    tmp->next = nullptr;

    if (mySize == 0) {
        myFront = tmp;
        myBack = tmp;
    } else {
        myBack->next = tmp;
        myBack = tmp;
        tmp = nullptr;
    }
    ++mySize;
}

// dequeue
// dequeues the front item off the queue
// pre: DblQueue exists.
// post: Removes item on front of the queue. If the queue
// was already empty, throws an std::underflow_error exception.
void PendingQueue::dequeue() {
    if (mySize == 0) {
        throw std::underflow_error("The queue is empty");
    } else if (mySize == 1) {
        delete myFront;
        myFront = nullptr;
        myBack = nullptr;
        mySize--;
    } else {
        PendingQueue::NodePtr tmp = myFront;
        myFront = myFront->next;
        delete tmp;
        tmp = nullptr;
        mySize--;
    }
}
// front

// Returns the front item of the queue without dequeueing it.
// pre: DblQueue exists.
// post: Returns item at front of queue. If the queue is empty,
// throws an std::underflow_error exception.
ItemType PendingQueue::front() const {
    if (mySize == 0) {
        throw std::underflow_error("The queue is empty");
    } else {
        return myFront->betSlip;
    }
}

// size
// Returns the number of items on the queue.
size_t PendingQueue::size() const {
    return mySize;
}

// Updates the pending q to check
void PendingQueue::update(){

}
