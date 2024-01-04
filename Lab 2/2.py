import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addFront(self, item):
        self.items.append(item)
    def min_max(self):
        result = list(map(int, self.items))
        return [min(result), max(result)]

    def display(self):
        for i in self.items:
            print(i, end = " ")

    def input_in_file(self):
        f = open('text.txt', 'w+')
        for i in self.items:
            f.write(i + ' ')
            
    def len_queue(self):
        return len(self.items)

    def average(self):
        result = list(map(int, self.items))
        return sum(result)/len(result)

    def before_min(self):
        result = list(map(int, self.items))
        minIndex = result.index(min(result))
        return self.items[minIndex-1] if minIndex > 0 else None

def output_from_file():
    f = open('text.txt', 'r')
    d=Queue()
    
    str = f.readline()
    str = str.split()
    for i in str:
        d.addFront(i)
    f.close()
    return d

if __name__ == "__main__":
    while(True):
        clear()
        print("1. Create queue")
        print("2. Create queue from file")
        print("3. Print queue")
        print("4. Check for emptiness")
        print("5. Add el to begin")
        print("6. Len")
        print("7. Average")
        print("8. Min and max")
        print("9. El before min")
        print("10. Print deque in file")
        print("0. Exit")

        cmd = input("Choose: ")
        if cmd == "1":
            q=Queue()
            f = True
        elif cmd == "2":
            q = output_from_file()
            f = True
        elif cmd == "3":
            if f:
                q.display()
                print('\n')
                pause()
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()
        elif cmd =="4":
            if f:
                if q.isEmpty() == True:
                    print("Queue is empty")
                    print('\n')
                    pause()   
                if q.isEmpty() == False:
                    print("Queue is not empty")
                    print('\n')
                    pause()    
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()
        elif cmd == "5":
            if f:
                data = input('Input value: ')
                q.addFront(str(data))
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()
        elif cmd == "6":
            if f:
                print(q.len_queue(), "el")
                print('\n')
                pause()  
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()        
        elif cmd == "7":
            if f:
                print(q.average())
                print('\n')
                pause() 
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()
        elif cmd == "8":
            if f:
                print(q.min_max())
                print('\n')
                pause() 
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()          
        elif cmd == "9":
            if f:
                print(q.before_min())
                print('\n')
                pause() 
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()                
        elif cmd == "10":
            if f:
                q.input_in_file()
            else:
                print("Queue doesnt created\n")
                print('\n')
                pause()                     
        elif cmd == "0":
            break    
        else:
            print("Invalid input value")
            pause()              
