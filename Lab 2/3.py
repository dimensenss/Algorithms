import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        self.items.append(item)

    def addRear(self, item):
        self.items.insert(0,item)
    
    def display(self):
        for i in self.items:
            print(i, end = " ")
            
    def display_last(self):
        print(self.items[-1])
        
    def input_in_file(self):
        f = open('text.txt', 'w+')
        for i in self.items:
            f.write(i + ' ')      
              
def output_from_file():
    f = open('text.txt', 'r')
    d=Deque()
    str = f.readline()
    str = str.split()
    for i in str:
        d.addFront(i)
    f.close()
    return d
if __name__ == "__main__":
    while(True):
        clear()
        print("1. Create deque")
        print("2. Create deque from file")
        print("3. Print deque")
        print("4. Check for emptiness")
        print("5. Add el to begin")
        print("6. Add el to end")
        print("7. Print last el")
        print("8. Print deque in file")
        print("0. Exit")
            
        cmd = input("Choose: ")
        if cmd == "1":
            d=Deque()
            f = True
        elif cmd == "2":
            d = output_from_file()
            f = True
        elif cmd == "3":
            if f:
                d.display()
                print('\n')
                pause()
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()
        elif cmd =="4":
            if f:
                if d.isEmpty() == True:
                    print("Deque is empty")
                    print('\n')
                    pause()   
                if d.isEmpty() == False:
                    print("Deque is not empty")
                    print('\n')
                    pause()    
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()
        elif cmd == "5":
            if f:
                data = input('Input value: ')
                d.addFront(str(data))
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()
        elif cmd == "6":
            if f:
                data = input('Input value: ')
                d.addRear(str(data))
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()
        elif cmd == "7":        
            if f:
                d.display_last()
                print('\n')
                pause()   
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()
        elif cmd == "8":
            if f:
                d.input_in_file()
            else:
                print("Deque doesnt created\n")
                print('\n')
                pause()                     
        elif cmd == "0":
            break    
        else:
            print("Invalid input value")
            pause()