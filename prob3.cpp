//USER: Rudradip Ray
//PROG: USACO Brone Feb 2022 Problem 3
//LANG: C++
#include <bits/stdc++.h>
void setIO(std::string name = "") {
	std::ios_base::sync_with_stdio(0); std::cin.tie(0);
	if((int)(name).size()) {
		std::freopen((name+".in").c_str(), "r", stdin);
		std::freopen((name+".out").c_str(), "w", stdout);
	}
}
bool sortlen(std::vector<int> v1, std::vector<int> v2) {
    return v1.size() < v2.size();
}
int spell(std::vector<std::string> d, std::string w) {
	std::vector<std::vector<int>> positions = {};
	for (auto i : w) {
		std::vector<int> pos;
		int posIndex = 0;
		for (auto i1 : d) {
			for (auto i2 : i1) {
				if (i == i2) {
					pos.push_back(posIndex+1);
				}
			}
			posIndex++;
		}
		positions.push_back(pos);
	}
	std::vector<std::vector<int>> cPositions;
	for (auto j : positions) {
		std::unordered_set<int> s(j.begin(), j.end());
    	j.assign(s.begin(), s.end());
    	cPositions.push_back(j);
    }
    std::sort(cPositions.begin(), cPositions.end(), sortlen);
    std::map<char, int> characters;
    int index = 0;
    for (auto i :cPositions) {
    	if (i.size() == 0) {
    		return 0;
    	}
    	if (i.size() == 1) {
    		characters.insert(std::pair<char,int>(w[index],i[0]));
    	}
    	if (i.size() > 1) {
    		for (auto const& x : characters) {
    			for (auto j : i) {
    				if (j == x.second) {
    					i.erase(std::find(i.begin(),i.end(),j));
    				}
    			} 
    		}
    		if (i.size() == 0) {
    			return 0;
    		} else {
    			characters.insert(std::pair<char,int>(w[index],i[0]));
    		}
    }
    std::vector<int> occurences;
    for (auto t : characters) {
    	occurences.push_back(t.second);
    }
    std::set<int> s(occurences.begin(), occurences.end());
	return s.size() != occurences.size();
	return 1;
}
int main() {
	setIO();
	int n;
	std::cin >> n;
	std::string d1, d2, d3, d4;
	std::cin >> d1;
	std::cin >> d2;
	std::cin >> d3;
	std::cin >> d4;	
	std::vector<std::string> dice = {d1,d2,d3,d4};
	std::vector<std::string> words = {};
	for (int i=0;i<n;i++) {
		std::string word;
		std::cin >> word;
		words.push_back(word);
	}
	for (auto h : words) {
		if (spell(dice,h)==0) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
	return 0;
}