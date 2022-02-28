//USER: Rudradip Ray
//PROG: USACO Brone Feb 2022 Problem 1
//LANG: C++
#include <bits/stdc++.h>
void setIO(std::string name = "") {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	if((int)(name).size()) {
		std::freopen((name+".in").c_str(), "r", stdin);
		std::freopen((name+".out").c_str(), "w", stdout);
	}
}
int numChanges(std::vector<int> logSleep) {
	std::vector<int> cLog;
	std::unordered_set<int> s(logSleep.begin(), logSleep.end());
    cLog.assign(s.begin(), s.end());
    if (cLog.size() == 1) {
    	return 0; // If all of the digits are the same
    }
    if (logSleep.size()%2==1) {
    	return logSleep.size()-1; 
    }
    if (logSleep.size()%2==0) {
    	return logSleep.size()/2;
    }
	for (int i=0;i<logSleep.size()-1;i++) {
		for (auto j : logSleep) {
			if (logSleep[i]+logSleep[i+1] == j) {
				return 1;
			}
		}
	}
}
int main() {
	setIO();
	int n;
	std::cin >> n;
	for (int i1=0;i1<n;i1++) {
		std::vector<int> sleep;
		int num;
		std::cin >> num;
		for (int i2=0;i2<num;i2++) {
			int h;
			std::cin >> h;
			sleep.push_back(h);
		}
		std::cout << numChanges(sleep) << "\n";
	}
	return 0;
}