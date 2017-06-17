#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std;

int mensaje=0;
int contador=0;

using std::left;
using std::right;
//arbol para tomar las ordenes------------------------------------------------------------------------------------------------------------------------------
class nodo2 {
	//dESDE OTRA CLASE SE PUEDEN acceder a estos atributos
   public:
    nodo2(int vv, string vv2,float vv3,int vv4,float vv5, nodo2 *sig2, nodo2 *ante2)
    {
       codigo2 = vv;
       producto2 = vv2;
       precio2 = vv3;
       cantidad = vv4;
       pagar = vv5;
       siguiente2 = sig2;
       anterior2=ante2;
    }
    //Desde otra clase/funcion no de puede acceder a los atributos o metodos privados.
   private:
    int codigo2;
    string producto2;
    float precio2;
    int cantidad;
    float pagar;
    nodo2 *siguiente2;
    nodo2 *anterior2;

   //Una funcion externa puede acceder a los atributos privados.
   friend class listaa;
};

nodo2 *crearnodo2(int,string,float,int,float,nodo2 *,nodo2 *);

nodo2 *arbol2 = NULL; //incializa el arbol en NULL

typedef nodo2 *pnodo2;

class listaa {
   public:
   	void insertarnodo2(nodo2 *&,int,string,float,int,float,nodo2 *);
   	void mostrararbol(nodo2 *); //FUNCIOIN PARA RECCORER EL arbol con while   		
   private:
    pnodo2 primero2;
    pnodo2 actual2;
};


//arbol para ingresar el menu-------------------------------------------------------------------------------------------------------------------------
class nodo {
	//dESDE OTRA CLASE SE PUEDEN acceder a estos atributos
   public:
    nodo(int v, string v2,float v3, nodo *sig, nodo *ante)
    {
       codigo = v;
       producto = v2;
       precio = v3;
       siguiente = sig;
       anterior=ante;
    }
    //Desde otra clase/funcion no de puede acceder a los atributos o metodos privados.
   private:
    int codigo;
    string producto;
    float precio;
    nodo *siguiente;
    nodo *anterior;

   //Una funcion externa puede acceder a los atributos privados.
   friend class lista;
};

//PROTOTIPOS
void menu();
void mostrar();
//menu del cliente
void cliente();
void menucliente();
void bienvenida();
void datoscliente();
void mostrardatoscliente();
char nombre[50]; char direccion[50]; char nit[20];
int comprar,comprarotro,efectivo,cambio,regresar;
float total;

nodo *crearnodo(int,string,float,nodo *,nodo *);

nodo *arbol = NULL; //incializa el arbol en NULL

typedef nodo *pnodo;

class lista {
   public:
   	void insertarnodo(nodo *&,int,string,float,nodo *);
   	void mostrararbol2(nodo *); //FUNCIOIN PARA RECCORER EL arbol con while
   	int buscar(int , nodo *);
   private:
    pnodo primero;
    pnodo actual;
};


int main() {
	menu();
   system("pause");
   return 0;
}

int valor_buscado=0;

void menu(){
	int opcion=0,val=0,contador=0;
	string val2; int val3;
	do {
		system("cls");
		cout<<"\t\t\t******************** MARIO'S PIZZA ********************"<<endl;
		cout<<"1. INGRESAR PRODUCTOS"<<endl;
		cout<<"2. VER MENU"<<endl;
		cout<<"3. SISTEMA-CLIENTE"<<endl;
		cout<<"4. SALIR"<<endl<<endl;
		cout<<"OPCION: ";
		cin>>opcion;
			switch(opcion){
				case 1:
					int registrarotro;
					do
					{					
						system("cls");
						cout<<"--------INGESANDO PRODUCTO--------"<<endl;
						lista Lista5;
						Lista5.mostrararbol2(arbol);
						cout<<endl;
						contador++;
						val=contador;
						cout<<"Cod. # "<<contador<<endl;
						cout<<"Ingrese Producto: ";
						cin>>val2;						
						cout<<"Ingrese Precio: ";
						cin>>val3;
						lista Lista;
						Lista.insertarnodo(arbol,val,val2,val3,NULL);						
						//system("pause");
						cout<<"Ingresar Otro Producto 1)SI 2)NO: "; cin>>registrarotro;
					}while(registrarotro==1);
						break;
				case 2: 
						system("cls");
						cout<<"--------MENU MARIO'S PIZZA'--------"<<endl;
						lista Lista4;
						Lista4.mostrararbol2(arbol);
						cout<<endl;
						system("pause");
						break;
											
				case 3: 
						system("cls");						
						cliente();
						system("pause");
			}	
	}while(opcion != 4);
}

//funcion para crear nodos nuevos
nodo *crearnodo(int n,string n2,float n3,nodo *anterior){
     nodo *nuevo_nodo= new nodo(n,n2,n3,NULL,anterior);
     return nuevo_nodo;
}

