//1. librerias
#include<iostream>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<stdio.h>

using namespace std;

//2. Zona para estructuras,constantes y variables globales
struct Sesion{
	string num_Sesion;
	string pelicula;
	string hora;
	string protagonista;
	string calificacion;
	
	Sesion *sgt;
	Sesion *ant;
};

struct Dia{
	string DiasSemana;
	Sesion *pcab_Sesion=NULL;
	Sesion *pfin_Sesion=NULL;
	Dia *sgt;
	Dia *ant;
};
struct Sala{
	string num_sala;
	Dia *pcab_Dia=NULL;
	Dia *pfin_Dia=NULL;
	Sala *sgt;
	Sala *ant;
};


struct Cine{
	string nombre;
	Sala *pcab_Sala=NULL;
	Sala *pfin_Sala=NULL;
	Cine *sgt;
	Cine *ant;
};


//3. zona para definir funciones

int menu();
void operaciones(int op,Cine *&pcab_Cine, Cine *&pfin_Cine);
void fun_registarCine(Cine *&pcab_Cine,Cine *&pfin_Cine);
Cine *fun_BuscarCine(string codigo,Cine *pcab);
void fun_registrarSala(Sala *&pcab_Sala,Sala *&pfin_Sala);
void fun_registarSesion(Sesion *&pcab_Sesion,Sesion *&pfin_Sesion);
Sesion *fun_BuscarSesion(string numSesion,Sesion *pcab_Sesion);
void presentarDatosCine(Cine *dirCine);

Sala *fun_BuscarSala(string numeroSala,Sala *pcab_Sala);
Dia *fun_registrarDia(string diaS, Dia *&pcab_Dia,Dia *&pfin_Dia);
Dia *fun_BuscarDia(string diaSemana,Dia *pcab_Dia);
void fun_listar(Sesion *pcab_Sesion);
Sesion *fun_BuscarPelicula(string nombrePelicula,Sesion *pcab_Sesion);
void fun_listarEmpresas(Cine *pcab_Cine);
void listarSala(Sala *pcab_Sala);
void listarDia(Dia *pcab_Dia);
void listarSesion(Sesion *pcab_Sesion);
void mostrarPelicula(string nombrePelicula, Cine*pcab_Cine);
void modificarPeliculaEnSala(string nombrePelicula, string numSala,Cine*pcab_Cine);
void listarPorEdades(string Clasf_edades, Cine*pcab_Cine);
//void fun_listarCine(Cine *pcab_Cine);


//4. zona para la función principal
int main(){
	setlocale(LC_CTYPE,"Spanish");
	//nuestro código
	
	Cine *pcab_Cine=NULL;
	Cine *pfin_Cine=NULL;	
	
	
	int op;
	
	do{
	system("cls");
	op=menu();
	operaciones(op,pcab_Cine,pfin_Cine);
	cout<<"Desea realizar otra operación: SI(1) ";
	cin>>op;
}while(op==1);
  getch();	//realizar una pausa
return 0;
}

//5. zona para implementar las fonciones

int menu(){
	int op;
	do{
		system("cls");
		cout<<"-------------------MENU--------------------"<<endl;
		cout<<"1) REGISTRAR CINES"<<endl;
		cout<<"2) REGISTAR SALAS"<<endl;
		cout<<"3) REGISTAR SESIONES"<<endl;
		cout<<"4) REGISTAR PELÍCULA"<<endl;
		cout<<"5) VISUALIZAR INFORMACION EN UNA SALA CONCRETA"<<endl;
		cout<<"6) BUSCAR PELICULA"<<endl;
		cout<<"7) MODIFICAR UNA PELICULA DE UNA SALA CONCRETA"<<endl;
		cout<<"8) LISTAR PELÍCULA POR EDADES"<<endl;
		cout<<"9) LISTAR CARTERA DE TODAS LAS EMPRESAS ASOCIADAS"<<endl;
		cout<<"10) SALIR DEL PROGRAMA"<<endl;		
		cout<<"Elija una opcion: "; cin>>op;	
	}while(op<1 or op>10);
	return op;
}

