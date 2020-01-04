#include <stdlib.h>
#include <iostream>
#include <string>
#include "error.h"

using namespace std;

int errorCount = 0;

static string abortMsg[] = {
                           NULL,
                           "Invalid command line arguments",
                           "Failed to open source file",
                           "Failed to open intermediate form file",
                           "Failed to open assembly file",
                           "Too many syntax errors",
                           "Stack overflow",
                           "Code segment overflow",
                           "Nesting too deep",
                           "Runtime error",
                           "Unimplemented feature",
};

void AbortTranslation(TAbortCode ac)
{
  cerr <<"*** Fatal translator erro: " << abortMsg[-ac] << endl;
  exit(ac);
}

                           
