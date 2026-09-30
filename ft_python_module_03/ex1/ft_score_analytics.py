import sys

print("=== Player Score Analytics ===")
arr=[]

a=1
while(len(sys.argv) > a):
        if sys.argv[a].isnumeric():
            arr.append(int(sys.argv[a]))
        else:
            print(f"Invalid parameter: '{sys.argv[a]}'")
        a += 1
if arr != []:
        print(f"Scores processed: {arr}")
        print(f"Total players: {len(arr)}")
        print(f"Total score: {sum(arr)}")
        print(f"Average score: {sum(arr)/len(arr)}")
        print(f"High score: {max(arr)}")
        print(f"Low score: {min(arr)}")
        print(f"Score range: {max(arr) -min(arr)}")
else :
        print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
