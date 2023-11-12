def minimize_attacks_to_win(n, hordes):
    # Sort hordes in decreasing order
    hordes.sort(reverse=True)

    total_attacks = 0
    x = 0

    for horde in hordes:
        while horde >= x:
            # Use second type of attack
            horde -= x
            x = 0
            total_attacks += 1

        # Use first type of attack for remaining monsters
        x += 1
        total_attacks += 1

    return total_attacks

# Example usage:
n = 4  # Number of hordes
hordes = [1, 3, 1, 1]  # Number of monsters in each horde
result = minimize_attacks_to_win(n, hordes)
print(result)  # Output the minimum number of attacks required

