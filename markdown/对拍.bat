loop:
	random.exe
	exec1.exe
	exec2.exe
	fc exec1.out exec2.out
	if %errorcode = 1 then
	goto flag
	if not errorlevel 1 goto loop