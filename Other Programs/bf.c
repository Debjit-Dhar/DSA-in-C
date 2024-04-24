#include <stdio.h>
void main()
{
    struct status{
       unsigned delta_cts:1;
       unsigned delta_dsr:1;
       unsigned tr_edge:1;
       unsigned delta_rec:1;
       unsigned cts:1;
       unsigned dsr:1;
       unsigned ring:1;
       unsigned rec_line:1;
    }status1;
}