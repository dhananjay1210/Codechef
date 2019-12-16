#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	long T;
	long long n,k;
	int flag;
	cin>>T;
	cout<<setprecision(6)<<fixed;
	while(T--){
		cin>>n>>k;
		if(n==1){
			cout<<1.0<<endl;
			continue;
		}
		else if(n==2){
			cout<<0.5<<endl;
			continue;
		}
		else{
			flag=0;
			while(n!=1 && k!=0){
				if(n%2==0){
					n = n/2;
					if(n%2==1 && n!=1 && flag==0)
						n += 1;
				}
				else{
					n = (n/2) +1;
				}
				k--;
				flag=1;
				//cout<<n<<endl;
			}
			cout<<1.0/n<<endl;
		}
	}
}