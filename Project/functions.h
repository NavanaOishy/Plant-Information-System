include<bits/stdc++.h>
using namespace std;
class display
{
public:
    int p;
    //int rev[61][2]={0};
    string displayTreePortalOptions(int Category,int Season)
    {
        int arr[61] = {0};
        system("cls");
        cout<<"Choose plant:"<<endl;
        int count = 1;
        for(int i=1;i<=60;i++)
        {
            if(category_season[i][0]==Category && category_season[i][1]==Season)
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
    string displayTreeByCategory(int Category)
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
    string displayTreeBySeason(int Season)
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
        int i;
        for(i=1;i<=60;i++)
        {
            if(plant[i]==p)break;
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
            cout<<"Information about "<<plant[p]<<":\n\n";
            cout<<"Scientific Name :  "<<scientific_name[p]<<endl;
            cout<<"Family :   "<<family[p]<<endl;
            cout<<"Local Name :    "<<local_name[p]<<endl;
            cout<<"Cultivation Monthn:  "<<cultivation_month[p]<<endl;
            cout<<"Growing Conditions : "<<growing_conditions[p]<<endl;
            cout<<"Soil Type :   "<<soil_type[p]<<endl;
            cout<<"Water Requirement :   "<<water-requirement[p]<<endl;
            cout<<"Temperature :   "<<temperature[p]<<endl;
            cout<<"Diseases :     "<<diseases[p]<<endl;
            cout<<"Diseases Management :     "<<diseases_management[p]<<endl;
        }
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
            int a=(rev[p][0]/(rev[p][0]+rev[p][1]))*100;
            int b=100-a;
            if(a==0&&b==0)cout<<"No riview available"<<endl<<endl;
            else cout << a << " percent users found this information useful and " << b << " percent users did not find this information useful";
        break;
        }
    }
};
