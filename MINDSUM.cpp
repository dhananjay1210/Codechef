#include<fstream>
#include<ctime>

#include<stdio.h>
#include<map>
#include<iterator>
#include<queue>
#include<iostream>

#define CLOCKS_PER_SE 733000000
typedef long long int lli;
using namespace std;

lli digsum(lli n){
	lli sum=n;
	//while(sum > 9){
		sum=0;
		while(n>0){
			sum = sum + (n%10);
			n = n/10;
		}
		//n=sum;
	//}
	
	return sum;
}

void showq(queue <lli> gq) 
{ 
    queue <lli> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
void clear( queue<lli> &q )
{
   queue<lli> empty;
   swap( q, empty );
}
int main(){
	ofstream fout ("test.out");
    ifstream fin ("test.in");
	
	int T,i,arr[10];
	lli count2,n,d,dig_n,dig_d,ins1,ins2,min_val,element,temp_back;
	scanf("%d",&T);
	
	while(T--){
		map<lli,lli> m1;
		map<lli,lli>::iterator itr,end;
		queue<lli> q;
		
		count2=1;
		min_val=9;
		
		for(i=0 ; i<10 ; i++){
			arr[i]=0;
		}
		scanf("%lld %lld",&n,&d);
		dig_n=n;
		dig_d=d;
		while(dig_n>=10)
			dig_n = digsum(dig_n);
		while(dig_d>=10)
			dig_d = digsum(dig_d);
		//printf("%d %d",dig_n,dig_d);
		//arr[min_val] = 1;
		while(true){
			dig_n += dig_d;
			while(dig_n>=10)
				dig_n = digsum(dig_n);
			if(dig_n < min_val)
				min_val = dig_n;
			if(arr[dig_n]==1 || dig_n==1)
				break;
			else
				arr[dig_n] = 1;
		}
		/*
		while(n>=100)
			n = digsum(n);
		while(d>=100)
			d=digsum(d);
		*/
		//printf("Expected min val : %d\n",min_val);
		if(min_val==n){
			printf("%lld %lld\n",n,(n-n));
			continue;
		}
		m1.insert(pair<lli,lli>(digsum(n),1));
		m1.insert(pair<lli,lli>(n+d,1));
		end = m1.end();
		q.push(digsum(n));
		q.push(n+d);
		temp_back = q.back();
		
		while(m1.find(min_val) == end){
			count2++;
			/*
			printf("\nMap is :\n");
			for(map<lli,lli>::const_iterator it = m1.begin(); it != m1.end(); ++it)
			{
				cout << it->first << " " << it->second << " " << "\n";
			}
			printf("Queue is:\n");
			showq(q);
			*/
			while(q.front() != temp_back){
				element = q.front();
				q.pop();
				ins1 = digsum(element);
				ins2 = element+d;
				if(m1.find(ins1) == end){
					m1.insert(pair<lli,lli> (ins1,count2));
					q.push(ins1);
				}
				if(m1.find(ins2) == end){
					m1.insert(pair<lli,lli> (ins2,count2));
					q.push(ins2);
				}
			}
			//printf("ins1=%d ins2=%d %lld\n",ins1,ins2,count2);
			element = q.front();
			q.pop();
			ins1 = digsum(element);
			ins2 = element+d;
			if(m1.find(ins1) == end){
				m1.insert(pair<lli,lli> (ins1,count2));
				q.push(ins1);
			}
			if(m1.find(ins2) == end){
				m1.insert(pair<lli,lli> (ins2,count2));
				q.push(ins2);
			}
			//printf("ins1=%d ins2=%d %lld\n",ins1,ins2,count2);
			temp_back = q.back();
			end = m1.end();			
		}
		itr = m1.find(min_val);
		printf("%lld %lld\n",itr->first,itr->second);
		//m1.erase(m1.begin(),m1.end());
		//clear(q);
		cout<< "Done in " << clock() / CLOCKS_PER_SE <<"sec"<< endl;
	}
	return 0;
}