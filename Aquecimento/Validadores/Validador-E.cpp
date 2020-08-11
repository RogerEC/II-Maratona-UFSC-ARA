#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    while(!inf.readToken("[A-Z]{1,10}", "a").empty())
        inf.readEoln();
    inf.readEof();
}