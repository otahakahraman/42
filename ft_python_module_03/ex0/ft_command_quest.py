import sys

print("=== Command Quest ===")
print(f"Program name: {sys.argv[0]}")
if len(sys.argv) <= 1:
    print("No arguments provided!")
else :
    a = 1
    print(f"Arguments received: {len(sys.argv) - 1}")
    while(len(sys.argv) > a):
        print(f"Argument {a}: {sys.argv[a]}")
        a += 1
print(f"Total arguments: {len(sys.argv)}\n")