//funcion para insertar nodos en el arbol
void lista::insertarnodo(nodo *&arbol, int n,string n2,float n3, nodo *anterior){
     if(arbol==NULL)
     {
            nodo *nuevo_nodo=crearnodo(n,n2,n3,anterior);
            arbol=nuevo_nodo;
     }else //si el arbol tiene uno o mas nodos
     {
  			insertarnodo(arbol->siguiente,n,n2,n3,arbol);
         	//arbol->anterior=arbol->siguiente;
     }
}

//funcon para mostrar el arbol USANDO ITERACIONES
void lista::mostrararbol2(nodo *arbol){
     if(arbol== NULL)
     {
        return ; //SI no encuentra nodos retorno sin hacer nada
     }
     else
     {
     	//contador difine cuantos espacios dejar del margen
     	//nodo *arbol2;
	 cout<<left<<setw(8)<<"Cod."<<setw(27)<<"Producto"<<"Precio"<<endl;
     while(arbol!= NULL){
     		//cout<<"codigo de nodo: "<<arbol<<" , valor de nodo: "<<arbol->codigo<<" "<<arbol->producto<<" , nodo siguiente: "<<arbol->siguiente<<endl;     							
			cout<<left<<setw(8)<<arbol->codigo<<setw(27)<<arbol->producto<<arbol->precio<<endl;						
			arbol=arbol->siguiente;																
		 }
}
}

//funcion para buscar un nodo por su valor dentro del arbol
string val22; int val33,val44,val2; float val55;
int lista::buscar(int v, nodo *arbol){
	//verificamos qu el arbol no este vacio
	if(arbol == NULL){
			return 0;
	}else{ //si no esta vacio
		if(arbol->codigo == v)
		{
			cout<<"Codigo: "<<arbol->codigo<<"  Producto: "<<arbol->producto<<"  Precio:"<<arbol->precio<<endl;
		
			//aqui guardamos los valores al nuevo arbol donde se almacenan en la factura a generar	
			val2=arbol->codigo;
			val22=arbol->producto;
			val33=arbol->precio;
			cout<<"Cantidad: "; cin>>val44;
			val55= val44*val33;

			mensaje=1;
			total=total+val55;
			return 0;
		}else{
				buscar(v,arbol->siguiente);				
		}			
	}
}
//cliente------------------------------------------------------------------------------------------------------------------------------------------------
//funcion para crear nodos nuevos
nodo2 *crearnodo2(int nn,string nn2,float nn3,int nn4,float nn5, nodo2 *anterior2){
     nodo2 *nuevo_nodo2= new nodo2(nn,nn2,nn3,nn4,nn5,NULL,anterior2);
     return nuevo_nodo2;
}

//funcion para insertar nodos en el arbol
void listaa::insertarnodo2(nodo2 *&arbol2, int nn,string nn2,float nn3,int nn4, float nn5, nodo2 *anterior2){
     if(arbol2==NULL)
     {
        nodo2 *nuevo_nodo2=crearnodo2(nn,nn2,nn3,nn4,nn5,anterior2);
        arbol2=nuevo_nodo2;
     }else //si el arbol tiene uno o mas nodos
     {
  		insertarnodo2(arbol2->siguiente2,nn,nn2,nn3,nn4,nn5,arbol2);
        //arbol->anterior=arbol->siguiente;
     }
}

//funcon para mostrar el arbol con while, es el arbol con todas las ordenes realizadas
void listaa::mostrararbol(nodo2 *arbol2){
     if(arbol2== NULL)
     {
                return ; //SI no encuentra nodos retorno sin hacer nada
     }
     else
     {
     	//contador difine cuantos espacios dejar del margen
     	//nodo *arbol2;
	cout<<left<<setw(8)<<"Cod."<<setw(27)<<"Producto"<<setw(10)<<"Precio"<<setw(10)<<"Cantidad"<<"Pagar"<<endl;
    while(arbol2!= NULL)
	{
    //cout<<"codigo de nodo: "<<arbol<<" , valor de nodo: "<<arbol->codigo<<" "<<arbol->producto<<" , nodo siguiente: "<<arbol->siguiente<<endl;     							
	cout<<left<<setw(8)<<arbol2->codigo2<<setw(27)<<arbol2->producto2<<setw(10)<<arbol2->precio2<<setw(10)<<arbol2->cantidad<<arbol2->pagar<<endl;						
	arbol2=arbol2->siguiente2;																
	}
}
}

///funcion cliente **************************************************************************
void cliente()
{
do
{	
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPresione 1 y Enter Para Continuar"<<endl; 
	cout<<"\t\t\t\t\t\t\t\t\t"; cin>>regresar;	
	if(regresar==1)
	{	
		bienvenida();
		datoscliente();
		menucliente();
		mostrardatoscliente();		
		listaa Listaa1;
		Listaa1.mostrararbol(arbol2);
		cout<<"Total:    "<<total<<endl;
		cout<<"Efectivo: "; cin>>efectivo;
		cambio=efectivo-total;
		cout<<"       ----------"<<endl;
		cout<<"Cambio:   "<<cambio<<endl;		
		cout<<"       ----------"<<endl;
		cout<<"\tVuelva Pronto"<<endl<<endl;        
		arbol2 = NULL;//eliminamos el arbol completo para que otro cliente pueda pedir su orden
		system("pause");
		regresar=1;
	}
	else
	{
		regresar=2;
	}
	
}while(regresar==1);
}

