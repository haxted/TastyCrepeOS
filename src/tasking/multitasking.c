
#include <multitasking.h>
// mostly follows the osdev.org tut so credits ig


static Task *r;
static Task n;
static Task o;
extern int getESP();
extern int getEBP();

int initTasks() {
    n.reg.eflags = getEFLAGS();
    createTask(&o, r->n, n.reg.eflags);
    n.n = &o;
    o.n = &n;
    r = &n;
}

int createTask(Task *tsk, void(*mn)(), uint32_t flags) {
    tsk->reg.eax = 0;
    tsk->reg.ebx = 0;
    tsk->reg.ecx = 0;
    tsk->reg.edx = 0;
    tsk->reg.esi = 0;
    tsk->reg.edi = 0;
    tsk->reg.eflags = flags;
    tsk->reg.eip = (size_t)mn;
    tsk->reg.esp = getESP();
    tsk->reg.ebp = getEBP();
    tsk->n = 0;
    return 0;
}

void yield() {
    Task *l = r;
    r = r->n;
    switchtsk(&r->reg, &l->reg);
    
}