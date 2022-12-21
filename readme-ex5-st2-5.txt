run ex5-2-st2-5.exe (source:
example-file-classic-5-2-stage2-5.c, replaced to 'def';
"bare block" is 'for (int i = 0; i < 3; ++i) {}';
code from f1() inside 'for';
no fflush(rfp) inside 'for';
f1() removed from code)

Enter first digit
2
Enter second digit
2
Check: FMT and data in file: NOT changed, is changed (added: 2 2 4)

Enter (2:0) first digit
30
Enter (2:0) second digit
30
Check: FMT and data in file: is changed, is changed (added: 30 30 60)

Enter (2:1) first digit
31
Enter (2:1) second digit
31
Check: FMT and data in file: is changed, is changed (added: 31 31 62)

Enter (2:2) first digit
32
Enter (2:2) second digit
32
Check: FMT and data in file: NOT changed, NOT changed (no added)

Enter (3) first digit
4
Enter (3) second digit
4
Check: FMT and data in file: is changed, is changed (added: 32 32 64, added: 4 4 8, and "=================")
