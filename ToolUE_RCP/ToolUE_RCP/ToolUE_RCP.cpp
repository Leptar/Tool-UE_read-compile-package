#include <cstdio>
using namespace std;
#include <string>
#include "json.hpp"
using json = nlohmann::json;

string HOWTOUSE =
    "How to use ToolUE_RCP :\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] show-infos\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] build\n"
    "ToolUE_RCP [CHEMIN DU UPROJECT] package [CHEMIN DU PACKAGE]\n";

void showinfo(string pathToUproj)
{
    //TODO
    printf("%s\n", pathToUproj.c_str());
}

void build(string pathToUproj)
{
    //TODO
    printf("%s\n", pathToUproj.c_str());
}

void package(string pathToUproj, string pathToPackage)
{
    //TODO
    printf("%s\n%s", pathToUproj.c_str(), pathToPackage.c_str());
}


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf(HOWTOUSE.c_str());
        return 1;
    }
    
    if (strcmp(argv[2], "show-infos") == 0){ showinfo("Test show infos"); }
    else if (strcmp(argv[2], "build") == 0){ build("Test build"); }
    else if (strcmp(argv[2], "package") == 0 && argc == 4){ package("Test package", argv[3]); }
    else
    {
        printf(HOWTOUSE.c_str());
        return 1;
    }

    return 0;
}
