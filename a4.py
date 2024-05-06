def create_set():
    myset=[]
    choice='y'
    while (choice[0]=='y'):
        print("\nEnter number:")
        num=int(input())
        myset.append(num)
        print("\n Do you want to enter more number(y/n):")
        choice=input()
    return myset

def AddElement(A,num):
    print("Enter position at which you want to insert element:")
    pos=int(input())
    for i in range(len(A)):
        if(i==pos):
            A=A[:pos]+[num]+A[pos:]
    print(A)
    
def RemoveElement(A,num):
    count=0
    for i in range(len(A)):
        if(A[i]==num):
            count+=1
    if(count>=1):
        pos=A.index(num)
        new_A=A[:pos]+A[pos+1:]
        print(new_A)
    else:
        print("element not found in array")
def Union(setA,setB):
    C=list({i:i for i in setA + setB}.values())
    print("union set:",C)
    
def Intersection(setA,setB):
    C=[i for i in setA if i in setB]
    print("intersection set:",C)
    
    
def Difference(setA,setB):
    C=[element for element in setA if element not in setB]
    print("Difference set:",C)
    
def Contains_element(A,num):
    found=False
    for i in range(len(A)):
        if(A[i]==num):
            found=True
            break
        else:
            found=False
    return found

def size_of_set(A):
    count=0
    for i in range(len(A)):
        count+=1
    return count

def subset(A,B):
    status=False
    if(all(i in A for i in B)):
        status=True
    if(status):
        print("\n Yes subset exists")
    else:
        print("\n No subset does not exists")   
        

A={}
print("\nCreate set A")
A=create_set()
print("A=",A)

B={}
print("\nCreate set B")
B=create_set()
print("B=",B)

while(True):
    print("1.Add")
    print("2.Remove")
    print("3.Membership of element")
    print("4.Size")
    print("5.union")
    print("6.intersection")
    print("7.difference")
    print("8.check subset")
    print("9.exit")
    print=("Enter your choice:")
    choice=int(input())
    
    if choice==1:
        print("A:",A)
        num=int(input("Enter number to be added in set:"))
        AddElement(A,num)
    
    elif choice==2:
        print("A:",A)
        num=int(input("Enter number to be rremoved from set:"))
        RemoveElement(A,num)
        
    elif choice==3:
        print("A:",A)
        num=int(input("Enter number to be searched in set:"))
        if(Contains_element(A,num)):
            print("element present in the set")
        else:
            print("element not present in the set")
            
    elif choice==4:
        print("A:",A)
        print("\nsize of the set :",size_of_set(A))
    
    elif choice==5:
        print("A:",A)
        print("B:",B)
        Union(A,B)
        
    elif choice==6:
        print("A:",A)
        print("B:",B)
        Intersection(A,B)
        
    elif choice==7:
        print("A:",A)
        print("B:",B)
        Difference(A,B)
        
    elif choice==8:
        print("A:",A)
        print("B:",B)
        subset(A,B)

    else:
        print("thank you") 
        break     
        
        
    
    
