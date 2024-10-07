class Node:
    def __init__(self,value,parent=None):
        self.data = value
        self.left = None
        self.right = None
        self.parent = parent

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self,value):
        if not self.root:
            self.root = Node(value)
        else:
            temp = self.root
            while temp != None:
                if temp.data < value:
                    if not temp.right:
                        temp.right = Node(value,temp)
                        temp = temp.right
                    temp = temp.right
                elif temp.data > value:
                    if not temp.left:
                        temp.left = Node(value,temp)
                        temp = temp.left
                    temp = temp.left

    def __insertPreorder__(self,node):
        if node:
            self.insert(node.data)
            self.__insertPreorder__(node.left)
            self.__insertPreorder__(node.right)

    def __inorder__(self,node):
        if node.left:
            self.__inorder__(node.left)
        print(node.data, end=" ")
        if node.right:
            self.__inorder__(node.right)

    def inorder(self):
        print("Inorder: ",  end="")
        self.__inorder__(self.root)
        print()

    def search(self,value):
        #Some code stuff
        temp = self.root
        found = False
        traversed = False
        while not found and not traversed:
            if temp.data > value:
                if not temp.left:
                    traversed = True
                temp = temp.left
            elif temp.data < value:
                if not temp.right:
                    traversed =True
                temp = temp.right
            else:
                found = True
        
        return temp if found else None
    
    def delete(self, value):
        if not self.root:
            return
        elif self.root.data == value:
            current = self.root
            if self.root.right:
                self.root = self.root.right
                self.__insertPreorder__(current.left)
            elif self.root.left:
                self.root = self.root.left
                self.__insertPreorder__(current.right)
            print(f"{current.data} deleted(Root)")
        else:
            current = self.search(value)
            if current:
                parent = current.parent
                if current.data > parent.data:
                    parent.right = None
                else:
                    parent.left = None
                self.__insertPreorder__(current.right)
                self.__insertPreorder__(current.left)
                print(f"{current.data} deleted")
            else:
                print(f"{value} Not Found")


def main():
    tree = BinaryTree()
    tree.insert(31)
    tree.insert(13)
    tree.insert(23)
    tree.insert(54)
    tree.insert(72)
    tree.insert(91)

    tree.inorder()
    tree.delete(14)
    tree.inorder()
    tree.delete(15)
    tree.inorder()
    tree.delete(13)
    tree.inorder()
    tree.delete(31)
    tree.inorder()
    tree.delete(54)
    tree.inorder()
    tree.delete(13)
    tree.inorder()

if __name__ == "__main__":
    main()