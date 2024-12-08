#include<bits/stdc++.h>
using namespace std;
#include "lists.h"
int rev[61][2] = {{0}};
class display
{
public:
    int p;

    int displayTreePortalOptions(int Category,int Season)
    {
        //int arr[61] = {0};
        vector<int>arr;
        arr.push_back(0);
        system("cls");
        cout<<"Choose plant:"<<endl;
        int count = 1;
        for(int i=1;i<=60;i++)
        {
            if(category_season[i][0]==Category && category_season[i][1]==Season)
            {
                cout<<"  "<<count<<" - "<<plant[i]<<endl;
                arr.push_back(i);
                //arr[count] = i;
                count++;
            }
        }
        cin>>p;
        if(p>0&&p<count)
            return arr[p];
        else
        {
            cout << "Invalid choice. Advice selection failed." << endl;
            return 0;
        }
    }
    int displayTreeByCategory(int Category)
    {
        int arr[61] = {0};
        system("cls");
        cout<<"Choose plant:"<<endl;
        int count = 1;
        for(int i=1;i<=60;i++)
        {
            if(category_season[i][0]==Category)
            {
                cout<<"  "<<count<<" - "<<plant[i]<<endl;
                arr[count] = i;
                count++;
            }
        }
        cin>>p;
        if(p>0&&p<count)
            return arr[p];
        else
        {
            cout << "Invalid choice. Advice selection failed." << endl;
            return 0;
        }
    }
    int displayTreeBySeason(int Season)
    {
        int arr[61] = {0};
        system("cls");
        cout<<"Choose plant:"<<endl;
        int count = 1;
        for(int i=1;i<=60;i++)
        {
            if(category_season[i][1]==Season)
            {
                cout<<"  "<<count<<" - "<<plant[i]<<endl;
                arr[count] = i;
                count++;
            }
        }
        cin>>p;
        if(p>0&&p<count)
            return arr[p];
        else
        {
            cout << "Invalid choice. Advice selection failed." << endl;
            return 0;
        }
    }
    int search(string p)
    {
        //transform(p.begin(), p.end(), p.begin(), ::tolower);
        //string str;
        int i=0;
        /*while(p[i]!='\0')
        {
            if(p[i]!=' ')
            {
                p[i]=tolower(p[i]);
            }
            i++;
        }*/

        for(i=1;i<=60;i++)
        {
            if(plant[i]==p)break;
            cout<<p<<" "<<plant[i]<<"\n";
        }
        if(i<=60)return i;
        else return 0;
    }
    void displayInformation(int p)
    {
        system("cls");
        if(p==0)cout<<"Plant information not found"<<endl;
        else
        {
            cout<<"Information about "<<plant[p]<<":\n\n\n";

            cout<<"Season :  "<<season[category_season[p][1]-1]<<"\n\n";
            cout<<"Scientific Name :  "<<scientific_name[p]<<"\n\n";
            cout<<"Family :   "<<family[p]<<"\n\n";
            cout<<"Local Name :    "<<local_name[p]<<"\n\n";
            cout<<"Cultivation Monthn:  "<<cultivation_month[p]<<"\n\n";
            cout<<"Growing Conditions : "<<growing_conditions[p]<<"\n\n";
            cout<<"Soil Type :   "<<soil_type[p]<<endl;
            cout<<"Water Requirement :   "<<water_requirement[p]<<"\n\n";
            cout<<"Temperature :   "<<temperature[p]<<"\n\n";
            cout<<"Diseases :     "<<diseases[p]<<"\n\n";
            cout<<"Diseases Management :     "<<diseases_management[p]<<"\n\n";

            review(p);
        }
        cout << "\n\npress any key to continue or ESC to exit\n";
        if(_getch()==27)exit(0);

    }
    void review(int p)
    {
        int r,o;
        cout << "\nTo give review press 1" << endl << "To see others review press 2" << endl;
        cin>>r;
        switch(r)
        {
        case 1:
            cout << "Did you find this information useful?" << endl << "If yes, press 1" << endl << "If not, press 2" << endl;
            cin>>o;
            if(o==1)
            {
                rev[p][0]++;
            }
            else
            {
                rev[p][1]++;
            }
            cout << endl << endl << "\t\t.......Thanks For Your Review........" << endl;
        break;
        case 2:
            cout << "For the plant : " <<plant[p] <<' '<< endl;
            //int a=(rev[p][0]/(rev[p][0]+rev[p][1]))*100;
            //int b=100-a;
            if(rev[p][0]==0&&rev[p][1]==0)cout<<"No riview available"<<endl<<endl;
            else
            {
                int a=(rev[p][0]/(rev[p][0]+rev[p][1]))*100;
                int b=100-a;
                cout << a << " percent users found this information useful and " << b << " percent users did not find this information useful";
            }
        break;
        }
    }
};

