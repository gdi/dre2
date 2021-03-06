#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <re2/re2.h>
#include <sys/time.h>

using namespace std;
using namespace re2;

int main(int argc, char *argv[]) {
  char *buf;
  if (argc != 2) {
    printf("Usage: cat testfile | ./%s <regex to evaluate>\n", argv[0]);
    return 0;
  }

  RE2 search_re(argv[1]);

  buf = (char*)calloc(0x10000, 1);
  while (fgets(buf, 0x10000 - 1, stdin)) {
    if (RE2::PartialMatch(buf, search_re)) {
      printf( "%s", buf );
    }
  }
  free(buf);
  return 0;
}
