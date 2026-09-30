import sys


if len(sys.argv)!=2:
    print("Usage: ft_ancient_text.py <file>\n")
    sys.exit(1)
access_file=sys.argv[1]

print("=== Cyber Archives Recovery & Preservation ===")
print(f"Accessing file '{sys.argv[1]}'")
try:
    file = open(access_file,"r")
    data=file.read()
    print("---\n")
    print(data)
    print(f"\n---\nFile '{sys.argv[1]}' closed.\n")
    file.close()

except OSError as err:
    print(f"Error opening file '{sys.argv[1]}':{err}")
    sys.exit(1)

print("Transform data:\n---\n")
new_data=""
for ch in data:
    if ch=="\n" :
        new_data+="#\n"
    else:
        new_data+=ch
new_data+="#"
print(new_data)
print("\n---")
name=input("Enter new file name (or empty): ")
if name=="":
    print("Not saving data.")
else:
    print(f"Saving data to '{name}'\n"
          f"Data saved in file '{name}'.")
    new_file=open(f"{name}","w")
    new_file.write(new_data)
    new_file.close()
