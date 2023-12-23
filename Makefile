FILE = template.cpp

a.out: $(FILE)
	g++-13 -O1 -Wall $(FILE)
