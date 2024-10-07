class MinStack(object):

    # MAIN IDEA IS TO KEEP TRACK OF TWO STACKS
    # THE SECONDARY ONLY GETTING POPULATED IF WE FIND A SMALLER or EQUAL ELEMENT DURING PUSH
    # AND getMin retrieves the top of min_Stack
    def __init__(self):
        self.main_stack = []
        self.min_stack = []
        self.main_size = 0 
        self.min_size = 0 
        

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """

        self.main_stack.append(val)

        if len(self.min_stack) == 0  or val <= self.min_stack[-1] :
            self.min_stack.append(val)
            self.min_size += 1

        self.main_size += 1 

        
    # delete element instead of setting to null , otherwise the top element is substituted as null
    def pop(self):
        """
        :rtype: None
        """
        if self.main_size == 0 :
            return None 
        else :
            rm1 = self.main_stack.pop()
            if rm1 == self.min_stack[-1]:
                self.min_stack.pop()

            return None 

    def top(self):
        """
        :rtype: int
        """
        if self.main_size == 0 :
            return None     
        else :
            return self.main_stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        if len(self.min_stack) == 0:
            return None
        else :
            return self.min_stack[-1]