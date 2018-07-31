#include<bitset>
#include "EncryptionAlg.hpp"
using namespace std;

int main()
{
	string temp = "VukIsic97";
	string ret = Monoalphabetic(temp, 5);
	cout << temp << endl;
	cout << ret << endl;
	cout << endl << endl;

	string temp1 = "AazZ";
	string key1 = "Vukv";
	string ret1 = OneTime(temp1, key1);
	cout << bitset<8>(temp1[0]) << endl;
	cout << bitset<8>(key1[0]) << endl;
	cout << bitset<8>(ret1[0]) << endl;
	cout << ret1 << endl;
	cout << endl << endl;

	string temp2 = "aTTACkATdOWN";
	string key2 = "LEMON";
	string ret2 = Vigenere(temp2, key2);
	cout << temp2 << endl;
	cout << ret2 << endl;
	cout << endl << endl;

	string temp3 = "VuuK";
	string ret3 = Homophone(temp3);
	cout << ret3 << endl;
	cout << endl << endl;

	const int r_s = 3;
	const int c_s = 7;
	int rk[r_s] = { 1,0,2 };
	int ck[c_s] = { 1,0,6,2,4,3,5 };

	string temp4 = "UNIVERZITETUNOVOMSADU";
	string ret4 = Transposition(temp4, rk, ck, r_s, c_s);
	cout << ret4 << endl;

	

	string temp5 = "NOVISAD";
	string ret5 = PlayFair(temp5);
	cout << ret5 << endl;



	system("pause");
	return 0;
}