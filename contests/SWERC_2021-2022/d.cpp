#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
int n,m;
vl people;
vl prefixSum;
vl iceCream;
vl huts;
vl leftIce;
vl rightIce;
int main() {

    cin>>n>>m;
    vl prepeople=vl(n);
    prefixSum=vl(n+1);
    prefixSum[0]=0; 

    vl prehuts(n);
    for(int i=0;i<n;++i){
        cin>>prepeople[i];
        
        prehuts[i]=100*i;
    }
    iceCream=vl(m);
    for(int i=0;i<m;++i){
        cin>>iceCream[i];
        if(iceCream[i]%100==0){
            if(iceCream[i]/100<n)
            prehuts[iceCream[i]/100]=-1;
        }
    }
    sort(iceCream.begin(),iceCream.end());
    for(int i=0;i<n;++i){
        if(prehuts[i]!=-1){
            people.pb(prepeople[i]);
            huts.pb(prehuts[i]);
        }
    }
    n=huts.size();
    if(n==0){
        cout<<"0\n";
        return 0;
    }
    for(int i=0;i<n;++i){
        prefixSum[i+1]=prefixSum[i]+people[i];
    }
    

    int nextIce=0;
    for(int i=0;i<n;++i){
        while(nextIce<m && iceCream[nextIce]<huts[i]){
            nextIce++;
        }
        leftIce.pb(nextIce-1);
        if(nextIce==m){
            rightIce.pb(-1);
        }
        else{
            rightIce.pb(nextIce);
        }

    }
/*
    for(int i=0;i<n;++i){
        cout<<i<<" "<<leftIce[i]<<" "<<rightIce[i]<<endl;
    }
*/
    ll ans = 0;
    for(int left = 0;left<n;++left){
        int il = leftIce[left];
        int ir = rightIce[left];
        //cout<<"l:"<<left<<" "<<il<<" "<<ir<<" "<<huts[left]<<endl;
        if(il==-1){
            int bl,br;
            bl = left;
            br = (int)huts.size()-1;
            if(leftIce.back()==-1){
                ans = max(ans, prefixSum[n]-prefixSum[left]);
            }
            else{
                while(br-bl>1){
                int mid = (bl+br)/2;
                if(leftIce[mid]==-1){
                    bl=mid;
                }
                else{
                    br = mid;
                }
            }
                //cout<<left<<" "<<bl<<endl;
                ans = max(ans, prefixSum[bl+1]-prefixSum[left]);
            }
            

        }
        else if(ir==-1){
            ans = max(ans, prefixSum.back()-prefixSum[left]);
            //cout<<left<<" "<<n<<" "<<ans<<endl;
        }
        else{
            ld increment = (huts[left]-iceCream[il]);
            //cout<<increment<<" ";
            increment += (iceCream[ir]-(increment+huts[left]))/2;
            //cout<<increment<<endl;
            if(huts.back()<increment+huts[left]){
                ans = max(ans, prefixSum.back()-prefixSum[left]);
                //cout<<"increment: "<<increment<<endl;
                //cout<<huts.back()-huts[left]<<" "<<left<<" "<<n<<" "<<ans<<endl;
            }
            else{
                int bl,br;
                bl = left;
                br = (int)huts.size()-1;
                while(br-bl>1){
                    int mid = (bl+br)/2;
                    if(huts[mid]-huts[left]<increment){
                        bl=mid;
                    }
                    else{
                        br = mid;
                    }
                }
                
                ans = max(ans, prefixSum[bl+1]-prefixSum[left]);
                //cout<<left<<" "<<bl<<" "<< ans<<endl;
            }
            

        }

    }
    ans=max(ans,people[n-1]);
    cout<<ans<<"\n";


    return 0;
}