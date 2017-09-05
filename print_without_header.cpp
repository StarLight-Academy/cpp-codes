/*
 * C++ program without header files
 */
extern "C"{
int printf(const char *format, ...);
}

int main(){
	int a = 10, b = 20;
	int c = a + b;
	printf("Hello World %d", c);
	return 0;
}