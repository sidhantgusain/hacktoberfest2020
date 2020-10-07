num = int(input("Enter any number: "))  
sum = 0  
temp = num  
  
while temp>0:  
   digit=temp % 10  
   sum+=digit ** 3  
   temp //= 10  
  
if num == sum:  
   print(num," -> Armstrong number")  
else:  
   print(num," -> Not an Armstrong number")
