#include <bits/stdc++.h> 
using namespace std;

long long int expo(long long int x, long long int y){
	if(y==1) return x;
	long long int res = expo(x,y/2);
	
	if(y%2) return res*res*x;
	else return res*res;
}

int main(){
	long long int t,l,alice;
	string s;
	float score;	
	cin >> t;

	for (int q=0 ; q<t ; q++){
		cin >> l;
		map<char,long long int>a_total,b_total,a_doc,b_doc;
		long long int a=0,b = 0; 
		for(int i=0 ; i<l ; i++){
			cin >> s;
			alice = 1;
			int v,c;
			for (int j=1 ; j < s.length() ; j++){
				v = 0;
				c = 0;
				for (int k=0 ; k<3 ; k++){
					if (j-k >= 0){
						if (s[j-k]=='a' || s[j-k]=='e' || s[j-k]=='i' || s[j-k]=='o' || s[j-k]=='u') v++;
						else c++;
					}
				}
				if (v<c){
					alice = 0;
					break;
				}
			}
			bool hs[26];
			for (int z = 0; z < 26; z++)
			{
				hs[z] = true;
			}
			
			for (int j=0 ; j < s.length() ; j++){
				if (alice){
					a_total[s[j]]++;
					if(hs[int(s[j]) - 97]){
						hs[int(s[j]) - 97] = false;
						a_doc[s[j]]++;
					}
				}
				else{
					b_total[s[j]]++;
					if(hs[int(s[j]) - 97]){
						hs[int(s[j]) - 97] = false;
						b_doc[s[j]]++;
					}
				}
			}
			if(alice) a++;
			else b++;		
		}
		
		vector<long long int>l1,l2;
		for(auto pair : a_doc){
			l1.push_back(pair.second);
			l2.push_back((int)(pow(a_total[pair.first],a)+0.5));
		}
		for(auto pair : b_doc){
			l1.push_back((int)(pow(b_total[pair.first],b)+0.5));
			l2.push_back(pair.second);
		}
		sort(l1.begin(), l1.end());
		sort(l2.begin(), l2.end());
		
		float score=1;
		long int i=0,j=0;
		
		while(i<l1.size() && j<l2.size()){
			if(score<=1e15 && l1[i]<1e15){
				score *= l1[i];
				i++;
			}
			else if(score>1e15 && l1[j]<1e30){
				score /= l2[j];
				j++;
			}
		}
		while(i<l1.size()){
			score *= l1[i];
			i++;
		}
		while(j<l2.size()){
			score /= l2[j];
			j++;
		}
		
		if(score > 10000000){
			cout << "Infinity" << endl;
		}
		else {
			cout << score << endl;
		}
		
	}
	return 0;
}