#include <cstdio>
using namespace std;
#include <string>
#include "json.hpp"
using json = nlohmann::json;

string HowToUse =
    "How to use ToolUE_RCP :\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] show-infos\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] build\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] package [CHEMIN DU PACKAGE]\n";

void showinfo(string pathToUproj)
{
    //TODO
}

void build(string pathToUproj)
{
    //TODO
}

void package(string pathToUproj, string pathToPackage)
{
    //TODO
}

int main(int argc, char* argv[])
{
    //TODO

    // if (argc < 3)
    // {
    //     showinfo("error");
    //     return 1;
    // }
    //
    // if (std::strcmp(argv[2], "show-infos") == 0)
    // {
    //     showinfo("poulet"); 
    // }


    return 0;
}
