#include <iostream>
#include <list>
#define size 5000

using namespace std;

int arr[size];
int pre[size];
int nxt[size];
int unused = 1;

void insert(int addr, int num) {
	arr[unused] = num;
	pre[unused] = addr;
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	else nxt[unused] = pre[0];
	nxt[addr] = unused;
	unused++;
}
void erase(int addr) {
	if (nxt[addr] != addr) {
		nxt[pre[addr]] = nxt[addr];
		if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
	}
	else {
		nxt[addr] = -1;
		pre[addr] = -1;
	}
}

int jump(int j, int cur) {
	if (j != 1) {
		return jump(j - 1, nxt[cur]);
	}
	else {
		return nxt[cur];
	}
}

void traversal(int j) {
	int cur = nxt[j - 1];
	while (cur != -1) {
		cout << arr[cur];
		erase(cur);
		cur = jump(j, cur);
	}
}

int main() {
	fill(pre, pre + size, -1);
	fill(nxt, nxt + size, -1);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		insert(i, i + 1);
	}
	traversal(k);
}