import matplotlib.pyplot as plt
import random
COUNT = [10]
class AVL: 
    
    class Node:
        def __init__(self,val):
            self.val = val
            self.right = None
            self.left = None
            self.height = 1
    def __init__(self,arr = []):
        self.root = None
        for i in arr:
            self.insert(i)
    def getHeight(self, node):
        if node == None:
            return 0
        return node.height
    def getBalance(self,node):
        if node == None:
            return 0
        return self.getHeight(node.left)-self.getHeight(node.right)
    def RotRight(self, node):
        y = node.left
        y_r = y.right
        y.right = node
        node.left = y_r

        node.height = 1 + max(self.getHeight(node.left),self.getHeight(node.right))
        y.height = 1 + max(self.getHeight(y.left),self.getHeight(y.right))
        return y
    def RotLeft(self, node):
        y = node.right
        y_l = y.left
        y.left = node
        node.right = y_l

        node.height = 1 + max(self.getHeight(node.left),self.getHeight(node.right))
        y.height = 1 + max(self.getHeight(y.left),self.getHeight(y.right))
        return y
    def __insert(self,node,val):
        if node == None:
            return self.Node(val)
        elif val < node.val:
            node.left = self.__insert(node.left, val)
        else:
            node.right = self.__insert(node.right, val)
        node.height = 1 + max(self.getHeight(node.left),self.getHeight(node.right))

        balance = self.getBalance(node)

        if balance > 1 and val < node.left.val:
            return self.RotRight(node)


        if balance < -1 and val > node.right.val:
            return self.RotLeft(node)

        if balance > 1 and val > node.left.val:
            node.left = self.RotLeft(node.left)
            return self.RotRight(node)

        if balance < -1 and val < node.right.val:
            node.right = self.RotRight(node.right)
            return self.RotLeft(node)

        return node
    def insert(self,val):
        self.root = self.__insert(self.root,val)
    def print2DUtil(self,root, space) :
        if (root == None) :
            return
        space += COUNT[0]
        self.print2DUtil(root.right, space)
        print()
        for i in range(COUNT[0], space):
            print(end = " ")
        print(root.val)
        self.print2DUtil(root.left, space)
 
    def print2D(self):
        self.print2DUtil(self.root, 0)
LIMIT = 10000
START = 100
STEP = 100
def randomize(size):
    return random.sample(range(LIMIT+1), size)
def inc(size):
    return [i for i in range(size)]
def dec(size):
    return [size-i-1 for i in range(size)]
def measure(get_seq,title):
    heights = []
    elements = []
    for i in range(START,LIMIT,STEP):
        seq = get_seq(i)
        elements.append(i)
        tree = AVL(seq)
        heights.append(tree.getHeight(tree.root))
    plt.plot(elements,heights)
    plt.title(title)
    plt.show()
tree = AVL([i for i in range(5000)])
tree.print2D()
# measure(randomize,"Random seq")
# measure(inc,"Ascending seq")
# measure(dec,"Descending seq")
