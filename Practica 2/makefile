# Makefile para la práctica 2: Cadenas y lenguajes

# Variables
CXX = g++                          # Compilador a usar
CXXFLAGS = -Wall -g                # Opciones de compilación (advertencias y depuración)

# Nombre del ejecutable
EXECUTABLE = p02_strings

# Archivos fuente
SOURCES = main.cc cadena.cc        # Lista de archivos fuente
OBJECTS = $(SOURCES:.cc=.o)       # Archivos objeto generados

# Regla principal
all: $(EXECUTABLE)                # Compila el ejecutable

# Regla para crear el ejecutable
$(EXECUTABLE): $(OBJECTS)         # Dependencias del ejecutable
	$(CXX) $(CXXFLAGS) -o $@ $^   # Compila el ejecutable a partir de los archivos objeto

# Regla para compilar archivos objeto
%.o: %.cc                          # Compilación de archivos .cc a .o
	$(CXX) $(CXXFLAGS) -c $<       # $< es el primer pre-requisito (el archivo .cc)

# Regla para limpiar el directorio
clean:                             # Limpia archivos objeto y el ejecutable
	rm -f $(OBJECTS) $(EXECUTABLE)  # Elimina archivos objeto y ejecutable
