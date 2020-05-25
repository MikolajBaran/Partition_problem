#include <iostream>

using namespace std;

int n;

int returnSum(int x){
	int s = 0;
	for(int i=1; i<+x; i++){
		s+=i;
	}
	return s;
}

void partition(int* A, int L){
	bool** arr = new bool*[n];
	for(int i=0; i<n; i++){
		arr[i] = new bool[L+1];
//		arr[i][0] = true;
	}
	
	/*for(int j=1; j<=L; j++){
		if(A[0] == j){
			arr[0][j] = true;
		}
		else{
			arr[0][j] = false;
		}
	}*/
	
	cout << "\n\n--------------------------------------------" << endl;
	cout << "Tablica pomocnicza: \n\t";
	
	for(int x=0; x<n; x++){
		for(int y=0; y<=L; y++){
			if(x==0){
				if(y==0 || y==A[0]){
					arr[x][y] = true;
				}
				else{
					arr[x][y] = false;
				}
			}
			else{
				if(arr[x-1][y] == true || (A[x]<=y && arr[x-1][y-A[x]] == true)){
					arr[x][y] = true;
				}
				else{
					arr[x][y] = false;
				}
			}
			cout << arr[x][y] << " ";
		}
		cout << "\n\t";
	}
	cout << "\n\n";
	if(arr[n-1][L]){
		cout << "Podany zbior A mozna podzielic na dwa podzbiory o rownej sumie wartosci rozmiarow tych elementow." << endl;
	}
	else{
		cout << "Nie istnieje taki podzial zbioru A, ze oba podzbiory zawieraja elementy o rownej sumie wartosci rozmiarow." << endl;
	}
	
	for(int i = 0; i < n; ++i) {
    	delete [] arr[i];
	}
	delete [] arr;
}

int main() {
	cout << "Program rozwiazujacy problem PARTITION podzialu zbioru na dwa podzbiory o rownej sumie wartosci elementow." << endl;
	cout << "Podaj liczebnosc zbioru: ";
	cin >> n;
	while(n>10||n<1){
		cout << "Niepoprawne dane. Podaj liczbe z przedzialu 1-10." << endl;
		cout << "Podaj liczebnosc zbioru: ";
		cin >> n;
	}
	
	int* A = new int[n];
	int tempSum = 0;
	for(int i=0; i<n; i++){
		cout << "\nWprowadz rozmiar s(a) elementu a" << i+1 << ": ";
		cin >> A[i];
		while(tempSum+A[i] > 55-returnSum(n-i)){
			cout << "Suma rozmiarow elementow s nie moze przekroczyc 55, co przy wprowadzonych danych jest niemozliwe. Wprowadz inna wartosc." << endl;
			cin >> A[i];
		}
		for(int j=0; j<i; j++){
			if(A[j] == A[i]){
				while(A[j] == A[i]){
					cout << "\nRozmiary kolejnych elementow nie moga sie powtarzac. Element a" << j << " mial juz wartosc " << A[i] << ". Wprowadz inna wartosc." << endl;
					cin >> A[i];
				}
			}
		}
		tempSum+=A[i];
	}
	
	if(tempSum%2 == 1){
		cout << "Suma rozmiarow wszystkich elementow s jest nieparzysta, co oznacza, ze nie istnieje taki podzial zbioru A, ze oba podzbiory zawieraja elementy o rownej sumie wartosci." << endl;
	}
	else{
		partition(A,tempSum/2);
	}
	
	return 0;
}
