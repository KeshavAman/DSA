/*
Problem Statement
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.
You need to implement the following public functions :
1. Constructor: It initializes the data members as required.

2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.

3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.
Operations Performed On The Queue :
Query-1(Denoted by an integer 1): Enqueues integer data to the queue.

Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns it to the caller, return -1 if no element is present in the queue.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function, return -1 if no element is present in the queue.

Query-4(Denoted by an integer 4): Returns a boolean value denoting whether the queue is empty or not.
Input Format :
The first line contains an integer ‘t’ denoting the number of test cases.

For each test case, the first line contains an integer 'q' which denotes the number of queries to be run against each operation on the queue. 

Every 'q' lines represent an operation that needs to be performed.

For the enQueue operation, the input line will contain two integers separated by a single space, representing the type of the operation in the integer and the integer data being enqueued into the queue.

For the rest of the operations on the queue, the input line will contain only one integer value, representing the query being performed on the queue.
Output Format :
For Query-1, print the data being enqueued in the queue.
For Query-2, print the data being dequeued from the queue.
For Query-3, print the data kept on the front of the queue.
For Query-4, print 'true' or 'false'(without quotes).

Output for every query will be printed in a separate line.
*/

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
      	size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) return 1;
        else return 0;
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"Queue if full" <<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear) return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if(qfront == rear) return -1;
        else{
            return arr[qfront];
        }
    }
};
