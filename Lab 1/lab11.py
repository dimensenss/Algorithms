import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
 
class CircularLinkedList:
    def __init__(self):
        self.head = None
 
    def get_node(self, index):
        if self.head is None:
            return None
        current = self.head
        for i in range(index):
            current = current.next
            if current == self.head:
                return None
        return current
 
    def get_prev_node(self, ref_node):
        if self.head is None:
            return None
        current = self.head
        while current.next != ref_node:
            current = current.next
        return current
 
    def insert_after(self, ref_node, new_node):
        new_node.next = ref_node.next
        ref_node.next = new_node
 
    def insert_before(self, ref_node, new_node):
        prev_node = self.get_prev_node(ref_node)
        self.insert_after(prev_node, new_node)
 
    def insert_at_end(self, new_node):
        if self.head is None:
            self.head = new_node
            new_node.next = new_node
        else:
            self.insert_before(self.head, new_node)
 
    def append(self, data):
        self.insert_at_end(Node(data))
 
    def display(self):
        if self.head is None:
            return
        current = self.head
        while True:
            print(f"[{current.data}]", end = "")
            current = current.next
            if current == self.head:
                break
            print('->', end = '')
            
    def list_length(self):
        if self.head is None:
            return "list is empty"
        count = 0
        current = self.head
        while True:
            count = count + 1
            current = current.next
            if current == self.head:
                break
        return count
    
    def remove_list_item_by_id(self, item_id):
        
        current_id = 1
        current_node = self.head
        previous_node = None
        
        while True:
            if current_id == item_id:
                if previous_node is not None:
                    previous_node.next = current_node.next
                else:
                    self.head = current_node.next
                    previous_node = current_node
                    current_node = current_node.next
                    return
    
            previous_node = current_node
            current_node = current_node.next
            current_id = current_id + 1
            if current_node == self.head:
                break
        return
    
        return self.head
    def pop_front(self):
        if(self.head != None):
            if(self.head.next == self.head):
                self.head = None
            else:
                temp = self.head
                firstNode = self.head

                while(temp.next != self.head):
                    temp = temp.next

                self.head = self.head.next
                temp.next = self.head 
                firstNode = None 

    def clear(self):
        self.__init__()
        return None
    
    def input_in_file(self):
        if self.head is None:
            return
        current = self.head
        f = open('text.txt', 'w+')
        while True:
            f.write(current.data + ' ')
            current = current.next
            if current == self.head:
                f.close()
                break
    
def interchange(llist, n):
    current = llist.get_node(n)
    current2 = current.next
    if current2.next != current:
        before = llist.get_prev_node(current)
        after = current2.next
        before.next = current2
        current2.next = current
        current.next = after
    if llist.head == current:
        llist.head = current2
    elif llist.head == current2:
        llist.head = current
        
def output_from_file():
    f = open('text.txt', 'r')
    a_cllist = CircularLinkedList()
    str = f.readline()
    str = str.split()
    for i in str:
        a_cllist.append(i)
    f.close()
    return a_cllist    
if __name__ == "__main__":
    while True:
        print('\n')
        
        clear()
        print("1. Сформировать список")
        print("2. Добавить элемент в список")
        print("3. Распечатать список")
        print("4. Удалить элемент по номеру")
        print("5. Узнать сколько элементов в списке")
        print("6. Поменять соседние элементы местами")
        print("7. Объеденить два списка")
        print("8. Записать список в файл")
        print("9. Создать список из файла")
        print("10. Очистить список")
        print("0. Выход")
        
        cmd = input("Выберите пункт: ")
    
        if cmd == "1":
            a_cllist = CircularLinkedList()
            f = True
        elif cmd == "2":
            if f:
                n = int(input("Сколько элементов добавить: "))
                for i in range(n):
                    data = input('Введите элемент: ')
                    a_cllist.append(str(data))
            else:
                print('Список не сформирован\n')
                pause()
                continue        
        elif cmd == "3":
            a_cllist.display()
            print('\n')
            pause()
        elif cmd == "4":
            n = int(input("Какой элемент удалить?: "))
            if n == 1:
                a_cllist.pop_front()
            if n in range(a_cllist.list_length()+1):      
                a_cllist.remove_list_item_by_id(n)
        elif cmd == "5":
            print("Всего",a_cllist.list_length(),"узлов")
            print('\n')
            pause()
        elif cmd == "6":
            n = int(input("Какие элементы передвинуть?: "))
            if n in range(a_cllist.list_length()+1):
                interchange(a_cllist, n-1)
        elif cmd == "7":
            a_cllist2 = CircularLinkedList()
            print('Для начала создайте второй список')
            n = int(input("Сколько элементов добавить: "))
            for i in range(n):
                data = input('Введите элемент: ')
                a_cllist2.append(str(data))
            current = a_cllist2.head
            
            while True:
                a_cllist.append(current.data)
                current = current.next
                if current == a_cllist2.head:
                    break 
        elif cmd == "8":
            if f:
                a_cllist.input_in_file()
            else:
                print('Список не сформирован\n')
                pause()
                continue
        elif cmd == "9":
            
                a_cllist = output_from_file()
                f = True
                pause()
                
        elif cmd == "10":
            if f:
                a_cllist.clear()
            else:
                print('Список не сформирован\n')
                pause()
                continue                      
        elif cmd == "0":
            break
        else:
            print("Вы ввели не правильное значение") 
        