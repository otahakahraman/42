def secure_archive(name,mode="read",content=""):
    try:
        if mode == "write":
            with open(name,"w") as file:
                file.write(content)
            return (True,"Content successfully written to file") 
        elif mode == "read":
            with open(name,"r") as file:
                data=file.read()
            return (True,data)
    except Exception as err:
        return(False,str(err))

print("=== Cyber Archives Security ===\n")
print("Using 'secure_archive' to read from a nonexistent file:")
print(secure_archive("/not/existing/file","read"))
print("\nUsing 'secure_archive' to read from an inaccessible file:")
print(secure_archive("/etc/master.passwd","read"))

print("\nUsing 'secure_archive' to read from a regular file:")
print(secure_archive("ancient_fragment.txt"))
result=secure_archive("ancient_fragment.txt")

print("\nUsing 'secure_archive' to write previous content to a new file:")
if result[0]:
    print(secure_archive("new_fragment.txt","write",result[1]))
