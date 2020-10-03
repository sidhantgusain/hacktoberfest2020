
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
int t;
cin>>t;
while(t--)
{
    int w,n;
    cin>>w>>n;
    int cost[n+1][w+1],W[n+1],val[n+1];
    W[0]=0;
    val[0]=0;
    for(int i=0;i<n;i++)
        cin>>W[i+1]>>val[i+1];
     for(int i=0;i<n+1;i++)
            for(int j=0;j<w+1;j++)
     {
         if(i==0 || j==0)
            cost[i][j]=0;
         else if(j<W[i])
             cost[i][j]=cost[i-1][j];
         else
            cost[i][j]=(cost[i-1][j-W[i]]+val[i])>cost[i-1][j]?(cost[i-1][j-W[i]]+val[i]):cost[i-1][j];
 
     }
     cout<<"Hey stupid robber, you can get "<<cost[n][w]<<"."<<endl;
 
 
}
return 0;
	}
