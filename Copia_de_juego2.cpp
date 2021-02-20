#include <stdlib.h>
#include <iostream>
using namespace std;

class Juego //automatico
{
    private:
    int size_tablero;
    string *_tablero;
    void tablero_ ()
    {
        for (int i=0;i<size_tablero;i++)
        {
            if (i == 4 || i == 13 || i == 21)
            {
                _tablero[i]= "S";
            } 

            else if (i == 8 || i == 15 || i == 27)
            {
                _tablero[i]= "L";
            }
            else
            {
                _tablero[i]= "N";
            }
        }
    }

    public:
    Juego() //constructor asignar valores
    {
        size_tablero=30;
        _tablero= new string [size_tablero];
        tablero_();
    }

    virtual void print_tablero();

    virtual int dado ();

    virtual void jugar();
};

void Juego:: print_tablero()
{
    for (int i=0; i<size_tablero; i++)
    {
        cout << _tablero[i] << " | ";
    }   
    cout << endl;
}
int Juego:: dado()
{
    srand(time(0));
    return ((rand()%6)+1); 
}
void Juego:: jugar()
{
    int j1=1;
    int j2=0;
    int turno_j1=1;
    int turno_j2=1;
    int casilla_j1=1;
    int casilla_j2=1;
    int pos1=0;
    int pos2=0;
    int penalty= 3;
    int reward= 3;

    string continuar= "c";

    while (pos1 < size_tablero - 1 && pos2 < size_tablero - 1) // checar
    {
        if (j1>j2)
        {
            cout << "Jugador 1. Turno: " << turno_j1 << endl;
            turno_j1 += 1;
            cout << "El dado dio: " << dado() << endl; 
            cout << "Comenzaste en: " << _tablero[pos1] << "  Numero: " << casilla_j1 << endl;
            casilla_j1 = casilla_j1 + dado();
            pos1 = pos1 + dado();
            cout << "caiste en: " << _tablero[pos1] << "  Numero: " << casilla_j1 << endl;
            if (_tablero[pos1] == "S")
            {
                pos1 -= penalty;
                casilla_j1 -= penalty;
                cout << "Caiste en una serpiente, tu nueva posición es: " << casilla_j1 << "  Esta casilla es: " << _tablero[pos1] << endl;
            }

            else if (_tablero[pos1] == "L")
            {
                pos1 += reward;
                casilla_j1 += reward;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j1 << "  Esta casilla es: " << _tablero[pos1] << endl;
            }

            cout << "Quiere seguir juegando? c: continuar, e: exit" << endl;
            cin >> continuar;
            if (continuar == "e")
            {
                cout << "Gracias por jugar beibi" << endl; 
                break;
            }
            j2 += 1;
        }

        if (j1==j2)
        {
            cout << "Jugador 2. Turno: " << turno_j2 << endl;
            turno_j2 += 1;
            cout << "El dado dio: " << dado() << endl;
            cout << "Comenzaste en: " << _tablero[pos2]  << "   Numero: " << casilla_j2 << endl; 
            casilla_j2 = casilla_j2 + dado();
            pos2 = pos2 + dado();
            cout << "caiste en: " << _tablero[pos2] << "  Numero: " << casilla_j2 << endl;
            if (_tablero[pos2] == "S")
            {
                pos2 -= penalty;
                casilla_j2 -= penalty;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j2 << "  Esta casilla es: " << _tablero[pos2] << endl;
            }

            else if (_tablero[pos2] == "L")
            {
                pos2 += reward;
                casilla_j2 += reward;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j2 << "  Esta casilla es: " << _tablero[pos2] << endl;
            }

            cout << "Quiere seguir juegando? c: continuar, e: exit" << endl;
            cin >> continuar;
            if (continuar == "e")
            {
                cout << "Gracias por jugar beibi" << endl; 
                break;
            }
            j1 += 1;
        }
    }
    
    if (casilla_j1 == size_tablero )
    {
        cout << "Gracias por jugar! ciao bella.   Ganador: jugador 1"  << endl;
    }

    if (casilla_j2 == size_tablero )
    {
        cout << "Gracias por jugar! ciao bella.   Ganador: jugador 2"  << endl;
    }
}

