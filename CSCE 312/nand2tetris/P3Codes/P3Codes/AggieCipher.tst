// File name: projects/03/AggieCipher.tst
// Complete the test file below

load AggieCipher.hdl,
output-file AggieCipher.out,  // output file
compare-to AggieCipher.cmp,    // compare file
output-list in%B1.4.1 out%B1.4.1;

set in %B0000,
tick,
tock,
output;

set in %B1110,
tick,
tock,
output;

set in %B1101,
tick,
tock,
output;

set in %B0101,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

set in %B0101,
tick,
tock,
output;

set in %B0101,
tick,
tock,
output;

set in %B0101,
tick,
tock,
output;

set in %B0010,
tick,
tock,
output;

set in %B0010,
tick,
tock,
output;

set in %B0010,
tick,
tock,
output;

set in %B0010,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

set in %B0001,
tick,
tock,
output;

// Once above test cases work fine for your implementation for the provided cmp file,
// test with more examples of your own below, and accordingly verify if the output file reports correct outputs as expected
