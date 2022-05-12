
#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

class book

{
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;

public:
    book()
    {
        author = new char[20];
        title = new char[20];
        publisher = new char [20];
        price = new float;
        stock = new int;
    }
    void feed_data();
    void edit_data();
    void show_data();
    int search(char[], char[]);
    void buy_book();
};
void book::feed_data()
{
    cin.ignore();
    cout <<"\n Enter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;

}
void book::edit_data()
{
    cout << "\n Enter Author Name: ";
    cin.getline(author, 20);
    cout << "Enter Title Name: ";
    cin.getline(title, 20);
    cout << "Enter Publisher Name: ";
    cin.getline(publisher, 20);
    cout << "Enter Price: ";
    cin >> *price;
    cout << "Enter Stock Position: ";
    cin >> *stock;
}
void book::show_data()
{
        cout << "\n Author Name: " << author;
        cout << "\n Title Name: " << title;
        cout << "\n Publisher Name: " << publisher;
        cout << "\n Price: " << price;
        cout << "\nStock Position: " << *stock;
}
int book::search(char t_buy[20], char a_buy[20])
    {
        if(strcmp(t_buy, title) == 0 && strcmp(a_buy, author) == 0)
            return 1;
        else
            return 0;
    }
void book::buy_book()
{
    int count;
    cout << "\n Enter Number of Books to Buy: ";
    cin >> count;
    if (count <= *stock)
    {
        *stock=*stock - count;
        cout << "\n Books Bought Sucessfully";
        cout << "\n Amount: Rs. " << (*price)*count;
    }
    else
        cout << "\n Required Copies not in Stock";
}
int main()
{
    book *B[20];
    int i = 0, r, t = 0, choice;
    char title_buy[20], author_buy[20];
    while(1)
    {
        cout << "\n\n\t Menu" << "\n1. Entry New Book"
        << "\n2. Buy Book "
        << "\n3. Search for Book"
        << "\n4. Edit Detail of Book"
        << "\n5. Exit"
        << "\n\n Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: B[i] = new book;
                B[i]->feed_data();
            i++;   break;
            case 2: cin.ignore();
            cout << "\n Enter Title of Book: ";
            cin.getline(title_buy, 20);
            cout << "Enter Author of Book: ";
            cin.getline(author_buy, 20);
            for(t=0; t<i; t++)
                if(B[t] ->search(title_buy, author_buy))
                {
                    B[t]->buy_book();
                    break;
                }
            if(t==1)
                cout << "\nTHis Book is Not in Stock";
            break;
            case 3: cin.ignore();
            cout << "\nEnter Title of Book: ";
            cin.getline(title_buy, 20);
            cout << "Enter Author of Book: ";
            cin.getline(author_buy, 20);
            for(t=0;t<i;t++)
            {
                if(B[t] ->search(title_buy, author_buy))
                {
                    cout << "\nBook Found Successfully ";
                    B[t]->show_data();
                    break;
                }
            }
            if(t==i)
            {
                cout << "\nThis Book is Not in Stock ";
                break;
            }
            case 4: cin.ignore();
            cout << "\nEnter Title of Book: ";
            cin.getline(title_buy, 20);
            cout << "Enter Author of Book: ";
            cin.getline(author_buy, 20);
            for(t=0; t<1; t++)
            if(B[t] ->search(title_buy, author_buy))
            {
                cout << "\n Book Found Successfully ";
                B[t]->edit_data();
                break;
                case 5: exit(0);
                default: cout << "\n Invalid Choice Entered";

            }

        }
        return 0;

    }
