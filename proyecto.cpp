#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.txt";
struct Diccionario{
    char palabra[500];            //declaracion de los datos
    char traduccion [500];
    char funcion [500];

};
void Crear();
void Leer();
main ( ) {
	Crear();
	Leer();
    system ("pause");
}

void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b"); //direccion de guardado de datos
	char res;
	Diccionario diccionario;
	do{
		fflush(stdin);        //codigo de pantalla de los datos a ingresar
		cout<<"Ingrese Palabra:";
		cin>>diccionario.palabra;
		cin.ignore();

		
        cout<<"Ingrese Traduccion:";
        cin.getline(diccionario.traduccion ,500);
        
        cout<<"Ingrese Funcion:";
        cin.getline(diccionario.funcion,500);
        
        
        
    fwrite(&diccionario,sizeof(Diccionario),1,archivo);  //guardar achivo
	cout<<"Desea ingresar otro dato(s/n):"; //ingreso o no de datos
   cin>>res;
}while(res=='s'|| res=='S');

fclose(archivo);
Leer();
	}
void Leer (){
	system ("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Diccionario diccionario;
	int id=0; //indice a posicion de resgistro (fila) dentro del archivo
	fread(&diccionario,sizeof(Diccionario),1,archivo);
	cout<<"_________________________________________________"<<endl;
	cout<<" ----------- Contenido del Diccionario ----------"<<endl;
	do{
		cout<<"_____________________________"<<endl;
		cout<<"---------- Palabra ----------"<<endl;
		cout<<"Traduccion ="<<diccionario.traduccion<<endl;
		cout<<"Funcion ="<< diccionario.funcion<<endl;
		fread(&diccionario,sizeof(Diccionario),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
