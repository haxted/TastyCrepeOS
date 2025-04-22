#include "idt.hxx"
static IDTEntry idt[IDT_SZ];
IDTPtr idtptr;

    void setEntry(unsigned int index, void* handler, int type) {
      Term::term_outc('\n');
      Term::term_outs("Setting IDT entry");
      IDTEntry* desc = &idt[index];
      desc->offset1 = (uint32_t)handler & 0xFFFF;
      desc->selector = 0x08;
      desc->type = type;
      desc->zer0 = 0x00;
      desc->offset2 = (uint32_t)handler >> 16;
    }
    void initIDT() {
      Term::term_outs("Initializing IDT...");
      Term::term_outc('\n');
      idtptr.base = (unsigned long)&idt[0];
      idtptr.limit = (uint16_t)sizeof(IDTEntry) * IDT_SZ - 1;

      for(int i = 0; i < 32; i++) {
        setEntry(i, 0, 0x8E);
      }
      lidt(&idtptr);
    }