void operaciones(int op,Cine *&pcab_Cine, Cine *&pfin_Cine){
	Cine *dirCine;
	Sala *dirSala;
	string nombreCine;
	string numSala;
	string diaS;
	Dia *dirDia;
	Sesion *dirSesion;
	string numSesion;
	string nombrePelicula;
	string Clasf_edades;
	int dato;
	switch(op){
		case 1:
		
			 system("cls");
			fun_registarCine(pcab_Cine,pfin_Cine);
			 break;
		case 2:
			system("cls");
				cout<<"Ingrese el nombre del cine: ";
				cin>>nombreCine;
				system("cls");
				dirCine=fun_BuscarCine(nombreCine,pcab_Cine);
				if(dirCine==NULL){
					cout<<"El cine no existe"<<endl;
				
			}else{
				presentarDatosCine(dirCine);
			fun_registrarSala(dirCine->pcab_Sala,dirCine->pfin_Sala);
			}	  		
 	

		     break;	 
		case 3:
			system("cls");
			
				cout<<"Ingrese el nombre del cine: ";
				cin>>nombreCine;
				system("cls");
				dirCine=fun_BuscarCine(nombreCine,pcab_Cine);
				if(dirCine==NULL){
					cout<<"El cine no existe"<<endl;
				
			}else{
				presentarDatosCine(dirCine);
				cout<<"Ingrese el numero de la Sala: ";
				cin>>numSala;
				
				dirSala=fun_BuscarSala(numSala,dirCine->pcab_Sala);
				if(dirSala==NULL){
					cout<<"La sala No existe"<<endl;
				}else{
				cout<<"Sala "<<numSala<<endl;
				cout<<"Ingrese el dia: ";
				cin>>diaS;
				fun_registrarDia(diaS, dirSala->pcab_Dia,dirSala->pfin_Dia);
				
				//system("cls");
				dirDia=fun_BuscarDia(diaS,dirSala->pcab_Dia);
				if(dirDia==NULL){
					
				
			}else{
				
			fun_registarSesion(dirDia->pcab_Sesion,dirDia->pfin_Sesion);
			}	  		
 	
				
				}	  			  
			
			}
			break;
		case 4:
		system("cls");
			
				cout<<"Ingrese el nombre del cine: ";
				cin>>nombreCine;
				system("cls");
				dirCine=fun_BuscarCine(nombreCine,pcab_Cine);
				if(dirCine==NULL){
					cout<<"El cine no existe"<<endl;
				
			}else{
				presentarDatosCine(dirCine);
				cout<<"Ingrese el numero de la Sala: ";
				cin>>numSala;
				
				dirSala=fun_BuscarSala(numSala,dirCine->pcab_Sala);
				if(dirSala==NULL){
					cout<<"La sala No existe"<<endl;
				}else{
				cout<<"Sala "<<numSala<<endl;
				cout<<"Ingrese el dia: ";
				cin>>diaS;
				
				//system("cls");
				dirDia=fun_BuscarDia(diaS,dirSala->pcab_Dia);
				if(dirDia==NULL){
					cout<<"EL día no existe"<<endl;
				}else{
				cout<<"Ingrese el número de Sesion: ";
				cin>>numSesion;
				dirSesion =fun_BuscarSesion(numSesion,dirDia->pcab_Sesion);
				if(dirSesion==NULL){
					cout<<"La sesion no existe"<<endl;
				}else{
				cout<<"------Ingrese Nuevos Datos de la Pelicula------"<<endl;
				fflush(stdin);
				cout<<"Nombre: ";
				getline(cin,dirSesion->pelicula);
				fflush(stdin);
				cout<<"Hora: "; 
				getline(cin,dirSesion->hora);
				fflush(stdin);
				cout<<"Protagonista: "; 
				getline(cin,dirSesion->protagonista);
				fflush(stdin);
				cout<<"Calificación: "; 
				getline(cin,dirSesion->calificacion);
			}
			
			}
			}	  		
	 }
			break;
		case 5:
				system("cls");
			
				cout<<"Ingrese el nombre del cine: ";
				cin>>nombreCine;
				system("cls");
				dirCine=fun_BuscarCine(nombreCine,pcab_Cine);
				if(dirCine==NULL){
					cout<<"El cine no existe"<<endl;
				
			}else{
				presentarDatosCine(dirCine);
				cout<<"Ingrese el numero de la Sala: ";
				cin>>numSala;
				
				dirSala=fun_BuscarSala(numSala,dirCine->pcab_Sala);
				if(dirSala==NULL){
					cout<<"La sala No existe"<<endl;
				}else{
				cout<<"Sala "<<numSala<<endl;
				cout<<"Ingrese el dia: ";
				cin>>diaS;
				
				//system("cls");
				dirDia=fun_BuscarDia(diaS,dirSala->pcab_Dia);
				if(dirDia==NULL){
					cout<<"EL día no existe"<<endl;
				}else{
				cout<<"Ingrese el número de Sesion: ";
				cin>>numSesion;
				dirSesion=fun_BuscarSesion(numSesion,dirDia->pcab_Sesion);
				if(dirSesion==NULL){
					cout<<"La sesion no existe"<<endl;
				}else{
				 fun_listar(dirDia->pcab_Sesion);
			}
			
			}
			}	  		
	 }
		
			break;
		case 6:
			system("cls");
			fflush(stdin);
			cout<<"Ingrese el nombre de la Pelicula: ";
			getline(cin,nombrePelicula);
			mostrarPelicula(nombrePelicula, pcab_Cine);
			
			break;
		case 7:
			system("cls");
			fflush(stdin);
			cout<<"Ingrese el nombre de la Pelicula: ";
			getline(cin,nombrePelicula);
			cout<<"Ingrese el numero de la Sala: ";
			getline(cin,numSala);
			modificarPeliculaEnSala(nombrePelicula,numSala,pcab_Cine);
			break;
		case 8:
			system("cls");
			fflush(stdin);
			cout<<"Ingrese la clasificación de las peliculas: ";
			getline(cin,Clasf_edades);
			listarPorEdades(Clasf_edades,pcab_Cine);
			break;
		case 9:
			fun_listarEmpresas(pcab_Cine);
			break;
		case 10:
			cout<<"Para salir del Programa Ingrese(1): ";
			cin>>dato;
			if(dato==1){
				exit(0);
			}
			break;

		
	}
	
}

