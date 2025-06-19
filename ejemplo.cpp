#include<iostream>
#include<string>
using namespace std;

struct EMP {
	int num;
	string nom;
	float ven[12], sal;
};

int main() {
	EMP EMPLEADOS[100];
	int n;

	cout << "Ingrese la cantidad de empleados: ";
	cin >> n;
	cout << "\n========= REGISTRO DE EMPLEADOS =========\n";
	for (int i = 0; i < n; i++) {
		cout << "Empleado #" << i + 1 << "\n";
		cout << "Num empleado: ";
		cin >> EMPLEADOS[i].num;

		cin.ignore();
		cout << "Nombre: ";
		getline(cin, EMPLEADOS[i].nom);

		for (int j = 0; j < 12; j++) {
			cout << "  Venta " << j + 1 << ": ";
			cin >> EMPLEADOS[i].ven[j];
		}

		cout << "Salario: ";
		cin >> EMPLEADOS[i].sal;

		cout << "------------------------------------------\n";
	}

	return 0;
}