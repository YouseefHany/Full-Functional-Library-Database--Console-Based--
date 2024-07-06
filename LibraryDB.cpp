/*
CODED BY :
  █████╗    ██████╗     █████╗
 ██╔══██╗  ██╔═══██╗   ██╔══██╗
 ╚█████╔╝  ██║   ██║   ╚█████╔╝
 ██╔══██╗  ██║   ██║   ██╔══██╗
 ╚█████╔╝  ╚██████╔╝   ╚█████╔╝
  ╚════╝    ╚═════╝     ╚════╝
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

#define GoodThings ios_base::sync_with_stdio(0);
#define Are cin.tie(0);
#define Coming cout.tie(0);



/*


                                                  Surah Al-Mu'minun Verses [ 84 -> 89 ]

                        Say, [O Muhammad], "To whom belongs the earth and whoever is in it, if you should know?" (84)
                        They will say, "Allah's". Ask them, "Then why do you not understand this"? (85)
                        Say, "Who is Lord of the seven heavens and Lord of the Great Throne?" (86)
                        They will say, "[They belong] to Allah." Say, "Then will you not fear Him?" (87)
                        Say, "In whose hand is the realm of all things - and He protects while
                        none can protect against Him - if you should know?" (88)
                        They will say, "[All belongs] to Allah." Say, "Then how are you deluded?" (89)

*/


void menu()
{
    cout << "Library Menu\n\n";
    cout << "1 ) Add a book\n";
    cout << "2 ) Search for a book using PREFIX Method\n";
    cout << "3 ) Add a user\n";
    cout << "4 ) Let a user borrow a book\n";
    cout << "5 ) Let a user return a book\n";
    cout << "6 ) Print the whole library by IDs\n";
    cout << "7 ) Print the whole library by NAMEs\n";
    cout << "8 ) Print who borrowed a book by its Name\n";
    cout << "9 ) EXIT\n";
    cout << endl << "Enter your choice [1-9] : ";
}

void more()
{
    cout << endl;
    for (int i = 0; i <= 2; i++) {cout << "~"; Sleep(300);}
    cout << " Would you like to do something else ?\n\n";
    Sleep (1000);
}

struct Books_data
{
    int id;
    string name;
    int quantity;

    void Read_Books()
    {
        cin >> id >> name >> quantity;
    }
};


struct Users_Data
{
    int id;
    string name;
    vector<Books_data> books_borrowed;

    void Read_Users()
    {
        cin >> id >> name;
    }

};


bool name_comp(const Books_data &a, const Books_data &b) {
    return a.name < b.name;
}

bool ID_comp(const Books_data &a, const Books_data &b) {
    return a.id < b.id;
}

bool user_name_comp(const Users_Data &a, const Users_Data &b) {
    return a.name < b.name;
}

bool user_ID_comp(const Users_Data &a, const Users_Data &b) {
    return a.id < b.id;
}