void fun_registarCine(Cine *&pcab_Cine,Cine *&pfin_Cine){
//	insertar un nodo
Cine *nuevoCine;
Cine *dirCine;
string nombreCine;
 if(pcab_Cine==NULL){
 	//crear el primer producto
 	nuevoCine=new(Cine);
 	cout<<"Ingrese el nombre del cine: ";
 	cin>>nuevoCine->nombre;
 	fflush(stdin);


 	nuevoCine->ant=NULL;
 	nuevoCine->sgt=NULL;
 // asignar a la cabecera
	pcab_Cine=nuevoCine;
	pfin_Cine=nuevoCine;
 	
 }else{
 	 	cout<<"Ingrese El Nombre del cine: ";
    	cin>>nombreCine;
    	dirCine=fun_BuscarCine(nombreCine,pcab_Cine);
  		if(dirCine==NULL){
	 	//crear el primer producto
	 	nuevoCine=new(Cine);
	 	
	 	nuevoCine->nombre=nombreCine;
	 	fflush(stdin);


 		nuevoCine->ant=NULL;
 		nuevoCine->sgt=NULL;
 		//asignar los punteros
 		pfin_Cine->sgt=nuevoCine;
 		nuevoCine->ant=pfin_Cine;
 		pfin_Cine=nuevoCine;
    		
		}else{
			cout<<"Ya esta registrado el nombre del cine: "<<nombreCine<<" ya está registrado"<<endl;
		}
 }
	
}
Cine *fun_BuscarCine(string codigo,Cine *pcab){
	Cine *pActual=pcab;
	while(pActual!=NULL){
		if(pActual->nombre == codigo){
			return pActual;
		}
		pActual=pActual->sgt;
	}
	return NULL;
}

