#Makefile de l'application Analog

Grammaire : Lexer.o State0.o State1.o State2.o State3.o State4.o State5.o State6.o State7.o State8.o State9.o Automate.o main.o 
	g++ -std=c++11 -o Grammaire Lexer.o State0.o State1.o State2.o State3.o State4.o State5.o State6.o State7.o State8.o State9.o Automate.o main.o

Lexer.o : Lexer.h Lexer.cpp
	g++ -c -std=c++11 Lexer.cpp
	
State0.o : State0.h State.h Lexer.h Automate.h State0.cpp
	g++ -c -std=c++11 State0.cpp
	
State1.o : State1.h State.h Lexer.h Automate.h State1.cpp
	g++ -c -std=c++11 State1.cpp
	
State2.o : State2.h State.h Lexer.h Automate.h State2.cpp
	g++ -c -std=c++11 State2.cpp
	
State3.o : State3.h State.h Lexer.h Automate.h State3.cpp
	g++ -c -std=c++11 State3.cpp
	
State4.o : State4.h State.h Lexer.h Automate.h State4.cpp
	g++ -c -std=c++11 State4.cpp
	
State5.o : State5.h State.h Lexer.h Automate.h State5.cpp
	g++ -c -std=c++11 State5.cpp
	
State6.o : State6.h State.h Lexer.h Automate.h State6.cpp
	g++ -c -std=c++11 State6.cpp
	
State7.o : State7.h State.h Lexer.h Automate.h State7.cpp
	g++ -c -std=c++11 State7.cpp
	
State8.o : State8.h State.h Lexer.h Automate.h State8.cpp
	g++ -c -std=c++11 State8.cpp
	
State9.o : State9.h State.h Lexer.h Automate.h State9.cpp 
	g++ -c -std=c++11 State9.cpp
	
Automate.o : Automate.h Lexer.h State.h State0.h State1.h State2.h State3.h State4.h State5.h State6.h State7.h State8.h State9.h Automate.cpp 
	g++ -c -std=c++11 Automate.cpp	

main.o : Automate.h main.cpp
	g++ -c -std=c++11 main.cpp
	
clean :
	rm *.o *.exe Grammaire* 
