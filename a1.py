class HashingDemo:
    def __init__(self):
        self.size=int(input("ENter size of hash table:"))
        self.HashTable=list(0 for i in range(self.size))
        self.num_of_elements=0
        self.comparisons=0
        
    def isTableFull(self):
        if self.num_of_elements==self.size:
            return True
        else:
            return False
        
    def HashFun(self,element):
        return element%self.size
    
    def InsertElement_Linear(self,element):
        if self.isTableFull():
            print("Hash table full")
            return False
        OccupiedStatus=False
        
        position=self.HashFun(element)
        if self.HashTable[position]==0:
            self.HashTable[position]=element
            print("telephone number "+str(element)+" at position "+str(position))
            OccupiedStatus=True
            self.num_of_elements += 1
        else:
            print("collision has occured for telephone number "+str(element)+" at index "+str(position))
            position=self.LinearProbing(element,position)
            self.HashTable[position]=element
            OccupiedStatus=True
            self.num_of_elements += 1
        return OccupiedStatus
    
    def LinearProbing(self,element,position):
        while self.HashTable[position]!=0:
            position+=1
            if position >= self.size:
                position=0
        return position
    
    def InsertElement_Quadratic(self,element):
        if self.isTableFull():
            print ("hash table full")
            return False
        
        OccupiedStatus=False
        position=self.HashFun(element)
        if self.HashTable[position]==0:
            self.HashTable[position]=element
            print("telephone number "+str(element)+" at position "+str(position))
            OccupiedStatus=True
            self.num_of_elements += 1
        else:
            print("Collision has occurred for telephone number "+str(element)+" at index "+str(position))
            OccupiedStatus,position=self.quadraticProbing(element,position)  
            if OccupiedStatus:
                self.HashTable[position]=element
                self.num_of_elements += 1
            self.HashTable[position]=element
            OccupiedStatus=True
            self.num_of_elements += 1
        return OccupiedStatus
    
    def quadraticProbing(self,element,position):
        Found=False
        limit=50
        i=1
        while i<=limit:
            newPosition = position + (i**2)
            newPosition = newPosition % self.size  
            if self.HashTable[newPosition]==0:
                Found=True
                break
            else:
                i+=1
        return Found,newPosition
    
    def search(self,element):
        found=False
        position=self.HashFun(element)
        self.comparisons+=1
        if(self.HashTable[position]==element):
            isFound=True
            return position
        else:
            temp=position-1
            while position<self.size:
                if self.HashTable[position]!=element:
                    position+=1
                    self.comparisons+=1
                else:
                    return position
                
                positon=temp
                while position>=0:
                    if self.HashTable[position]!=element:
                        position-=1
                        self.comparisons+=1
                    else:
                        return position
        if not found:
            print("element not found")
            return False
        
    def display(self):
        print("\n")
        print("\nPosition\tTelephone Number\n")
        for i in range (self.size):
            print("\t"+str(i)+"====> "+str(self.HashTable[i]))
    

hash_obj1=HashingDemo()
hash_obj1.InsertElement_Linear(111111112)
hash_obj1.InsertElement_Linear(222222221)
hash_obj1.InsertElement_Linear(333333337)
hash_obj1.InsertElement_Linear(444444440)
hash_obj1.InsertElement_Linear(555555551)
hash_obj1.InsertElement_Linear(666666668)
hash_obj1.InsertElement_Linear(888888887)

hash_obj1.display()
print()
print("position of number 222222221 is:"+str(hash_obj1.search(222222221)))
print("position of number 555555551 is:"+str(hash_obj1.search(555555551)))
print("position of number 888888887 is:"+str(hash_obj1.search(888888887)))

print("comparisions:"+str(hash_obj1.comparisons))


hash_obj2=HashingDemo()
hash_obj2.InsertElement_Quadratic(111111112)
hash_obj2.InsertElement_Quadratic(222222221)
hash_obj2.InsertElement_Quadratic(333333337)
hash_obj2.InsertElement_Quadratic(444444440)
hash_obj2.InsertElement_Quadratic(555555551)
hash_obj2.InsertElement_Quadratic(66666668)
hash_obj2.InsertElement_Quadratic(888888887)

hash_obj2.display()
print()
print("position of number 222222221 is:"+str(hash_obj2.search(222222221)))
print("position of number 555555551 is:"+str(hash_obj2.search(555555551)))
print("position of number 888888887 is:"+str(hash_obj2.search(888888887)))

print("comparisions:"+str(hash_obj2.comparisons))



                    
                
        