void fun_registrarSala(Sala *&pcab_Sala,Sala *&pfin_Sala){
 	string numeroSala;
	Sala *nuevaSala;
	Sala *dirSala;

 if(pcab_Sala==NULL){
 	//crear el primer producto
 	nuevaSala=new(Sala);
 	cout<<"Ingrese el número de la Sala: ";
 	cin>>nuevaSala->num_sala;
 	fflush(stdin);


 	nuevaSala->ant=NULL;
 	nuevaSala->sgt=NULL;
 // asignar a la cabecera
	pcab_Sala=nuevaSala;
	pfin_Sala=nuevaSala;
 	
 }else{
 	 	cout<<"Ingrese el número de la Sala: ";
    	cin>>numeroSala;
    	dirSala=fun_BuscarSala(numeroSala,pcab_Sala);
  		if(dirSala==NULL){
	 	//crear el primer producto
	 	nuevaSala=new(Sala);
	 	
	 	nuevaSala->num_sala=numeroSala;
	 	fflush(stdin);


 		nuevaSala->ant=NULL;
 		nuevaSala->sgt=NULL;
 		//asignar los punteros
 		pfin_Sala->sgt=nuevaSala;
 		nuevaSala->ant=pfin_Sala;
 		pfin_Sala=nuevaSala;
    		
		}else{
			cout<<"El número de la Sala: "<<numeroSala<<" ya está registrado"<<endl;
		}
 }
}
 
 
void fun_registarSesion(Sesion *&pcab_Sesion,Sesion *&pfin_Sesion){
//	insertar un nodo
Sesion *nuevaSesion;
Sesion *dirSesion;
string numSesion;
 if(pcab_Sesion==NULL){
 	//crear el primer producto
 	nuevaSesion=new(Sesion);
 	fflush(stdin);
 	cout<<"Ingrese el número de la Sesión: ";
 	cin>>nuevaSesion->num_Sesion;
 	fflush(stdin);
	cout<<"Ingrese el nombre de la Pelicula: ";
 	getline(cin,nuevaSesion->pelicula);
	cout<<"Ingrese la hora: ";
 	cin>>nuevaSesion->hora;
 	fflush(stdin);
	cout<<"Ingrese el nombre de los protagonistas: ";
 	getline(cin,nuevaSesion->protagonista);
 	fflush(stdin);
 	cout<<"Ingrese la calificación: ";
 	cin>>nuevaSesion->calificacion;
	
	
 	nuevaSesion->ant=NULL;
 	nuevaSesion->sgt=NULL;
 // asignar a la cabecera
	pcab_Sesion=nuevaSesion;
	pfin_Sesion=nuevaSesion;
 	
 }else{
 	 	cout<<"Ingrese el número de la Sesión: ";
    	cin>>numSesion;
    	dirSesion=fun_BuscarSesion(numSesion,pcab_Sesion);
  		if(dirSesion==NULL){
	 	//crear el primer producto
	 	nuevaSesion=new(Sesion);
	 	nuevaSesion->num_Sesion=numSesion;
	 	fflush(stdin);
		cout<<"Ingrese el nombre de la Pelicula: ";
	 	getline(cin,nuevaSesion->pelicula);
		cout<<"Ingrese la hora: ";
	 	cin>>nuevaSesion->hora;
	 	fflush(stdin);
		cout<<"Ingrese el nombre de los protagonistas: ";
	 	getline(cin,nuevaSesion->protagonista);
	 	fflush(stdin);
	 	cout<<"Ingrese la calificación: ";
	 	cin>>nuevaSesion->calificacion;

 		nuevaSesion->ant=NULL;
 		nuevaSesion->sgt=NULL;
 		//asignar los punteros
 		pfin_Sesion->sgt=nuevaSesion;
 		nuevaSesion->ant=pfin_Sesion;
 		pfin_Sesion=nuevaSesion;
    		
		}else{
			
			cout<<"El numero de la Sesion: "<<numSesion<<" ya está registrado"<<endl;
			system("pause");
		}
 }
	
}

Sesion *fun_BuscarSesion(string numSesion,Sesion *pcab_Sesion){
	Sesion *pActual=pcab_Sesion;
	while(pActual!=NULL){
		if(pActual->num_Sesion == numSesion){
			return pActual;
		}
		pActual=pActual->sgt;
	}
	return NULL;
}

