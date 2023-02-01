#include <iostream>
#include <string>
#include <set>
#include <map>
#include <string_view>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

using Translate = map<std::string, std::string>;
using History = std::vector<string>;
using Language = pair<string, string>;

std::set<std::string> make_exit_commands()
{
    std::set<std::string> set{"q", "quit", "e", "exit"};
    return set;
}

void execute_command(string command, Translate &translate, History &history, std::istream &stream)
{
    if (command == "add")
    {
        string str1;
        string str2;
        stream >> str1;
        stream >> str2;
        translate.emplace(str1, str2);
        std::cout << str1 + "=>" + str2 << std::endl;
        history.push_back("add " + str1 + " " + str2);
        str1 = "";
        str2 = "";
    }
    else if (command == "translate")
    {
        std::string line;
        std::getline(stream, line);

        std::stringstream words;
        std::string word;
        words << line;
        while (!words.eof())
        {
            words >> word;
            auto it = translate.find(word);
            if (it != translate.cend())
            {
                cout << it->second << endl;
            }
            else
            {
                cout << "???" << endl;
            }
        }
    }
    else if (command == "print")
    {
        for (auto it : translate)
        {
            cout << it.first + "=>" + it.second << endl;
        }
    }
    else if (command == "save")
    {
        std::string filename;
        stream >> filename;
        std::ofstream f(filename, std::ios::out);
        for (const auto &str : history)
        {
            f << str << "\n";
        }
    }
    else if (command == "load")
    {
        std::string filename;
        stream >> filename;
        auto f = std::ifstream{filename};
        while (!f.eof())
        {
            std::string add;
            f >> add;
            execute_command(add, translate, history, f);
        }
    }
    else if (command == "clear")
    {
        translate.clear();
        history.clear();
        cout << "Clearing every translations" << endl;
    }
    else if (command == "remove")
    {
        string str;
        stream >> str;
        for (auto it = translate.begin(); it != translate.end();)
        {
            if (it->first == str || it->second == str)
            {
                std::cout << it->first << " x " << it->second << std::endl;
                it = translate.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
}

int main(int argc, char **argv)
{
    Language language = argc == 3 ? Language{argv[1], argv[2]} : Language{"fr", "en"};
    std::set<std::string> exits_command = make_exit_commands();
    Translate translate;
    History history;
    std::string command;
    std::string str1 = "";
    std::string str2 = "";
    do
    {
        std::cin >> command;
        execute_command(command, translate, history, std::cin);
    } while (exits_command.count(command) == 0);

    return 0;
}