class Node:
    def __init__(self, val = None, nxt = None):
        self.val = val
        self.next = nxt
        
class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.size = 0

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.size:
            return -1
        
        ptr = self.head
        
        while index:
            ptr = ptr.next
            index-=1
            
        return ptr.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        newNode = Node(val, self.head)
        self.head = newNode
        self.size+=1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        newNode = Node(val)
        ptr = self.head
        if not ptr:
            self.head = newNode
        else:
            while ptr.next:
                ptr = ptr.next
            ptr.next = newNode
        self.size+=1

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index > self.size:
            return
        
        if index == 0:
            self.addAtHead(val)
        elif index == self.size:
            self.addAtTail(val)
        else:
            
            ptr = self.head

            while index > 1:
                ptr = ptr.next
                index-=1

            tmp = ptr.next
            ptr.next = Node(val, tmp)

            self.size+=1
        
    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index >= self.size:
            return
        
        if index == 0:
            self.head = self.head.next
        else:
            ptr = self.head
            while index > 1:
                index-=1
                ptr = ptr.next
            ptr.next =  ptr.next.next
            
        self.size-=1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
