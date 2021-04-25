class Stack:

    def __init__(self):
        self.stack = []

    def push(self, n):
        self.stack.append(n)

    def pop(self):
        if len(self.stack) == 0:
            print("Stack is empty. No element to pop.")
            return None
        return self.stack.pop()
    
    def top(self):
        if len(self.stack) == 0:
            print("Stack is empty.")
            return False
        return self.stack[len(self.stack)-1]
    
    def isEmpty(self):
        if len(self.stack) == 0:
            return True
        return False

    def size(self):
        return len(self.stack)
    
    
class Queue:

    def __init__(self):
        self.queue = []
    
    def enqueue(self, n):
        self.queue.append(n)

    def dequeue(self):
        if len(self.queue) > 0:
            dequeued = self.queue[0]
            self.queue = self.queue[1:]
            return dequeued

    def rear(self):
        if len(self.queue) == 0:
            print("Queue is empty.")
            return False
        return self.queue[len(self.queue)-1]

    def front(self):
        if len(self.queue) == 0:
            print("Queue is empty.")
            return False
        return self.queue[0]

    def size(self):
        return len(self.queue)

    def isEmpty(self):
        if len(self.queue) == 0:
            return True
        return False


def testStack():
    myStack = Stack()
    myStack.push(42)
    print("Top of stack: ", myStack.top())
    # prints “Top of stack: 42”
    print("Size of stack: ", myStack.size())
    # prints “Size of stack: 1”
    popped_value = myStack.pop()
    print("Popped value: " , popped_value)
    # prints “Popped value: 42”
    print("Size of stack: ", myStack.size())
    # prints “Size of stack: 0”
    popped_value = myStack.pop()
    print("Popped value: " , popped_value)
    # prints "Stack is empty. No element to pop. Popped value:  None"

def testQueue():
    myQueue = Queue()
    myQueue.enqueue(1)
    myQueue.enqueue(2)
    myQueue.enqueue(3)
    print("Size of queue: ", myQueue.size())
    # prints “Size of queue: 3”
    print("Front of queue: ", myQueue.front())
    # prints “Front of queue: 1”
    print("Rear of queue: ", myQueue.rear())
    # prints “Rear of queue: 3”
    dequeuedItem = myQueue.dequeue()
    print("Dequeue item: ", dequeuedItem)
    # prints “Dequeued item: 1”


testStack()
testQueue()
