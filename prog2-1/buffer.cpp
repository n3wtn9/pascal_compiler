#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include "common.h"
#include "buffer.h"

using namespace std;

char eofChar = 0x7F;
int inputPosition;
int listFlag = true;

TListBuffer list;

TTextInBuffer::TTextInBuffer(const char *pInputFileName, TAbortCode ac)
  : pFileName(new char[strlen(pInputFileName) + 1])
{
  strcpy(pFileName, pInputFileName);
  file.open(pFileName, ios::in);
  if (!file.good()) AbortTranslation(ac);
}

char TTextInBuffer::GetChar(void)
{
  const int tabSize = 8;
  char ch;

  if (*pChar ==eofChar) return eofChar;
  else if(*pChar == '\0') ch = GetLine();
  else {
    ++pChar;
    ++inputPosition;
    ch = *pChar;
  }

  if (ch == '\t') inputPosition += tabSize - inputPosition%tabSize;

  return ch;
}

char TTextInBuffer::PutBackChar(void)
{
  --pChar;
  --inputPosition;
  return *pChar;
}

TSourceBuffer::TSourceBuffer(const char *pSourceFileName)
  : TTextInBuffer(pSourceFileName, abortSourceFileOpenFailed) 
{
  if (listFlag) list.Initialize(pSourceFileName);
  GetLine();
}

char TSourceBuffer::GetLine(void)
{
  extern int lineNumber, currentNestingLevel;
 
  if (file.eof()) pChar = &eofChar;

  else {
    file.getline(text, maxInputBufferSize);
    pChar = text;

    if (listFlag) list.PutLine(text, ++currentLineNumber,
                               currentNestingLevel);
  }
  
  inputPosition = 0;
  return *pChar;
}

const int maxPrintLineLength = 80;
const int maxLinesPerPage    = 50;



void TListBuffer::PrintPageHeader(void)
{
  const char formFeedChar = '\f';
  cout << formFeedChar << "Page " << ++pageNumber
       << "   " << pSourceFileName << "   " << date
       << endl << endl;

  lineCount = 0;
}

void TListBuffer::Initialize(const char *pFileName)
{
  text[0] = '\0';
  pageNumber = 0;
  
  pSourceFileName = new char[strlen(pFileName) + 1];
  strcpy(pSourceFileName, pFileName);

  time_t timer;
  time(&timer);
  strcpy(date, asctime(localtime(&timer)));
  date[strlen(date) -1] = '\0';
  
  PrintPageHeader();
}

void TListBuffer::PutLine(void)
{
  if (listFlag && (lineCount == maxLinesPerPage)) PrintPageHeader();

  text[maxPrintLineLength] = '\0';

  cout << text << endl;
  text[0] = '\0';

  ++lineCount;
}

