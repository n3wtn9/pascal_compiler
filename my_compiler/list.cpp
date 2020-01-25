# include <iostream>
# include "error.h"
# include "buffer.h"

using namespace std;

int main(int argc, char *argv[])
{
  char ch;
  
  if (argc != 2) {
    cerr << "Usage: list <source file>" << endl;
    AbortTranslation(abortInvalidCommandLineArgs);
  }

  TSourceBuffer source(argv[1]);

  do {
    ch = source.GetChar();
  } while (ch != eofChar);
}
