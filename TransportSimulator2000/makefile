OBJ= main.o Trajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o TrajetDAO.o
COMP= g++
COMPFLAG = -Wall -std=c++11 -ggdb -DMAP

TrajetSimulator2000 : $(OBJ)
	$(COMP) $(COMPFLAG) -o TrajetSimulator2000 $(OBJ)
	
main.o : main.cpp Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h ListeTrajets.h
	$(COMP) $(COMPFLAG) -c main.cpp 
	
TrajetDAO.o : TrajetDAO.h TrajetDAO.cpp Catalogue.h Trajet.h
	$(COMP) $(COMPFLAG) -c TrajetDAO.cpp 

Catalogue.o : Catalogue.h ListeTrajets.h Catalogue.cpp Trajet.h
	$(COMP) $(COMPFLAG) -c Catalogue.cpp

TrajetCompose.o : TrajetCompose.h Trajet.h ListeTrajets.h TrajetSimple.h TrajetCompose.cpp
	$(COMP) $(COMPFLAG) -c TrajetCompose.cpp

TrajetSimple.o : TrajetSimple.h Trajet.h TrajetSimple.cpp
	$(COMP) $(COMPFLAG) -c TrajetSimple.cpp

ListeTrajets.o : ListeTrajets.h Trajet.h TrajetSimple.h TrajetCompose.h TrajetCompose.cpp
	$(COMP) $(COMPFLAG) -c ListeTrajets.cpp
	
Trajet.o : Trajet.h Trajet.cpp
	$(COMP) $(COMPFLAG) -c Trajet.cpp
clean :
	rm $(OBJ)
