#include <fstream> 
#include <iostream> 
#include <string>
#include <vector> 
#include <iterator>
#include <windows.h>
#include <sstream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[])
{
    

    int askid = 0; 
	int ansid = 0;
    cout << "Answer last id? " << endl;
    cin >> ansid;
    ansid++;
    cout << "Question last id? " << endl;
    cin >> askid;
    askid++;
    char chis;
  
    
char ch='0'; 
  string s ="('";
  string sa = "INSERT INTO `wp_ansDATA` (`ID`, `ANS`) VALUES ";
  string squ = "INSERT INTO `wp_askDATA` (`ID`, `ASK`) VALUES ";
 const char *fromFName="kushat.txt";
 const char *QueFName="wp_askDATA.sql";
 const char *AnsFName="wp_ansDATA.sql";
ifstream in(fromFName);
while((ch = in.get())!= '{') {   //EOF было бы желательно
        if (char(ch)!='\n' || char(ch)!='-'|| char(ch)!='=') s=s+char(ch);
        cout << ch;
        switch (ch) // начало оператора switch
  {
     case '.':
     {
     	stringstream strs;
     	strs << ansid;
  string temp_str = strs.str();
     sa = sa + "('" + temp_str + "', '" + s + "'),";
     cout << endl;
     ansid++;
     temp_str = "";
  //   strs ='0';
     s = "";
     
     break;
     }
     case '!':
     {
     	stringstream strs;
     	strs << ansid;
  string temp_str = strs.str();
     sa = sa + "('" + temp_str + "', '" + s + "'),";
     cout << endl;
     ansid++;
     s = "";
     temp_str = "";
  //   strs ='0';
     break;
     }
     case '?':
     {
     	stringstream strs;
     	strs << askid;
  string temp_str = strs.str();
     squ = squ + "('" + temp_str + "', '" + s + "'),";
     cout << endl;
     askid++;
     temp_str = "";
  //   strs ='0';
     s = "";
     break;
     }
    /* default:
             {
              if (char(ch)!='\n') s=s+char(ch);    
                  }*/
     ofstream out (AnsFName); 
     out << s + ';';
     s = '0';
};
ofstream out (AnsFName); 
     out << sa;
ofstream ok (QueFName); 
     ok << squ;
     
};
/*delete s; 
delete sa; 
delete squ;*/

    system("pause");
    cin.get ();
    return 0;
}
