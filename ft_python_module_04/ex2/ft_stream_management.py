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
    sys.stderr.write(f"[STDERR]Error opening file '{sys.argv[1]}':{err}")
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
sys.stdout.write("Enter new file name (or empty): ")
sys.stdout.flush()

name=sys.stdin.readline()
if len(name)>0 and name[-1]=="\n":
    name=name[:-1]
sys.stdout.write(f"Saving data to {name}")
try:
    savefile=open(name,"w")
    savefile.write(new_data)
    savefile.close()
except OSError as err:
    sys.stdout.write(f"[STDERR] Error opening file '{name}': {err}\nData not saved.\n")
