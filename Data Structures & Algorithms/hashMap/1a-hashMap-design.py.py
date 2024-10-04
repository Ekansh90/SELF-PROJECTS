"""
Leetcode - Problem 706 

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
"""

# implemented using a list
class MyHashMap(object):

    # LIST IS NOT OPTIMAL AS IT NEEDS RESIZING , MULTIPLE TIMES
    def __init__(self, cap = 10):
        
        self.cap = cap
        self.items = [None]* self.cap
        
    """
    For the requirements of this problem 
    We modify the value if a pre-existing values exists for the same key
    """
    def put(self, key = None , value = None ):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key < self.cap :
            self.items[key] = value

        else : 
            # create temp new hash map
            new_map = MyHashMap(self.cap * 2)

            # copy items from original map to new
            for i in range(self.cap):
                new_map.put(i, self.items[i])

            # put the new value inside the new hash map
            new_map.put(key, value)

            # copy everything from new to original hash map
            self.cap = new_map.cap
            self.items = new_map.items
        

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key < self.cap :
            if self.items[key] is not None :
                return self.items[key]
            
        return -1 
        

    def remove(self, key):
        """
        :type key: int
        :rtype: None
        """
        if key > self.cap :
            pass
        else :
            if self.items[key] is not None :
                del self.items[key] 

    # In case of collision on insertion of value on pre-existing pair 
    # Implemented using Linear probing 
    def find_next_hash_index(self, key):
        
        for i in range(self.cap):
            if self.items[(key + i )%self.cap] is None :
                return (key + i )%self.cap 
            
            # quadratic probing 
            # ( key + (i*i) ) % self.cap 
            
            # double hashing , key=> hash index 1 , h2 => hash index 2  
            # ( key + i(h2) ) % self.cap
        

            

myHashMap = MyHashMap()
"""
myHashMap.put(0,1)
myHashMap.put(1, 1)
myHashMap.put(9, 9)

# finding index where next value for hash index 9 should be inserted 
# assuming we do not modify the value if a pre-existing key is present 
nxt = myHashMap.find_next_hash_index(9)


a = myHashMap.get(1)    # return 1, The map is now [[1,1], [2,2]]
b = myHashMap.get(3)    # return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1) # The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2)    # return 1, The map is now [[1,1], [2,1]]
#myHashMap.remove(2) # remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2)
"""

myHashMap.remove(14)                    
a = myHashMap.get(4)                    
myHashMap.put(7,3)                    
myHashMap.put(11,1)                    
myHashMap.put(12,1)                    
myHashMap.get(7)                    
myHashMap.put(1, 19)                    
myHashMap.put(0, 3)                    
myHashMap.put(1, 8)                    
myHashMap.put(2, 6)                    


