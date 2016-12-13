#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int n;


        cin>>n;
  int c=0;
  int i=2;
  int g=0;
  n=n*2;
        while(c<=n){
            i++;
        for (int j=2; j*j<=i; j++)
        {

            if (i % j == 0)
                break;
            else if (j+1 > sqrt(i)) {
                    c++;

                                  cout<<i<<" ";
                                g++;
                               if(g == 2){
                            cout<<"\n";
                            g=0;
                        }

            }

        }
        }
        /*
        i=0;
        int g=0;
while(n>0){
    if(a[i]==a[i+1]-2){
        cout<<a[i]<<" "<<a[i+1]<<"\n";
        n=n-1;
        g++;
        cout <<g<<endl;
    }
    i++;
}
*/
    return 0;
}
