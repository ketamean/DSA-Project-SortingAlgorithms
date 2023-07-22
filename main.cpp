#include "sorting_implementation.cpp"
#include "cmd.cpp"

int main (int argc, const char* argv[]) {
    vector<string> str_argv;
    for(int i = 0; i < argc; i++)
       str_argv.push_back(string(argv[i]));
    getTASK(argc,str_argv);
    return 0;
}