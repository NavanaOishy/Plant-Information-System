#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include "user.h"
#include "plant_info.h"
using namespace std;
int main()
{
    user u;
    display pi;
    int Category,Season,choice,s,i;
    char y,z,c;
    string Plant="",a;
    u.loadUserData();
    while(true)
    {
        if (!loggedIn)
        {
            u.displayMenu();
            cin >> choice;
            switch (choice) {
                case 1:
                    u.login();
                    break;
                case 2:
                    u.registerUser();
                    break;
                case 3:
                    u.saveUserData();
                    cout << "Exiting...\n";
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        }
        else
        {
            system("cls");
            cout << "\n===================== Welcome to ==================\n";
            cout << "\n=============== Plant Database System ==============\n";
            cout << "Choose Plant By : "<<endl;
            cout <<"  1 - Type"<<endl;
            cout <<"  2 - Season"<<endl;
            cout <<"  3 - Name"<<endl;
            y=0;
            cin>>y;
            switch(y)
            {
                case '1':
                    cout << "Choose Your Plant Category: "<<endl;
                    for(i=1;i<=5;i++)
                    {
                        cout<<" "<<i<<" - "<<category[i-1]<<endl;
                    }

                    cin >>Category;

                    cout<<"\nDo you want to filter by season?\n"<<endl;
                    cout<<" 1 - Yes"<<endl;
                    cout<<" 2 - No"<<endl;
                    cin>>z;
                    if(z == '1')
                    {
                        cout << "Choose Season: "<<endl;
                        for(i=1;i<=3;i++)
                        {
                            cout<<" "<<i<<" - "<<season[i-1]<<endl;
                        }
                        cin>>Season;
                        s=pi.displayTreePortalOptions(Category, Season);
                        pi.displayInformation(s);
                    }
                    else
                    {
                        //show all seasons of a category
                        s=pi.displayTreeByCategory(Category);
                        pi.displayInformation(s);
                    }
                break;
                case '2':
                    cout << "Choose Your Plant Season: "<<endl;
                    for(i=1;i<=3;i++)
                    {
                        cout<<" "<<i<<" - "<<season[i-1]<<endl;
                    }

                    cin >>Season;

                    cout<<"\nDo you want to filter by plant type?\n"<<endl;
                    cout<<" 1 - Yes"<<endl;
                    cout<<" 2 - No"<<endl;
                    cin>>z;
                    if(z == '1')
                    {
                        cout << "Choose Category: "<<endl;
                        for(i=1;i<=5;i++)
                        {
                            cout<<" "<<i<<" - "<<category[i-1]<<endl;
                        }
                        cin>>Category;
                        s=pi.displayTreePortalOptions(Category, Season);
                        pi.displayInformation(s);
                    }
                    else
                    {
                        //show all seasons of a season
                        s=pi.displayTreeBySeason(Season);
                        pi.displayInformation(s);
                    }
                break;
                case '3':
                    cout<<" Enter the plant name:"<<endl;
                    while(cin>>a)
                    {
                        Plant=Plant+a+" ";
                    }
                    Plant.resize(Plant.size()-1);
                    s = pi.search(Plant);
                    pi.displayInformation(s);
                break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                    cout << "\n\npress any key to continue\n";
                    _getch();
                break;
            }
        }
    }
    return 0;
}

