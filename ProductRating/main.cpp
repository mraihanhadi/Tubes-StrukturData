#include <iostream>
#include "app.h"
using namespace std;

int main()
{
    listCustomer lc;
    listProduct lp;
    int pilihan;
    createListCustomer(lc);
    createListProduct(lp);
    pilihan = menuLogin();
    while(pilihan != 0)
    {
        switch(pilihan)
        {
        case 1:
            {
                while(pilihan != 0)
                {
                    pilihan = menuAdmin();
                    switch(pilihan)
                    {
                    case 1:
                        {
                            infotypeP x;
                            adrP p;
                            cout << "Masukkan nama product: ";
                            cin >> x.nama;
                            p = createElmProduct(x);
                            insertProduct(lp,p);
                            break;
                        }
                    case 2:
                        {
                            deleteProductData(lp);
                            break;
                        }
                    case 4:
                        {
                            showProductData(lp);
                            break;
                        }
                    case 5:
                        {
                            adrC x;
                            deleteCustomerData(lc);
                            break;
                        }
                    case 6:
                        {
                            showCustomerData(lc);
                            break;
                        }
                    }
                }
                pilihan = menuLogin();
                break;
            }
        case 2:
            {
                if(firstC(lc) == NULL)
                {
                    cout << "Belum ada akun di list! Silahkan sign up terlebih dahulu!" << endl;
                    pilihan = menuLogin();
                    break;
                }
                else
                {
                    string s;
                    adrC c;
                    cout << "Enter username: ";
                    cin >> s;
                    c = findCustomerData(lc,s);
                    if(c != NULL)
                    {
                        string currentUser = infoC(c).username;
                        while(pilihan != 0)
                        {
                            pilihan = menuUser();
                            switch(pilihan)
                            {
                            case 1:
                                {
                                    string x,p;
                                    adrR r;
                                    cout << "Nama product yang ingin di rating: ";
                                    cin >> p;
                                    cout << "Masukkan rating: ";
                                    cin >> x;
                                    r = createElmRating(x);
                                    insertRating(lc,lp,currentUser,p,r);
                                    break;
                                }
                            case 3:
                                {
                                    string x;
                                    cout << "Nama product yang sudah anda rating yang ingin dihapus: ";
                                    cin >> x;
                                    deleteRatingData(lc,lp,x,currentUser);
                                    break;
                                }
                            case 4:
                                {
                                    showRatedProduct(lc,currentUser);
                                    break;
                                }
                            case 5:
                                {
                                    showUnratedProduct(lc,lp,currentUser);
                                    break;
                                }
                            case 6:
                                {
                                    showCustomerData(lc);
                                    break;
                                }
                            }
                        }
                        pilihan = menuLogin();
                    }
                    else
                    {
                        cout << "Username tidak ditemukan silahkan sign up!" << endl;
                        pilihan = menuLogin();
                        break;
                    }
                }
                break;
            }
        case 3:
            {
                bool valid = false;
                adrC c;
                infotypeC u;
                while(!valid)
                {
                    cout << "Masukkan username baru: ";
                    cin >> u.username;
                    if(findCustomerData(lc,u.username)!=NULL)
                    {
                        cout << "Username telah dipakai! Silahkan inputkan username lagi!"<<endl;
                    }
                    else
                    {
                        valid = true;
                    }
                }
                c = createElmCustomer(u);
                signUp(lc,c);
                cout << "Akun berhasil dibuat! Silahkan login dengan username yang telah dibuat!"<<endl;
                pilihan = menuLogin();
                break;
            }
        pilihan = menuLogin();
        }
    }
    return 0;
}
