class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = []
        

    def insert(self, word: str) -> None: # O(N)
        """
        Inserts a word into the trie.
        """
        if word not in self.dict:
            self.dict.append(word)
        

    def search(self, word: str) -> bool: # O(N)
        """
        Returns if the word is in the trie.
        """
        return word in self.dict
        

    def startsWith(self, prefix: str) -> bool: # O(N * LengthOfPrefix)
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        for _ in self.dict:
            if _.startswith(prefix):
                return True
        return False


################################################

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isEndOfWord = False
        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        
        

    def insert(self, word: str) -> None: # O(len(word))
        """
        Inserts a word into the trie.
        """
        cur = self.root
        
        for lvl in range(len(word)):
            idx = ord(word[lvl]) - ord('a')
            
            if not cur.children[idx]:
                cur.children[idx] = TrieNode()
            cur = cur.children[idx]
            
        cur.isEndOfWord = True
        
        

    def search(self, word: str) -> bool: # O(len(word))
        """
        Returns if the word is in the trie.
        """
        cur = self.root
        
        for lvl in range(len(word)):
            idx = ord(word[lvl]) - ord('a')
            if not cur.children[idx]:
                return False
            cur = cur.children[idx]
        
        return cur.isEndOfWord
        
        

    def startsWith(self, prefix: str) -> bool: # O(len(prefix))
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur = self.root
        
        for lvl in range(len(prefix)):
            idx = ord(prefix[lvl]) - ord('a')
            if not cur.children[idx]:
                return False
            cur = cur.children[idx]
        
        return True

