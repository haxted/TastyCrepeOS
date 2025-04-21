#include "memcpy.hxx"

void memcpy(void *dest, const void *src, unsigned int sz) {
  unsigned char* d = (unsigned char*)dest;
  unsigned char* s = (unsigned char*)src;
  for(int i = 0; i < sz; i++) {
    d[i] = s[i];
  }
}
