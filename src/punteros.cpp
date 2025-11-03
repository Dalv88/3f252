#include <iostream>
#include <string>
#include <list>
using namespace std;

class Humano{
private:
    string nombre;
    int edad;
public:
    Humano() : nombre("Sin nombre"), edad(0) {}
    Humano(string n, int e) : nombre(n), edad(e) {}

    string LeerNombre( return nombre;)
    int LeerEdad(){ return edad;}
};

class Alumno : public Humano{
private:
    int registro;
public:
    Alumno() : Humano("Alumno sin nombre", 0), registro(0) {}

    Alumno(string n, int e, int r) : Humano(n, e), registro(r) {}

    int LeerRegistro() { return registro; }
};

class Empleado : public Humano{
private:
    long noEmpleado;
public:
    Empleado() : Humano("Empleado sin nombre", 0), noEmpleado(0) {}

    Empleado(string n, int e, long noEmp) : Humano(n, e), noEmpleado(noEmp) {}

    long LeerNumeroEmpleado() { return noEmpleado; }
};

int main(int arc, char const *argv[])
{
    Humano* humano = NULL;
    Alumno* alumno = new Alumno("Carlos", 20, 123);
    Empleado* empleado = new Empleado("Ana", 30, 98765);

    humano = alumno;
    cout << "Edad del alumno: " << humano->LeerEdad() << endl;

    humano = empleado;
    cout << "Edad del empleado: " << humano->LeerEdad() << endl;

    list<Humano*> listaHumanos;
    listaHumanos.emplace_back(new Alumno("Luis", 19, 456));
    listaHumanos.emplace_back(new Alumno("Sofia", 21, 789));
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Empleado("Mario", 40, 1001));
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());

    for (auto &&humano : listaHumanos)
    {
        cout << humano->LeerNombre() << endl;
    }
    

    return 0;
}
