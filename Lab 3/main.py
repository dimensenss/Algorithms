import os
clear = lambda: os.system('cls')
pause = lambda: os.system("pause")
f = False
f1 = False
class TreeNode:
    def __init__(self, name = None, key=None, group = None):
        self.key = key
        self.name = name
        self.group = group
        self.left = None
        self.right = None

    def __str__(self):
        return f"TreeNode({self.name})"
        return f"TreeNode({self.key})"
        return f"TreeNode({self.group})"

    def insert(self, name = None ,key = None, group = None):
        if self.key  is None:
            self.key = key
            self.name = name
            self.group = group
            return
        
        if key < self.key:
            if self.left is None:
                self.left = TreeNode(name,key,group)
            else:
                self.left.insert(name,key,group)
        elif key > self.key :
            if self.right is None:
                self.right = TreeNode(name,key,group)
            else:
                self.right.insert(name,key,group)
        else:
            raise ValueError(f"Key {key} already exists")
    def sec_insert(self, name = None ,key = None, group = None):
        if self.key  is None:
            self.key = key
            self.name = name
            self.group = group
            return
        
        if name < self.name:
            if self.left is None:
                self.left = TreeNode(name,key,group)
            else:
                self.left.insert(name,key,group)
        elif name > self.name :
            if self.right is None:
                self.right = TreeNode(name,key,group)
            else:
                self.right.insert(name,key,group)
        else:
            raise ValueError(f"Key {group} already exists")
    
     # Прямой обход дерева
    def traversePreOrder(self, dir = "root",level=0):
        print(f"[{dir}] #{level} = {self.name},{self.key},{self.group} | left = {self.left} | right = {self.right}")
        if self.left:
            self.left.traversePreOrder("left", level+1)
        if self.right:
            self.right.traversePreOrder("right", level+1)

    # Центрированный обход дерева
    def traverseInOrder(self, dir = "root",level=0):
        if self.left:
            self.left.traverseInOrder("left", level+1)
        print(f"[{dir}] #{level} = {self.name},{self.key},{self.group} | left = {self.left} | right = {self.right}")
        if self.right:
            self.right.traverseInOrder("right", level+1)

    # Обратный обход дерева
    def traversePostOrder(self, dir = "root",level=0):
        if self.left:
            self.left.traversePostOrder("left", level+1)
        if self.right:
            self.right.traversePostOrder("right", level+1)
        print(f"[{dir}] #{level} = {self.name},{self.key},{self.group} | left = {self.left} | right = {self.right}")
        
    def print_hierarchy(self, dir = "root "):
        if self.group == None:
            if self.left == None:
                print(f"[{dir}] {self.name},{self.key} | left = {self.left}\t    | right = {self.right}")
            else:
                print(f"[{dir}] {self.name},{self.key} | left = {self.left}| right = {self.right}")
            if self.left  is not None: self.left.print_hierarchy("left ")
            if self.right is not None: self.right.print_hierarchy("right")
        else:        
            if self.left == None:
                print(f"[{dir}] {self.name},{self.key},{self.group} | left = {self.left}\t       | right = {self.right}")
            else:
                print(f"[{dir}] {self.name},{self.key},{self.group} | left = {self.left}| right = {self.right}")
            if self.left  is not None: self.left.print_hierarchy("left ")
            if self.right is not None: self.right.print_hierarchy("right")
    
        
    def average(self,av =set(), size =0):
        av.add(self.key)
        if self.left:
            self.left.average(av)
        if self.right:
            self.right.average(av)
        s = str(sum(av)/len(av))    
        return s[:s.find('.')+2]
    
    def get_len(self):
        av.add(self.key)
        if self.left:
            self.left.get_len(av)
        if self.right:
            self.right.get_len(av)
        return len(av)
        
    def _delete(self):
        tree = TreeNode()
        return tree
    
    def del_right(self):
        if self is not None: self.right = None
        
    def del_left(self):
        if self is not None: self.left = None
    
    def deleteNode(root, key):
        parent = None
        curr = root
        while curr and curr.key != key:
            parent = curr

            if key < curr.key:
                curr = curr.left
            else:
                curr = curr.right

        if curr is None:
            return root
        
        if curr.left is None and curr.right is None:
            if curr != root:
                if parent.left == curr:
                    parent.left = None
                else:
                    parent.right = None
            else:
                root = None
        elif curr.left and curr.right:
            successor = tree.getMinimumKey(curr.right)
            
            val = successor.key
            name = successor.name
            group = successor.group

            tree.deleteNode(successor.key)
            
            curr.key = val
            curr.name = name
            curr.group = group

        else:
            if curr.left:
                child = curr.left
            else:
                child = curr.right

            if curr != root:
                if curr == parent.left:
                    parent.left = child
                else:
                    parent.right = child
            else:
                root = child
        return root

    def getMinimumKey(self, curr):
        while curr.left:
            curr = curr.left
        return curr
    def second_tree(self, tree2):
        
        tree2.sec_insert(self.name, self.key,self.group)
        if self.left:
            self.left.second_tree(tree2)
        if self.right:
            self.right.second_tree(tree2)
        return tree2   

