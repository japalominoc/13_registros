#include<iostream>
#include<string>
using namespace std;

struct correo{
	string user;
	string domain;
};

struct contactoEmail{
	string nom;
	char sex;
	int edad;
	correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
	int n,op;
	string nom, user, domain;
	char sex;
	int edad;
	correo email;
	contactoEmail cont, lista[100];
	n=0;
	do{
		system("cls");
		cout<<"Organizador de contactos :::::::::::::::::::::"<<endl;
		cout<<endl;
		cout<<"1. Agregar un contacto"<<endl;
		cout<<"2. Modificar un contacto"<<endl;
		cout<<"3. Mostrar listado de contactos"<<endl;
		cout<<"4. Eliminar un contacto\n";
		cout<<"0. Salir"<<endl;
		cout<<endl;
		cout<<"Ingresa una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"Agregar contacto :::::::::::::::::::::::: "<<endl;
				cout<<endl;
                cin.ignore();
                cout<<"Ingrese nombres: "; getline(cin,nom);
                cout<<"Ingrese sexo (M/F): "; cin>>sex;
                cout<<"Ingrese edad: "; cin>>edad;
                cout<<"Ingrese correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                cout<<endl;
                cout<<"Ha ingreso la siguiente informacion:"<<endl;
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                imprimeContacto(cont);                 //imprimeContacto(cont);
				cout<<endl;
				char opc;
				cout<<"Esta informacion es correcta? (S/N): "; cin>>opc;
				if(opc=='S'|| opc=='s'){
					lista[n] = cont;
             	    n++;
             	    cout << "\033[32mLa operacion ha sido exitosa\033[0m" << endl;
             	    cout<<endl;
				}
				else{
					cout<<"Contacto descartado. No se guardo"<<endl;
				}
                system("pause");
                break;
            case 2:
				system("cls");
				cout<<"Modificar contacto :::::::::::::::::::::::: "<<endl;
				cout<<endl;
				
            	if(n ==0){
            			cout<<"No hay contacto para modificar"<<endl;
				}
				else{
					cout << "Id\tNombres\t\t\t\tSexo\t\tEdad\tCorreo electronico\n";
					cout << "-----------------------------------------------------------------------------------------------------\n";
					for (int i = 0; i < n; i++) {
						cout << i + 1 << "\t"<< lista[i].nom << "\t";
						if (lista[i].sex == 'M' || lista[i].sex == 'm'){
							cout << "Masculino\t";
						}
						else{
							cout << "Femenino\t";
						}
						cout << lista[i].edad << "\t" << lista[i].email.user << "@" << lista[i].email.domain << endl;
					}
				}
				int mod;
				cout << "\nIngrese el ID del contacto a modificar: ";
				cin >> mod;
				mod--;
				
				if (mod >= 0 && mod < n) {
					cin.ignore();
					char opc;
					string nom, user, domain;
					int edad;
					char sex;
				
					contactoEmail temp = lista[mod];
				
					cout << "Modificar nombres? (S/N): ";
					cin >> opc;
					cin.ignore();
					if (opc == 'S' || opc == 's') {
						cout << "\tIngrese nombres: ";
						getline(cin, nom);
						temp.nom = nom;
					}
					cout << "Modificar sexo? (S/N): ";
					cin >> opc;
					if (opc == 'S' || opc == 's') {
						cout << "\tIngrese sexo (M/F): ";
						cin >> sex;
						temp.sex = sex;
					}
					cout << "Modificar edad? (S/N): ";
					cin >> opc;
					if (opc == 'S' || opc == 's') {
						cout << "\tIngrese edad: ";
						cin >> edad;
						temp.edad = edad;
					}
					cout << "Modificar correo? (S/N): ";
					cin >> opc;
					if (opc == 'S' || opc == 's') {
						cout << "\tIngrese usuario: ";
						cin >> user;
						cout << "\tIngrese dominio: ";
						cin >> domain;
						leerCorreo(temp.email, user, domain);
					}
					cout << "\nHa ingresado la siguiente informacion:\n";
					imprimeContacto(temp);
					cout << "\n¿Esta informacion es correcta? (S/N): ";
					cin >> opc;
				
					if (opc == 'S' || opc == 's') {
						lista[mod] = temp;
						cout << "\033[32mLa modificacion fue exitosa.\033[0m\n";
					} else {
						cout << "Modificacion descartada. No se aplicaron cambios.\n";
					}
				} else {
					cout << "ID fuera del rango\n";
				}
				system("pause");
	            break;
            case 3:
				system("cls");
				cout<<"Lista de contactos :::::::::::::::::::::::: "<<endl;
				cout<<endl;
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i+1<<"--------------------"<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 4:
			    system("cls");
				cout << "Eliminar contacto ::::::::::::::::::::::::\n\n";
			
				if (n == 0) {
					cout << "No hay contactos para eliminar.\n";
				} else {
					cout << "ID\tNombres\t\t\t\tSexo\tEdad\tCorreo electronico\n";
					cout << "------------------------------------------------------------------------\n";
					for (int i = 0; i < n; i++) {
						cout << i + 1 << "\t" << lista[i].nom << "\t";
						cout << ((lista[i].sex == 'M' || lista[i].sex == 'm') ? "Masculino" : "Femenino") << "\t";
						cout << lista[i].edad << "\t";
						cout << lista[i].email.user << "@" << lista[i].email.domain << endl;
					}
			
					int eli;
					cout << "\nIngrese el ID del contacto que desea eliminar: ";
					cin >> eli;
					eli--;
			
					if (eli >= 0 && eli < n) {
						cout << "\nContacto seleccionado:\n";
						imprimeContacto(lista[eli]);
						char conf;
						cout << "\nEsta seguro que desea eliminar este contacto? (S/N): ";
						cin >> conf;
			
						if (conf == 'S' || conf == 's') {
							for (int i = eli; i < n - 1; i++) {
								lista[i] = lista[i + 1];
							}
							n--; 
							cout << "\033[31mContacto eliminado correctamente.\033[0m\n";
						} else {
							cout << "Eliminacion cancelada.\n";
						}
					} else {
						cout << "ID fuera de rango.\n";
					}
				}
				system("pause");
				break;      	
            case 0:
            	char salir;
                cout << "¿Esta seguro de salir? (S/N): ";
				cin >> salir;
				if (salir == 'S' || salir == 's') {
					cout << "Saliendo del programa..." << endl;
					break;
				} else {
					op = -1;
				}
				break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
		}
	}while(op !=0);
	return 0;
	}		
void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombres: "<<c.nom<<endl;
    cout<<"Sexo:    "<<c.sex<<endl;
    cout<<"Edad:    "<<c.edad<<endl;
    cout<<"Email:   "<<c.email.user<<"@"<<c.email.domain<<endl;
}
