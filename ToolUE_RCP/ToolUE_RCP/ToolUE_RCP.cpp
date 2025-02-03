#include <cstdio>
#include <fstream>
#include <string>
#include "filesystem"
#include <sys/stat.h>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

string HOW_TO_USE =
    "How to use ToolUE_RCP :\n"
    "Put the .exe file, in Unreal Engine directory (Need to be an Unreal Engine from source)\n"
    "Commands lines :\n"
    "\t[ToolUE_RCP or exe path] [PATH TO UPROJECT] show-infos\n"
    "\t[ToolUE_RCP or exe path] [PATH TO UPROJECT] build\n"
    "\t[ToolUE_RCP or exe path] [PATH TO UPROJECT] package [PATH TO PACKAGE]\n";

void showinfo(const string& pathToUproj)
{
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

    // Print UE Version
    string UEVersion;
    if (!UPROJ_data.contains("EngineAssociation"))
    {
        UEVersion = "Error : Engine Association not found";
    } else
    {
        UEVersion = UPROJ_data["EngineAssociation"];
        if (UEVersion.length() > 4) { UEVersion += " (From source)"; }
    }
    printf("UE version : %s\n", UEVersion.c_str());

    // Print Plugins
    printf("Plugins :\n");
    for (auto jsonrow : UPROJ_data["Plugins"])
    {
        printf("\t %s\n", jsonrow["Name"].get<string>().c_str());
    }
}

void build(const string& pathToUproj)
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

    // get project name
    string projectName;
    if (!UPROJ_data.contains("Modules"))
    {
        filesystem::path p(pathToUproj);
        projectName = p.stem().string();
    } else
    {
        projectName = UPROJ_data["Modules"][0]["Name"];
    }
    // Path to build.bat from UE from source
    string cml = ".\\Engine\\Build\\BatchFiles\\Build.bat "
                + projectName + " Win64 development " + pathToUproj + " -waitmutex";
    system(cml.c_str());
    
}

void package(const string& pathToUproj, const string& pathToPackage)
{
    //TODO
    struct stat sb;
    if (!(stat(pathToUproj.c_str(), &sb) == 0 && !(sb.st_mode & S_IFDIR)))
    {
        printf("Error in opening file. Check if there is no error on the path\n");
        printf("%s\n", HOW_TO_USE.c_str());
        return;
    }
    
    if (stat(pathToPackage.c_str(), &sb) != 0)
    {
        printf("Error in package path. Check if there is no error on the path\n");
        printf("%s\n", HOW_TO_USE.c_str());
        return;
    }
    string cml = ".\\Engine\\Build\\BatchFiles\\RunUAT.bat ";
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
