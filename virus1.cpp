#include <iostream>
#include <fstream>
using namespace std;

void writeFile(string victimFile){
    ofstream myfile(victimFile);
    if (myfile.is_open()){
    char s[] =  "   #include <iostream>\n#include <fstream>\nusing namespace std;\n\n"
     "void writeFile(string victimFile){\n    ofstream myfile(victimFile);\n    if (myfile.is_open()){\n    c"
     "har s[] =$$;\n    for (int i=0; s[i]; i++) {\n        if (s[i] == '$' && s[i + 1] == '$') {\n          "
     "  myfile << \"\\\"\";\n            for (int j = 0; s[j]; j++) {\n                if (s[j] == '\"') myfile <"
     "< \"\\\\\\\"\";\n                else if (s[j] == '\\n') myfile << (\"\\\\n\");\n                else myfile << s"
     "[j];\n                if (j % 100 == 63) myfile << \"\\\"\\n    \\\"\";\n            }\n            myfile << "
     "\"\\\"\";\n            i++;\n        } else\n            myfile << s[i];\n    }\n    myfile.close();\n    "
     "}\n}\n\nint main(int argc, char ** argv) {\n   writeFile(argv[1]);\n    return 0;\n}";
    for (int i=0; s[i]; i++) {
        if (s[i] == '$' && s[i + 1] == '$') {
            myfile << "\"";
            for (int j = 0; s[j]; j++) {
                if (s[j] == '"') myfile << "\\\"";
                else if (s[j] == '\n') myfile << ("\\n");
                else myfile << s[j];
                if (j % 100 == 63) myfile << "\"\n    \"";
            }
            myfile << "\"";
            i++;
        } else
            myfile << s[i];
        }
    myfile.close();
    }
}

int main(int argc, char ** argv) {
    writeFile(argv[2]);
    return 0;
}