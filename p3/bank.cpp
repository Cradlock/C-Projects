#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <math.h>
#include <sstream>




using std::string;
using std::cin;
using std::cout;
using std::endl;

const char create = 'c';
const int cash = 2;
const int top_up_balanc = 3;
const int info = 4;
const char delete_card='x';
const char exit_card = 'd';



struct Card{
private:
    int id;
    unsigned int password;
    unsigned long long money;
public:
    Card(){
         this->id = -1;
         this->password = 0;
    }
    Card(int id,unsigned int password)
    {
         this->id = id;
         this->password = password;
         this->money = 0;
    }

    void info(){
         cout << "id: " << this->id << "  " << "balanc: " << this->money << endl;
    }

    int get_id(){
       return this->id;
    }

    bool is_empty(){
       if(this->id == -1){
           return true;
       }
       return false;
    }

    bool checkId(int& id){
         if(this->id == id){
            return true;
         } else {
            return false;
         }
    }

    bool checkPass(unsigned int& password){
         if(this->password == password){
            return true;
         } else {
            return false;
         }
    }

    void top_up_balanc(int& sum){
         this->money += sum;
    }

    int cash_out(int& sum){
         if(sum > this->money){
             return -1;
         } else {
             this->money -= sum;
             return sum;
         }

    }

    void transaction(Card& another_user,int& sum){

    }


};


int main()
{
   Card* your_card = new Card();
   bool run = true;


    while(run){

        std::list<Card> persons;

        std::ifstream inFile("data.txt",std::ios::binary);



        if(inFile.is_open()){

            Card cIn;
            while(inFile.read(reinterpret_cast<char*>(&cIn),sizeof(Card))){
                persons.push_back(cIn);

            };


            inFile.close();
        }

        if(your_card->is_empty()){
            cout << "Id your card - If you has not card. create - c; \n -->";
            string command;
            cin >> command;

            std::stringstream ss(command);


            char ch;
            if(ss >> ch){
               if(ch == create){
                  int id = 0;
                  unsigned int password;
                  for(auto card : persons){
                      id = card.get_id();
                  }
                  id++;
                  cout << "Your id --> " << id << '\n' << "Write your password -->";
                  cin >> password;
                  Card new_card {id,password};
                  persons.push_back(new_card);
                  std::ofstream outFile("data.txt",std::ios::app|std::ios::binary);
                  if(!outFile){
                      std::cerr << "in database";
                      return 1;
                  }

                  outFile.write(reinterpret_cast<const char*>(&new_card),sizeof(Card));

                  outFile.close();
                  delete your_card;
                  your_card = &new_card;
                  cout << "--------Your card created---------!!!!" << endl;
               }
            }

            ss.clear();
            ss.str(command);

            int your_id;
            if(ss >> your_id && ss.eof()){
                 bool find = false;
                     for(auto& p : persons){
                       if(!find){
                         if(p.checkId(your_id)){
                             find = true;
                             unsigned int password;
                             for(int i = 5;i != 0;--i){
                                cout << "password(only numbers) -->";
                                cin >> password;
                                if(p.checkPass(password)){
                                   cout << "Succesfuly" << endl;
                                   delete your_card;
                                   your_card = &p;
                                   break;
                                } else {
                                   cout << "Inncorect password -> " << i << endl;

                                }
                                password = 0;
                             }
                         }
                       }
                     }
                   if(!find)
                      cout << "Inncorrect id" << endl;
                 }





        }
        else if (!your_card->is_empty()){

           string command;
           cout << "commands ----> cash - 2 | top up balanc - 3 | info 4 | exit - d | delete - x " << endl;

           cin >> command;
           std::stringstream ss(command);
           char Char;
           if(ss >> Char){
               switch(Char){
                   case delete_card:
                      {
                         std::ofstream outFile("data.txt",std::ios::trunc|std::ios::binary);
                         if(!outFile){
                            std::cerr << "Error in 202 str" << endl;
                            return 1;
                         }

                         std::list<Card> new_persons;

                         for(auto card : persons){
                             if(card.get_id() != your_card->get_id()){
                                   new_persons.push_back(card);
                             }
                         }

                         cout << "Your card was deleted  id-->" << your_card->get_id() << endl;
                         your_card = new Card();

                         outFile.close();
                      }
                      break;
                   case exit_card:
                      your_card = new Card();
                      break;
               }
           }

           ss.clear();
           ss.str(command);

           int Int;
           if(ss >> Int && ss.eof()){
               switch(Int){
                   case cash:
                     {
                       int sum;
                       cout << "-->";
                       cin >> sum;
                       int res = your_card->cash_out(sum);
                       if(res == -1){
                           cout << "Your balance not enough" << endl;
                       } else {
                          cout << "-->" << res << '$' << "<--"<< endl;
                       }
                     }
                       break;
                   case top_up_balanc:
                       {
                       int sum;
                       cout << "-->";
                       cin >> sum;
                       your_card->top_up_balanc(sum);
                       cout << "Succesfuly" << endl;
                       }
                       break;
                   case info:
                       your_card->info();
                       break;
               }
           }
        }
        std::ofstream outFile("data.txt",std::ios::binary);
        for(auto p : persons){
            outFile.write(reinterpret_cast<const char *>(&p),sizeof(Card));


        }
           outFile.close();
   }
   return 0;
}

