def linearsearch(arr,size,key):
    for i in range(len(arr)):
        if arr[i]==key:
            return i
       
     
    return -1




size=int(input("Enter size of array: "))
arr=[]
for i in range(size):
    arr.append(int(input("Enter the element: ")))
key =int(input("Enter element to be searched: "))

ans=linearsearch(arr,size,key)
if ans==-1:
    print("Element Not Found")
else:
    print("Element found at ",ans+1," index")
