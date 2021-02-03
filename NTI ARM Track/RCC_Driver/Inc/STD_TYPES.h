#ifndef _STD_TYPES_H
#define _STD_TYPES_H
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef enum
{
  STD_OK =0,
  STD_NOK
   
}Std_RetType;

typedef enum
{
  STD_LOW =0,
  STD_HIGH
  
}Std_LevelType;

typedef enum
{
  STD_FALSE=0,
  STD_TRUE
}Std_boolean;

#define NULL  0xFF

typedef  void (* ptrFunction) (void);
#define NULL_PTR  (ptrFunction) 0x00


#define STD_DISABLED  0x55
#define STD_ENABLED   0x00
#endif
