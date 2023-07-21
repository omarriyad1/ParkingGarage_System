#include <iostream>

using namespace std;
class vehicle
{
public:
    string model_name;
    int ID;
    int model_year;
    int location;
    int length;
    int width;

    vehicle()
    {
        std::string name=" ";
        int num=0;
        int year=0;
        int len=0;
        int wid=0;
    }
    vehicle(std::string name,int num,int year,int len,int wid)
    {

        model_name=name;
        ID=num;
        model_year=year;
        length=len;
        width=wid;
    }
    void  setVehicle(std::string name,int num,int year,int len,int wid)
    {
        model_name=name;
        ID=num;
        model_year=year;
        length=len;
        width=wid;
    }

};
class GarageSlot
{
public:
    int length ;
    int width ;
    int x;

    char* grageslots;
    GarageSlot()
    {

    }
    GarageSlot(int m)
    {
        grageslots=new char[m];
        for(int i=0; i<m; i++)
        {
            grageslots[i]='_';
            x = m / 2 ;
            if(i<x)
            {
                length =200;
                width = 120 ;
            }
            else
            {
                length =240;
                width = 140 ;
            }

        }
    }


    int siz;
    vehicle* v;
    bool free;
    int counter=0;
    bool addVehicle(vehicle v)
    {
        // this->v = v;
        free = false;
        grageslots[counter]='*';
        v.location=counter;
        counter++;
        return free;
    }
    bool deleteVehicle(int count)
    {
        free = true;
        grageslots[count]='_';
        counter--;
    }
    int calulate_totalNum()
    {
        return counter;
    }
};
class slotselection
{
    GarageSlot*d;
    int vfin =2*(d->x);
public:
    slotselection()
    {
        d=new GarageSlot();
    }
    int place = -1;
    int slotselect(vehicle ve, GarageSlot *g)
    {
        d=g;
        if (ve.length <= 200 &&ve.width<=120)
        {
            for(int j=0; j< d->x; j++)
            {
                if(d->grageslots[j]=='_')
                {
                    cout<<"slot[" <<j+1<<"]is the best place"<<endl;
                    place = j ;
                    return j;
                }
            }
        }
        else if (ve.length <= 240 &&ve.width<=140)
        {
            for(int j=d->x; j< vfin; j++)
            {
                if(d->grageslots[j]=='_')
                {
                    cout<<"slot[" <<j<<"]is the best place"<<endl;
                    place = j ;
                    return j;
                }
            }
        }
        else
        {

            cout << "no place" << endl;
            place =0;
            return 0;
        }


    }
} ;



class Garage
{
public:
    Garage(int s)
    {
        this->slots=new GarageSlot(s);
    }
    vehicle* obj;
    GarageSlot* slots;
    slotselection* ss;
    int dur;
    int arrive_time,departure_time;
    //parkingfees pay;
    double total_income=0;
    void parkin(vehicle v,int x)
    {
        if(v.length>240 ||v.width>140)
        {
            throw x;
        }
        else
        {
            ss->slotselect(v,slots);
            if (ss->place >= 0)
            {

                cout<<"enter the arrival time"<<endl;
                cin>>arrive_time;
                slots->addVehicle(v);

            }
            else
                cout<< "sorry no place for your car"<<endl;

        }
    }
    void displayavailableslots()
    {
        for (int i =0;i<(2*slots->x);i++)
        {
            cout << slots->grageslots[i]<<"  " ;
        }

    }
    void parkout(vehicle v)
    {
        cout<<"enter the leave time"<<endl;
        cin>>departure_time;
        dur=departure_time-arrive_time;

        if(v.length<=200&&v.width<=120)
        {
            cout<<"the fees"<<dur*10<<endl;
            total_income+=(departure_time-arrive_time)*10;
            slots->deleteVehicle(v.location);
        }
        else
        {
            cout<<"the fees"<<dur*20<<endl;
            total_income+=(departure_time-arrive_time)*20;
            slots->deleteVehicle(v.location);
        }
        ;
    }
};
class parkingfees
{
public:
    Garage g;
    vehicle v;
    double print_fees()
    {
        if(v.length<=200&&v.width<=120)
        {
            cout<<"the fees"<<g.departure_time-g.arrive_time*10<<endl;
            return (g.departure_time-g.arrive_time)*10;
        }
        else
        {
            cout<<"the fees"<<g.departure_time-g.arrive_time*20<<endl;
            return (g.departure_time-g.arrive_time)*20;
        }

    }
};


int main()
{

    string s=" ";
    int siz ;
    int choice;
    std::string model_name;
    int ID;
    int model_year;
    int length;
    int width;
    cout<<"enter the size of the parking"<<endl;
    cin>>siz;
    Garage p(siz);
    vehicle veh;

    do
    {
        cout << "Choose from the menu: \n" <<
             "1- Park in new vehicle.\n" <<
             "2- Park out a vehicle.\n" <<
             "3- Get the total income till now.\n" <<
             "4- Get the total number of vehicles till now\n" <<
             "5- Display the available slots.\n" <<
             "6- Exit.\n";
        cout << "Choice: ";
        cin >> choice;
        if (choice==1)

        {
            cout << "Enter the vehicle's model name: ";
            cin >> model_name;
            cout << "Enter the vehicle's ID: ";
            cin >> ID;
            cout << "Enter the vehicle's model year: ";
            cin >> model_year;
            cout << "Enter the vehicle's length: ";
            cin >> length;
            cout << "Enter the vehicle's width: ";
            cin >> width;

            veh.setVehicle(model_name, ID, model_year,length,width);
            try
            {
                p.parkin(veh,0);
            }
            catch(...)
            {
                cout<<"sorry there is no place for your car"<<endl;
            }
        }
        else if (choice==2)
        {
            cout << "Enter the vehicle's model name: ";
            cin >> model_name;
            cout << "Enter the vehicle's ID: ";
            cin >> ID;
            cout << "Enter the vehicle's model year: ";
            cin >> model_year;
            cout << "Enter the vehicle's length: ";
            cin >> length;
            cout << "Enter the vehicle's width: ";
            cin >> width;
            veh.setVehicle(model_name, ID, model_year,length,width);
            p.parkout(veh);
        }
        else if (choice==3)
        {
            cout << "The total income: " << p.total_income << " EGP\n";
        }
        else if (choice==4)
        {
            cout << "The total number of vehicles used the parking garage is: " << p.slots->calulate_totalNum()<< endl;
        }
        else if (choice==5)
        {
            p.displayavailableslots();
            return 0;
        }
        else if (choice==6)
        {
            cout << "The program has been exited successfully.\n";
            return 0;
        }

    }
    while (true);

    return 0;
}