void presentarDatosCine(Cine *dirCine){
 	cout<<"NOMBRE: "<<dirCine->nombre<<endl;
 }
 
Sala *fun_BuscarSala(string numeroSala,Sala *pcab_Sala){
	Sala *pActual=pcab_Sala;
	while(pActual!=NULL){
		if(pActual->num_sala == numeroSala){
			return pActual;
		}
		pActual=pActual->sgt;
	}
	return NULL;
}


Dia * fun_registrarDia(string diaS, Dia *&pcab_Dia,Dia *&pfin_Dia){
 	string diaSemana;
	Dia *nuevoDia;
	Dia *dirDia;

 if(pcab_Dia==NULL){
 	//crear el primer producto
 	nuevoDia=new(Dia);
 	nuevoDia->DiasSemana=diaS;
 	fflush(stdin);


 	nuevoDia->ant=NULL;
 	nuevoDia->sgt=NULL;
 // asignar a la cabecera
	pcab_Dia=nuevoDia;
	pfin_Dia=nuevoDia;
 	
 }else{

    	dirDia=fun_BuscarDia(diaS,pcab_Dia);
  		if(dirDia==NULL){
	 	//crear el primer producto
	 	nuevoDia=new(Dia);
	 	
	 	nuevoDia->DiasSemana=diaS;
	 	fflush(stdin);


 		nuevoDia->ant=NULL;
 		nuevoDia->sgt=NULL;
 		//asignar los punteros
 		pfin_Dia->sgt=nuevoDia;
 		nuevoDia->ant=pfin_Dia;
 		pfin_Dia=nuevoDia;
    		
		}else{
			cout<<"El día: "<<diaSemana<<" ya está registrado"<<endl;
		}
 }
 return nuevoDia;
}
Dia *fun_BuscarDia(string diaS,Dia *pcab_Dia){
	Dia *pActual=pcab_Dia;
	while(pActual!=NULL){
		if(pActual->DiasSemana == diaS){
			return pActual;
		}
		pActual=pActual->sgt;
	}
	return NULL;
}


void fun_listar(Sesion *pcab_Sesion){
	Sesion *pActualSesion=pcab_Sesion;
	while(pActualSesion!=NULL){
		//extraer Informacion
		cout<<"Nombre: "<<pActualSesion->pelicula<<endl;
		cout<<"Hora: "<<pActualSesion->hora<<endl;
		cout<<"Protagonista: "<<pActualSesion->protagonista<<endl;
		cout<<"Calificacion "<<pActualSesion->calificacion<<endl;
		cout<<endl;
		//alterar la Condicion
		pActualSesion=pActualSesion->sgt;
	}
}

Sesion *fun_BuscarPelicula(string nombrePelicula,Sesion *pcab_Sesion){
	Sesion *pActual=pcab_Sesion;
	while(pActual!=NULL){
		if(pActual->pelicula == nombrePelicula){
			return pActual;
		}
		pActual=pActual->sgt;
	}
	return NULL;
}


void fun_listarEmpresas(Cine *pcab_Cine){
	Cine *pActualCine=pcab_Cine;
	while(pActualCine!=NULL){
		//extraer Informacion
		cout<<"Nombre Del Cine: "<<pActualCine->nombre<<endl;
		cout<<" "<<endl;
		listarSala(pActualCine->pcab_Sala);
		cout<<endl;
		//alterar la Condicion
		pActualCine=pActualCine->sgt;
	}
}


void listarSala(Sala *pcab_Sala){
	while(pcab_Sala!=NULL){
		cout<<"Número de Sala: "<<pcab_Sala->num_sala<<endl;
		cout<<endl;
		listarDia(pcab_Sala->pcab_Dia);
		cout<<endl;
		pcab_Sala = pcab_Sala->sgt;
	}
}

