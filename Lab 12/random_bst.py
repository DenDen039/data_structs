from collections import deque
import random


class Node:
    def __init__(self,val: int):
        self.left = None
        self.right = None
        self.val = val
        self.c = 0
    def connections (self,prefix = "",isLeft = False):
        rep = prefix
        rep+= "├──" if isLeft else "├──"
        rep+= str(self.val)+"\n"
        prefix+= "│   "if isLeft else "    "
        if self.left != None:
            rep+=self.left.connections(prefix, True)
        if self.right != None:
            rep+=self.right.connections(prefix, False)
        return rep
class BST():
    def __init__(self,arr: list = []):
        self.root = None
        for i in arr:
            self.random_insert(i)
            print(self.get_tree())

    def __random_insert(self,node,val):
        if node == None:
            return Node(val)
        else:
            if random.randint(0,node.c) == node.c:
                return self.__root_insert(node,Node(val))
            if val < node.val:
                node.c+=1
                node.left = self.__random_insert(node.left,val)
                return node
            else:
                node.c+=1
                node.right = self.__random_insert(node.right,val)
                return node

    def random_insert(self,val):
        self.root = self.__random_insert(self.root,val)
    def getsize(self,node):
        if node == None:
            return 0
        return node.c+1
    def fixsize(self,node):
        node.c = self.getsize(node.left)+self.getsize(node.right)
    def join(self,p,q):
        if p == None:
            return q
        if q == None:
            return p
        if random.randint(0,p.c+q.c) < p.c:
            p.right = self.join(p.right,q)
            self.fixsize(p)
            return p
        else:
            q.left = self.join(p,q.left)
            self.fixsize(q)
            return q
    def __random_remove(self,p,val):
        if p == None:
            return p 
        if p.val == val:
            q = self.join(p.left,p.right)
            return q
        elif val<p.val:
            p.c-=1
            p.left = self.__random_remove(p.left,val)
        else:
            p.c-=1
            p.right = self.__random_remove(p.right,val)
        return p
    def random_remove(self,val):
        if self.find(val) != None:
            self.root = self.__random_remove(self.root,val)
    def __min_element(self,node):
        if node.left == None:
            return node
        return self.__min_element(node.left)
    
    def __del_by_value(self,currentNode,val):
        if currentNode.val == val:
            if currentNode.right == None:
                return currentNode.left
            elif currentNode.left == None:
                return currentNode.right
            else:
                min_el = self.__min_element(currentNode.right)
                currentNode.val = min_el.val
                currentNode.right = self.__del_by_value(currentNode.right,currentNode.val)
                currentNode.c-=1
                return currentNode
        else:
            if currentNode.val > val and currentNode.left != None:
                currentNode.left = self.__del_by_value(currentNode.left,val)
                currentNode.c-=1
            elif currentNode.right != None:
                currentNode.right = self.__del_by_value(currentNode.right,val)
                currentNode.c-=1
            return currentNode
    def del_by_value(self,val):
        if self.root != None and self.find(val) != None:
            self.root = self.__del_by_value(self.root,val)
    def insert(self,val:int):
        if self.root == None:
            self.root = Node(val)
        else:
            temp = self.root
            while True:
                if temp.val == val:
                    break
                temp.c +=1
                if temp.val > val:
                    if temp.left == None:
                        temp.left = Node(val)
                        break
                    else:
                        temp = temp.left
                else:
                    if temp.right == None:
                        temp.right = Node(val)
                        break
                    else:
                        temp = temp.right
    
    def __del_by_index(self,node,key):
        if node.left != None:
            leftCount=node.left.c+1
        else:
            leftCount = 0
        if key < leftCount:
            node.left = self.__del_by_index(node.left, key)
            node.c -= 1
            return node
        if key==leftCount:
            if node.left == None:
                return node.right
            elif node.right == None:
                return node.left
            else:
                min_el = self.__min_element(node.right)
                node.val = min_el.val
                
                new_key = 0
                if node.right.left != None:
                    new_key = node.right.left.c+1
                node.right = self.__del_by_index(node.right,new_key)
                node.c-=1
                return node
        node.right = self.__del_by_index(node.right, key - leftCount - 1)
        node.c-=1
        return node

    def del_by_index(self,key):
        if self.root == None or self.root.c < key:
            return None
        self.root = self.__del_by_index(self.root,key)

    def find(self,val:int):
        temp = self.root
        while temp.left != None or temp.right != None:
            if temp.val == val:
                return temp
            if temp.val > val:
                if temp.left == None:
                    return None
                else:
                    temp = temp.left
            else:
                if temp.right == None:
                    return None
                else:
                    temp = temp.right
        if temp.val == val:
            return temp
        return None
    def RotRight(self,node):
        temp = node.left
        n_c = 0
        if temp.right != None:
            n_c = temp.right.c+1
        if node.right != None:
            n_c += (node.right.c+1)
        l_c = n_c+1
        if temp.left != None:
            l_c += temp.left.c+1
        node.left = temp.right
        temp.right = node
        node.c = n_c
        temp.c = l_c
        node = temp
        return node
    def RotLeft(self,node):
        temp = node.right
        n_c = 0
        if temp.left != None:
            n_c = temp.left.c+1
        if node.left != None:
            n_c += node.left.c+1
        l_c = n_c+1
        if temp.right != None:
            l_c += temp.right.c+1
        node.right = temp.left
        temp.left = node
        node.c = n_c
        temp.c = l_c
        node = temp  
        return node

    def __root_insert(self,node,n_node):
        if node == None:
            node = n_node
            return n_node
        elif node.val < n_node.val:
            node.c +=1
            node.right = self.__root_insert(node.right,n_node)
            return self.RotLeft(node)
        else:
            node.c +=1
            node.left = self.__root_insert(node.left,n_node)
            return self.RotRight(node)

    def root_insert(self,val):
        temp = Node(val)
        self.root = self.__root_insert(self.root,temp)
        
    def __req_print(self,node):  
        if node.left != None:
            self.__req_print(node.left)
        print(node.val,end = " ")
        if node.right != None:
            self.__req_print(node.right)

    def print_seq(self):
        self.__req_print(self.root)

    def get_tree(self):
        if self.root == None:
            return ""
        return self.root.connections()
    def __find_by_index(self,node,key):
        if node.left != None:
            leftCount=node.left.c
        else:
            leftCount = 0
        if key < leftCount:
            return self.__select_bst(node.left, key)
        if key==leftCount:
            return node.val
        return self.__select_bst(node.right, key - leftCount - 1)
#1
N = 30
seq = random.sample(range(31), N)
seq = [i for i in range(20)]
# #2
tree = BST(seq)
while True:
    num = int(input())
    if num == 100:
        break
    tree.random_remove(num)
    print(tree.get_tree())
tree.print_seq()