class NilNode(object):
    def __init__(self):
        self.red = False

NIL = NilNode() 

class RBNode(object):
    def __init__(self,name = None, key = None, group = None):
        self.red = True
        self.parent = None
        self.key = key
        self.name = name
        self.group = group
        self.left = NIL
        self.right = NIL

class RedBlackTree(object):
    def __init__(self):
        self.root = None
        self.size =0
    def add(self,name,key, group,curr = None):
        self.size += 1
        new_node = RBNode(name,key, group)
        # Base Case - Nothing in the tree
        if self.root == None:
            new_node.red = False
            self.root = new_node
            return
        
        # Search to find the node's correct place
        currentNode = self.root
        while currentNode != NIL:
            potentialParent = currentNode
            if new_node.key < currentNode.key:
                currentNode = currentNode.left
            else:
                currentNode = currentNode.right
                
        # Assign parents and siblings to the new node
        new_node.parent = potentialParent
        if new_node.key < new_node.parent.key:
            new_node.parent.left = new_node
        else:
            new_node.parent.right = new_node
        self.fix_tree_after_add(new_node)
        
    def deleteNodeRB(self, key):
        parent = None
        curr = self.root
        while curr and curr.key != key:
            parent = curr

            if key < curr.key:
                curr = curr.left
            else:
                curr = curr.right

        if curr is None:
            return self
        
        if curr.left is NIL and curr.right is NIL:
            if curr != self.root:
                if parent.left == curr:
                    parent.left = NIL
                else:
                    parent.right = NIL
            else:
                self = None
        elif curr.left != NIL and curr.right != NIL:
            successor = tree1.getMinimumKeyRB(curr.right)
            
            val = successor.key
            name = successor.name
            group = successor.group

            tree1.deleteNodeRB(successor.key)
            
            curr.key = val
            curr.name = name
            curr.group = group

        else:
            if curr.left:
                child = curr.left
            else:
                child = curr.right

            if curr != self:
                if curr == parent.left:
                    parent.left = child
                else:
                    parent.right = child
            else:
                self.root = child
        return self.root
    def getMinimumKeyRB(self, curr):
            while curr.left != NIL:
                curr = curr.left
            return curr
        

            
    def contains(self,name,key, group, curr=None):
        if curr == None:
            curr = self.root
        while curr != NIL and key != curr.key:
            if key < curr.key:
                curr = curr.left
            else:
                curr = curr.right
        return curr

    def fix_tree_after_add(self,new_node):
        #print("Tree is being fixed!")
        while new_node != self.root and new_node.parent.red == True:
            if new_node.parent == new_node.parent.parent.left:
                uncle = new_node.parent.parent.right
                if uncle.red:
                    # This is Case 1
                    new_node.parent.red = False
                    uncle.red = False
                    new_node.parent.parent.red = True
                    new_node = new_node.parent.parent
                else:
                    if new_node == new_node.parent.right:
                        # This is Case 2
                        new_node = new_node.parent
                        self.left_rotate(new_node)
                    # This is Case 3
                    new_node.parent.red = False
                    new_node.parent.parent.red = True
                    self.right_rotate(new_node.parent.parent)
            else:
                uncle = new_node.parent.parent.left
                if uncle.red:
                    # Case 1
                    new_node.parent.red = False
                    uncle.red = False
                    new_node.parent.parent.red = True
                    new_node = new_node.parent.parent
                else:
                    if new_node == new_node.parent.left:
                        # Case 2
                        new_node = new_node.parent
                        self.right_rotate(new_node)
                    # Case 3
                    new_node.parent.red = False
                    new_node.parent.parent.red = True
                    self.left_rotate(new_node.parent.parent)
        self.root.red = False



    def delete(self):
        pass
    
    def left_rotate(self,x):
        y = x.right
        x.right = y.left
        if y.left != NIL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        else:
            if x == x.parent.left:
                x.parent.left = y
            else:
                x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self,x):
        y = x.left
        x.left = y.right
        # Turn sibling's left subtree into node's right subtree
        if y.right != NIL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        else:
            if x == x.parent.right:
                x.parent.right = y
            else:
                x.parent.left = y
        y.right = x
        x.parent = y

    def get_all_nodes(self):
        pass
    
    def is_red(self):
        return self.root != None and self.root.red == 1;
    
    def is_black(self):
        return self.root != None and self.root.black == 1;
    
