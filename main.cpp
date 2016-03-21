#include <iostream>
#include "LearningCMakeConfig.h"

#ifdef USE_MY_LIBRARY
#include "mylibrary/myFunctions.cpp"
#endif

using namespace std;

int main() {
    cout << "Hello, World! " << endl;
    cout << "Version " << LearningCMake_VERSION_MAJOR << "." << LearningCMake_VERSION_MINOR << endl;

#ifdef USE_MY_LIBRARY
    cout << "Calling myFunctions " << sumSomething(2, 3) << endl;
#else
    cout << "Calling default " << (2 + 3) << endl;
#endif
    return 0;
}