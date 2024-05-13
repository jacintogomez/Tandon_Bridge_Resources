//
// Created by Jacinto Gomez on 5/12/24.
//

#include <iostream>
using namespace std;

class BankAccount{
public:
    BankAccount(const BankAccount& ba):account_num(ba.account_num),balance(ba.balance),firstname(ba.firstname),lastname(ba.lastname){}
    BankAccount(int an,double b,string fn,string ln):account_num(an),balance(b),firstname(fn),lastname(ln){}
    string firstname;
    string lastname;
    void display(){cout<<firstname<<" "<<lastname<<"'s acccount"<<endl;}
    friend class CreditCard;
protected:
    void withdrawfunds(int amt){
        if(balance-amt>=0){
            balance-=amt;
            cout<<"Withdrew $"<<amt<<", new account balance is $"<<balance<<endl;
        }else{
            cout<<"Insufficient funds"<<endl;
        }
    }
    void adddebt(int amt){
        if(debt+amt<=maxdebt){
            debt+=amt;
            cout<<"$"<<amt<<" added to credit, available credit is now $"<<maxdebt-debt<<endl;
        }else{
            cout<<"Not enough available credit"<<endl;
        }
    }
private:
    int account_num;
    double balance;
    double debt=0; //begin with no debt
    double maxdebt=1000;
};

class DebitCard:public BankAccount{
public:
    DebitCard(int pin,int an,double b,string fn,string ln):PIN(pin), BankAccount(an,b,fn,ln){}
    int PIN;
    void withdrawal(int pin,int amt){
        if(PIN==pin){
            withdrawfunds(amt);
        }else{
            cout<<"Incorrect PIN"<<endl;
        }
    }
    void display(){
        BankAccount::display(); //call super-class by using scope resolution operator ::
    }
};

class CreditCard{
public:
    CreditCard(DebitCard* dc):linked_card(dc){}
    DebitCard* linked_card;
    void buy_on_credit(int amt){
        linked_card->adddebt(amt);
    }
};

int main(){
    //BankAccount dk=BankAccount(469200764234,100000,"Daniel","Katz");
    DebitCard dc=DebitCard(10001,469200764234,100000,"Daniel","Katz");
    dc.display();
    dc.withdrawal(92305,60); //incorrect PIN rejects the request
    dc.withdrawal(10001,60);
    dc.withdrawal(10001,150000);
    CreditCard cc=CreditCard(&dc);
    cc.buy_on_credit(960);
    cc.buy_on_credit(200);
    return 0;
}