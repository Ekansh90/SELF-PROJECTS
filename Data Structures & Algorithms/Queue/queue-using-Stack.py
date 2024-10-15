class MyQueue(object):

    def __init__(self):

        # in
        self.s1 = []
        self.s1_size = 0
        
        # out
        self.s2 = []
        self.s2_size = 0

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.s1.append(x)
        self.s1_size += 1 
        


    def pop(self):
        """
        :rtype: int
        """
        if self.s1_size == 0 :
            return None 
        
        elif self.s1_size == 1 :
            rm = self.s1.pop()
            self.s1_size -= 1 
            return rm 
        
        else :
            for i in range(1, self.s1_size):
                self.s2.append(self.s1[i])
                self.s2_size += 1 

            rm = self.s1[0]

            self.s1 = self.s2 
            self.s1_size = self.s2_size

            
            self.s2 = []
            self.s2_size = 0 
            

            return rm 

                
            



        

    def peek(self):
        """
        :rtype: int
        """
        return self.s1[0]
        

    def empty(self):
        """
        :rtype: bool
        """
        return self.s1_size == 0 
        


# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
obj.push(1)
obj.push(2)
obj.push(3)
param_3 = obj.peek()
param_2 = obj.pop()
param_4 = obj.empty()