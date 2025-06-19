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
	//Registro de datos
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
	//Mayor ventas(numero y nombre)
	float may_venta=-1;
	int mayor=-1;
	for(int i=0;i<n;i++){
			float suma=0;
		for(int j=0;j<12;j++){
			suma=suma+EMPLEADOS[i].ven[j];
		}
		if(suma>may_venta){
			may_venta=suma;
			mayor=i;
		}
	}	
	if (mayor != -1) {
		cout << "Empleado con mayores ventas anuales:\n";
		cout << "Num empleado: " << EMPLEADOS[mayor].num<<endl;
		cout<<"Nombre: " << EMPLEADOS[mayor].nom<<endl;
		cout<< "Total Ventas: " << may_venta << endl;
	}
	return 0;
}