void bienvenida()
{
	//cout<<"\t\t\t******************** MARIO'S PIZZA ********************"<<endl;
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tBIENVENIDOS A"<<endl<<endl;
	//cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t  MARIO'S'"<<endl<<endl;
	cout<<"*******                ********        **************     *****************         *********************      **************       ***  *********************"<<endl;
	cout<<"********              *********      *****************    *******************       *********************     ****************      ***  *********************"<<endl;
	cout<<"*********            **********     *******    *******    *********************     *********************    ******************     ***  *********************"<<endl;
	cout<<"**********          ***********    *******      *******   **********************           *******          ********************    ***  *********************       "<<endl;
	cout<<"***********        ************   *******        *******  *******         *******          *******         *******        *******   ***  *********       "<<endl;
	cout<<"************     **************  *******         *******  *******         *******          *******        *******          *******  ***  *********     "<<endl;
	cout<<"*************   ***************  *******         *******  *******         *******          *******        *******          *******       *********    "<<endl;
	cout<<"****** **************** *******  *******         *******  *******        ********          *******        *******          *******       *********"<<endl;
	cout<<"******  **************  *******  ***********************  ***********************          *******        *******          *******       *********************"<<endl;
	cout<<"******   ************   *******  ***********************  ***********************          *******        *******          *******       *********************"<<endl;
	cout<<"******    **********    *******  ***********************  **********************           *******        *******          *******       *********************"<<endl;
	cout<<"******     *******      *******  *******         *******  *******  *******                 *******        *******          *******       *********************"<<endl;
	cout<<"******      *****       *******  *******         *******  *******   *******                *******        *******          *******                   *********"<<endl;
	cout<<"******       ***        *******  *******         *******  *******    *******               *******        *******          *******                   *********"<<endl;
	cout<<"******        *         *******  *******         *******  *******     *******              *******        *******          *******                   *********"<<endl;
	cout<<"******                  *******  *******         *******  *******      *******             *******         *******        *******                    *********"<<endl;
	cout<<"******                  *******  *******         *******  *******       *******            *******          ********************         *********************"<<endl;
	cout<<"******                  *******  *******         *******  *******        *******    *********************    ******************          *********************"<<endl;
	cout<<"******                  *******  *******         *******  *******         *******   *********************     ****************           *********************"<<endl;
	cout<<"******                  *******  *******         *******  *******          *******  *********************      **************            *********************"<<endl;	
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\tPIZZA"<<endl;
	cout<<"\t\t\t\t\t\t\t\tES UN GUSTO PODER ATENDERLE"<<endl;
	system("pause");
}

void datoscliente()
{
	system("cls");
	cout<<"\t\t\t******************** MARIO'S PIZZA ********************"<<endl;
	cout<<"-------------------------- FACTURA----------------------------"<<endl;
	fflush(stdin);//sirve para limpiar el buffer
	cout<<"Nombre:    "; gets(nombre);
	cout<<"Nit:       "; gets(nit);
	cout<<"Direccion: "; gets(direccion);
}

void mostrardatoscliente()
{
	system("cls");
	cout<<"************************ MARIO'S PIZZA ***********************"<<endl;
	cout<<"-------------------------- FACTURA----------------------------"<<endl;
	cout<<"Nombre:    "<<nombre<<"     Nit:       "<<nit<<endl;
	cout<<"Direccion: "<<direccion<<endl;
	cout<<"--------------------------------------------------------------"<<endl<<endl;
}


void menucliente()
{
	total=0;
	do
	{		
		system("cls");
		cout<<"\t\t\t******************** MENU MARIO'S PIZZA ********************"<<endl<<endl;
		lista Lista5;
		Lista5.mostrararbol2(arbol);		
		cout<<endl;
		
		//mostramos los productos ordenados para realizar factura
		cout<<"-------------------------- FACTURA----------------------------"<<endl;
		listaa Listaa1;
		Listaa1.mostrararbol(arbol2);
		cout<<"Total: "<<total<<endl;
		cout<<endl;

		cout<<"¿Que Desea Ordenar?"<<endl;
		cout<<"Cod: "; cin>>comprar;
		
		//buscamos el producto que deseamos ordenar
		mensaje=0;
		lista Lista3;
		Lista3.buscar(comprar,arbol);
		if(mensaje != 1)
		{
			cout<<endl<<"========================= PRODUCTO NO ENCONTRADO ==========================="<<endl;	
		}												
		else
		{		
		//guardamos las ordenes compradas en el arbol						
		listaa Listaa;
		Listaa.insertarnodo2(arbol2,val2,val22,val33,val44,val55,NULL);						
		}
		
	Listaa1.mostrararbol(arbol2);
	cout<<"Total: "<<total<<endl;
	cout<<"1)Ordenar Otro 2)Generar Factura: "; cin>>comprarotro;
	}while(comprarotro==1);
}

