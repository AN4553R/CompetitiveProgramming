class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEndOfWord = False
        
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for ch in word:    
            if not ch in node.children.keys():
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.isEndOfWord = True

    def search(self, word: str) -> bool:
        nodes = [self.root]
        for ch in word:
            next_nodes = []
            for node in nodes:            
                if ch in node.children.keys():
                    next_nodes.append(node.children[ch])
                if ch == '.':
                    next_nodes.extend(node.children.values())
            nodes = next_nodes
        return any(node.isEndOfWord for node in nodes)
                

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
