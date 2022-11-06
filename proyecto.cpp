#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const char *nombre_archivo = "archivo.txt";
struct Diccionario{
    char palabra[500];            //declaracion de los datos
    char traduccion [500];
    char funcion [500];

};
struct Traductor{
	char traductor[500];
};
void Crear();
void Leer();
void Actualizar();
void Borrar();
void Buscar();
void Traducir();
main ( ) {
	int op;
	cout<<"-------------------------------- Bienvenido --------------------------------\n";
	cout<<"Por favor, ingrese el numeral de la opcion que desea ejecutar :)\n";
	cout<<"1. Ingresar datos\n";
	cout<<"2. Visualizar datos\n";
	cout<<"3. Actualizar datos\n";
	cout<<"4. Borrar datos\n";
	cout<<"5. Buscar datos\n";
	cout<<"6. Traducir codigo\n";
	cout<<"Ingrese la opcion deseada: ";
	cin>>op;
	switch(op){
		case 1: Crear(); break;
		case 2: Leer();  break;
		case 3: Actualizar(); break;
		case 4: Borrar(); break;
		case 5: Buscar(); break;
		case 6: Traducir(); break;
	}
	
	
	
	
	
    system ("pause");
}

void Crear(){
	system ("cls");
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
		cout<<"ID = "<<id<<endl;
		cout<<"Palabra = "<<diccionario.palabra<<endl;
		cout<<"Traduccion = "<<diccionario.traduccion<<endl;
		cout<<"Funcion = "<< diccionario.funcion<<endl;
		fread(&diccionario,sizeof(Diccionario),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void Actualizar(){
	system ("cls");
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	Diccionario diccionario;
	int id=0;				//posicion de la palabra a cambiar
	cout<<"Ingrese el ID de la palabra que desea Modificar:";  //posicion donde ira la nueva palabra
	cin>>id;
	fseek(archivo,id * sizeof(Diccionario),SEEK_SET);

	cout<<"Ingrese la palabra que desea cambiar:";   //palabra a sustituir
	cin>>diccionario.palabra,500;        
	cin.ignore();
		
	cout<<"Ingrese la traduccion:";            //nueva traduccion
	cin.getline(diccionario.traduccion,500);
		
	cout<<"Ingrese la funcion:";           //para darle el nuevo concepto
	cin.getline(diccionario.funcion,500);

	fwrite(&diccionario,sizeof(Diccionario),1,archivo);    
	fclose(archivo);
	Leer();
}
void Borrar(){
	system ("cls");

	const char *nombre_archivo_temp = "temp.txt";
	FILE* archivo = fopen(nombre_archivo,"a+b");
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	Diccionario diccionario;
	int id=0, id_n=0; 
	cout<<"Ingrese el id a eliminar: ";
	cin>>id;
	while(fread(&diccionario,sizeof(Diccionario),1,archivo)){
		if(id_n !=id){
			fwrite(&diccionario,sizeof(Diccionario),1,archivo_temp);
		}
		
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	                      // se invierte
	archivo = fopen(nombre_archivo,"w+b"); 
	archivo_temp = fopen(nombre_archivo_temp,"a+b");
	
	while(fread(&diccionario,sizeof(Diccionario),1,archivo_temp)){
		fwrite(&diccionario,sizeof(Diccionario),1,archivo);
	}
	fclose(archivo);
	fclose(archivo_temp);
	Leer();
}
void Buscar(){

	system ("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Diccionario diccionario;
	int id=0;
	fread(&diccionario,sizeof(Diccionario),1,archivo);
	
	cout<<"Ingrese el ID de la palabra que desea buscar."<<endl;
	cin>>id;
	
	if(id==id){
		cout<<"ID = "<<id<<endl;
		cout<<"Palabra = "<<diccionario.palabra<<endl;
		cout<<"Traduccion = "<<diccionario.traduccion<<endl;
		cout<<"Funcion = "<< diccionario.funcion<<endl;
		fread(&diccionario,sizeof(Diccionario),1,archivo);
	}
	else{
		cout<<"El ID que ingreso es incorrecto"<<endl;
	}
    (feof(archivo)==0);
	fclose(archivo); 
}
void Traducir(){
	cin.ignore();
	system("cls");
	//const char *temporal_alamacen = "alamacenDedatos.txt";
	FILE* archivo = fopen(nombre_archivo, "rb");
	//FILE* temporal_archivo = fopen(temporal_alamacen, "w+b");
	
	char posicion = ' ';
	string palabra2 = "";
	string cadenaCaracteres = "";
	string almacenPalabra, almacenNotraductor;
	cout<<"Ingrese su codigo a traducir :)\n";
	getline(cin, cadenaCaracteres, '$');
	
	//separar por caracteres las palabras
	stringstream input_stringstream(cadenaCaracteres);
	while(getline(input_stringstream, palabra2, posicion)){
		//cout << "Un valor: " << palabra2 << endl;
		 Diccionario diccionario;
		 fread(&diccionario, sizeof(Diccionario),1,archivo);
		 do{
		 	if(diccionario.palabra == palabra2){
		 		cout<<"su traduccion es: "<<diccionario.traduccion<<endl;
			 }
			 fread(&diccionario, sizeof(Diccionario),1,archivo);
		 }while(feof(archivo)==0);
		 
	}
	
	fclose(archivo);
}










