#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string_view>
#include <sstream>
using namespace std;

std::set<std::string> make_exit_commands(){
    std::set<std::string> set {"q", "quit", "e", "exit"};
    return set;
}

int main()
{
    std::set<std::string> exits_command = make_exit_commands();
    std::map<std::string, std::string> translate;
    std::string string;
    std::string str1 = "";
    std::string str2 = "";
    do
    {
        std::cin >> string;
        if (string.find("add") != std::string::npos){
            std::cin >> str1;
            std::cin >> str2;
            translate.emplace(str1, str2);
            std::cout << str1 + "=>" + str2 << std::endl;
            str1 = "";
            str2 = "";
        }
        if (string.find("translate") != std::string::npos){
            std::string line;
            std::getline(std::cin, line);

            std::stringstream words;
            std::string word;
            words << line;
            words >> word;
            while (words.eof()){
                auto it = translate.find(word);
                if (it != translate.cend()){
                    cout << it->second << endl;
                }
                else {
                    cout << "???" << endl;
                }
            }


            // std::cin >> str1;
            // auto it = translate.find(str1);
            // if (it != translate.cend()){
            //     cout << it->second << endl;
            // }
            // else {
            //     cout << "???" << endl;
            // }
        }
    } while (exits_command.count(string) == 0);

    return 0;
}