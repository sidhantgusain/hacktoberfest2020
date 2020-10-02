def binarysearch(arr,low,high,key):
    mid = (low+high)//2
    if low<high:
        
        if arr[mid]==key:
            return mid
        elif arr[mid]<key:
            return binarysearch(arr,mid+1,high,key)
        elif arr[mid]>key:
            return binarysearch(arr,low,mid-1,key)
        else:
            pass
    else:
        return -1



print("Enter a sorted array:")
size=int(input("Enter size of array: "))
arr=[]
for i in range(size):
    arr.append(int(input("Enter the element: ")))
key =int(input("Enter element to be searched: "))

ans=binarysearch(arr,0,size-1,key)
if ans==-1:
    print("Element Not Found")
else:
    print("Element found at ",ans+1," index")
