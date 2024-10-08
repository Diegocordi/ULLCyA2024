# Definimos el compilador
CXX = g++

# Definimos las opciones de compilación
CXXFLAGS = -std=c++11 -Wall -Wextra

# Lista de archivos fuente
SOURCES = main.cpp CodeAnalyzer.cpp

# Convertimos los archivos fuente en archivos objeto
OBJECTS = $(SOURCES:.cpp=.o)

# Nombre del ejecutable
TARGET = code_analyzer

# Regla por defecto: compilar el ejecutable
all: $(TARGET)

# Regla para crear el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos fuente en archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)
