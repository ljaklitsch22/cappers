//
// Created by Lukas Jaklitsch on 12/17/19.
//

#ifndef CAPPERS_PENDINGQUEUE_H
#define CAPPERS_PENDINGQUEUE_H

#include "BetSlip.h"
#include <stddef.h>

typedef BetSlip ItemType;

class PendingQueue {
private:
    struct Node {
        BetSlip betSlip;
        Node *next;

        Node() = default;
    };
    typedef Node *NodePtr;
    NodePtr myFront;
    NodePtr myBack;
    size_t mySize;

public:
// Class Constructor
    PendingQueue();

// Copy Constructor
// pre: Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter

    PendingQueue(const PendingQueue &rhs);

// Class Destructor
// Destroys a queue
// pre: Class object exists
// post: Class object does not exist
    ~PendingQueue();

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
    const PendingQueue& operator=(const PendingQueue &rhs);

// isEmpty
// Checks if the queue is empty
// pre: A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

// enqueue
// enqueues an item to back of the queue.
// pre: DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
    void enqueue(const ItemType &item);

// dequeue
// dequeues the front item off the queue
// pre: DblQueue exists.
// post: Removes item on front of the queue. If the queue
// was already empty, throws an std::underflow_error exception.
    void dequeue();

// front
// Returns the front item of the queue without dequeueing it.
// pre: DblQueue exists.
// post: Returns item at front of queue. If the queue is empty,
// throws an std::underflow_error exception.
    ItemType front() const;

// size
// Returns the number of items on the queue.
    size_t size() const;

    // Update the pending bets by checking if the money available is in yet
    // update moneyTotal, not counter
    void update();
};

#endif //CAPPERS_PENDINGQUEUE_H
