CXX := g++
CXXFLAGS := $(shell root-config --cflags --glibs)

main: bin/main.exe
	@echo making main...

bin/%.exe: bin/%.o
	@echo executable... $< [$@]
	$(CXX) $(CXXFLAGS) -o $@ $<

bin/%.o: %.cpp
	@echo compiling... $< [$@]
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@echo cleaning...
	rm -f $(wildcard bin/*)