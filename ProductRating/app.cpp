#include "app.h"

#include "app.h"

using namespace std;

void createListCustomer(listCustomer &lc) {
    firstC(lc) = NULL;
}

void signUp(listCustomer &lc, adrC c){
    if(firstC(lc) == NULL){
        firstC(lc) = c;
    }else{
        nextC(c) = firstC(lc);
        firstC(lc) = c;
    }
}

adrC createElmCustomer(infotypeC x){
    adrC c = new elmCustomer;
    infoC(c) = x;
    nextC(c) = NULL;
    firstR(c) = NULL;
    lastR(c) = NULL;
    return c;
}


adrC findCustomerData(listCustomer lc, string username){
    if(firstC(lc) == NULL)
    {
        return NULL;
    }
    else
    {
        adrC c;
        c = firstC(lc);
        while(c != NULL){
            if(infoC(c).username == username){
                return c;
            }
            c = nextC(c);
        }
        return NULL;
    }
}

void deleteFirstCustomer(listCustomer &lc, adrC &x){
    if(firstC(lc) == NULL){
        cout << "List Kosong";
    }else if(nextC(firstC(lc)) == NULL){
        x = firstC(lc);
        firstC(lc) = NULL;
    }else{
        x = firstC(lc);
        firstC(lc) = nextC(x);
        nextC(x) = NULL;
    }

}

void deleteLastCustomer(listCustomer &lc, adrC &x){
    adrC b;
    if(firstC(lc) == NULL){
        cout << "List Kosong";
    }else if(nextC(firstC(lc)) == NULL){
        x = firstC(lc);
        firstC(lc) = NULL;
    }else{
        b = firstC(lc);
        while(nextC(nextC(b)) != NULL){
            b = nextC(b);
        }
        x = nextC(b);
        nextC(b) = NULL;
    }
}

void deleteAfterCustomer(listCustomer &lc, adrC prec, adrC &x){
    if(firstC(lc) == NULL){
        cout << "List Kosong";
    }else{
        x = nextC(prec);
        nextC(prec) = nextC(x);
        nextC(x) = NULL;
    }
}

void deleteCustomerData(listCustomer &lc){
    if(firstC(lc) == NULL){
        cout << "List customer kosong!" << endl;
    }else{
        adrC p,x;
        string username;
        cout << "Masukkan username customer yang ingin dihapus: ";
        cin >> username;
        p = findCustomerData(lc, username);
        if(p != NULL){
            if(p == firstC(lc)){
                deleteFirstCustomer(lc,x);
            }else if(nextC(p) ==  NULL){
                deleteLastCustomer(lc,x);
            }else{
                adrC prec = firstC(lc);
                while(nextC(prec)!= p){
                    prec = nextC(prec);
                }
                deleteAfterCustomer(lc, prec, x);
            }
            cout<<"Data customer telah dihapus!"<<endl;
        }else {
            cout << "Username customer tidak ditemukan!" << endl;
        }
    }
}

void showCustomerData(listCustomer lc){
     if (firstC(lc) == NULL) {
        cout << "List customer kosong!" << endl;
     }else{
        adrC x = firstC(lc);
        int count =0;
        while(x != NULL){
            cout << "Customer: " << infoC(x).username << endl;
            count++;
            x = nextC(x);
        }
        cout << "Total Customers: "  << count << endl;
     }
}
void createListProduct(listProduct &lp)
{
    firstP(lp) = NULL;
}
adrP createElmProduct(infotypeP x)
{
    adrP p = new elmProduct;
    nextP(p) = NULL;
    infoP(p) = x;
    return p;
}
void insertProduct(listProduct &lp, adrP p)
{
    if(firstP(lp) == NULL)
    {
        firstP(lp) = p;
    }
    else
    {
        adrP x = firstP(lp);
        while(nextP(x)!=NULL)
        {
            x = nextP(x);
        }
        nextP(x) = p;
    }
    cout << "Berhasil menambahkan data!" << endl;
}

