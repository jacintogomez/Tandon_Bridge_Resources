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
    friend class CreditCard; //give credit card access to debt private member
protected:
    void withdrawfunds(int amt){
        if(balance-amt>=0){
            balance-=amt;
            cout<<"Withdrew $"<<amt<<", new account balance is $"<<balance<<endl;
        }else{
            debt+=20;
            cout<<"Insufficient funds, overdraft fee of $20 is applied"<<endl;
        }
    }
    void depositfunds(int amt){
        if(debt>0){ //first pay off debt
            if(debt>=amt){
                debt-=amt;
                cout<<"Paid off $"<<amt<<" of debt"<<endl;
            }else{
                amt-=debt;
                debt=0;
                cout<<"Paid off all debt"<<endl;
            }
        }
        balance+=amt;
        cout<<"Deposited $"<<amt<<", new account balance is $"<<balance<<endl;
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
    DebitCard(int pin,int an,double b,string fn,string ln):PIN(pin),BankAccount(an,b,fn,ln){}
    int PIN;
    void withdrawal(int pin,int amt){
        if(PIN==pin){withdrawfunds(amt);}
        else{cout<<"Incorrect PIN"<<endl;}
    }
    void deposit(int pin,int amt){
        if(PIN==pin){depositfunds(amt);}
        else{cout<<"Incorrect PIN"<<endl;}
    }
    void display(){
        BankAccount::display(); //call super-class by using scope resolution operator ::
    }
};

class CreditCard{   // adding late fee functionality will require time tracking, so to simplify this example I just have the credit card class add to the account debt
public:             // ..and to access the account debt it needs to be marked as a friend to the BankAccount class, which is done above
    CreditCard(DebitCard* dc):linked_card(dc){}
    DebitCard* linked_card;
    void buy_on_credit(int amt){
        linked_card->adddebt(amt);
    }
};

int main(){
    //BankAccount dk=BankAccount(469200764234,100000,"Daniel","Katz"); //cannot create this on its own, should instead make it along with the debit card object
    DebitCard dc=DebitCard(10001,469200764234,100000,"Daniel","Katz");
    dc.display();
    dc.withdrawal(92305,60); //incorrect PIN rejects the request
    dc.withdrawal(10001,60);
    dc.withdrawal(10001,150000);
    CreditCard cc=CreditCard(&dc);
    cc.buy_on_credit(960);
    cc.buy_on_credit(200);
    dc.deposit(10001,70);
    dc.deposit(10001,50000);
    return 0;
}