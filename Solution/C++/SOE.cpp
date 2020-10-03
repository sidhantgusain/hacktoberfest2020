
// SIEVE OF ERATHOSTHENES

#include<bits/stdc++.h>

using namespace std;

void soe(int n)
{
    vector<bool> primes(n+1, 1);  //  this is a vector whch is sayinng that this index (n)  is true for all the indexes initially 
    primes[0] = primes[1] = 0;   //make 1, 0 as false, initially only as they can't be the prime no.s

    for(int i=0; i*i<n; i++){   // the loop will cover only till i*i ele  
    //agar 30 eles hai toh loop sief 5 tk hi chalega(5*5 = 25) and 6*6 = 36 toh limit exceed kr di 
        if(primes[i] == 1)
        // agar number prime marked hai toh make the elements 
        for(int ja = i; i*ja <= n; ja++){
           primes[i*ja] = 0;
        }
    }

    for(int i =0; i<=n; i++){
        if(primes[i] == 1){
            cout<<i<<" ";
        }
    }
}

int main(int argc, char** argv){
    int n =100;
    soe(n);
}