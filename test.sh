#!/bin/bash
d=0
nb_test=0
printf "\nNumber of your test ?\n\n"
read -r nb_test
printf "\nTest number |$nb_test|\n"

printf "\nVerbose?\n\n"
read -r b
printf "\nVerbose choisie |$b|\n"

printf "Dump ?\n\n"
read -r d
printf "\nDump choisi |$d|\n"

printf "\nCompilations en cours...\n"

if [ $d != 0 ]
then
	./zaz_corewar -v $b -d $d test/$nb_test.cor > test/result_test$nb_test.Zaz
	./corewar -v $b -dump $d test/$nb_test.cor > test/result_test$nb_test.Us
fi
./zaz_corewar -v $b test/$nb_test.cor > test/result_test$nb_test.Zaz
./corewar -v $b test/$nb_test.cor > test/result_test$nb_test.Us
# diff test/result_test$nb_test.Zaz test/result_test$nb_test.Us > test/diff
# printf "\n------------------ DIFF ----------------\n"
# if [ !test/diff ]
# then
# 	printf "PAS DE DIFF :D\n"
# fi
# 	cat test/diff
# printf "\n------------------ CMP ----------------\n"
cmp test/result_test$nb_test.Zaz test/result_test$nb_test.Us > test/cmp
if [ !test/cmp ]
then
	printf "COMPARAISON OK :D\n"
fi
	cat test/cmp
