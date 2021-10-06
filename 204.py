# Create the given count_stair_ways function

def count_stair_ways(n):

    # Here, blank fill with n

    def repeat(n):

        # Here, fill blank with the condition

        # n less than equal to 1

        if n <= 2:

          # Than, fill the blank with

          # the return of value n

            return n

        # Otherwise

        else:

            # Return repeat count_stair_ways(n-1)

            # and count_stair_ways(n-2) ways by

            # the help of repeat() tree recursion function

            return repeat(n - 1) + repeat(n - 2) +repeat(n - 3)

    # Here, you can return the values in two ways:



    # Note: Use any approach from 1 way and 2 way

    # and put or remove comment as per your requirement

    # Here, I’m using 2nd way approach.

    # 1 way:

    # return repeat(1 + n)

    # 2 way:

    # Here, return 1 plus with function

    return 1+repeat(n)

# Call the function:

# Here, you can put comment before

# print function and directly call

# the function from terminal

print(count_stair_ways(3))
print(count_stair_ways(4))
print(count_stair_ways(5))

print(count_stair_ways(6))
print(count_stair_ways(7))

print(count_stair_ways(8))
print(count_stair_ways(9))
print(count_stair_ways(10))
