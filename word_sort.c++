#include <iostream>
#include <list>
#define size 5000

using namespace std;

int arr[size];
int pre[size];
int nxt[size];
int ans[size];
int unused = 1;

void insert(int addr, int num) {
	arr[unused] = num;
	if (nxt[addr] != -1) {
		pre[nxt[addr]] = unused;
		if (pre[addr] == -1) {
			pre[unused] = addr;
		}
	}
	else {
		if ()
		nxt[unused] = 1;
		pre[1] = unused;
	}
	nxt[addr] = unused;
	unused++;
}
void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
}

int jump(int j, int cur) {
	if (j != 1) {
		cout << arr[cur] << '\n';
		return jump(j - 1, nxt[cur]);
	}
	else { 
		cout << arr[cur] << '\n';
		return nxt[cur];
	}
}

void traversal(int j) {
	int cur = 0;
	int i = 0;
	while (cur != nxt[cur]) {
		erase(cur);
		cur = nxt[cur];
		cur = jump(j-1, cur); 
		if (arr[cur] != 0) {
			cout << arr[cur] << 'a' << '\n';
			ans[i] = arr[cur];
		}
		i++;

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

	cout << '<';
	for (int i = 0; i < n-1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n - 1] << '>';
}