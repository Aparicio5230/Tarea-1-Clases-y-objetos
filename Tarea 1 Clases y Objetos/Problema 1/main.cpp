#include <iostream>

using namespace std;

class Empleado {
  private:

    int claveEmpleado;
    string nombre;
    string domicilio;
    float sueldo;
    string reportaA;

  public:

    Empleado(int clave,string _nombre,string _domicilio, float _sueldo, string reporta) {

        claveEmpleado = clave;
        nombre = _nombre;
        domicilio = _domicilio;
        sueldo = _sueldo;
        reportaA = reporta;
    }
    Empleado() {
        claveEmpleado = 0;
        nombre = "Sin definir . . .";
        domicilio = "Sin definir . . .";
        sueldo = 0.0;
        reportaA = "Sin definir . . .";
    }

    int dimeClave() {
        return claveEmpleado;
    }

    float dimeSueldo() {
        return sueldo;
    }

    void imprime()const {

        cout<<"Clave: "<<claveEmpleado<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Domicilio: "<<domicilio<<endl;
        cout<<"Sueldo: "<<sueldo<<endl;
        cout<<"Reporta a : "<<reportaA<<endl<<endl;
    }

    void cambiaDomicilio(string nuevoDomicilio) {
        domicilio = nuevoDomicilio;
    }

    void cambiaReportaA(string nuevoReportaA) {
        reportaA = nuevoReportaA;
    }

    void aumentarSueldo(float nuevoSueldo) {
        sueldo = nuevoSueldo;
    }

};

int menu();
void pausarParaContinuar();
int opcion;

int main() {
    Empleado jefePlanta(1,"La abuelita","Av. Plutalco", 1500, "El abuelito");
    Empleado jefePersonal(2,"La Tia","Av. Mateos", 1500, "El Tio");;

    int claveBuscar;
    string cadena;
    do {

        opcion = menu();

        switch(opcion) {
        case 1: {

            system("cls");
            cout<<"Digita la clave: ";
            cin>>claveBuscar;
            cin.ignore();

            if(claveBuscar == jefePersonal.dimeClave()) {

                cout<<"Cambio de domicilio de Jefe de Personal"<<endl;
                cout<<"Nuevo domicilio: ";
                getline(cin,cadena);
                jefePlanta.cambiaDomicilio(cadena);
            } else if(claveBuscar == jefePlanta.dimeClave()) {

                cout<<"Cambio de domicilio de Jefe de Planta"<<endl;
                cout<<"Nuevo domicilio: ";
                getline(cin,cadena);
                jefePlanta.cambiaDomicilio(cadena);
            }
            else{
                cout<<"Clave no encontrada :("<<endl;
            }

        }
        break;
        case 2: {

            system("cls");
            cout<<"Digita la clave: ";
            cin>>claveBuscar;
            cin.ignore();

            float porcentajeA;
            float nuevoSueldo, sueldo;

            if(claveBuscar == jefePersonal.dimeClave()) {

                cout<<"Aumento de sueldo de Jefe de Personal"<<endl;
                cout<<"Porcentaje a aumentar (0% a 100%): ";
                cin>>porcentajeA;
                if(porcentajeA > 100 || porcentajeA < 0) {
                    return 1;
                }
                sueldo = jefePersonal.dimeSueldo();

                nuevoSueldo = sueldo + (sueldo * (porcentajeA / 100));

                jefePersonal.aumentarSueldo(nuevoSueldo);

            } else if(claveBuscar == jefePlanta.dimeClave()) {

                cout<<"Aumento de sueldo de Jefe de Planta"<<endl;
                cout<<"Porcentaje a aumentar (0% a 100%): ";
                cin>>porcentajeA;

                sueldo = jefePlanta.dimeSueldo();

                nuevoSueldo = sueldo + (sueldo * (porcentajeA / 100));

                jefePlanta.aumentarSueldo(nuevoSueldo);
            }
            else{
                cout<<"Clave no encontrada :("<<endl;
            }
        }
        break;
        case 3: {

            system("cls");
            cout<<"Imprimiendo datos . . ."<<endl<<endl;
            cout<<"Jefe de Personal"<<endl;
            jefePersonal.imprime();
            cout<<"Jefe Planta"<<endl;
            jefePlanta.imprime();

            pausarParaContinuar();

        }
        break;
        case 4: {
            system("cls");
            cout<<"Digita la clave: ";
            cin>>claveBuscar;
            cin.ignore();

            if(claveBuscar == jefePersonal.dimeClave()) {

                cout<<"Cambio de a quien reportarse de Jefe de Personal"<<endl;
                cout<<"Nuevo a nombre: ";
                getline(cin,cadena);
                jefePersonal.cambiaReportaA(cadena);

            } else if(claveBuscar == jefePlanta.dimeClave()) {

                cout<<"Cambio de a quien reportarse de Jefe de Planta"<<endl;
                cout<<"Nuevo nombre: ";
                getline(cin,cadena);
                jefePlanta.cambiaReportaA(cadena);
            }
            else{
                cout<<"Clave no encontrada :("<<endl;
            }

        }
        break;
        default:cout<<"Opcion no valida (1-5)"<<endl<<endl;
            ;
        }

    } while(opcion != 5);

    return 0;
}

int menu() {

    system("cls");
    cout<<"1.-Cambiar domicilio"<<endl; //pedir clave y nuevo domicilio
    cout<<"2.-Actualizar el sueldo"<<endl; //pedir la clave y porcentaje de aumento
    cout<<"3.-Imprimir datos"<<endl; //clave a buscar
    cout<<"4.-Cambiar nombre de a quien reportarse"<<endl;
    cout<<"5.-Salir"<<endl;
    cout<<"OPcion -> ";
    cin>>opcion;
    cin.ignore();
    return opcion;
}

void pausarParaContinuar(){

    cout<<"Presiona enter para continuar"<<endl;
    getchar();
}