void listarDia(Dia *pcab_Dia){
	while(pcab_Dia!=NULL){
		cout<<"Día: "<<pcab_Dia->DiasSemana<<endl;
		cout<<endl;
		listarSesion(pcab_Dia->pcab_Sesion);
		cout<<endl;
		pcab_Dia = pcab_Dia->sgt;
	}
}
void listarSesion(Sesion *pcab_Sesion){
	while(pcab_Sesion!=NULL){
		cout<<"Numero Sesion: "<<pcab_Sesion->num_Sesion<<endl;
		cout<<"Pelicula: "<<pcab_Sesion->pelicula<<endl;
		cout<<"Hora: "<<pcab_Sesion->hora<<endl;
		cout<<"Protagonista: "<<pcab_Sesion->protagonista<<endl;
		cout<<"Calificación: "<<pcab_Sesion->calificacion<<endl;
		cout<<endl;
		pcab_Sesion = pcab_Sesion->sgt;
	}
}



void mostrarPelicula(string nombrePelicula, Cine*pcab_Cine){
	Cine *pActual=pcab_Cine;
	Dia *pDia;
	Sala *pSala;
	Sesion *pSesion;

	while(pActual!=NULL){
		pSala = pActual->pcab_Sala;
		while(pSala!=NULL){
			pDia=pSala->pcab_Dia;
			while(pDia!=NULL){
				pSesion=pDia->pcab_Sesion;
				while(pSesion!=NULL){
					if(pSesion->pelicula==nombrePelicula){
						cout<<"Se proyecta en: "<<endl;
						cout<<"El cine: "<<pActual->nombre<<", el día: "<<pDia->DiasSemana<<", En la Sala: "<<pSala->num_sala<<", En la Sesion: "<<pSesion->num_Sesion<<endl;
						cout<<"Hora: "<<pSesion->hora<<endl;
					}
				pSesion= pSesion->sgt;	
				}
			pDia = pDia->sgt;	
			}
		pSala =pSala->sgt;	
		}
		pActual=pActual->sgt;
	}
}


void modificarPeliculaEnSala(string nombrePelicula, string numSala,Cine*pcab_Cine){
	Cine *pActual=pcab_Cine;
	Dia *pDia;
	Sala *pSala;
	Sesion *pSesion;

	while(pActual!=NULL){
		pSala = pActual->pcab_Sala;
		while(pSala!=NULL){
			if(pSala->num_sala==numSala){
				cout<<"La Sala: "<<pSala->num_sala<<endl;
			}
			pDia=pSala->pcab_Dia;
			while(pDia!=NULL){
				pSesion=pDia->pcab_Sesion;
				while(pSesion!=NULL){
					if(pSesion->pelicula==nombrePelicula){
						cout<<"Ingrese el Nombre de la Nueva Pelicula: ";
						getline(cin,pSesion->pelicula);
						cout<<"La pelicula ha sido Registrada"<<endl;
					}
				pSesion= pSesion->sgt;	
				}
			pDia = pDia->sgt;	
			}
		pSala =pSala->sgt;	
		}
		pActual=pActual->sgt;
	}
}


void listarPorEdades(string Clasf_edades, Cine*pcab_Cine){
	Cine *pActual=pcab_Cine;
	Dia *pDia;
	Sala *pSala;
	Sesion *pSesion;

	while(pActual!=NULL){
		pSala = pActual->pcab_Sala;
		while(pSala!=NULL){
			pDia=pSala->pcab_Dia;
			while(pDia!=NULL){
				pSesion=pDia->pcab_Sesion;
				while(pSesion!=NULL){
					if(pSesion->calificacion==Clasf_edades){
						cout<<"Pelicula: "<<pSesion->pelicula<<endl;
						cout<<"Se proyecta en: "<<endl;
						cout<<"El cine: "<<pActual->nombre<<", el día: "<<pDia->DiasSemana<<", En la Sala: "<<pSala->num_sala<<", En la Sesion: "<<pSesion->num_Sesion<<endl;
						cout<<"Hora: "<<pSesion->hora<<endl;
						cout<<"Clasificación: "<<pSesion->calificacion<<endl;
						cout<<endl;
					}
				pSesion= pSesion->sgt;	
				}
			pDia = pDia->sgt;	
			}
		pSala =pSala->sgt;	
		}
		pActual=pActual->sgt;
	}
}


