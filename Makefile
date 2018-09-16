
TARGET 		= sfml-app

CC			= g++
CFLAGS 		= -Wall -I. 
LINKER 		= g++ 
#Here Librairies
LDFLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES 	:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.hpp)
OBJECTS		:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm 			= rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)

	$(LINKER) $(OBJECTS) -o $@ $(LDFLAGS)
	@echo "Linking complete !"
	@echo "Executing the program"
	@echo "---------------------"
	@echo "* * * * * * * * * * *"
	@echo "---------------------"
	@echo ""

#	@./$(BINDIR)/$(TARGET)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"
	


.PHONY: clean remove run gdb


gdb:
	@gdb $(BINDIR)/$(TARGET)

run:
	@./$(BINDIR)/$(TARGET)


clean: 
	@$(rm) $(OBJECTS)
	@echo "Cleanup Complete"
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"


# $@ = nom de la cible
# $< = nom de la première dépendance
# $^ = liste des dépendances
# $? = liste des dépendances plus récentes que la cible
# $* = le nom du fichier sans suffixe