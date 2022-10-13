#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Diccionario{
    int codigo;            //declaracion de los datos
    char nombres [50];
    char funcion [50];
    int simbolo;
};
void Crear();
main ( ) {

	Crear();
    system ("pause");
    
}
void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b"); //direccion de guardado de datos
	char res;
	Diccionario diccionario;
	do{
		fflush(stdin);        //codigo de pantalla de los datos a ingresar
		cout<<"ingrese codigo:";
		cin>>diccionario.codigo;
		cin.ignore();
		
        cout<<"Ingrese Nombre:";
        cin.getline(diccionario.nombres , 50);
        
        cout<<"Ingrese Funcion:";
        cin.getline(diccionario.funcion, 50);
        
        cout<<"Ingrese Simbolo:";
        cin>>diccionario.simbolo;
        
    fwrite(&diccionario,sizeof(Diccionario),1,archivo);  //guardar achivo
	cout<<"Desea ingresar otro dato(s/n):"; //ingreso o no de datos
   cin>>res;
}while(res=='s'|| res=='S');

fclose(archivo);
	}
