#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include <iostream>
#define infoC(C) (C)->infoC
#define nextC(C) (C)->nextC
#define firstR(C) (C)->firstRelC
#define infoP(P) (P)->infoP
#define nextP(P) (P)->nextP
#define nextR(R) (R)->nextR
#define prevR(R) (R)->prevR
#define product(R) (R)->product
#define rating(R) (R)->rating
#define firstC(LC) (LC).firstC
#define firstP(LP) (LP).firstP

using namespace std;

struct customer
{
    string username;
};
struct product
{
    string nama;
};
typedef struct elmCustomer *adrC;
typedef struct elmProduct *adrP;
typedef struct elmRating *adrR;
typedef customer infotypeC;
typedef product infotypeP;

struct elmCustomer
{
    infotypeC infoC;
    adrC nextC;
    adrR firstR;
};
struct elmProduct
{
    infotypeP infoP;
    adrP nextP;
};
struct elmRating
{
    adrR nextR,prevR;
    adrP product;
    int rating;
};
struct listCustomer
{
    adrC firstC;
};
struct listProduct
{
    adrP firstP;
};

void createListCustomer(listCustomer &lc);
void createListProduct(listProduct &lp);
adrC createElmCustomer(infotypeC x);
adrP createElmProduct(infotypeP x);
adrR createElmRating(int x);

void signUp(listCustomer &lc, adrC c); /* insert first */
void insertProduct(listProduct &lp, adrP p); /* insert last */

adrC findCustomerData(listCustomer lc, string username);
void deleteFirstCustomer(listCustomer &lc, adrC x);
void deleteLastCustomer(listCustomer &lc, adrC x);
void deleteAfterCustomer(listCustomer &lc, adrC prec,adrC x);
void deleteCustomerData(listCustomer &lc, adrC x);

adrC findProduct(listCustomer lc, string nama);
void deleteFirstProduct(listProduct &lp, adrP x);
void deleteLastProduct(listProduct &lp, adrP x);
void deleteAfterProduct(listProduct &lp, adrP prec,adrP x);
void deleteProductData(listProduct &lp, adrP x);

void showCustomerData(listCustomer lc);
void showProductData(listProduct lp);
#endif // APP_H_INCLUDED
