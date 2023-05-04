//implementing a queue using 2 stacks
#include <stack>
#include <iostream>

using namespace std;

class MyQueue{
private:
    stack<int> wrong; //enqueue
    stack<int> right; //dequeue

public:
    MyQueue(){}

    void push(int x){
        wrong.push(x);
    }

    int pop(){
        int front;

        if(right.empty()){
            while(!wrong.empty()){
                right.push(wrong.top());
                wrong.pop();
            }
        }

        front = right.top();
        right.pop();

        return front;
    }

    int peek(){
        if(right.empty()){
            while(!wrong.empty()){
                right.push(wrong.top());
                wrong.pop();
            }
        }

        return right.top();
    }

    bool empty(){
        if(right.empty() && wrong.empty()){
            return true;
        }else{
            return false;
        }
    }

};



int main(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue->peek() << endl; // return 1
    cout << myQueue->pop() << endl; // return 1, queue is [2]
    myQueue->empty(); // return false
}