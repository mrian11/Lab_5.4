#include <iostream>
#include <cmath>

using namespace std;

double P0(const int N, const int z)
{
	double P = 1;
	for (int k = N; k <= z; k++)
		P *= (((k * 1.0 - N) / (k * 1.0 + N)) + 1);
	return P;
}

double P1(const int N, const int z, const int k )
{
	if (k > z)
		return 1;
	else
		return (((k * 1.0 - N) / (k * 1.0 + N)) + 1) * P1( N, z, k + 1);
}

double P2(const int N, const int k )
{
	if (k < N)
		return 1;
	else
		return (((k * 1.0 - N) / (k * 1.0 + N)) + 1) * P2(N, k - 1);
}

double P3(const int z, const int N, const int k, double t)
{
	t = t * (((k * 1.0 - N) / (k * 1.0 + N)) + 1);
	if (k >= z)
		return t;
	else
		return P3( z, N, k + 1, t);
}

double P4(const int N, const int k,  double t)
{
	t = t * (((k * 1.0 - N) / (k * 1.0 + N)) + 1);
	if (k <= N)
		return t;
	else
		return P4( N, k - 1, t);
}
int main()
{
	int z = 19;
	int  N;
	cout << "N = "; cin >> N;
	cout << "(iter)        P0 = " << P0(N, z) << endl;
	cout << "(rec up ++)   P1 = " << P1(N, z, N ) << endl;
	cout << "(rec up --)   P2 = " << P2(N, z ) << endl;
	cout << "(rec down ++) P3 = " << P3(z, N, N, 1) << endl;
	cout << "(rec down --) P4 = " << P4(N, z, 1) << endl;
	return 0;
}