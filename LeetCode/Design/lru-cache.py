class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cash = {}
    
    
    def get(self, key) -> int:
        # move to end if recently used
        value = self.cash.get(key)
        if value is not None:
            del self.cash[key]
            self.cash[key] = value
            return value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cash:
            del self.cash[key]
        else:
            if len(self.cash) == self.capacity:
                del self.cash[next(iter(self.cash))] # remove first element (least used)            
        self.cash[key] = value

        
## OR


class LRUCache:

    def __init__(self, capacity: int):
        self.cache = collections.OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            self.cache.move_to_end(key)
            return self.cache[key]
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
