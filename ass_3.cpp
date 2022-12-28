#include <iostream>
#include <string.h>
using namespace std;

class publication
{
private:
    float price;
    string title;

public:
    publication()
    {
        price = 0.0;
        title = " ";
    }
    void get_data()
    {
        cout << "Enter the Title : ";
        cin.ignore();
        getline(cin,title);
        cout << "Enter the Price : ";
        cin >> price;
    }

    void put_data()
    {

        cout << "\nTitle : " << title;
        cout << "\nPrice : " << price;
    }
};

class book : public publication
{
private:
    int pages;

public:
    book()
    {
        pages = 0;
    }
    void get_data()
    {
        publication::get_data();
        cout << "Enter the page count : ";
        cin >> pages;
    }
    void put_data()
    {
        publication::put_data();
        try
        {
            if (pages == 0 || pages < 0)
                throw pages;
        }
        catch (int f)
        {
            cout << "\n Error:Pages Not Valid.";
            pages = 0;
        }
        cout << "\n Pages are :" << pages;
    }
};

class tape : public publication
{
private:
    float min;

public:
    tape()
    {
        min = 0.0;
    }
    void get_data()
    {
        publication::get_data();
        cout << "Enter Play time of Cassette : ";
        cin >> min;
    }
    void put_data()
    {
        publication::put_data();
        try
        {
            if (min < 0.0)
            {
                throw min;
            }
        }
        catch (float r)
        {
            cout << "\nError:Invalid playtime : ", min;
            min = 0.0;
        }
        cout << "\nPlaytime is : " << min;
    }
};

int main()
{
    book b[10];
    tape t[10];

    int choice = 0, bookcount = 0, tapecount = 0;
    cout << "--------------------";
    do
    {
        cout << "\n 1. Add book ";
        cout << "\n 2. Add tape: ";
        cout << "\n 3. Display book ";
        cout << "\n 4. Display tape";
        cout << "\n 5. Exit:" << endl;
        cout << "\n Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            b[bookcount].get_data();
            bookcount++;
            break;
        case 2:
            t[tapecount].get_data();
            tapecount++;
            break;
        case 3:
            for (int i = 0; i < bookcount; i++)
            {
                b[i].put_data();
            }
            break;
        case 4:
            for (int i = 0; i < tapecount; i++)
            {
                t[i].put_data();
            }
            break;
        case 5:
            cout << "Program Exited Successfully";
            break;
        default:
            break;
        }
    } while (choice != 5);
    return 0;
}