#include<iostream>
using namespace std;

int main(){
	int n,c,MXCOST=1000,min=1,max,inc,graderInp=0,checked=0,addby,shift;
	cin >> n >> c;
	inc = 1000;
	addby = 500;
	shift = 1;
	max = min + inc;
	if(max > n)
		max = n;
	if(n==1){
		cout << "3 1" << endl;
		return 0;
	}
	
	while( (max-min+1) > MXCOST){
		if(graderInp==0){
			cout << "1 "  << max << endl;
			MXCOST--;
		}
		
		cin >> graderInp;
		if(graderInp==1){
			MXCOST = MXCOST - c;
			//if((min != mid-1))
				cout << "2" << endl;
			addby  = addby / shift;
			shift << 1;
			max = min + addby;
			
			cout << "1 "  << max << endl;
			MXCOST--;
			cin >> graderInp;
			if(graderInp==1){
				MXCOST = MXCOST - c;
				cout << "2" << endl;
				max = max -1;
				checked = 1;
			}
			else{
				min = max + 1;
				max = min + addby;
				if(max > n)
					max = n;
			}
			
			graderInp=0;
		}
		else if(graderInp==0){
			min = max+1;
			max = min + inc;
			if(max > n)
				max = n;
			if(checked)
					max = min;
		}

		//cout << "Rem cost : "<<MXCOST << "\t\t diff : " << (max - min) << endl;
	}
	
	graderInp=0;
	while(min<max && !graderInp){
		cout << "1 "  << min << endl;
		cin >> graderInp;
		min++;
	}
	if(graderInp)
		cout << "3 " << min-1 << endl;
	else
		cout << "3 " << min << endl;
	
}