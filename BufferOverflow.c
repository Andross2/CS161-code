#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 

void vulnerable(char* buf){
	gets(buf);
}

void print_input() {
	int c; // using "int" to represent 'char'
	c = getchar();
	/* 可以一次输入多个字符，也能打印出来 
	EOD = ctrl + D */
	while(c != EOF) {
		putchar(c);
		c = getchar();
	}
}

void print_input_short() {
	int c;
	while((c = getchar()) != EOF) {
		putchar(c);
	}
}

void char_count() {
	double nc = 0;
	while(getchar() != EOF)
		++nc;  // ++nc is more efficient
	printf("%.0f\n", nc);  // using %.0f to print double or float
}

void char_count_forloop() {
	long nc;

	for(long nc = 0; getchar() != EOF; ++nc)

	printf("%ld\n", nc);  // %ld used to print long int
}

void line_count() {
	int c, nl;
	nl = 0;
	while((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
	}

}

void word_count() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nc = nw = 0; //这里是传值 不是传引用 C只用指针表示传引用
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("nw: %d\n nl: %d\n nc: %d\n", nw, nl, nc);
}

/* this is the function to decide whether passing value or reference */
void pass_what() {
	int a = 1;
	int b = a;
	int* c = &a;
	printf("b = %d, c = %d\n", b, *c);
	a = 2;
	printf("set a = 2, b =: %d\n", b);  // b = 1. So C is passing value
	printf("c = %d\n", *c); // passing reference only when pointer is used
}

void count_occurance() {
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for(i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while((c = getchar()) != EOF)
	// 所有的if-else结构同属于单独一个逻辑结构，因此while不需要大括号
	// 牛逼！！！
		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if(c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits= ");
	for(i = 0; i < 10; i ++)
		printf("%d ", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}

/* C语言当传variable时，传value。当传array时，传reference（pointer/address） */
void pass_by_value(int n) {
	int i;
	for(i = 0; i < n; --n)
		printf("i = %d, n = %d\n", i, n);
}

int main()
{
	char buf[2];
	int authenticated = 0;
	int a = 1, b = 2, a1 = 16;
	float c = 3.00001, d = 4.001;
	char c1, c2;
	int n = 5;

	pass_by_value(n);
	printf("the n in main frange is: %d\n", n);
	// count_occurance();
	// pass_what();
	// word_count();
	// char_count();
	// print_input();
	// vulnerable(buf);
	printf("%d\n", authenticated);
	printf("%d %d \n", a, b);
	printf("%3.1f %6f \n", c, d);
	printf("%x\n", a1);
	c1 = getchar();
	c2 = '$';
	putchar(c2);

	printf("%c %c\n", c1, c2);
	return 0;
}
