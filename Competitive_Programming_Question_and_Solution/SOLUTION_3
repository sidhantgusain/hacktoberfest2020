    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        string s;
        while(cin>>s && s[0]!='0')
        {
            int n=s.length();
            long long int dp1[n],dp2[n];
            dp1[0]=1;dp2[0]=0;
            for(int i=1;i<n;i++)
            {
                if(s[i]=='0')
                {
                    dp2[i]=dp1[i-1];
                    dp1[i]=0;
                    continue;
                }
                int x=(s[i-1]-'0')*10+s[i]-'0';
                if(x<=26)
                {
                    dp1[i]=dp1[i-1]+dp2[i-1];
                    dp2[i]=dp1[i-1];
                }
                else
                {
                    dp1[i]=dp1[i-1]+dp2[i-1];
                    dp2[i]=0;
                }
            }
            cout<<dp1[n-1]+dp2[n-1]<<endl;
        }
    }
     
