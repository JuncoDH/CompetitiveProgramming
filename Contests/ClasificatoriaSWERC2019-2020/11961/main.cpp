/*WA, missing sorting the answer*/
#include <bits/stdc++.h>

#define echo(x) cout << #x << ":" << x << endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int n,k;
int input[10],dat[10];
vector<string> ans;

void permut(int index,int changed){
    if(index==n){
        string s="";
        for(int i=0;i<n;++i){
            if(dat[i]==0)s+="A";
            if(dat[i]==1)s+="C";
            if(dat[i]==2)s+="G";
            if(dat[i]==3)s+="T";
        }
        ans.push_back(s);
        return;
    }
    if(changed==k){
        dat[index]=input[index];
        permut(index+1,changed);
        return;
    }
    dat[index]=(input[index]);
    permut(index+1,changed);
    for(int i=1;i<4;++i){
        dat[index]=(input[index]+i)%4;
        permut(index+1,changed+1);
    }
    
}

int main(void) {
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        ans=vector<string>();
        if(n==0){
            cout<<"0\n";
            continue;
        }
        cin>>s;
        for(int i=0;i<s.length();++i){
            switch(s[i]){
                case 'A':
                    input[i]=0;break;
                case 'C':
                    input[i]=1;break;
                case 'G':
                    input[i]=2;break;
                case 'T':
                    input[i]=3;break;
            }
        }
        permut(0,0);
        cout<<ans.size()<<"\n";
        for(string s:ans){
            cout<<s<<"\n";
        }
        
    }

    return 0;
}

/*
 1
 3 1
 AAA
 
 
 
 
 
 */