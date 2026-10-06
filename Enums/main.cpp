// C++ program to create a directory in Linux
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <thread>
#include <chrono>

enum class Status
{
  Pending = 0, Success = 1, Failed = 2      
};

class Command 
{
    private:
    std::string Name;

    public:
    Status status = Status::Pending;
    static bool is_nameValid(const std::string& Name) {
        size_t name_length = Name.length();
        if (!Name.empty()) {
            for (size_t each_char = 0; each_char < name_length; each_char++) {
                if (Name[each_char] == '/' || Name[each_char] == '\\') {
                    std::cout << "[Error] the directory name should not contain '/' or '\\'\n";
                    return false;
                } 
            } 
            return true;
        } else {
            std::cerr << "[Error] the directory name was empty\n";
            return false;
        }
    }

    Command(std::string Name_directory) {
        Name = Name_directory;
    };  
    Status get_Satus() const {
        return status;
    }
};

class Create_Directory : public Command
{
    private:
    const char* newFolder;
    
    public:
    Create_Directory(const char* folderName) : Command(folderName) {
        newFolder = folderName;
    }
    void execute() {
        if (!Command::is_nameValid(newFolder)) {
            status = Status::Failed;
        } else {
             if (mkdir(newFolder, 0777) == -1) {
            std::cerr << "Error :  " << std::strerror(errno) << std::endl;
            } else {
            std::cout << "Directory: " << newFolder << " created";
            status = Status::Success;
            }
        }
    }
};  

class Delete_Directory : public Command
{
    private:
    const char* ExistantFiles;
    public:
    Delete_Directory(const char* ExistantFile) : Command(ExistantFile) {
        ExistantFiles = ExistantFile;
    } 
    void execute() {
        std::filesystem::remove_all(ExistantFiles);
    }
};

int main()
{
    Command command("Nsd");
    Create_Directory Dir("Nsd");
    Delete_Directory Rm("Nsd");

    Dir.execute();
    std::cout << "Waiting 5 seconds until it's delete it\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Rm.execute();

}