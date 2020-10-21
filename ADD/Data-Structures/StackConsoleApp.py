#Stack using Python
'''
Functions: empty(), size(), top(), push(element), pop(), print(), clear()
'''

# Refrenced this from here: https://www.geeksforgeeks.org/stack-in-python/
class Stack:
    def __init__(self):
        self.stack = []  # inital stage of Stack ie 0 (null) (Time Complexity : O(1))

    def empty(self):     # Returns whether the stack is empty – Time Complexity : O(1)
        print(f"Stack is Empty: {(False, True) [len(self.stack)==0]}") # <--- Ternery Statement https://book.pythontips.com/en/latest/ternary_operators.html

    def size(self):     # Returns the size of the stack – Time Complexity : O(1)
        return(len(self.stack))

    def top(self):     # Returns a reference to the top most element of the stack – Time Complexity : O(1)
        if self.stack:
            return("Top of Stack: " + self.stack[-1])    # this will get the last element of stack
        else:
            return("Stack is empty (Top of stack is null)")

    def push(self, element): # Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
        self.stack.append(element)  
        print(self.stack)
        
    def pop(self):
        self.stack.pop()    # Deletes the top most element of the stack – Time Complexity : O(1)
        print(self.stack)
    
    def print(self):
        # printing the stack using loop 
        print("Stack: ", end ="")
        for i in range(len(self.stack)): 
            print (self.stack[i], end =", ")    

    def clear(self):
        print("Stack was cleared....")
        self.stack.clear()

def main():

    # Stack Variable Reference
    stack = Stack()

    print("More information can be found here: https://www.geeksforgeeks.org/stack-in-python/")

    isRunning = True

    while isRunning:
        # Clear the terminal history - This is the escape character for clearing the terminal 
        print("\033c")

        # Prompt the user for input
        print("==================================================\n" +
            "Please select from one of the following: \n" +
            "1) Add new element to Stack (push)\n" +
            "2) Remove element from Stack to Stack (pop)\n" +
            "3) Print the entire stack from memory\n" +
            "4) Prints if the stack is empty (empty)\n"
            "5) Prints the Size of the stack (size)\n"
            "6) Remove all from Stack (Pop til head == null)\n" +
            "7) Exit Application\n" +
            "==================================================\n" +
            "User Input: ")

        choice = int(input())
        
        # Space out the room a bit before we start prompting the user with more information
        print("\n\n\n")

        # There's no good implmentation of Switch/Case statements so we will use If/Else Statements
        if (choice == 1):
            print("\033c")
            print("Please insert your value: ")
            addInput = input()
            stack.push(addInput)
        elif (choice == 2):
            print(stack.top() + " was removed from stack") 
            if (stack.size() > 0):
                stack.pop()
            input("\nPress Enter to continue...")
        elif (choice == 3):
            stack.print()
            input("\nPress Enter to continue...")
        elif (choice == 4):
            stack.empty()
            input("\nPress Enter to continue...")
        elif (choice == 5):
            print("Length: " + str(stack.size()))
            input("\nPress Enter to continue...")
        elif (choice == 6):
            stack.clear()
            input("\nPress Enter to continue...")
        elif (choice == 7):
            isRunning = False
        else:
            print("Error reading input")

    # On Application Exit
    print("\n\nApplication Exited.....")

if __name__ == "__main__":
    main()