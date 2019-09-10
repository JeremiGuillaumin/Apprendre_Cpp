#include "ipv4.h"

/**
 * @brief IPV4::CalculerMasque
 * @details Calcul le masque du réseau à parir de CIDR
 * @param _cidr entier sur 8 bits
 */

void IPv4::CalculerMasque(unsigned char _cidr)
{
    int indice;
    //Le masque est remis à 0 -> 0.0.0.0
    for(indice=0 ; indice<4 ; indice++)
        masque[indice] = 0;
    indice= 0;
    //tant que le cidr est un multiple de 8
    while(_cidr>=8)
    {
        masque[indice++]=255;
        _cidr -= 8;
    }
    //Complément pour la fin du cidr (<8)
    unsigned char puissance = 128;
    while(_cidr-->0) //Après le test la variable _cidr est décrémentée
    {
        //les puissances de 2 sont ajoutées à l'octet par valeur décroissante
        masque[indice] += puissance;
        puissance /=2;
    }
}

/**
 * @brief IPv4::IPv4
 * @details Constructeur de la classe, initialise l'adresse et le masque
 * @param _adresse Adresse IPv4
 * @param _cidr valeur derrière le / de l'adresse
 */

IPv4::IPv4(const unsigned char *_adresse, const unsigned char _cidr)
{
    adresse = new unsigned char[4];
    masque = new unsigned char[4];
    for (int indice = 0; indice < 4; indice++)
        adresse[indice] = _adresse[indice];
    if (_cidr<=32)
        CalculerMasque(_cidr);
}

/**
 * @brief IPv4::IPv4
 * @details Constructeur de la classe, initialise l'adresse et le masque
 *          alloue la mémoire pour adresse et pour masque
 * @param _adresse Adresse IPv4
 * @param _masque Masque du réseau
 */

IPv4::IPv4(const unsigned char *_adresse, const unsigned char *_masque)
{
    adresse = new unsigned char[4];
    masque = new unsigned char[4];
    for(int indice=0;indice<4;indice++)
    {
        adresse[indice]=_adresse[indice];
        masque[indice]=_masque[indice];
    }
}

/**
 * @brief IPv4::~IPv4
 * @details Destructeur de la classe libère la mémoire allouée
 */

IPv4::~IPv4()
{
    delete [] adresse;
    delete [] masque;
}

/**
 * @brief IPv4::ObtenirMasque
 * @param _masque
 */

void IPv4::ObtenirMasque(unsigned char * _masque)
{
    for(int indice = 0; indice < 4; indice++)
        _masque[indice] = masque[indice];
}

/**
 * @brief IPv4::ObtenirAdresseReseau
 * @param _reseau
 */

void IPv4::ObtenirAdresseReseau(unsigned char * _reseau)
{
    for(int indice = 0; indice < 4; indice++)
        _reseau[indice] = adresse[indice] & masque[indice];
}

/**
 * @brief IPv4::ObtenirAdresseDiffusion
 * @param _diffusion
 */

void IPv4::ObtenirAdresseDiffusion(unsigned char * _diffusion)
{
    unsigned char adresseDuReseau[4];
    ObtenirAdresseReseau(adresseDuReseau);
    for(int indice = 0; indice < 4; indice++)
        _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice];
}
