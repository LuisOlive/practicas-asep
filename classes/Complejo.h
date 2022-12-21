#include "_utilidades.h"

#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo
{
public:
    // # estas son las propiedades o atributos

    double real, imaginaria;
    string nombre;

    // # estos son constructores
    // Crea una instancia anonima de un complejo, sin paramteros se crea un 0 + 0i
    Complejo(double re = 0, double im = 0)
    {
        real = re;
        imaginaria = im;
    }

    // Crea una instancia nombrada de complejo, sin paramteros se crea un 0 + 0i
    Complejo(string _nombre, double re = 0, double im = 0)
    {
        nombre = _nombre;
        real = re;
        imaginaria = im;
    }

    // # este es el destructor
    ~Complejo()
    { // ~ es con alt 126
        // valores dañinos para el programa, para eso es el destructor
        real = 8624184286426;
        imaginaria = -86426728268;
    }

    // # estos son metodos
    // muestra toda la info del numero complejo
    void status()
    {
        cout << nombre << " = " << real << " + " << imaginaria << "i\n";
    }

    void statusPolar()
    {
        cout
            << nombre << " = " // nombre =
            << modulo()        // modulo del complejo
            << " | "
            << argumento() * RAD_2_DEG // argumento, transformado a grados
            << (char)-89               // símbolo º
            << endl;
    }

    // podemos retornar objetos
    // devuelve la suma de un complejo con otro
    Complejo mas(Complejo otro)
    {
        return Complejo(real + otro.real, imaginaria + otro.imaginaria);
    }

    // # esto es una sobrecarga de mas()
    // devuelve la suma de un complejo con otro usando flotantes
    Complejo mas(double re, double im = 0)
    {
        return mas(Complejo(re, im));
    }

    // para escribir operadores se usa el keyword operator
    Complejo operator+(Complejo otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return mas(otro);
    }

    Complejo operator+(double otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return mas(otro);
    }

    Complejo menos(Complejo otro)
    {
        return Complejo(real - otro.real, imaginaria - otro.imaginaria);
    }

    Complejo menos(double re, double im = 0)
    {
        return menos(Complejo(re, im));
    }

    // para escribir operadores se usa el keyword operator
    Complejo operator-(Complejo otro)
    { // otro solo es una convencion
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return menos(otro);
    }

    // para escribir operadores se usa el keyword operator
    Complejo operator-(double otro)
    { // otro solo es una convencion
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return menos(otro);
    }

    Complejo por(Complejo otro)
    {
        // z = a + bi, w = c + di -> zw = ac - bd + (ad + bc)i
        double a = real, b = imaginaria,
               c = otro.real, d = otro.imaginaria;

        return Complejo(a * c - b * d, a * d + b * c);
    }

    Complejo por(double re, double im = 0)
    {
        return por(Complejo(re, im));
    }

    Complejo operator*(Complejo otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return por(otro);
    }

    Complejo operator*(double otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return por(otro);
    }

    Complejo entre(Complejo otro)
    {
        // z = a + bi, w = c + di
        double a = real, b = imaginaria,
               c = otro.real, d = otro.imaginaria;

        /*
          .      ac + bd + (bc - ad)i     ac + bd        bc - ad
         .z/w = ---------------------- = --------- + i -----------
          .           c² + d²             c² + d²        c² + d²
        */
        double denom = c * c + d * d; // (c² + d²)

        return Complejo((a * c + b * d) / denom, (b * c - a * d) / denom);
    }

    Complejo entre(double re, double im = 0)
    {
        return entre(Complejo(re, im));
    }

    Complejo operator/(Complejo otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return entre(otro);
    }

    Complejo operator/(double otro)
    {
        // recoemndacion es tener el algoritmo con un metodo en palabras
        return entre(otro);
    }

    double modulo()
    {
        // pitagorazo de real e imaginaria
        return sqrt(real * real + imaginaria * imaginaria);
    }

    double argumento()
    {
        // previniendo division entre 0
        if (real == 0)
            return PI_2 * (imaginaria < 0) ? -1 : (imaginaria > 0); // pi/2 * signo(im)

        return atan(imaginaria / real);
        // return atan(imaginaria / (real + 1e-8)); // otra forma, más fácil, pero menos precisa
    }

    Complejo conjugado()
    {
        return Complejo(real, -imaginaria);
    }

    // con excepcion del punto todos los ops. pueden sobrecargarse
    bool esMayorQue(Complejo otro)
    {
        return modulo() > otro.modulo();
    }

    // # esto es la una sobrecarga de operador booleano
    // bool es un tipo de dato, que solo puede ser 0 o 1, puede sustituir por int
    bool operator>(Complejo otro)
    {
        return esMayorQue(otro);
    }

    bool esMenorQue(Complejo otro)
    {
        return modulo() > otro.modulo();
    }

    bool operator<(Complejo otro)
    {
        return esMenorQue(otro);
    }

    bool esMayorOIgualQue(Complejo otro)
    {
        return modulo() >= otro.modulo();
    }

    bool operator>=(Complejo otro)
    {
        return esMayorOIgualQue(otro);
    }

    // si no se desea, puede no crearse un metodo normal e implementarse directo el operador
    bool operator==(Complejo otro)
    {
        return real == otro.real && imaginaria == otro.imaginaria;
    }

    // # mas operadores
    // sobrecarga del paréntsis
    void operator()(string nom, int x = 0)
    {
        // con la gran ventaja de que el paréntesis está hecho para mucho paramteros
        nombre = nom;
    }

    // este operador previene un sobreescritura completa
    void operator=(Complejo otro)
    {
        real = otro.real;
        imaginaria = otro.imaginaria;
        // más adelante vemos como hacer que el igual devuelva el nuevo resultado
    }

    // este operador previene un sobreescritura completa
    void operator+=(Complejo otro)
    {
        real += otro.real;
        imaginaria += otro.imaginaria;
        // más adelante vemos como hacer que el igual devuelva el nuevo resultado
    }

    // ++ requiere un prametro aunque no se utilize
    void operator++(int _)
    {
        real++;
        imaginaria++;
    }
};

ostream &operator<<(ostream &_cout, Complejo z)
{
    _cout << z.real << " + " << z.imaginaria << "i"; // expresion lineal
    return _cout;
}

#endif
