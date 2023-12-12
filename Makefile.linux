PROJECT_DIR=.

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++14 
CC=gcc
CXX=g++

FILES=data_structures/disjoint_set.cpp graph.cpp main.cpp sort/msort.cpp

# Using OpenCV for Visualization
OPENCV=1
ifeq ($(OPENCV), 1)
	LDFLAGS+=  `pkg-config --libs opencv`
	CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv`
endif


SRC_DIR=${PROJECT_DIR}/src/

SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})

all: 
	$(warning "You have to type one of the following commands")
	$(warning "     Type 'make prim' to run compile and run the Prim's algorithm")
	$(warning "     Type 'make kruskal' to run compile and run the Kruskal's algorithm")
	$(warning "     Type 'make dijkstra' to run compile and run the Dijkstra algorithm")

prim: ${SRC_FILES} ${SRC_DIR}algorithms/prim.cpp
	${CXX} ${CFLAGS} -DPRIM $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

kruskal: ${SRC_FILES} ${SRC_DIR}algorithms/kruskal.cpp
	${CXX} ${CFLAGS} -DKRUSKAL $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

dijkstra: ${SRC_FILES} ${SRC_DIR}algorithms/dijkstra.cpp
	${CXX} ${CFLAGS} -DDIJKSTRA $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 


