#include <iostream>

using namespace std;
/*class Duration{

private:
    int arrive_time;
    int leave_time ;
public:
    Duration(int arrive=0,int leave=0){
    arrive_time=arrive;
    leave_time=leave;
    }
    void setArrive_time(int arrive){
    arrive_time=arrive;
    }
    void setLeave_time(int leave){
    leave_time=leave;
    }
    int getArrive_time(){
    return arrive_time;
    }
    int getLeave_time(){
    return leave_time;
    }

};*/
class vehicle
{
public:
    string model_name;
    int ID;
    int model_year;
    //Duration time;
    int location;
    int length;
    int width;

    vehicle(string name=" ",int num=0,int year=0,int len=0,int wid=0)
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
    GarageSlot(int s)
    {
        arr=new char[s];
        for(int i=0; i<40; i++)
        {
            arr[i]='_';
            if(i<20)
            {
                length =200;
                width = 120 ;
            }
            else
                length =240;
                width = 140 ;
        }
    }

    char* arr;
    int siz;
    vehicle* v;
    bool free;
    int counter=0;
    bool addVehicle(vehicle* v)
    {
        this->v = v;
        free = false;
        arr[counter]='*';
        v->location=counter;
        counter++;
        return free;
    }
    bool deleteVehicle(int count)
    {
        free = true;
        arr[count]='_';
        counter--;
    }
    int calulate_totalNum()
    {
        return counter;
    }
};
class slotselection{
    //Garage * objj;
    GarageSlot*d;
public:
    int place = 0;
    int slotselectionn(vehicle ve)
    {
        if (ve.length == 200 &&ve.width==120)
        {
            for(int j=0; j<20; j++)
            {
                if(d->arr[j]=='_')
                {
                    cout<<"slot[" <<j<<"is the best place"<<endl;
                    place = j ;
                    return j;
                }
                else
                    cout << "no place" << endl;
                    place =0;
                    return 0;
            }
        }
        else if (ve.length == 240 && ve.width==140)
        {
            for(int j=20; j<40; j++)
            {
                if(d->arr[j]=='_')
                {
                    cout<<"slot[" <<j<<"]is the best place"<<endl;
                    place = j ;
                    return j;
                }
                else
                    cout << "no place" << endl;
                    place =0;
                    return 0;
            }
        }
    }


};
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
    void parkin(vehicle* v)
    {
        ss->slotselectionn(*v);
        if (ss->place > 0)
        {

        cout<<"enter the arrival time"<<endl;
        cin>>arrive_time;
        slots->addVehicle(v);

        }
        else
            cout<< "sorry noplace for your car"<<endl;

       // obj= v;
       // v->time.setArrive_time(arrive);
    }
    void parkout(vehicle* v)
    {
        cout<<"enter the leave time"<<endl;
        cin>>departure_time;
  //      obj=v;
//        v->time.setLeave_time(departure);
        //dur= Duration(v->time.getArrive_time(),v->time.getLeave_time());
        //total_income+=v->time.getLeave_time()-v->time.getArrive_time();
        dur=departure_time-arrive_time;
        total_income+=departure_time-arrive_time;
        cout<<"the fees"<<dur<<endl;
        slots->deleteVehicle(v->location);
    }
};
class parkingfees
{
public:
//int Duration;
Garage g;
    double print_fees()
    {
        cout<<"the fees"<<g.departure_time-g.arrive_time*5<<endl;//check
        return (g.departure_time-g.arrive_time)*5;//check
    }
};


int main()
{

    string s=" ";
    int siz ;
    int choice;
    string model_name;
    int ID;
    int model_year;
    int length;
    int width;
    cout<<"enter the size of the parking"<<endl;
    cin>>siz;
    Garage p(siz);
    vehicle* veh;

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
            veh=new vehicle(model_name, ID, model_year,length,width);
            p.parkin(veh);
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
            veh=new vehicle(model_name, ID, model_year,length,width);
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
            cout << "The program has been exited successfully.\n";
            return 0;
        }

    }
    while (true);

    return 0;
}
