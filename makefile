OBJ= main.o Trajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o
COMP= g++
COMPFLAG = -Wall -std=c++11

TrajetSimulator2000 : $(OBJ)
	$(COMP) -o TrajetSimulator2000 $(OBJ)
main.o : main.cpp Catalogue.h Trajet.h
	$(COMP) -c main.cpp 
Catalogue.o : Catalogue
