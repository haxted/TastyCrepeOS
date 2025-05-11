
#include <multitasking.h>
// mostly follows the osdev.org tut so credits ig


static Task *r;
static Task n;
static Task o;
extern int getESP();
extern int getEBP();

int initTasks() {
    n.eflags = getEFLAGS();
    createTask(&o, r->n, n->regs.eflags);
    n.n = &o;
    o.n = &n;
    r = &n;
}

int createTask(Task *tsk, void(*mn)(), uint32_t flags) {
    tsk->regs.eax = 0;
    tsk->regs.ebx = 0;
    tsk->regs.ecx = 0;
    tsk->regs.edx = 0;
    tsk->regs.esi = 0;
    tsk->regs.edi = 0;
    tsk->regs.eflags = flags;
    tsk->regs.eip = (size_t)mn;
    tsk->regs.esp = getESP();
    tsk->regs.ebp = getEBP();
    tsk->n = 0;
    return 0;
}

void yield() {
    Task *l = r;
    r = r->n;
    switchtsk(r->regs, l->regs);
    
}