#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 10; i++) {
        char *a = malloc(10 * 1024 * 1024);
        memset(a, 0, 10 * 1024 * 1024);
        sleep(1);
    }

    return 0;
}

/*
Mach Virtual Memory Statistics: (page size of 4096 bytes)
    free   active   specul inactive throttle    wired  prgable   faults     copy    0fill reactive   purged file-backed anonymous cmprssed cmprssor  dcomprs   comprs  pageins  pageout  swapins swapouts
  792982   887759   102826   757249        0   834405    58206  363791K  6286792  290509K  8374659  7648076      376344   1371490  4125020   818711 10575605 22799345 15859397    80883  6011846  6894863 
  790370   887967   102826   759616        0   834444    58206     4017        0     3854        0        0      376344   1374065  4124986   818695       34        0        0        0        0        0 
  787698   886627   102826   760630        0   837454    54594     2942       47     2745        0        0      376344   1373739  4124932   818663       54        0        0        0        0        0 
  783490   889169   102895   770649        0   829047    55602    29648     3574     5510        0        0      376419   1386294  4124517   818551      439        0       20        0        0        0 
  771308   890046   102925   786852        0   827540    59244    27453      592    10787        2        0      377439   1402384  4116662   815207     6866        0      641        0        0        0 
  814389   853163   103013   778977        0   833158    59282     7274        0     5119        0        0      377531   1357622  4101705   811287     1035        0       62        0        0        0 
  812081   856645   103013   778964        0   831853    59795     2768        0     2613        0        0      377531   1361091  4101701   811287        2        0        0        0        0        0 
  795286   854931   103013   778132        0   852611    54835     2727        0     2904        0        0      377531   1358545  4091932   809911     9767        0        0        0        0        0 
  793869   858604   103013   777836        0   850822    54835     2816        2     2698        0        0      377531   1361922  4091625   809831       42        0        0        0        0        0 
  787656   864677   103175   777717        0   850946    54854    10564      354     6702        0        5      377980   1367589  4091254   809623      371        0      336        0        0        0 
  813650   849779   103177   767730        0   849861    55894      353        8      211        0        0      377982   1342704  4091242   809623       12        0        0        0        0        0 
  813513   849335   103177   767689        0   850371    55870      246        0       73        0        1      377982   1342219  4091228   809623       14        0        0        0        0        0 
  813660   849385   103177   767594        0   850415    55870      231        0       87        0        0      377982   1342174  4091226   809623        2        0        0        0        0        0 
  813499   908426   103177   767665        0   791469    62908      521        0      305        0        0      377982   1401286  4091180   809623       46        0        0        0        0        0 
  813701   896692   103180   772933        0   797713    62714      221        0      118        0        0      377985   1394820  4091126   809591       54        0        0        0        0        0 
  813768   896280   103180   773354        0   797713    62708      220        0      133        0        0      377985   1394829  4091087   809591       39        0        0        0        0        0 
*/