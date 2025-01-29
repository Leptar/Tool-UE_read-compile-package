#include <cstdio>
#include <fstream>
#include <string>
#include "filesystem" 
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

string HOW_TO_USE =
    "How to use ToolUE_RCP :\n"
    "ToolUE_RCP [PATH TO UPROJECT] show-infos\n"
    "ToolUE_RCP [PATH TO UPROJECT] build\n"
    "ToolUE_RCP [PATH TO UPROJECT] package [PATH TO PACKAGE]\n";

void showinfo(const string& pathToUproj)
{
    //TODO

    // try to open file
    ifstream file(pathToUproj);
    if (!file.is_open())
    {
        printf("Error in opening file. Check if there is no error on the path\n");
        printf("%s\n", HOW_TO_USE.c_str());
        return;
    }
    json UPROJ_data = json::parse(file);

    // Print the project name
    string projectName;
    if (!UPROJ_data.contains("Modules"))
    {
       filesystem::path p(pathToUproj);
        projectName = p.stem().string();
    } else
    {
        projectName = UPROJ_data["Modules"][0]["Name"];
    }
    printf("Project Name : %s\n", projectName.c_str());

    
}

void build(const string& pathToUproj)
{
    //TODO
    printf("%s\n", pathToUproj.c_str());
}

void package(const string& pathToUproj, const string& pathToPackage)
{
    //TODO
    printf("%s\n%s", pathToUproj.c_str(), pathToPackage.c_str());
}


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf(HOW_TO_USE.c_str());
        return 1;
    }
    
    if (strcmp(argv[2], "show-infos") == 0){ showinfo(argv[1]); }
    else if (strcmp(argv[2], "build") == 0){ build(argv[1]); }
    else if (strcmp(argv[2], "package") == 0 && argc == 4){ package(argv[1], argv[3]); }
    else
    {
        printf(HOW_TO_USE.c_str());
        return 1;
    }

    return 0;
}
