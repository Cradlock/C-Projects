#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <list>

enum commands{
   Create='c',
   Open='o',

   Read='r',
   Edit='e',
   Exit='x',
   App='a',
   Clear='f',
};



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main()
{
//    start:
//    string your_path = "";
//    bool run = true;
//    cout << "Create File - c | Open File - o" << endl;
//    while(run){
//
//         if(your_path == ""){
//             char operation;
//             operation = std::getchar();
//             if(operation == Open){
//                 string path;
//                 cout << "Path --> ";
//                 cin >> path;
//
//
//                 std::ifstream inFile(path);
//                 if(inFile.is_open()){
//                    cout << "<-----File open----->" << endl;
//                    inFile.close();
//                    your_path = path;
//                 } else {
//                    cout << "This File not" << endl;
//                    goto start;
//                 }
//             }
//             else if(operation == Create){
//                 string path;
//                 cout << "Path --> ";
//                 cin >> path;
//
//                 std::ifstream inFile(path);
//                 inFile.close();
//                 your_path = path;
//             }
//
//         }else{
//             cout << "Edit - e | Exit - x | App - a | Clear - f | Read - r" << endl;
//             char operation;
//             cin >> operation;
//
//
//             switch(operation){
//                case Edit:
//                    {
//                    string find_str;
//                    getline(cin,find_str);
//
//
//                    string text;
//                    std::ifstream outFile(your_path);
//                    getline(cin,find_str,'|');
//
//                    string str;
//                    while(getline(outFile,str)){
//                        text += str;
//                        text += '\n';
//                    }
//                    outFile.close();
//
//                    cout << text << endl;
//
//                    }
//                    break;
//                case Exit:
//                    your_path = "";
//                    cout << "You exited this file" << endl;
//                    goto start;
//                case App:
//                    {
//                    string str;
//                    cout << "Write your str(| - end) \n--> ";
//                    getline(cin,str);
//                    std::ofstream outFile(your_path,std::ios::app);
//
//
//                      getline(cin,str,'|');
//
//
//                      outFile << str << endl;
//
//                    outFile.close();
//                    }
//                    cout << "String app to file" << endl;
//                    break;
//                case Clear:
//                    {
//                    std::ofstream outFile(your_path,std::ios::trunc);
//                    outFile.close();
//                    cout << "Cleared this file" << endl;
//                    }
//                    break;
//                case Read:
//                    {
//                    string str;
//                    std::ifstream inFile(your_path);
//
//                    cout << "------start-------------------------------" << endl;
//                    while(getline(inFile,str)){
//                        cout << str << endl;
//                        str = "";
//                    }
//                    cout << "------end----------------------------------" << endl;
//
//                    inFile.close();
//                    }
//                    break;
//             }
//         }
//    }


    return 0;
}
