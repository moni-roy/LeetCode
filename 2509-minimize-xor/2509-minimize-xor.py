class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        # Step 1: Count the set bits in num2
        count_set_bits_num2 = bin(num2).count('1')
        
        # Step 2: Generate x to minimize XOR difference
        x = 0
        for i in range(31, -1, -1):  # Check bits from most significant to least significant
            if count_set_bits_num2 == 0:
                break
            if num1 & (1 << i):  # If the bit is set in num1
                x |= (1 << i)   # Set the same bit in x
                count_set_bits_num2 -= 1
        
        # Step 3: If more bits are needed, set the least significant unset bits
        for i in range(32):
            if count_set_bits_num2 == 0:
                break
            if not (x & (1 << i)):  # If the bit is not set in x
                x |= (1 << i)      # Set the bit
                count_set_bits_num2 -= 1
        
        return x