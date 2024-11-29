#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
#include <iostream>
#define infoC(C) (C)->infoC
#define nextC(C) (C)->nextC
#define firstR(C) (C)->firstR
#define lastR(C) (C)->lastR
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
    adrR firstR,lastR;
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
    string rating;
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
adrR createElmRating(string x);

void signUp(listCustomer &lc, adrC c); /* insert first */
void insertProduct(listProduct &lp, adrP p); /* insert last */
void insertRating(listCustomer &lc, listProduct lp, string username, string nama, adrR r);

adrC findCustomerData(listCustomer lc, string username);
void deleteFirstCustomer(listCustomer &lc, adrC &x);
void deleteLastCustomer(listCustomer &lc, adrC &x);
void deleteAfterCustomer(listCustomer &lc, adrC prec,adrC &x);
void deleteCustomerData(listCustomer &lc);

adrP findProduct(listProduct lp, string nama);
void deleteFirstProduct(listProduct &lp, adrP &x);
void deleteLastProduct(listProduct &lp, adrP &x);
void deleteAfterProduct(listProduct &lp, adrP prec,adrP &x);
void deleteProductData(listProduct &lp);

adrR findRating(adrP p, adrC c);
void deleteFirstRating(adrC &c, adrR &x);
void deleteLastRating(adrC &c, adrR &x);
void deleteAfterRating(adrC &c, adrR prec,adrR &x);
void deleteRatingData(listCustomer &lc, listProduct lp, string nama, string username);

void showCustomerData(listCustomer lc);
void showProductData(listProduct lp);
void showRatedProduct(listCustomer lc, string username);
void showUnratedProduct(listCustomer lc, listProduct lp, string username);

int menuLogin();
int menuAdmin();
int menuUser();

#endif // APP_H_INCLUDED
