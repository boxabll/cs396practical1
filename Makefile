sc: string_calc.c
	gcc -w -Wno-format-security -fno-stack-protector -o sc string_calc.c

clean:
	rm -f sc