import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
class DoubleLinkedList:
    class Node:
        previous_node = None
        next_node =None
        element = None
        
        def __init__(self,element, next_node = None, previous_node = None) -> None:
            self.element = element
            self.next_node = next_node
            self.previous_node = previous_node
           
    head = None
    tail = None
    length = 0
    
    def add(self, element):
        self.length +=1
        if not self.head:
            self.head = self.Node(element)
            return element
        elif not self.tail:
            self.tail = self.Node(element, None, self.head)
            self.head.next_node = self.tail
            return element
        else:
            self.tail = self.Node(element, None, self.tail)
            self.tail.previous_node.next_node = self.tail
            return element
    def delete(self, index):
        if self.head:
            if index > self.length // 2:
                el = self._del(index, reverse = True)
                
            elif index <= self.length  // 2:
                el = self._del(index, reverse = False)  
            self.length -=1
            return el
    def _del(self, index, reverse = False):
        if index == 0:
            el = self.head.element
            self.head = self.head.next_node
            self.head.previous_node = None
            return el
        elif index == self.length-1:
            el = self.tail.element
            self.tail = self.tail.previous_node
            self.tail.next_node = None
            return el
        elif reverse:
            i = self.length-1
            node = self.tail
            
            while i != index:
                node = node.previous_node
                i-=1
            el = node.element
            node.previous_node.next_node, node.next_node.previous_node = node.next_node, node.previous_node
            del node
            return el
        else:
            i = 0
            node = self.head
            while i != index:
                node = node.next_node
                i+=1
            el = node.element
            node.previous_node.next_node, node.next_node.previous_node = node.next_node, node.previous_node
            del node
            return el    
                    
    def __iter__(self):
        node = self.head
        while node:
            yield node.element
            node = node.next_node
            
    def swap_val(self, index):
        if self.head is None:
            return None
        current_id = 1
        node = self.head
        while True: 
            
            if current_id == index:
                if node is self.tail:
                    el = node.element
                    node.element = node.previous_node.element
                    node.previous_node.element = el
                    return
                elif node.previous_node is not None:
                    el = node.element
                    node.element = node.next_node.element
                    node.next_node.element = el
                    return 
                else:
                    el = node.element
                    node.element = node.next_node.element
                    node.next_node.element = el
                    return   
            node = node.next_node 
            current_id += 1
    def clear(self):
        self.head = None
        return None               
    def input_in_file(self):
        if self.head is None:
            return
        node = self.head
        f = open('text.txt', 'w+')
        while node:
            f.write(node.element + ' ')
            node = node.next_node
        f.close()    
def output_from_file():
    f = open('text.txt', 'r')
    dblist = DoubleLinkedList()
    str = f.readline()
    str = str.split()
    for i in str:
        dblist.add(i)
    f.close()
    return dblist              
if __name__ == '__main__':
    while True:
        print('\n')
        
        clear()
        print("1. Сформировать список")
        print("2. Добавить элемент в список")
        print("3. Распечатать список")
        print("4. Удалить элемент по номеру")
        print("5. Узнать сколько элементов в списке")
        print("6. Поменять соседние элементы местами")
        print("7. Записать список в файл")
        print("8. Создать список из файла")
        print("9. Очистить список")
        print("0. Выход")
        
        cmd = input("Выберите пункт: ")
        if cmd == "1":
            dblist = DoubleLinkedList()
            f = True
        elif cmd == "2":
            if f:
                n = int(input("Сколько элементов добавить: "))
                for i in range(n):
                    data = input('Введите элемент: ')
                    dblist.add(str(data))
            else:
                print('Список не сформирован\n')
                pause()
                continue
        elif cmd == "3":
            for e in dblist:
                print(f"[{e}]->", end = '')
            print('None')        
            pause()
            
        elif cmd == "4":
            n = int(input("Какой элемент удалить?: "))
            if n in range(dblist.length+1):      
                dblist.delete(n-1) 
        elif cmd == "5":
            print("Всего",dblist.length,"узлов")
            print('\n')
            pause()
        elif cmd == "6":
            n = int(input("Какие элементы передвинуть?: "))
            if n in range(dblist.length+1):
                dblist.swap_val(n)
        elif cmd == "7":
            if f:
                dblist.input_in_file()
            else:
                print('Список не сформирован\n')
                pause()
                continue
            print('\n')
            pause()
        elif cmd == "8":
            dblist = output_from_file()
            f = True
            print('\n')
            pause()            
        elif cmd == "9":
            dblist.clear()            
        elif cmd == "0":
            break
        else:
            print("Вы ввели не правильное значение")                                  
