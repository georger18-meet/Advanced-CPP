#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 0)
	{
		return;
	}
	TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
	TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
	int N = 0;
	cout << "How many Disks?: ";
	cin >> N;

	// A, B and C are the rod names
	TowerOfHanoi(N, 'A', 'C', 'B');

	return 0;
}