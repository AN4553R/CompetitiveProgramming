class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = []
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if word not in self.dict:
            self.dict.append(word)
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return word in self.dict
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        for _ in self.dict:
            if _.startswith(prefix):
                return True
        return False


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
