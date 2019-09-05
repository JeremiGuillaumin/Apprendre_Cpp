#include <iostream>
#include <iomanip>
#include<fstream>
#include<string>
using namespace std; // évite d'écrire std::cout

int main()
{

    string nomDuFichier;

        cout << "Entrer le nom du fichier à lire : ";
        cin >> nomDuFichier;

        //Création du flux en lecture sur le fichier
        ifstream leFichier(nomDuFichier.c_str()); // c_str() transforme string en char*

        if(!leFichier .is_open())
            cerr << "Erreur lors de l'ouverture du fichier" << endl;

        else{

            string pays;
            int nbOr;
            int nbArgent;
            int nbBronze;

            cout << "+"<<setfill('-')<<setw(45)<<"+"<<setfill(' ') << endl;

            do{

                leFichier >> pays >> nbOr >> nbArgent >> nbBronze;

                if(leFichier.good())
                {

                    cout << "|" <<setw(29) << left << pays<< "|" << setw(3) << right << nbOr << "|" << setw(3) << right << nbArgent << " | "<< setw(3) << right << nbBronze << " | " <<endl;

                }

            }while(!leFichier.eof());
            cout << "+"<<setfill('-')<<setw(45)<<"+"<<setfill(' ') << endl;



        }

    return 0;


    }
