def main():
    try:
        num_users = int(input("Enter number of users: "))
    except ValueError:
        print("Please enter a valid number.")
        return

    user_items = {}

    for _ in range(num_users):
        username = input("\nEnter username: ").strip()

        try:
            num_items = int(input("How many items? "))
        except ValueError:
            print("Please enter a valid number.")
            return

        items = []
        for i in range(num_items):
            item_name = input(f"Item {i + 1}: ").strip()
            items.append(item_name)

        user_items[username] = items

    item_frequencies = {}
    for items in user_items.values():
        for item in items:
            if item in item_frequencies:
                item_frequencies[item] += 1
            else:
                item_frequencies[item] = 1

    common_items = []
    unique_items = set()
    most_popular_items = []
    max_count = 0

    for item, count in item_frequencies.items():
        if count > 1:
            common_items.append(item)
        elif count == 1:
            unique_items.add(item)

        if count > max_count:
            max_count = count
            most_popular_items = [item]
        elif count == max_count:
            most_popular_items.append(item)

    print("\nUSER DATA:")
    for user, items in user_items.items():
        print(f"{user} -> {items}")

    print("\nCOMMON ITEMS:")
    if common_items:
        for item in common_items:
            print(item)
    else:
        print("None")

    print("\nUNIQUE ITEMS:")
    if unique_items:
        for item in unique_items:
            print(item)
    else:
        print("None")

    print("\nMOST POPULAR ITEM:")
    if most_popular_items:
        for item in most_popular_items:
            print(item)
    else:
        print("None")

if __name__ == "__main__":
    main()