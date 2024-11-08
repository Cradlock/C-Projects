#include <iostream>
#include <fstream>
#include <string>
#include <list>

using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

#define CREATE 'c'
#define LIST 'l'
#define UPDATE 'e'
#define DELETE 'd'

#define EXIT 'x'
#define CLEAR 'f'


void show_fun()
{
    cout << "------> c - create record l - view all records\n------> f - clear lists d - delete record" << endl;
}

int main()
{
   std::ofstream fl("data.txt",ios::app);

   fl.close();


   string data;

   std::ifstream Ifs("data.txt");

   if(Ifs.is_open()){

   bool run = true;
            while(run){
                char even[1];
                show_fun();
                cin >> even;
                switch(even[0]){
                    case LIST:
                       {
                          string record;
                          std::ifstream ifs("data.txt");
                          while(getline(ifs,record)){
                             for(int i = 0;i < record.size();++i){

                                    if(record[i] == '<')
                                    {
                                        cout << ") ";
                                        continue;
                                    }
                                    if(record[i] == '>') continue;
                                    cout << record[i];

                             }
                             cout << endl;
                          }
                          ifs.close();
                       }
                       break;
                    case CREATE:
                       {
                       int number = 1;
                       std::ofstream ofs("data.txt",ios::app);
                       string record;
                       getline(cin,record);


                         {
                           string lastline;
                           string line;
                           std::ifstream out_file("data.txt");



                           while(getline(out_file,line)){
                               lastline = line;
                           }

                           if(!lastline.empty()){
                               string num;
                               for(int i = 0;lastline[i] != '<';++i){
                                  num += lastline[i];
                               }
                               number = std::stoi(num) + 1;


                           }

                           out_file.close();
                         }

                       getline(cin,record,'\n');
                       ofs << number << "<"+record+">" << endl;
                       ofs.close();
                       }

                       break;

                    case DELETE:
                       {
                         int number = 0;
                         cin >> number;
                         std::list<string> records;
                         std::ifstream ifs("data.txt");

                         string record;
                         while(getline(ifs,record)){
                                string num_r;
                                int num_record;
                                for(int i = 0;record[i] != '<';++i){
                                    num_r += record[i];
                                }
                                num_record = std::stoi(num_r);
                                if(number != num_record){
                                   records.push_back(record);
                                   record.clear();
                                }
                         }
                         std::ofstream ofs("data.txt");
                         ifs.close();

                         for(string record : records){
                            ofs << record << endl;
                            cout << record << endl;
                         }

                         ofs.close();
                       }
                       break;

                    case CLEAR:
                       {
                       std::ofstream fl("data.txt",ios::trunc);
                       fl.close();
                       }
                       break;

                    case EXIT:
                       run = false;
                       break;

                    default:
                       cout << "Inncorrect input" << endl;
                }
            }
   }
   Ifs.close();
   return 0;
}



