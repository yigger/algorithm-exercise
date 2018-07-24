cc = gcc
prom = algorithm
deps = lib/helper.h lib/sort.h
obj = src/main.o lib/helper.o lib/sort.o

$(prom): $(obj)
	@$(cc) -o $(prom) $(obj)

%.o: %.c $(deps)
	@$(cc) -c $< -o $@
	
clean:
	@-rm -rf $(obj) $(prom)
	@echo "finish clean"