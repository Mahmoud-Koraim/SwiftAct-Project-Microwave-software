/*
 * macros.h
 *
 * Created: 26/08/2018 02:23:30 م
 *  Author: Ali Abdelhady
 */ 


#ifndef MACROS_H_
#define MACROS_H_

	#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
	#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
	#define TOGEL_BIT(REG,BIT) (REG^=(1<<BIT))
	#define IS_BIT_SET(REG,BIT) (REG&(1<<BIT))
	#define IS_BIT_CLEAR(REG,BIT) (!(REG&(1<<BIT)))



#endif /* MACROS_H_ */