import sys

if len(sys.argv)!=2:
    print("Usage: ft_ancient_text.py <file>\n")
    sys.exit(1)
access_file=sys.argv[1]

print("=== Cyber Archives Recovery ===")
print(f"Accessing file '{sys.argv[1]}'")
try:
    file = open(access_file,"r")
    data=file.read()
    print("---\n")
    print(data)
    file.close()
    print(f"\n---\nFile '{sys.argv[1]}' closed.")

except Exception as err:
    print(f"Error opening file '{sys.argv[1]}':{err}")