def Display(root):
    
    if root != NIL:
        Display(root.left)
        print(root.name, root.key, root.group,end='\t')
        if root.left != NIL:
            print(root.left.name, root.left.key,root.left.group,end='  ')
        else:
            print('BLACK',end='\t\t')
        if root.right != NIL:
            print(root.right.name,root.right.key,root.right.group,end='  ')
        else:
            print('BLACK',end='\t\t')
        if root.red:
            print('RED')
        else:
            if root.parent is None:
                print("BLACK ROOT")
            else:
                print('BLACK')
            
        Display(root.right)
        
    
def TracePath(root,key):
    path = []
    while root != NIL:
        if key < root.key:
            if root.red:
                s = "BLACK"
            else:
                s = "RED"
            path.append(s)
            root = root.left
        elif key > root.key:
            if root.parent == None:
                s= "BLACK"
            else:
                if root.red:
                    s = "BLACK"
                else:
                    s = "RED"
            path.append(s)
            root = root.right
        else:
            break
    return path

def input_in_file_RB(root):
    lst =[]
    def _input_in_file(root):
        if root != NIL:
            _input_in_file(root.left)
            lst.append(f"{root.name, root.key, root.group}")
            
            _input_in_file(root.right)
    _input_in_file(root)
    f = open("text.txt", "w+")
    for i in lst:
        f.write(i + ' ')

def output_from_file():
    f = open('text.txt', 'r')
    tree = TreeNode()
    str = f.readline()
    f.close()
    _len = len(str)
    #str = str.split('()')
    lst_name = []
    lst_key = []
    lst_group = []
    for i in range(0,len(str),21):
        lst_name.append(str[2+i:7+i])

    for i in range(0,len(str),21):
        lst_key.append(int(str[10+i:15+i]))

    for i in range(0,len(str),21):
        lst_group.append(int(str[17+i:19+i]))
    i =0
    while i< len(lst_name):
        tree.insert(lst_name[i], lst_key[i], lst_group[i])
        i+=1
    return tree

def output_from_file_RB():
    f = open('text.txt', 'r')
    tree = RedBlackTree()
    str = f.readline()
    f.close()
    _len = len(str)
    #str = str.split('()')
    lst_name = []
    lst_key = []
    lst_group = []
    for i in range(0,len(str),21):
        lst_name.append(str[2+i:7+i])

    for i in range(0,len(str),21):
        lst_key.append(int(str[10+i:15+i]))

    for i in range(0,len(str),21):
        lst_group.append(int(str[17+i:19+i]))
    i =0
    while i< len(lst_name):
        tree.add(lst_name[i], lst_key[i], lst_group[i])
        i+=1
    return tree

