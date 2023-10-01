#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date{
public:
    Date(int m,int d,int y):day(d),month(m),year(y){}
    int day;
    int month;
    int year;
    vector<int> months={31,28,31,30,31,30,31,31,30,31,30,31};
    int gregorian(int m,int y){
        if(m==2&&((y%4==0&&y%100!=0)||y%400==0)){return 29;}
        else{return months[m];}
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
    Date& operator+=(const int& inc){
        int limit=gregorian(month,year);
        int res=day+inc;
        if(res<=limit){day=res;}

    }
    void operator>(const int inc){
        int res=inc+month;
        month=res%12;
        year+=res/12;
    }
    void operator>>(const int inc){
        year+=inc;
    }
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
    Date usa(7,4,1776);
    usa++;
    return 0;
}