#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define USER_DB_FILE "user_db.txt"
using namespace std;
int numUsers = 0;
int loggedIn = 0;
class user
{
public:
    string username[MAX_USERNAME_LENGTH];
    string password[MAX_PASSWORD_LENGTH];
    string name,pass;

    void displayMenu()
    {
        system("cls");  // Clear the screen
        cout << "\n===================== Welcome to ==================\n";
        cout << "\n===============  Plant Information System ===============" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "=================================================" << endl;
        cout << "Enter your choice (1-3): ";
    }
    void loadUserData()
    {
        ifstream file(USER_DB_FILE);
        if (!file)
        {
            cout << "No user data found." << endl;
            return;
        }

        numUsers = 0;
        while (file >> username[numUsers] >> password[numUsers])
        {
            numUsers++;
        }

        file.close();
    }
    void saveUserData()
    {
        ofstream file(USER_DB_FILE);
        if (!file)
        {
            cout << "Error saving user data." << endl;
            return;
        }

        for (int i = 0; i < numUsers; i++)
        {
            file << username[i] << " " << password[i] << endl;
        }

        file.close();
    }
    int authenticateUser(string name, string  pass)
    {
        for (int i = 0; i < numUsers; i++)
        {
            if ((username[i] == name) && (password[i] == pass))
            {
                return 1;  // User authenticated
            }
        }

        return 0;  // User not found or invalid credentials
    }

    void registerUser()
    {
        system("cls");  // Clear the screen
        cout << "\n=============== User Registration ===============" << endl;
        cout << "Enter a username: ";
        cin >> name;
        cout << "Enter a password: ";
        cin >> pass;

        for (int i = 0; i < numUsers; i++)
        {
            if (username[i] == name)
            {
                cout << "Username already exists. Registration failed." << endl;
                return;
            }
        }

        username[numUsers] = name;

        password[numUsers] = pass;
        numUsers++;

        cout << "Registration successful." << endl;
        cout << "Press any key to continue or ESC to exit.";

        if (_getch() == 27)
        {
            saveUserData();
            cout << "Exiting..." << endl;
            exit(0);
        }
    }

    void login()
    {
        system("cls");  // Clear the screen
        cout << "\n================ User Login ===================" << endl;
        cout << "Enter your username: ";
        cin >> name;
        cout << "Enter your password: ";
        cin >> pass;

        int isAuthenticated = authenticateUser(name, pass);

        if (isAuthenticated)
        {
            cout << "Login successful." << endl;
            loggedIn = 1;
            //_getch();  // Wait for user input
        }
        else
        {
            cout << "Login failed. Invalid username or password." << endl;
            loggedIn = 0;
            cout<<"\nPress any key to continue\n";
            _getch();  // Wait for user input
        }
    }
    friend class display;
};
