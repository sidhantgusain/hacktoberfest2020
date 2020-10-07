#Stack using Python
'''
Functions: push(), popOut(), 
'''
class Stack:
    def __init__(self):
        self.stack = []  #inital stage of Stack ie 0 (null)
    
    def push(self, element):
        self.stack.append(element)  
        print(self.stack)
        
    def popOut(self):
        self.stack.pop()    #we have a predefine function to pop element
        print(self.stack)

#Test case
s1 = Stack()
#Push elements in Stack
s1.push(10)
s1.push(20)
s1.push(30)
s1.push(40)
#Pop elements from Stack in LIFO form
s1.popOut()