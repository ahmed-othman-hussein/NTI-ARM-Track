#ifndef _BIT_MATH_H
#define _BIT_MATH_H
// set bit number bitNum of variable var
#define SET_BIT(var,bitNum) (var) |=(1<<(bitNum))
// clear bit number bitNum of variable var
#define CLR_BIT(var,bitNum) (var) &=~(1<<(bitNum))
// togle bit number bitNum of variable var
#define TOGGLE_BIT(var,bitNum) (var) ^=(1<<(bitNum)) 
// get bit number bitNum of variable var
#define GET_BIT(var,bitNum) (((var)>>(bitNum))&1)
/*circular shift left */
#define SHIFT_LEFT_U8(x,num) ((x)<<(num))|((x)>>(8-(num)))
/*circular shift Right  */
#define SHIFT_RIGHT_U8(x,num) ((x)>>(num))|((x)<<(8-(num)))

/*circular shift left */
#define SHIFT_LEFT_U32(x,num) ((x)<<(num))|((x)>>(32-(num)))
/*circular shift Right  */
#define SHIFT_RIGHT_U32(x,num) ((x)>>(num))|((x)<<(32-(num)))


#endif
