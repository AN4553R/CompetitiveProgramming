# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class BSTIterator:
    
    def inOrder(self, root:TreeNode) -> None:
        if not root:
            return
        self.inOrder(root.left)
        self.queue.append(root.val)
        self.inOrder(root.right)
        
    def __init__(self, root: TreeNode):
        self.root = root
        self.queue = deque()
        self.inOrder(root)

    def next(self) -> int:
        return self.queue.popleft()

    def hasNext(self) -> bool:
        return len(self.queue) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()


######################################################################################

class BSTIterator:
    
    def inOrder(self, root:TreeNode) -> None:
        if not root:
            return
        self.inOrder(root.left)
        self.arr.append(root.val)
        self.inOrder(root.right)
        
    def __init__(self, root: TreeNode):
        self.root = root
        self.idx = 0
        self.arr = []
        self.inOrder(root)

    def next(self) -> int:
        result = self.arr[self.idx]
        self.idx+=1
        return result

    def hasNext(self) -> bool:
        return self.idx < len(self.arr)
