# blah: blah.o
# 	cc blah.o -o blah # Runs third

# blah.o: blah.c
# 	cc -c blah.c -o blah.o # Runs second

# # Typically blah.c would already exist, but I want to limit any additional required files
# blah.c:
# 	echo "int main() { printf("Hi"); return 0; }" > blah.c # Runs first
clean:
	rm *.o a.out