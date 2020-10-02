import java.io.*;
import java.util.*;
class GFG  
{  
public static void main(String args[]) throws IOException
  { 
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(); //Enter size of array
    int x=sc.nextInt(); //Enter the number you want to find
    int arr[]=new int[n];
    for(int i=0;i<n;i++)   //Enter the array
    {
        arr[i]=sc.nextInt();
    }
      
    int result = search(arr, x); 
    if(result == -1) 
        System.out.print("Element is not present in array"); 
    else
        System.out.print("Element is present at index " + result); 
  } 
public static int search(int arr[], int x) 
{ 
    int n = arr.length; 
    for(int i = 0; i < n; i++) 
    { 
        if(arr[i] == x) 
            return i; 
    } 
    return -1; 
} 
  
} 
