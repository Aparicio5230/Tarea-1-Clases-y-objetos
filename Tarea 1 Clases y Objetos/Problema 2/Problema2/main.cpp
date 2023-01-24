#include <iostream>

using namespace std;

class Materia {

  private:
      int clave;
      string nombre;
      string profesorTit;
      string libroTexto;

  public:

      Materia(int _clave,string _nombre,string profe,string libro) {
          clave = _clave;
          nombre = _nombre;
          profesorTit = profe;
          libroTexto = libro;
    }

    Materia() {
        clave= 0;
        nombre = "Sin definir . . .";
        profesorTit = "Sin definir . . .";
        libroTexto = "Sin definir . . .";
    }

    void imprime() {
     cout<<"Clave: "<<clave<<endl;
     cout<<"Nombre: "<<nombre<<endl;
     cout<<"Nombre Profesor: "<<profesorTit<<endl;
     cout<<"Libro: "<<libroTexto<<endl;
     cout<<endl<<endl;
    }

    int dimeClave() {
        return clave;
    }
    void cambiaClave(int _clave) {
        clave = _clave;
    }

    void cambiaProfe(string _nombre) {
        profesorTit = _nombre;
    }

};

int menu();
void enterParaContinuar();

int opcionMenu;

int main() {
    ///Materia(int _clave,string _nombre,string profe,string libro) {
    Materia Programacion(1,"Programacion","Basulto Degollado","Intro. a la pProgramacion");
    Materia BasesDatos(2,"Bases de datos","Vicente Suarez","Bases de datos 1");

    int claveBuscar = 0;
    do {

        opcionMenu = menu();

        switch(opcionMenu) {
        case 1: {

            int nuevaClave;

            system("cls");
            cout<<"Cambiar la clave de la materia"<<endl;
            cout<<"Clave de la materia: ";
            cin>>claveBuscar;

            if(claveBuscar == Programacion.dimeClave()) {
                cout<<"Nueva clave: ";
                cin>>nuevaClave;
                Programacion.cambiaClave(nuevaClave);
            } else if(claveBuscar == BasesDatos.dimeClave()) {
                cout<<"Nueva clave: ";
                cin>>nuevaClave;
                BasesDatos.cambiaClave(nuevaClave);
            } else {
                cout<<"Clave no encontrada :("<<endl<<endl;
            }
            enterParaContinuar();
        }
        break;

        case 2: {

            string cadena;

            system("cls");
            cout<<"Cambiar el nombre del maestro"<<endl;
            cout<<"Clave de la materia: ";
            cin>>claveBuscar;

            if(claveBuscar == Programacion.dimeClave()) {
                cout<<"Nuevo Nombre del maestrx: ";
                getline(cin,cadena);
                Programacion.cambiaProfe(cadena);

            } else if(claveBuscar == BasesDatos.dimeClave()) {
                cout<<"Nuevo Nombre del maestrx: ";
                getline(cin,cadena);
                BasesDatos.cambiaProfe(cadena);
            } else {
                cout<<"Clave no encontrada :("<<endl<<endl;
            }
            enterParaContinuar();
        }
        break;
        case 3:
            {
                system("cls");
                cout<<"Imprimiendo datos"<<endl;
                cout<<"Programacion . . ."<<endl;
                Programacion.imprime();
                cout<<"Bases de datos . . ."<<endl;
                BasesDatos.imprime();
                enterParaContinuar();
            }
            break;
        default:
            ;
        }

    } while(opcionMenu != 4);
    return 0;
}

int menu() {

    system("cls");
    cout<<"1.-Cambiar clave de Materia"<<endl;
    cout<<"2.-Cambiar el nombre del maestro"<<endl;
    cout<<"3.-Imprime datos"<<endl;
    cout<<"4.-Salir"<<endl;
    cout<<"Opcion-> ";
    cin>>opcionMenu;
    cin.ignore();

    return opcionMenu;
}

void enterParaContinuar() {
    cout<<"Presiona enter para continuar . . ."<<endl;
    getchar();
}
