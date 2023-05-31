FILE = template.cpp

a.out: $(FILE)
	g++-11 -O1 -Wall $(FILE)