int main()
{
    // GoodThings Are Coming
    cout << "Welcome to ur most humble Library Database Program <3 \n\n\n";

    vector<Books_data> books;
    vector<Users_Data> users;

    while(true)
    {
        menu();
        int choice; cin >> choice;
        Books_data book;
        Users_Data user;

        if (choice == 1)    // add a book
        {
            cout << "\n Enter ID, name, Quantity:";
            Books_data book;
            book.Read_Books();
            books.push_back(book);
            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl << "Book -> [" << book.id << "] : " << book.name << " With Qty ( " << book.quantity << " ) Added Sucessfully !\n";
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 2)   // book search
        {
            cout << "\n\n Enter a prefix for the requested book to search for :";
            string prf; cin >> prf;

            {
                cout << "\n  Searching";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }
            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            if (books.empty())
            {
                cout << "\n[-X-] No Books Available at all\n";
                continue;
            }
            else
            {
                cout << "\nBooks Found : \n";
                for (int i = 0; i < books.size(); i++)
                {
                    bool found = false;
                    string tmp(books[i].name.begin(), books[i].name.begin() + prf.size());

                    if (tmp == prf)
                    {
                        cout << "[" << books[i].id << "] " << books[i].name << " Qty ( " << books[i].quantity << " )" << endl;

                        found = true;
                    }


                    if (!found)
                    {
                        cout << "[-X-] No Books Found\n";

                    }
                }
            }
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 3)   // add a user
        {
            cout << "\n Enter ID, Name:";
            Users_Data user;
            user.Read_Users();
            users.push_back(user);

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}

            cout << endl << "User -> [" << user.id << "] : " << user.name << " Added Sucessfully !\n";

            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 4)   // user borrows a book
        {
            cout << "Enter user's ID: ";
            int user_id;    cin >> user_id;

            cout << "Enter book's ID: ";
            int book_id;    cin >> book_id;


            {
                cout << "\n\n  Requesting a Books DataBase Check";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}

            int user_index = -1;
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].id == user_id)
                {
                    user_index = i;
                    break;
                }
            }

            int book_index = -1;
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].id == book_id)
                {
                    book_index = i;
                    break;
                }
            }

            if (user_index != -1 && book_index != -1)
            {
                if (books[book_index].quantity > 0)
                {
                    users[user_index].books_borrowed.push_back(books[book_index]);
                    books[book_index].quantity--;
                    cout << "\nBook borrowed successfully !\n";
                }
                else
                {
                    cout << "\nBook out of stock !\n";
                }
            }
            else
            {
                cout << "\nInvalid user or book ID.\n";
            }
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 5)   // user returns a book
        {
            cout << "Enter user's ID: ";
            int user_id;    cin >> user_id;

            cout << "Enter book's ID: ";
            int book_id;    cin >> book_id;

            {
                cout << "\n\n  Requesting a Books DataBase Check";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}


            int user_index = -1;
            for (int i = 0; i < users.size(); i++)
            {
                if (users[i].id == user_id)
                {
                    user_index = i;
                    break;
                }
            }

            if (user_index != -1)
            {
                int book_index = -1;
                for (int i = 0; i < users[user_index].books_borrowed.size(); i++) {
                    if (users[user_index].books_borrowed[i].id == book_id) {
                        book_index = i;
                        break;
                    }
                }

                if (book_index != -1)
                {
                    for (int i = 0; i < books.size(); i++)
                    {
                        if (books[i].id == book_id)
                        {
                            books[i].quantity++;
                            break;
                        }
                    }
                    users[user_index].books_borrowed.erase(users[user_index].books_borrowed.begin() + book_index);
                    cout << "\nBook returned successfully !\n";
                }
                else
                {
                    cout << "\nUser did not borrow this book !\n";
                }
            }
            else
            {
                cout << "\nInvalid user or book ID !\n";
            }

            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 6)   // print users and books by ID
            {

            {
                cout << "\n\n  Requesting a Books DataBase Check";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}

            cout << "\nThe Whole users list :\n";
            sort(users.begin(), users.end(), user_ID_comp);
            for (int i = 0; i < users.size(); i++)
            {
                cout << users[i].id << " " << users[i].name << endl;
            }

            cout << "\n\nThe whole books list :\n";
            sort(books.begin(), books.end(), ID_comp);
            for (int i = 0; i < books.size(); i++)
            {
                cout << books[i].id << " " << books[i].name << " " << books[i].quantity << "\n";
            }
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 7)   // print users and books by name
        {
            {
                cout << "\n\n  Requesting a Books DataBase Check";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}

            cout << "\nThe Whole users list:\n";
            sort(users.begin(), users.end(), user_name_comp);
            for (int i = 0; i < users.size(); i++)
            {
                cout << users[i].id << " " << users[i].name << endl;
            }

            cout << "\n\nThe whole books list:\n";
            sort(books.begin(), books.end(), name_comp);
            for (int i = 0; i < books.size(); i++)
            {
                cout << books[i].id << " " << books[i].name << " " << books[i].quantity << "\n";
            }

            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 8)   // print users who borrowed a specific book
        {
            cout << " Enter The Book's name: ";
            string book_name;   cin >> book_name;

            {
                cout << "\n\n  Searching";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << endl;
            }

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}

            cout << "\nUsers who borrowed the book:\n";
            bool found = false;
            for (int i = 0; i < users.size(); i++)
            {
                for (int j = 0; j < users[i].books_borrowed.size(); j++)
                {
                    if (users[i].books_borrowed[j].name == book_name)
                    {
                        cout << users[i].id << " " << users[i].name << endl;
                        found = true;
                    }
                }
            }
            if (!found)
            {
                cout << "\nNo user has borrowed this book !\n";
            }

            for (int i = 0; i < 45; i++) {cout << "="; Sleep (1);}
            cout << endl;
            more();
        }
        else if (choice == 9)
        {
            cout << "Thanks for using an 808 Software <3";
            cout << "\n\nCould you rate the work out of 10 plz ????\n";
            cout << "Rate :";
            double rate;    cin >> rate;
            cout << "\nRate : " << rate;
            cout << "\nThank you so much <3\n\n\n you can go now !";
            Sleep(100000);
            break;
        }
    }
}