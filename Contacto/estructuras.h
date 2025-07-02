#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
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
#endif
