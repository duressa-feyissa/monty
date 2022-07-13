#ifndef _MONTY_
#define _MONTY_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **obs, unsigned int line_number);
} instruction_t;

/**
 * struct global - Global variables across multiple file
 * @num: string variable hold integeral value which pushed
 * @value: integer variable which hold equivalent integer value of num
 * @change: check for stack or queue
 *
 * Description: Global variables
 * for stack, queues, LIFO, FIFO
 */
typedef struct global
{
	char *num;
	int value;
	int change;
	int x;
} global_t;

extern global_t glob;

/** Read and Parse operator function **/
void parse(char *str, stack_t **obs, unsigned int count);
void readFun(char *filename, stack_t **obs);
void findCommad(stack_t **obs, char *str, unsigned int count);
char *analysis(char *str);

/** Error handler function **/
void firstError(void);
void secondError(char *s);
void thirdError(unsigned int i, char *s);

/** function which help to free memory **/
void freeFun(stack_t **obs);

/** basic operation handler function**/
void PUSH(stack_t **obs, unsigned int count);
void PALL(stack_t **obs, unsigned int count);
void _PINT(stack_t **obs, unsigned int count);
void POP(stack_t **obs, unsigned int count);
void SWAP(stack_t **obs, unsigned int count);
void ADD(stack_t **obs, unsigned int count);
void NOP(stack_t **obs, unsigned int count);
void SUB(stack_t **obs, unsigned int count);
void MUL(stack_t **obs, unsigned int count);
void DIV(stack_t **obs, unsigned int count);
void MOD(stack_t **obs, unsigned int count);
void _PCHAR(stack_t **obs, unsigned int count);
void _PSTR(stack_t **obs, unsigned int count);
void ROT1(stack_t **obs, unsigned int count);
void ROTR(stack_t **obs, unsigned int count);

#endif
