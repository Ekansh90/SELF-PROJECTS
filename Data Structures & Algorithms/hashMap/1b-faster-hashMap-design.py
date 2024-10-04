class MyHashMap(object):

    def __init__(self):
        self.dict = {}
        

    def put(self, key, value):
        self.dict[key] = value
        
    # call the get method on a dictionary , if not found -1 is returned 
    def get(self, key):
        result = self.dict.get(key, -1)
        return result
        

    def remove(self, key):
        self.dict[key] = -1
        


# Your MyHashMap object will be instantiated and called as such:
obj = MyHashMap()
obj.put(1,3)
obj.put(13,31)
param_2 = obj.get(131)
# obj.remove(key)