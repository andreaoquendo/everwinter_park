#A regra output tem como dependência o arquivo objeto projeto.o
#O comando cria um executável saida a partir do objeto projeto.o
output: projeto.o
	g++ projeto.o -o output

#A regra projeto.o tem como dependência o arquivo fonte projeto.c
#O arquivo objeto projeto.o é criado a partir do arquivo fonte projeto.c
projeto.o: projeto.c
	g++ -c projeto.c

#A regra clean: apaga os arquivos .o ao digitarmos make clean no console
clean:
	rm -f *.o

#A regra execClean apaga o arquivo executável ao digitarmos make execClean no console
execClean:
	rm -f output