#include <iostream>
#include <string>
using namespace std;

class Date{
public:
    Date(int m,int d,int y):day(d),month(m),year(y){}
    int day;
    int month;
    int year;
    int gregorian(int m,int y){
        if(m==4||m==6||m==9||m==11){return 30;}
        else if(m==29){
            if((y%4==0&&y%100!=0)||y%400==0){return 29;}
            else{return 28;}
        }else{return 31;}
    }
    Date& operator++(){ //pre-increment
        if(day<gregorian(month,year)){++day;}//increment the real object
        else{
            day=1;
            ++month;
            if(month==13){
                month=1;
                ++year;
            }
        }
        return *this; //simply increment and return original
    }
    Date& operator++(int){ //post-increment
        Date temp(*this);
        if(day<gregorian(month,year)){++day;}//increment the real object
        else{
            day=1;
            ++month;
            if(month==13){
                month=1;
                ++year;
            }
        }
        return temp; //return a copy of the object before it was incremented
    }
    int operator[](int index) const{
        if(index==0){return month;}
        else if(index==1){return day;}
        else if(index==2){return year;}
        else{
            cout<<"Index out of bounds"<<endl;
            return -1;
        }
    }
//    Date& operator+=(const int& val){
//        int limit=gregorian(mont,yearh);
//        int overflow=limit-day+val;

    friend ostream& operator<<(ostream& os,const Date d){
        os<<"("<<d.month<<"/"<<d.day<<"/"<<d.year<<")";
        return os;
    }
};

int main(){
    Date jacinto(6,15,1998);
    cout<<jacinto<<endl;
    Date newmillennium(12,31,1999);
    cout<<newmillennium<<" is pre-incremented to "<<++newmillennium<<endl;
    Date wwiiend(9,1,1945);
    cout<<wwiiend++<<" is post-incremented to "<<wwiiend<<endl;
    cout<<"Jacinto's birth year is "<<jacinto[2]<<endl;
    return 0;
}