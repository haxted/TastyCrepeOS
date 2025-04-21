#pragma once

void hlt() {
  for(;;){
    __asm__("cli; hlt");
  }
}
