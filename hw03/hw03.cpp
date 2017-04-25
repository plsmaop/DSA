#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<bitset>
using namespace std;
unsigned long long nextMap(unsigned long long map, int action);
int ans[10000][16];

bool is2048(unsigned long long& tmp){
	bitset<64> check(tmp);
	bitset<4> single;
	bitset<4> True(11);
	for(int i = 0; i <= 63; i=i+4){
		for(int j = 0; j <=3; j++){
			single[j] = check[i+j];
		}
		if(single == True) return true;
	}
	return false;
}
vector<int> convert(unsigned long long& final){
	bitset<64> tmp(final);
	bitset<4> single;
	vector<int> out;
	for(int i = 0; i <= 63; i=i+4){
		for(int j = 0; j <=3; j++){
			single[j] = tmp[i+j];
		}
		unsigned long pow = single.to_ulong();
		int num = (1<<pow);
		if(num == 1) out.push_back(0);
		else out.push_back(num);
	}
	return out;
}


unsigned long long DFS_RECURSION(unsigned long long &initMap, vector<int>& action){
	unsigned long long tmp = initMap;
	if(is2048(tmp)) return tmp;
	unsigned long long next=0;
	for(int i = 0; i <= 3; i++){
		next = nextMap(tmp,i);
		if(next != tmp){												//not dead end
			action.push_back(i);
			next = DFS_RECURSION(next,action);
		}
		if(is2048(next)) return next;
	}
	action.pop_back();
	return 0;
}

void DFS(unsigned long long& initMap){
	vector<int> action;
	unsigned long long final= DFS_RECURSION(initMap,action);
	
	if(final != 0) {
		vector<int> out = convert(final);
		cout << "Action:\n"; for(auto i : action) cout << i << " ";
		cout << "\nFinal:\n"; 
		for(int i = 0; i <=15 ; i= i+4){
			for(int j = 0; j <= 3; j++){
				cout << out[i+j] << " ";
			}
			cout << "\n";
		}
	}
	else{
		cout << "Action:\n"<< -1 <<"\nFinal:\n";
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++) cout << "-1 ";
			cout << "\n";
		}
	}
}
void input(int n){
	unsigned long long initMap;
	for(int i = 0; i < n; i++){
		initMap = 0;
		for(int j = 0; j <= 15; j++){
            unsigned long long shift = (j<<2);
            unsigned long long tmp = ((unsigned long long)ans[i][j]<<shift);
			initMap += tmp;
		}
        DFS(initMap);
	}
}
int main(void){
	int number;
	cin >> number;
	for(int i = 0 ; i < number; i++){
		for(int j = 0; j <= 15; j++){
			int tmp;
			cin >> tmp;
			if(tmp ==0) ans[i][j] = 0;
            else ans[i][j] = 31 - __builtin_clz(tmp);
		}
	}
	input(number);
    return 0;
}
