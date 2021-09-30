#include <iostream>
#include <string>
#include <sstream>



using namespace std;
int main()
{
    char Password[100];
    int KeyNumber[100];
    string Key;
    char Key2[100];
    int i = 0;
    int Elegir;


    cout << "Bienvenido al encriptador\n1-Encriptar\n2-Desencriptar\n¿Que desea elegir?=";
    cin >> Elegir;

    if (Elegir == 1) {
        goto Encripta;
    }
    else {
        goto Desencripta;
    }



    //Encriptar
    Encripta:

    cout << "Introduce lo que quieras encriptar:\n";
    cin >> Password;

    srand(time(NULL));

    do {


        int randNum = rand() % (256 - 0 + 1) + 0;
        
        if (Password[i] == '-') {
            Password[i] = ' ';
        }

        Reroll:

        Password[i] = randNum - Password[i];

        if (Password[i] == '\32' || Password[i]== '\13') {
            goto Reroll;
        }

        if (i == strlen(Password) - 1) {
            Key = Key + to_string(randNum) + ';';
        }
        else {
            Key = Key + to_string(randNum) + '.';
        }


        i++;

    } while (i != strlen(Password));

    cout << "\n" << Password;

    cout << "\n" << Key;

    return 0;

    //Desencriptar
    Desencripta:

    cout << "Introduce lo que quieras desencriptar:\n";
    cin >> Password;
    cout << "Introduce la KEY\n";
    cin >> Key2;
    
    int i2[3];
    string i21;
    int i22;
    int i4 = 0;
    int i3 = 0;
    do {

        if (Key2[i] == '.') {
            i22 = stoi(i21);

            Password[i4] = i22 - Password[i4];
           
            cout << Password[i4];

            i3 = 0;
            i4++;
            i21 = "";
        }
        else {
            if (Key2[i] == ';') {
                i22 = stoi(i21);

                Password[i4] = i22 - Password[i4];

                cout << Password[i4];

                break;
            }

            i2[i3] = (int)Key2[i];
            i21 += i2[i3];
            
            i3++;
        }
        
        i++;
    } while (i != strlen(Key2));


    return 0;



}
