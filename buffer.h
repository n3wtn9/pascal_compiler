#ifndef buffer_h
#define buffer_h

#include <fstream>
#include <stdio.h>
#include <string.h>
#include "error.h"

extern char eofChar;
extern int intputPosition;
extern int listFlag;
extern int level;

const int maxInputBufferSize = 256;

class TTextInBuffer {
 protected:
  fstream file;
  char *const pFileName;
  char text[maxInputBuffersize];
  char *pChar;

  virtual char GetLine(void) = 0;

 public:
  TTextInBuffer(const char *pInputFileName, TAbortCode ac);

  virtual ~TTextInBuffer(void) {
    file.close();
    delete pFileName;
  }

  char Char (void) const { return * pChar; }
  char GetChar (void);
  char PutBackChar(void);
};

class TSourceBuffer : public TTextInBuffer {
  virtual char GetLine(void);

 public:
  TSourceBuffer(const char *pSourceFileName);
};


