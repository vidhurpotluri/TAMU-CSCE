// File name: AddSub16.tst
// Name: Vidhur Potluri

load AddSub16.hdl,
output-file AddSub16.out,
compare-to AddSub16.cmp,
output-list a%B1.16.1 b%B1.16.1 sel%D2.1.2 out%B1.16.1;

set a %B0000000000000000,
set b %B0000000000000000,
set sel 0,
eval,
output;

set sel 1,
eval,
output;

set a %B0000000000001111,
set b %B0000000011001010,
set sel 0,
eval,
output;

set sel 1,
eval,
output;

set a %B0000000000000000,
set b %B1111111111111111,
set sel 0,
eval,
output;

set sel 1,
eval,
output;

set a %B1111111111111111,
set b %B1111111111111111,
set sel 0,
eval,
output;

set sel 1,
eval,
output;