class Manual : public Juego
{
    private:
    int size_tablero;
    string *_tablero;
    void tablero_ ()   
    {
        for (int i=0;i<size_tablero;i++)
        {
           cout << "Ingrese su tablero. Recuerde que tiene que ser: N: casilla normal, L: escalera, S: sepriente" << endl;
           cin >> _tablero[i];
        }
    }
    public:
 // como el constructor esta rriba y heredas se puede borrar. (constructor del tablero)
    int penalty;
    int reward;
    Manual(){}; //por tener uno con parametros debes tener uno por default
    Manual(int s_tablero, int penalty_, int reward_)
    {
        size_tablero= s_tablero;
        penalty= penalty_;
        reward= reward_;
        _tablero= new string[size_tablero];
        tablero_(); //lamas a la funcion
    }
    void print_tablero();
    int dado ();
    void jugar();
};

void Manual::print_tablero()
{
    for (int i=0; i<size_tablero; i++)
    {
        cout << _tablero[i] << " | ";
    }   
    cout << endl;
}
int Manual:: dado()
{
    srand(time(0));
    return ((rand()%6)+1); 
}
void Manual:: jugar()
{
    int j1=1;
    int j2=0;
    int turno_j1=1;
    int turno_j2=1;
    int casilla_j1=1;
    int casilla_j2=1;
    int pos1=0;
    int pos2=0;

    string continuar= "c";

    while (pos1 < size_tablero - 1 && pos2 < size_tablero - 1) // checar
    {
        if (j1>j2)
        {
            cout << "Jugador 1. Turno: " << turno_j1 << endl;
            turno_j1 += 1;
            cout << "El dado dio: " << dado() << endl; 
            cout << "Comenzaste en: " << _tablero[pos1] << "  Numero: " << casilla_j1 << endl;
            casilla_j1 = casilla_j1 + dado();
            pos1 = pos1 + dado();
            cout << "caiste en: " << _tablero[pos1] << "  Numero: " << casilla_j1 << endl;
            if (_tablero[pos1] == "S")
            {
                pos1 -= penalty;
                casilla_j1 -= penalty;
                cout << "Caiste en una serpiente, tu nueva posición es: " << casilla_j1 << "  Esta casilla es: " << _tablero[pos1] << endl;
            }

            else if (_tablero[pos1] == "L")
            {
                pos1 += reward;
                casilla_j1 += reward;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j1 << "  Esta casilla es: " << _tablero[pos1] << endl;
            }

            cout << "Quiere seguir juegando? c: continuar, e: exit" << endl;
            cin >> continuar;
            if (continuar == "e")
            {
                cout << "Gracias por jugar beibi" << endl; 
                break;
            }
            j2 += 1;
        }

        if (j1==j2)
        {
            cout << "Jugador 2. Turno: " << turno_j2 << endl;
            turno_j2 += 1;
            cout << "El dado dio: " << dado() << endl;
            cout << "Comenzaste en: " << _tablero[pos2]  << "   Numero: " << casilla_j2 << endl; 
            casilla_j2 = casilla_j2 + dado();
            pos2 = pos2 + dado();
            cout << "caiste en: " << _tablero[pos2] << "  Numero: " << casilla_j2 << endl;
            if (_tablero[pos2] == "S")
            {
                pos2 -= penalty;
                casilla_j2 -= penalty;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j2 << "  Esta casilla es: " << _tablero[pos2] << endl;
            }

            else if (_tablero[pos2] == "L")
            {
                pos2 += reward;
                casilla_j2 += reward;
                cout << "Caiste en una escalera, tu nueva posición es: " << casilla_j2 << "  Esta casilla es: " << _tablero[pos2] << endl;
            }

            cout << "Quiere seguir juegando? c: continuar, e: exit" << endl;
            cin >> continuar;
            if (continuar == "e")
            {
                cout << "Gracias por jugar beibi" << endl; 
                break;
            }
            j1 += 1;
        }
    }
    
    if (casilla_j1 == size_tablero )
    {
        cout << "Gracias por jugar! ciao bella.   Ganador: jugador 1"  << endl;
    }

    if (casilla_j2 == size_tablero )
    {
        cout << "Gracias por jugar! ciao bella.   Ganador: jugador 2"  << endl;
    }
}

int main()
{
    int decision= 0;
    int s_tablero;
    int penalty_;
    int reward_;


    cout<< "desea ingresar usted los datos de forma manual? 1: si, 2: no" << endl;
    cin >> decision;
    if (decision==1)
    {
        
        cout << "ingrese numero de casillas" << endl;
        cin >> s_tablero;
        cout << "ingrese numero de castigo" << endl;
        cin >> penalty_;
        cout << "ingrese recompensa" << endl;
        cin >> reward_;
        Manual jugar(s_tablero, penalty_, reward_);
        jugar.print_tablero();
        jugar.jugar();

    }
    else
    {
        Juego jugar;
        jugar.print_tablero();
        jugar.jugar();
    }
};
