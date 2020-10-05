//Java program to implement Quick Sort algorithm

import java.util.*;
public class QuickSort {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("No. of elements in array? ");
		int n = s.nextInt();
		int a[] = new int[n];
		System.out.println("Enter the array elements- ");
		for(int i=0;i<n;i++)
			a[i] = s.nextInt();
		System.out.println("The unsorted array is - ");
		for(int i=0;i<n;i++)
			System.out.print(a[i] + " ");
		quickSort(a,0,n-1);
		
		System.out.println("\n\nThe sorted array is- ");
		for(int i=0; i<n; i++)
			System.out.print(a[i] + " ");
	}
		
	//Quick Sort
	public static void quickSort(int a[], int lb, int ub)
	{
		if(lb < ub)
		{
			int loc = partition(a,lb,ub);	//Partitioning
			quickSort(a,lb,loc-1);
			quickSort(a,loc+1,ub);
		}
	}
	
	public static int partition(int a[],int lb,int ub)
	{
		int temp;
		int pivot = a[lb];					//Our pivot element
		int start = lb;
		int end = ub;
		
		while(start < end)
		{
			while(a[start] <= pivot && start<end)
				start++;
			
			while(a[end] > pivot)
				end--;
			
			if(start<end)
			{
				temp = a[start];
				a[start] = a[end];
				a[end] = temp;
			}
		}
		//swap pivot and a[end]
		temp = a[lb];
		a[lb] = a[end];
		a[end] = temp;
		return end;
	}
}
