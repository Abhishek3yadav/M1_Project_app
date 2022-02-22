#Target_name : Dependencies
#<TAB>Command

target : menu.c  ./3_Implementation/src/input.c ./3_Implementation/unity/unity.c ./3_Implementation/test/test_menu.c ./3_Implementation/inc/menu.h 
	    gcc menu.c  ./3_Implementation/src/input.c ./3_Implementation/inc/menu.h -o new.o
		gcc ./3_Implementation/unity/unity.c ./3_Implementation/test/test_menu.c -o test.out
