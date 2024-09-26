/*

    OpenLog source file for updating graphics files directy
    Written by ghgltggamer

*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdio>

int main(int argc, char * argv[]){
    std::string command = argv[1];
    std::ifstream command_file(command);

    if (command_file.is_open()){
        std::string file_data;
        while (std::getline(command_file, file_data)){
            if (file_data.find("remove:") != -1){
                std::string macro = "remove:";
                std::string file = file_data.substr(file_data.find("remove:")+macro.length());

                std::ofstream rem(file);
            }
            else if (file_data.find("updated:") != -1){
                std::string macro = "updated:";
                std::string file = file_data.substr(file_data.find("updated:")+macro.length());
                std::string new_File = file.substr(0, file.find(","));
                // std::string file_path = file.substr();
                // std::cout<<file;
                // std::cout<<"\n\n\n comma place "<<new_File;
                std::string comma = file.substr(file.find(",")+1);
                // std::cout<<comma;

                std::ifstream get_file(new_File);
                std::system("mkdir updated");
                std::string dat;
                std::string new_Dat;
                std::string file_name_new = "updated/"+comma;
                std::ofstream make_file(file_name_new);
                while (std::getline(get_file, dat)){
                    // dat += dat + "\n";
                    // std::cout<<dat<<std::endl;
                    new_Dat += dat+"\n";
                }
                make_file<<new_Dat;
                // UPDATED_LOGS
                std::ifstream UPDATED_LOGS_I("updated/UPDATED_LOGS");
                std::string UPDATED_FILE_DATA;
                std::string UPDATED_LOGS_REAL;
                while (std::getline(UPDATED_LOGS_I, UPDATED_FILE_DATA)){
                    UPDATED_LOGS_REAL += UPDATED_FILE_DATA + "\n";
                }
                UPDATED_LOGS_REAL += comma + ":" + new_File;

                std::ofstream UPDATED_LOGS_O("updated/UPDATED_LOGS");
                UPDATED_LOGS_O<<UPDATED_LOGS_REAL;
            }
            else if (file_data.find("UPDATE_FILES;") != -1){
                std::string macro = "UPDATE_FILES;";
                std::ifstream UPDATE_LOGS_I("updated/UPDATED_LOGS");
                std::string UPDATE_LOGS_CURRENT;
                while (std::getline(UPDATE_LOGS_I, UPDATE_LOGS_CURRENT)){
                    std::string get_first_file = UPDATE_LOGS_CURRENT.substr(0, UPDATE_LOGS_CURRENT.find(":"));
                    std::string orig_file = UPDATE_LOGS_CURRENT.substr(UPDATE_LOGS_CURRENT.find(":")+1);
                    std::string first_file_data;
                    std::cout<<orig_file;
                    std::string get_first_file_data;
                    std::ifstream first_file_i("updated/"+get_first_file);
                    while (std::getline(first_file_i, get_first_file_data)){
                        first_file_data += get_first_file_data + "\n";
                        // std::cout<<first_file_data;
                    }

                    std::ofstream orig_file_o(orig_file);
                    orig_file_o<<first_file_data;
                    // std::cout<<first_file_data;
                }
            }
            else {
                std::cout<<"ERROR (OpenLog) : Invalid syntax; Unknown macro "<<file_data<<" in "<<command<<"";
                break;
            }
        }
    }
    else {
        std::cout<<"\n\n ERROR (OpenLog) : File not found";
    }
}



/*

    OpenLogs - Domain Specific Language for File Management
    Developed by ghgltggamer

*/