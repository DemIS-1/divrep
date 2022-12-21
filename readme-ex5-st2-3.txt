run ex5-2-st2-3.exe (source:
example-file-classic-5-2-stage2-3.c, no 'main fflush', variables f1() 'abc', replaced to 'def';
"bare block" is 'for (int i = 0; i < 3; ++i) {}';
code from f1() inside 'for';
no fflush(rfp);
f1() exists but not call from 'main()';)

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
Check: FMT and data in file: NOT changed, is changed (added: 31 31 62)

Enter (2:2) first digit
32
Enter (2:2) second digit
32
Check: FMT and data in file: NOT changed, NO changed (no added data)


Enter (3) first digit
4
Enter (3) second digit
4
Check: FMT and data in file: is changed, is changed (added: 32 32 64, added: 4 4 8, and "=================")
