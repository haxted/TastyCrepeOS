#include <stdio.h>
#include <iso646.h>
static unsigned char font[] = {
    #embed "VGA8.F16"
};

int pos = 0;
void kputc(char c, rgb_t* color, loc_t* loc) {
        if(pos >= 1280*1024) {
                clrscr();
        } else {
        if(c == '\n') {
                pos += (1280 - (pos % 1280));
        }
        const uint8_t *glyph = font[c - ' '];
        for(int i = 0; i < 7; i++) {
            uint8_t bmp = glyph[i];
            for(int j = 0; j < 15; j++) {
                if(j & (1 << (15 - j)) {
                    int index = (loc.y + i) * 1280 + (loc.x + j);
                    putpx(loc, color);
                }
            }
        }

        }
        pos++;
        }
}

// FIXME: Dumbass code in both kputc and kputs.

void kputs(const char *str) {
        rgb_t color;
        loc_t loc;
        loc.x = (pos >> 16) & 0xffff;
        loc.y = pos & 0xffff;
        color.r = 255;
        color.g = 255;
        color.b = 255;
        while(*str){
                kputc(*str++, color, loc);
        }
        kputc('\n', 0);
}

void clrscrC(rgb_t* rgb) {
        for(int i = 0; i < 1280*1024; i++) {
                framebufferaddr[i * 3] = rgb->r;
                framebufferaddr[i * 3 + 1] = rgb->g;
                framebufferaddr[i * 3 + 2] = rgb->b;
        }
        pos = 0;
}
void clrscr() {
        for(int i = 0; i < 1280*1024; ++i) {
                framebufferaddr[i * 3] = 0xFF;
                framebufferaddr[i * 3 + 1] = 0xFF;
                framebufferaddr[i * 3 + 2] = 0xFF;
        }
        pos = 0;
}
/*
Commented until i feel like i want to fix it.
void kprintn(int n, rgb_t rgb) {
        char buf[11];
        int i = 0;
        if(n == 0) buf[i++] = '0';
        else {
                while(n) {
                        buf[i++] = '0' + (n % 10);
                        n /= 10;
                }

        }
        for(int k = 0; k < i; k++) {
                bfr[k * 2] = buf[i - k - 1];
                bfr[k * 2 + 1] = color;
        }

}
*/
void kprintf(const char* str) {
    //Copied from kputs.
        rgb_t coloreee;
        loc_t loceee;
        loceee.x = (pos >> 16) & 0xffff;
        loceee.y = pos & 0xffff;
        coloreee.r = 255;
        coloreee.g = 255;
        coloreee.b = 255;
        while(*str) {
                kputc(*str++, coloreee, loceee);
        }
}

void printr(char c, int wid, int hei, rgb_t* rgb, loc_t* loc) {
        int off = (loc->y * 1280 + loc->x);
        for(int s = 0; s < wid*hei; s++) {
            kputc(c, rgb, loc);
                if((s+1) % wid == 0) {
                        kputc('\n', rgb, loc);
                }
        }
}

int putpx(loc_t loc, rgb_t rgb) {
        if(loc.x > 1280 or loc.x < 0 or loc.y > 1024 or loc.y < 0) return 1;
        int offset = (loc.y * 1280 + loc.x);
        framebufferaddr[offset * 3] = rgb.r;
        framebufferaddr[offset * 3 + 1] = rgb.g;
        framebufferaddr[offset * 3 + 2] = rgb.b;
        return 0;
}

void videoFunc(int func, videoParam_t* params) {
        switch(func) {
                case 0: kputs(params->str); break;
                case 1: putpx(params->location, params->colort); break;
                case 2: printr(params->c, params->wid, params->hei, params->colort, params->location);
                case 3: kputc(params->c, params->colort, params->location);
                default: return;
        }
}