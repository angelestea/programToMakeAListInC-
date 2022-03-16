#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

using namespace std;
int reprobados, aprobados, supletorio, totalAlumnos, contabilizador=0;;
double porRe, porApro, porSuple;
struct Alumno{
    char nombre[50];
    char direccion[150];
    char semestre[50];
    int edad;
    int materiasAprobadas;
    int alumno;
    string status;
};

struct datos{
    Alumno alu;
    datos *sig;
};
struct datos *c, *primero = NULL, *ultimo = NULL;

struct datos *nuevo_nodo();
void error();
void push(int & var);
void leer();
int colaVacia ();
void mostrarCola ();
void mostrarColaTwo();
void stadistics(int *&, datos *&);

int main (){
    char op;
    int contAlum=0;

    system("cls");
        cout<<"\n\n\t\t\t\t\t     *********************"<<endl;
        cout<<"\t\t\t\t\t     | Opening data base |"<<endl;
        cout<<"\t\t\t\t\t     *********************"<<endl;
        for(int i = 0; i<=100;i++){
        string loading="";
        loading+=".";
        cout<<loading;
        Sleep(15);
    }
    do{
        system("cls");
        cout << "\n\t\t  *********************************" << endl;
        cout << "\t\t  | Sistema de registro de alumnos |" << endl;
        cout << "\t\t  *********************************" << endl;
        cout << "\n\n\t 1. Ingresar datos " << endl;
        cout << "\n\n\t 2. Mostrar datos de los alumnos " << endl;
        cout << "\n\n\t 3. Estadisticas " << endl;
        cout << "\n\n\t 4. Salir" << endl;
        do{
            cout<<"\n\t\tIngrese una opcion [1-4]: ";
            op=getche();//recibe inforamción directo del teclado
        }while(op<'1'||op>'4');
        switch(op){
            case '1':
                contabilizador++;
                contAlum++;
                push(*&contabilizador);
                break;
            case '2':
                if(contAlum>0){
                        system("cls");
                    totalAlumnos=reprobados+aprobados+supletorio;
                    cout<<"\n\t\tAlumnos registrados: "<<totalAlumnos<<endl;
                    mostrarCola();
                    getch();
                }else{
                        system("cls");
                    cout<<"\n\t\tNo existen alumnos registrados, regrese al menu para registrar alumnos"<<endl;
                    getch();
                }
                break;
            case '3':
                if(colaVacia()){
                        system("cls");
                    cout<<"\n\t\tNo existen alumnos registrados, regrese al menu para registrar alumnos"<<endl;
                    getch();
                }else{
                    system("cls");
                    totalAlumnos=reprobados+aprobados+supletorio;
                    porRe=(reprobados*100)/totalAlumnos;
                    porApro=(aprobados*100)/totalAlumnos;
                    porSuple=(supletorio*100)/totalAlumnos;
                    cout<<"\n\t\t **********************"<<endl;
                    cout<<"\n\t\t Estadisticas del curso"<<endl;
                    cout<<"\n\t\t **********************"<<endl;
                    cout<<"\n\t\t Cantidad de alumnos                          : "<<totalAlumnos<<endl;
                    cout<<"\n\t\t Porcentaje de alumnos en la base de datos    : 100%"<<endl;
                    cout<<"\n\t\t Cantidad de alumnos aprobados                : "<<aprobados<<endl;
                    cout<<"\n\t\t Porcentaje de alumnos aprobados              : "<<porApro<<"%"<<endl;
                    cout<<"\n\t\t Cantidad de alumnos reprobados               : "<<reprobados<<endl;
                    cout<<"\n\t\t Porcentaje de alumnos reprobados             : "<<porRe<<"%"<<endl;
                    cout<<"\n\t\t Cantidad de alumnos a cursar el supletorio   : "<<supletorio<<endl;
                    cout<<"\n\t\t Porcentaje de alumnos a cursar el supletorio : "<<porSuple<<"%"<<endl;
                    cout<<"\n"<<endl;
                    cout<<"\n\t\t Lista del curso"<<endl;
                    mostrarColaTwo();
                    getch();
                }
                mostrarColaTwo();
                break;

        }
    }while(op!='4');
    system("cls");
    cout<<"\n"<<endl;
    for(int i = 0;i<=45;i++){
        string exit = "";
        exit+=".";
        cout<<exit;
        Sleep(10);
    }

    cout<<"\n"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"\t\t     Exiting"<<endl;
    cout<<"*********************************************"<<endl;
    for(int i = 0;i<=45;i++){
        string exit = "";
        exit+=".";
        cout<<exit;
        Sleep(25);
    }
    cout<<"\n"<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"\t\t  Exit complete"<<endl;
    cout<<"*********************************************"<<endl;
    getch();
    return 0;
}

