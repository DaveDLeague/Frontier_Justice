#include <iostream>

#include "frontier_justice.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argv && argc){} // ghetto warning suppressor

    if(!FrontierJustice::init()){
        cout << "Error initializing Frontier Justice.\n";
        return 1;
    }

    FrontierJustice::start();

    return 0;
}
