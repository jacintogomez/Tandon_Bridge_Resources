#include <iostream>
#include <vector>
using namespace std;

class Date{
public:
    Date():day(1),month(1),year(0){}
    Date(const Date& d):day(d.day),month(d.month),year(d.year){}
    Date(int m,int d,int y){
        int limit;
        if(m>0&&m<=12){
            month=m;
        }else{month=1;}
        limit=gregorian(month,y);
        if(d>0&&d<=limit){day=d;}
        else{day=1;}
        year=y;
    }
    int day;
    int month;
    int year;
    vector<int> months={31,28,31,30,31,30,31,31,30,31,30,31};
    int gregorian(int m,int y){
        if(m==2&&((y%4==0&&y%100!=0)||y%400==0)){return 29;}
        else{return months[m-1];}
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
        return *this; //return original
    }
    Date operator++(int){ //post-increment
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
    Date& operator+=(const int& inc){ //increment day
        int ref=inc;
        while(ref>0){
            ++(*this);
            --ref;
        }
        return *this;
    }
    bool operator==(const Date& o) const{
        return year==o.year&&month==o.month&&day==o.day;
    }
    //subtract two dates, resulting the number of days between them
    int operator-(const Date& other) const{
        if(year<other.year||(year==other.year&&month<other.month||(month==other.month&&day<other.day))){
            cout<<"Invalid operation"<<endl;
            return -1;
        }
        Date copy=other;
        int count=0;
        while(!(*this==copy)){
            ++copy;
            ++count;
        }
        return count;
    }
    //index a date, where [0] gives the month, [1] gives the day, and [2] gives the year of that date
    int operator[](int index) const{
        if(index==0){return month;}
        else if(index==1){return day;}
        else if(index==2){return year;}
        else{
            cout<<"Index out of bounds"<<endl;
            return -1;
        }
    }
    //the overloaded variables don't have to be used for their original function,
    //below is an example of overloading > to increment a month, and overloading >> to increment a year
    void operator>(const int inc){ //increment month
        int res=inc+month;
        month=res%12;
        year+=res/12;
    }
    void operator>>(const int inc){ //increment year
        year+=inc;
    }
    //read in input
    friend istream& operator>>(istream& is,Date& d){
        cout<<"month: ";
        is>>d.month;
        cout<<"day: ";
        is>>d.day;
        cout<<"year: ";
        is>>d.year;
        return is;
    }
    //format output
    friend ostream& operator<<(ostream& os,const Date& d){
        os<<"("<<d.month<<"/"<<d.day<<"/";
        if(d.year>0){os<<d.year<<")";}
        else{os<<-1*d.year<<"B.C.)";}
        return os;
    }
};

int main(){
    Date nyu(4,18,1831);
    cout<<"date NYU was founded: "<<nyu<<endl;
    Date newmillennium(12,31,-1999);
    cout<<newmillennium<<" is pre-incremented to "<<++newmillennium<<endl;
    Date wwiiend(9,1,1945);
    cout<<wwiiend++<<" is post-incremented to "<<wwiiend<<endl;
    cout<<"WWII ended in "<<wwiiend[2]<<endl;
    Date input;
    cout<<"enter today's date: "<<endl;
    cin>>input;
    cout<<"today is "<<input<<endl;
    cout<<"days since the NYU was founded: "<<input-nyu;
    return 0;
}