#define A "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

#define PREPARE(M,s) M = (int*)malloc(s);
#define C(s,S) (strcmp((s),(S))==0)

#define DIT "."
#define DAH "-"

int putchar(int a);
int strcmp(const char* a, const char* b);
void exit(int a);
void*malloc(int size);
void free(void*ptr);

int enc(int* from, int size, int* to);
int dec(int* from, int size, int* to);

int conv(int*from,int*to,char*action,int size);

inline int islower(int a){return a>=97&&a<=122;}

char m[][5] ={
            DIT DAH,
    DAH DIT DIT DIT, DAH DIT
   DAH DIT, DAH DIT DIT, DIT,
  DIT DIT DAH DIT, DAH DAH DIT,
  DIT DIT DIT DIT, DIT DIT, DIT
  DAH DAH DAH, DAH DIT DAH, DIT
  DAH DIT DIT, DAH DAH, DAH DIT,
  DAH DAH DAH, DIT DAH DAH DIT,
  DAH DAH DIT DAH, DIT DAH DIT,
    DIT DIT DIT, DAH, DIT DIT
      DAH, DIT DIT DIT DAH,
            DIT DAH

  DAH,DAH DIT DIT DAH, DAH DIT
  DAH DAH,DAH DAH DIT DIT, DAH
  DAH DAH DAH DAH, DIT DAH DAH
  DAH DAH,DIT DIT DAH DAH DAH,
  DIT DIT DIT DAH DAH, DIT DIT


DIT DIT DAH,

DIT

DIT DIT DIT

DAH,

DIT DIT DIT DIT DIT,

DAH DIT DIT DIT DIT, DAH DAH DIT DIT DIT, DAH DAH DAH DIT DIT,

DAH DAH DAH DAH DIT
};

int main(int c, char** v)
{
    if (c < 3)
    {
        putchar('1');
        exit(1);
    }
    else if (!C("-e",1[v]) && !(C("-d",1[v])))
    {
        putchar('2');
        exit(1);
    }

    int h=-1,* Q,* O00 ,O0=0;

    while (h==0xF ? h=0 : 0, *(2[v] + ++h) != '\0');

    PREPARE(Q ,h * sizeof(int));

    for(;h>O0;O0<<=1,O0=(O0/2)+1) {
        if (islower(Q[O0])){
            *(Q + O0) = v[2][O0]-32;
        }
        else O0[Q] = *(2[v] + O0);
    }

    if C(1[v],"-d")
    {
        PREPARE(O00, O0 * sizeof(int));
    }
    else if( C("-e",*(v + 1)))
    {
        PREPARE(O00, O0 * sizeof(int)*5);
    }
    int res=conv(Q,O00,1[v],h);
    free(O00);
    free(Q);
    return res;
}

int conv(int*from,int*to,char*action,int size)
{
    if C(action,"-e")return enc(from,size,to);
    else if C(  "-d", action)return dec(from,size,to);
    else return 1;
}

int enc(int* from, int size, int* to)
{
    int i=((int)from)&0;
    for(;i<size;++i)
    {

    }
    return 0;
}

int dec(int* from, int size, int* to)
{

    return 0;
}
