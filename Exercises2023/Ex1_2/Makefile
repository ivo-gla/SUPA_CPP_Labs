CC=g++ #Compiler
FLAGS=
TARGET=AD
OBJECTS= CustomFunctions.o AnalyseData.o #test2.0

${TARGET}:${OBJECTS}
	@echo "Linking ..."
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}
	@make clean

AnalyseData.o: AnalyseData.cxx CustomFunctions.h
	${CC} ${FLAGS} -c AnalyseData.cxx

CustomFunctions.o: CustomFunctions.cxx CustomFunctions.h
	${CC} ${FLAGS} -c CustomFunctions.cxx


clean: 
	@rm -f *.o *~

cleantarget:
	@rm -f ${TARGET}