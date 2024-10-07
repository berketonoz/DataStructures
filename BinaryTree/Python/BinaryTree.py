class Node:
    def __init__(self,value):
        self.data = value
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root 

    def insert(self,value):
        if not self.root:
            self.root = Node(value)
        else:
            temp = self.root
            inserted = False
            while not inserted and temp.data != value:
                if temp.data < value:
                    if not temp.right:
                        temp.right = Node(value)
                        inserted = True
                    temp = temp.right
                elif temp.data > value:
                    if not temp.left:
                        temp.left = Node(value)
                        inserted = True
                    temp = temp.left

    def inorder(self,node):
        if node.left:
            self.inorder(node.left)
        print(node.data)
        if node.right:
            self.inorder(node.right)

    def search(self,value):
        #Some code stuff
        temp = self.root
        found = False
        traversed = False
        while not found and not traversed:
            if temp.data == value:
                found = True
            
            if temp.data > value:
                if not temp.left:
                    traversed = True
                temp = temp.left
            elif temp.data < value:
                if not temp.right:
                    traversed =True
                temp = temp.right
        
        return found and not traversed



def main():
    tree = BinaryTree()
    tree.insert(10)
    tree.insert(5)
    tree.insert(4)
    tree.insert(13)
    tree.insert(19)
    tree.inorder(tree.getRoot())


if __name__ == "__main__":
    main()