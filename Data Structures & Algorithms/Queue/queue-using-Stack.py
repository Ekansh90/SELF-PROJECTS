class MyQueue(object):

    def __init__(self):

        # in
        self.s1 = []
        
        # out
        self.s2 = []


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.s1.append(x)

        


    def pop(self):
        """
        :rtype: int
        """
        # shift elements from s1 to s2 , now s2 has everything in reverse order to making deque easier
        if not self.s2 :
            self.__move__()
           

        if self.s2 :
            return self.s2.pop()
            
        else :
            return None 
    

                
            



        

    def peek(self):
        """
        :rtype: int
        """
        # if s2 empty shift from s1 
        if not self.s2  :
            self.__move__()
        
        if self.s2 :
            return self.s2[-1] # return top

        

    def empty(self):
        """
        :rtype: bool
        """
        return not self.s1 and not self.s2 
        
    def __move__(self):
        while self.s1 :
            self.s2.append(self.s1.pop()) 


# Your MyQueue object will be instantiated and called as such:
obj = MyQueue()
param_3 = obj.peek()
param_2 = obj.pop()
param_4 = obj.empty()