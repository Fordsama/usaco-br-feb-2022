//USER: Rudradip Ray
//PROG: USACO Brone Feb 2022 Problem 2
//LANG: C++
#include <bits/stdc++.h>
void setIO(std::string name = "") {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	if((int)(name).size()) {
		std::freopen((name+".in").c_str(), "r", stdin);
		std::freopen((name+".out").c_str(), "w", stdout);
	}
}
int calculateChanges(std::vector<int> initial, std::vector<int> preffered, int length) {
	int changes = 0;
	while (initial != preffered) {
		for(int j=0;j<length;j++) {
			if (initial[j] != preffered[j]) {
				int index = 0;
				for (auto h : initial) {
					if (h==preffered[j]) {
						int move = initial[index];
						initial.erase(initial.begin() + index);
						auto it = initial.insert(initial.begin() + j, move);
					}
					index++;
				}
				changes++;
			}
		}
	}
	return changes;
}
int main() {
	setIO();
	int n;
	std::cin >> n;
	std::vector<int> iOrder;
	std::vector<int> pOrder;
	for (int i1=0;i1<n;i1++) {
		int h;
		std::cin >> h;
		iOrder.push_back(h);
	}
	for (int i2=0;i2<n;i2++) {
		int h;
		std::cin >> h;
		pOrder.push_back(h);
	}
	std::cout << calculateChanges(iOrder,pOrder,n) << "\n";
	return 0;
}