def input_in_file(self):
    lst =[]
    def _input_in_file(self):
        if self != None:
            _input_in_file(self.left)
            lst.append(f"{self.name, self.key, self.group}")
            
            _input_in_file(self.right)
    _input_in_file(self)
    f = open("text.txt", "w+")
    for i in lst:
        f.write(i + ' ')
        
    
if __name__ == "__main__":
    while(True):
        clear()
        print("1. Create tree")
        print("2. Create tree from file")
        print("3. Print tree")
        print("4. Average by key")
        print("5. Print direct bypass")
        print("6. Print symmetrical bypass")
        print("7. Print reverse bypass")
        print("8. Delete all tree")
        print("9. Delete left under tree")
        print("10. Delete right under tree")
        print("11. Delete one branch ")
        print("12. Copy in another tree")
        print("13. Color in Red-Black tree")
        print("14. Print Red-Black tree")
        print("15. Add brach in RB tree")
        print("16. Delete brach in RB tree")
        print("17. Check paths in RB tree")
        print("18. Print in file")
        print("0. Exit")

        cmd = input("Choose: ")
        if cmd == "1":
            tree = TreeNode()
            data = int(input("How many branches add?: "))
            for i in range(data):
                name = str(input("Enter name: "))
                key = int(input("Enter key: "))
                group = int(input("Enter data: "))
                print()
                tree.insert(name,key,group)
            f = True
        if cmd =="2":
            tree = output_from_file()
            f = True
        if cmd =="3":
            if f:
                tree.print_hierarchy()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="4":
            if f:
                print(tree.average())
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="5":
            if f:
                tree.traversePreOrder()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="6":
            if f:
                tree.traverseInOrder()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="7":
            if f:
                tree.traversePostOrder()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="8":
            if f:
                tree = tree._delete()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="9":
            if f:
                tree.del_left()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="10":
            if f:
                tree.del_right()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="11":
            if f:
                tree.print_hierarchy()
                print()
                data = int(input('Enter key to del: '))
                tree.deleteNode(data)
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="12":
            if f:
                tree2 = TreeNode()
                tree2 = tree.second_tree(tree2)
                tree = tree2
                tree2._delete()
                tree.print_hierarchy()
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="13":
            tree1 = RedBlackTree()
            tree1 = output_from_file_RB()
            print('\n')
            pause()
            f1 = True
        if cmd =="14":
            if f1:
                print('Node\t\tLeft Child\tRight Child\tColor')
                Display(tree1.root)
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="15":
            if f1:
                data = int(input("How many branches add?: "))
                for i in range(data):
                    name = str(input("Enter name: "))
                    key = int(input("Enter key: "))
                    group = int(input("Enter data: "))
                    print()
                    tree1.add(name,key,group)
                    print('\n')
                    pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="16":
            if f1:
                print('Node\t\tLeft Child\tRight Child\tColor')
                Display(tree1.root)
                print()
                data = int(input('Enter key to del: '))
                tree1.deleteNodeRB(data)
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="17":
            if f1:
                print('Node\t\tLeft Child\tRight Child\tColor')
                Display(tree1.root)
                print()
                data = int(input('Enter key to check: '))
                print(TracePath(tree1.root, data), "-> None")
                print('\n')
                pause()
            else:
                print("tree doesnt created\n")
                print('\n')
                pause()
        if cmd =="18":
            data = int(input("Which tree input in file? tree - 1, RB tree - 2: "))
            if data == 1:
                input_in_file(tree)
            elif  data == 2:
                input_in_file_RB(tree1.root)
            else:
                print('Eror')
            print('\n')
            pause()

            
        
        if cmd =="0":
            break
