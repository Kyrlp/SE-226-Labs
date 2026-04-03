# Q1

def factorial(x):
    if x <= 1:
        return 1
    return x * factorial(x - 1)

# Q2

term_abs = lambda x, i: (x ** (2 * i)) / factorial(2 * i)

def exp_x(x, n):
    total = 0
    for i in range(n):
        term = term_abs(x, i)

        if i % 2 != 0:
            term = -term
        total += term
    return total

# Q3

G_n = 0

def calculate_Gn(n, r):

    global G_n
    if n == 0:
        G_n += 1
    else:
        G_n += (r ** n)
        calculate_Gn(n - 1, r)



if __name__ == "__main__":
    print(" Question 2: S Summation ")

    user_x = float(input("Enter the value for x: "))
    user_n_q2 = int(input("Enter the number of terms (n): "))
    s_result = exp_x(user_x, user_n_q2)
    print(f"Result S = {s_result}")

    print("\n Question 3: G_n Series ")
    user_n_q3 = int(input("Enter the number of terms (n): "))
    user_r = float(input("Enter the common ratio (r): "))

    G_n = 0 #reset global variable just incase

    calculate_Gn(user_n_q3, user_r)
    print(f"Result G_n = {G_n}")
