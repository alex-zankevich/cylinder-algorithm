#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>


int n,m;
int** mtrx;

std::queue<std::pair<int,int>>	que;
std::stack<std::pair<int, int>>	st;

void go_deep(std::pair<int, int> pos){
	st.push(pos);
	mtrx[pos.first][pos.second] = 1;
	if (!mtrx[pos.first][pos.second+1]){
		go_deep(std::pair<int, int>(pos.first,pos.second + 1));
	}
	if (pos.first == m){
		if (!mtrx[1][pos.second]){
			go_deep(std::pair<int, int>(1,pos.second));
		}
	}
	if (!mtrx[pos.first+1][pos.second]){
		go_deep(std::pair<int, int>(pos.first+1, pos.second));
	}
	if (!mtrx[pos.first][pos.second-1]){
		go_deep(std::pair<int, int>(pos.first, pos.second - 1));
	}
	if (!mtrx[pos.first-1][pos.second]){
		go_deep(std::pair<int, int>(pos.first-1, pos.second));
	}
	if (pos.first == 1){
		if (!mtrx[m][pos.second]){
			go_deep(std::pair<int, int>(m, pos.second));
		}
	}
	st.pop();

}

int main(){
	std::ifstream in("in.txt");
	std::ofstream temp("temp.txt");
	std::ofstream out("out.txt");
	in >> m >> n;

	mtrx = new int*[m+2];
	for (int i = 0; i < m+2; i++){
		mtrx[i] = new int[n+2];
	}
	for (int i = 0; i < m+2; i++){
		for (int j = 0; j < n+2; j++){
			mtrx[i][j] = 1;
		}
	}
	for (int i = 1; i < m+1; i++){
		for (int j = 1; j < n+1; j++){
			in >> mtrx[i][j];
		}
	}
	int count = 0;
	for (int i = 1; i < m + 1; i++){
		for (int j = 1; j < n + 1; j++){
			if (!mtrx[i][j]){
				go_deep(std::pair<int, int>(i, j));
				count++;
			}
		}
	}
	out << count;
	return 0;
}