int colaVacia(){
    return (primero ==NULL);
};


void mostrarCola()
{
    if(!colaVacia()){
    c = primero;
      cout<<endl;
      while(c)
      {
         cout<<"\n";
         cout<<"\t\t\t Numero del alumno : "<<c->alu.alumno<<endl;
         cout<<"\t\t\t Nombre alumno     : "<< c->alu.nombre <<endl;
         cout<<"\t\t\t Direccion         : "<<c->alu.direccion<<endl;
         cout<<"\t\t\t Edad del alumno   : "<< c->alu.edad <<endl;
         cout<<"\t\t\t Semestre          : "<< c->alu.semestre <<endl;
         cout<<"\t\t\t Materias aprobadas: "<<c->alu.materiasAprobadas<<endl;
         cout<<"\t\t\t Estatus del alumno: "<<c->alu.status<<endl;
         c = c->sig;
      }
      cout<<endl;
      }
}

void push(int &numeroCl)
{
    numeroCl=contabilizador;
   int eda, sla, asien, cl=1, m;
   char fin;
   do{
        fflush(stdin);
       system ("cls");

       if(!colaVacia()){
            cout<<"\n\t Lista de alumnos ";
        mostrarCola();
       }else{
            cout<<"\n\t Ingresar datos de alumno\n";
        mostrarCola();
       }
        c = new struct datos;
       cout<<"\n\t\t Ingrese el nombre del alumno  : ";
       cin.getline(c->alu.nombre,50,'\n');
       cout<<"\n\t\t Direccion del alumno          : ";cin.getline(c->alu.direccion,50,'\n');
       cout<<"\n\t\t Ingrese la edad               : ";
       cin>>eda;
        c->alu.edad=eda;
        fflush(stdin);
       cout<<"\n\t\t Ingrese el semestre del alumno: ";cin.getline(c->alu.semestre,50,'\n');
       cout<<"\n\t\t Materias aprobadas            : ";
       cin>>m;
       c->alu.materiasAprobadas=m;
       if(c->alu.materiasAprobadas==6){
        c->alu.status="supletorio";
       }else if(c->alu.materiasAprobadas==7){
        c->alu.status="aprobado";
       }else{
         c->alu.status="rebrobado";
       }
       if(c->alu.status.compare("supletorio")==0){
        supletorio+=1;
       }else if(c->alu.status.compare("aprobado")==0){
        aprobados+=1;
       }else if(c->alu.status.compare("rebrobado")==0){
        reprobados+=1;
       }
       c->alu.alumno=numeroCl;
       c->sig = NULL;

       if(ultimo){
        ultimo->sig=c;
       }

       ultimo=c;

       if(!primero){
        primero=c;
       }
       cout<<"\n\t\t Desea ingresar mas alumnos? (S/N)";
       fin=toupper(getche());
       cl++;
   }while (fin == 'S');
}

void mostrarColaTwo()
{
    if(!colaVacia()){
        c = primero;
      cout<<endl;
      while(c)
      {
          cout<<"\n";
          cout<<"\t\t\t Numero del alumno: "<<c->alu.alumno<<endl;
          cout<<"\t\t\t Direccion        : "<<c->alu.direccion<<endl;
         cout<<"\t\t\t Nombre alumno     : "<< c->alu.nombre <<endl;
         cout<<"\t\t\t Edad del alumno   : "<< c->alu.edad <<endl;
         cout<<"\t\t\t Semestre          : "<< c->alu.semestre <<endl;
         cout<<"\t\t\t Materias aprobadas: "<<c->alu.materiasAprobadas<<endl;
         cout<<"\t\t\t Estatus del alumno: "<<c->alu.status<<endl;
         c = c->sig;
      }
      cout<<endl;
      }
}
