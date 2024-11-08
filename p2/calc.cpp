#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;



string rmSpace(const string& str){
     string result;
     for(char& c : str){
         if(c != ' '){
             result += c;
         }
     }
     return result;

}

static int beg = -1,end = -1;






int main()
{

   bool run = true;
   while(run){
   string val;
   getline(cin,val);

   string str;
   str = rmSpace(val);

   int ans;
   for(int i = 0,c = 0;i <= str.length();++i){
        if(str[i] == '*'){

            string a_s,b_s;
            int a,b;


            for(int j = i-1;str[j] != '+' && str[j] != '-' && str[j] != '*' && str[j] != '/' && j >= 0;--j){
                  a_s += str[j];
                  ::beg = j;
            }

            for(int j = i+1;str[j] != '+' && str[j] != '-' && str[j] != '*' && str[j] != '/' && j >= 0;++j){
                  b_s += str[j];
                  ::end = j;
            }

            std::reverse(a_s.begin(),a_s.end());
            a = std::stoi(a_s);
            b = std::stoi(b_s);
            ans = a*b;

        } else if (str[i] == '/'){
            string a_s,b_s;
            int a,b;
            for(int j = i-1;str[j] != '+' && str[j] != '-' && str[j] != '*' && str[j] != '/' && j >= 0;--j){
                  a_s += str[j];
                  ::beg = j;
            }
            for(int j = i+1;str[j] != '+' && str[j] != '-' && str[j] != '*' && str[j] != '/' && j >= 0;++j){
                  b_s += str[j];
                  ::end = j;
            }

            std::reverse(a_s.begin(),a_s.end());
            a = std::stoi(a_s);
            b = std::stoi(b_s);
            ans = a/b;

        }

        if(end != -1 && beg != -1){
             string res;
             res = std::to_string(ans);
             str.erase(beg,(end - beg)+1);
             str.insert(beg, res);


             ans = 0;
             res = "";
             end = -1;
             beg = -1;
        }


   }


   int res = 0;
   string num_str = "";
   for(int i = 0;i <= str.length();++i){

       if(num_str == ""){
           num_str += str[i];

       } else{
           if(str[i] != '+' && str[i] != '-' && i != str.length()){
               num_str += str[i];
           }else{
                int num = 0;
                num = std::stoi(num_str);
                res += num;
                num_str = "";
                i--;
           }
       }



   }

   cout << "--->" << val << " = " << res << endl;
   }
   return 0;
}


