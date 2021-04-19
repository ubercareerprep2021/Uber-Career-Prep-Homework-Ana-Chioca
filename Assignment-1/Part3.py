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

def test():
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

test()