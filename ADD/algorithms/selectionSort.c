#include<stdio.h>
int main(){
    /*
        array with max element limit upto 25
        i & j are the looping variables
        count variable to get total number of elements user want to sort
    */
   int i, j, count, temp, array[25];

   printf("How many numbers u are going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&array[i]);
 
   // Logic of selection sort algorithm
   for(i=0;i<count;i++){

      for(j=i+1;j<count;j++){

         if(array[i]>array[j]){

            temp=array[i];
            array[i]=array[j];
            array[j]=temp;

         }
      }
   }
    //displaying all orted elements
   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",array[i]);

   return 0;
}