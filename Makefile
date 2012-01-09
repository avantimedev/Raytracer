# Define the compiler options
CXXFLAGS  = -pipe -O2 -Wall -W -ansi -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast

# Define what to do when make is executed without arguments.
all: raytracer

# The following rule means "if ltest is older than ltest.o or list.o,
# then link ltest".
raytracer: color.o image.o light.o main.o material.o point.o ray.o scene.o sphere.o vector.o shape.o raytracer.o plane.o tga.o
	g++ -o raytracer color.o image.o light.o main.o material.o point.o ray.o scene.o sphere.o vector.o shape.o raytracer.o plane.o tga.o

# Define the rules for the object files.
color.o: color.cc color.h
	g++ -c $(CXXFLAGS) color.cc
image.o: image.cc image.h
	g++ -c $(CXXFLAGS) image.cc
light.o: light.cc light.h
	g++ -c $(CXXFLAGS) light.cc
main.o: main.cc
	g++ -c $(CXXFLAGS) main.cc
material.o: material.cc material.h
	g++ -c $(CXXFLAGS) material.cc
point.o: point.cc point.h
	g++ -c $(CXXFLAGS) point.cc
ray.o: ray.cc ray.h
	g++ -c $(CXXFLAGS) ray.cc
scene.o: scene.cc scene.h
	g++ -c $(CXXFLAGS) scene.cc
sphere.o: sphere.cc sphere.h
	g++ -c $(CXXFLAGS) sphere.cc
vector.o: vector.cc vector.h
	g++ -c $(CXXFLAGS) vector.cc
shape.o: shape.cc shape.h
	g++ -c $(CXXFLAGS) shape.cc
plane.o: plane.cc plane.h
	g++ -c $(CXXFLAGS) plane.cc
raytracer.o: raytracer.cc raytracer.h
	g++ -c $(CXXFLAGS) raytracer.cc
tga.o: tga.cc tga.h
	g++ -c $(CXXFLAGS) tga.cc
clean:
	rm -rf *o raytracer
