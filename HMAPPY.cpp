#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define MAX 100001
#define MAX_VAL 1000000001

using namespace std;
typedef long long int lli;
struct node{
		lli a;
		lli b;
		lli prod;
	};

	
bool compare1(node x, node y){
	return x.prod < y.prod;
}

int main(){
	
	lli n,m,i,ind_max1=-1,ind_max2=-1,sum=0,temp;
	lli largest,l,r;
	vector<node> v(MAX);
	//iterator itr;
	
	scanf("%lld %lld",&n,&m);
	//itr = v1.end();
	
	for(i=0 ; i<n ; i++){
		scanf("%lld",&v[i].a);
	}
	for(i=0 ; i<n ; i++){
		scanf("%lld",&v[i].b);
		v[i].prod=(v[i].a)*(v[i].b);
		sum += v[i].a;
	}
	
	if(m>=sum){
		printf("%d\n",0);
		return 0;
	}
	if(n==1){
		printf("%lld\n",(v[0].a - m)*(v[0].b));
		return 0;
	}
	if(n==2){
		int flag=0;
		if(v[1].prod > v[0].prod){
			flag=1;
		}
		while(m){
			while(v[flag].prod >= v[abs(flag-1)].prod && m){
				v[flag].prod = v[flag].prod - v[flag].b;
				m--;	
			}
			if(flag==0)
				flag=1;
			else
				flag=0;
		}
		printf("%lld\n",max(v[0].prod,v[1].prod));
		return 0;
	}
	//vector<node> v(arr,arr+n);
	make_heap(v.begin(),v.end(),compare1);
	//sort(arr,arr+n,compare1);
	
	//for(i=0 ; i<n ; i++){
	//	printf("%lld   %lld   %lld\n",v[i].a,v[i].b,v[i].prod);
	//}
	
	i=0;
	while(m){
		//max1=arr[0];
		if(v[1].prod>=v[2].prod)
			ind_max2 = 1;
		else
			ind_max2=2;
		
		while(v[0].prod >= v[ind_max2].prod && m){
			v[0].prod = v[0].prod - v[0].b;
			m--;	
		}
		
		//heapify max heap
		i=0;
		while(true){
			largest=0;
			l=2*i +1;
			r=2*i +2;
			if(l<n && v[l].prod > v[i].prod){
				largest=l;
			}
			else{
				largest=i;
			}
			if(r< n && v[r].prod > v[largest].prod){
				largest=r;
			}
			if (largest!=i){
				node t=v[i];
				v[i]=v[largest];
				v[largest]=t;
				i=largest;
			}
			else{
				break;
			}
		}
		/*
		printf("\nAfter :\n");
		for(i=0 ; i<n ; i++){
			printf("%lld   %lld   %lld\n",v[i].a,v[i].b,v[i].prod);
		}
		*/
	} 
	/*
	printf("\nAfter :\n");
	for(i=0 ; i<n ; i++){
		printf("%lld   %lld   %lld\n",arr[i].a,arr[i].b,arr[i].prod);
	}
	*/
	printf("%lld\n",v[0].prod);
	return 0;
}