adrP findProduct(listProduct lp, string nama)
{
    if(firstP(lp) == NULL)
    {
        return NULL;
    }
    else
    {
        adrP p = firstP(lp);
        while(p != NULL && infoP(p).nama != nama)
        {
            p = nextP(p);
        }
        return p;
    }
}
void deleteFirstProduct(listProduct &lp, adrP &x)
{
    x = firstP(lp);
    firstP(lp) = nextP(firstP(lp));
    nextP(x) = NULL;
}
void deleteLastProduct(listProduct &lp, adrP &x)
{
    if(nextP(firstP(lp)) == NULL)
    {
        x = firstP(lp);
        firstP(lp) = NULL;
    }
    else
    {
        adrP p = firstP(lp);
        while(nextP(nextP(p))!= NULL)
        {
            p = nextP(p);
        }
        x = nextP(p);
        nextP(p) = NULL;
    }
}
void deleteAfterProduct(listProduct &lp, adrP prec,adrP &x)
{
    x = nextP(prec);
    nextP(prec) = nextP(x);
    nextP(x) = NULL;
}
void deleteProductData(listProduct &lp)
{
    if(firstP(lp) == NULL)
    {
        cout << "List product kosong!" << endl;
    }
    else
    {
        adrP p,x;
        string nama;
        cout << "Masukkan nama product yang ingin dihapus: ";
        cin >> nama;
        p = findProduct(lp,nama);
        if(p != NULL)
        {
            if(p == firstP(lp))
            {
                deleteFirstProduct(lp,x);
            }
            else if(nextP(p) ==  NULL)
            {
                deleteLastProduct(lp,x);
            }
            else
            {
                adrP prec = firstP(lp);
                while(nextP(prec)!=p)
                {
                    prec = nextP(prec);
                }
                deleteAfterProduct(lp,prec,x);
            }
            delete x;
            cout << "Product telah dihapus!" << endl;
        }
        else
        {
            cout << "Product tidak ditemukan!" << endl;
        }
    }
}
void showProductData(listProduct lp)
{
    if(firstP(lp)==NULL)
    {
        cout << "List product kosong" << endl;
    }
    else
    {
        adrP p = firstP(lp);
        int count = 0;
        while(p !=NULL)
        {
            cout << "Nama: " << infoP(p).nama << endl;
            p = nextP(p);
            count++;
        }
        cout << "Total product: " << count << endl;
    }
}
adrR createElmRating(string x)
{
    adrR r = new elmRating;
    nextR(r) = NULL;
    rating(r) = x;
    product(r) = NULL;
    return r;
}
void insertRating(listCustomer &lc, listProduct lp, string username, string nama, adrR r)
{
    adrC c = findCustomerData(lc,username);
    adrP p = findProduct(lp, nama);
    if(p != NULL)
    {
        if(firstR(c)!=NULL)
        {
            nextR(r) = firstR(c);
            prevR(firstR(c)) = r;
            firstR(c) = r;
            product(r) = p;
        }
        else
        {
            firstR(c) = r;
            lastR(c) = r;
            product(r) = p;
        }
    }
    else
    {
        cout << "Tidak ditemukan product!"<<endl;
    }
}
adrR findRating(adrP p, adrC c)
{
    if(firstR(c) == NULL)
    {
        return NULL;
    }
    else
    {
        adrR r = firstR(c);
        while(r!=NULL && product(r)!= p)
        {
            r = nextR(r);
        }
        return r;
    }
}
void deleteFirstRating(adrC &c, adrR &x)
{
    x = firstR(c);
    if(nextR(firstR(c)) == NULL)
    {
        firstR(c) = NULL;
        lastR(c) = NULL;
    }
    else
    {
        firstR(c) = nextR(firstR(c));
        nextR(x) = NULL;
        prevR(firstR(c)) = NULL;
        product(x) = NULL;
    }
}
void deleteLastRating(adrC &c, adrR &x)
{
    x = lastR(c);
    if(nextR(firstR(c)) == NULL)
    {
        firstR(c) = NULL;
        lastR(c) = NULL;
    }
    else
    {
        lastR(c) = prevR(lastR(c));
        nextR(lastR(c)) = NULL;
        prevR(x) = NULL;
        product(x) = NULL;
    }
}
void deleteAfterRating(adrC &c, adrR prec,adrR &x)
{
    x = nextR(prec);
    nextR(prec) = nextR(x);
    prevR(nextR(prec)) = NULL;
    nextR(x) = NULL;
    prevR(x) = NULL;
}
void deleteRatingData(listCustomer &lc, listProduct lp, string nama, string username)
{
    if(firstC(lc) != NULL)
    {
        adrC c;
        c = findCustomerData(lc,username);
        if(c!=NULL)
        {
            if(firstP(lp) != NULL)
            {
                adrP p;
                p = findProduct(lp,nama);
                if(p != NULL)
                {
                    if(firstR(c)!=NULL)
                    {
                        adrR r,x;
                        r = findRating(p,c);
                        if(r != NULL)
                        {
                            if(r == firstR(c))
                            {
                                deleteFirstRating(c,x);
                            }
                            else if(r==lastR(c))
                            {
                                deleteLastRating(c,x);
                            }
                            else
                            {
                                adrR prec = firstR(c);
                                while(nextR(prec) != r)
                                {
                                    prec = nextR(prec);
                                }
                                deleteAfterRating(c,prec,x);
                            }
                        }
                        else
                        {
                            cout << "Belum pernah memberikan rating ke product!" << endl;
                        }
                    }
                    else
                    {
                        cout << "Belum pernah memberikan rating ke product apapun!"<<endl;
                    }
                }
                else
                {
                    cout << "Product tidak ditemukan!" << endl;
                }
            }
            else
            {
                cout << "List product kosong!" << endl;
            }
        }
        else
        {
            cout << "Username customer tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List customer kosong!" << endl;
    }
}
void showRatedProduct(listCustomer lc, string username)
{
    if(firstC(lc) != NULL)
    {
        adrC c;
        c = findCustomerData(lc,username);
        if(c!=NULL)
        {
            if(firstR(c)!=NULL)
            {
                adrR r = firstR(c);
                adrP p;
                while(r!=NULL)
                {
                    p = product(r);
                    cout << "Nama product: " << infoP(p).nama << endl << "Rating: " << rating(r) << endl;
                    r = nextR(r);
                }
            }
            else
            {
                cout << "Belum pernah memberikan rating ke product apapun!" << endl;
            }
        }
        else
        {
            cout << "Username customer tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List customer kosong!" << endl;
    }
}
void showUnratedProduct(listCustomer lc, listProduct lp, string username)
{

    if(firstC(lc) != NULL)
    {
        adrC c;
        c = findCustomerData(lc,username);
        if(c!=NULL)
        {
            if(firstP(lp)!=NULL)
            {
                if(firstR(c)!=NULL)
                {
                    adrP p = firstP(lp);
                    while(p!=NULL)
                    {
                        adrR r = firstR(c);
                        while(r!=NULL && product(r)!=p)
                        {
                            r = nextR(r);
                        }
                        if(r == NULL)
                        {
                            cout << "Nama product: " << infoP(p).nama << endl;
                        }
                        p = nextP(p);
                    }
                }
                else
                {
                    showProductData(lp);
                }
            }
            else
            {
                cout << "List product kosong!" << endl;
            }
        }
        else
        {
            cout << "Username customer tidak ditemukan!" << endl;
        }
    }
    else
    {
        cout << "List customer kosong!" << endl;
    }
}
int menuLogin()
{
    cout << "====== Aplikasi Rating Product ======" << endl;
    cout << "1. Login Admin" << endl;
    cout << "2. Login Customer" << endl;
    cout << "3. Sign Up" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
    int input;
    cin >> input;
    return input;
}
int menuAdmin()
{
    cout << "====== Aplikasi Rating Product ======" << endl;
    cout << "1. Insert data product" << endl;
    cout << "2. Delete data product" << endl;
    cout << "3. Update data product" << endl;
    cout << "4. View data product" << endl;
    cout << "5. Delete data customer" << endl;
    cout << "6. View data customer" << endl;
    cout << "0. Log out" << endl;
    cout << "Pilih: ";
    int input;
    cin >> input;
    return input;
}
int menuUser()
{
    cout << "====== Aplikasi Rating Product ======" << endl;
    cout << "1. Rate product" << endl;
    cout << "2. Edit rating" << endl;
    cout << "3. Delete rating" << endl;
    cout << "4. View rated product" << endl;
    cout << "5. View unrated product" << endl;
    cout << "6. Update account" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih: ";
    int input;
    cin >> input;
    return input;
}
