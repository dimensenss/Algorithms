import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        self.items.insert(0,item)

    def display(self):
        for i in self.items:
            print(i, end = " ")
            
    def _swap(self):
        a = self.items[0]
        self.items[0] = self.items[-1]
        self.items[-1] = a
        
    def _reverse(self):
        self.items.reverse()
    
    def del_even(self):
        del self.items[1::2]
    
    def del_min(self):
        del self.items[self.items.index(min(self.items))]
        
    def del_expect_last(self):
        del self.items[1::]
        
    def del_expect_first(self):
        del self.items[:len(self.items)-1:]               
        
    def input_in_file(self):
        f = open('text.txt', 'w+')
        for i in self.items:
            f.write(i + ' ')
    def insert_zero(self):
        result = list(map(int, self.items))
        maxIndex = result.index(max(result))
        self.items.insert(maxIndex+1, '0')

def output_from_file():
    f = open('text.txt', 'r')
    s = Stack()
    str = f.readline()
    str = str.split()
    for i in str:
        s.addFront(i)
    f.close()
    return s

if __name__ == "__main__":
    while(True):
        clear()
        print("1. Create stack")
        print("2. Create stack from file")
        print("3. Print stack")
        print("4. Check for emptiness")
        print("5. Add el to begin")
        print("6. Swap fist and last")
        print("7. Reverse")
        print("8. Del even")
        print("9. Insert 0 after max")
        print("10. Del min")
        print("11. Del all except the first")
        print("12. Del all except the last")
        print("13. Print deque in file")
        print("0. Exit")

        cmd = input("Choose: ")
        if cmd == "1":
            s = Stack()
            f = True
        elif cmd == "2":
            s = output_from_file()
            f = True
        elif cmd == "3":
            if f:
                s.display()
                print('\n')
                pause()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd =="4":
            if f:
                if s.isEmpty() == True:
                    print("Stack is empty")
                    print('\n')
                    pause()   
                if s.isEmpty() == False:
                    print("Stack is not empty")
                    print('\n')
                    pause()    
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "5":
            if f:
                data = input('Input value: ')
                s.addFront(str(data))
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "6":
            if f:
                s._swap()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "7":
            if f:
                s._reverse()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "8":
            if f:
                s.del_even()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "9":
            if f:
                s.insert_zero()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()        
        elif cmd == "10":
            if f:
                s.del_min()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "11":
            if f:
                s.del_expect_first()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()
        elif cmd == "12":
            if f:
                s.del_expect_last()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()                                      
        elif cmd == "13":
            if f:
                s.input_in_file()
            else:
                print("Stack stack created\n")
                print('\n')
                pause()                     
        elif cmd == "0":
            break    
        else:
            print("Invalid input value")
            pause()              
