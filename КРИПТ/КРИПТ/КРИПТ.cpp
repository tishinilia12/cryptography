// ?????.cpp: ?????????? ????? ????? ??? ??????????? ??????????.
//

#include <iostream> 
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <stack>
#include <fstream>
#include <bitset>
#include <sstream> 
#include <unordered_map>
#include <ctime>

using namespace std;

long long  stdgcd(long long a, long long b) {
	a = abs(a);
	b = abs(b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}


long long gcd(long long a, long long b, long long & x, long long & y) {
	x = 0;
	long long lastx = 1;
	y = 1;
	long long lasty = 0;
	while (b) {
		long long c = b;
		long long quotient = a / b;
		b=a%b;
		a = c;
		c = x;
		x = lastx - quotient * x;
		lastx = c;
		c = y;
		y = lasty - quotient * y;
		lasty = c;
	}
	x = lastx;
	y = lasty;
	return a;
}
long long MYCHEK(long long a, long long b) {
	long long ch, x = 1, y = 1;
	ch = gcd(a, b, x, y);
	if (ch != 1) {
		cout << 404 << endl;
		exit(404);
	}
	return  x % b;
}


int main()
{
	time_t  MyTIME = time(NULL);
	long long q1 = 0, q2 = 0;
	long long x1 = 14;
	long long	y1 = 101358533;
	long long P[2] = { x1, y1 };
	long long	a = 797;
	long long	b = 173;
	long long	n = 103240021;
	long long	Pn[2];
	Pn[0] = P[0];
	Pn[1] = P[1];
	long long	k = 1;
	long long	zzz1 = 3 * Pn[0] * Pn[0] + a, zzz2 = 2 * Pn[1];
	q1 = stdgcd(zzz1, zzz2);
	zzz1 /= q1, zzz2 /= q1;
	long long m = ((zzz1*(zzz2/abs(zzz2)) % n) * (MYCHEK(abs(zzz2), n))%n)%n;
	while (1) {
		long long x =(n*n+m*m - Pn[0] - P[0]) % n;
		long long y = (n*n + m * (Pn[0] - x) - Pn[1]) % n;
		Pn[0] = x;
		k++;
		cout << "x=" << x << " y=" << y << endl;
		if (k % 51617236 == 0) {
			q1 = 1;
		}
		Pn[1] = y;
		if (P[0] - Pn[0] != 0){
			if (P[1] - Pn[1] != 0) {
				zzz1 = P[1] - Pn[1], zzz2 = P[0] - Pn[0];
				q1 = stdgcd(zzz1, zzz2);
				zzz1 /= q1, zzz2 /= q1;
				m = ((zzz1*(zzz2 / abs(zzz2)) % n) * (MYCHEK(abs(zzz2), n)) % n) % n;
			}
		}
		else {
			cout << "k = " << k + 1 << endl;
			break;
		}
	}

	cout << time(NULL) - MyTIME;
	return 0;
}

