cd ..
dir /B *.c* > files.txt
xgettext --from-code=cp1251 -a --no-location -s --no-wrap --escape -ffiles.txt -olang/wxTranslation.po

pause